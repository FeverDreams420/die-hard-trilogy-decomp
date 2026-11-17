#include "common.h"
#include "psyq/libgpu.h"
#include "psyq/libcd.h"

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", start);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B268);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B2D8);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B340);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B350);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B360);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B370);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", OpenEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CloseEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", TestEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", EnableEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B3C0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B3D0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006B3E0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", open);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", read);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", write);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", close);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", format);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", delete);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StartCARD);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StopCARD);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _card_read);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _bu_init);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _card_info);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _card_auto);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", strcpy);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", bzero);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", InitHeap);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", printf);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", Exec);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", FlushCache);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SysEnqIntRP);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SysDeqIntRP);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ChangeClearRCnt);

extern int D_801D20B0;
extern u32 D_800A391C;

void PadInit(int mode) {
    D_801D20B0 = mode;
    D_800A391C = -1;
    ResetCallback();
    PAD_init(0x20000001, &D_800A391C);
    ChangeClearPAD(0);
}

extern u32 D_800A391C;

u32 PadRead(int id) {
    PAD_dr();
    return ~D_800A391C;
}

void PadStop(void) {
    StopPAD();
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PAD_init);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PAD_dr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ChangeClearPAD);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", VSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", v_wait);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", puts);

extern int (**D_8008C43C)();

int ResetCallback(void) {
    return D_8008C43C[3]();
}

extern int (**D_8008C43C)();

int InterruptCallback(int a, int b) {
    return D_8008C43C[2](a, b);
}

extern int (**D_8008C43C)();

int DMACallback(int a, int b) {
    return D_8008C43C[1](a, b);
}

extern int (**D_8008C43C)();

int VSyncCallback(void (*func)()) {
    return D_8008C43C[5](0, func);
}

extern int (**D_8008C43C)();

int VSyncCallbacks(int a, int b) {
    return D_8008C43C[5](a, b);
}

extern int (**D_8008C43C)();

int StopCallback(int a, int b) {
    return D_8008C43C[4](a, b);
}

extern int (**D_8008C43C)();

int RestartCallback(int a, int b) {
    return D_8008C43C[6](a, b);
}

extern u16 D_8008B3B6;

int CheckCallback(void) {
    return D_8008B3B6;
}

extern volatile u16 *D_8008C444;

int GetIntrMask(void) {
    return *D_8008C444;
}

extern volatile u16 *D_8008C444;

int SetIntrMask(int mask) {
    int old = *D_8008C444;

    *D_8008C444 = mask;
    return old;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", startIntr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", trapIntr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", setIntr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", stopIntr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", restartIntr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memclr_8006BEE8);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ReturnFromException);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ResetEntryInt);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", HookEntryInt);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _96_remove);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", setjmp);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", startIntrVSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", trapIntrVSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", setIntrVSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memclr_8006C060);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", startIntrDMA);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", trapIntrDMA);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", setIntrDMA);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memclr_8006C308);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadTPage);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDefDrawEnv);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006C5FC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006C614);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetTPage);

u16 GetClut(int x, int y) {
    return (y << 6) | ((x >> 4) & 0x3F);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DumpTPage);

extern char D_8007B7D4[];
extern int (*D_8008C4E8)(char *fmt, ...);

void DumpClut(u16 clut) {
    (*D_8008C4E8)(D_8007B7D4, (clut & 0x3F) << 4, clut >> 6);
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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetSemiTrans);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetShadeTex);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawTPage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawLoad);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MargePrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DumpDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DumpDispEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ResetGraph);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetGraphReverse);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetGraphDebug);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetGraphQueue);

extern u8 D_8008C4EC;

int GetGraphType(void) {
    return D_8008C4EC;
}

extern u8 D_8008C4EE;

int GetGraphDebug(void) {
    return D_8008C4EE;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawSyncCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDispMask);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", checkRECT);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ClearImage);

extern u32 (**D_8008C4E4)();
extern char D_8007B9C0[];

int LoadImage(RECT *rect, u32 *p) {
    checkRECT(D_8007B9C0, rect);
    return D_8008C4E4[2](D_8008C4E4[8], rect, 8, p);
}

extern u32 (**D_8008C4E4)();
extern char D_8007B9CC[];

int StoreImage(RECT *rect, u32 *p) {
    checkRECT(D_8007B9CC, rect);
    return D_8008C4E4[2](D_8008C4E4[7], rect, 8, p);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MoveImage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ClearOTag);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ClearOTagR);

extern u32 (**D_8008C4E4)();

void DrawPrim(void *p) {
    int len = ((P_TAG *)p)->len;

    D_8008C4E4[15](0);
    D_8008C4E4[5]((u32 *)p + 1, len);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawOTag);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PutDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawOTagEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PutDispEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetDispEnv);

