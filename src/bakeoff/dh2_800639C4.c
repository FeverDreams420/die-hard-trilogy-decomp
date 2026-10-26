/* DH2 0x800639C4 (also DH3 0x800650D0): product of two fields, and that /32 with a minimum of 1. */

typedef struct {
    char pad0[0x2A];
    short f2A;
    char pad1[0x38 - 0x2C];
    unsigned int f38;
    unsigned int f3C;
    char pad2[0x46 - 0x40];
    short f46;
} Obj;

void func_800639C4(Obj *o) {
    o->f38 = o->f2A * o->f46;
    o->f3C = o->f38 >> 5;
    if (o->f3C == 0) {
        o->f3C = 1;
    }
}
