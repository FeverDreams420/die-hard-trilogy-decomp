/* DH2 0x80083DA4: AddPrim (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

void AddPrim(void *ot, void *p) {
    ((P_TAG *)p)->addr = ((P_TAG *)ot)->addr;
    ((P_TAG *)ot)->addr = (unsigned long)p;
}
