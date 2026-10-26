/* DH1 0x80067E60: same ring push as LOADER 0x800307EC, other addresses. */

extern unsigned char D_800A2C08;     /* gp+0x21C: write index */
extern char D_800A7FF0[16];

void func_80067E60(char c) {
    D_800A2C08 = (D_800A2C08 + 1) % 16;
    D_800A7FF0[D_800A2C08] = c;
}
