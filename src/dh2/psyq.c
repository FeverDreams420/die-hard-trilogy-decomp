#include "common.h"
#include "psyq/libgpu.h"
#include "psyq/libcd.h"

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", start);

void func_80078F5C(void) {
}

void SpuSetVoiceAttr(void *attr) {
    _SpuSetVoiceAttr(attr, 0, 0x17, 0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuSetVoiceAttr);

extern volatile u16 *D_800A2198;
extern u32 D_800A224C;

int SpuGetKeyStatus(u32 voice) {
    int i;
    int ch = -1;
    u16 env;

    for (i = 0; i < 24; i++) {
        if (voice & (1 << i)) {
            ch = i;
            break;
        }
    }
    if (ch == -1) {
        return -1;
    }
    env = D_800A2198[ch * 8 + 6];
    if (D_800A224C & (1 << ch)) {
        if (env) {
            return 1;
        }
        return 3;
    }
    if (env) {
        return 2;
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_note2pitch);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_pitch2note);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetReverbModeParam);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_setReverbAttr);

/* One block of the SPU RAM allocation table set up by SpuInitMalloc. The top
 * bits of addr flag the entry: 0x80000000 free, 0x40000000 end of table. */
typedef struct {
    u32 addr;
    u32 size;
} SpuMallocRec;

extern SpuMallocRec *D_800A265C;

int _SpuIsInAllocateArea(u32 addr) {
    int i;
    u32 a;

    for (i = 0;; i++) {
        a = D_800A265C[i].addr;
        if (a & 0x80000000) {
            continue;
        }
        if (a & 0x40000000) {
            break;
        }
        a &= 0x0FFFFFFF;
        if (a >= addr || addr < a + D_800A265C[i].size) {
            return 1;
        }
    }
    return 0;
}

extern SpuMallocRec *D_800A265C;
extern int D_800A21BC;

int _SpuIsInAllocateArea_(u32 addr) {
    int i;
    u32 a;

    addr <<= D_800A21BC;
    for (i = 0;; i++) {
        a = D_800A265C[i].addr;
        if (a & 0x80000000) {
            continue;
        }
        if (a & 0x40000000) {
            break;
        }
        a &= 0x0FFFFFFF;
        if (a >= addr || addr < a + D_800A265C[i].size) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetCommonAttr);

extern volatile u16 *D_800A2198;

int _spu_reset(void) {
    volatile int i, n;
    u16 c = D_800A2198[0xD5];

    D_800A2198[0xD5] = c & 0x7FCF;
    n = 13;
    for (i = 0; i < 240; i++) {
        n *= 3;
    }
    c &= 0xFFCF;
    D_800A2198[0xD5] = c;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_init);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_writeByIO);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FiDMA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_r_);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_t);

extern int D_800A21B0;
extern u16 D_800A2194;
extern int D_800A21BC;

int _spu_write(u8 *addr, u32 size) {
    if (D_800A21B0 == 0) {
        _spu_t(2, D_800A2194 << D_800A21BC);
        _spu_t(1);
        _spu_t(3, addr, size);
    } else {
        _spu_writeByIO(addr, size);
    }
    return size;
}

extern u16 D_800A2194;
extern int D_800A21BC;

int _spu_read(int addr, int size) {
    _spu_t(2, D_800A2194 << D_800A21BC);
    _spu_t(0);
    _spu_t(3, addr, size);
    return size;
}

extern volatile u16 *D_800A2198;
extern int D_800A21BC;

void _spu_FsetRXX(int index, u32 value, int mode) {
    if (mode == 0) {
        D_800A2198[index] = value;
    } else {
        D_800A2198[index] = value >> D_800A21BC;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FsetRXXa);

extern volatile u16 *D_800A2198;
extern int D_800A21BC;

int _spu_FgetRXXa(int index, int mode) {
    u16 v = D_800A2198[index];

    if (mode == -1) {
        return v;
    }
    return v << D_800A21BC;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuClearReverbWorkArea);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuInit);

extern int D_800A2650, D_800A21F0, D_800A2248;
void _spu_FiDMA();

void SpuStart(void) {
    if (D_800A2650 == 0) {
        D_800A2650 = 1;
        func_8007FD1C();
        D_800A21F0 = 0;
        _SpuDataCallback(_spu_FiDMA);
        D_800A2248 = OpenEvent(0xF0000009, 0x20, 0x2000, 0);
        EnableEvent(D_800A2248);
        func_8007FFB4();
    }
}

void *_SpuDataCallback(void (*func)()) {
    return (void *)DMACallback(4, func);
}

void SsUtReverbOff(void) {
    _SpuInit(0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetReverb);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_8007BC3C);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuIsTransferCompleted);

extern SpuMallocRec *D_800A265C;
extern int D_800A2658, D_800A2654;
extern int D_800A21BC;

int SpuInitMalloc(int num, SpuMallocRec *top) {
    if (num > 0) {
        top->addr = 0x40001010;
        D_800A265C = top;
        D_800A2658 = 0;
        D_800A2654 = num;
        top->size = (0x10000 << D_800A21BC) - 0x1010;
        return num;
    }
    return 0;
}

extern int D_800A21F4, D_800A21B0;

void SpuSetTransferMode(int mode) {
    int m;

    switch (mode) {
    case 0:
        m = 0;
        break;
    case 1:
        m = 1;
        break;
    default:
        m = 0;
        break;
    }
    D_800A21F4 = mode;
    D_800A21B0 = m;
}

extern u16 D_800A2194;

u32 SpuSetTransferStartAddr(u32 addr) {
    D_800A2194 = _spu_FsetRXXa(-1, addr);
    return addr;
}

extern int D_800A21CC, D_800A21C8;

