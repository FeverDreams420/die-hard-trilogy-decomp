/* DH2 0x8008208C: SetPriority (PsyQ library). */

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    unsigned char r0, g0, b0, code;
} P_TAG;

typedef struct {
    unsigned long tag;
    unsigned long code[2];
} DR_PRIO;

void SetPriority(DR_PRIO *p, int pbc, int pbw) {
    ((P_TAG *)p)->len = 2;
    p->code[0] = 0xE6000000 | (pbc ? 2 : 0) | (pbw != 0);
    p->code[1] = 0;
}
