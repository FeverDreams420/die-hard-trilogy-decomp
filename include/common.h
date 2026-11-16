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

#endif /* COMMON_H */
