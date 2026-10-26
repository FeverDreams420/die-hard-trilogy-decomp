# Die Hard Trilogy decomp build. Run inside WSL from the repo root:
#   make split     run splat (regenerates asm/ and build/<exe>.ld)
#   make           assemble, link and rebuild each EXE into build/
#   make check     compare each rebuilt EXE with disc/ (OK or the first differing offset)
#
# Each EXE has a config/<exe>.yaml. Phase 3 builds only BOOT; add more to EXES.

EXES   := boot
# disc file name for each EXE
FILE_boot := BOOT.EXE

CROSS   := mipsel-linux-gnu-
AS      := $(CROSS)as
LD      := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy
PYTHON  := .venv/bin/python

ASFLAGS := -EL -march=r3000 -mtune=r3000 -msoft-float -no-pad-sections -Iinclude -G0
LDFLAGS := -EL --no-check-sections -nostdlib

# Each EXE's object list comes from its asm folder, which splat creates.
asm_of = $(shell find asm/$(1) -name '*.s' 2>/dev/null)
obj_of = $(patsubst %.s,build/%.s.o,$(call asm_of,$(1)))

.PHONY: all split check clean
all: $(foreach e,$(EXES),build/$(FILE_$(e)))

split:
	@for e in $(EXES); do $(PYTHON) -m splat split config/$$e.yaml || exit 1; done

build/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

define exe_rules
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

clean:
	rm -rf build/asm $(foreach e,$(EXES),build/$(e).elf build/$(e).map build/$(FILE_$(e)))
