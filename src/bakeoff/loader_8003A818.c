/* LOADER 0x8003A818 (also SLIDE, DH1 0x80070C9C, DH2, DH3): copy a 3-int vector into an object. */

typedef struct {
    int x, y, z;
} Vec3;

typedef struct {
    char pad[0x14];
    Vec3 v;
} Obj;

Obj *func_8003A818(Obj *o, Vec3 *v) {
    o->v = *v;
    return o;
}