extern u32 (**D_8008C4E4)();

u32 GetODE(void) {
    return D_8008C4E4[14]() >> 31;
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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetPriority);

u32 get_mode(int dfe, int dtd, u16 tpage);

void SetDrawMode(u32 *p, int dfe, int dtd, int tpage, void *tw) {
    setlen(p, 2);
    p[1] = get_mode(dfe, dtd, tpage);
    p[2] = get_tw(tw);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_ofs);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_tw);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_dx);

extern volatile u32 *D_8008C5C0;

u32 _status(void) {
    return *D_8008C5C0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _otc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _clr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _dws);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _drs);

extern volatile u32 *D_8008C5C0;
extern u8 D_800A3960[];

void _ctl(u32 n) {
    *D_8008C5C0 = n;
    D_800A3960[n >> 24] = n;
}

extern u8 D_800A3960[];

int _getctl(int n) {
    return D_800A3960[n];
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _cwb);

extern volatile u32 *D_8008C5C0, *D_8008C5C4, *D_8008C5C8, *D_8008C5CC;

void _cwc(u32 addr) {
    *D_8008C5C0 = 0x04000002;
    *D_8008C5C4 = addr;
    *D_8008C5C8 = 0;
    *D_8008C5CC = 0x01000401;
}

extern volatile u32 *D_8008C5C0;
extern volatile u32 *D_8008C5BC;

u32 _param(u32 n) {
    *D_8008C5C0 = n | 0x10000000;
    return *D_8008C5BC & 0xFFFFFF;
}

int _addque(int a, int b, int c) {
    return _addque2(a, b, 0, c);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _addque2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _exeque);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _reset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _sync);

extern int D_8008C604;
extern int D_8008C608;

void set_alarm(void) {
    D_8008C604 = VSync(-1) + 240;
    D_8008C608 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_alarm);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _version);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memcpy_8006FC1C);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GPU_cw);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetFogFar);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetFogNear);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", InitGeom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SquareRoot0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", gteMIMefunc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverage12);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverage0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverageShort12);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverageShort0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverageByte);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadAverageCol);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CompMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MulMatrix0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MulRotMatrix0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MulRotMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetMulMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ApplyMatrixLV);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ApplyRotMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ScaleMatrixL);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PushMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PopMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ReadRotMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ReadLightMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ReadColorMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MulMatrix2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ApplyMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80070C9C);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ScaleMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetRotMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetTransMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetVertex0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetVertex1);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetVertex2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetVertexTri);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetRGBfifo);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetIR123);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetIR0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetSZfifo3);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetSZfifo4);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetSXSYfifo);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetRii);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetMAC123);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetData32);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDQA);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDQB);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80070F5C);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80070F7C);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetFarColor);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80070FBC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80070FDC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransSV);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SquareSS12);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SquareSS0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SquareSL12);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SquareSL0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers3);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTrans);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_800711AC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_800711DC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers4);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotNclip3);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotNclip4);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTrans_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotTransPers4_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotAverage3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotNclip3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotAverageNclip3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotColorDpq_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotColorDpq3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotAverageNclipColorDpq3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotAverageNclipColorCol3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColor_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColor3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColorDpq_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColorDpq3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColorCol_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NormalColorCol3_nom);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RotMatrix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _patch_gte);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80071A2C);

extern u32 *D_801FB864;
extern u32 D_801FC0F8;

void StSetRing(u32 *ring_addr, u32 ring_size) {
    D_801FB864 = ring_addr;
    D_801FC0F8 = ring_size;
    StClearRing();
}

int CdGetToc(void *loc) {
    return CdGetToc2(1, loc);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdGetToc2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdInit);

void def_cbsync(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void def_cbready(void) {
    DeliverEvent(0xF0000003, 0x40);
}

void def_cbread(void) {
    DeliverEvent(0xF0000003, 0x40);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DeliverEvent);

extern u8 D_80090B4C;

int CdStatus(void) {
    return D_80090B4C;
}

extern u8 D_80090B5C;

int CdMode(void) {
    return D_80090B5C;
}

extern u8 D_80090B5D;

int CdLastCom(void) {
    return D_80090B5D;
}

extern u8 D_80090B58[];

u8 *CdLastPos(void) {
    return D_80090B58;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdReset);

void CdFlush(void) {
    CD_flush();
}

extern int D_80090B48;

int CdSetDebug(int level) {
    int old = D_80090B48;

    D_80090B48 = level;
    return old;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdComstr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdIntstr);

int CdSync(int a, int b) {
    return CD_sync(a, b);
}

int CdReady(int a, int b) {
    return CD_ready(a, b);
}

extern void *D_80090B3C;

void *CdSyncCallback(void *func) {
    void *old = D_80090B3C;

    D_80090B3C = func;
    return old;
}

extern void *D_80090B40;

void *CdReadyCallback(void *func) {
    void *old = D_80090B40;

    D_80090B40 = func;
    return old;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControl);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControlF);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControlB);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_cw);

