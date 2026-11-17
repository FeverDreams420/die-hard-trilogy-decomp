/* DH2 0x80083EA8: SetPolyF3 (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void SetPolyF3(void *p) {
    ((P_TAG *)p)->len = 4;
    ((P_TAG *)p)->code = 0x20;
}