u32 SpuRead(u8 *addr, u32 size) {
    if (size > 0x7F000) {
        size = 0x7F000;
    }
    _spu_write(addr, size);
    if (D_800A21CC == 0) {
        D_800A21C8 = 0;
    }
    return size;
}

extern volatile u16 *D_800A2198;
extern u32 D_800A224C;

void SpuSetKey(int on, u32 voices) {
    u32 v = voices & 0xFFFFFF;
    u16 lo = v;
    u16 hi = v >> 16;
    switch (on) {
    case 1:
        D_800A2198[0xC4] = lo;
        D_800A2198[0xC5] = hi;
        D_800A224C |= v;
        break;
    case 0:
        D_800A2198[0xC6] = lo;
        D_800A2198[0xC7] = hi;
        D_800A224C &= ~v;
        break;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuMalloc);

extern int D_800A2200, D_800A21FC;

int SpuReserveReverbWorkArea(int on) {
    if (on && !_SpuIsInAllocateArea_(D_800A2200)) {
        D_800A21FC = 1;
        return 1;
    }
    D_800A21FC = 0;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_gcSPU);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", cb_read);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", cd_read_retry);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdRead);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdReadSync);

extern void *D_800A2958;

void *CdReadCallback(void *func) {
    void *old = D_800A2958;

    D_800A2958 = func;
    return old;
}

extern u8 D_800A2A18;

int CdStatus(void) {
    return D_800A2A18;
}

extern u8 D_800A2A28;

int CdMode(void) {
    return D_800A2A28;
}

extern u8 D_800A2A29;

int CdLastCom(void) {
    return D_800A2A29;
}

extern u8 D_800A2A24[];

u8 *CdLastPos(void) {
    return D_800A2A24;
}

int CdReset(int mode) {
    if (mode == 2) {
        CD_initintr();
        return 1;
    }
    if (CD_init()) {
        return 0;
    }
    if (mode == 1 && CD_initvol()) {
        return 0;
    }
    return 1;
}

void CdFlush(void) {
    CD_flush();
}

extern int D_800A2A14;

int CdSetDebug(int level) {
    int old = D_800A2A14;

    D_800A2A14 = level;
    return old;
}

extern char *D_800A2A2C[];
extern char D_80088C70[];

char *CdComstr(u8 com) {
    if (com >= 0x1C) {
        return D_80088C70;
    }
    return D_800A2A2C[com];
}

extern char *D_800A2AAC[];
extern char D_80088C70[];

char *CdIntstr(u8 intr) {
    if (intr >= 7) {
        return D_80088C70;
    }
    return D_800A2AAC[intr];
}

int CdSync(int a, int b) {
    return CD_sync(a, b);
}

int CdReady(int a, int b) {
    return CD_ready(a, b);
}

extern void *D_800A2A08;

void *CdSyncCallback(void *func) {
    void *old = D_800A2A08;

    D_800A2A08 = func;
    return old;
}

extern void *D_800A2A0C;

void *CdReadyCallback(void *func) {
    void *old = D_800A2A0C;

    D_800A2A0C = func;
    return old;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdControl);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdControlF);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdControlB);

int CdMix(void *vol) {
    CD_vol(vol);
    return 1;
}

int CdGetSector(void *madr, int size) {
    return CD_getsector(madr, size) == 0;
}

void *CdDataCallback(void (*func)()) {
    return (void *)DMACallback(3, func);
}

int CdDataSync(int a, int b) {
    return CD_datasync(a, b);
}

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

int CdPosToInt(CdlLOC *p) {
    return (btoi(p->minute) * 60 + btoi(p->second)) * 75 + btoi(p->sector) - 150;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_cw);

extern volatile u8 *D_800A2CCC, *D_800A2CD0, *D_800A2CD4, *D_800A2CD8;

int CD_vol(u8 *vol) {
    *D_800A2CCC = 2;
    *D_800A2CD4 = vol[0];
    *D_800A2CD8 = vol[1];
    *D_800A2CCC = 3;
    *D_800A2CD0 = vol[2];
    *D_800A2CD4 = vol[3];
    *D_800A2CD8 = 0x20;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_flush);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_initvol);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_initintr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_init);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_datasync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_getsector);

extern int D_800A2CB0;

