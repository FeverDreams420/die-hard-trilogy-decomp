/* DH2 0x80083D6C: NextPrim (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void *NextPrim(void *p) {
    return (void *)(((P_TAG *)p)->addr | 0x80000000);
}
