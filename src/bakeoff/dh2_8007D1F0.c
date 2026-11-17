/* DH2 0x8007D1F0: CdPosToInt (PsyQ library). */

typedef struct {
    unsigned char minute;
    unsigned char second;
    unsigned char sector;
    unsigned char track;
} CdlLOC;

#define btoi(b) ((b) / 16 * 10 + (b) % 16)

int CdPosToInt(CdlLOC *p) {
    return (btoi(p->minute) * 60 + btoi(p->second)) * 75 + btoi(p->sector) - 150;
}
