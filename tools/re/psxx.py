"""Quick static helper for PS-X EXEs: BIOS stubs, callers, address refs, disassembly.

psxx.py EXE bios                 list BIOS call stubs (A0/B0/C0) and their callers
psxx.py EXE refs ADDR [ADDR..]   find lui/addiu-style references to addresses (+-0x40)
psxx.py EXE callers ADDR         jal sites that call ADDR
psxx.py EXE dis START END        disassemble with objdump-like output (needs WSL objdump; here raw)
"""
import struct
import sys

REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

BIOS_A = {0x00: "open", 0x02: "read", 0x04: "close", 0x13: "setjmp", 0x14: "longjmp", 0x3F: "printf",
          0x42: "Load", 0x43: "Exec", 0x44: "FlushCache", 0x49: "GPU_cw", 0x51: "LoadExec",
          0x70: "_bu_init", 0x71: "_96_init", 0x72: "_96_remove", 0x9F: "SetMemSize", 0xA0: "WarmBoot",
          0xA4: "CdGetLbn", 0xA5: "CdReadSector", 0xA6: "CdGetStatus"}
BIOS_B = {0x00: "alloc_kernel_memory", 0x07: "DeliverEvent", 0x08: "OpenEvent", 0x09: "CloseEvent",
          0x0B: "TestEvent", 0x0C: "EnableEvent", 0x0D: "DisableEvent", 0x0E: "OpenThread",
          0x10: "ChangeThread", 0x12: "InitPAD", 0x13: "StartPAD", 0x14: "StopPAD", 0x17: "ReturnFromException",
          0x18: "SetDefaultExitFromException", 0x19: "SetCustomExitFromException", 0x32: "open", 0x34: "read",
          0x36: "close", 0x3F: "puts", 0x47: "AddDevice", 0x4A: "InitCARD", 0x4B: "StartCARD",
          0x56: "GetC0Table", 0x57: "GetB0Table", 0x5B: "ChangeClearPad"}
BIOS_C = {0x00: "EnqueueTimerAndVblankIrqs", 0x01: "EnqueueSyscallHandler", 0x02: "SysEnqIntRP",
          0x03: "SysDeqIntRP", 0x0A: "ChangeClearRCnt", 0x12: "InstallDevices"}


def load(path):
    d = open(path, "rb").read()
    taddr, tsize = struct.unpack_from("<II", d, 0x18)
    body = d[0x800:0x800 + tsize]
    words = struct.unpack_from(f"<{len(body) // 4}I", body)
    return taddr, words


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def bios_stubs(taddr, words):
    stubs = {}
    for i in range(len(words) - 2):
        a, b, c = words[i:i + 3]
        # addiu t2, zero, 0xA0/B0/C0 ; jr t2 ; addiu t1, zero, N
        if (a & 0xFFFF0000) == 0x240A0000 and (a & 0xFFFF) in (0xA0, 0xB0, 0xC0) \
                and b == 0x01400008 and (c & 0xFFFF0000) == 0x24090000:
            table = a & 0xFFFF
            num = c & 0xFFFF
            names = {0xA0: BIOS_A, 0xB0: BIOS_B, 0xC0: BIOS_C}[table]
            stubs[taddr + 4 * i] = f"{table:X}({num:#04x}) {names.get(num, '?')}"
    return stubs


def callers(taddr, words, target):
    out = []
    for i, w in enumerate(words):
        if w >> 26 == 3:  # jal
            pc = taddr + 4 * i
            dest = (pc & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if dest == target:
                out.append(pc)
    return out


def refs(taddr, words, targets, slack=0x40):
    """Pair each lui with the next addiu/ori/load/store using the same register."""
    hits = []
    for i, w in enumerate(words):
        if w >> 26 != 0x0F:  # lui
            continue
        rt = (w >> 16) & 31
        hi = (w & 0xFFFF) << 16
        for j in range(i + 1, min(i + 12, len(words))):
            x = words[j]
            op, rs, xrt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
            if rs == rt and op in (0x09, 0x0D, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B):
                addr = (hi | (x & 0xFFFF)) if op == 0x0D else (hi + s16(x & 0xFFFF)) & 0xFFFFFFFF
                for t in targets:
                    if t - slack <= addr <= t + slack:
                        hits.append((taddr + 4 * i, taddr + 4 * j, addr, t))
                if xrt == rt and op not in (0x28, 0x29, 0x2B):
                    break  # register overwritten
            elif xrt == rt and op not in (0x28, 0x29, 0x2B, 0x02, 0x03, 0x04, 0x05):
                break
    return hits


def main():
    path, cmd = sys.argv[1], sys.argv[2]
    taddr, words = load(path)
    if cmd == "bios":
        stubs = bios_stubs(taddr, words)
        for addr, name in sorted(stubs.items()):
            cs = callers(taddr, words, addr)
            print(f"{addr:#010x}  {name:32} called from {', '.join(hex(c) for c in cs) or '-'}")
    elif cmd == "callers":
        t = int(sys.argv[3], 16)
        for c in callers(taddr, words, t):
            print(hex(c))
    elif cmd == "refs":
        ts = [int(a, 16) for a in sys.argv[3:]]
        for lui, use, addr, t in refs(taddr, words, ts):
            print(f"lui at {lui:#010x}, used at {use:#010x} -> {addr:#010x} (target {t:#010x}{addr - t:+#x})")


if __name__ == "__main__":
    main()
