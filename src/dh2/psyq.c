#include "common.h"
#include "psyq/libgpu.h"

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", start);

void func_80078F5C(void) {
}

void SpuSetVoiceAttr(void *attr) {
    _SpuSetVoiceAttr(attr, 0, 0x17, 0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuSetVoiceAttr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuGetKeyStatus);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_note2pitch);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_pitch2note);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetReverbModeParam);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_setReverbAttr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuIsInAllocateArea);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuIsInAllocateArea_);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetCommonAttr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_reset);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_init);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_writeByIO);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FiDMA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_r_);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_t);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_write);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_read);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FsetRXX);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FsetRXXa);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _spu_FgetRXXa);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuClearReverbWorkArea);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _SpuInit);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuStart);

void *_SpuDataCallback(void (*func)()) {
    return (void *)DMACallback(4, func);
}

void SsUtReverbOff(void) {
    _SpuInit(0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetReverb);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_8007BC3C);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuIsTransferCompleted);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuInitMalloc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetTransferMode);

extern u16 D_800A2194;

u32 SpuSetTransferStartAddr(u32 addr) {
    D_800A2194 = _spu_FsetRXXa(-1, addr);
    return addr;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuRead);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuSetKey);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuMalloc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SpuReserveReverbWorkArea);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdReset);

void CdFlush(void) {
    CD_flush();
}

extern int D_800A2A14;

int CdSetDebug(int level) {
    int old = D_800A2A14;

    D_800A2A14 = level;
    return old;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdComstr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdIntstr);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdIntToPos);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdPosToInt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_cw);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CD_vol);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdInit);

void def_cbsync(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void def_cbready(void) {
    DeliverEvent(0xF0000003, 0x40);
}

void def_cbread(void) {
    DeliverEvent(0xF0000003, 0x40);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdRead2);

void StCdInterrupt2(void) {
    StCdInterrupt();
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StSetStream);

int CdGetToc(void *loc) {
    return CdGetToc2(1, loc);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", CdGetToc2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StCdInterrupt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", mem2mem);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", dma_execute);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", init_ring_status);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StClearRing);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StGetNext);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", data_ready_callback);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StGetBackloc);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StFreeRing);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetRCnt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", GetRCnt);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ResetRCnt);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_8008003C);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PadInit);

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

int ResetCallback(int a, int b) {
    return D_800A3E88[3](a, b);
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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", stopIntr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", restartIntr);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memclr_80080800);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", HookEntryInt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ResetEntryInt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _96_remove);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ReturnFromException);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", startIntrDMA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", trapIntrDMA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", setIntrDMA);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memclr_80080AE8);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", startIntrVSync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", trapIntrVSync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", setIntrVSync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memclr_80080C10);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", VSync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", v_wait);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ResetGraph);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetGraphReverse);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetGraphDebug);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetGraphQueue);

extern u8 D_800A3F44;

int GetGraphType(void) {
    return D_800A3F44;
}

extern u8 D_800A3F46;

int GetGraphDebug(void) {
    return D_800A3F46;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DrawSyncCallback);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDispMask);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DrawSync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", checkRECT);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ClearImage);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadImage);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", StoreImage);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MoveImage);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ClearOTag);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", ClearOTagR);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DrawPrim);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DrawOTag);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", PutDrawEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DrawOTagEnv);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawArea);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawOffset);

void SetPriority(u32 *p, int pbc, int pbw) {
    setlen(p, 2);
    p[1] = 0xE6000000 | (pbc ? 2 : 0) | (pbw != 0);
    p[2] = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawMode);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_ofs);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", get_tw);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _cwb);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", _cwc);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memset_80083B40);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", GPU_cw);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", GetTPage);

u16 GetClut(int x, int y) {
    return (y << 6) | ((x >> 4) & 0x3F);
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DumpTPage);

extern char D_8008922C[];
extern int (*D_800A3F40)(char *fmt, ...);

void DumpClut(u16 clut) {
    (*D_800A3F40)(D_8008922C, (clut & 0x3F) << 4, clut >> 6);
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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetSemiTrans);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetShadeTex);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetLineF3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetLineG3);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetLineF4);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetLineG4);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDrawLoad);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MargePrim);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DumpDrawEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DumpDispEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDumpFnt);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntLoad);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntOpen);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntFlush);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", FntPrint);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadTPage);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadClut);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", LoadClut2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetDefDrawEnv);

typedef struct {
    s16 x, y, w, h;
} RECT;

typedef struct {
    RECT disp;
    RECT screen;
    u8 isinter;
    u8 isrgb24;
    u8 pad0, pad1;
} DISPENV;

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetFogFar);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SetFogNear);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MulMatrix2);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", RotTransSV);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSS12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSS0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSL12);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", SquareSL0);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", func_80086B40);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTReset);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTGetEnv);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTPutEnv);

int DecDCTBufSize(u32 *bs) {
    return *(u16 *)bs;
}

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", DecDCTin);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MDEC_in);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MDEC_out);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MDEC_in_sync);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", MDEC_out_sync);

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

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", memmove);

INCLUDE_ASM("asm/dh2/nonmatchings/psyq", puts);
