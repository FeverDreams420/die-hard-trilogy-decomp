/* LOADER 0x80030AC0 (also DH2 0x80072798, DH3 0x80071BE0): field 12 of a 16-byte table entry. */

typedef struct {
    int a;
    int offset;
    int c;
    int d;
} Entry16;

int func_80030AC0(Entry16 *base, short i) {
    return base[i].d;
}
