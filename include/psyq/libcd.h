#ifndef LIBCD_H
#define LIBCD_H

#include "types.h"

/* CD-ROM position in BCD minutes, seconds and sectors (75 per second). */
typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;

#define btoi(b) ((b) / 16 * 10 + (b) % 16)
#define itob(i) ((i) / 10 * 16 + (i) % 10)

#endif /* LIBCD_H */
