#include "common.h"
#include "psyq/libgpu.h"

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PadInit);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PadRead);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PadStop);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PAD_init);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PAD_dr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ChangeClearPAD);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", VSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", v_wait);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", puts);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ResetCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", InterruptCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DMACallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", VSyncCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", VSyncCallbacks);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StopCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", RestartCallback);

extern u16 D_8008B3B6;

int CheckCallback(void) {
    return D_8008B3B6;
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetIntrMask);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetIntrMask);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadClut);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadClut2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDefDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDefDispEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006C5FC);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_8006C614);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetTPage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetClut);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DumpTPage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DumpClut);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", NextPrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", IsEndPrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", AddPrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", AddPrims);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CatPrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", TermPrim);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetLineF3);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetLineG3);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetLineF4);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetLineG4);

void SetBlockFill(void *p) {
    setlen(p, 3);
    setcode(p, 0x2);
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawMove);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", LoadImage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StoreImage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", MoveImage);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ClearOTag);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", ClearOTagR);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawPrim);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawOTag);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PutDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DrawOTagEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", PutDispEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetDispEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", GetODE);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetTexWindow);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawArea);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawOffset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetPriority);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawMode);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SetDrawEnv);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_ofs);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_tw);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", get_dx);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _status);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _otc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _clr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _dws);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _drs);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _ctl);

extern u8 D_800A3960[];

int _getctl(int n) {
    return D_800A3960[n];
}

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _cwb);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _cwc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _param);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _addque);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _addque2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _exeque);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _reset);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _sync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", set_alarm);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StSetRing);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdGetToc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdGetToc2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdInit);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", def_cbsync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", def_cbready);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", def_cbread);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdFlush);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdSetDebug);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdComstr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdIntstr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdReady);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdSyncCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdReadyCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControl);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControlF);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdControlB);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdMix);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdGetSector);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdDataCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdDataSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdIntToPos);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdPosToInt);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_cw);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CD_vol);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdReadCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", CdRead2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StCdInterrupt2);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StClearRing);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", func_80074D48);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", data_ready_callback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StGetBackloc);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", StSetStream);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_read);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FsetRXX);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FsetRXXa);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _spu_FgetRXXa);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuDataCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SsUtReverbOff);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetVoiceAttr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", _SpuSetVoiceAttr);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuGetKeyStatus);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuRead);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", SpuSetTransferStartAddr);

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

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTout);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTinSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCToutSync);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCTinCallback);

INCLUDE_ASM("asm/dh1/nonmatchings/psyq", DecDCToutCallback);

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
