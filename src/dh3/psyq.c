#include "common.h"
#include "psyq/libgpu.h"
#include "psyq/libcd.h"

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", start);

void func_800783A4(void) {
}

void SpuSetVoiceAttr(void *attr) {
    _SpuSetVoiceAttr(attr, 0, 0x17, 0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _SpuSetVoiceAttr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuGetKeyStatus);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_note2pitch);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_pitch2note);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetReverbModeParam);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_setReverbAttr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _SpuIsInAllocateArea);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _SpuIsInAllocateArea_);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetCommonAttr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_reset);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_init);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_writeByIO);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_FiDMA);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_r_);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_t);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_write);

extern u16 D_8009E024;
extern int D_8009E04C;

int _spu_read(int addr, int size) {
    _spu_t(2, D_8009E024 << D_8009E04C);
    _spu_t(0);
    _spu_t(3, addr, size);
    return size;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_FsetRXX);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_FsetRXXa);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_FgetRXXa);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuClearReverbWorkArea);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _SpuInit);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuStart);

void *_SpuDataCallback(void (*func)()) {
    return (void *)DMACallback(4, func);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetReverbDepth);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetReverbVoice);

void SsUtReverbOff(void) {
    _SpuInit(0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetReverb);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_8007B120);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuIsTransferCompleted);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuInitMalloc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetTransferMode);

extern u16 D_8009E024;

u32 SpuSetTransferStartAddr(u32 addr) {
    D_8009E024 = _spu_FsetRXXa(-1, addr);
    return addr;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuRead);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuSetKey);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuMalloc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SpuReserveReverbWorkArea);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _spu_gcSPU);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _SpuSetAnyVoice);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", cb_read);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", cd_read_retry);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdRead);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdReadSync);

extern void *D_8009E7E8;

void *CdReadCallback(void *func) {
    void *old = D_8009E7E8;

    D_8009E7E8 = func;
    return old;
}

extern u8 D_8009E8A8;

int CdStatus(void) {
    return D_8009E8A8;
}

extern u8 D_8009E8B8;

int CdMode(void) {
    return D_8009E8B8;
}

extern u8 D_8009E8B9;

int CdLastCom(void) {
    return D_8009E8B9;
}

extern u8 D_8009E8B4[];

u8 *CdLastPos(void) {
    return D_8009E8B4;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdReset);

void CdFlush(void) {
    CD_flush();
}

extern int D_8009E8A4;

int CdSetDebug(int level) {
    int old = D_8009E8A4;

    D_8009E8A4 = level;
    return old;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdComstr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdIntstr);

int CdSync(int a, int b) {
    return CD_sync(a, b);
}

int CdReady(int a, int b) {
    return CD_ready(a, b);
}

extern void *D_8009E898;

void *CdSyncCallback(void *func) {
    void *old = D_8009E898;

    D_8009E898 = func;
    return old;
}

extern void *D_8009E89C;

void *CdReadyCallback(void *func) {
    void *old = D_8009E89C;

    D_8009E89C = func;
    return old;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdControl);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdControlF);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdControlB);

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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_cw);

extern volatile u8 *D_8009EB5C, *D_8009EB60, *D_8009EB64, *D_8009EB68;

int CD_vol(u8 *vol) {
    *D_8009EB5C = 2;
    *D_8009EB64 = vol[0];
    *D_8009EB68 = vol[1];
    *D_8009EB5C = 3;
    *D_8009EB60 = vol[2];
    *D_8009EB64 = vol[3];
    *D_8009EB68 = 0x20;
    return 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_flush);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_initvol);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_initintr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_init);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_datasync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CD_getsector);

extern int D_8009EB40;

