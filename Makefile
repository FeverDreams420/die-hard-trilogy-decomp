# Die Hard Trilogy decomp build. Run inside WSL from the repo root:
#   make split     run splat (regenerates asm/ and build/<exe>.ld)
#   make           assemble, link and rebuild each EXE into build/
#   make check     compare each rebuilt EXE with disc/ (OK or the first differing offset)
#   make clean     delete build outputs (keeps asm/, the Ghidra project and the linker scripts)
#
# Each EXE has a config/<exe>.yaml. Add each new EXE to EXES and give it a FILE_<exe> line.

EXES   := boot dh1 dh2 dh3
# disc file name for each EXE
FILE_boot := BOOT.EXE
FILE_dh1  := DH1.EXE
FILE_dh2  := DH2.EXE
FILE_dh3  := DH3.EXE

# pipefail, so a cc1 error in the middle of the C pipeline fails the build
SHELL       := /bin/bash
.SHELLFLAGS := -o pipefail -c
# and delete the half-written .o, or the next make thinks it's up to date
.DELETE_ON_ERROR:

CROSS   := mipsel-linux-gnu-
AS      := $(CROSS)as
LD      := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy
PYTHON  := .venv/bin/python

ASFLAGS := -EL -march=r3000 -mtune=r3000 -msoft-float -no-pad-sections -Iinclude -G0
LDFLAGS := -EL --no-check-sections -nostdlib

# C pipeline, mirroring the original toolchain:
#   cpp -> cc1 (GCC) -> maspsx (makes GNU as behave like Sony's ASPSX) -> as
# Settings from the Phase 4 bake-off (docs/compiler-notes.md): GCC 2.5.7 with -O2 -G8
# matches 20 of 22 test leaves. ASPSX is 2.34 for DH1, 2.21 for DH2, DH3 and LOADER.
# A file or EXE can override a setting with a target-specific variable, for example:
#   build/src/loader/%.c.o: ASPSX_VER := 2.21
# Ubuntu's cpp, not tools/gcc-*/cpp: the old 32-bit cpp can't open files on
# /mnt/c ("Value too large for defined data type", large WSL inode numbers).
CPP      := cpp
CC1      := tools/gcc-2.5.7-psx/cc1
GFLAG    := -G8
CPPFLAGS := -nostdinc -Iinclude -undef -Dmips -D__mips__ -D__OPTIMIZE__ -Dpsx -D__psx__ \
	-D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C
CFLAGS   := -quiet -O2 $(GFLAG) -w -fno-builtin -fpeephole -ffunction-cse -fpcc-struct-return \
	-fcommon -msoft-float
# -O1 lets GNU as fill branch delay slots, which ASPSX did for compiled code
CASFLAGS := $(ASFLAGS) -O1
ASPSX_VER := 2.34
# DH2 and DH3 expand symbol+register loads and stores as lui/addiu/addu/op 0(at)
# (for example lhu in 0x80065328 of DH2), the ASPSX 2.21 form; DH1 has only the
# 2.34 form (lui/addu/op %lo(at)).
build/src/dh2/%.c.o build/src/dh3/%.c.o: ASPSX_VER := 2.21
# Each EXE has a single .rodata segment that also holds its .data and .sdata,
# so small constants the compiler puts in .sdata (initializers of 8 bytes or
# less) go to .rodata until data is split into its own segments.
SDATA_TO_RODATA := sed 's/^\t\.sdata$$/\t.rdata/'
# GCC puts ".align 3" before each jump table. In the original EXEs the tables
# are only word aligned in absolute terms (jtbl_8007ACA0 at 0 mod 8 is followed
# directly by jtbl_8007ACB4 at 4 mod 8), and one big C file can't reproduce the
# section base of each original source file anyway, so drop it and keep GCC's
# ".align 2". Any padding the original has belongs to the INCLUDE_RODATA
# symbol before the table.
JTBL_ALIGN := sed '/^\t\.align\t3$$/{N;s/^\t\.align\t3\n\(\t\.align\t2\)$$/\1/;}'
MASPSX   = $(PYTHON) tools/maspsx/maspsx.py --expand-div --aspsx-version=$(ASPSX_VER) $(GFLAG)

