#ifndef LIBSPU_H
#define LIBSPU_H

#include "types.h"

#define SPU_VOICE_VOLL (0x01 << 0)
#define SPU_VOICE_VOLR (0x01 << 1)

#define SPU_COMMON_MVOLL (0x01 << 0)
#define SPU_COMMON_MVOLR (0x01 << 1)

typedef struct {
    short left;
    short right;
} SpuVolume;

typedef struct {
    unsigned long voice;
    unsigned long mask;
    SpuVolume volume;
    SpuVolume volmode;
    SpuVolume volumex;
    unsigned short pitch;
    unsigned short note;
    unsigned short sample_note;
    short envx;
    unsigned long addr;
    unsigned long loop_addr;
    long a_mode;
    long s_mode;
    long r_mode;
    unsigned short ar;
    unsigned short dr;
    unsigned short sr;
    unsigned short rr;
    unsigned short sl;
    unsigned short adsr1;
    unsigned short adsr2;
} SpuVoiceAttr;

typedef struct {
    SpuVolume volume;
    long reverb;
    long mix;
} SpuExtAttr;

typedef struct {
    unsigned long mask;
    SpuVolume mvol;
    SpuVolume mvolmode;
    SpuVolume mvolx;
    SpuExtAttr cd;
    SpuExtAttr ext;
} SpuCommonAttr;

void SpuSetVoiceAttr(SpuVoiceAttr *arg);
void SpuSetCommonAttr(SpuCommonAttr *attr);

#endif
