#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/*
 * INCLUDE_ASM pulls a not-yet-decompiled function's splat assembly into a C file.
 *
 * With a non-zero -G, GCC 2.7.2 moves all functions after the data in its
 * output, which would also move them after plain __asm__ statements. So each
 * include is wrapped in a dummy function whose name maspsx recognises: maspsx
 * drops the wrapper and keeps only the lines marked "# maspsx-keep"
 * (see tools/maspsx/README.md, "INCLUDE_ASM reordering workaround hack").
 *
 * splat wrote this file once; config/*.yaml set generate_asm_macros_files: no
 * so it is not overwritten.
 */

#if !defined(M2CTX) && !defined(PERMUTER)

#define INCLUDE_ASM(FOLDER, NAME) \
    void __maspsx_include_asm_hack_##NAME() { \
        __asm__( \
            ".text # maspsx-keep\n" \
            "\t.align\t2 # maspsx-keep\n" \
            "\t.set noreorder # maspsx-keep\n" \
            "\t.set noat # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            "\t.set reorder # maspsx-keep\n" \
            "\t.set at # maspsx-keep\n" \
        ); \
    }

#define INCLUDE_RODATA(FOLDER, NAME) \
    void __maspsx_include_asm_hack_rodata_##NAME() { \
        __asm__( \
            ".section .rodata # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            ".text # maspsx-keep\n" \
        ); \
    }

__asm__(".include \"include/macro.inc\"\n");

#else

#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif /* !defined(M2CTX) && !defined(PERMUTER) */

#endif /* INCLUDE_ASM_H */
