/* DH2 0x80083DE0: AddPrims (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void AddPrims(void *ot, void *p0, void *p1) {
    ((P_TAG *)p1)->addr = ((P_TAG *)ot)->addr;
    ((P_TAG *)ot)->addr = (unsigned long)p0;
}
