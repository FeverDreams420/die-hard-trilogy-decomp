#ifndef TASK_H
#define TASK_H

/* Task list entry shared by the DH2 and DH3 engines. */

#include "common.h"

typedef struct {
    s32 pad0;
    s32 vals[3];
} Unk800A317CVals;

struct Task {
    void (*func)(void);
    void (*saved)(void);
    void (*cleanup)(void);
    struct Task *next;
    struct Task *prev;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    char pad1A[2];
    Unk800A317CVals *vals;
    s32 id;
    s32 flags;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    s16 unk2C;
    u8 unk2E;
    u8 unk2F;
};

#endif
