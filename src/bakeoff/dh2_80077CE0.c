/* DH2 0x80077CE0 (also DH3 0x80077128): sum of size/4 words, last first. */

int func_80077CE0(int *p, unsigned int size) {
    int sum = 0;
    unsigned int n = size >> 2;

    while (n--) {
        sum += p[n];
    }
    return sum;
}
