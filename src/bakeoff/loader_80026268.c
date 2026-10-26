/* LOADER 0x80026268 (also SLIDE, DH2, DH3): round up to a multiple of 4. */

int func_80026268(int a) {
    return (a + 3) & ~3;
}