void CD_set_test_parmnum(int n) {
    D_8009EB40 = n;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", callback);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdInit);

void def_cbsync(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void def_cbready(void) {
    DeliverEvent(0xF0000003, 0x40);
}

void def_cbread(void) {
    DeliverEvent(0xF0000003, 0x40);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdRead2);

void StCdInterrupt2(void) {
    StCdInterrupt();
}

extern int D_801FA2B4, D_800BA1A0, D_801CA294, D_801984EC, D_800B9EA0;
extern void *D_8018CB60, *D_8018CB64;
extern s16 D_800BA19C;

void StSetStream(int mode, int start, int end, void *func1, void *func2) {
    func_8007EF34(1, start, end);
    D_801FA2B4 = 0;
    D_8018CB60 = func1;
    D_800BA1A0 = mode & 1;
    D_801CA294 = 0;
    D_801984EC = 0;
    D_800BA19C = 0;
    D_800B9EA0 = 0;
    D_8018CB64 = func2;
}

int CdGetToc(void *loc) {
    return CdGetToc2(1, loc);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CdGetToc2);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StCdInterrupt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", mem2mem);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", dma_execute);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", init_ring_status);

extern s32 D_801985B0;
extern s32 D_801FA2B8;
extern s32 D_801FA344;

void func_8007EF34(s32 arg0, s32 arg1, s32 arg2) {
    D_801FA344 = arg0;
    D_801985B0 = arg1;
    D_801FA2B8 = arg2;
}

extern u32 *D_801FA34C;
extern u32 D_801FAE00;

void StSetRing(u32 *ring_addr, u32 ring_size) {
    D_801FA34C = ring_addr;
    D_801FAE00 = ring_size;
    StClearRing();
}

extern int D_801FA0BC, D_801FA0B8, D_801FA0B4, D_801DA6BC;
extern u32 D_801FAE00;
extern int D_8018CD90, D_800B9EA0;
extern s16 D_800BA19C;

void StClearRing(void) {
    D_801FA0BC = 0;
    D_801FA0B8 = 0;
    D_801FA0B4 = 0;
    D_801DA6BC = 0;
    init_ring_status(0, D_801FAE00);
    D_8018CD90 = 0;
    D_800BA19C = 0;
    D_800B9EA0 = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StGetNext);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", data_ready_callback);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StGetBackloc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StFreeRing);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _card_info);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _card_auto);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StopCARD);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", StartCARD);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _card_read);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CloseEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_8007F2B4);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", close);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", write);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SysDeqIntRP);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SysEnqIntRP);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", EnableEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", delete);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", format);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetRCnt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", GetRCnt);

extern volatile u32 *D_8009EC74;
extern u32 D_8009EC7C[];

int StartRCnt(int spec) {
    spec &= 0xFFFF;
    D_8009EC74[1] |= D_8009EC7C[spec];
    return spec < 3;
}

extern volatile u32 *D_8009EC74;
extern u32 D_8009EC7C[];

int StopRCnt(int spec) {
    spec &= 0xFFFF;
    D_8009EC74[1] &= ~D_8009EC7C[spec];
    return 1;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ResetRCnt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DisableEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DeliverEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", InitHeap);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _bu_init);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", Exec);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", OpenEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", read);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", WaitEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", TestEvent);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_8007F53C);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ChangeClearRCnt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", open);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", FlushCache);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_8007F57C);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_8007F58C);

extern void *D_8009EC8C;

void *func_8007F59C(void *func) {
    void *old = D_8009EC8C;

    D_8009EC8C = func;
    return old;
}

extern void *D_8009EC8C;

void *func_8007F5B4(void) {
    return D_8009EC8C;
}

extern int D_801DA428;
extern u32 D_800B6AF4;

void PadInit(int mode) {
    D_801DA428 = mode;
    D_800B6AF4 = -1;
    ResetCallback();
    PAD_init(0x20000001, &D_800B6AF4);
    ChangeClearPAD(0);
}

extern u32 D_800B6AF4;

u32 PadRead(int id) {
    PAD_dr();
    return ~D_800B6AF4;
}

