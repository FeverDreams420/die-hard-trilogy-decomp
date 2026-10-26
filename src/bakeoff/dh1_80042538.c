/* DH1 0x80042538: append an object to a list and clear two fields. */

typedef struct {
    char pad[0x2A];
    short f2A;
    short f2C;
} Obj;

extern short D_800A2F3C;
extern Obj *D_800A5E90[];

void func_80042538(Obj *o) {
    D_800A5E90[D_800A2F3C] = o;
    o->f2C = 0;
    o->f2A = 0;
    D_800A2F3C++;
}