void CD_set_test_parmnum(int n) {
    D_800A2CB0 = n;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", callback);

extern char D_80088EC8[];

void def_cbsync(void);
void def_cbready(void);
void def_cbread(void);

int CdInit(void) {
    int i = 4;

retry:
    if (CdReset(1) != 1) {
        if (i-- != 0) {
            goto retry;
        }
        printf(D_80088EC8);
        return 0;
    }
    CdSyncCallback(def_cbsync);
    CdReadyCallback(def_cbready);
    CdReadCallback(def_cbread);
    return 1;
}

void def_cbsync(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void def_cbready(void) {
    DeliverEvent(0xF0000003, 0x40);
}

void def_cbread(void) {
    DeliverEvent(0xF0000003, 0x40);
}

extern int D_800BD970;
void data_ready_callback(void);
void StCdInterrupt2(void);

int CdRead2(int mode) {
    u8 param[4];

    param[0] = mode;
    CdControl(0xE, param, 0);
    if (mode & 0x100) {
        if (mode & 0x20) {
            D_800BD970 = 0;
        } else {
            D_800BD970 = 1;
        }
        CdDataCallback(data_ready_callback);
        CdReadyCallback(StCdInterrupt2);
    }
    return CdControl(0x1B, 0, 0);
}

void StCdInterrupt2(void) {
    StCdInterrupt();
}

extern int D_801F95A8, D_800BD96C, D_801C99A0, D_80169FB8, D_800BD674;
extern void *D_8015EB34, *D_8015EB38;
extern s16 D_800BD968;

void StSetStream(int mode, int start, int end, void *func1, void *func2) {
    func_8007F99C(1, start, end);
    D_801F95A8 = 0;
    D_8015EB34 = func1;
    D_800BD96C = mode & 1;
    D_801C99A0 = 0;
    D_80169FB8 = 0;
    D_800BD968 = 0;
    D_800BD674 = 0;
    D_8015EB38 = func2;
}

int CdGetToc(void *loc) {
    return CdGetToc2(1, loc);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdGetToc2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StCdInterrupt);

void mem2mem(u32 *dst, u32 *src, u32 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", dma_execute);

extern u32 *D_801F9640;

int init_ring_status(int start, u32 n) {
    u32 i;
    u32 *p;

    for (i = 0; i < n; i++) {
        p = &D_801F9640[(i + start) * 8];
        *p = 0;
    }
}

extern s32 D_80169FBC;
extern s32 D_801F95AC;
extern s32 D_801F9638;

void func_8007F99C(s32 arg0, s32 arg1, s32 arg2) {
    D_801F9638 = arg0;
    D_80169FBC = arg1;
    D_801F95AC = arg2;
}

extern u32 *D_801F9640;
extern u32 D_801F9DEC;

void StSetRing(u32 *ring_addr, u32 ring_size) {
    D_801F9640 = ring_addr;
    D_801F9DEC = ring_size;
    StClearRing();
}

extern int D_801F92B0, D_801F92AC, D_801F92A8, D_801D9D98;
extern u32 D_801F9DEC;
extern int D_8015EB64, D_800BD674;
extern s16 D_800BD968;

void StClearRing(void) {
    D_801F92B0 = 0;
    D_801F92AC = 0;
    D_801F92A8 = 0;
    D_801D9D98 = 0;
    init_ring_status(0, D_801F9DEC);
    D_8015EB64 = 0;
    D_800BD968 = 0;
    D_800BD674 = 0;
}

extern u32 *D_801F9640;
extern u32 D_801F9DEC;
extern int D_801F92B0;
extern s32 D_801F95AC;

int StGetNext(u32 **addr, u32 **header) {
    volatile u16 *p = (u16 *)&D_801F9640[D_801F92B0 * 8];

    if (*p == 1) {
        D_801F92B0 = 0;
        if (D_801F95AC != 0) {
            *p = 0;
        }
        p = (u16 *)&D_801F9640[D_801F92B0 * 8];
    }
    if (*p != 2) {
        return 1;
    }
    *p = 4;
    *addr = (u32 *)((u8 *)&D_801F9640[D_801F9DEC * 8] + D_801F92B0 * 2016);
    *header = (u32 *)p;
    return 0;
}

extern u32 *D_801F9640;
extern int D_801F92AC, D_801F92A8, D_801D9D98, D_800B78C4;
extern u8 D_800B78C0[];
extern void *D_8015EB34;

void data_ready_callback(void) {
    u32 *p = &D_801F9640[D_801F92AC * 8];

    *(u16 *)p = 2;
    *(CdlLOC *)D_800B78C0 = *(CdlLOC *)&p[7];
    D_800B78C4 = p[2];
    D_801F92AC = D_801F92A8;
    if (D_8015EB34) {
        ((void (*)())D_8015EB34)();
    }
    D_801D9D98 = 0;
}

extern int D_800BD970, D_800B78C4;
extern u8 D_800B78C0[];

int StGetBackloc(u8 *loc) {
    if (D_800BD970 != 0) {
        return -1;
    }
    CdIntToPos(CdPosToInt(D_800B78C0) + 1, loc);
    return D_800B78C4;
}

extern u32 *D_801F9640;
extern u32 D_801F9DEC;
extern int D_801F92B0;

int StFreeRing(u32 *base) {
    int i, k;
    s16 n;
    s16 *p;

    k = (base - &D_801F9640[D_801F9DEC * 8]) / 504;
    p = (s16 *)&D_801F9640[k * 8];
    n = p[3];
    if (p[0] != 4) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        *(u16 *)&D_801F9640[(i + k) * 8] = 0;
    }
    D_801F92B0 = i + k;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _card_info);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _card_auto);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StopCARD);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StartCARD);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _card_read);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CloseEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_8007FD1C);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", close);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", write);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SysDeqIntRP);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SysEnqIntRP);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", EnableEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", delete);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", format);

extern volatile u16 *D_800A2DE8;

int SetRCnt(int spec, u16 target, int mode) {
    int i = spec & 0xFFFF;
    u16 m = 0x48;

    if (i >= 3) {
        return 0;
    }
    D_800A2DE8[i * 8 + 2] = 0;
    D_800A2DE8[i * 8 + 4] = target;
    if (i == 0 || i == 1) {
        if (mode & 0x10) {
            m = 0x49;
        }
        if (!(mode & 1)) {
            m |= 0x100;
        }
    } else if (i == 2) {
        if (!(mode & 1)) {
            m = 0x248;
        }
    }
    if (mode & 0x1000) {
        m |= 0x10;
    }
    D_800A2DE8[i * 8 + 2] = m;
    return 1;
}

extern volatile u16 *D_800A2DE8;

int GetRCnt(int spec) {
    int i = spec & 0xFFFF;

    if (i >= 3) {
        return 0;
    }
    return D_800A2DE8[i * 8];
}

extern volatile u32 *D_800A2DE4;
extern u32 D_800A2DEC[];

int StartRCnt(int spec) {
    spec &= 0xFFFF;
    D_800A2DE4[1] |= D_800A2DEC[spec];
    return spec < 3;
}

extern volatile u32 *D_800A2DE4;
extern u32 D_800A2DEC[];

int StopRCnt(int spec) {
    spec &= 0xFFFF;
    D_800A2DE4[1] &= ~D_800A2DEC[spec];
    return 1;
}

