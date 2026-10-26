/* LOADER 0x80026278 (also SLIDE, DH1 0x800437C8, DH2, DH3): move cur toward target by step. */

int func_80026278(int cur, int target, int step) {
    int diff = cur - target;

    if (diff == 0) {
        return cur;
    }
    if (diff < 0) {
        if (-diff < step) {
            return target;
        }
        return cur + step;
    }
    if (diff < step) {
        return target;
    }
    return cur - step;
}