void PadStop(void) {
    StopPAD();
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PAD_dr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PAD_init);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ChangeClearPAD);

extern int (**D_8009FD18)();

int ResetCallback(void) {
    return D_8009FD18[3]();
}

extern int (**D_8009FD18)();

int InterruptCallback(int a, int b) {
    return D_8009FD18[2](a, b);
}

extern int (**D_8009FD18)();

int DMACallback(int a, int b) {
    return D_8009FD18[1](a, b);
}

extern int (**D_8009FD18)();

int VSyncCallback(void (*func)()) {
    return D_8009FD18[5](0, func);
}

extern int (**D_8009FD18)();

int VSyncCallbacks(int a, int b) {
    return D_8009FD18[5](a, b);
}

extern int (**D_8009FD18)();

int StopCallback(int a, int b) {
    return D_8009FD18[4](a, b);
}

extern int (**D_8009FD18)();

int RestartCallback(int a, int b) {
    return D_8009FD18[6](a, b);
}

extern u16 D_8009EC92;

int CheckCallback(void) {
    return D_8009EC92;
}

extern volatile u16 *D_8009FD20;

int GetIntrMask(void) {
    return *D_8009FD20;
}

extern volatile u16 *D_8009FD20;

int SetIntrMask(int mask) {
    int old = *D_8009FD20;

    *D_8009FD20 = mask;
    return old;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", startIntr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", trapIntr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", setIntr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", stopIntr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", restartIntr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memclr_8007FD78);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", HookEntryInt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ResetEntryInt);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _96_remove);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ReturnFromException);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", startIntrDMA);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", trapIntrDMA);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", setIntrDMA);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memclr_80080060);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", startIntrVSync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", trapIntrVSync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", setIntrVSync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memclr_80080188);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", VSync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", v_wait);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ResetGraph);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetGraphReverse);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetGraphDebug);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetGraphQueue);

extern u8 D_8009FDD4;

int GetGraphType(void) {
    return D_8009FDD4;
}

extern u8 D_8009FDD6;

int GetGraphDebug(void) {
    return D_8009FDD6;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DrawSyncCallback);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDispMask);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DrawSync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", checkRECT);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ClearImage);

extern u32 (**D_8009FDCC)();
extern char D_80087688[];

int LoadImage(RECT *rect, u32 *p) {
    checkRECT(D_80087688, rect);
    return D_8009FDCC[2](D_8009FDCC[8], rect, 8, p);
}

extern u32 (**D_8009FDCC)();
extern char D_80087694[];

int StoreImage(RECT *rect, u32 *p) {
    checkRECT(D_80087694, rect);
    return D_8009FDCC[2](D_8009FDCC[7], rect, 8, p);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MoveImage);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ClearOTag);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ClearOTagR);

extern u32 (**D_8009FDCC)();

void DrawPrim(void *p) {
    int len = ((P_TAG *)p)->len;

    D_8009FDCC[15](0);
    D_8009FDCC[5]((u32 *)p + 1, len);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DrawOTag);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PutDrawEnv);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DrawOTagEnv);

extern u8 D_8009FDE4[];

void *GetDrawEnv(void *env) {
    memcpy(env, D_8009FDE4, 0x5C);
    return env;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PutDispEnv);

extern u8 D_8009FE40[];

void *GetDispEnv(void *env) {
    memcpy(env, D_8009FE40, 0x14);
    return env;
}

extern u32 (**D_8009FDCC)();

u32 GetODE(void) {
    return D_8009FDCC[14]() >> 31;
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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetPriority);

u32 get_mode(int dfe, int dtd, u16 tpage);

void SetDrawMode(u32 *p, int dfe, int dtd, int tpage, void *tw) {
    setlen(p, 2);
    p[1] = get_mode(dfe, dtd, tpage);
    p[2] = get_tw(tw);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDrawEnv);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_ofs);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_tw);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_dx);

extern volatile u32 *D_8009FEA8;

