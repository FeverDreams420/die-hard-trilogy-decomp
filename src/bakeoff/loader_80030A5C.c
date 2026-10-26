/* LOADER 0x80030A5C (also SLIDE, DH2, DH3): fixed-point lerp, t in 1/4096. */

int func_80030A5C(int a, int b, int t) {
    return (a * (0x1000 - t) + t * b) >> 12;
}
