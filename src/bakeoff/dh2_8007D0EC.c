/* DH2 0x8007D0EC: CdIntToPos (PsyQ library). */

typedef struct {
    unsigned char minute;
    unsigned char second;
    unsigned char sector;
    unsigned char track;
} CdlLOC;

#define itob(i) ((i) / 10 * 16 + (i) % 10)

CdlLOC *CdIntToPos(int i, CdlLOC *p) {
    int sec, min;

    i += 150;
    sec = i / 75;
    p->sector = itob(i % 75);
    min = sec / 60;
    sec %= 60;
    p->second = itob(sec);
    p->minute = itob(min);
    return p;
}
