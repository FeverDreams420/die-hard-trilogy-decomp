/* LOADER 0x80030A90 (also SLIDE, DH1 0x8003E414, DH2, DH3): pointer from a 16-byte table entry's offset. */

typedef struct {
    int a;
    int offset;
    int c;
    int d;
} Entry16;

void *func_80030A90(Entry16 *base, short i) {
    Entry16 *e = &base[i];

    return (char *)base + e->offset;
}
