/* DH1 0x80061A30 (also DH2 0x80035420, DH3 0x800609F8): *table[i].p - 1. */

typedef struct {
    int *p;
    int pad[3];
} Entry16;

extern Entry16 *D_800A353C;

int func_80061A30(short i) {
    return *D_800A353C[i].p - 1;
}
