#ifndef LIBSPU_H
#define LIBSPU_H

#include "types.h"

#define SPU_VOICE_VOLL (0x01 << 0)
#define SPU_VOICE_VOLR (0x01 << 1)
#define SPU_VOICE_VOLMODEL (0x01 << 2)
#define SPU_VOICE_VOLMODER (0x01 << 3)
#define SPU_VOICE_PITCH (0x01 << 4)
#define SPU_VOICE_NOTE (0x01 << 5)
#define SPU_VOICE_SAMPLE_NOTE (0x01 << 6)
#define SPU_VOICE_WDSA (0x01 << 7)
#define SPU_VOICE_ADSR_AMODE (0x01 << 8)
#define SPU_VOICE_ADSR_SMODE (0x01 << 9)
#define SPU_VOICE_ADSR_RMODE (0x01 << 10)
#define SPU_VOICE_ADSR_AR (0x01 << 11)
#define SPU_VOICE_ADSR_DR (0x01 << 12)
#define SPU_VOICE_ADSR_SR (0x01 << 13)
#define SPU_VOICE_ADSR_RR (0x01 << 14)
#define SPU_VOICE_ADSR_SL (0x01 << 15)

#define SPU_COMMON_MVOLL (0x01 << 0)
#define SPU_COMMON_MVOLR (0x01 << 1)
#define SPU_COMMON_CDVOLL (0x01 << 6)
#define SPU_COMMON_CDVOLR (0x01 << 7)
#define SPU_COMMON_CDREV (0x01 << 8)
#define SPU_COMMON_CDMIX (0x01 << 9)

#define SPU_REV_MODE (0x01 << 0)
#define SPU_REV_DEPTHL (0x01 << 1)
#define SPU_REV_DEPTHR (0x01 << 2)
#define SPU_REV_DELAYTIME (0x01 << 3)
#define SPU_REV_FEEDBACK (0x01 << 4)
#define SPU_REV_MODE_OFF 0

#define SPU_OFF 0
#define SPU_ON 1
#define SPU_ALLCH 0xFFFFFF
#define SPU_TRANSFER_BY_DMA 0
#define SPU_VOICE_LINEARIncN 1
#define SPU_VOICE_LINEARDecN 3

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

typedef struct {
    unsigned long mask;
    long mode;
    SpuVolume depth;
    long delay;
    long feedback;
} SpuReverbAttr;

void SpuSetVoiceAttr(SpuVoiceAttr *arg);
void SpuSetCommonAttr(SpuCommonAttr *attr);
void SpuStart(void);
long SpuInitMalloc(long num, char *top);
long SpuSetTransferMode(long mode);
long SpuReserveReverbWorkArea(long on_off);
long SpuSetReverbModeParam(SpuReverbAttr *attr);
long SpuSetReverb(long on_off);
void SsUtReverbOff(void);

#endif