extern volatile u16 *D_800A2DE8;

int ResetRCnt(int spec) {
    int i = spec & 0xFFFF;

    if (i >= 3) {
        return 0;
    }
    D_800A2DE8[i * 8] = 0;
    return 1;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DisableEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DeliverEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", InitHeap);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _bu_init);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", nextfile);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", Exec);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", OpenEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", read);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", WaitEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", TestEvent);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_8007FFB4);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ChangeClearRCnt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", open);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", firstfile);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FlushCache);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80080004);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80080014);

extern void *D_800A2DFC;

void *func_80080024(void *func) {
    void *old = D_800A2DFC;

    D_800A2DFC = func;
    return old;
}

extern void *D_800A2DFC;

void *func_8008003C(void) {
    return D_800A2DFC;
}

extern int D_801D9B14;
extern u32 D_800B78C8;

void PadInit(int mode) {
    D_801D9B14 = mode;
    D_800B78C8 = -1;
    ResetCallback();
    PAD_init(0x20000001, &D_800B78C8);
    ChangeClearPAD(0);
}

extern u32 D_800B78C8;

u32 PadRead(int id) {
    PAD_dr();
    return ~D_800B78C8;
}

void PadStop(void) {
    StopPAD();
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PAD_dr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PAD_init);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ChangeClearPAD);

extern int (**D_800A3E88)();

int ResetCallback(void) {
    return D_800A3E88[3]();
}

extern int (**D_800A3E88)();

int InterruptCallback(int a, int b) {
    return D_800A3E88[2](a, b);
}

extern int (**D_800A3E88)();

int DMACallback(int a, int b) {
    return D_800A3E88[1](a, b);
}

extern int (**D_800A3E88)();

int VSyncCallback(void (*func)()) {
    return D_800A3E88[5](0, func);
}

extern int (**D_800A3E88)();

int VSyncCallbacks(int a, int b) {
    return D_800A3E88[5](a, b);
}

extern int (**D_800A3E88)();

int StopCallback(int a, int b) {
    return D_800A3E88[4](a, b);
}

extern int (**D_800A3E88)();

int RestartCallback(int a, int b) {
    return D_800A3E88[6](a, b);
}

extern u16 D_800A2E02;

int CheckCallback(void) {
    return D_800A2E02;
}

extern volatile u16 *D_800A3E90;

int GetIntrMask(void) {
    return *D_800A3E90;
}

extern volatile u16 *D_800A3E90;

int SetIntrMask(int mask) {
    int old = *D_800A3E90;

    *D_800A3E90 = mask;
    return old;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", startIntr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", trapIntr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", setIntr);

typedef struct {
    u16 started;
    u16 unk2[24];
    u16 mask;
    u32 dmask;
    int jmpbuf[1];
} IntrEnv;
extern IntrEnv D_800A2E00;
extern volatile u16 *D_800A3E90;
extern volatile u32 *D_800A3E94;
extern volatile u16 *D_800A3E8C;
void ResetEntryInt();

void *stopIntr(void) {
    if (D_800A2E00.started == 0) {
        return 0;
    }
    func_8007FD1C();
    D_800A2E00.mask = *D_800A3E90;
    D_800A2E00.dmask = *D_800A3E94;
    *D_800A3E8C = *D_800A3E90 = 0;
    *D_800A3E94 &= 0x77777777;
    ResetEntryInt();
    D_800A2E00.started = 0;
    return &D_800A2E00;
}

void *restartIntr(void) {
    if (D_800A2E00.started) {
        return 0;
    }
    HookEntryInt(D_800A2E00.jmpbuf);
    D_800A2E00.started = 1;
    *D_800A3E90 = D_800A2E00.mask;
    *D_800A3E94 = D_800A2E00.dmask;
    func_8007FFB4();
    return &D_800A2E00;
}

void memclr_80080800(u32 *p, int n) {
    while (n--) {
        *p++ = 0;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", HookEntryInt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ResetEntryInt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _96_remove);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ReturnFromException);

extern u32 D_800A3EA0[];
extern volatile u32 *D_800A3E9C;
void trapIntrDMA();
void *setIntrDMA();

void *startIntrDMA(void) {
    memclr_80080AE8(D_800A3EA0, 8);
    *D_800A3E9C = 0;
    InterruptCallback(3, trapIntrDMA);
    return setIntrDMA;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", trapIntrDMA);

extern u32 D_800A3EA0[];
extern volatile u32 *D_800A3E9C;

void *setIntrDMA(int ch, void (*func)()) {
    void *old = (void *)D_800A3EA0[ch];

    if (func != old) {
        if (func != 0) {
            D_800A3EA0[ch] = (u32)func;
            *D_800A3E9C = (*D_800A3E9C & 0xFFFFFF) | 0x800000 | (1 << (ch + 16));
        } else {
            D_800A3EA0[ch] = 0;
            *D_800A3E9C = ((*D_800A3E9C & 0xFFFFFF) | 0x800000) & ~(1 << (ch + 16));
        }
    }
    return old;
}

void memclr_80080AE8(u32 *p, int n) {
    while (n--) {
        *p++ = 0;
    }
}

extern void *D_800A3EC4[];
extern volatile u32 *D_800A3EE8;
extern volatile int D_800A3EE4;
void trapIntrVSync();
void setIntrVSync(int index, void *func);

void *startIntrVSync(void) {
    *D_800A3EE8 = 0x107;
    D_800A3EE4 = 0;
    memclr_80080C10(D_800A3EC4, 8);
    InterruptCallback(0, trapIntrVSync);
    return setIntrVSync;
}

extern volatile int D_800A3EE4;
extern void *D_800A3EC4[];

void trapIntrVSync(void) {
    int i;

    D_800A3EE4++;
    for (i = 0; i < 8; i++) {
        if (D_800A3EC4[i]) {
            ((void (*)())D_800A3EC4[i])();
        }
    }
}

extern void *D_800A3EC4[];

void setIntrVSync(int index, void *func) {
    if (func != D_800A3EC4[index]) {
        D_800A3EC4[index] = func;
    }
}

void memclr_80080C10(u32 *p, int n) {
    while (n--) {
        *p++ = 0;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", VSync);

extern volatile int D_800A3EE4;
extern char D_80088FD0[];

void v_wait(int n, int cnt) {
    volatile int c = cnt << 15;

    while (D_800A3EE4 < n) {
        if (--c == -1) {
            puts(D_80088FD0);
            ChangeClearPAD(0);
            ChangeClearRCnt(3, 0);
            return;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ResetGraph);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetGraphReverse);

typedef struct {
    u32 tag;
    u32 code[15];
} DR_ENV;

typedef struct {
    RECT clip;
    s16 ofs[2];
    RECT tw;
    u16 tpage;
    u8 dtd;
    u8 dfe;
    u8 isbg;
    u8 r0, g0, b0;
    DR_ENV dr_env;
} DRAWENV;

/* libgpu state at 0x800A3F40 */
typedef struct {
    int (*printf)(char *fmt, ...);
    u8 type;
    u8 queue;
    u8 debug;
    u8 reverse;
    s16 w, h;
    u8 unkC[8];
    DRAWENV draw;
    DISPENV disp;
} GpuEnv;
extern GpuEnv D_800A3F40;

extern char D_80089060[];

int SetGraphDebug(int level) {
    u8 old = D_800A3F40.debug;

    D_800A3F40.debug = level;
    if (level & 0xFF) {
        D_800A3F40.printf(D_80089060, D_800A3F40.debug, D_800A3F40.type, D_800A3F40.reverse);
    }
    return old;
}

extern u32 (**D_800A3F3C)();
extern char D_8008908C[];

int SetGraphQueue(int mode) {
    u8 old = D_800A3F40.queue;

    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_8008908C, mode);
    }
    if (mode != D_800A3F40.queue) {
        D_800A3F3C[13](1);
        D_800A3F40.queue = mode;
        DMACallback(2, 0);
    }
    return old;
}

int GetGraphType(void) {
    return D_800A3F40.type;
}


int GetGraphDebug(void) {
    return D_800A3F40.debug;
}

extern char D_800890A0[];
extern void *D_800A3F50;

void *DrawSyncCallback(void *func) {
    void *old;

    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_800890A0, func);
    }
    old = D_800A3F50;
    D_800A3F50 = func;
    return old;
}

extern u32 (**D_800A3F3C)();
extern char D_800890BC[];

void SetDispMask(int mask) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_800890BC, mask);
    }
    if (mask == 0) {
        memset_80083B40((u8 *)&D_800A3F40.disp, -1, sizeof(DISPENV));
    }
    D_800A3F3C[4](mask ? 0x03000000 : 0x03000001);
}