extern volatile u8 *D_80090E00, *D_80090E04, *D_80090E08, *D_80090E0C;

int CD_vol(u8 *vol) {
    *D_80090E00 = 2;
    *D_80090E08 = vol[0];
    *D_80090E0C = vol[1];
    *D_80090E00 = 3;
    *D_80090E04 = vol[2];
    *D_80090E08 = vol[3];
    *D_80090E0C = 0x20;
    return 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_flush);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_initvol);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_initintr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_init);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_datasync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_getsector);

extern int D_80090DE4;

void CD_set_test_parmnum(int n) {
    D_80090DE4 = n;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", callback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdSearchFile);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _cmp);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_newmedia);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_searchdir);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_cachefile);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", cd_read);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memcpy_800745F8);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", strcmp);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", strncmp);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", cb_read);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", cd_read_retry);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdRead);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdReadSync);

extern void *D_80090E50;

void *CdReadCallback(void *func) {
    void *old = D_80090E50;

    D_80090E50 = func;
    return old;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdRead2);

void StCdInterrupt2(void) {
    StCdInterrupt();
}

extern int D_801F97B8, D_801F97B0, D_801F97AC, D_801D20EC;
extern u32 D_801FC0F8;
extern int D_801C0950, D_800A7FD0;
extern s16 D_800A7FE4;

void StClearRing(void) {
    D_801F97B8 = 0;
    D_801F97B0 = 0;
    D_801F97AC = 0;
    D_801D20EC = 0;
    init_ring_status(0, D_801FC0F8);
    D_801C0950 = 0;
    D_800A7FE4 = 0;
    D_800A7FD0 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80074D48);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", data_ready_callback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StGetBackloc);

extern int D_801F97CC, D_800A7FE8, D_801C2054, D_801C1B84, D_800A7FD0;
extern void *D_801C0948, *D_801C094C;
extern s16 D_800A7FE4;

void StSetStream(int mode, int start, int end, void *func1, void *func2) {
    func_800750D8(1, start, end);
    D_801F97CC = 0;
    D_801C0948 = func1;
    D_800A7FE8 = mode & 1;
    D_801C2054 = 0;
    D_801C1B84 = 0;
    D_800A7FE4 = 0;
    D_800A7FD0 = 0;
    D_801C094C = func2;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StFreeRing);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", init_ring_status);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StGetNext);

extern s32 D_801FB85C;
extern s32 D_801C1B88;
extern s32 D_801F97D0;

void func_800750D8(s32 arg0, s32 arg1, s32 arg2) {
    D_801FB85C = arg0;
    D_801C1B88 = arg1;
    D_801F97D0 = arg2;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StCdInterrupt);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", mem2mem);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", dma_execute);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuInit);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuStart);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_reset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_init);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_writeByIO);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FiDMA);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_r_);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_t);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_write);

extern u16 D_800913B8;
extern int D_800913E0;

int _spu_read(int addr, int size) {
    _spu_t(2, D_800913B8 << D_800913E0);
    _spu_t(0);
    _spu_t(3, addr, size);
    return size;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FsetRXX);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FsetRXXa);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FgetRXXa);

void *_SpuDataCallback(void (*func)()) {
    return (void *)DMACallback(4, func);
}

void SsUtReverbOff(void) {
    _SpuInit(0);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80076F04);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DisableEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuInitMalloc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuMalloc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_gcSPU);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuFree);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetReverb);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuIsInAllocateArea);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuIsInAllocateArea_);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetReverbModeParam);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_setReverbAttr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuReserveReverbWorkArea);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetReverbVoice);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuSetAnyVoice);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuClearReverbWorkArea);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", WaitEvent);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetKey);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetKeyOnWithAttr);

void SpuSetVoiceAttr(void *attr) {
    _SpuSetVoiceAttr(attr, 0, 0x17, 0);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuSetVoiceAttr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuGetKeyStatus);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuRead);

extern u16 D_800913B8;

u32 SpuSetTransferStartAddr(u32 addr) {
    D_800913B8 = _spu_FsetRXXa(-1, addr);
    return addr;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetTransferMode);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuIsTransferCompleted);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetCommonAttr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_note2pitch);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_pitch2note);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTReset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTGetEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTPutEnv);

int DecDCTBufSize(u32 *bs) {
    return *(u16 *)bs;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTin);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MDEC_reset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MDEC_in);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MDEC_out);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MDEC_in_sync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MDEC_out_sync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", timeout);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80079AC0);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTvlcSize);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTvlc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80079E58);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", strlen);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8007A6C4);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", memchr);
