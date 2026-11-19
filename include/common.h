#ifndef COMMON_H
#define COMMON_H

/* Included first by every C file (splat's generated_c_preamble). */

#include "include_asm.h"
#include "types.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* FAKE: stores the caller's return address ($ra) straight into a global.
 * The original code does this with a single `sw $ra` right after the
 * prologue; plain C under GCC 2.5.7 cannot express it
 * (__builtin_return_address(0) reloads $ra from the stack frame instead).
 * The original was probably a developer debug macro whose real source may
 * turn up later. Used by four task-list functions only; the PC port drops
 * the line. */
#define GET_RA(var) __asm__ volatile("sw $31, %0" : "=m"(var))

/* FAKE: debug trap. Several DH2 task functions end in a bare `break 7`
 * with no division next to it, which no GCC 2.5.7 C construct produces, so
 * the original most likely wrote it as inline asm. The PC port replaces it
 * with abort(). maspsx reads a single `break` operand as a 20-bit code and
 * splits it into two fields, so 7 << 10 is what yields the original
 * encoding (0x0007000D, the same word ASPSX emits for `break 7`). */
#define TRAP() __asm__ volatile("break 0x1C00")

#endif /* COMMON_H */