extern u32 (**D_800A3F3C)();
extern char D_800890D0[];

int DrawSync(int mode) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_800890D0, mode);
    }
    return D_800A3F3C[15](mode);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", checkRECT);

extern u32 (**D_800A3F3C)();
extern char D_80089108[];

int ClearImage(RECT *rect, u8 r, u8 g, u8 b) {
    checkRECT(D_80089108, rect);
    return D_800A3F3C[2](D_800A3F3C[3], rect, 8, (b << 16) | (g << 8) | r);
}

extern u32 (**D_800A3F3C)();
extern char D_80089114[];

int LoadImage(RECT *rect, u32 *p) {
    checkRECT(D_80089114, rect);
    return D_800A3F3C[2](D_800A3F3C[8], rect, 8, p);
}

extern u32 (**D_800A3F3C)();
extern char D_80089120[];

int StoreImage(RECT *rect, u32 *p) {
    checkRECT(D_80089120, rect);
    return D_800A3F3C[2](D_800A3F3C[7], rect, 8, p);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MoveImage);

extern char D_80089138[];
extern u32 D_800A4000;

u32 *ClearOTag(u32 *ot, int n) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_80089138, ot, n);
    }
    while (--n) {
        setlen(ot, 0);
        setaddr(ot, ot + 1);
        ot++;
    }
    *ot = (u32)&D_800A4000 & 0xFFFFFF;
    return ot;
}

extern u32 (**D_800A3F3C)();
extern char D_80089150[];
extern u32 D_800A4000;

u32 *ClearOTagR(u32 *ot, int n) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_80089150, ot, n);
    }
    D_800A3F3C[11](ot, n);
    *ot = (u32)&D_800A4000 & 0xFFFFFF;
    return ot;
}

extern u32 (**D_800A3F3C)();

void DrawPrim(void *p) {
    int len = ((P_TAG *)p)->len;

    D_800A3F3C[15](0);
    D_800A3F3C[5]((u32 *)p + 1, len);
}

extern u32 (**D_800A3F3C)();
extern char D_80089168[];

void DrawOTag(u32 *p) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_80089168, p);
    }
    D_800A3F3C[2](D_800A3F3C[6], p, 0, 0);
}

extern u32 (**D_800A3F3C)();
extern char D_8008917C[];

DRAWENV *PutDrawEnv(DRAWENV *env) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_8008917C, env);
    }
    SetDrawEnv(&env->dr_env, env);
    env->dr_env.tag |= 0xFFFFFF;
    D_800A3F3C[2](D_800A3F3C[6], &env->dr_env, 0x40, 0);
    memcpy(&D_800A3F40.draw, env, sizeof(DRAWENV));
    return env;
}

extern u32 (**D_800A3F3C)();
extern char D_80089194[];

