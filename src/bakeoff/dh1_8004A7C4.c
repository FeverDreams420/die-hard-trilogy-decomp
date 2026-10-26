/* Phase 4 bake-off leaf: DH1 0x8004A7C4 (also DH2 0x8005E828, DH3 0x8006007C). */

int func_8004A7C4(int a, int b, int c) {
    int t;

    if (b <= 0) {
        t = (b * c) >> 12;
    } else {
        t = b >> 2;
    }
    return a + t;
}
