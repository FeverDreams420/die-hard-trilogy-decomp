/* LOADER 0x80026254 (also SLIDE, DH2, DH3): round a + b up to a multiple of 4. */

int func_80026254(int a, int b) {
    return (a + b + 3) & ~3;
}
