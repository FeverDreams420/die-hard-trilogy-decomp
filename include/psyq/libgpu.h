#ifndef LIBGPU_H
#define LIBGPU_H

#include "types.h"

/* Header word shared by every GPU primitive: the low 24 bits link to the next
 * primitive in an ordering table, the top byte is the primitive's length in
 * words (not counting the header). */
typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    u8 r0, g0, b0, code;
} P_TAG;

#define setlen(p, _len) (((P_TAG *)(p))->len = (u8)(_len))
#define setcode(p, _code) (((P_TAG *)(p))->code = (u8)(_code))
#define setaddr(p, _addr) (((P_TAG *)(p))->addr = (u32)(_addr))
#define getaddr(p) (u32)(((P_TAG *)(p))->addr)

#endif /* LIBGPU_H */
