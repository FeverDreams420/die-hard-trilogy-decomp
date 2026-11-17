/* DH2 0x80083C44: GetClut (PsyQ library). */

unsigned short GetClut(int x, int y) {
    return (y << 6) | ((x >> 4) & 0x3F);
}
