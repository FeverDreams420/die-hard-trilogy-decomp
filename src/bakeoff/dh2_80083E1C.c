/* DH2 0x80083E1C: CatPrim (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void CatPrim(void *p0, void *p1) {
    ((P_TAG *)p0)->addr = (unsigned long)p1;
}