u32 _status(void) {
    return *D_8009FEA8;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _otc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _clr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _dws);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _drs);

extern volatile u32 *D_8009FEA8;
extern u8 D_800B6B38[];

void _ctl(u32 n) {
    *D_8009FEA8 = n;
    D_800B6B38[n >> 24] = n;
}

extern u8 D_800B6B38[];

int _getctl(int n) {
    return D_800B6B38[n];
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _cwb);

extern volatile u32 *D_8009FEA8, *D_8009FEAC, *D_8009FEB0, *D_8009FEB4;

void _cwc(u32 addr) {
    *D_8009FEA8 = 0x04000002;
    *D_8009FEAC = addr;
    *D_8009FEB0 = 0;
    *D_8009FEB4 = 0x01000401;
}

extern volatile u32 *D_8009FEA8;
extern volatile u32 *D_8009FEA4;

u32 _param(u32 n) {
    *D_8009FEA8 = n | 0x10000000;
    return *D_8009FEA4 & 0xFFFFFF;
}

int _addque(int a, int b, int c) {
    return _addque2(a, b, 0, c);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _addque2);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _exeque);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _reset);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _sync);

extern int D_8009FEEC;
extern int D_8009FEF0;

void set_alarm(void) {
    D_8009FEEC = VSync(-1) + 240;
    D_8009FEF0 = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", get_alarm);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _version);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memset_800830B8);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", GPU_cw);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", GetTPage);

u16 GetClut(int x, int y) {
    return (y << 6) | ((x >> 4) & 0x3F);
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DumpTPage);

extern char D_800877A0[];
extern int (*D_8009FDD0)(char *fmt, ...);

void DumpClut(u16 clut) {
    (*D_8009FDD0)(D_800877A0, (clut & 0x3F) << 4, clut >> 6);
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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetSemiTrans);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetShadeTex);

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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDrawTPage);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDrawLoad);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MargePrim);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DumpDrawEnv);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DumpDispEnv);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadTPage);

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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDefDrawEnv);

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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80083C68);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80083C88);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", CompMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MulMatrix0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MulRotMatrix0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MulRotMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetMulMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ApplyMatrixLV);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ApplyRotMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ScaleMatrixL);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PushMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", PopMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ReadRotMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ReadLightMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ReadColorMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", gteMIMefunc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetFarColor);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SquareRoot0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ScaleMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ApplyMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80084978);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverage12);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverage0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverageShort12);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverageShort0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverageByte);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LoadAverageCol);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetRotMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotTransPers);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotTransPers3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotTransPers4);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80084D78);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", InitGeom);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", _patch_gte);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80084E78);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80084EA8);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", LocalLight);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DpqColor);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColor);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColor3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColorDpq);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColorDpq3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColorCol);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", NormalColorCol3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ColorDpq);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", ColorCol);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", AverageSZ3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", AverageSZ4);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotTrans);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotNclip3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotNclip4);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetFogFar);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetVertex0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetVertex1);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetVertex2);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetVertexTri);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetRGBfifo);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetIR123);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetIR0);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetSZfifo3);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetSZfifo4);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetSXSYfifo);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetRii);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetMAC123);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetData32);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDQA);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetDQB);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", RotMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetTransMatrix);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", SetFogNear);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MulMatrix2);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_800857A8);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTReset);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTGetEnv);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTPutEnv);

int DecDCTBufSize(u32 *bs) {
    return *(u16 *)bs;
}

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTin);

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

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MDEC_reset);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MDEC_in);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MDEC_out);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MDEC_in_sync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", MDEC_out_sync);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", timeout);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", func_80085EE8);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTvlcSize);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", DecDCTvlc);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", bzero);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memset_80086290);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memcpy);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", printf);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", setjmp);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", strcpy);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", sprintf);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memchr);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", strlen);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", memmove);

INCLUDE_ASM("asm/dh3/nonmatchings/psyq", puts);
