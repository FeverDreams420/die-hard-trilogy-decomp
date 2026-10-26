/* DH1 0x80023400 (also DH3 0x80029BB8): 16 flags -> 0 or 0xFFFF. */

extern unsigned short D_801FC0D8[16];

void func_80023400(unsigned short *src) {
    unsigned short *dst = D_801FC0D8;
    unsigned short i;
    int unused[2];

    for (i = 0; i < 16; i++) {
        if (*src == 0) {
            *dst = 0;
        } else {
            *dst = 0xFFFF;
        }
        dst++;
        src++;
    }
}
