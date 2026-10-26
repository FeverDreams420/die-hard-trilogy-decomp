/* DH1 0x80023400 (also DH3 0x80029BB8): 16 flags -> 0 or 0xFFFF. */

extern unsigned short D_801FC0D8[16];

void func_80023400(unsigned short *src) {
    unsigned short i;

    for (i = 0; i < 16; i++) {
        if (src[i] == 0) {
            D_801FC0D8[i] = 0;
        } else {
            D_801FC0D8[i] = 0xFFFF;
        }
    }
}
