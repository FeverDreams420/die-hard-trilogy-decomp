/* DH2 0x80083D2C: DumpClut (PsyQ library). */

extern char D_8008922C[];
extern int (*D_800A3F40)(char *fmt, ...);

void DumpClut(unsigned short clut) {
    (*D_800A3F40)(D_8008922C, (clut & 0x3F) << 4, clut >> 6);
}