void DrawOTagEnv(u32 *p, DRAWENV *env) {
    if (D_800A3F40.debug >= 2) {
        D_800A3F40.printf(D_80089194, p, env);
    }
    SetDrawEnv(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    D_800A3F3C[2](D_800A3F3C[6], &env->dr_env, 0x40, 0);
    memcpy(&D_800A3F40.draw, env, sizeof(DRAWENV));
}

extern u8 D_800A3F54[];

void *GetDrawEnv(void *env) {
    memcpy(env, D_800A3F54, 0x5C);
    return env;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PutDispEnv);

extern u8 D_800A3FB0[];

void *GetDispEnv(void *env) {
    memcpy(env, D_800A3FB0, 0x14);
    return env;
}

extern u32 (**D_800A3F3C)();

u32 GetODE(void) {
    return D_800A3F3C[14]() >> 31;
}

void SetTexWindow(u32 *p, void *tw) {
    setlen(p, 2);
    p[1] = get_tw(tw);
    p[2] = 0;
}

u32 get_cs(s16 x, s16 y);
u32 get_ce(s16 x, s16 y);

void SetDrawArea(u32 *p, RECT *r) {
    setlen(p, 2);
    p[1] = get_cs(r->x, r->y);
    p[2] = get_ce(r->x + r->w - 1, r->y + r->h - 1);
}

void SetDrawOffset(u32 *p, s16 *ofs) {
    setlen(p, 2);
    p[1] = get_ofs(ofs[0], ofs[1]);
    p[2] = 0;
}

void SetPriority(u32 *p, int pbc, int pbw) {
    setlen(p, 2);
    p[1] = 0xE6000000 | (pbc ? 2 : 0) | (pbw != 0);
    p[2] = 0;
}

u32 get_mode(int dfe, int dtd, u16 tpage);

void SetDrawMode(u32 *p, int dfe, int dtd, int tpage, void *tw) {
    setlen(p, 2);
    p[1] = get_mode(dfe, dtd, tpage);
    p[2] = get_tw(tw);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_ofs);

u32 get_tw(RECT *tw) {
    int pr[4];

    if (tw) {
        pr[0] = (tw->x & 0xFF) >> 3;
        pr[2] = (-tw->w & 0xFF) >> 3;
        pr[1] = (tw->y & 0xFF) >> 3;
        pr[3] = (-tw->h & 0xFF) >> 3;
        return 0xE2000000 | (pr[1] << 15) | (pr[0] << 10) | (pr[3] << 5) | pr[2];
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_dx);

extern volatile u32 *D_800A4018;

u32 _status(void) {
    return *D_800A4018;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _otc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _clr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _dws);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _drs);

extern volatile u32 *D_800A4018;
extern u8 D_800B790C[];

void _ctl(u32 n) {
    *D_800A4018 = n;
    D_800B790C[n >> 24] = n;
}

extern u8 D_800B790C[];

int _getctl(int n) {
    return D_800B790C[n];
}

extern volatile u32 *D_800A4018, *D_800A4014;

int _cwb(u32 *p, int n) {
    *D_800A4018 = 0x04000000;
    while (n--) {
        *D_800A4014 = *p++;
    }
    return 0;
}

extern volatile u32 *D_800A4018, *D_800A401C, *D_800A4020, *D_800A4024;

void _cwc(u32 addr) {
    *D_800A4018 = 0x04000002;
    *D_800A401C = addr;
    *D_800A4020 = 0;
    *D_800A4024 = 0x01000401;
}

extern volatile u32 *D_800A4018;
extern volatile u32 *D_800A4014;

u32 _param(u32 n) {
    *D_800A4018 = n | 0x10000000;
    return *D_800A4014 & 0xFFFFFF;
}

int _addque(int a, int b, int c) {
    return _addque2(a, b, 0, c);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _addque2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _exeque);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _reset);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _sync);

extern int D_800A405C;
extern int D_800A4060;

void set_alarm(void) {
    D_800A405C = VSync(-1) + 240;
    D_800A4060 = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_alarm);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _version);

