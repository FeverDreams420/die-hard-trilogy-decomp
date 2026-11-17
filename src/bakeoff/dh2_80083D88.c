/* DH2 0x80083D88: IsEndPrim (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

int IsEndPrim(void *p) {
    return ((P_TAG *)p)->addr == 0xFFFFFF;
}
