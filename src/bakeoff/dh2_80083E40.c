/* DH2 0x80083E40: TermPrim (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void TermPrim(void *p) {
    ((P_TAG *)p)->addr = 0xFFFFFF;
}