void memset_80083B40(u8 *p, int c, int n) {
    while (n--) {
        *p++ = c;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", GPU_cw);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", GetTPage);

u16 GetClut(int x, int y) {
    return (y << 6) | ((x >> 4) & 0x3F);
}

extern char D_80089214[];

void DumpTPage(u16 tpage) {
    if (GetGraphType() == 1 || GetGraphType() == 2) {
        D_800A3F40.printf(D_80089214, (tpage >> 9) & 3, (tpage >> 7) & 3, (tpage << 6) & 0x7C0, (tpage << 3) & 0x300);
    } else {
        D_800A3F40.printf(D_80089214, (tpage >> 7) & 3, (tpage >> 5) & 3, (tpage << 6) & 0x7C0,
                          ((tpage << 4) & 0x100) + ((tpage >> 2) & 0x200));
    }
}

extern char D_8008922C[];

void DumpClut(u16 clut) {
    (*D_800A3F40.printf)(D_8008922C, (clut & 0x3F) << 4, clut >> 6);
}

void *NextPrim(void *p) {
    return (void *)(getaddr(p) | 0x80000000);
}

int IsEndPrim(void *p) {
    return getaddr(p) == 0xFFFFFF;
}

void AddPrim(void *ot, void *p) {
    setaddr(p, getaddr(ot));
    setaddr(ot, p);
}

void AddPrims(void *ot, void *p0, void *p1) {
    setaddr(p1, getaddr(ot));
    setaddr(ot, p0);
}

void CatPrim(void *p0, void *p1) {
    setaddr(p0, p1);
}

void TermPrim(void *p) {
    setaddr(p, 0xFFFFFF);
}

void SetSemiTrans(void *p, int abe) {
    if (abe) {
        ((P_TAG *)p)->code |= 2;
    } else {
        ((P_TAG *)p)->code &= ~2;
    }
}

void SetShadeTex(void *p, int tge) {
    if (tge) {
        ((P_TAG *)p)->code |= 1;
    } else {
        ((P_TAG *)p)->code &= ~1;
    }
}

void SetPolyF3(void *p) {
    setlen(p, 4);
    setcode(p, 0x20);
}

void SetPolyFT3(void *p) {
    setlen(p, 7);
    setcode(p, 0x24);
}

void SetPolyG3(void *p) {
    setlen(p, 6);
    setcode(p, 0x30);
}

void SetPolyGT3(void *p) {
    setlen(p, 9);
    setcode(p, 0x34);
}

void SetPolyF4(void *p) {
    setlen(p, 5);
    setcode(p, 0x28);
}

void SetPolyFT4(void *p) {
    setlen(p, 9);
    setcode(p, 0x2C);
}

void SetPolyG4(void *p) {
    setlen(p, 8);
    setcode(p, 0x38);
}

void SetPolyGT4(void *p) {
    setlen(p, 12);
    setcode(p, 0x3C);
}

void SetSprt8(void *p) {
    setlen(p, 3);
    setcode(p, 0x74);
}

void SetSprt16(void *p) {
    setlen(p, 3);
    setcode(p, 0x7C);
}

void SetSprt(void *p) {
    setlen(p, 4);
    setcode(p, 0x64);
}

void SetTile1(void *p) {
    setlen(p, 2);
    setcode(p, 0x68);
}

void SetTile8(void *p) {
    setlen(p, 2);
    setcode(p, 0x70);
}

void SetTile16(void *p) {
    setlen(p, 2);
    setcode(p, 0x78);
}

void SetTile(void *p) {
    setlen(p, 3);
    setcode(p, 0x60);
}

void SetLineF2(void *p) {
    setlen(p, 3);
    setcode(p, 0x40);
}

void SetLineG2(void *p) {
    setlen(p, 4);
    setcode(p, 0x50);
}

void SetLineF3(void *p) {
    setlen(p, 5);
    setcode(p, 0x48);
    ((u32 *)p)[5] = 0x55555555;
}

void SetLineG3(void *p) {
    setlen(p, 7);
    setcode(p, 0x58);
    ((u32 *)p)[7] = 0x55555555;
}

void SetLineF4(void *p) {
    setlen(p, 6);
    setcode(p, 0x4C);
    ((u32 *)p)[6] = 0x55555555;
}

void SetLineG4(void *p) {
    setlen(p, 9);
    setcode(p, 0x5C);
    ((u32 *)p)[9] = 0x55555555;
}

void SetBlockFill(void *p) {
    setlen(p, 3);
    setcode(p, 0x2);
}

void SetDrawMove(u32 *p) {
    setlen(p, 5);
    setcode(p, 1);
    p[2] = 0x80000000;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawTPage);

void SetDrawLoad(u32 *p, RECT *r) {
    int n = (r->w * r->h + 1) / 2;
    int len = n + 4;

    if (n <= 0 || n > 11) {
        len = 0;
    }
    setlen(p, len);
    p[1] = 0x01000000;
    p[2] = 0xA0000000;
    p[3] = *(u32 *)&r->x;
    p[4] = *(u32 *)&r->w;
}

int MargePrim(void *p0, void *p1) {
    int len = ((P_TAG *)p0)->len + ((P_TAG *)p1)->len + 1;

    if (len > 0x20) {
        return -1;
    }
    setlen(p0, len);
    *(u32 *)p1 = 0;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DumpDrawEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DumpDispEnv);

extern int D_800A41E4, D_800A41E8;
int FntPrint(char *fmt, ...);

void SetDumpFnt(int id) {
    if (id >= 0 && id <= D_800A41E4) {
        D_800A41E8 = id;
        D_800A3F40.printf = FntPrint;
    }
}

extern u32 D_800A41EC[];
extern u16 D_800BBE10, D_800BBE0C;
extern int D_800A41E4;
extern u8 D_800A4064[];
u16 LoadClut2(u32 *clut, int x, int y);

void FntLoad(int tx, int ty) {
    D_800BBE10 = LoadClut2(D_800A41EC, tx, ty + 0x80);
    D_800BBE0C = LoadTPage(D_800A41EC + 0x80, 0, 0, tx, ty, 0x80, 0x20);
    D_800A41E4 = 0;
    memset_80087628(D_800A4064, 0, 0x180);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntOpen);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntFlush);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntPrint);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadTPage);

u16 LoadClut(u32 *clut, int x, int y) {
    RECT rect;

    rect.x = x;
    rect.y = y;
    rect.w = 256;
    rect.h = 1;
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

u16 LoadClut2(u32 *clut, int x, int y) {
    RECT rect;

    rect.x = x;
    rect.y = y;
    rect.w = 16;
    rect.h = 1;
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

#define getTPage(tp, abr, x, y)                                                                     \
    ((GetGraphType() == 1 || GetGraphType() == 2)                                                   \
         ? ((((tp) & 3) << 9) | (((abr) & 3) << 7) | (((y) & 0x300) >> 3) | (((x) & 0x3FF) >> 6)) \
         : ((((tp) & 3) << 7) | (((abr) & 3) << 5) | (((y) & 0x100) >> 4) | (((x) & 0x3FF) >> 6) | \
            (((y) & 0x200) << 2)))

DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h) {
    int pal = (int)func_8008003C();

    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = h;
    if (pal) {
        env->dfe = h < 289;
    } else {
        env->dfe = h < 257;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = getTPage(0, 0, 640, 0);
    env->isbg = 0;
    return env;
}

DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h) {
    env->disp.x = x;
    env->disp.y = y;
    env->disp.w = w;
    env->screen.x = 0;
    env->screen.y = 0;
    env->screen.w = 0;
    env->screen.h = 0;
    env->isrgb24 = 0;
    env->isinter = 0;
    env->pad1 = 0;
    env->pad0 = 0;
    env->disp.h = h;
    return env;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80085190);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_800851B0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CompMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MulMatrix0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MulRotMatrix0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MulRotMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetMulMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ApplyMatrixLV);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ApplyRotMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ScaleMatrixL);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PushMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PopMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ReadRotMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ReadLightMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ReadColorMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", gteMIMefunc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetFarColor);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareRoot0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ScaleMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ApplyMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80085EA0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverage12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverage0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverageShort12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverageShort0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverageByte);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadAverageCol);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetRotMatrix);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTransPers);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTransPers3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTransPers4);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_800862A0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", InitGeom);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _patch_gte);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_800863A0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_800863D0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LocalLight);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DpqColor);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColor);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColor3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColorDpq);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColorDpq3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColorCol);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", NormalColorCol3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ColorDpq);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ColorCol);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", AverageSZ3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", AverageSZ4);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTrans);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotNclip3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotNclip4);

