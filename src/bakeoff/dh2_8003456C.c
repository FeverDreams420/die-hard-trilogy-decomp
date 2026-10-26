/* DH2 0x8003456C (also DH3 0x80047FF8): add two 3-short vectors. */

typedef struct {
    short x, y, z;
} SVec3;

void func_8003456C(SVec3 *a, SVec3 *b, SVec3 *out) {
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}