# Each EXE's objects: its top-level asm files (header, data, asm segments) and its
# C files. The per-function files in asm/<exe>/nonmatchings/ are pulled into
# the C files by INCLUDE_ASM, so they are dependencies, not objects.
asm_of = $(shell find asm/$(1) -name '*.s' -not -path '*/nonmatchings/*' 2>/dev/null)
c_of   = $(shell find src/$(1) -name '*.c' 2>/dev/null)
obj_of = $(patsubst %.s,build/%.s.o,$(call asm_of,$(1))) $(patsubst %.c,build/%.c.o,$(call c_of,$(1)))

.PHONY: all split check clean report upload-progress
all: $(foreach e,$(EXES),build/$(FILE_$(e)))

split:
	@for e in $(EXES); do $(PYTHON) -m splat split config/$$e.yaml || exit 1; done

build/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

build/src/%.c.o: src/%.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) | $(SDATA_TO_RODATA) | $(JTBL_ALIGN) | $(MASPSX) | $(AS) $(CASFLAGS) -o $@

define exe_rules
$(patsubst %.c,build/%.c.o,$(call c_of,$(1))): $(shell find asm/$(1)/nonmatchings -name '*.s' 2>/dev/null) \
	$(wildcard include/*.h include/*.inc)

build/$(1).elf: $(call obj_of,$(1)) build/$(1).ld
	$(LD) $(LDFLAGS) -Map build/$(1).map -T build/$(1).ld \
		-T build/$(1).undefined_syms_auto.txt -T build/$(1).undefined_funcs_auto.txt -o $$@

build/$(FILE_$(1)): build/$(1).elf
	$(OBJCOPY) -O binary $$< $$@
endef
$(foreach e,$(EXES),$(eval $(call exe_rules,$(e))))

check: all
	@status=0; for f in $(foreach e,$(EXES),$(FILE_$(e))); do \
		want=$$(grep "  $$f\$$" config/hashes.txt | cut -d' ' -f1); \
		got=$$(sha1sum build/$$f | cut -d' ' -f1); \
		if [ "$$want" = "$$got" ]; then echo "OK    $$f $$got"; \
		else echo "FAIL  $$f: $$(cmp build/$$f disc/$$f 2>&1 | head -1)"; status=1; fi; \
	done; exit $$status

# objdiff-format progress report, and its upload to bytematch.dev.
# The upload needs the project token in BYTEMATCH_TOKEN and a clean tree,
# so the report always belongs to the commit it is filed under.
BYTEMATCH_PROJECT ?= FeverDreams420/die-hard-trilogy-decomp
BYTEMATCH_VERSION ?= SLUS_001.19

report: all
	$(PYTHON) tools/progress.py --report build/report.json

upload-progress: check report
	@test -n "$$BYTEMATCH_TOKEN" || { echo "BYTEMATCH_TOKEN is not set"; exit 1; }
	@git diff --quiet HEAD -- src include asm config Makefile || \
		{ echo "Commit your changes first: the report is filed under HEAD"; exit 1; }
	@curl --fail-with-body -sS -X POST \
		-H "Authorization: Bearer $$BYTEMATCH_TOKEN" \
		-H "Content-Type: application/json" \
		--data-binary @build/report.json \
		--url-query "version=$(BYTEMATCH_VERSION)" \
		--url-query "commit=$$(git rev-parse HEAD)" \
		--url-query "commit_timestamp=$$(git log -1 --format=%cI)" \
		--url-query "commit_message=$$(git log -1 --format=%s)" \
		"https://bytematch.dev/api/v1/projects/$(BYTEMATCH_PROJECT)/reports"; echo

clean:
	rm -rf build/asm build/src $(foreach e,$(EXES),build/$(e).elf build/$(e).map build/$(FILE_$(e)))