void SetFogFar(int a, int h) {
    SetDQA(-a * 64 / h);
    SetDQB(0x1400000);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetVertex0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetVertex1);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetVertex2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetVertexTri);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetRGBfifo);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetIR123);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetIR0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetSZfifo3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetSZfifo4);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetSXSYfifo);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetRii);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetMAC123);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetData32);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDQA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDQB);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetTransMatrix);

void SetFogNear(int a, int h) {
    SetDQA(-(a * 320) / h);
    SetDQB(0x1400000);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MulMatrix2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTransSV);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSS12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSS0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSL12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSL0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80086B40);

void DecDCTReset(int mode) {
    if (mode == 0) {
        ResetCallback();
    }
    MDEC_reset(mode);
}

extern u32 D_800A5098[], D_800A50D8[], D_800A511C[];

u32 *DecDCTGetEnv(u32 *env) {
    u32 *d, *s;
    int n;

    d = env;
    s = D_800A5098;
    n = 16;
    while (n--) {
        *d++ = *s++;
    }
    d = env + 16;
    s = D_800A50D8;
    n = 16;
    while (n--) {
        *d++ = *s++;
    }
    d = env + 32;
    s = D_800A511C;
    n = 32;
    while (n--) {
        *d++ = *s++;
    }
    return env;
}

extern u32 D_800A5094[], D_800A5098[], D_800A50D8[], D_800A5118[];
void MDEC_in(u32 *buf, u32 size);

u32 *DecDCTPutEnv(u32 *env) {
    int i;
    u32 *src, *dst;

    src = env;
    dst = D_800A5098;
    i = 16;
    while (i--) {
        *dst++ = *src++;
    }
    dst = D_800A50D8;
    src = env + 16;
    i = 16;
    while (i--) {
        *dst++ = *src++;
    }
    MDEC_in(D_800A5094, 0x20);
    MDEC_in(D_800A5118, 0x20);
    return env;
}

int DecDCTBufSize(u32 *bs) {
    return *(u16 *)bs;
}

void DecDCTin(u32 *buf, int mode) {
    if (mode & 1) {
        *buf &= ~0x08000000;
    } else {
        *buf |= 0x08000000;
    }
    if (mode & 2) {
        *buf |= 0x02000000;
    } else {
        *buf &= ~0x02000000;
    }
    MDEC_in(buf, *(u16 *)buf);
}

int DecDCTout(int a, int b) {
    return MDEC_out(a, b);
}

int DecDCTinSync(int a, int b) {
    return MDEC_in_sync(a, b);
}

int DecDCToutSync(int a, int b) {
    return MDEC_out_sync(a, b);
}

void *DecDCTinCallback(void (*func)()) {
    return (void *)DMACallback(0, func);
}

void *DecDCToutCallback(void (*func)()) {
    return (void *)DMACallback(1, func);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MDEC_reset);

extern volatile u32 *D_800A51D4, *D_800A519C, *D_800A51A0, *D_800A51CC, *D_800A51A4;

void MDEC_in(u32 *buf, u32 size) {
    MDEC_in_sync();
    *D_800A51D4 |= 0x88;
    *D_800A519C = (u32)(buf + 1);
    *D_800A51A0 = (size >> 5) << 16 | 0x20;
    *D_800A51CC = *buf;
    *D_800A51A4 = 0x01000201;
}

extern volatile u32 *D_800A51D4, *D_800A51B0, *D_800A51A8, *D_800A51AC;

void MDEC_out(u32 *buf, u32 size) {
    MDEC_out_sync();
    *D_800A51D4 |= 0x88;
    *D_800A51B0 = 0;
    *D_800A51A8 = (u32)buf;
    *D_800A51AC = (size >> 5) << 16 | 0x20;
    *D_800A51B0 = 0x01000200;
}

extern volatile u32 *D_800A51D0;
extern char D_8008939C[];

int MDEC_in_sync(void) {
    volatile int cnt = 0x100000;

    while (*D_800A51D0 & 0x20000000) {
        if (--cnt == -1) {
            timeout(D_8008939C);
            return -1;
        }
    }
    return 0;
}

extern volatile u32 *D_800A51B0;
extern char D_800893AC[];

int MDEC_out_sync(void) {
    volatile int cnt = 0x100000;

    while (*D_800A51B0 & 0x01000000) {
        if (--cnt == -1) {
            timeout(D_800893AC);
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", timeout);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80087280);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTvlcSize);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTvlc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", bzero);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memset_80087628);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memcpy);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", strcat);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", printf);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", setjmp);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", strlen);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", strcpy);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", sprintf);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memchr);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", puts);
