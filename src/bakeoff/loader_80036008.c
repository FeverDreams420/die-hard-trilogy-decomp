/* LOADER 0x80036008 (also DH2 0x8007891C, DH3 0x80077D64): skip to the first digit. */

char *func_80036008(char *s) {
    while (*s < '0' || *s > '9') {
        s++;
    }
    return s;
}
