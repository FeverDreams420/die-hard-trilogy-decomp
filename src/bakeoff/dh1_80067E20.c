/* DH1 0x80067E20: clear the ring that 0x80067E60 pushes into. */

extern unsigned char D_800A2C08;     /* gp+0x21C */
extern char D_800A7FF0[16];

void func_80067E20(void) {
    short i;

    for (i = 0; i < 16; i++) {
        D_800A7FF0[i] = 0;
    }
    D_800A2C08 = 0;
}
