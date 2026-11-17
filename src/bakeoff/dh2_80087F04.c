/* DH2 0x80087F04: memmove (PsyQ library). */

char *memmove(char *dst, char *src, int n) {
    if (dst >= src) {
        while (n-- > 0) {
            dst[n] = src[n];
        }
    } else {
        while (n-- > 0) {
            *dst++ = *src++;
        }
    }
    return dst;
}
