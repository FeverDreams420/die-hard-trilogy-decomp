/* LOADER 0x800307EC (also DH2 0x8006AFFC, DH3 0x8006E6B4): push a byte into a 16-entry ring. */

extern unsigned char D_800516A8;     /* gp+0x204: write index */
extern char D_80056A10[16];

void func_800307EC(char c) {
    D_800516A8 = (D_800516A8 + 1) % 16;
    D_80056A10[D_800516A8] = c;
}
