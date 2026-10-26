/* LOADER 0x80030AA8 (also SLIDE, DH1 0x8003E42C, DH2, DH3): field 8 of a 16-byte table entry. */

typedef struct {
    int a;
    int offset;
    int c;
    int d;
} Entry16;

int func_80030AA8(Entry16 *base, short i) {
    Entry16 *e = &base[i];

    return e->c;
}
