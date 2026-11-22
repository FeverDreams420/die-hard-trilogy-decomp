#include "common.h"
#include "psyq/libspu.h"

typedef struct {
    struct {
        u8 pad0[4];
        u8 unk4;
        u8 unk5;
        u8 pad6[0x2EA];
    } players[8];
    s16 unk1780;
    u8 pad1782[0x2];
    s16 unk1784;
    s16 unk1786;
    s16 unk1788;
    s16 unk178A;
    s16 unk178C;
    s16 unk178E;
} Unk800A350C;

extern Unk800A350C *D_800A350C;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Unk8002A35C;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    u16 uv0;
    u16 clut;
    s32 xy1;
    u16 uv1;
    u16 tpage;
    s32 xy2;
    u16 uv2;
    u16 pad1E;
    s32 xy3;
    u16 uv3;
    u16 pad26;
} Unk8002CE64_Prim;

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    u8 r0, g0, b0, code;
} P_TAG;

#define setaddr(p, _addr) (((P_TAG *)(p))->addr = (u32)(_addr))
#define getaddr(p) (u32)(((P_TAG *)(p))->addr)
#define setlen(p, _len) (((P_TAG *)(p))->len = (u8)(_len))
#define setcode(p, _code) (((P_TAG *)(p))->code = (u8)(_code))
#define getcode(p) (u8)(((P_TAG *)(p))->code)
#define setSemiTrans(p, abe) ((abe) ? setcode(p, getcode(p) | 0x02) : setcode(p, getcode(p) & ~0x02))
#define addPrim(ot, p) setaddr(p, getaddr(ot)), setaddr(ot, p)
#define setRGB0(p, _r0, _g0, _b0) ((p)->r0 = _r0, (p)->g0 = _g0, (p)->b0 = _b0)
#define setPolyFT4(p) setlen(p, 9), setcode(p, 0x2C)
#define setShadeTex(p, tge) ((tge) ? setcode(p, getcode(p) | 1) : setcode(p, getcode(p) & ~1))

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", main);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A6E4);

u16 D_800A29EC = 0xF676;

u16 D_800A29EE = 0x8770;

s16 D_800A29F0 = 0;

s16 D_800A29F2 = 0;
s16 D_800A29F4 = 3;

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A29F6);

extern u8 D_801D74C0[], D_801E20A0[], D_801E74C0[], D_801F20A0[];
typedef struct {
    s16 x, y, w, h;
} RECT;

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

typedef struct {
    RECT disp;
    RECT screen;
    u8 isinter;
    u8 isrgb24;
    u8 pad0;
    u8 pad1;
} DISPENV;

typedef struct {
    DISPENV disp;
    DRAWENV draw;
    u32 ot[0xA00];
    void *prims;
    void *unk2874;
    u8 buf[0xB3B0];
} Unk800A8078;

extern Unk800A8078 D_800A8078[2];
extern s16 D_800A33C4;
extern DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h);

void func_8001E80C(void) {
    SetDefDispEnv(&D_800A8078[0].disp, 0, 0, 0x140, D_800A33C4);
    D_800A8078[0].draw.clip.x = 0;
    D_800A8078[0].draw.clip.y = 0;
    D_800A8078[0].draw.clip.w = 0x140;
    D_800A8078[0].draw.ofs[0] = 0;
    D_800A8078[0].draw.ofs[1] = 0;
    D_800A8078[0].draw.tw.x = 0;
    D_800A8078[0].draw.tw.y = 0;
    D_800A8078[0].draw.tw.w = 0xFF;
    D_800A8078[0].draw.tw.h = 0xFF;
    D_800A8078[0].draw.dtd = 0xFF;
    D_800A8078[0].draw.dfe = 0xFF;
    D_800A8078[0].draw.isbg = 0xFF;
    D_800A8078[0].draw.r0 = 0;
    D_800A8078[0].draw.g0 = 0;
    D_800A8078[0].draw.b0 = 0;
    D_800A8078[0].prims = D_801D74C0;
    D_800A8078[0].unk2874 = D_801E20A0;
    D_800A8078[0].draw.clip.h = D_800A33C4;
    SetDefDispEnv(&D_800A8078[1].disp, 0x140, 0, 0x140, D_800A33C4);
    D_800A8078[1].draw.clip.x = 0x140;
    D_800A8078[1].draw.clip.y = 0;
    D_800A8078[1].draw.clip.w = 0x140;
    D_800A8078[1].draw.ofs[0] = 0x140;
    D_800A8078[1].draw.ofs[1] = 0;
    D_800A8078[1].draw.tw.x = 0;
    D_800A8078[1].draw.tw.y = 0;
    D_800A8078[1].draw.tw.w = 0xFF;
    D_800A8078[1].draw.tw.h = 0xFF;
    D_800A8078[1].draw.dtd = 0xFF;
    D_800A8078[1].draw.dfe = 0xFF;
    D_800A8078[1].draw.isbg = 0xFF;
    D_800A8078[1].draw.r0 = 0;
    D_800A8078[1].draw.g0 = 0;
    D_800A8078[1].draw.b0 = 0;
    D_800A8078[1].prims = D_801E74C0;
    D_800A8078[1].unk2874 = D_801F20A0;
    D_800A8078[1].draw.clip.h = D_800A33C4;
}

extern u16 D_800A29EC;
extern u16 D_800A29EE;

s32 func_8001E9DC(s32 n) {
    u16 t, u;

    D_800A29EC = (D_800A29EC ^ D_800A29EE) + 7;
    t = D_800A29EC >> 15;
    D_800A29EC <<= 1;
    D_800A29EE = (D_800A29EE + 0xACB9) ^ 0x7C9F;
    u = D_800A29EE << 15;
    D_800A29EE >>= 1;
    D_800A29EC |= t;
    D_800A29EE |= u;
    return (s16)((D_800A29EC & 0x7FFF) % (s16)n);
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk8003BA6C_Data;

typedef struct {
    u8 pad[0x1C];
    Unk8003BA6C_Data *data;
    u8 pad20[8];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
} Unk8003BA6C_Task;

typedef struct {
    s32 pad0;
    s32 vals[3];
} Unk800A317CVals;

extern struct Task {
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
} *D_800A317C;

extern Unk8003BA6C_Task *func_80021264(void (*fn)(), s16, s16);
extern void func_8003E77C(void *, s32);
extern void *D_800A33E4;
extern u8 *D_800A3304;
extern void (*D_800A34A4)(void);
extern u8 D_800C38E8[];
extern void func_8001EC50(void);
extern void func_8003E4E8(void);
extern void func_80069728();

extern s16 D_800A2F44;
extern void *D_801F7D24;
extern u16 D_8008A708[][16];
extern char D_80087CA8[];
extern u8 D_800896A8[];
extern void func_80053770(void);
extern s16 func_80054C70(void *data, s32 a1);
extern void func_800697C0(void);
extern s32 DrawSync(s32 mode);
extern int VSync(int mode);
extern void LoadTPage(void *pix, s32 tp, s32 abr, s16 x, s32 y, s32 w, s32 h);
extern void LoadClut(u16 *clut, s32 x, s32 y);
extern void func_8001EBD4(void);
extern s16 D_800A2F0C;
extern s16 D_800A2FEC;
extern s16 D_800A333C;
extern volatile s32 D_800A31F4;
extern void func_8001F37C(void);
extern void func_8001F0F8(void);

void func_8001EA74(void) {
    s16 i;

    D_800A2F44 = 0;
    D_801F7D24 = D_800A317C;
    func_80053770();
    func_80054C70(D_80087CA8, 0);
    func_800697C0();
    DrawSync(0);
    VSync(0);
    LoadTPage(D_800896A8, 0, 0, 0x2C0, 0, 0x100, 0x100);
    for (i = 0; i < 7; i++) {
        DrawSync(0);
        VSync(0);
        LoadClut(D_8008A708[i], 0x300, i);
    }
    DrawSync(0);
    VSync(0);
    func_80021264(func_8001EBD4, 1, 0x2C);
    D_800A2F0C = 13;
    D_800A2FEC = 0;
    D_800A333C = 0;
    D_800A31F4 = 3;
    func_8001F37C();
    *(s32 *)D_800A317C->vals = 0;
    D_800A317C->func = func_8001F0F8;
}

void func_8001EBD4(void) {
    D_800A33E4 = D_800C38E8;
    D_800A3304 = (u8 *)0x80013000;
    func_80021264(func_80069728, 4, 0x12);
    func_8003E77C(D_800A33E4, 0x87);
    D_800A34A4 = func_8001EC50;
    D_800A317C->func = func_8003E4E8;
}

extern void func_8003FCC8(void);
extern void *func_8003E414(void *, s16);
extern void *func_8003219C(void *, void *);
extern void func_8001FEBC(void);
extern void func_800248D4(void);
extern void func_8003E85C(void);
extern s16 D_800A2FEC;
extern s16 D_800A307C;
extern s16 D_800A33F4;

void func_8001EC50(void) {
    func_8003FCC8();
    func_8003219C(func_8003E414(D_800A33E4, 1), D_800A3304);
    func_8001FEBC();
    func_800248D4();
    D_800A2FEC = 0;
    D_800A33F4 = D_800A307C;
    D_800A317C->func = func_8003E85C;
}

extern s16 D_800A333C;
extern volatile s32 D_800A31F4;
extern void *D_801F7D24;
extern s16 D_800A2F0C;
extern void func_8001F37C(void);
extern void func_800403C8(void);
extern void func_8001F0F8(void);

void func_8001ECC8(void) {
    D_800A333C = 0;
    D_800A31F4 = 3;
    D_801F7D24 = D_800A317C;
    func_8001F37C();
    func_800403C8();
    D_800A2F0C = 1;
    D_800A2FEC = 0;
    func_80021264(func_8003E85C, 1, 0x2C);
    D_800A33F4 = D_800A307C;
    *(s32 *)D_800A317C->vals = 0;
    D_800A317C->func = func_8001F0F8;
}

extern s16 D_800A2F34;
extern s16 D_800A3454;
extern s16 D_800A319C;
extern s16 D_800A34C4;
extern s16 D_800A322C;
extern s16 D_800A304C;
extern s32 D_800A2FBC;
extern Unk8002A35C *D_800A3534;
extern s16 D_800A2F74;
extern s16 D_800A2F2C;
extern s16 D_800A303C;
extern s16 D_800A30EC;
extern s32 D_800A301C;
extern struct Task *D_801F7D6C;
extern Unk8003BA6C_Task *D_801F7D30;
extern Unk8003BA6C_Task *D_801F7D40;
extern Unk8003BA6C_Task *D_801F7D4C;
extern s16 D_800C38C8[];
extern s16 D_800A329C;
extern s16 D_800A305C[3];
extern s16 D_800A29F0;
extern Unk8002A35C D_8007C4FC[];
extern s16 D_800A2A26;
extern s16 D_800A3574;
extern s32 D_800A2FCC;
extern s16 D_800A315C;
extern s16 D_800A33F4;
extern s16 D_800A3184;
extern s32 D_800A2F8C;
extern s16 D_800A3414;
extern Unk800A8078 D_800A8078[2];

void func_80056918(void);
void func_800569DC(void);
void func_8004BDD0(void);
void func_8004DFD0(void);
void func_800411E4(void);
void func_80036F28(void);
void func_800498B0(void);
void func_80051960(void);
void func_8001FC20(void);
void func_80022610(void);
void func_8006AB40(void);
void func_8003BB9C(void);
void func_8003BFA8(void);
void func_800390B8(void);
extern void func_80031070(void);
void func_800509D0(void);
void func_8002214C(void);
void func_8002A194(void);
void func_8004983C(void);
void func_800204F0(void);
extern void func_8006B370(unsigned long spec);
void func_8001FD58(void);
extern void func_8006A4C4(void);
void func_8003BB20(void);
void func_80020D60(void);
void func_8005010C(s32 vol, s32 pan);

void func_8001ED6C(void) {
    Unk8002CE64_Prim *p0;
    Unk8002CE64_Prim *p1;
    s16 i;

    D_800A3414 = 0;
    D_800A2F34 = 0;
    D_800A3454 = 0;
    D_800A319C = 0;
    D_800A34C4 = 0;
    D_800A322C = func_8001E9DC(2);
    D_800A304C = func_8001E9DC(6);
    D_800A303C = -1;
    D_800A2FBC = 0x7FFFFFFF;
    D_800A3534 = NULL;
    switch (D_800A307C) {
    case 0:
    case 4:
    case 9:
    case 14:
    case 19:
    case 23:
        D_800A2F2C = 0;
        D_800A2F74 = 0;
    }
    D_800A30EC = 0;
    p0 = D_800A8078[0].unk2874;
    p1 = D_800A8078[1].unk2874;
    for (D_800A301C = 0; D_800A301C < 500; D_800A301C++) {
        setPolyFT4(p0);
        setPolyFT4(p1);
        setShadeTex(p0, 1);
        setShadeTex(p1, 1);
        p0++;
        p1++;
    }
    for (i = 1; i < 0x80; i++) {
        ((s32 *)&D_801F7D24)[i] = 0;
    }
    D_801F7D6C = (struct Task *)func_80021264(func_80056918, 1, 0x4C);
    func_800569DC();
    LoadClut((u16 *)D_800C38C8, 0x280, 0xFF);
    func_8004BDD0();
    func_8004DFD0();
    func_800411E4();
    func_80036F28();
    func_800498B0();
    func_80051960();
    func_8001FC20();
    D_801F7D30 = func_80021264(func_80022610, 1, 0);
    func_8006AB40();
    func_8003BB9C();
    func_8003BFA8();
    func_800390B8();
    D_801F7D40 = func_80021264(func_80031070, 1, 8);
    func_800509D0();
    func_8002214C();
    func_8002A194();
    D_801F7D4C = func_80021264(func_8004983C, 1, 0);
    if (D_800A329C == 0) {
        D_800A305C[0] = 90;
        func_80021264(func_800204F0, 1, 0);
    }
    D_800A29F0 = 0;
    func_8006B370(0xF2000001);
    for (i = 0; i < 4; i++) {
        D_8007C4FC[i].x = 0;
    }
    D_800A2A26 = 0;
    D_800A3574 = 0;
    func_8001FD58();
    D_800A2FCC = 0;
    D_800A31F4 = 3;
    D_800A315C = 0;
    D_800A33F4 = D_800A307C;
    func_8006A4C4();
    func_80021264(func_8003BB20, 1, 0);
    D_800A3184 = 0;
    D_800A2F8C = 0;
    func_80020D60();
    func_8005010C(D_800A350C->unk1784 * 4, 0);
}

extern u16 D_800A3014;
extern s32 D_800A30DC;
extern s16 D_801C1F04[];
extern volatile u16 D_800A32AC[];
extern s16 D_800A33A4;
extern s32 D_800A339C;
extern s16 D_800A356C;
extern s16 D_800A303C;
extern s16 D_800A2F2C;
extern s16 D_800A2F74;
extern void func_8001FF14(void);
extern void func_80031070(void);
extern void func_80050738(s32 arg0);
extern void func_80052E18(s32 arg0);
extern void func_800683E4(void);

void func_8001F0F8(void) {
    D_800A3014 = 12;
    D_800A30DC++;
    if (D_801C1F04[0] != 0 && (D_800A32AC[1] & 0x800)) {
        func_8001FF14();
    }
    switch (D_800A2F0C) {
    case 1:
        func_8001F37C();
        if (D_800A2FEC != 0 && *(s32 *)D_800A317C->vals == 0) {
            func_80052E18(3);
            *(s32 *)D_800A317C->vals = -1;
        }
        break;
    case 6:
    case 7:
    case 8:
    case 12:
        func_80031070();
        func_8001F778();
        break;
    case 11:
        D_800A33A4 = 0;
        func_8001F37C();
        if (D_801C1F04[0] != 0 && D_800A307C == D_800A33F4 && (D_800A32AC[1] & 0x100)) {
            *(s32 *)D_800A317C->vals = 0;
            func_80050738(D_800A339C);
            func_80052E18(4);
            D_801C1F04[0] = 0;
            D_800A2F2C = 0;
            D_800A2F74 = 0;
            D_800A33F4 = D_800A307C - 1;
        }
        if (*(s32 *)D_800A317C->vals == 0 && D_800A356C == 2) {
            *(s32 *)D_800A317C->vals = -1;
            func_80050738(D_800A339C);
            func_80052E18(7);
        }
        break;
    case 13:
        func_8001F37C();
        if (D_800A2FEC != 0) {
            D_800A303C = 0;
            func_800683E4();
            D_800A2F44 = 1;
            D_800A2F0C = 12;
        }
        break;
    }
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A7C8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A7D4);

extern u16 D_8007C42C[];
extern u16 D_800A2A24;
extern s16 D_800A29F0;
extern volatile s32 D_800A31F4;
extern Unk800A8078 D_800A8078[2];
extern Unk8002CE64_Prim *D_800A30A4;
extern Unk8002CE64_Prim *D_800A31C4;
extern void *D_800A3374;
extern u32 *D_800A32E4;
extern s16 D_800A33BC;
extern s16 D_800A33D4;
extern s32 D_800A2F8C;
extern s32 func_8006B350(unsigned long spec);
extern void func_8006B370(unsigned long spec);
extern DISPENV *PutDispEnv(DISPENV *env);
extern DRAWENV *PutDrawEnv(DRAWENV *env);
extern u32 *ClearOTagR(u32 *ot, s32 n);
extern void DrawOTag(u32 *ot);
extern s32 DrawSync(s32 mode);
extern int VSync(int mode);
long func_8001FE30();
int func_800201A0(void);
void func_80020704(void);

void func_8001F37C(void) {
    s16 i;
    s16 cur;
    s32 n;

    for (i = 0; i < 18; i++) {
        D_8007C42C[i] = D_800A2A24 - 1;
    }
    if (D_800A2F0C == 11) {
        func_800201A0();
    }
    if (D_800A2F0C == 1 || D_800A2F0C == 13) {
        DrawSync(0);
        if (func_8006B350(0xF2000001) < 0x100) {
            VSync(0);
        }
        if (func_8006B350(0xF2000001) < 0x1FE) {
            VSync(0);
        }
        func_8001FE30();
        D_800A31F4 = 3;
    } else {
        DrawSync(0);
        n = func_8006B350(0xF2000001);
        if (D_800A29F0 < n) {
            D_800A29F0 = n;
        }
    }
    func_80020704();
    while (D_800A31F4 < 2) {
    }
    D_800A31F4 = 0;
    PutDispEnv(&D_800A8078[D_800A333C].disp);
    ClearOTagR(D_800A8078[D_800A333C].ot, 0xA00);
    cur = D_800A333C;
    n = D_800A30A4 - (Unk8002CE64_Prim *)D_800A8078[cur].buf;
    D_800A32E4 = D_800A8078[cur].ot;
    if (D_800A33BC < n) {
        D_800A33BC = n;
    }
    n = D_800A31C4 - (Unk8002CE64_Prim *)D_800A8078[cur].unk2874;
    if (D_800A33D4 < n) {
        D_800A33D4 = n;
    }
    n = (u8 *)D_800A3374 - (u8 *)D_800A8078[cur].prims;
    if (D_800A2F8C < n) {
        D_800A2F8C = n;
    }
    D_800A333C = cur ^ 1;
    PutDrawEnv(&D_800A8078[D_800A333C].draw);
    DrawOTag(&D_800A8078[D_800A333C].ot[0x9FF]);
    D_800A30A4 = (Unk8002CE64_Prim *)D_800A8078[D_800A333C].buf;
    D_800A31C4 = D_800A8078[D_800A333C].unk2874;
    D_800A3374 = D_800A8078[D_800A333C].prims;
    func_8006B370(0xF2000001);
}

extern Unk800A8078 D_800A8078[2];
extern Unk8002CE64_Prim *D_800A30A4;
extern Unk8002CE64_Prim *D_800A31C4;
extern void *D_800A3374;
extern u32 *D_800A32E4;
extern void DrawOTag(u32 *ot);
extern u32 *ClearOTagR(u32 *ot, s32 n);
extern u16 func_8004FB10(void);
extern s32 func_8006B350(unsigned long spec);
extern DISPENV *PutDispEnv(DISPENV *env);
extern DRAWENV *PutDrawEnv(DRAWENV *env);

void func_8001F778(void) {
    DrawOTag(&D_800A8078[D_800A333C].ot[0x9FF]);
    DrawSync(0);
    VSync(0);
    func_8004FB10();
    if (func_8006B350(0xF2000001) < 0x200) {
        VSync(0);
    }
    func_8004FB10();
    PutDispEnv(&D_800A8078[D_800A333C].disp);
    ClearOTagR(D_800A8078[D_800A333C].ot, 0xA00);
    D_800A32E4 = D_800A8078[D_800A333C].ot;
    D_800A333C ^= 1;
    PutDrawEnv(&D_800A8078[D_800A333C].draw);
    D_800A30A4 = (Unk8002CE64_Prim *)D_800A8078[D_800A333C].buf;
    D_800A31C4 = D_800A8078[D_800A333C].unk2874;
    D_800A3374 = D_800A8078[D_800A333C].prims;
    func_8006B370(0xF2000001);
}

extern s32 D_800A301C;

void func_8001F970(void) {
    D_800A30A4 = (Unk8002CE64_Prim *)D_800A8078[0].buf;
    D_800A31C4 = (Unk8002CE64_Prim *)D_800A8078[1].buf;
    for (D_800A301C = 0; D_800A301C < 0x47E; D_800A301C++) {
        setRGB0(D_800A30A4, 0x80, 0x80, 0x80);
        setRGB0(D_800A31C4, 0x80, 0x80, 0x80);
        setPolyFT4(D_800A30A4);
        setPolyFT4(D_800A31C4);
        setShadeTex(D_800A30A4, 0);
        setShadeTex(D_800A31C4, 0);
        D_800A30A4++;
        D_800A31C4++;
    }
    D_800A301C = 0;
    D_800A30A4 = D_800A8078[0].unk2874;
    D_800A31C4 = D_800A8078[1].unk2874;
    for (; D_800A301C < 0x1F4; D_800A301C++) {
        setRGB0(D_800A30A4, 0x80, 0x80, 0x80);
        setRGB0(D_800A31C4, 0x80, 0x80, 0x80);
        setPolyFT4(D_800A30A4);
        setPolyFT4(D_800A31C4);
        setShadeTex(D_800A30A4, 1);
        setShadeTex(D_800A31C4, 1);
        D_800A30A4++;
        D_800A31C4++;
    }
}

extern s16 D_801C0B44[];
extern s16 D_801C2034[];
s32 func_8001E9DC(s32);
void func_8001FCB0(void);

void func_8001FC20(void) {
    s16 i;

    func_80021264(func_8001FCB0, 1, 0);
    for (i = 0; i < 16; i++) {
        D_801C0B44[i] = func_8001E9DC(360) - 180;
        D_801C2034[i] = 0;
    }
}

void func_8001FCB0(void) {
    s16 i;

    for (i = 0; i < 16; i++) {
        D_801C0B44[i] += D_801C2034[i];
        if (D_801C0B44[i] > 0) {
            D_801C2034[i]--;
            if (D_801C0B44[i] > 180) {
                D_801C0B44[i] = 180;
            }
        } else {
            D_801C2034[i]++;
        }
    }
}

extern long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
extern long EnableEvent(long event);
extern void func_8006B3C0(void);
extern void func_8006B3D0(void);
extern void func_8006B340(unsigned long spec, unsigned short target, long mode);
extern void func_8006B360(unsigned long spec);
extern void func_8006B370(unsigned long spec);
extern long D_800A31AC;
long func_8001FE30();

void func_8001FD58(void) {
    if (D_800A31AC == 0) {
        func_8006B3C0();
        D_800A31AC = OpenEvent(0xF2000003, 2, 0x1000, func_8001FE30);
        EnableEvent(D_800A31AC);
        func_8006B340(0xF2000003, 1, 0x1000);
        func_8006B360(0xF2000003);
        func_8006B370(0xF2000003);
        func_8006B3D0();
    }
}

extern long CloseEvent(long event);

void func_8001FDE4(void) {
    if (D_800A31AC != 0) {
        func_8006B3C0();
        CloseEvent(D_800A31AC);
        D_800A31AC = 0;
        func_8006B3D0();
    }
}

extern s16 D_800A2A68;

long func_8001FE30() {
    D_800A31F4++;
    D_800A2A68--;
    func_8004FB10();
}

extern void *func_80022600(void *);

void *func_8001FE84(s32 size) {
    s32 old = (s32)D_800A33E4;

    D_800A33E4 = func_80022600((void *)(size + old));
    return (void *)old;
}

extern void func_80050758(void);
extern void func_8004FB38(void);
extern void func_8004FFE0(int volume, int pan);
extern s32 func_800504F0(s32, void *);
extern s32 D_800A32A4;

void func_8001FEBC(void) {
    func_80050758();
    func_8004FB38();
    func_8004FFE0(0x3FFF, 0);
    D_800A32A4 = func_800504F0(0, func_8003E414(D_800A33E4, 2));
}

typedef struct {
    u16 unk0;
    char name[6];
    char *desc;
} Unk8007C268;

extern Unk8007C268 D_8007C268[];
extern s16 D_800A29F2;
extern s16 D_800A29F4;
extern void *D_800A3374;
extern volatile u16 D_800A343C[];
extern void func_80053864(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_8001FF14(void) {
    void *prim = D_800A3374;
    s16 n = D_800A29F2;
    u8 col[4] = {0xFF, 0xFF, 0xFF, 0};

    D_800A3374 = prim;
    if (D_800A343C[1] & 0x8000) {
        D_800A33F4 = --D_800A307C;
    }
    if (D_800A343C[1] & 0x2000) {
        D_800A33F4 = ++D_800A307C;
    }
    if (D_800A343C[1] & 0x1000) {
        D_800A29F2 = n - 1;
    }
    if (D_800A343C[1] & 0x4000) {
        D_800A29F2++;
    }
    if (D_800A29F4 < 0) {
        D_800A29F4 = 0;
    }
    if (D_800A29F4 >= 8) {
        D_800A29F4 = 7;
    }
    if (D_800A29F2 < 0) {
        D_800A29F2 = 11;
    }
    if (D_800A29F2 >= 12) {
        D_800A29F2 = 0;
    }
    if (D_800A307C < 0) {
        D_800A307C = 23;
    }
    if (D_800A307C >= 24) {
        D_800A307C = 0;
    }
    func_80053864(40, 224, "LEVEL", 0x600, 0x280, col, col);
    func_80053864(100, 224, D_8007C268[D_800A307C].name, 0x600, 0x280, col, col);
    func_80053864(220, 224, D_8007C268[D_800A307C].desc, 0x600, 0x280, col, col);
}

extern s16 D_800A3424;
extern u8 D_801D7330[][4];
extern int CdGetToc(u8 (*loc)[4]);
extern s16 D_800A3404;

int func_8002014C(void) {
    u8 param[16];

    param[0] = 5;
    CdControlB(0xE, param, 0);
    D_800A3404 = CdGetToc(D_801D7330);
    D_800A3424 = 2;
    return -1;
}

extern s16 D_800A3234;
extern s16 D_800A3024;
extern u32 D_800A314C;
extern s16 D_800A2A68;
extern s16 D_800A3424;
extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
s32 func_80020380(s16 track);

/* CdlGetlocP result: track, index, min, sec, frame, amin, asec, aframe */
static u8 D_800A2E7C[8];

int func_800201A0(void) {
    s16 track = D_800A3234;

    if (track == -1 || D_800A2A68 >= 0) {
        return;
    }
    D_800A2A68 = 20;
    if (D_800A3424 != 0) {
        return;
    }
    if (track != D_800A3024) {
        D_800A3234 = D_800A3024;
        D_800A314C = D_801D7330[D_800A3024 + 1][1] + D_801D7330[D_800A3024 + 1][0] * 90 - 2;
    }
    CdControlB(0x11, 0, D_800A2E7C);
    if (D_800A2E7C[5] * 90 + D_800A2E7C[6] >= D_800A314C) {
        func_80020380(D_800A3234 - 2);
    }
}

extern s16 D_800A3424;
extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);

void func_800202B4(void) {
    u8 result[8];

    if (D_800A3424 != 2) {
        CdControlB(8, 0, result);
        VSync(0);
        D_800A3424 = 2;
    }
}

extern s16 D_800A3424;
extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);

void func_80020300(void) {
    u8 result[8];

    if (D_800A3424 == 1) {
        CdControlB(3, 0, result);
        D_800A3424 = 0;
    }
}

void func_80020340(void) {
    u8 result[8];

    if (D_800A3424 == 0) {
        CdControlB(9, 0, result);
        D_800A3424 = 1;
    }
}

extern s16 D_800A3234;
extern s16 D_800A3024;
extern u32 D_800A314C;
extern s16 D_800A305C[3];
extern s16 D_800A2A68;
extern u8 D_801D7330[][4];
extern int CdControl(unsigned char com, unsigned char *param, unsigned char *result);

s32 func_80020380(s16 track) {
    u8 unused[56];

    D_800A3424 = 0;
    D_800A3234 = track + 2;
    D_800A3024 = D_800A3234;
    D_800A314C = D_801D7330[D_800A3024 + 1][1] + D_801D7330[D_800A3024 + 1][0] * 90 - 2;
    CdControlB(2, D_801D7330[track + 2], 0);
    CdControlB(0xE, (unsigned char *)5, 0);
    CdControl(3, 0, 0);
    D_800A305C[0] = track;
    D_800A305C[1] = 30;
    D_800A2A68 = 20;
    return -1;
}

void func_80020468(void) {
    func_80020380(D_800A307C % 3 + 15);
}

typedef struct {
    u8 val0;
    u8 val1;
    u8 val2;
    u8 val3;
} CdlATV;

extern int CdMix(CdlATV *vol);

void func_800204C0(s32 vol) {
    CdlATV atv;

    atv.val0 = vol;
    atv.val1 = vol;
    atv.val2 = 0;
    atv.val3 = 0;
    CdMix(&atv);
}

extern char D_8007A7C8[];
extern char D_8007A7D4[];
extern u8 D_800A2A30[];
extern u8 D_800A2A3C[];
extern char *strcpy(char *dst, const char *src);

void func_800204F0(void) {
    char text[32];

    switch (D_800A307C) {
    case 3:
    case 8:
    case 13:
    case 18:
    case 22:
        func_80053864(160, (D_800A33C4 >> 1) - 30, D_8007A7C8, 0x600, 0x600, D_800A2A3C, D_800A2A30);
        func_80053864(160, (D_800A33C4 >> 1) + 30, D_8007A7D4, 0x600, 0x600, D_800A2A3C, D_800A2A30);
        break;
    default:
        strcpy(text, "LEVEL ");
        strcpy(text + 6, D_8007C268[D_800A307C].name);
        func_80053864(160, (D_800A33C4 >> 1) - 30, text, 0x600, 0x600, D_800A2A3C, D_800A2A30);
        func_80053864(160, (D_800A33C4 >> 1) + 30, D_8007C268[D_800A307C].desc, 0xAF0, 0x600, D_800A2A3C, D_800A2A30);
        break;
    }
    if (D_800A317C->unk14 != 0) {
        D_800A317C->unk14--;
    } else {
        func_80021554();
    }
}

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A0B);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A10);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A18);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A1C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A20);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A24);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A30);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A34);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A38);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A3C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A40);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A44);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A48);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A4C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A50);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A54);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A58);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A5C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A60);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A64);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A68);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A83C);

extern void FlushCache(void);

void func_800206CC(void) {
    DrawSync(0);
    func_8006B3C0();
    FlushCache();
    func_8006B3D0();
}

extern s16 D_801C1EEE;
extern volatile u16 D_800A343C[];
extern void func_80031070(void);

void func_80020704(void) {
    volatile u16 *pad;

    if (D_801C1EEE != 0) {
        pad = &D_800A343C[1];
        do {
            func_80031070();
            if (*pad & 0x20) {
                return;
            }
        } while (!(*pad & 0x800));
        D_801C1EEE = 0;
    }
}

extern volatile u16 D_800A343C[];
extern volatile u16 D_800A30F4[];
extern volatile u16 D_800A34CC[];
extern volatile u16 D_800A31A4[];

void func_8002076C(void) {
    short i = 1;
    int n;

    while (1) {
        D_800A343C[i] = D_800A30F4[i];
        D_800A34CC[i] = D_800A31A4[i];
        D_800A30F4[i] = 0;
        D_800A31A4[i] = 0;
        n = i--;
        if (n == 0) break;
    }
}

extern volatile u16 D_800A3144[];
extern volatile u16 D_800A2F9C[];
extern volatile u16 D_800A316C[];
extern u8 *D_800A3384[];

void func_800207DC(void) {
    s16 i;

    for (i = 0; i < 2; i++) {
        if (D_800A3384[i][0] != 0) {
            D_800A2F9C[i];
            D_800A316C[i] = D_800A3144[i];
            D_800A3144[i] = 0;
            D_800A30F4[i] |= ~D_800A316C[i] & D_800A3144[i];
            D_800A31A4[i] |= D_800A316C[i] & ~D_800A3144[i];
            D_800A2F9C[i] = 0;
        } else if (D_800A3384[i][1] == 0x41) {
            D_800A316C[i] = D_800A3144[i];
            D_800A3144[i] = ~(D_800A3384[i][3] + (D_800A3384[i][2] << 8));
            D_800A30F4[i] |= ~D_800A316C[i] & D_800A3144[i];
            D_800A31A4[i] |= D_800A316C[i] & ~D_800A3144[i];
            D_800A2F9C[i] = 1;
        } else {
            D_800A316C[i] = D_800A3144[i];
            D_800A3144[i] = 0;
            D_800A30F4[i] |= ~D_800A316C[i] & D_800A3144[i];
            D_800A31A4[i] |= D_800A316C[i] & ~D_800A3144[i];
            D_800A2F9C[i] = 0;
        }
    }
}

typedef struct {
    u8 *c[10];
} Unk8007C394;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
} Unk800209B8_Tile;

extern Unk8007C394 D_8007C394;
extern s16 D_800A3514;
extern void DrawPrim(void *p);

void func_800209B8(void) {
    Unk800209B8_Tile t;
    Unk8007C394 cols = D_8007C394;
    s16 tens = D_800A3514 / 10;
    s16 ones = D_800A3514 % 10;

    t.x0 = ones * 10 + 40;
    t.y0 = tens * 10 + 40;
    t.r0 = cols.c[ones][0];
    t.g0 = cols.c[ones][1];
    t.b0 = cols.c[ones][2];
    setlen(&t, 2);
    setcode(&t, 0x70);
    DrawPrim(&t);
    t.x0 = 0xA0;
    t.y0 = 0xC8;
    t.r0 = cols.c[tens][0];
    t.g0 = cols.c[tens][1];
    t.b0 = cols.c[tens][2];
    setlen(&t, 2);
    setcode(&t, 0x70);
    DrawPrim(&t);
    func_8001F778();
    if (++D_800A3514 >= 100) {
        D_800A3514 = 0;
    }
}

void func_80020B90(void) {
    Unk800209B8_Tile t;
    Unk8007C394 cols = D_8007C394;
    s16 tens = D_800A3514 / 10;
    s16 ones = D_800A3514 % 10;

    t.x0 = ones * 10 + 40;
    t.y0 = tens * 10 + 40;
    t.r0 = cols.c[ones][0];
    t.g0 = cols.c[ones][1];
    t.b0 = cols.c[ones][2];
    setlen(&t, 2);
    setcode(&t, 0x70);
    DrawPrim(&t);
    t.x0 = 0xA0;
    t.y0 = 0xC8;
    t.r0 = cols.c[tens][0];
    t.g0 = cols.c[tens][1];
    t.b0 = cols.c[tens][2];
    setlen(&t, 2);
    setcode(&t, 0x70);
    DrawPrim(&t);
    if (++D_800A3514 >= 100) {
        D_800A3514 = 0;
    }
}
extern u32 *D_800A32E4;
extern void *D_800A3374;
extern DRAWENV *SetDrawEnv(DR_ENV *dr_env, DRAWENV *env);

extern s16 D_800A3104;
extern s16 D_800A33C4;
extern char D_8007A83C[];
extern u8 D_800A2A34[];
void func_80020E38(s16 ofsx, s16 ofsy, u8 isbg, s16 x, s16 y, s16 w, s16 h);
extern void func_80053864(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_80020D60(void) {
    D_800A3104 = 0x9FE;
    if (D_800A333C == 0) {
        func_80020E38(320, 0, 0, 320, 0, 320, D_800A33C4);
    } else {
        func_80020E38(0, 0, 0, 0, 0, 320, D_800A33C4);
    }
    func_80053864(100, 56, D_8007A83C, 0x800, 0x800, D_800A2A34, D_800A2A34);
    func_80020E38(640, 0, 0, 640, 0, 320, 120);
}

void func_80020E38(s16 ofsx, s16 ofsy, u8 isbg, s16 x, s16 y, s16 w, s16 h) {
    DR_ENV *prim = D_800A3374;
    DRAWENV env;

    env.clip.x = x;
    env.clip.y = y;
    env.clip.w = w;
    env.clip.h = h;
    env.ofs[0] = ofsx;
    env.ofs[1] = ofsy;
    env.tw.x = 0;
    env.tw.y = 0;
    env.tw.w = 255;
    env.tw.h = 255;
    env.dtd = 255;
    env.dfe = 255;
    env.isbg = isbg;
    env.r0 = 0;
    env.g0 = 0;
    env.b0 = 0;
    SetDrawEnv(prim, &env);
    addPrim(D_800A32E4 + 0x9FE, prim);
    prim++;
    D_800A3374 = prim;
}

extern struct {
    s16 count[3];
    s16 size[3];
    s16 total;
    s16 unk8;
    s32 left;
} D_801D20B4;
extern u8 D_801C2058[];
extern u8 *D_801F7724[];
extern u8 *D_801F7924[];
extern u8 *D_801F7B24[];
extern u8 D_801F75A4[];
extern u8 D_801F7624[];
extern u8 D_801F76A4[];
extern s16 D_801F759C[3];
extern struct Task D_800A61F0[];
extern s16 D_800A31EC;
extern s16 D_800A3314;
extern s16 D_800A31BC;
extern s16 D_800A332C;
extern s16 D_800A3484;
extern s16 D_800A330C;
extern s32 D_800A79CC;
extern struct Task *D_800A32C4;
extern s32 D_800A2F7C;

void func_80020F08(void) {
    s32 left;
    u8 *p;
    s16 i;

    D_800A31EC = 0;
    D_800A3314 = 0;
    D_800A31BC = 0;
    D_800A332C = 0x800;
    D_800A3484 = 0x800;
    D_800A330C = 0x800;
    D_801D20B4.count[0] = 0x1C;
    D_801D20B4.count[1] = 0x10;
    D_801D20B4.count[2] = 0x10;
    D_801D20B4.size[0] = 0x400;
    D_801D20B4.size[1] = 0x200;
    D_801D20B4.size[2] = 0x168;
    D_801D20B4.unk8 = 5;
    left = 0x10000;
    p = D_801C2058;
    for (i = 0; i < D_801D20B4.count[0]; i++) {
        if (left - D_801D20B4.size[0] < 0) {
            D_801D20B4.count[0] = i;
            break;
        }
        D_801F7724[i] = p;
        D_801F75A4[i] = 0;
        p += D_801D20B4.size[0];
        left -= D_801D20B4.size[0];
    }
    if (left > 0) {
        for (i = 0; i < D_801D20B4.count[1]; i++) {
            if (left - D_801D20B4.size[1] < 0) {
                D_801D20B4.count[1] = i;
                break;
            }
            D_801F7924[i] = p;
            D_801F7624[i] = 0;
            p += D_801D20B4.size[1];
            left -= D_801D20B4.size[1];
        }
    } else {
        D_801D20B4.count[1] = 0;
    }
    if (left > 0) {
        for (i = 0; ; i++) {
            if (left - D_801D20B4.size[2] < 0) {
                D_801D20B4.count[2] = i;
                break;
            }
            D_801F7B24[i] = p;
            D_801F76A4[i] = 0;
            p += D_801D20B4.size[2];
            left -= D_801D20B4.size[2];
        }
        D_801D20B4.count[2] = i;
    } else {
        D_801D20B4.count[2] = 0;
    }
    D_801D20B4.left = left;
    D_800A2F7C = 0;
    D_800A317C = D_800A61F0;
    D_800A61F0[0].unk2E = 0;
    D_800A61F0[0].unk2F = 0;
    D_801F75A4[0] = 0xFF;
    D_800A32C4 = &D_800A61F0[1];
    D_800A61F0[0].next = D_800A61F0;
    D_800A61F0[0].prev = D_800A61F0;
    D_801D20B4.total = D_801D20B4.count[0] + D_801D20B4.count[1] + D_801D20B4.count[2];
    D_801F759C[0] = D_801D20B4.count[0];
    D_801F759C[1] = D_801D20B4.count[1];
    D_801F759C[2] = D_801D20B4.count[2];
    D_800A61F0[0].vals = (Unk800A317CVals *)D_801F7724[0];
    D_801F759C[0] = D_801D20B4.count[0] - 1;
    for (i = 1; i < 0x80; i++) {
        D_800A61F0[i].next = &D_800A61F0[i + 1];
        ((s32 *)&D_801F7D24)[i] = 3;
    }
    D_800A79CC = 0;
}

extern struct Task *D_800A32C4;
extern s32 D_800A2F7C;
extern s32 func_8002186C(s16);

Unk8003BA6C_Task *func_80021264(void (*fn)(), s16 flags, s16 size) {
    struct Task *t;
    struct Task *next;

    if (D_800A32C4 == NULL) {
        return NULL;
    }
    if ((s16)func_8002186C(size) == 0) {
        return NULL;
    }
    t = D_800A32C4;
    t->func = fn;
    next = t->next;
    D_800A317C->next->prev = t;
    t->next = D_800A317C->next;
    D_800A317C->next = t;
    t->prev = D_800A317C;
    t->unk14 = D_800A305C[0];
    t->unk16 = D_800A305C[1];
    t->unk18 = D_800A305C[2];
    D_800A32C4 = next;
    t->id = D_800A2F7C++;
    t->unk28 = 0xFF;
    t->unk29 = 0xFF;
    t->unk2A = 0xFF;
    t->flags = flags;
    t->cleanup = NULL;
    return (Unk8003BA6C_Task *)t;
}

extern struct Task *D_801F7D6C;

struct Task *func_80021358(void (*fn)(), s16 flags, s16 size) {
    struct Task *anchor = D_801F7D6C;
    struct Task *t;
    struct Task *next;

    if (D_800A32C4 == NULL) {
        return NULL;
    }
    if ((s16)func_8002186C(size) == 0) {
        return NULL;
    }
    t = D_800A32C4;
    t->func = fn;
    next = t->next;
    anchor->prev->next = t;
    t->prev = anchor->prev;
    t->next = anchor;
    anchor->prev = t;
    t->unk14 = D_800A305C[0];
    t->unk16 = D_800A305C[1];
    t->unk18 = D_800A305C[2];
    D_800A32C4 = next;
    t->id = D_800A2F7C++;
    t->flags = flags;
    t->cleanup = NULL;
    t->unk28 = 0x80;
    t->unk29 = 0x80;
    t->unk2A = 0x80;
    return t;
}

struct Task *func_80021454(struct Task *parent, void (*fn)(), s16 flags, s16 size) {
    struct Task *t;
    struct Task *next;

    if (D_800A32C4 == NULL) {
        return NULL;
    }
    if ((s16)func_8002186C(size) == 0) {
        return NULL;
    }
    t = D_800A32C4;
    t->func = fn;
    next = t->next;
    parent->next->prev = t;
    t->next = parent->next;
    parent->next = t;
    t->prev = parent;
    t->unk14 = D_800A305C[0];
    t->unk16 = D_800A305C[1];
    t->unk18 = D_800A305C[2];
    D_800A32C4 = next;
    t->id = D_800A2F7C++;
    t->flags = flags;
    t->cleanup = NULL;
    t->unk28 = 0;
    t->unk29 = 200;
    t->unk2A = 0xFF;
    return t;
}

void func_80021554(void) {
    struct Task *t;
    struct Task *next;

    switch (D_800A317C->unk2E) {
    case -1:
        break;
    case 0:
    case 1:
        D_801F75A4[D_800A317C->unk2F] = 0;
        D_801F759C[0]++;
        break;
    case 2:
        D_801F7624[D_800A317C->unk2F] = 0;
        D_801F759C[1]++;
        break;
    case 3:
        D_801F76A4[D_800A317C->unk2F] = 0;
        D_801F759C[2]++;
        break;
    }
    D_800A317C->unk2E = 0xFF;
    D_800A317C->unk2F = 0xFF;
    t = D_800A317C;
    t->vals = (Unk800A317CVals *)3;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    next = D_800A32C4;
    D_800A32C4 = t;
    t->next = next;
    D_800A317C = t->prev;
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A85C);

extern void func_80021554(void);

void func_80021698(s16 mask) {
    struct Task *cur = D_800A317C;

    for (D_800A317C = cur->next; D_800A317C != cur; D_800A317C = D_800A317C->next) {
        if (mask & D_800A317C->flags) {
            if (D_800A317C->cleanup != NULL) {
                D_800A317C->cleanup();
            }
            func_80021554();
        }
    }
    D_800A317C = cur;
}

extern void func_80020F08(void);
extern void func_8001EA74(void);
extern s16 D_800A3414;
extern s16 D_800A2F34;
extern s16 D_800A3454;
extern s16 D_800A3294;
extern s16 D_800A33CC;
extern s16 D_800A32BC;
extern u16 D_800A3014;

void func_8002174C(void) {
    func_80020F08();
    D_800A317C->unk28 = 0xFF;
    D_800A317C->unk29 = 0xFF;
    D_800A317C->unk2A = 0;
    D_800A3414 = 0;
    D_800A2F34 = 0;
    D_800A3454 = 0;
    D_800A3294 = 0;
    D_800A33CC = 0;
    D_800A32BC = 0;
    D_800A317C->func = func_8001EA74;
    for (;;) {
        D_800A317C->func();
        D_800A3014 += 5;
        D_800A317C = D_800A317C->next;
    }
}

void func_8002182C(struct Task *task) {
    struct Task *saved = D_800A317C;

    D_800A317C = task;
    task->func();
    D_800A317C = saved;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002186C);

typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR;

typedef struct {
    s16 m[3][3];
    s32 t[3];
} MATRIX;

typedef struct {
    s32 vx, vy, vz, pad;
} VECTOR;

extern s16 D_800A2A1A;
extern s16 D_800A2A20;
extern SVECTOR D_800A2FC4;
extern SVECTOR D_800A3194;
extern SVECTOR D_800A349C;
extern MATRIX D_801C0B64;
extern VECTOR D_801C1EC4;
extern MATRIX *func_8002384C(SVECTOR *rot, MATRIX *m);
extern void func_800223C8(MATRIX *m, s16 arg1);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX *func_80070C9C(MATRIX *m, VECTOR *v);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);

void func_80021BE4(void) {
    if (D_800A2A1A != 0) {
        D_800A2A1A--;
        D_800A3194.vx = func_8001E9DC(0x50) + (s16)(D_800A3194.vx - 0x28);
        D_800A3194.vy = func_8001E9DC(0x50) + (s16)(D_800A3194.vy - 0x28);
        D_800A3194.vz = func_8001E9DC(0x50) + (s16)(D_800A3194.vz - 0x28);
    }
    D_800A349C.vx = -D_800A3194.vx;
    D_800A349C.vy = -D_800A3194.vy;
    D_800A349C.vz = -D_800A3194.vz;
    func_8002384C(&D_800A2FC4, &D_801C0B64);
    func_800223C8(&D_801C0B64, D_800A2A20);
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    func_80070C9C(&D_801C0B64, &D_801C1EC4);
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80021D44);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002214C);

void func_800223C8(MATRIX *m, s16 scale) {
    m->m[2][0] = (m->m[2][0] * scale) >> 12;
    m->m[2][1] = (m->m[2][1] * scale) >> 12;
    m->m[2][2] = (m->m[2][2] * scale) >> 12;
}

s32 func_80022424(void) {
    return 0;
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 w, h;
} TILE;

typedef struct {
    u8 minute, second, sector, track;
} CdlLOC;

typedef struct {
    CdlLOC pos;
    u32 size;
    char name[16];
} CdlFILE;

extern void CdSetDebug(int level);
extern CdlFILE *CdSearchFile(CdlFILE *fp, char *name);
extern int CdRead(int sectors, u32 *buf, int mode);
extern void SetTile(TILE *p);
extern void DrawPrim(void *p);
extern int CdReadSync(int mode, u8 *result);
extern s32 func_80022424();

s32 func_8002242C(u32 *buf, char *name) {
    CdlFILE file;
    TILE tile;
    s32 i;

    CdSetDebug(0);
    if (CdSearchFile(&file, name) == NULL) {
        for (i = 0; i < 201; i++) {
            VSync(0);
            LoadTPage(func_80022424, 0, 0, 0xFA, i & 0xFF, 0x100, 0x100);
        }
        return 0;
    }
    CdControlB(0x15, (unsigned char *)&file.pos, 0);
    CdRead((file.size + 0x7FF) >> 11, buf, 0x80);
    i = 0;
    tile.x0 = 0;
    tile.y0 = 200;
    tile.w = 320;
    tile.h = 15;
    tile.r0 = 0;
    tile.g0 = 0;
    tile.b0 = 0;
    SetTile(&tile);
    DrawPrim(&tile);
    tile.w = 1;
    tile.h = 5;
    tile.r0 = 0xFF;
    tile.g0 = 0xFF;
    tile.b0 = 0;
    while (CdReadSync(1, 0) > 0) {
        VSync(0);
        if (i++ > 300) {
            return 0;
        }
        switch (i % 10) {
        case 0:
            tile.h = 10;
            break;
        case 5:
            tile.h = 5;
            break;
        default:
            tile.h = 1;
            break;
        }
        tile.x0 = i;
        DrawPrim(&tile);
    }
    return file.size;
}

void *func_80022600(void *p) {
    u32 v = (u32)p;
    v += 3;
    v &= ~3;
    return (void *)v;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80022610);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80022D60);

extern unsigned short D_801FC0D8[16];
extern void SetFarColor(long r, long g, long b);
extern int func_800296F8(s32 a, s32 b, s32 t);

void func_80023270(unsigned short *src, s16 t, u8 r, u8 g, u8 b) {
    unsigned short *dst;
    u8 col[3];
    unsigned short i;
    int semi;
    unsigned short stp;

    SetFarColor(r, g, b);
    dst = D_801FC0D8;
    i = 0;
    semi = 0;
    for (; i < 16; i++) {
        stp = 0;
        if (*src == 0) {
            col[0] = 0;
            col[1] = 0;
            col[2] = 0;
            src++;
        } else {
            if (semi) {
                stp = (i < 4) << 15;
            } else {
                stp = 0x8000;
            }
            col[0] = (*src & 0x1F) << 3;
            col[1] = ((*src >> 5) & 0x1F) << 3;
            col[2] = ((*src >> 10) & 0x1F) << 3;
            src++;
            col[0] = func_800296F8(col[0], r, t);
            col[1] = func_800296F8(col[1], g, t);
            col[2] = func_800296F8(col[2], b, t);
        }
        *dst++ = stp | (((col[0] >> 3) + ((col[1] >> 3) << 5) + ((col[2] >> 3) << 10)) & 0x7FFF);
    }
}

extern unsigned short D_801FC0D8[16];

void func_80023400(unsigned short *src) {
    unsigned short *dst = D_801FC0D8;
    unsigned short i;
    int unused[2];

    for (i = 0; i < 16; i++) {
        if (*src == 0) {
            *dst = 0;
        } else {
            *dst = 0xFFFF;
        }
        dst++;
        src++;
    }
}

extern s16 D_800854C0[];

MATRIX *func_80023450(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    s16 cxsy, sxsy;

    cx = D_800854C0[(-(u16)r->vx + 0x400) & 0xFFF];
    sy = D_800854C0[-(u16)r->vy & 0xFFF];
    sx = D_800854C0[-(u16)r->vx & 0xFFF];
    cxsy = (cx * sy) >> 12;
    sxsy = (sx * sy) >> 12;
    cy = D_800854C0[(-(u16)r->vy + 0x400) & 0xFFF];
    cz = D_800854C0[(-(u16)r->vz + 0x400) & 0xFFF];
    sz = D_800854C0[-(u16)r->vz & 0xFFF];
    m->m[0][0] = (u32)(cy * cz) >> 12;
    m->m[0][1] = (u32)(-cx * sz - sxsy * cz) >> 12;
    m->m[0][2] = (u32)(sx * sz - cxsy * cz) >> 12;
    m->m[1][0] = (u32)(cy * sz) >> 12;
    m->m[1][1] = (u32)(cx * cz - sxsy * sz) >> 12;
    m->m[1][2] = (u32)(-sx * cz - cxsy * sz) >> 12;
    m->m[2][0] = sy;
    m->m[2][1] = (u32)(sx * cy) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

MATRIX *func_80023660(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    u16 ax, ay, az;
    s32 cxsy, cxcy, sxsy, sxcy;

    ax = r->vx;
    ay = r->vy;
    cx = D_800854C0[(ax + 0x400) & 0xFFF];
    sy = D_800854C0[ay & 0xFFF];
    cxsy = cx * sy;
    cy = D_800854C0[(ay + 0x400) & 0xFFF];
    cxcy = cx * cy;
    sx = D_800854C0[ax & 0xFFF];
    sxsy = sx * sy;
    sxcy = sx * cy;
    az = r->vz;
    cz = D_800854C0[(az + 0x400) & 0xFFF];
    sz = D_800854C0[az & 0xFFF];
    m->m[0][0] = (u32)(cy * cz) >> 12;
    m->m[0][1] = (u32)(-(s16)(cxcy >> 12) * sz - sxsy) >> 12;
    m->m[0][2] = (u32)((s16)(sxcy >> 12) * sz - cxsy) >> 12;
    m->m[1][0] = sz;
    m->m[1][1] = (u32)(cx * cz) >> 12;
    m->m[1][2] = (u32)(-sx * cz) >> 12;
    m->m[2][0] = (u32)(sy * cz) >> 12;
    m->m[2][1] = (u32)(-(s16)(cxsy >> 12) * sz + sxcy) >> 12;
    m->m[2][2] = (u32)((s16)(sxsy >> 12) * sz + cxcy) >> 12;
    return m;
}

MATRIX *func_8002384C(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800854C0[ax & 0xFFF];
    sy = D_800854C0[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800854C0[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800854C0[(az + 0x400) & 0xFFF];
    sz = D_800854C0[az & 0xFFF];
    cx = D_800854C0[(ax + 0x400) & 0xFFF];
    m->m[0][0] = -((cy * cz + (s16)(sxsy >> 12) * sz) >> 12);
    m->m[0][1] = -((-cx * sz) >> 12);
    m->m[0][2] = -((-sy * cz + (s16)(sxcy >> 12) * sz) >> 12);
    m->m[1][0] = -((cy * sz - (s16)(sxsy >> 12) * cz) >> 12);
    m->m[1][1] = -((cx * cz) >> 12);
    m->m[1][2] = -((-sy * sz - (s16)(sxcy >> 12) * cz) >> 12);
    m->m[2][1] = sx;
    m->m[2][0] = (u32)(cx * sy) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

MATRIX *func_80023A64(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800854C0[ax & 0xFFF];
    sy = D_800854C0[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800854C0[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800854C0[(az + 0x400) & 0xFFF];
    sz = D_800854C0[az & 0xFFF];
    cx = D_800854C0[(ax + 0x400) & 0xFFF];
    m->m[0][0] = -((cy * cz + (s16)(sxsy >> 12) * sz) >> 12);
    m->m[0][1] = -((-cx * sz) >> 12);
    m->m[0][2] = -((-sy * cz + (s16)(sxcy >> 12) * sz) >> 12);
    m->m[1][0] = -((cy * sz - (s16)(sxsy >> 12) * cz) >> 12);
    m->m[1][1] = -((cx * cz) >> 12);
    m->m[1][2] = -((-sy * sz - (s16)(sxcy >> 12) * cz) >> 12);
    m->m[2][1] = sx;
    m->m[2][0] = (u32)(cx * sy) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

MATRIX *func_80023C7C(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, sy, sz;
    s32 cy, cz;
    u16 ax, ay, az;
    s32 cxsy, sxsy;

    ax = r->vx;
    ay = r->vy;
    cx = D_800854C0[(ax + 0x400) & 0xFFF];
    sy = D_800854C0[ay & 0xFFF];
    cxsy = cx * sy;
    sx = D_800854C0[ax & 0xFFF];
    sxsy = sx * sy;
    az = r->vz;
    cy = D_800854C0[(ay + 0x400) & 0xFFF];
    cz = D_800854C0[(az + 0x400) & 0xFFF];
    sz = D_800854C0[az & 0xFFF];
    m->m[0][2] = -sy;
    m->m[0][0] = (u32)(cy * cz) >> 12;
    m->m[0][1] = (u32)(-cy * sz) >> 12;
    m->m[1][0] = (u32)(cx * sz - (s16)(sxsy >> 12) * cz) >> 12;
    m->m[1][1] = (u32)((s16)(sxsy >> 12) * sz + cx * cz) >> 12;
    m->m[1][2] = (u32)(-sx * cy) >> 12;
    m->m[2][0] = (u32)((s16)(cxsy >> 12) * cz + sx * sz) >> 12;
    m->m[2][1] = (u32)(sx * cz - (s16)(cxsy >> 12) * sz) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80023E80);

extern int func_800296F8(s32 a, s32 b, s32 t);

void func_800241BC(s16 *a, s16 *b, s16 t, s16 *out) {
    out[0] = func_800296F8(a[0], b[0], t);
    out[1] = func_800296F8(a[1], b[1], t);
    out[2] = func_800296F8(a[2], b[2], t);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80024240);

typedef struct {
    int *p;
    int pad[3];
} Entry16;

extern Entry16 *D_800A353C;

typedef struct {
    s16 v[27][4];
} Unk800245B8_Frame;

typedef struct {
    s32 unk0;
    u16 count;
    u8 pad6[0x12];
    Unk800245B8_Frame frames[1];
} Unk800245B8;

void func_800245B8(s16 idx) {
    Unk800245B8 *anim = (Unk800245B8 *)D_800A353C[idx].p;
    Unk800245B8_Frame *f;
    s16 tmp[4];
    s16 n = anim->count;

    while (n--) {
        f = &anim->frames[n];
        func_800241BC(f->v[4], f->v[5], 0x800, tmp);
        func_800241BC(f->v[4], tmp, 0x100, f->v[4]);
        func_800241BC(f->v[5], tmp, 0x400, f->v[5]);
        func_800241BC(f->v[6], f->v[7], 0x800, tmp);
        func_800241BC(f->v[6], tmp, 0x400, f->v[6]);
        func_800241BC(f->v[7], tmp, 0x400, f->v[7]);
        func_800241BC(f->v[8], f->v[9], 0x800, tmp);
        func_800241BC(f->v[8], tmp, 0x100, f->v[8]);
        func_800241BC(f->v[9], tmp, 0x400, f->v[9]);
        func_800241BC(f->v[10], f->v[11], 0x800, tmp);
        func_800241BC(f->v[10], tmp, 0x400, f->v[10]);
        func_800241BC(f->v[11], tmp, 0x400, f->v[11]);
        func_800241BC(f->v[4], f->v[8], 0x800, tmp);
        func_800241BC(f->v[4], tmp, -0x7D0, f->v[4]);
        func_800241BC(f->v[8], tmp, -0x7D0, f->v[8]);
        func_800241BC(f->v[14], f->v[15], -0x200, f->v[14]);
        func_800241BC(f->v[20], f->v[21], -0x200, f->v[20]);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800247D4);

extern void *D_800A351C;
extern void *D_800A310C;
extern u8 D_801FB888[];
extern u8 D_8007F9A8[];
extern u8 D_8007FB14[];
extern u8 D_8007FC48[];
extern u8 D_8007FDB4[];
extern void *func_80022600(void *);
extern void func_800247D4(u8 *);
extern void func_80024240(s16);
extern void func_800245B8(s16);

void func_800248D4(void) {
    s32 *file;
    s32 n;
    Entry16 *e;
    s16 i;

    D_800A351C = func_80022600(D_801FB888);
    func_800247D4(D_8007F9A8);
    func_800247D4(D_8007FC48);
    func_800247D4(D_8007FB14);
    func_800247D4(D_8007FDB4);
    file = func_8003E414(D_800A33E4, 0);
    n = *file;
    D_800A353C = (Entry16 *)(file + 1);
    while (n--) {
        e = D_800A353C++;
        e->p = (int *)((u8 *)file + (s32)e->p);
    }
    D_800A353C = (Entry16 *)(file + 1);
    D_800A33E4 = func_8003E414(D_800A33E4, 1);
    D_800A310C = func_80022600(D_800A33E4);
    i = *file;
    while (i--) {
        func_80024240(i);
    }
    i = *file;
    while (i--) {
        func_800245B8(i);
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    u8 unk2C;
    u8 unk2D;
    u8 pad2E[0x14];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
} Obj80024D00;

void func_80024A2C(Obj80024D00 *src, Obj80024D00 *dst) {
    dst->unk0 = src->unk0;
    dst->unk2 = src->unk2;
    dst->unk4 = src->unk4;
    dst->unk6 = src->unk6;
    dst->unk8 = src->unk8;
    dst->unkC = src->unkC;
    dst->unk10 = src->unk10;
    dst->unk14 = src->unk14;
    dst->unk16 = src->unk16;
    dst->unk18 = src->unk18;
    dst->unk1A = src->unk1A;
    dst->unk1C = src->unk1C;
    dst->unk1E = src->unk1E;
    dst->unk20 = src->unk20;
    dst->unk22 = src->unk22;
    dst->unk24 = src->unk24;
    dst->unk26 = src->unk26;
    dst->unk28 = src->unk28;
    dst->unk2A = src->unk2A;
    dst->unk2C = src->unk2C;
    dst->unk2D = src->unk2D;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 padB;
} Unk800A30B4;

extern Unk800A30B4 *D_800A30B4;

void func_80024B28(Obj80024D00 *obj, s16 idx) {
    obj->unk2D = D_800A30B4[idx].unkA;
    obj->unk20 = D_800A30B4[idx].unk0;
    obj->unk22 = D_800A30B4[idx].unk2;
    obj->unk24 = D_800A30B4[idx].unk4;
    obj->unk26 = D_800A30B4[idx].unk6;
    obj->unk28 = D_800A30B4[idx].unk8;
    obj->unk2A = 3500;
}

extern s16 D_800A324C;

void func_80024BA8(Obj80024D00 *obj) {
    s16 idx;

    idx = func_8001E9DC(D_800A324C);
    obj->unk2D = D_800A30B4[idx].unkA;
    obj->unk24 = D_800A30B4[idx].unk4;
    idx = func_8001E9DC(D_800A324C);
    obj->unk20 = D_800A30B4[idx].unk0;
    idx = func_8001E9DC(D_800A324C);
    obj->unk22 = D_800A30B4[idx].unk2;
    idx = func_8001E9DC(D_800A324C);
    obj->unk26 = D_800A30B4[idx].unk6;
    idx = func_8001E9DC(D_800A324C);
    obj->unk28 = D_800A30B4[idx].unk8;
    obj->unk2A = 3500;
}

void func_80024BA8(Obj80024D00 *obj);

void func_80024D00(Obj80024D00 *obj) {
    obj->unk0 = obj->unk2 = 0;
    obj->unk4 = 0;
    obj->unk6 = 0;
    obj->unk8 = 0;
    obj->unkC = 0;
    obj->unk10 = 0;
    obj->unk14 = 0;
    obj->unk16 = 0;
    obj->unk18 = 0;
    obj->unk1A = 0x1000;
    obj->unk1C = 0;
    obj->unk1E = 0;
    obj->unk2A = 3500;
    obj->unk2C = 100;
    func_80024BA8(obj);
}

int func_80024D64(int i) {
    return (s16)func_8001E9DC(*D_800A353C[(s16)i].p);
}

typedef struct {
    u16 prevId;
    u16 id;
    u8 pad4[2];
    s16 unk6;
    u32 prevTime;
    u32 time;
    u32 unk10;
    u16 unk14;
    u16 unk16;
    u8 pad18[2];
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
} Anim;

extern Entry16 *D_800A353C;

void func_80024DA8(anim, id, time, arg3, blend)
Anim *anim;
s16 id;
s16 time;
s16 arg3;
s16 blend;
{
    if (anim->unk1E != 0) {
        blend = 0;
        anim->unk1E = 0;
    }
    anim->prevId = anim->id;
    anim->prevTime = anim->time;
    if (time != -1) {
        anim->time = time;
    }
    anim->time = anim->time / D_800A353C[id].p[2] * D_800A353C[id].p[2];
    anim->id = id;
    anim->unk6 = arg3;
    if (blend != 0) {
        anim->unk16 = 1;
        anim->unk1A = 0x1000 / blend;
    } else {
        anim->unk16 = 0;
    }
}

void func_80024EA0(Anim *anim, s16 id, s16 time, s16 arg3, s16 blend) {
    if (anim->id != (u16)id) {
        func_80024DA8(anim, id, time, arg3, blend);
    }
}

s16 func_80024EF0(Anim *anim) {
    s16 ret = 0;
    int *info;
    s32 t;

    if (anim->unk16 == 2) {
        anim->unk10 += anim->unk1A;
        if (anim->unk10 >= 0x1000) {
            anim->unk16 = 0;
        }
    } else {
        info = D_800A353C[anim->id].p;
        t = anim->unk6 + anim->time;
        if (t >= info[0]) {
            anim->time = t - info[0];
        } else if (t < 0) {
            anim->time = t + info[0];
        } else {
            anim->time = t;
        }
        if (anim->unk14 & 1) {
            if (info[2] * 2 + anim->time >= info[0]) {
                anim->unk6 = 0;
                ret = -1;
            }
        }
        if (anim->time >= info[0]) {
            ret = -1;
        }
        anim->time %= info[0];
    }
    return ret;
}

s32 func_80024FFC(s16 a, s16 b) {
    return (a + b - 0x100) >> 5;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002501C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A86C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A6C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A74);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A7C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A80);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A88);

extern s32 SquareRoot0(s32 a);
extern s16 D_800874C0[];

s32 func_80028B04(Unk8002A35C *a, Unk8002A35C *b) {
    s32 dx = a->x - b->x;
    s32 adx = ABS(dx);
    s32 dz = a->z - b->z;
    s32 adz = ABS(dz);
    s32 dist;
    s32 s;
    s32 c;
    s32 ang;

    dist = (SquareRoot0((adx * adx + adz * adz) >> 4) + 2) << 2;
    if (dist < 2) {
        return -1;
    }
    s = (adx << 10) / dist;
    c = (adz << 10) / dist;
    if (c >= 0x400) {
        c = 0x3FF;
    }
    if (s >= 0x2D5) {
        ang = 0x400 - D_800874C0[c];
    } else {
        ang = D_800874C0[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return (s16)(0x1000 - ang);
}

typedef struct {
    s32 vx;
    s32 vy;
    s32 vz;
} Vec32;

s16 func_80028C78(Vec32 *a, Vec32 *b) {
    s32 dx = a->vx - b->vx;
    s32 adx = ABS(dx);
    s32 dz = a->vz - b->vz;
    s32 adz = ABS(dz);
    s32 dist;
    s32 s;
    s32 c;
    s32 ang;

    if (adx > 0x8000 || adz > 0x8000) {
        adx >>= 8;
        adz >>= 8;
    }
    dist = (SquareRoot0((adx * adx + adz * adz) >> 4) + 2) << 2;
    if (dist < 2) {
        return -1;
    }
    s = (adx << 10) / dist;
    c = (adz << 10) / dist;
    if (s >= 0x400) {
        s = 0x3FF;
    }
    if (c >= 0x400) {
        c = 0x3FF;
    }
    if (s >= 0x2D5) {
        ang = 0x400 - D_800874C0[c];
    } else {
        ang = D_800874C0[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return (s16)(0x1000 - ang);
}

s32 func_8002A35C(Unk8002A35C *a, Unk8002A35C *b);
s32 func_80028B04(Unk8002A35C *a, Unk8002A35C *b);
extern Unk8002A35C D_800A2A10;

void func_80028E14(Unk8002A35C *from, Unk8002A35C *to, Unk8002A35C *out) {
    Unk8002A35C d;

    out->y = -func_80028B04(from, to);
    d.z = func_8002A35C(from, to);
    d.x = to->y - from->y;
    out->x = func_80028B04(&D_800A2A10, &d) - 0x800;
    out->z = 0;
}

extern s32 SquareRoot0(s32 a);

s32 func_80028E94(Vec32 *a, Vec32 *b) {
    s32 dx = a->vx - b->vx;
    s32 dz;
    s32 sum;

    dx = (dx < 0) ? -dx : dx;
    sum = dx * dx;
    dz = a->vz - b->vz;
    dz = (dz < 0) ? -dz : dz;
    return SquareRoot0(sum + dz * dz);
}

typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
} Vec16;

extern s16 func_80028C78(Vec32 *from, Vec32 *to);
extern Vec32 D_8007C3BC;

void func_80028F00(Vec32 *from, Vec32 *to, Vec16 *angle) {
    Vec32 d;

    angle->vy = -func_80028C78(from, to);
    d.vz = func_80028E94(from, to);
    d.vx = to->vy - from->vy;
    angle->vx = func_80028C78(&D_8007C3BC, &d) - 0x800;
    angle->vz = 0;
}

extern s32 RotNclip4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *otz, s32 *flag);
extern s32 RotNclip3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *otz, s32 *flag);
extern s32 RotTransPers4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *flag);
extern s32 RotTransPers3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *flag);
extern s32 func_800292FC(void);
extern s32 func_800293A4(void);
extern s32 D_800A2EFC;
extern s32 D_800A326C;
extern s32 D_800A3394;
extern void *D_800A3154;
extern void AddPrim(void *ot, void *p);

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    u16 uv0;
    u16 clut;
    s32 xy1;
    u32 uv1;
    s32 xy2;
    u16 uv2;
    u16 pad;
} Unk8002DB90_Prim;

typedef struct {
    SVECTOR *v[4];
    u16 tex;
    u8 unk12;
    s8 clut;
} Unk8002DB90_Face;

extern Unk8002CE64_Prim *D_800A31C4;

void func_80028F80(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    D_800A326C = func_800293A4();
    if (D_800A326C < 0x9FF) {
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 10);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        prim->clut = tex[f->clut + 14];
        setlen(prim, 9);
        setcode(prim, 0x2F);
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

extern MATRIX D_801FB868;
extern MATRIX *MulMatrix2(MATRIX *m0, MATRIX *m1);
extern Vec32 D_801C0954;
extern Vec32 D_801D2058;
extern Vec32 D_800A7FD4;
extern s32 D_801D70F0[];
extern s32 D_801D723C[];

typedef struct {
    u8 pad0[0x12];
    u16 flags;
} Unk80032344_Face;

extern void (*D_8007FF9C[])(Unk80032344_Face *f);

s16 func_800290D4(s16 idx, s16 mode) {
    SVECTOR unused;
    SVECTOR rot;
    s16 models[7] = { 0, 0x43, 0x47, 0x46, 0x49, 0x48, 0x45 };
    Unk80032344_Face *f;

    if (idx <= 0) {
        return 0;
    }
    switch (idx) {
    case 1:
    case 3:
        func_80028F00(&D_801C0954, &D_801D2058, (Vec16 *)&rot);
        break;
    case 2:
    case 4:
    case 5:
    case 6:
        func_80028F00(&D_800A7FD4, &D_801C0954, (Vec16 *)&rot);
        break;
    }
    rot.vy += D_800A2FC4.vy;
    func_80023660(&rot, &D_801FB868);
    MulMatrix2(&D_801C0B64, &D_801FB868);
    SetRotMatrix(&D_801FB868);
    func_80070C9C(&D_801FB868, (VECTOR *)&D_801C0954);
    SetTransMatrix(&D_801FB868);
    f = (Unk80032344_Face *)(D_801D70F0[models[idx]] + 8);
    do {
        D_8007FF9C[f->flags & 0x1F](f);
    } while (!((f++)->flags & 0x80));
    if (mode != 0) {
        f = (Unk80032344_Face *)(D_801D723C[idx] + 8);
        mode = 0;
        do {
            func_80028F80((Unk8002DB90_Face *)f);
        } while (!((f++)->flags & 0x80));
    }
    return mode;
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A8CC);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800292FC);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80029334);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002936C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800293A4);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800293F0);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002943C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80029488);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800295B8);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800296F8);

void func_80029728(s16 ofsx, s16 ofsy, u8 isbg, s16 x, s16 y, s16 w, s16 h) {
    DR_ENV *prim = D_800A3374;
    DRAWENV env;

    env.clip.x = x;
    env.clip.y = y;
    env.clip.w = w;
    env.clip.h = h;
    env.ofs[0] = ofsx;
    env.ofs[1] = ofsy;
    env.tw.x = 0;
    env.tw.y = 0;
    env.tw.w = 255;
    env.tw.h = 255;
    env.dtd = 255;
    env.dfe = 255;
    env.isbg = isbg;
    env.r0 = 0;
    env.g0 = 0;
    env.b0 = 0;
    SetDrawEnv(prim, &env);
    addPrim(D_800A32E4 + 1, prim);
    prim++;
    D_800A3374 = prim;
}

extern VECTOR D_8007A8CC;
extern u16 D_800A2A1C;
extern s16 D_800A2A1E;
extern SVECTOR D_800A2FC4;
extern SVECTOR D_800A349C;
extern MATRIX D_801C0B64;
extern VECTOR D_801C1EC4;
extern MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX *func_80070C9C(MATRIX *m, VECTOR *v);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);

void func_800297F8(SVECTOR *pos) {
    SVECTOR rot;
    VECTOR scale = D_8007A8CC;

    if (D_800A2A1E == 0) {
        rot.vx = 0x400;
        rot.vz = 0;
        rot.vy = D_800A2FC4.vy;
        D_800A349C.vx = -pos->vx;
        D_800A349C.vy = 0;
        D_800A349C.vz = -pos->vz;
    } else {
        rot.vx = 0x400;
        rot.vy = 0x800;
        rot.vz = 0;
        D_800A349C.vx = 0;
        D_800A349C.vy = 0;
        D_800A349C.vz = 0;
    }
    func_8002384C(&rot, &D_801C0B64);
    ScaleMatrix(&D_801C0B64, &scale);
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    D_801C1EC4.vz = (s16)D_800A2A1C;
    func_80070C9C(&D_801C0B64, &D_801C1EC4);
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80029944);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
    } unk24[64];
    struct {
        u8 unk0;
        u8 unk1;
        u8 unk2;
        u8 unk3;
    } unk224[64];
} Unk8002A194_Data;

extern void func_80029944();
extern Unk8003BA6C_Task *D_801F7D48;
extern s16 D_800A2A1E;
extern s16 D_800A327C;

void func_8002A194(void) {
    Unk8002A194_Data *data;
    s16 i;

    D_801F7D48 = func_80021264(func_80029944, 1, 0x324);
    if (D_801F7D48 != NULL) {
        data = (Unk8002A194_Data *)D_801F7D48->data;
        data->unk6 = data->unkE = data->unk16 = data->unk1E = data->unk0 = 0;
        data->unk4 = data->unk8 = data->unk10 = data->unk14 = -0x4100;
        data->unkC = data->unk18 = data->unk1C = data->unk20 = 0x3D00;
        for (i = 0; i < 64; i++) {
            data->unk24[i].unk0 = 0;
            data->unk24[i].unk2 = 0;
            data->unk24[i].unk4 = 0;
            data->unk24[i].unk6 = 0;
            data->unk224[i].unk0 = 0;
            data->unk224[i].unk1 = 0;
            data->unk224[i].unk2 = 0;
        }
        D_800A2A1E = 0;
        D_800A327C = -1;
    }
}

extern u8 D_8007FF40[][4];

void func_8002A270(Unk8002A35C *pos, s16 color) {
    Unk8002A194_Data *data = (Unk8002A194_Data *)D_801F7D48->data;

    if (data->unk0 < 64) {
        data->unk24[data->unk0].unk0 = pos->x;
        data->unk24[data->unk0].unk2 = pos->y;
        data->unk24[data->unk0].unk4 = pos->z;
        data->unk224[data->unk0].unk0 = D_8007FF40[color][0];
        data->unk224[data->unk0].unk1 = D_8007FF40[color][1];
        data->unk224[data->unk0].unk2 = D_8007FF40[color][2];
        data->unk224[data->unk0].unk3 = D_8007FF40[color][3];
        data->unk0++;
    }
}

s32 func_8002A35C(Unk8002A35C *a, Unk8002A35C *b) {
    s16 dx = a->x - b->x;
    s16 dz = a->z - b->z;

    return SquareRoot0(dx * dx + dz * dz);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002A3C4);

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u16 uv0, clut;
    s16 x1, y1;
    u16 uv1, tpage;
    s16 x2, y2;
    u16 uv2, pad1;
    s16 x3, y3;
    u16 uv3, pad2;
} Unk8002B4C0_Prim;

typedef struct {
    Unk8002A35C *pos;
    u8 pad4[8];
    s16 timer;
    u8 padE[2];
    u8 r, g, b;
    u8 pad13;
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    s16 size;
    s16 idx;
} Unk8002B4C0;

extern Unk8002A35C D_8007C4FC[];
extern void func_8002A7BC(void);

void func_8002A40C(void) {
    Unk8002B4C0 *obj = (Unk8002B4C0 *)D_800A317C->vals;
    Unk8002B4C0_Prim *prim = D_800A3374;
    Unk8002A35C *pos = obj->pos;
    SVECTOR v;
    u16 *tex;
    s16 found;
    s16 i;

    if (obj->timer == 0) {
        found = 0;
        for (i = 0; i < 4; i++) {
            if (D_8007C4FC[i].x == 0) {
                found = 1;
                obj->idx = i;
                D_8007C4FC[i].x = found;
                break;
            }
        }
        if (!found) {
            func_80021554();
            return;
        }
        SetRotMatrix(&D_801C0B64);
        SetTransMatrix(&D_801C0B64);
        v.vx = pos->x;
        v.vy = pos->y + 0x300;
        v.vz = pos->z;
        RotTransPers(&v, (s32 *)&obj->x, &D_800A2EFC, &D_800A3394);
        obj->r = 0xA0;
        obj->g = 0xA0;
        obj->b = 0xFF;
        obj->dx = (D_8007C4FC[obj->idx].y - obj->x) >> 3;
        obj->dy = (D_8007C4FC[obj->idx].z - obj->y) >> 3;
    }
    prim->x0 = obj->x - obj->size;
    prim->y0 = obj->y - obj->size;
    prim->x1 = obj->x + obj->size;
    prim->y1 = obj->y - obj->size;
    prim->x2 = obj->x - obj->size;
    prim->y2 = obj->y + obj->size;
    prim->x3 = obj->x + obj->size;
    prim->y3 = obj->y + obj->size;
    tex = (u16 *)D_800A3154;
    prim->uv0 = tex[0x84];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 0x86);
    prim->uv2 = tex[0x88];
    prim->uv3 = tex[0x8A];
    prim->clut = tex[0x95];
    prim->r0 = obj->r;
    prim->g0 = obj->g;
    prim->b0 = obj->b;
    setlen(prim, 9);
    setcode(prim, 0x2F);
    addPrim(D_800A32E4, prim);
    D_800A3374 = prim + 1;
    obj->x += obj->dx;
    obj->y += obj->dy;
    obj->size += 2;
    obj->timer += 2;
    if (obj->timer == 0x10) {
        obj->timer = 0;
        obj->x = D_8007C4FC[obj->idx].y;
        obj->y = D_8007C4FC[obj->idx].z;
        D_800A317C->func = func_8002A7BC;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002A7BC);

void func_8002B4C0(void) {
    Unk8002B4C0 *obj = (Unk8002B4C0 *)D_800A317C->vals;
    Unk8002B4C0_Prim *prim = D_800A3374;
    u16 *tex;

    prim->x0 = prim->x2 = obj->x - obj->size;
    prim->y0 = prim->y1 = obj->y - obj->size;
    prim->x1 = prim->x3 = obj->x + obj->size;
    prim->y2 = prim->y3 = obj->y + obj->size;
    tex = (u16 *)D_800A3154;
    prim->uv0 = tex[0x84];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 0x86);
    prim->uv2 = tex[0x88];
    prim->uv3 = tex[0x8A];
    prim->clut = tex[0x95];
    prim->r0 = obj->r;
    prim->g0 = obj->g;
    prim->b0 = obj->b;
    setlen(prim, 9);
    setcode(prim, 0x2E);
    addPrim(D_800A32E4, prim);
    D_800A3374 = prim + 1;
    obj->r -= 0x10;
    obj->g -= 0x10;
    obj->b -= 0x10;
    if (++obj->timer == 10) {
        D_8007C4FC[obj->idx].x = 0;
        func_80021554();
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002B674);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002BC04);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002C1D4);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002C758);

void func_8002CD18(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A31C4;
    u16 *tex;
    u32 *ot;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800293A4();
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        prim->clut = tex[f->clut + 14];
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        D_800A31C4++;
    }
}

void func_8002CE64(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A31C4;
    u16 *tex;
    u32 *ot;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800293A4();
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        prim->uv3 = tex[4];
        prim->uv2 = tex[6];
        prim->clut = tex[f->clut + 14];
        prim->tpage = tex[3];
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        D_800A31C4++;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002CFBC);

void func_8002D46C(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800292FC();
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv0 = tex[0];
        prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[f->clut + 14];
        setlen(prim, 7);
        setcode(prim, 0x27);
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002D5B4);

void func_8002DA54(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;

    D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800292FC();
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv0 = tex[0];
        prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[f->clut + 14];
        setlen(prim, 7);
        setcode(prim, 0x27);
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

void func_8002DB90(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;

    D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800292FC();
        tex = (u16 *)((u8 *)D_800A3154 + f->tex);
        prim->uv0 = tex[0];
        prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[f->clut + 14];
        setlen(prim, 7);
        setcode(prim, 0x25);
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

extern s16 D_800A2A22;
extern Unk8002CE64_Prim *D_800A30A4;

void func_8002DCCC(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

void func_8002DE8C(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 9);
            setcode(prim, 0x2E);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002E050(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

void func_8002E204(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 9);
            setcode(prim, 0x2E);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002E3BC(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

void func_8002E570(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv1 = tex[0];
            prim->uv0 = tex[2];
            prim->uv3 = tex[4];
            prim->uv2 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->tpage = tex[3];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

void func_8002E730(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800292FC();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 7);
            setcode(prim, 0x24);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002E8D4(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800292FC();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 7);
            setcode(prim, 0x26);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002EA78(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800292FC();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 7);
            setcode(prim, 0x24);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002EC10(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800292FC();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 7);
            setcode(prim, 0x26);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

void func_8002EDA8(Unk8002DB90_Face *f) {
    Unk8002DB90_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800292FC();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 7);
            setcode(prim, 0x24);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002EF40);

void func_8002F4F4(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv1 = tex[0];
            prim->uv0 = tex[2];
            prim->uv3 = tex[4];
            prim->uv2 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->tpage = tex[3];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

extern void SetSemiTrans(void *p, s32 abe);

void func_8002F6C0(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0 && !(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv1 = tex[0];
            prim->uv0 = tex[2];
            prim->uv3 = tex[4];
            prim->uv2 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->tpage = tex[3];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            SetSemiTrans(prim, 1);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

extern s16 D_800854C0[];

void func_8002F894(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 z;
    s16 c;
    s16 a;
    s32 r;
    s32 dx;
    s32 dz;
    SVECTOR p0;
    SVECTOR p1;
    SVECTOR p2;
    SVECTOR p3;
    SVECTOR unused;

    a = -func_80028B04((Unk8002A35C *)&D_800A3194, (Unk8002A35C *)f->v[0]);
    r = f->v[1]->vx;
    dx = (D_800854C0[(a + 0x400) & 0xFFF] * r) >> 12;
    dz = (D_800854C0[a & 0xFFF] * r) >> 12;
    p0.vx = p3.vx = f->v[0]->vx - dx;
    p0.vz = p3.vz = f->v[0]->vz + dz;
    p1.vx = p2.vx = f->v[0]->vx + dx;
    p1.vz = p2.vz = f->v[0]->vz - dz;
    p0.vy = p1.vy = f->v[2]->vy;
    p2.vy = p3.vy = f->v[0]->vy;
    D_800A326C = RotTransPers4(&p0, &p1, &p2, &p3, &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = z = func_800293A4();
        if (z > D_800A2A22) {
            c = (0x100 - (z - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8002FB4C);

void func_8002FEB8(void) {
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk80030090Pt;

typedef struct {
    Unk80030090Pt *p[3];
} Unk80030090;

extern struct Task *D_801F7D44;
extern struct Task *volatile D_801F7D50;

typedef struct {
    Unk80030090Pt *p[4];
} Unk8002FEC0;

extern void func_8002B674(Unk8002FEC0 *);
extern void func_8002EF40(Unk8002FEC0 *);

void func_8002FEC0(Unk8002FEC0 *quad) {
    Unk80030090Pt *ref;
    s16 max;

    if (D_801F7D50 == NULL) {
        ref = (Unk80030090Pt *)D_801F7D44->vals;
    } else {
        ref = (Unk80030090Pt *)D_801F7D50->vals;
    }
    max = quad->p[0]->unk2;
    if (max < quad->p[1]->unk2) {
        max = quad->p[1]->unk2;
    }
    if (max < quad->p[2]->unk2) {
        max = quad->p[2]->unk2;
    }
    if (max < quad->p[3]->unk2) {
        max = quad->p[3]->unk2;
    }
    if (max - ref->unk2 > 0x200) {
        func_8002B674(quad);
    } else {
        func_8002E3BC((Unk8002DB90_Face *)quad);
    }
}

void func_8002FFA8(Unk8002FEC0 *quad) {
    Unk80030090Pt *ref;
    s16 max;

    if (D_801F7D50 == NULL) {
        ref = (Unk80030090Pt *)D_801F7D44->vals;
    } else {
        ref = (Unk80030090Pt *)D_801F7D50->vals;
    }
    max = quad->p[0]->unk2;
    if (max < quad->p[1]->unk2) {
        max = quad->p[1]->unk2;
    }
    if (max < quad->p[2]->unk2) {
        max = quad->p[2]->unk2;
    }
    if (max < quad->p[3]->unk2) {
        max = quad->p[3]->unk2;
    }
    if (max - ref->unk2 > 0x200) {
        func_8002EF40(quad);
    } else {
        func_8002E570((Unk8002DB90_Face *)quad);
    }
}

extern void func_8002CFBC(Unk80030090 *);

void func_80030090(Unk80030090 *tri) {
    Unk80030090Pt *ref;
    s16 max;

    if (D_801F7D50 == NULL) {
        ref = (Unk80030090Pt *)D_801F7D44->vals;
    } else {
        ref = (Unk80030090Pt *)D_801F7D50->vals;
    }
    max = tri->p[0]->unk2;
    if (max < tri->p[1]->unk2) {
        max = tri->p[1]->unk2;
    }
    if (max < tri->p[2]->unk2) {
        max = tri->p[2]->unk2;
    }
    if (max - ref->unk2 > 0x200) {
        func_8002CFBC(tri);
    } else {
        func_8002EDA8((Unk8002DB90_Face *)tri);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80030154);

extern s16 func_800293F0(void);

void func_8003072C(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A3374;
    u16 *tex;
    u32 *ot;
    s32 mid;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800293A4();
        mid = (func_800293F0() + D_800A326C) >> 1;
        if (D_800A326C > D_800A2A22) {
            c = (0x100 - (D_800A326C - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            setlen(prim, 9);
            setcode(prim, 0x2E);
            ot = D_800A32E4 + mid;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800308F8);

void func_80030EA4(Unk8002DB90_Face *f) {
    Unk8002CE64_Prim *prim = D_800A30A4;
    u16 *tex;
    u32 *ot;
    s32 mid;
    s16 c;

    D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    if (!(D_800A3394 & 0xFFFFE000)) {
        D_800A326C = func_800293A4();
        mid = (func_800293F0() + D_800A326C) >> 1;
        if (D_800A326C > D_800A2A22) {
            c = (0x100 - (D_800A326C - D_800A2A22)) >> 1;
            if (c > 0x80) {
                c = 0x80;
            }
        } else {
            c = 0x80;
        }
        if (c > 0) {
            tex = (u16 *)((u8 *)D_800A3154 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
            prim->uv2 = tex[4];
            prim->uv3 = tex[6];
            prim->clut = tex[f->clut + 14];
            prim->r0 = c;
            prim->g0 = c;
            prim->b0 = c;
            ot = D_800A32E4 + mid + 20;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            D_800A30A4++;
        }
    }
}


typedef struct {
    s16 v[3];
} Unk800A2A80;

extern Unk800A2A80 D_800A2A80;
extern volatile u16 D_800A3144[];
extern volatile u16 D_800A32AC[];
extern volatile u16 D_800A3146;
extern volatile u16 D_800A32AE;
extern void func_800207DC();
extern void func_8002076C(void);
extern u16 func_8005AB1C();

void func_80031070(void) {
    s16 config = 0;
    Unk800A2A80 unused = D_800A2A80;

    if (D_800A2F0C == 11) {
        config = D_800A350C->players[D_800A350C->unk1780].unk5;
    }
    func_800207DC();
    func_8002076C();
    D_800A32AC[0] = func_8005AB1C((s16)D_800A3144[0], config);
    D_800A343C[0] = func_8005AB1C((s16)D_800A343C[0], config);
    D_800A32AE = D_800A3146;
    if (D_800A343C[0] & 0x100) {
        D_800A2A1C += 0x2000;
    }
    if ((s16)D_800A2A1C < 0) {
        D_800A2A1C = 0x1EFF;
    }
}

typedef struct {
    Unk8002A35C pos;
    u8 pad6[2];
    Unk8002A35C prev;
    u8 padE[4];
    s16 unk12;
    u8 pad14[0xE];
    s16 unk22;
    u8 pad24[0x18];
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    u8 pad48[4];
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 pad52[0x12];
    Anim anim;
    u8 pad84[0x50];
    s16 unkD4;
} Unk80045EF4;

extern void func_80039518(Unk80045EF4 *obj);

void func_800311AC(Unk80045EF4 *obj) {
    SVECTOR unused[2];

    func_80039518(obj);
    obj->pos.x += obj->unk3C;
    obj->pos.y += obj->unk40;
    obj->pos.z += obj->unk44;
}

typedef struct {
    s16 x;
    s16 pad2;
    s16 z;
    char pad6[0xBE];
    s16 cell;
} Unk80031200;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} GridCell;

typedef struct {
    s16 unk0;
    u16 x;
    u16 z;
    u16 w;
    u8 pad8[0x14];
    GridCell *cells;
} Grid;

extern Grid D_800A79F0;

void func_80031200(Unk80031200 *p) {
    s16 x = p->x + (D_800A79F0.x << 9);
    s16 z = p->z + (D_800A79F0.z << 9);

    p->cell = x / 1024 + (z / 1024) * 32;
}

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0xC];
    u16 unk12;
} Unk80031264_Target;

extern s32 D_800A2FBC;
extern Unk8002A35C *D_800A3534;

void func_80031264(Unk8002A35C *from) {
    Unk80031264_Target *target;
    s32 dist;
    s32 angle;

    if (D_801F7D50 != NULL) {
        target = (Unk80031264_Target *)D_801F7D50->vals;
        if (from != &target->pos) {
            dist = func_8002A35C(from, &target->pos);
            if (dist < D_800A2FBC) {
                angle = (func_80028B04(from, &target->pos) - target->unk12) << 20 >> 20;
                if (angle < 0) {
                    angle = -angle;
                }
                if (angle < 0x60) {
                    D_800A2FBC = dist;
                    D_800A3534 = from;
                }
            }
        }
    }
}

typedef struct {
    s16 x, y, z;
    char pad6[4];
    s16 fA;
    char padC[0xC];
    s32 f18;
    s16 f1C;
    char pad1E[2];
    s32 f20;
    char pad24[6];
    short f2A;
    short f2C;
} Obj;

typedef struct {
    SVECTOR rot;
    u8 pad8[0xA];
    s16 unk12;
    u8 pad14[4];
} Unk80045164_Model;

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0xA];
    Unk80045164_Model model;
    s16 unk28;
    u8 pad2A[2];
    s16 state;
    u8 pad2E[0x34];
    s16 unk62;
    Anim anim;
    u8 pad84[0x10];
    Obj unk94;
    u8 padC4[6];
    u8 unkCA;
    u8 padCB[9];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
    u8 padDC[0xC];
    s16 unkE8;
    s16 unkEA;
    s16 unkEC;
    s16 unkEE;
    s16 unkF0;
    s16 unkF2;
    s16 unkF4;
    u8 padF6[0x20];
    u8 unk116;
    u8 pad117[0xD];
    struct Task *unk124;
    u8 pad128[0x2C];
    s16 unk154;
    s16 unk156;
    s16 unk158;
    u8 pad15A[2];
    s16 unk15C;
    u8 pad15E[2];
    s16 unk160;
    s16 unk162;
} Unk80045164;

extern u8 *D_800A2FAC;
extern s16 D_801C1F00;
extern s16 D_801C1EDA;
extern s16 func_8002501C(void *obj, void *model, s16 fade, s32 arg3, Anim *anim);
extern void AddPrims(void *ot, void *p0, void *p1);
extern void func_80031ED0(SVECTOR *pos, SVECTOR *rot, s16 color);
extern s16 func_800290D4(s16 a, s16 b);
extern void func_800430AC(Obj *o, s16);

void func_80031320(Unk80045164 *obj) {
    SVECTOR unused[2];
    s16 n;
    u32 *ot;

    if (obj->state == 8 || obj->state == 4) {
        n = func_8002501C(obj, &obj->model, 0xFFF, 0, &obj->anim);
    } else {
        n = func_8002501C(obj, &obj->model, 0xFFF, 1, &obj->anim);
    }
    if (D_800A326C > 8 && n >= 8) {
        if (D_801C1F00 != 0) {
            func_80031ED0((SVECTOR *)obj, (SVECTOR *)&obj->model, obj->unk28);
        } else {
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrims(ot, D_800A2FAC + 0x14, D_800A2FAC);
            }
        }
        obj->unk156 = func_800290D4(obj->unkF4, obj->unk156);
        func_80031264(&obj->pos);
        if (D_801C1EDA != 0) {
            func_800430AC(&obj->unk94, 0);
        }
        obj->unk154 = 0;
    } else {
        obj->unk154 = 1;
    }
}

typedef struct {
    s16 x, y, z;
    u8 pad6[4];
    s16 unkA;
    u8 padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[2];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 pad24[4];
    s16 unk28;
    u8 pad2A[2];
    s16 hit;
    u8 pad2E[6];
    s16 unk34;
    u8 pad36[2];
} Unk800436E4_Probe;

void func_80041C48(Unk800436E4_Probe *probe);
void func_80042570(Unk800436E4_Probe *probe);

typedef struct {
    s16 x, y, z;
    u8 pad6[0x8E];
    Unk800436E4_Probe probe;
    u8 padCC[0x88];
    s16 unk154;
} Unk8003146C;

void func_80041104();

void func_8003146C(Unk8003146C *obj) {
    obj->probe.unk34 = 0;
    obj->probe.unk28 = 0;
    if (obj->unk154 == 0) {
        func_80042570(&obj->probe);
    }
    func_80041C48(&obj->probe);
    if (obj->probe.hit != 0) {
        obj->x += obj->probe.unk10;
        obj->z += obj->probe.unk14;
    }
    obj->probe.hit = 0;
    obj->probe.x = obj->x;
    obj->probe.y = obj->y;
    obj->probe.z = obj->z;
    func_80041104(obj);
}

typedef struct {
    s16 x, y, z;
    u8 pad6[0x4A];
    s16 unk50;
    u8 pad52[0x42];
    Unk800436E4_Probe probe;
} Unk80031500;

void func_80031500(Unk80031500 *obj) {
    obj->probe.unk34 = 0;
    obj->probe.unk28 = 0;
    obj->probe.hit = 0;
    func_80042570(&obj->probe);
    func_80041C48(&obj->probe);
    if (obj->probe.hit != 0) {
        obj->probe.hit = 0;
        obj->x += obj->probe.unk10;
        obj->z += obj->probe.unk14;
        obj->probe.unk10 = 0;
        obj->probe.unk12 = 0;
        obj->probe.unk14 = 0;
        obj->unk50 >>= 1;
    }
    obj->probe.x = obj->x;
    obj->probe.y = obj->y;
    obj->probe.z = obj->z;
}

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x1C];
    s16 unk30;
    u8 pad32[6];
    void *unk38;
    u8 pad3C[0x10];
    s16 unk4C;
    u8 pad4E[2];
    s16 unk50;
    u8 pad52[0x7A];
    s16 unkCC;
    s16 unkCE;
} Unk800315B0;

s32 func_800437C8(s32 value, s32 target, s32 step);

void func_800315B0(Unk800315B0 *obj) {
    if (obj->unk30 == 0) {
        if (obj->unkCE < 0x20) {
            obj->unkCE = func_800437C8(obj->unkCE, 0x20, 8);
        } else {
            obj->unkCE = func_800437C8(obj->unkCE, 0x40, 2);
        }
    }
}

void func_80031614(Unk800315B0 *obj) {
    if (obj->unk30 == 0) {
        if (obj->unkCE > -0x20) {
            obj->unkCE = func_800437C8(obj->unkCE, -0x20, 8);
        } else {
            obj->unkCE = func_800437C8(obj->unkCE, -0x40, 2);
        }
    }
}

void func_80031678(Unk800315B0 *obj) {
    if (obj->unk30 == 0) {
        obj->unk50 = func_800437C8(obj->unk50, 0, 0x30);
        obj->unk4C = func_800437C8(obj->unk4C, 0, 0x80);
    }
}

extern u8 D_8008011C[];

void func_800316CC(Unk800315B0 *obj) {
    obj->unk38 = D_8008011C;
    if (obj->unk30 == 0) {
        obj->unk50 = func_800437C8(obj->unk50, 0, 0x30);
        obj->unk4C = func_800437C8(obj->unk4C, 0, 0x80);
    }
}

void func_80031728(Unk800315B0 *obj) {
    obj->unk50 = func_800437C8(obj->unk50, -0x40, 0x20);
}

void func_8003175C(Unk800315B0 *obj) {
    if (obj->unk50 < 0x40) {
        obj->unk50 = func_800437C8(obj->unk50, 0x40, 0x18);
    } else {
        obj->unk50 = func_800437C8(obj->unk50, 0x60, 2);
    }
}

extern s16 func_80043814(s16 from, s16 to, s32 step);

void func_800317B0(Unk800315B0 *obj) {
    obj->unk12 = func_80043814(obj->unk12, obj->unkCC, 0x80);
    if (obj->unk12 == obj->unkCC) {
        obj->unk38 = D_8008011C;
    }
}

typedef struct {
    s16 x, y, z;
    u8 pad6[0xC];
    s16 unk12;
    u8 pad14[0x1A];
    s16 unk2E;
    s16 unk30;
    u8 pad32[0x32];
    Anim anim;
    u8 pad84[0x42];
    s16 unkC6;
    u8 padC8[6];
    s16 unkCE;
    u8 padD0[0x24];
    s16 unkF4;
} Unk80031AB8;

extern u16 D_8007C42C[];
extern u16 D_800A2A24;

void func_80031804(s16 i) {
    D_8007C42C[i] = D_800A2A24;
}

typedef struct {
    u8 pad0[0xF0];
    s16 unkF0;
    u8 padF2[2];
    s16 unkF4;
    s16 unkF6;
    u8 padF8[0x5E];
    s16 unk156;
} Unk80031828;

extern volatile u16 D_800A32AC[];
extern void func_80051778(s16 id, s16 flag);

void func_80031828(Unk80031828 *p) {
    u16 pressed = D_800A32AC[0];
    u16 held = D_800A343C[0];

    if (pressed & 0x1000) {
        func_80031804(0xB);
    }
    if (pressed & 0x20) {
        func_80031804(9);
    }
    if (pressed & 0x1000) {
        func_80031804(1);
    }
    if (pressed & 0x8000) {
        func_80031804(3);
    }
    if (pressed & 0x2000) {
        func_80031804(4);
    }
    if (pressed & 0x4000) {
        func_80031804(0xF);
    }
    if (pressed & 0x2000) {
        func_80031804(0x11);
    }
    if (pressed & 0x8000) {
        func_80031804(0x10);
    }
    switch (p->unkF4) {
    case 1:
        if ((held & 0x80) && p->unkF0 >= 3) {
            func_80031804(5);
            p->unkF0 = 0;
            p->unk156 = -1;
        }
        break;
    case 2:
    case 5:
        if ((pressed & 0x80) && p->unkF0 >= 0x1F) {
            func_80031804(5);
            p->unkF0 = 0;
            p->unkF6--;
        }
        break;
    case 3:
        if ((pressed & 0x80) && p->unkF0 >= 3) {
            func_80031804(5);
            p->unkF0 = 0;
            p->unkF6--;
        }
        break;
    case 4:
    case 6:
        if ((pressed & 0x80) && p->unkF0 >= 6) {
            func_80031804(5);
            p->unkF0 = 0;
            p->unkF6--;
        }
        break;
    }
    if (p->unkF6 == 0) {
        if (p->unkF4 != 1) {
            func_80051778(1, -1);
        }
        p->unkF4 = 1;
    }
    if (++p->unkF0 > 0x78) {
        p->unkF0 = 0x78;
    }
    if (pressed & 0x10) {
        func_80031804(6);
    }
    func_80031804(0xA);
}

void func_80031A5C(Unk80031AB8 *obj) {
    u16 *e = (u16 *)D_800A353C[obj->anim.id].p;

    if (obj->unk30 == 0) {
        obj->unk2E = 200;
        func_80024DA8(&obj->anim, 0x12, e[10], 0xB8, 1);
    }
}

extern u16 D_8007C432;
extern u16 D_8007C434;
extern u16 D_800A2A24;
extern const s16 D_8007C560[];
extern s16 func_80023E80(void *obj, s32 *a, s32 *b);

void func_80031AB8(Unk80031AB8 *obj) {
    u16 *e = (u16 *)D_800A353C[obj->anim.id].p;
    s32 tmp;
    s16 floor;

    if (D_8007C432 != D_800A2A24 && D_8007C434 != D_800A2A24) {
        obj->unkCE = func_800437C8(obj->unkCE, 0, 0x10);
    }
    obj->unk12 += obj->unkCE;
    obj->y += obj->unk2E;
    if (obj->unk30 != 0) {
        if (obj->anim.time < e[10]) {
            obj->anim.unk6 = 0xB8;
        } else {
            obj->anim.unk6 = 0x2E;
        }
        if (obj->anim.time >= e[11]) {
            obj->anim.time = e[11];
        }
    }
    obj->unk2E = func_800437C8(obj->unk2E, -0x1F4, 0x18);
    floor = obj->unkC6;
    if (floor == -1) {
        floor = func_80023E80(obj, &tmp, &tmp);
    }
    if (floor >= obj->y) {
        if (obj->unk30 != 0) {
            func_80024DA8(&obj->anim, D_8007C560[obj->unkF4], 0, 0xA4, 4);
        }
        obj->unk2E = 0;
        obj->y = floor;
        obj->unk30 = 0;
    } else if (obj->y - floor > 0x100) {
        obj->unk30++;
    }
    obj->unkC6 = -1;
}

typedef struct {
    SVECTOR v[27];
} AnimFrame;

typedef struct {
    s32 len;
    s32 count;
    u32 step;
    s32 scale;
    s32 unk10;
    s32 unk14;
    AnimFrame frames[1];
} AnimInfo;

s16 func_80031C58(Anim *anim) {
    AnimInfo *info = (AnimInfo *)D_800A353C[anim->id].p;
    s16 t;
    s16 len;
    s16 frame;
    s16 from;
    s16 to;
    s16 a;
    s16 wrap;

    t = ABS((s32)(anim->time % info->len));
    frame = t / info->step;
    D_800A2EFC = (t % info->step) * info->scale >> 12;
    if (frame == 0) {
        from = 0;
        to = info->frames[0].v[26].vz;
    } else {
        from = info->frames[frame - 1].v[26].vz;
        to = info->frames[frame].v[26].vz;
    }
    a = func_800296F8(from, to, D_800A2EFC);
    t = anim->time + anim->unk6;
    len = info->len;
    if (t > len) {
        wrap = info->frames[info->count - 1].v[26].vz;
        t = t - len;
    } else if (t < 0) {
        wrap = -info->frames[info->count - 1].v[26].vz;
        t = len + t;
    } else {
        wrap = 0;
    }
    frame = t / info->step;
    D_800A2EFC = (t % info->step) * info->scale >> 12;
    if (frame == 0) {
        from = 0;
        to = info->frames[0].v[26].vz;
    } else {
        from = info->frames[frame - 1].v[26].vz;
        to = info->frames[frame].v[26].vz;
    }
    return a - (wrap + func_800296F8(from, to, D_800A2EFC));
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
} LINE_F2;

extern SVECTOR D_800A3194;
extern SVECTOR D_800A349C;
extern MATRIX D_801C0B64;
extern VECTOR D_801C1EC4;
extern MATRIX D_801FB868;
extern void PushMatrix(void);
extern void PopMatrix(void);
extern void LoadAverageShort12(SVECTOR *v0, SVECTOR *v1, s32 p0, s32 p1, SVECTOR *v2);
extern MATRIX *RotMatrix(SVECTOR *r, MATRIX *m);
extern MATRIX *MulMatrix2(MATRIX *m0, MATRIX *m1);
extern s32 RotTransPers(SVECTOR *v0, s32 *sxy, s32 *p, s32 *flag);
extern void SetLineF2(LINE_F2 *p);

void func_80031ED0(SVECTOR *pos, SVECTOR *rot, s16 color) {
    LINE_F2 *line = D_800A3374;
    u32 *ot;
    s16 i;
    s16 c;
    u8 unused[0x48];

    PushMatrix();
    rot->vy = -rot->vy + 0x800;
    LoadAverageShort12(pos, &D_800A3194, 0x1000, -0x1000, &D_800A349C);
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    RotMatrix(rot, &D_801FB868);
    MulMatrix2(&D_801C0B64, &D_801FB868);
    SetRotMatrix(&D_801FB868);
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    rot->vy -= 0x800;
    rot->vy = -rot->vy;
    for (i = 0; i < 26; i += 2) {
        D_800A326C = RotTransPers((SVECTOR *)D_800A351C + i, (s32 *)&line->x0, &D_800A2EFC, &D_800A3394) >> 1;
        D_800A326C = ((RotTransPers((SVECTOR *)D_800A351C + (i + 1), (s32 *)&line->x1, &D_800A2EFC, &D_800A3394) >> 1) + D_800A326C) >> 1;
        if (D_800A326C > D_800A2A22) {
            c = (0x100 - (D_800A326C - D_800A2A22)) >> 1;
            if (c > 0x7F) {
                c = 0x7F;
            }
        } else {
            c = 0x7F;
        }
        if (c > 0) {
            c <<= 1;
            SetLineF2(line);
            switch (color) {
            case 0:
                line->r0 = c;
                line->g0 = c;
                line->b0 = c;
                break;
            case 4:
                line->r0 = 0;
                line->g0 = 0;
                line->b0 = c;
                break;
            case 20:
                line->r0 = c;
                line->g0 = c;
                line->b0 = 0;
                break;
            default:
                line->r0 = c;
                line->g0 = 0;
                line->b0 = 0;
                break;
            }
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, line++);
            }
        }
    }
    D_800A3374 = line;
    PopMatrix();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003219C);

typedef struct {
    SVECTOR pos;
    SVECTOR rot;
    VECTOR scale;
    u8 *data;
} Unk80032344;

extern s16 D_800A3224;
extern void (*D_8007FF9C[])(Unk80032344_Face *f);
extern void (*D_8008001C[])(Unk80032344_Face *f);
extern void func_80022D60(Unk80032344_Face *f);

s32 func_80032344(Unk80032344 *obj, s16 mode) {
    Unk80032344_Face *f = (Unk80032344_Face *)(obj->data + 8);
    s16 xy[2];

    PushMatrix();
    LoadAverageShort12(&obj->pos, &D_800A3194, 0x1000, -0x1000, &D_800A349C);
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    RotMatrix(&obj->rot, &D_801FB868);
    ScaleMatrix(&D_801FB868, &obj->scale);
    MulMatrix2(&D_801C0B64, &D_801FB868);
    SetRotMatrix(&D_801FB868);
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    if (mode != 2 || D_800A3224 == 0) {
        D_800A326C = RotTransPers((SVECTOR *)&D_800A2A10, (s32 *)xy, &D_800A2EFC, &D_800A3394) >> 1;
        if ((u32)(D_800A326C - 0x20) >= 0x960 || (u16)(xy[0] + 0x8C) >= 0x259 || (u16)(xy[1] + 0x50) >= 0x245) {
            PopMatrix();
            return 0;
        }
    }
    switch (mode) {
    case 0:
        do {
            D_8008001C[f->flags & 0x1F](f);
        } while (!((f++)->flags & 0x80));
        break;
    case 1:
        do {
            D_8007FF9C[f->flags & 0x1F](f);
        } while (!((f++)->flags & 0x80));
        break;
    case 2:
        do {
            func_80022D60(f);
        } while (!((f++)->flags & 0x80));
        break;
    }
    D_800A3224 = 0;
    PopMatrix();
    return -1;
}

typedef struct Unk800584A4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    s32 pad24;
    u16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 pad32[0x30];
    s16 unk62;
    u8 pad64[0x18];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    u8 pad82[4];
    s16 unk86;
    u8 pad88[0xC];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
    s16 unkA8;
    u8 padAA[8];
    u8 unkB2;
    u8 padB3;
} Unk800584A4;

extern Unk800584A4 *D_800A3564;

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9;
    s16 unkA;
} Unk800325DC_Self;

typedef struct {
    s16 unk0;
    s16 pad2;
    s32 unk4;
    s16 unk8;
    u8 padA[0x2A];
    s16 unk34;
} Unk800308F8;

extern void func_80030154(Unk800308F8 *p);
extern void func_80032A68(Unk800584A4 *obj);

void func_800325DC(void *arg0, void *arg1, Unk800325DC_Self *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];
    Unk800308F8 *part = (Unk800308F8 *)&obj->unk2C;
    Unk800308F8 *first = part;
    s16 limit;
    s16 hit;

    switch (obj->unk62) {
    case 0:
        limit = 1;
        break;
    case 1:
        limit = 15;
        break;
    default:
        limit = 10000;
        break;
    }
    if (obj->unk2A != 0) {
        hit = 0;
        if (obj->unkA6 < 0) {
            obj->unkA6 = 0;
        } else if (obj->unkA6 >= limit) {
            func_80032A68(obj);
            hit = -1;
        }
        if (hit == 0) {
            func_80042538((Obj *)&obj->unk7C);
        }
        if (self->unk8 == 0) {
            func_80030154(part);
        } else {
            func_8003072C((Unk8002DB90_Face *)part);
        }
    }
    obj++;
    if (first->unk34 == -1 && obj->unk2A != 0) {
        hit = 0;
        if (obj->unkA6 < 0) {
            obj->unkA6 = 0;
        } else if (obj->unkA6 >= limit) {
            func_80032A68(obj);
            hit = -1;
        }
        part = (Unk800308F8 *)&obj->unk2C;
        if (hit == 0) {
            func_80042538((Obj *)&obj->unk7C);
        }
        if (self->unk8 == 0) {
            func_80030154(part);
        } else {
            func_8003072C((Unk8002DB90_Face *)part);
        }
    }
}

typedef struct {
    u8 pad0[0x1C];
} Unk800A7A28;

extern Unk800A7A28 D_800A7A28[];
extern void func_800308F8(Unk800308F8 *p);
extern void func_80033918(Unk800584A4 *obj, Unk800A7A28 *info);

void func_80032770(void *arg0, void *arg1, Unk800325DC_Self *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];
    Unk800308F8 *part = (Unk800308F8 *)&obj->unk2C;
    Unk800308F8 *first = part;
    s16 limit;
    s16 hit;

    if (obj->unk2A == 0) {
        return;
    }
    switch (obj->unk62) {
    case 0:
        limit = 1;
        break;
    case 1:
        limit = 15;
        break;
    default:
        limit = 10000;
        break;
    }
    hit = 0;
    if (obj->unkA6 < 0) {
        obj->unkA6 = 0;
    } else if (obj->unkA6 >= limit) {
        func_80033918(obj, &D_800A7A28[obj->unkB2]);
        hit = -1;
    }
    if (hit == 0) {
        func_80042538((Obj *)&obj->unk7C);
    }
    if (self->unk8 == 0) {
        func_800308F8(part);
    } else {
        func_80030EA4((Unk8002DB90_Face *)part);
    }
    if (first->unk34 == -1) {
        part = (Unk800308F8 *)&obj[1].unk2C;
        if (self->unk8 == 0) {
            func_800308F8(part);
        } else {
            func_80030EA4((Unk8002DB90_Face *)part);
        }
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    u8 pad24[6];
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
    SVECTOR *unk3C[4];
    u8 pad4C[4];
    SVECTOR unk50[4];
    u8 pad70[0xC];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    u8 pad82[4];
    s16 unk86;
    u8 pad88[4];
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
    u8 pad92[2];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
    s16 unkA8;
    u8 padAA[6];
    s16 unkB0;
} Unk80033490;

extern s16 func_80050974(SVECTOR *pos, s32 arg1);
extern s16 func_800508F0(SVECTOR *pos);
extern s32 func_8004FB78(s32 *params);
void func_800335F0(Unk80033490 *obj, s16 speed);
void func_8004DE24(Unk80032344 *obj, s16 arg1);
void func_80042538(Obj *o);

void func_800328C0(s32 a0, s32 a1, Unk800584A4 *src) {
    Unk800584A4 *obj = &D_800A3564[src->unkA];
    s32 params[6];
    SVECTOR unused;
    s32 s;
    s32 c;

    if (obj->unk2A == 0) {
        return;
    }
    if (obj->unkA6 < 0) {
        obj->unkA6 = 0;
    }
    if (obj->unkA8 != 0 && obj->unkA6 == 0) {
        func_800335F0((Unk80033490 *)obj, 0x59);
    }
    s = (D_800854C0[obj->unkA & 0xFFF] * 16) >> 8;
    c = (D_800854C0[(obj->unkA + 0x400) & 0xFFF] * 16) >> 8;
    if (obj->unkA6 >= 16) {
        params[0] = 0x1E;
        params[1] = func_80050974((SVECTOR *)obj, 0x3FFF);
        params[2] = func_800508F0((SVECTOR *)obj) * 4;
        params[3] = 0x200;
        params[4] = 0;
        params[5] = 0;
        func_8004FB78(params);
        func_8004DE24((Unk80032344 *)obj, 0x10);
        obj->unk2A = 0;
    }
    obj->unk7C = obj->unk0 + c;
    obj->unk80 = obj->unk4 - s;
    obj->unk86 = obj->unkA;
    func_80042538((Obj *)&obj->unk7C);
    D_800A32E4 -= 25;
    func_80032344((Unk80032344 *)obj, 1);
    D_800A32E4 += 25;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80032A68);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80032FD8);

typedef struct {
    s16 x;
    s16 z;
    s16 angle;
} Unk80033490_Place;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
} Unk80033490_Size;

extern Unk80033490_Place D_80080614[];
extern Unk80033490_Size D_8008065C[];
extern s32 D_801D7030[];

void func_80033490(Unk80033490 *obj, s16 model, s16 kind) {
    obj->unk0 = (obj->unk0 & ~0x1FF) + D_80080614[kind >> 4].x;
    obj->unk4 = (obj->unk4 & ~0x1FF) + D_80080614[kind >> 4].z;
    obj->unk8 = 0;
    obj->unkA = obj->unk3A = D_80080614[kind >> 4].angle;
    obj->unkC = 0;
    obj->unk10 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk18 = 0x1000;
    obj->unk20 = D_801D7030[model];
    kind &= 0xF;
    obj->unk30 = obj->unk38 = D_8008065C[kind].a;
    obj->unk2E = obj->unk36 = D_8008065C[kind].b;
    obj->unk2C = obj->unk34 = D_8008065C[kind].c;
    obj->unk32 = 0;
    obj->unk3C[0] = &obj->unk50[0];
    obj->unk3C[1] = &obj->unk50[1];
    obj->unk3C[2] = &obj->unk50[2];
    obj->unk3C[3] = &obj->unk50[3];
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2;
    obj->unk80 = obj->unk4;
    obj->unkA6 = 0;
    obj->unkA8 = 0;
    obj->unkB0 = 0;
    obj->unk94 = 0x100;
    obj->unk98 = 0x400;
    obj->unk9C = 0x60;
    obj->unk8C = 0;
    obj->unk8E = 0;
    obj->unk90 = 0;
    obj->unk86 = obj->unkA;
}

typedef struct {
    char pad0[0xA];
    s16 unkA;
    char padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    char pad16[0x14];
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
} Unk80041178;

typedef struct {
    s16 id;
    s16 pad2;
    Unk80041178 *obj;
} Unk80041178Entry;

typedef struct {
    s16 count;
    s16 pad2;
    Unk80041178Entry entries[1];
} Unk80041178List;

extern struct {
    char pad0[0x1C];
    Unk80041178List *list;
} *D_801F7D28;

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0x20];
    s16 unk2C;
    u8 pad2E[0x6E];
    s32 unk9C;
} Unk80033820_Obj;

typedef struct {
    s16 speed;
    s16 dir;
    s16 count;
    s16 timer;
    Unk80033820_Obj *obj;
} Unk80033820;

extern s16 func_80050974(SVECTOR *pos, s32 arg1);
extern s16 func_800508F0(SVECTOR *pos);
extern s32 func_8004FB78(s32 *params);
extern void func_80033820(void);

void func_800335F0(Unk80033490 *obj, s16 speed) {
    Unk80041178List *list = D_801F7D28->list;
    Unk8003BA6C_Task *task;
    Unk80033820 *data;
    Unk8002A35C *target;
    s32 params[6];
    SVECTOR unused;
    s32 best;
    s32 dist;
    s16 i;
    s16 nearest;
    s16 dx;
    s16 dz;

    if (obj->unk2C == 1 || obj->unk2C == 5 || obj->unk2A == 0) {
        return;
    }
    params[0] = 0x1D;
    params[1] = func_80050974((SVECTOR *)obj, 0x3FFF);
    params[2] = func_800508F0((SVECTOR *)obj) * 4;
    params[3] = 0x580;
    params[4] = 0;
    params[5] = 0;
    func_8004FB78(params);
    task = func_80021264(func_80033820, 1, 0xC);
    if (task == NULL) {
        return;
    }
    data = (Unk80033820 *)task->data;
    data->speed = speed;
    data->dir = obj->unk2E;
    data->count = 50;
    data->obj = (Unk80033820_Obj *)obj;
    data->timer = obj->unk30;
    obj->unk2C = 1;
    best = 0x7FFFFFFF;
    nearest = 0;
    for (i = 0; i < list->count; i++) {
        dist = func_8002A35C((Unk8002A35C *)list->entries[i].obj, (Unk8002A35C *)obj);
        if (dist < best) {
            best = dist;
            nearest = i;
        }
    }
    target = (Unk8002A35C *)list->entries[nearest].obj;
    dx = obj->unk0 - target->x;
    dz = obj->unk4 - target->z;
    data->timer = 0x400;
    switch (obj->unkA >> 10) {
    case 0:
        if (dz > 0) {
            data->dir = 0;
        }
        if (dz < 0) {
            data->dir = 1;
        }
        break;
    case 1:
        if (dx > 0) {
            data->dir = 0;
        }
        if (dx < 0) {
            data->dir = 1;
        }
        break;
    case 2:
        if (dz > 0) {
            data->dir = 1;
        }
        if (dz < 0) {
            data->dir = 0;
        }
        break;
    case 3:
        if (dx > 0) {
            data->dir = 1;
        }
        if (dx < 0) {
            data->dir = 0;
        }
        break;
    }
}

void func_80033820(void) {
    Unk80033820 *data = (Unk80033820 *)D_800A317C->vals;
    Unk80033820_Obj *obj = data->obj;
    s16 *state = &obj->unk2C;

    if (data->dir != 0) {
        obj->unkA += data->speed;
    } else {
        obj->unkA -= data->speed;
    }
    data->timer -= data->speed;
    if (data->timer < 0) {
        data->speed = 20;
        if (data->dir != 0) {
            data->dir = 0;
        } else {
            data->dir = 1;
        }
        data->count = 5;
        data->timer = 0x400;
    }
    data->speed -= 4;
    data->count--;
    if (data->count < 0) {
        func_80021554();
        obj->unk9C = 32;
        *state = 5;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80033918);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80034194);

typedef struct {
    SVECTOR *v[3];
    s32 unkC;
    u16 unk10;
    u16 unk12;
} Unk8003516C_Face;

typedef struct {
    u8 *data;
    s16 used[10];
    s16 count;
    s16 timer;
    s16 state;
    s16 pad1E;
    s16 left;
} Unk8003516C_Faces;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 rx;
    s16 ry;
    s16 rz;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x10];
    Unk8003516C_Faces faces;
} Unk8003516C;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 rx;
    s16 ry;
    s16 rz;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s16 v0[4];
    s16 v1[4];
    s16 v2[4];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 pad3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 pad46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    u8 pad4E[0xA];
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 pad5E;
    s16 unk60;
    s16 unk62;
    s16 unk64;
    s16 pad66;
    s16 unk68;
    s16 pad6A;
    s16 unk6C;
    u8 pad6E[0xA];
    s16 unk78[4];
    s16 unk80[4];
    u16 unk88;
    u16 unk8A;
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
} Unk8003516C_Debris;

extern void func_800354B0();

void func_8003516C(Unk8003516C *obj) {
    Unk8003516C_Debris *d;
    Unk8003516C_Faces *faces;
    Unk8003BA6C_Task *task;
    Unk8003516C_Face *f;
    s16 i;
    s16 found;
    s16 v;

    obj->faces.state = 9;
    faces = &obj->faces;
    if (obj->faces.left == 0 || obj->faces.timer != 0) {
        return;
    }
    task = func_80021264(func_800354B0, 1, 0x94);
    if (task == NULL) {
        return;
    }
    d = (Unk8003516C_Debris *)task->data;
    i = func_8001E9DC(obj->faces.count);
    obj->faces.timer = 10;
    found = 0;
    obj->faces.left--;
    do {
        if (faces->used[i] != 0) {
            faces->used[i] = 0;
            found = 1;
        } else if (++i >= faces->count) {
            i = 0;
        }
    } while (!found);
    d->x = obj->x;
    d->y = obj->y;
    d->z = obj->z;
    d->rx = obj->rx;
    d->ry = obj->ry;
    d->rz = obj->rz;
    d->unk10 = obj->unk10;
    d->unk14 = obj->unk14;
    d->unk18 = obj->unk18;
    f = (Unk8003516C_Face *)(faces->data + 8);
    f += i;
    d->v0[0] = f->v[0]->vx;
    d->v0[1] = f->v[0]->vy;
    d->v0[2] = f->v[0]->vz;
    d->v1[0] = f->v[1]->vx;
    d->v1[1] = f->v[1]->vy;
    d->v1[2] = f->v[1]->vz;
    d->v2[0] = f->v[2]->vx;
    d->v2[1] = f->v[2]->vy;
    d->v2[2] = f->v[2]->vz;
    d->unk88 = f->unk10;
    d->unk8A = f->unk12;
    d->unk38 = d->unk40 = v = func_8001E9DC(30) - 15;
    d->unk48 = -v;
    d->unk3C = d->unk44 = d->unk4C = func_8001E9DC(30) - 15;
    d->unk3A = 20;
    d->unk42 = 20;
    d->unk4A = d->unk3A;
    if (d->unk38 < 0) {
        d->unk58 = d->unk60 = d->unk68 = 2;
    } else {
        d->unk58 = d->unk60 = d->unk68 = -2;
    }
    if (d->unk3C < 0) {
        d->unk5C = d->unk64 = d->unk6C = 2;
    } else {
        d->unk5C = d->unk64 = d->unk6C = -2;
    }
    d->unk62 = 0;
    d->unk5A = 0;
    d->unk8C = 10;
    d->unk8E = 600;
    for (i = 0; i < 3; i++) {
        d->unk78[i] = func_8001E9DC(14) - 7;
        if (d->unk78[i] < 0) {
            d->unk80[i] = -1;
        } else {
            d->unk80[i] = 1;
        }
    }
    d->unk90 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800354B0);

typedef struct {
    SVECTOR *parts[4];
    u8 pad10[4];
    SVECTOR part[4];
    u8 pad34[0x12];
    s16 unk46;
    s16 unk48;
    s16 type;
} Unk800358F0_Parts;

typedef struct {
    SVECTOR pos;
    SVECTOR rot;
    s32 scale[3];
    u8 pad1C[4];
    s32 unk20;
    u8 pad24[4];
    u16 unk28;
    u8 pad2A[2];
    Unk800358F0_Parts sub;
    u8 pad78[4];
    SVECTOR unk7C;
    SVECTOR unk84;
    u8 pad8C[8];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
    s16 unkA8;
    u8 padAA[0xA];
} Unk800358F0_Body;

typedef struct {
    s16 v[4];
} Unk800358F0_Tbl;

typedef struct {
    Unk800358F0_Body a;
    Unk800358F0_Body b;
} Unk800358F0;

extern Unk800358F0_Tbl D_800A2A88;
extern s16 D_800A2FFC;
extern s32 D_800A301C;
extern s16 D_800A3074;

void func_800358F0(Unk800358F0 *obj, s16 type, s32 dir) {
    Unk800358F0_Tbl tbl = D_800A2A88;
    Unk800358F0_Parts *s;
    Unk800358F0_Body *b;
    s16 k;
    s16 r;
    s32 sn;
    s32 cs;

    s = &obj->a.sub;
    b = &obj->b;
    s->unk46 = 0;
    s->unk48 = 0;
    s->parts[0] = &s->part[0];
    s->parts[1] = &s->part[1];
    s->parts[2] = &s->part[2];
    s->parts[3] = &s->part[3];
    if (type == 0x62) {
        k = 3;
    } else {
        k = type - 0x3E;
    }
    s->type = k;
    b->pos.vx = obj->a.pos.vx;
    b->pos.vy = obj->a.pos.vy;
    b->pos.vz = obj->a.pos.vz;
    obj->a.rot.vx = b->rot.vx = 0;
    obj->a.rot.vy = b->rot.vy = dir << 9;
    obj->a.rot.vz = b->rot.vz = 0;
    obj->a.scale[0] = b->scale[0] = 0x3000;
    obj->a.scale[1] = b->scale[1] = 0x3000;
    obj->a.scale[2] = b->scale[2] = 0x3000;
    obj->a.unk20 = D_801D70F0[tbl.v[k]];
    b->unk20 = D_801D70F0[59];
    obj->a.unk7C.vx = b->unk7C.vx = obj->a.pos.vx;
    obj->a.unk7C.vy = b->unk7C.vy = obj->a.pos.vy;
    obj->a.unk7C.vz = b->unk7C.vz = obj->a.pos.vz;
    obj->a.unk84.vx = b->unk84.vx = obj->a.rot.vx;
    obj->a.unk84.vy = b->unk84.vy = obj->a.rot.vy;
    obj->a.unk84.vz = b->unk84.vz = obj->a.rot.vz;
    obj->a.unkA6 = b->unkA6 = 0;
    obj->a.unkA8 = b->unkA8 = 0;
    obj->a.unk94 = 0x180;
    obj->a.unk98 = 0x180;
    obj->a.unk9C = 0x460;
    b->unk94 = 0x180;
    b->unk98 = 0x100;
    b->unk9C = 0x180;
    b->unk7C.vy += obj->a.unk98;
    if (D_800A2FFC == 0) {
        D_800A301C++;
        D_800A3074++;
    }
    r = obj->a.rot.vy;
    sn = D_800854C0[r & 0xFFF];
    cs = D_800854C0[(r + 0x400) & 0xFFF];
    b->unk28 = 0xFFFF;
    b->unk7C.vx -= (sn * 128) >> 12;
    b->unk7C.vz -= (cs * 128) >> 12;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80035B38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A8F4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A90);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    u8 pad24[0x4E];
    s16 unk72;
    s16 unk74;
    u8 pad76[6];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    s16 pad82;
    s16 unk84;
    s16 unk86;
    s16 unk88;
    u8 pad8A[0xA];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
    s16 unkA8;
} Unk800360C8;

extern struct {
    s32 unk0;
} D_801D7130;

void func_800360C8(Unk800360C8 *obj, s32 unused, s32 angle) {
    obj->unk2 = 0x480;
    obj->unk8 = 0;
    obj->unkA = angle << 9;
    obj->unkC = 0;
    obj->unk10 = 0x3000;
    obj->unk14 = 0x3000;
    obj->unk18 = 0x3000;
    obj->unk84 = 0;
    obj->unk86 = angle << 9;
    obj->unk88 = 0;
    obj->unkA6 = 0;
    obj->unkA8 = 0;
    obj->unk94 = 0x200;
    obj->unk98 = 0x400;
    obj->unk9C = 0x480;
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2;
    obj->unk80 = obj->unk4;
    obj->unk20 = D_801D7130.unk0;
    obj->unk74 = 0;
    obj->unk72 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003614C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A934);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A974);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
} Unk80036918;

extern s32 D_801D70F0[];

void func_800365C0(Unk80036918 *p, s16 type) {
    s16 idx;

    p->unk2 = 0x400;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unk10 = 0x1000;
    p->unk14 = 0x1000;
    p->unk18 = 0x1000;
    idx = type - 7;
    p->unk0 = (p->unk0 & ~0x1FF) + 0x100;
    p->unk4 = (p->unk4 & ~0x1FF) + 0x100;
    if (idx < 92 || idx > 102) {
        idx = 0;
    }
    p->unk20 = D_801D70F0[idx];
}

void func_80036644(void *arg0, void *arg1, Unk800584A4 *self) {
    func_80032344((Unk80032344 *)&D_800A3564[self->unkA], 1);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80036688);

void func_80036918(Unk80036918 *p, s16 type, s16 flag) {
    s16 idx;

    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unk10 = 0x1000;
    p->unk14 = 0x1000;
    p->unk18 = 0x1000;
    idx = type - 19;
    p->unk0 = (p->unk0 & ~0x1FF) + 0x100;
    p->unk4 = (p->unk4 & ~0x1FF) + 0x100;
    if (idx < 92 || idx > 102) {
        idx = 0;
    }
    p->unk20 = D_801D70F0[idx];
    if (flag) {
        p->unk0 += 0x100;
    }
}

void func_800369B8(void *arg0, void *arg1, Unk800584A4 *self) {
    func_80032344((Unk80032344 *)&D_800A3564[self->unkA], 1);
}

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    char pad6[2];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    char padE[2];
    s16 unk10;
    s16 state;
    s16 unk14;
    s16 id;
    s16 unk18;
    s16 unk1A;
} Unk800A7A20;

extern Unk800A7A20 D_800A7A20[50];
extern s16 D_800A30D4;
extern s16 D_800A3244;
extern SVECTOR D_800A30AC;

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0xA];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x4C];
    s16 unk62;
} Unk800369FC;

void func_800369FC(Unk800369FC *obj, s16 arg1, s16 spread, s16 flag, s16 arg4) {
    SVECTOR v;
    SVECTOR r;
    VECTOR out;
    MATRIX m;
    s16 i;

    if (D_800A30D4 >= 50) {
        return;
    }
    if (flag != 0) {
        D_800A3244++;
    }
    if (spread == 0) {
        spread = 16;
    }
    for (i = 0; i < 50; i++) {
        if (D_800A7A20[i].state == -1) {
            continue;
        }
        D_800A7A20[i].x = obj->pos.x;
        D_800A7A20[i].y = obj->pos.y + 0x276;
        D_800A7A20[i].z = obj->pos.z;
        D_800A7A20[i].id = obj->unk62;
        D_800A7A20[i].unk14 = obj->unk12;
        v.vx = -0x6E;
        v.vy = 0;
        v.vz = 0x258;
        r.vx = 0;
        r.vy = obj->unk12;
        r.vz = 0;
        func_80023C7C(&D_800A30AC, &D_801FB868);
        ApplyMatrix(&D_801FB868, (SVECTOR *)D_800A351C + 7, &out);
        D_800A7A20[i].x = obj->pos.x + out.vx;
        D_800A7A20[i].y = obj->pos.y + out.vy;
        D_800A7A20[i].z = obj->pos.z + out.vz;
        v.vx = 0;
        v.vy = 0;
        v.vz = func_8001E9DC(0x40) + 0x1A4;
        r.vx = obj->unk10 + (func_8001E9DC(spread * 2) - spread);
        r.vx = arg4 + (func_8001E9DC(spread * 2) - spread);
        r.vy = obj->unk12 + (func_8001E9DC(spread * 2) - spread);
        r.vz = obj->unk14;
        func_80023660(&r, &D_801FB868);
        ApplyMatrix(&D_801FB868, &v, &out);
        D_800A7A20[i].unk8 = out.vx;
        D_800A7A20[i].unkA = out.vy;
        D_800A7A20[i].unkC = out.vz;
        if (flag != 0) {
            D_800A7A20[i].unk18 = 2;
        } else {
            D_800A7A20[i].unk18 = 0;
        }
        D_800A7A20[i].unk10 = 20;
        D_800A7A20[i].state = -1;
        D_800A7A20[i].unk1A = arg1;
        D_800A7A20[i].x -= D_800A7A20[i].unk8 >> 1;
        D_800A7A20[i].y -= D_800A7A20[i].unkA >> 1;
        D_800A7A20[i].z -= D_800A7A20[i].unkC >> 1;
        D_800A30D4++;
        return;
    }
}

extern s16 D_800A336C;

s16 func_80036DE8(Unk8002A35C *pos, s16 type, s16 arg2, s16 arg3) {
    s16 i;

    if (D_800A30D4 >= 50) {
        return 0xFF;
    }
    for (i = 0; i < 50; i++) {
        if (D_800A7A20[i].state != -1) {
            D_800A7A20[i].x = pos->x;
            D_800A7A20[i].y = pos->y;
            D_800A7A20[i].z = pos->z;
            D_800A30D4++;
            D_800A7A20[i].unk8 = type;
            D_800A7A20[i].unkA = 0;
            D_800A7A20[i].unkC = arg2;
            D_800A7A20[i].unk18 = 1;
            D_800A7A20[i].unk10 = 2;
            D_800A7A20[i].state = -1;
            D_800A7A20[i].unk1A = arg3;
            D_800A7A20[i].id = D_800A336C;
            return i;
        }
    }
    return 0xFF;
}

extern void *D_801F7D34;
extern void func_80037D64();

void func_80036F28(void) {
    s16 i;

    D_800A3244 = 0;
    D_801F7D34 = func_80021264(func_80037D64, 1, 6);
    for (i = 0; i < 50; i++) {
        D_800A7A20[i].state = 0;
    }
    D_800A30D4 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80036FAC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2A98);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800371CC);

typedef struct {
    Unk8002A35C pos;
    u8 pad6[2];
    u8 unk8[64];
    u8 unk48[64];
    s16 unk88;
    s16 unk8A;
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
} Unk8003768C;

extern void func_80037790();

void func_8003768C(SVECTOR *pos, s16 arg1) {
    Unk8003BA6C_Task *task;
    Unk8003768C *d;
    s16 i;

    task = func_80021264(func_80037790, 1, 0x9A);
    if (task == NULL) {
        return;
    }
    d = (Unk8003768C *)task->data;
    for (i = 0; i < 64; i++) {
        d->unk8[i] = 0;
        d->unk48[i] = 0;
    }
    d->pos.x = pos->vx;
    d->pos.y = pos->vy;
    d->pos.z = pos->vz;
    d->unk88 = (pos->vx >> 8) + D_800A79F0.x * 2;
    d->unk8A = (pos->vz >> 8) + D_800A79F0.z * 2;
    d->unk8C = 2;
    d->unk8E = 2;
    d->unk90 = 3;
    d->unk94 = 7;
    d->unk92 = pos->vy + 0x200;
    d->unk96 = 20;
    d->unk98 = arg1;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80037790);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80037D64);

extern void func_8004ACD4(SVECTOR *pos);
extern void func_80056ADC(SVECTOR *v, s16 arg1);

void func_80038554(SVECTOR *pos) {
    s32 params[6];

    D_800A3244--;
    func_8003768C(pos, 0);
    func_8004ACD4(pos);
    func_80056ADC(pos, 0xE00);
    params[0] = 0x10;
    params[1] = func_80050974(pos, 0x3FFF);
    params[2] = func_800508F0(pos) * 4;
    params[3] = 0x400;
    params[4] = 0;
    params[5] = 0;
    func_8004FB78(params);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800385F4);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80038B00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A984);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007A9E0);

typedef struct {
    s16 x;
    s16 z;
    s16 unk4;
    s16 links[4];
    s16 unkE[4];
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[2];
} Unk80043CC4;

extern Unk80043CC4 *D_800A3084;
extern s16 D_800A31DC;

extern s16 D_800A3464;
extern s16 D_800A7F98[];
extern u8 *D_800A340C;
void func_800391E0(s16 i);

void func_800390B8(void) {
    s16 i;
    s16 j;
    Unk80043CC4 *node;
    u8 unused[16];

    D_800A3464 = 0;
    for (i = 0; i < D_800A31DC; i++) {
        node = &D_800A3084[i];
        if (node->unk16 != 0) {
            D_800A7F98[node->unk18] = i;
            D_800A3464++;
        }
        func_800391E0(i);
        for (j = 0; j < D_800A31DC; j++) {
            D_800A340C[j * 256 + i] = D_800A3084[j].unk1C;
        }
    }
}

extern s16 D_800A31D4;
typedef struct {
    s16 node;
    s16 dist;
} PathStep;

extern PathStep D_801FB9C8[];

void func_800391E0(s16 start) {
    volatile s16 count;
    PathStep *queue;
    s32 i;
    s32 head;
    s32 tail;
    s32 cur;
    s32 dist;
    s32 next;
    s16 found;

    queue = D_801FB9C8;
    D_800A31D4++;
    for (i = 0; i < D_800A31DC; i++) {
        queue[i].node = -1;
        queue[i].dist = -1;
    }
    queue[0].node = start;
    queue[0].dist = 1;
    count = D_800A31DC;
    D_800A3084[start].unk1C = start;
    D_800A3084[start].unk1A = D_800A31D4;
    D_800A3084[start].unk4 = 1;
    head = 0;
    tail = 1;
    while (tail + 1 < count) {
        for (i = head; i < tail; i++) {
            cur = queue[i].node;
            dist = queue[i].dist;
            found = 0;
            head++;
            next = D_800A3084[cur].links[0];
            if (next != -1 && D_800A3084[next].unk1A != D_800A31D4) {
                D_800A3084[next].unk1A = D_800A31D4;
                D_800A3084[next].unk1C = cur;
                D_800A3084[next].unk4 = dist + 1;
                queue[tail].node = next;
                queue[tail].dist = dist + 1;
                found = -1;
                tail++;
            }
            next = D_800A3084[cur].links[1];
            if (next != -1 && D_800A3084[next].unk1A != D_800A31D4) {
                D_800A3084[next].unk1A = D_800A31D4;
                D_800A3084[next].unk1C = cur;
                D_800A3084[next].unk4 = dist + 1;
                queue[tail].node = next;
                queue[tail].dist = dist + 1;
                found = -1;
                tail++;
            }
            next = D_800A3084[cur].links[2];
            if (next != -1 && D_800A3084[next].unk1A != D_800A31D4) {
                D_800A3084[next].unk1A = D_800A31D4;
                D_800A3084[next].unk1C = cur;
                D_800A3084[next].unk4 = dist + 1;
                queue[tail].node = next;
                queue[tail].dist = dist + 1;
                found = -1;
                tail++;
            }
            next = D_800A3084[cur].links[3];
            if (next != -1 && D_800A3084[next].unk1A != D_800A31D4) {
                D_800A3084[next].unk1A = D_800A31D4;
                D_800A3084[next].unk1C = cur;
                D_800A3084[next].unk4 = dist + 1;
                queue[tail].node = next;
                queue[tail].dist = dist + 1;
                found = -1;
                tail++;
            }
            if (!found) {
                count--;
            }
        }
    }
}

extern s16 *D_800A31B4;

s16 func_80039458(Unk80045164 *obj) {
    SVECTOR *p = (SVECTOR *)obj;
    s16 x = (p->vx >> 9) + D_800A79F0.x;
    s16 z = (p->vz >> 9) + D_800A79F0.z;

    return D_800A31B4[z * 64 + x];
}

s16 func_800394B8(SVECTOR *p) {
    s16 x = (p->vx >> 9) + D_800A79F0.x;
    s16 z = (p->vz >> 9) + D_800A79F0.z;

    return D_800A31B4[z * 64 + x];
}

extern MATRIX D_801FB868;
extern MATRIX *func_80023C7C(SVECTOR *r, MATRIX *m);

void func_80039518(Unk80045EF4 *obj) {
    SVECTOR unused[2];

    func_80023C7C((SVECTOR *)&obj->padE[2], &D_801FB868);
    ApplyMatrix(&D_801FB868, (SVECTOR *)&obj->unk4C, (VECTOR *)&obj->unk3C);
}

void func_8003955C(Unk80045164 *obj) {
    obj->anim.unk6 = 0xA4;
    func_80024EF0(&obj->anim);
}

void func_80039584(Unk80045164 *obj) {
    func_80031200((Unk80031200 *)obj);
    func_80024EF0(&obj->anim);
    func_8003146C((Unk8003146C *)obj);
    func_80031320(obj);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800395C0);

extern void func_8003D8EC(Unk80045164 *obj, s16 arg1);
extern void func_8003BAD8(void);
void func_8003BE8C();

void func_8003961C(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    s16 time;
    s16 done;

    func_80031320(obj);
    time = obj->anim.time;
    done = func_80024EF0(&obj->anim);
    obj->unkD4++;
    if (obj->unk116 != 0) {
        obj->model.rot.vy += 0x80;
        obj->pos.y += 0x40;
        if (done) {
            obj->anim.time = time;
            done = 0;
        }
        obj->unk116--;
        if (obj->unk116 == 0) {
            func_8003D8EC(obj, -1);
            D_800A317C->vals->vals[1] = 5;
            D_800A317C->func = func_8003BAD8;
        }
    }
    if (obj->unkD4 < 10) {
        obj->unk94.x = obj->pos.x;
        obj->unk94.y = obj->pos.y;
        obj->unk94.z = obj->pos.z;
        func_80041104(obj);
    }
    if (done) {
        obj->anim.time = time;
        func_8003D8EC(obj, -1);
        func_8003BE8C(obj);
        D_800A317C->vals->vals[1] = 5;
        D_800A317C->func = func_8003BAD8;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80039778);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80039858);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007A9F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AA38);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80039B80);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80039F98);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AA0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AA8);

extern s32 D_801C08F8[];

s16 func_8003A430(void *obj) {
    s16 i;

    for (i = 0; i < 0x14; i++) {
        if (D_801C08F8[i] == 0) {
            D_801C08F8[i] = (s32)obj;
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003A48C);

typedef struct {
    u8 pad0[0x122];
    s16 unk122;
} Unk8003A790;

extern s32 D_801C08F8[];
extern s16 D_800A2F14;
extern s16 D_800A2F74;
extern s16 D_800A3184;
extern s16 D_800A61B0;
extern s16 D_800A61B2;
typedef struct {
    s16 count;
    s16 idx;
    s16 unk4;
    s16 log[5][2];
} History;

extern History D_801D2078;

void func_8003A790(Unk8003A790 *obj, s16 type) {
    if (obj->unk122 != -1) {
        D_801C08F8[obj->unk122] = 0;
    }
    if (type == 0) {
        D_800A61B0 = -1;
        D_800A3184 += 60;
        if (D_800A2F14 == 0) {
            D_800A2F74++;
        }
    }
    if (type == 1) {
        D_800A61B2 = -1;
    }
    if (++D_801D2078.idx >= 5) {
        D_801D2078.idx = 0;
    }
    D_801D2078.log[D_801D2078.idx][0] = D_801D2078.count;
    D_801D2078.log[D_801D2078.idx][1] = type;
    D_801D2078.count++;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003A8A4);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003B04C);

extern void func_8003E384(Unk80045164 *obj);
extern s16 func_80023E80(void *obj, s32 *a, s32 *b);
extern void func_80039858(void);
extern void func_80049820(u32);

void func_8003B850(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    s32 tmp;

    func_8003E384(obj);
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320(obj);
    func_8002A270(&obj->pos, obj->unk28 != 4 ? 4 : 0);
    if (obj->unk158 == 0) {
        D_800A317C->func = D_800A317C->saved;
        return;
    }
    obj->unk158--;
    if (obj->unk94.f2A != 0) {
        if (obj->unk94.f2A < 0) {
            obj->unk158 = 200;
        } else {
            obj->unkF2 -= obj->unk94.f2A;
            if (obj->unkF2 <= 0) {
                if (D_800A7A20[obj->unkCA].id == D_800A336C) {
                    if (obj->unk28 == 4) {
                        func_80049820(-10000);
                    } else {
                        func_80049820(5000);
                    }
                } else {
                    func_80049820(5);
                }
                D_800A317C->func = func_80039858;
            }
        }
        obj->unk94.f2A = 0;
    }
}

typedef struct {
    u8 top[4];
    u8 bottom[4];
} Unk800A2AA8;

extern Unk800A2AA8 D_800A2AA8;
extern char D_8008B36C[];
extern s16 D_800A33C4;
extern void func_80053864(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_8003B9B0(void) {
    Unk8003BA6C_Data *data = (Unk8003BA6C_Data *)D_800A317C->vals;
    Unk800A2AA8 colors = D_800A2AA8;

    if (data->unk2 & 8) {
        func_80053864(160, D_800A33C4 - 30, D_8008B36C, 0x600, 0x3C0, colors.top, colors.bottom);
    }
    if (data->unk2 != 0) {
        data->unk2--;
    } else {
        func_80021554();
    }
}

extern s16 D_801D209C;
extern void func_8003B9B0();

void func_8003BA6C(void) {
    Unk8003BA6C_Task *task;
    Unk8003BA6C_Data *data;
    s16 *count = &D_801D209C;

    if (*count != 15) {
        task = func_80021264(func_8003B9B0, 1, 4);
        if (task != NULL) {
            data = task->data;
            data->unk2 = 0x70;
            data->unk0 = 0;
            (*count)++;
        }
    }
}

void func_8003BAD8(void) {
    s32 *t = (s32 *)D_800A317C->vals;

    if (t[2] != 0) {
        t[2]--;
    } else {
        func_80021554();
    }
}

extern s16 D_800A3184;
extern s16 D_800A33C4;
extern char D_8007AA38[];
extern u8 D_800A2A30[];
extern u8 D_800A2A38[];

extern void func_80053864(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_8003BB20(void) {
    if (D_800A3184 != 0) {
        func_80053864(160, D_800A33C4 - 50, D_8007AA38, 0x300, 0x200, D_800A2A30, D_800A2A38);
        D_800A3184--;
    }
}

typedef struct {
    s16 vals[10][4];
    s16 unk50[10];
    s16 unk64[10];
    s16 unk78[10];
    s16 unk8C[10];
    s16 unkA0[10];
    s16 unkB4[10];
    s16 unkC8[10];
    s16 unkDC[10];
    u8 unkF0[10];
    u8 unkFA[10];
    s16 unk104;
    s16 unk106;
} Unk8003BB9C_Data;

extern void *D_801F7D38;

void func_8003BC64(void);
extern int VSync(int mode);

void func_8003BB9C(void) {
    void *task;
    Unk8003BB9C_Data *data;
    s16 i;

    task = func_80021264(func_8003BC64, 1, 0x108);
    if (task == NULL) {
        while (1) {
            VSync(0);
        }
    }
    D_801F7D38 = task;
    data = *(Unk8003BB9C_Data **)((u8 *)task + 0x1C);
    data->unk104 = 0;
    data->unk106 = 1;
    for (i = 0; i < 10; i++) {
        data->unkFA[i] = 0;
        data->vals[i][0] = 0;
        data->vals[i][1] = 0;
        data->vals[i][2] = 0;
        data->vals[i][3] = 0;
        data->unk64[i] = 0;
        data->unk78[i] = 0;
        data->unk8C[i] = 0;
        data->unkA0[i] = 0;
        data->unkB4[i] = 0;
        data->unkC8[i] = 0;
        data->unkF0[i] = 0;
        data->unkDC[i] = 0;
    }
}

typedef struct {
    SVECTOR pos[10];
    s16 rotY[10];
    s16 unk64[10];
    s16 unk78[10];
    s16 unk8C[10];
    s16 unkA0[10];
    s16 unkB4[10];
    s16 unkC8[10];
    s16 unkDC[10];
    u8 animId[10];
    u8 active[10];
} Unk8003BC64;

typedef struct {
    SVECTOR rot;
    Anim anim;
    s16 unk28[5];
    s16 unk32;
    u8 unk34;
    u8 unk35;
} Unk8003BC64_Part;

void func_8003BC64(void) {
    Unk8003BC64 *obj = (Unk8003BC64 *)D_800A317C->vals;
    SVECTOR unused;
    Unk8003BC64_Part part;
    s32 *m;
    s16 i;

    part.anim.id = 0x1B;
    m = D_800A353C[part.anim.id].p;
    part.anim.time = ((u16 *)m)[11];
    part.anim.unk16 = 0;
    part.unk32 = 0xDAC;
    part.anim.unk1A = 0x1000;
    part.unk34 = 100;
    part.anim.unk1E = 0;
    part.anim.unk1C = 0;
    for (i = 0; i < 10; i++) {
        if (obj->active[i] == 0) {
            continue;
        }
        part.rot.vx = 0;
        part.rot.vy = obj->rotY[i];
        part.rot.vz = 0;
        part.unk28[0] = obj->unk64[i];
        part.unk28[1] = obj->unk78[i];
        part.unk28[2] = obj->unk8C[i];
        part.unk28[3] = obj->unkA0[i];
        part.unk28[4] = obj->unkB4[i];
        part.unk35 = obj->unkC8[i];
        part.anim.id = obj->animId[i];
        m = D_800A353C[part.anim.id].p;
        part.anim.time = m[0] - m[2];
        if (func_8002501C(&obj->pos[i], &part, 0xFFF, 0, &part.anim) >= 8 && D_800A326C > 8) {
            if (D_801C1F00 != 0) {
                func_80031ED0((SVECTOR *)&obj->pos[i], (SVECTOR *)&part, 0x14);
            } else {
                u32 *ot = D_800A32E4 + D_800A326C;
                if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                    AddPrims(ot, D_800A2FAC + 0x14, D_800A2FAC);
                }
            }
        } else {
            obj->active[i] = 0;
            obj->unkDC[i] = 0;
        }
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0xC];
    s16 unk12;
    u8 pad14[0x52];
    u8 unk66;
    u8 pad67[0x1D];
    s16 unk84;
    s16 unk86;
    s16 unk88;
    s16 unk8A;
    s16 unk8C;
    u8 pad8E[3];
    u8 unk91;
} Unk8003BE8C;

void func_8003BE8C(Unk8003BE8C *src) {
    Unk8003BB9C_Data *data;
    s16 slot;
    s16 best;
    s16 i;

    slot = 0;
    data = *(Unk8003BB9C_Data **)((u8 *)D_801F7D38 + 0x1C);
    best = 0x7FFF;
    for (i = 0; i < 10; i++) {
        if (data->unkDC[i] < best) {
            slot = i;
            best = data->unkDC[0];
        }
    }
    data->vals[slot][0] = src->unk0;
    data->vals[slot][1] = src->unk2;
    data->vals[slot][2] = src->unk4;
    data->unk50[slot] = src->unk12;
    data->unk64[slot] = src->unk84;
    data->unk78[slot] = src->unk86;
    data->unk8C[slot] = src->unk88;
    data->unkA0[slot] = src->unk8A;
    data->unkB4[slot] = src->unk8C;
    data->unkC8[slot] = src->unk91;
    data->unkF0[slot] = src->unk66;
    data->unkDC[slot] = data->unk106;
    data->unkFA[slot] = 0xFF;
    data->unk106++;
}

typedef struct {
    s16 used;
    u16 timer;
    s16 pad4;
    s16 state;
    u8 pad8[0x18];
} Unk8003BFA8_Entry;

typedef struct {
    u8 pad0[0x18];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
} Unk8003BFA8_Data;

extern u8 *D_800A3474;
extern s16 D_800A2F6C;
extern Unk8003BA6C_Task *D_801F7D3C[];
extern s16 D_800A329C;
extern s16 D_800A2EF0;
extern s16 D_800A3274;
extern Unk80045164 *D_801FBDC8[];
extern s16 D_800A31CC;
extern s16 D_800A3054;
extern s16 D_800A2FD4;
extern s16 D_800A3324;
extern s16 D_800A32F4;
extern s16 D_800A318C;
extern s16 D_800A2EE8;
extern s16 D_800A34AC;
extern s16 D_800A32DC;
extern s16 D_800A31FC;
extern s16 D_800A3504;
extern s16 D_800A344C;
extern s16 D_800A30C4;
extern void func_8003C1C4();

void func_8003BFA8(void) {
    Unk8003BFA8_Entry *e = (Unk8003BFA8_Entry *)D_800A3474;
    Unk8003BA6C_Task *task;
    Unk8003BFA8_Data *d;
    s16 i;
    s16 last;
    s16 reset = 0;

    task = func_80021264(func_8003C1C4, 1, 0x20);
    D_801F7D3C[0] = task;
    d = (Unk8003BFA8_Data *)task->data;
    d->unk18 = 0;
    if (D_800A329C != 0) {
        d->unk1A = 1;
    } else {
        d->unk1A = 0;
    }
    d->unk1C = 0;
    for (i = 0; i < 0x80; i++) {
        D_801FBDC8[i] = 0;
    }
    D_800A31CC = 0;
    D_800A3054 = 0;
    D_800A2FD4 = 0;
    D_800A3324 = 0;
    D_800A32F4 = 0;
    D_800A318C = 0;
    D_800A2EE8 = 0;
    D_800A34AC = 0;
    D_800A32DC = 0;
    D_800A31FC = 0;
    D_800A3504 = 0;
    D_800A344C = 0;
    D_800A30C4 = 0;
    D_800A3274 = 0;
    last = 99;
    for (i = 0; i < D_800A2F6C; e++, i++) {
        if (e->used == 0) {
            if (e->timer < 30) {
                last = i;
            }
            if (e->timer != 1) {
                e->timer *= 30;
            }
        }
        if (e->state == 4) {
            if (D_800A2EF0 != 0) {
                e->state = 2;
                reset = -1;
            } else {
                e->state = 1;
                reset = 0;
            }
        }
    }
    d->unk1E = last;
    if (reset) {
        D_800A2EF0 = 0;
    }
    for (i = 0; i < 20; i++) {
        D_801C08F8[i] = 0;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003C1C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AA48);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003CB90);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AAC0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AB0C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AB28);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003D280);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AB40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AB8C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AB0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AB8);

s16 func_8003D890(Unk80045164 *obj) {
    s16 i;

    for (i = 0; i < 0x80; i++) {
        if (D_801FBDC8[i] == 0) {
            D_801FBDC8[i] = obj;
            return i;
        }
    }
    return -1;
}

extern s16 D_801C1EF6;
extern s16 D_800A61BC;

void func_8003D8EC(Unk80045164 *obj, s16 arg1) {
    s32 params[6];

    if (obj->unk62 != -1) {
        D_801FBDC8[obj->unk62] = NULL;
    }
    switch (obj->unk28) {
    case 13:
        break;
    case 4:
        D_800A31CC--;
        D_800A32F4--;
        if (arg1) {
            D_800A318C++;
        } else {
            D_800A2EE8++;
        }
        if (D_800A32F4 == 0 && D_800A2F14 != 0 && D_800A2F74 == 0) {
            if (arg1) {
                params[0] = 0x33;
                params[1] = 0x3FFF;
                params[2] = 0;
                params[3] = 0x400;
                params[4] = 0;
                params[5] = 1;
                params[3] = D_801C1EF6 + 0x400;
                func_8004FB78(params);
            }
            D_800A61BC = -1;
        }
        break;
    case 18:
        D_800A31FC--;
        D_800A3504++;
    default:
        D_800A31CC--;
        D_800A3054--;
        D_800A2FD4++;
        if (D_800A3054 == 0 && D_800A2F14 == 0) {
            params[0] = 0x33;
            params[1] = 0x3FFF;
            params[2] = 0;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 1;
            params[3] = D_801C1EF6 + 0x400;
            func_8004FB78(params);
            D_800A61BC = -1;
        }
        break;
    }
}

extern void func_8003D280(void);

void func_8003DAE8(void) {
    func_8003D280();
    func_80021554();
}

void func_8003DB10(void) {
    func_8003D280();
    func_80021554();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003DB38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007ABB8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007ABFC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AC20);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AC34);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AC48);

typedef struct {
    s16 x, y, z;
    s16 pad6;
    s16 rx, ry, rz;
    s16 padE;
    s32 sx, sy, sz;
    s32 pad1C;
    s32 unk20;
} Unk8003E1D0_Model;

typedef struct {
    s16 x, y, z;
    s16 pad6;
    s16 unk8, unkA, unkC;
    s16 padE[2];
    s16 unk12;
    u8 pad14[0x14];
    s16 unk28;
    u8 pad2A[0x22];
    s16 unk4C, unk4E, unk50;
    u8 pad52[0x5A];
    s32 unkAC;
    s32 padB0;
    s32 unkB4;
    u8 padB8[0x1C];
    s16 unkD4, unkD6, unkD8, unkDA, unkDC;
    u8 padDE[4];
    s16 unkE2, unkE4;
    u8 padE6[0x2E];
    Unk8003E1D0_Model model;
} Unk8003E1D0;

extern SVECTOR D_800A34B4;
extern SVECTOR D_800A3544;
extern s16 func_80043CC4(s16 id);
extern short func_80043D68(short a, short b, short scale);
extern void func_8004379C(short id, SVECTOR *out);
extern void func_8003DB38(void);

void func_8003E1D0(void) {
    Unk8003E1D0 *obj = (Unk8003E1D0 *)D_800A317C->vals;
    Unk8003E1D0_Model *m = &obj->model;
    s32 d, e;

    obj->unkD8 = obj->unkDC = func_80043CC4(obj->unkD6);
    func_8004379C(obj->unkD6, &D_800A34B4);
    func_8004379C(obj->unkD8, &D_800A3544);
    d = func_8002A35C((Unk8002A35C *)&D_800A34B4, (Unk8002A35C *)&D_800A3544);
    e = func_8002A35C((Unk8002A35C *)obj, (Unk8002A35C *)&D_800A3544);
    obj->unkD4 = (d < e ? 0x200000 : 0x400000) / d;
    obj->unkDA = func_80043D68(obj->unkD6, obj->unkD8, 0x40);
    obj->unk4C = 0;
    obj->unk4E = 0;
    obj->unk50 = 0;
    obj->unk8 = obj->x;
    obj->unkA = obj->y;
    obj->unkC = obj->z;
    obj->unkE2 = func_8001E9DC(20) + 20;
    obj->unkE4 = 0;
    obj->unkAC = 100;
    obj->unkB4 = 100;
    if (obj->unk28 == 13) {
        m->x = obj->x;
        m->y = obj->y;
        m->z = obj->z;
        m->rx = 0;
        m->ry = obj->unk12;
        m->rz = 0;
        m->sx = 0x1000;
        m->sy = 0x1000;
        m->sz = 0x1000;
        m->unk20 = D_801D70F0[38];
        obj->unkD4 = 0;
    }
    D_800A317C->func = func_8003DB38;
}

void func_8003E384(Unk80045164 *obj) {
    obj->unk94.f18 = func_800437C8(obj->unk94.f18, 200, 2);
    obj->unk94.f20 = func_800437C8(obj->unk94.f20, 200, 2);
}

extern int CdSync(int mode, unsigned char *result);
extern int CdInit(void);

void func_8003E3CC(void) {
    u8 result[8];

    CdSync(0, result);
    CdControl(10, 0, result);
    CdSync(0, result);
    CdInit();
}

typedef struct {
    s32 offset;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} PackEntry;

typedef struct {
    s32 count;
    PackEntry entries[1];
} Pack;

void *func_8003E414(void *data, s16 i) {
    Pack *pack = data;
    return (u8 *)pack + pack->entries[i].offset;
}

u32 func_8003E42C(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk4;
}

s32 func_8003E444(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk8;
}

s32 func_8003E45C(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unkC;
}

void func_8003E474(void) {
}

extern volatile s16 D_800A2F84;

void func_8003E47C(void) {
    D_800A2F84 = 20;
}

extern char D_8007ABFC[];
extern int printf(const char *fmt, ...);
extern int ResetGraph(int mode);
extern void PadStop(void);
extern void StopPAD(void);
extern void func_80076F04(void);
extern void func_8006B188(s16);

void func_8003E490(void) {
    printf(D_8007ABFC);
    ResetGraph(3);
    PadStop();
    StopPAD();
    func_80076F04();
    func_800206CC();
    func_8006B188(1);
}

typedef struct {
    u8 loc[4];
    s32 size;
    u8 pad8[0x10];
} CdFileEntry;

extern volatile s16 D_800A345C;
extern volatile s16 D_800A334C;
extern volatile s16 D_800A34E4;
extern volatile s16 D_800A3124;
extern volatile s16 D_800A2F94;
extern s16 D_800A2FA4;
extern u32 *D_800A3254;
extern u8 *D_800A2C0C;
extern char D_8007AC20[];
extern char D_8007AC34[];
extern char D_8007AC48[];
extern int ResetCallback(void);
extern void CdReadCallback(void (*func)());
extern int printf(const char *fmt, ...);
extern void func_8003E3CC(void);
extern void func_8003E490(void);

void func_8003E4E8(void) {
    u8 unused[8];
    u8 result[8];
    CdFileEntry *e;
    s16 r;

    if (D_800A345C != 0) {
        r = CdSync(1, result);
        printf(D_8007AC20, result[0]);
        printf(D_8007AC34, r);
        if (r == 5) {
            D_800A334C = 601;
        } else if (r == 2) {
            ResetCallback();
            CdReadCallback(func_8003E47C);
            CdRead((u32)(((CdFileEntry *)D_800A2C0C)[D_800A3124].size + 0x7FF) >> 11, D_800A3254, 0x80);
            D_800A345C = 0;
        }
    }
    if (D_800A2F84 != 0) {
        D_800A2F84--;
        if (D_800A2F84 == 0) {
            func_800206CC();
            D_800A2FA4 = 0;
            D_800A317C->func = D_800A34A4;
            return;
        }
    }
    D_800A334C++;
    if (D_800A334C >= 601) {
        printf(D_8007AC48);
        D_800A34E4++;
        if (D_800A34E4 >= 4) {
            func_8003E490();
        }
        D_800A334C = 0;
        D_800A2F84 = 0;
        ResetCallback();
        CdReadCallback(NULL);
        if (D_800A2F94 != 0) {
            D_800A345C = 100;
            D_800A2F94 = 0;
        } else {
            D_800A345C = 25;
        }
        e = &((CdFileEntry *)D_800A2C0C)[D_800A3124];
        func_8003E3CC();
        CdControl(0x15, e->loc, 0);
    }
}

void func_8003E77C(void *dest, s32 arg1) {
    s32 file;

    D_800A34E4 = 0;
    D_800A334C = 0;
    D_800A2F84 = 0;
    file = arg1;
    D_800A2FA4 = file;
    ResetCallback();
    if (D_800A2F94 != 0) {
        D_800A345C = 100;
    } else {
        D_800A345C = 30;
    }
    D_800A3124 = file;
    D_800A3254 = dest;
    if (((CdFileEntry *)D_800A2C0C)[(s16)file].size == 0) {
        func_8003E490();
    }
    CdControl(0x15, ((CdFileEntry *)D_800A2C0C)[(s16)file].loc, 0);
    D_800A2F94 = 0;
}

typedef struct {
    s16 unk0;
    s16 next;
    u8 pad4[0x20];
    s16 *file;
} Unk8003E970;

extern s16 D_800A2FFC;
extern s16 D_800A2F54;
extern void *D_800A310C;
extern void *D_800A3154;
extern s16 D_800809E4[];
extern struct Unk800584A4 *D_800A3564;
extern volatile s16 D_800A2F94;
extern void *func_8001FE84(s32 size);
extern void CdReadCallback(void (*func)());
extern void func_8003E47C();
extern void func_8003F9F8();

void func_8003E85C(void) {
    Unk8003E970 *data;

    D_800A2FFC = 0;
    data = (Unk8003E970 *)D_800A317C->vals;
    D_800A2F54 = 7;
    D_800A33E4 = D_800A310C;
    D_800A3154 = func_8001FE84(0x8400);
    D_800A340C = func_8001FE84(0x10000);
    D_800A30B4 = func_8001FE84(0xF0);
    D_800A3564 = func_8001FE84(D_800809E4[D_800A307C] * 180);
    D_800A2F94 = -1;
    CdReadCallback(func_8003E47C);
    func_8003E77C(D_800A33E4, D_800A307C + 0x55);
    data->unk0 = 0;
    D_800A34A4 = func_8003F9F8;
    D_800A317C->func = func_8003E4E8;
}

void func_8003E970(void) {
    Unk8003E970 *data = (Unk8003E970 *)D_800A317C->vals;
    s16 *file = data->file;
    s16 end = *file;
    s16 done = 0;
    s16 i;

    if (data->next + 50 < *file) {
        end = data->next + 50;
    } else {
        done = -1;
    }
    for (i = data->next; i < end; i++) {
        D_801D70F0[i] = (s32)D_800A33E4;
        D_800A33E4 = func_8003219C(func_8003E414(file, i), D_800A33E4);
    }
    data->next = end;
    if (done) {
        D_800A317C->func = func_8003F9F8;
    }
}

extern u16 *D_800A3004;
extern u16 *D_800A2F5C;
extern u16 D_800A79FE;

void func_8003EA9C(void *file) {
    u16 *p;

    D_800A3004 = p = func_8003E414(file, 0);
    D_800A2F5C = p + 3;
    D_800A79FE = *p;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003EAE0);

extern u32 func_8003E42C(void *, s16);

void func_8003EEA8(void *file) {
    Unk80043CC4 *node;
    u32 count;
    u32 n;
    s16 i;

    D_800A3084 = func_8003E414(file, 1);
    count = func_8003E42C(file, 1) >> 5;
    i = 0;
    while (1) {
        n = count--;
        if (n == 0) break;
        node = &D_800A3084[i];
        i++;
        node->x -= D_800A79F0.x << 9;
        node->z -= D_800A79F0.z << 9;
        node->unkE[0] = 0;
        node->unkE[1] = 0;
        node->unkE[2] = 0;
        node->unkE[3] = 0;
    }
    D_800A31DC = i;
}

typedef struct {
    u16 n;
    s32 off;
} Unk8003EF64_Entry;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u16 unkA;
} Unk8003EF64_Def;

extern u8 *D_800A2F1C;
extern u8 *D_800A32EC;
extern u16 D_800A30BC;
extern u16 D_800A3434;

void func_8003EF64(void *file) {
    Unk8003EF64_Entry *hdr;
    u16 *src;
    s16 i;

    hdr = func_8003E414(file, 4);
    D_800A3474 = (u8 *)hdr + hdr[0].off;
    D_800A2F1C = (u8 *)hdr + hdr[1].off;
    src = (u16 *)((u8 *)hdr + hdr[2].off);
    D_800A32EC = (u8 *)hdr + hdr[3].off;
    D_800A2F6C = hdr[0].n;
    D_800A30BC = hdr[1].n;
    D_800A3434 = hdr[3].n;
    D_800A324C = hdr[2].n;
    for (i = 0; i < D_800A324C; i++) {
        ((Unk8003EF64_Def *)D_800A30B4)[i].unk0 = src[0] * 0x2C;
        ((Unk8003EF64_Def *)D_800A30B4)[i].unk2 = src[1] * 0x2C;
        ((Unk8003EF64_Def *)D_800A30B4)[i].unk4 = src[2] * 0x2C;
        ((Unk8003EF64_Def *)D_800A30B4)[i].unk6 = src[3] * 0x2C;
        ((Unk8003EF64_Def *)D_800A30B4)[i].unk8 = src[4] * 0x2C;
        ((Unk8003EF64_Def *)D_800A30B4)[i].unkA = src[5];
        src += 6;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8003F0E4);

typedef struct {
    s16 step;
    s16 unk2;
    u8 pad4[0x20];
    void *unk24;
    u16 *unk28;
} Unk8003F9F8;

extern void func_80040010(void *file);
extern s32 SpuIsTransferCompleted(s32 flag);
extern s16 D_801D72F0[];
extern void func_8003EAE0(void *file);
extern s32 *D_800A32B4;
extern s32 D_800A2FDC;
extern void func_800418DC(void *file);
extern s16 D_800A3074;
extern void func_8003F0E4(void);

void func_8003F9F8(void) {
    Unk8003F9F8 *d = (Unk8003F9F8 *)D_800A317C->vals;
    s16 i;

    switch (d->step) {
    case 0:
        func_80040010(D_800A33E4);
        break;
    case 1:
        D_800A339C = func_800504F0(0x28, func_8003E414(D_800A33E4, 4));
        break;
    case 2:
        if (SpuIsTransferCompleted(0) == 0) {
            return;
        }
        for (i = 0; i < 32; i++) {
            D_801D72F0[i] = 0;
        }
        d->unk2 = 0;
        d->unk24 = func_8003E414(D_800A33E4, 3);
        D_800A317C->func = func_8003E970;
        break;
    case 3:
        func_8003E77C(D_800A33E4, D_800A307C + 0x6E);
        D_800A34A4 = func_8003F9F8;
        D_800A317C->func = func_8003E4E8;
        break;
    case 4:
        func_8003EA9C(D_800A33E4);
        break;
    case 5:
        func_8003EAE0(D_800A33E4);
        break;
    case 6:
        func_8003EEA8(D_800A33E4);
        break;
    case 7:
        D_800A32B4 = func_8003E414(D_800A33E4, 6);
        D_800A2FDC = (s32)func_8003E414(D_800A33E4, 7);
        func_800418DC(D_800A33E4);
        break;
    case 8:
        func_8003EF64(D_800A33E4);
        break;
    case 9:
        d->unk2 = 0;
        d->unk28 = func_8003E414(D_800A33E4, 8);
        D_800A3074 = *d->unk28;
        if (D_800A3074 != 0) {
            D_800A301C = 0;
            d->unk28 += 2;
            D_800A317C->func = func_8003F0E4;
        }
        break;
    case 10:
        D_800A31B4 = func_8003E414(D_800A33E4, 5);
        D_800A33E4 = func_8003E414(D_800A33E4, 8);
        *(s32 *)((struct Task *)D_801F7D24)->vals = 0;
        D_800A2FEC = -1;
        D_800A303C = 0;
        D_800A2F54 = 6;
        func_80021554();
        break;
    }
    d->step++;
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AC90);

extern void LoadTPage(void *pix, s32 tp, s32 abr, s16 x, s32 y, s32 w, s32 h);

void func_8003FCC8(void) {
    s16 i;
    s16 x;
    s32 y;
    u8 *pix;

    pix = func_8003E414(D_800A33E4, 3);
    x = 0x280;
    i = 0;
    y = 0x100;
    for (; i < 3; i++) {
        LoadTPage(pix, 0, 0, x, y, 0x100, 0x100);
        pix += 0x8000;
        x -= 0x40;
    }
}

typedef struct {
    u8 u0, v0;
    u16 clut;
    u8 u1, v1;
    u16 tpage;
    u8 u2, v2;
    u16 padA;
    u8 u3, v3;
    u16 padE;
    u8 u4, v4;
    u16 tpage2;
    u8 u5, v5;
    u16 tpage1;
    u16 clut2;
    u16 pad1A;
    u16 cluts[8];
} Unk8003FD70_Tex;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 pad12;
    Unk8003FD70_Tex *unk14;
    u16 *unk18;
    s32 pad1C;
    u8 *unk20;
} Unk8003FD70;

extern u16 GetClut(s32 x, s32 y);
extern u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);

void func_8003FD70(void) {
    Unk8003FD70 *d = (Unk8003FD70 *)D_800A317C->vals;
    Unk8003FD70_Tex *e;
    u8 u, v;
    s16 i, j, k;
    s16 idx;

    e = d->unk14;
    v = 0;
    if (d->unk2 >= 3) {
        LoadTPage(d->unk20, 0, 0, d->unk8, d->unkA, 0x100, 0x100);
        d->unk20 += 0x8000;
    }
    u = 0;
    for (i = 0; i < 64; i++) {
        e->u5 = u;
        e->u4 = u;
        e->u0 = u;
        e->v5 = v;
        e->v4 = v;
        e->v0 = v;
        e->u1 = u + 0x1F;
        e->v1 = v;
        e->u2 = u;
        e->v2 = v + 0x1F;
        e->u3 = u + 0x1F;
        e->v3 = v + 0x1F;
        u += 0x20;
        if (u == 0) {
            v += 0x20;
        }
        idx = d->unk18[d->unk6];
        d->unkC = (idx & 1) * 160 + 0x2C0;
        d->unkE = (idx >> 1) + 0x100;
        e->clut = GetClut(d->unkC, d->unkE);
        e->clut2 = GetClut(d->unkC + 16, d->unkE);
        e->tpage = GetTPage(0, 0, d->unk8, d->unkA);
        e->tpage2 = GetTPage(0, 2, d->unk8, d->unkA);
        e->tpage1 = GetTPage(0, 1, d->unk8, d->unkA);
        e->u4 = e->u5 = e->u1;
        e->v4 = e->v5 = e->v1;
        for (j = 0, k = 0x20; k < 0xA0; k += 0x10) {
            e->cluts[j++] = GetClut(d->unkC + k, d->unkE);
        }
        e++;
        d->unk6++;
    }
    d->unk8 -= 0x40;
    if (d->unk8 < 0) {
        d->unk8 = 0x3C0;
        d->unkA = 0;
    }
    d->unk14 = e;
    d->unk2++;
    if (d->unk2 >= d->unk10) {
        D_800A317C->func = func_8003F9F8;
    }
}

typedef struct {
    u8 pad0[0xA];
    u16 unkA;
} Unk80040010_Hdr;

typedef struct {
    s16 pad0;
    s16 unk2;
    s16 pad4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    void *unk14;
    Unk80040010_Hdr *hdr;
    u16 *map;
    void *unk20;
} Unk80040010;

extern s16 D_800C38C8[];
extern void func_80040160(void);

void func_80040010(void *file) {
    Unk80040010 *data = (Unk80040010 *)D_800A317C->vals;
    s16 i;
    s16 j;

    data->map = func_8003E414(file, 0);
    data->hdr = func_8003E414(file, 1);
    data->unk12 = func_8003E42C(file, 0) >> 5;
    data->unk10 = func_8003E42C(file, 1) >> 7;
    data->unk20 = func_8003E414(file, 2);
    data->unk8 = 0x280;
    data->unkA = 0x100;
    data->unkC = 0x2C0;
    data->unkE = 0x100;
    data->unk2 = 0;
    data->unk6 = 0;
    data->unk14 = D_800A3154;
    D_800A317C->func = func_80040160;
    j = data->hdr->unkA << 4;
    for (i = 0; i < 16; i++) {
        if (data->map[j++] == 0xFFFF) {
            D_800C38C8[i] = 0x7000;
        } else {
            D_800C38C8[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80040160);

typedef struct {
    SVECTOR pos;
    SVECTOR rot;
    SVECTOR unk10;
    VECTOR scale;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
} Unk800403C8;

extern Unk8007C268 D_8007C268[];
extern u16 D_80080B8C[];
extern void func_80040620();

void func_800403C8(void) {
    Unk800403C8 *d = (Unk800403C8 *)func_80021264(func_80040620, 2, 0x38)->data;

    d->pos.vx = 0;
    d->pos.vy = 0x56;
    d->pos.vz = 0;
    d->rot.vx = 0;
    d->rot.vy = 0;
    d->rot.vz = 0;
    d->unk10.vx = 0;
    d->unk10.vy = 0;
    d->unk10.vz = 0;
    d->scale.vx = 0x2000;
    d->scale.vy = 0x2000;
    d->scale.vz = 0x2000;
    d->unk30 = 0;
    d->unk32 = 0;
    d->unk34 = 0;
    if (D_800A307C == 0) {
        d->unk28 = 10;
    } else {
        d->unk28 = D_8007C268[D_800A307C - 1].unk0;
    }
    if (D_800A2F14 != 0) {
        d->unk2A = 21;
    } else {
        d->unk2A = D_8007C268[D_800A307C].unk0;
    }
    d->unk2C = 10;
    d->unk2E = 0;
    D_800A3194.vx = 0x800;
    D_800A3194.vy = 0x137C - D_80080B8C[d->unk2A] * 2;
    if (d->unk2A >= 10) {
        D_800A3194.vy = D_80080B8C[d->unk2A] * 2 - 0x800;
    } else {
        D_800A3194.vy = D_80080B8C[d->unk2A] * 2 + 0x800;
    }
    D_800A3194.vz = 0;
    D_800A34B4.vx = 0;
    D_800A34B4.vy = D_80080B8C[d->unk2A] * 2;
    D_800A34B4.vz = 0;
    func_80028E14((Unk8002A35C *)&D_800A34B4, (Unk8002A35C *)&D_800A3194, (Unk8002A35C *)&D_800A3544);
    D_800A3194.vx = 0;
    D_800A3194.vz = -7000;
    D_800A2A20 = 0x1800;
    d->unk36 = D_800A3544.vx;
    D_800A2FC4.vx = 0;
    D_800A2FC4.vy = 0;
    D_800A2FC4.vz = 0;
    D_800A2FC4.vy = 0;
    D_800A2FC4.vz = 0;
    func_80021BE4();
    D_800A2FC4.vy = -D_800A2FC4.vy;
    D_800A2FC4.vz = -D_800A2FC4.vz;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80040620);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007ACA0);

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
} POLY_F3;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    s32 xy3;
} POLY_F4;

extern s32 func_800711AC(s32 sxy0, s32 sxy1, s32 sxy2);

void func_80040C68(SVECTOR **v, s16 shade) {
    POLY_F4 *prim = D_800A3374;
    u32 *ot;

    D_800A326C = RotTransPers4(v[3], v[2], v[1], v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800A2EFC, &D_800A3394);
    D_800A326C = func_800293A4();
    if (D_800A326C >= 8) {
        if (func_800711AC(prim->xy0, prim->xy1, prim->xy3) <= 0) {
            shade >>= 1;
        }
        prim->r0 = shade;
        prim->g0 = shade;
        prim->b0 = shade;
        setlen(prim, 5);
        setcode(prim, 0x2A);
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

void func_80040D98(SVECTOR **v, u8 shade) {
    POLY_F3 *prim = D_800A3374;
    u32 *ot;

    if (RotNclip3(v[2], v[1], v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0) {
        D_800A326C = func_800292FC();
        if (D_800A326C >= 8) {
            prim->r0 = shade;
            prim->g0 = shade;
            prim->b0 = shade;
            setlen(prim, 4);
            setcode(prim, 0x20);
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    s32 xy3;
    u32 pad;
} LINE_F4;

void func_80040E94(SVECTOR **v, s16 shade) {
    LINE_F4 *prim = D_800A3374;
    u32 *ot;

    D_800A326C = RotTransPers4(v[3], v[2], v[1], v[0], &prim->xy0, &prim->xy1, &prim->xy2, &prim->xy3, &D_800A2EFC, &D_800A3394);
    D_800A326C = func_800293A4();
    if (D_800A326C >= 8) {
        if (func_800711AC(prim->xy0, prim->xy1, prim->xy2) > 0) {
            prim->r0 = 0;
            prim->g0 = 0x40 - shade;
            prim->b0 = shade;
        } else {
            prim->r0 = 0;
            prim->g0 = 0x20 - (shade >> 1);
            prim->b0 = shade >> 1;
        }
        setcode(prim, 0x4C);
        setlen(prim, 6);
        setSemiTrans(prim, 1);
        prim->pad = 0x55555555;
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrim(ot, prim);
        }
        prim++;
        D_800A3374 = prim;
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    u32 pad;
} LINE_F3;

void func_80040FF4(SVECTOR **v, u8 shade) {
    LINE_F3 *prim = D_800A3374;
    u32 *ot;

    if (RotNclip3(v[2], v[1], v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800A2EFC, &D_800A326C, &D_800A3394) > 0) {
        D_800A326C = func_800292FC();
        if (D_800A326C >= 8) {
            s16 c = shade;
            prim->r0 = 0;
            prim->g0 = ~c;
            prim->b0 = c;
            setlen(prim, 5);
            setcode(prim, 0x48);
            prim->pad = 0x55555555;
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrim(ot, prim);
            }
            prim++;
            D_800A3374 = prim;
        }
    }
}

typedef struct {
    char pad0[0x12];
    s16 unk12;
    char pad14[0x80];
    Unk80041178 sub;
} Unk80041104;

void func_80041104(Unk80041104 *p) {
    Unk80041178List *list = D_801F7D28->list;

    list->entries[list->count].id = D_800A317C->id;
    list->entries[list->count].obj = &p->sub;
    list->count++;
    p->sub.unk10 = 0;
    p->sub.unk12 = 0;
    p->sub.unk14 = 0;
    p->sub.unk2C = 0;
    p->sub.unk2E = 0;
    p->sub.unkA = -p->unk12;
}

void func_80041178(Unk80041178 *o) {
    Unk80041178List *list = D_801F7D28->list;

    list->entries[list->count].id = D_800A317C->id;
    list->entries[list->count].obj = o;
    list->count++;
    o->unk2A = 0;
    o->unk10 = 0;
    o->unk12 = 0;
    o->unk14 = 0;
    o->unk2C = 0;
    o->unkA = 0;
}

void func_8004121C(void);

void func_800411E4(void) {
    void *task = func_80021264(func_8004121C, 1, 0x144);
    Unk80041178List *list;

    D_801F7D28 = task;
    list = *(Unk80041178List **)((u8 *)task + 0x1C);
    list->count = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004121C);

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 r1, g1, b1, p1;
    s16 x1, y1;
} LINE_G2;

extern void SetLineG2(LINE_G2 *p);

void func_8004161C(SVECTOR *a, SVECTOR *b, s16 color) {
    LINE_G2 *line = D_800A3374;
    SVECTOR d;
    s16 dx;
    s16 dz;
    u32 *ot;

    dx = a->vx - D_800A3194.vx;
    dz = a->vz - D_800A3194.vz;
    if ((dx < 0 ? -dx : dx) > 0x3000 || (dz < 0 ? -dz : dz) > 0x3000) {
        return;
    }
    PushMatrix();
    D_800A349C.vx = a->vx - D_800A3194.vx;
    D_800A349C.vy = a->vy - D_800A3194.vy;
    D_800A349C.vz = a->vz - D_800A3194.vz;
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    SetRotMatrix(&D_801C0B64);
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    RotTransPers((SVECTOR *)&D_800A2A10, (s32 *)&line->x0, &D_800A2EFC, &D_800A3394);
    d.vx = b->vx - a->vx;
    d.vy = b->vy - a->vy;
    d.vz = b->vz - a->vz;
    RotTransPers(&d, (s32 *)&line->x1, &D_800A2EFC, &D_800A3394);
    PopMatrix();
    SetLineG2(line);
    switch (color) {
    case 0:
        line->r0 = 0xFF;
        line->g0 = 0xFF;
        line->b0 = 0xFF;
        break;
    case 1:
        line->r0 = 0xFF;
        line->g0 = 0;
        line->b0 = 0;
        break;
    case 2:
        line->r0 = 0;
        line->g0 = 0xFF;
        line->b0 = 0;
        break;
    case 3:
        line->r0 = 0;
        line->g0 = 0;
        line->b0 = 0xFF;
        break;
    case 4:
        line->r0 = 0xFF;
        line->g0 = 0xFF;
        line->b0 = 0;
        break;
    case 5:
        line->r0 = 0;
        line->g0 = 0xFF;
        line->b0 = 0xFF;
        break;
    default:
        line->r0 = 0xFF;
        line->g0 = 0;
        line->b0 = 0xFF;
        break;
    }
    line->r1 = 0x40;
    line->g1 = 0x40;
    line->b1 = 0x40;
    ot = D_800A32E4 + 12;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, line++);
    }
    D_800A3374 = line;
}

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[0x32];
} Unk800418DC;

extern Unk800418DC *D_800A300C;
extern s16 D_800A32FC;
extern u16 D_80080A18[];
extern s32 *D_800A32B4;
extern s32 D_800A2FDC;

void func_800418DC(void *file) {
    s16 corners[8][2] = {
        { 64, 64 }, { -64, 64 }, { -64, -64 }, { 64, -64 },
        { 128, 128 }, { -128, 128 }, { -128, -128 }, { 128, -128 },
    };
    u8 *hdr;
    s16 dx, dy, dz;
    u32 i;

    hdr = func_8003E414(file, 2);
    D_800A300C = (Unk800418DC *)(hdr + 0x28);
    D_800A32FC = ((s16 *)hdr)[2];
    switch (D_800A307C) {
    case 6:
    case 17:
    case 23:
        dx = 0;
        dy = 0x600;
        dz = 0;
        break;
    case 4:
    case 10:
    case 14:
    case 20:
        dx = 0;
        dy = 0;
        dz = 0x200;
        break;
    default:
        dx = 0;
        dy = 0;
        dz = 0;
        break;
    }
    dy += D_80080A18[D_800A307C];
    for (i = 0; i < D_800A32FC; i++) {
        D_800A300C[i].x += dx;
        D_800A300C[i].y += dy;
        D_800A300C[i].z += dz;
    }
    for (i = 0; i < 0x400; i++) {
        D_800A32B4[i] += D_800A2FDC;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80041AB4);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80041C48);

extern short D_800A2F3C;
extern Obj *D_800A5E90[];

void func_80042538(Obj *o) {
    D_800A5E90[D_800A2F3C] = o;
    o->f2C = 0;
    o->f2A = 0;
    D_800A2F3C++;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80042570);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AD3C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80042DD0);

extern void func_8004161C(SVECTOR *a, SVECTOR *b, s16 c);

void func_800430AC(Obj *obj, s16 arg1) {
    struct { s32 x; s32 z; } p[4];
    SVECTOR a;
    SVECTOR b;
    SVECTOR c;
    SVECTOR d;
    s16 ang;
    s32 w;
    s32 h;
    s16 cs;
    s16 sn;
    s32 cw;
    s32 sh;
    s32 ch;
    s32 sw;
    s32 dx;
    s32 dz;
    s16 i;

    ang = obj->fA;
    w = obj->f18;
    cs = D_800854C0[(ang + 0x400) & 0xFFF];
    cw = cs * w;
    sn = D_800854C0[(ang + 0x800) & 0xFFF];
    sh = sn * obj->f20;
    ch = cs * obj->f20;
    sw = sn * w;
    dx = (cw + sh) >> 12;
    p[0].x = obj->x - dx;
    dz = (sw - ch) >> 12;
    p[0].z = obj->z - dz;
    p[2].x = obj->x + dx;
    p[2].z = obj->z + dz;
    dx = (cw - sh) >> 12;
    p[1].x = obj->x - dx;
    dz = (sw + ch) >> 12;
    p[1].z = obj->z - dz;
    p[3].x = obj->x + dx;
    p[3].z = obj->z + dz;
    i = 0;
    do {
        a.vy = b.vy = obj->y;
        c.vy = d.vy = obj->y + obj->f1C;
        a.vx = c.vx = p[i].x;
        a.vz = c.vz = p[i].z;
        b.vx = d.vx = p[(i + 1) % 4].x;
        b.vz = d.vz = p[(i + 1) % 4].z;
        func_8004161C(&a, &b, arg1);
        func_8004161C(&a, &c, arg1);
        func_8004161C(&c, &d, arg1);
        i++;
    } while (i < 4);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80043308);

extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern void func_800430AC(Obj *o, s16);
extern MATRIX D_801C0B64;

void func_800433F4(void) {
    SVECTOR unused;
    short i;

    if (D_800A2F3C != 0) {
        SetRotMatrix(&D_801C0B64);
        SetTransMatrix(&D_801C0B64);
        for (i = 0; i < D_800A2F3C; i++) {
            func_800430AC(D_800A5E90[i], 2);
        }
    }
}

typedef struct {
    s16 x, y, z;
    u8 pad6[4];
    s16 angle;
    u8 padC[0xC];
    s32 w;
    s32 h;
    s32 d;
    u8 pad24[0x14];
} Unk80043498_Box;

extern Unk80043CC4 *D_800A3084;
extern u8 D_800A2A34[];
extern u8 D_800A2A38[];
extern u8 D_800A2A3C[];
extern u8 D_800A2A4C[];
extern s16 func_80023E80(void *obj, s32 *a, s32 *b);
extern void func_800545BC(short x, short y, int value, int d, int a, u8 *b, u8 *c);

void func_80043498(s16 n, s16 side) {
    Unk80043498_Box box;
    SVECTOR from;
    s16 x[2] = {280, 40};
    u8 *col[2] = {D_800A2A3C, D_800A2A4C};
    s16 kind[2] = {1, 4};
    s32 tmp;
    s16 i;
    s16 k;

    box.x = from.vx = D_800A3084[n].x;
    box.y = 0x400;
    box.z = from.vz = D_800A3084[n].z;
    box.y = from.vy = func_80023E80(&box, &tmp, &tmp);
    box.w = 0x40 << side;
    box.h = 0x400;
    box.d = 0x40 << side;
    box.angle = 0;
    from.vy += 0x200;
    func_800430AC((Obj *)&box, kind[side]);
    func_800545BC(x[side], 0x40, n, 0x600, 0x200, col[side], D_800A2A34);
    if (side == 0) {
        for (i = 0; i < 4; i++) {
            k = D_800A3084[n].links[i];
            if (k != -1) {
                func_800545BC(x[side], i * 16 + 0x50, k, 0x600, 0x200, D_800A2A38, D_800A2A34);
                box.x = D_800A3084[k].x;
                box.y = 0x400;
                box.z = D_800A3084[k].z;
                box.y = func_80023E80(&box, &tmp, &tmp);
                box.angle = 0;
                func_800430AC((Obj *)&box, 2);
                box.y += 0x200;
                func_8004161C(&from, (SVECTOR *)&box, 0);
            }
        }
    }
}

int func_800436E4(SVECTOR *pos, s16 arg1) {
    Unk800436E4_Probe probe;

    probe.x = pos->vx;
    probe.y = pos->vy;
    probe.z = pos->vz;
    probe.unkA = 0;
    probe.unk18 = arg1;
    probe.unk1C = 0x400;
    probe.unk20 = arg1;
    probe.hit = 0;
    probe.unk34 = 0;
    func_80042570(&probe);
    if (probe.hit != 0) {
        return -1;
    }
    func_80041C48(&probe);
    return -(probe.hit != 0);
}

s16 func_80043770(s16 x, s16 z) {
    return D_800A340C[(x << 8) + z];
}

void func_8004379C(short id, SVECTOR *out) {
    Unk80043CC4 *node = &D_800A3084[id];

    out->vx = node->x;
    out->vy = 0;
    out->vz = node->z;
}

s32 func_800437C8(s32 value, s32 target, s32 step) {
    s32 d = value - target;

    if (d == 0) {
        return value;
    }
    if (d < 0) {
        if (-d < step) {
            return target;
        }
        return value + step;
    }
    if (d < step) {
        return target;
    }
    return value - step;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80043814);

s32 func_80043858(SVECTOR *p, SVECTOR *a, SVECTOR *b) {
    s32 dot;
    s32 len;

    dot = ((p->vz - b->vz) * (p->vz - a->vz) - (p->vx - b->vx) * (a->vx - p->vx) + 0x800) >> 12;
    len = ((p->vx - a->vx) * (p->vx - a->vx) + (p->vz - a->vz) * (p->vz - a->vz) + 0x800) >> 12;
    if (len == 0) {
        return 0;
    }
    if (len + 0x800 < dot) {
        return -1;
    }
    if (dot < -0x800) {
        return -1;
    }
    return (dot << 12) / len;
}

typedef struct {
    s16 x;
    s16 pad2;
    s16 z;
} Unk80043930;

s32 func_80043930(Unk80043930 *a, Unk80043930 *b, Unk80043930 *c) {
    s32 ax = a->x;
    s32 az = a->z;
    s32 cross = (az - c->z) * (b->x - ax) - (ax - c->x) * (b->z - az);

    if (cross < 0) {
        cross = -cross;
    }
    return SquareRoot0(cross);
}

extern s16 D_800A3464;
extern s16 D_800A7F98[];

s16 func_800439A4(s16 exclude) {
    s16 i = 0;
    s16 idx = func_8001E9DC(D_800A3464);
    s16 id;

    while (1) {
        id = D_800A7F98[idx];
        if (id != exclude && D_800A3084[id].unk16 == 2) {
            return id;
        }
        idx = (idx + 1) % D_800A3464;
        if (++i >= 51) {
            return D_800A7F98[0];
        }
    }
}

s32 func_80043A90(SVECTOR *a, SVECTOR *b) {
    s32 dx = (a->vx - b->vx) >> 4;
    s32 dy = (a->vy - b->vy) >> 4;
    s32 dz = (a->vz - b->vz) >> 4;

    return SquareRoot0(dx * dx + dy * dy + dz * dz) << 4;
}

s32 func_80043B0C(SVECTOR *v) {
    return SquareRoot0(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE[2];
    s16 unk12;
    u8 pad14[0x14];
    s16 unk28;
    u8 pad2A[0x22];
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 pad52[0x12];
    u8 unk64[2];
    s16 unk66;
    u8 pad68[0x18];
    s16 unk80;
    u8 pad82[0x50];
    s16 unkD2;
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
    s16 unkDC;
    s16 unkDE;
    s16 unkE0;
    s16 unkE2;
    s16 unkE4;
    u8 padE6[0xE];
    s16 unkF4;
    u8 padF6[0xE];
    s16 unk104;
    u8 pad106[0xC];
    s16 unk112;
    s16 unk114;
    s16 unk116;
    s16 unk118;
    u8 pad11A[0xC];
    s16 unk126;
    u8 pad128[0x2A];
    s16 unk152;
} Obj80047314;

void func_8004379C(short id, SVECTOR *out);

s32 func_80043B6C(Unk8002A35C *out, Obj80047314 *obj) {
    SVECTOR b;
    SVECTOR a;
    s32 dist;

    func_8004379C(obj->unkD6, &a);
    func_8004379C(obj->unkD8, &b);
    out->x = func_800296F8(a.vx, b.vx, obj->unkD4);
    out->y = func_800296F8(a.vy, b.vy, obj->unkD4);
    out->z = func_800296F8(a.vz, b.vz, obj->unkD4);
    dist = func_8002A35C(out, (Unk8002A35C *)obj);
    out->x += func_800296F8(obj->unkDE, 0, dist * 2);
    out->z += func_800296F8(obj->unkE0, 0, dist * 2);
    return dist;
}

s16 func_80043C60(s16 exclude) {
    s16 idx;

    do {
        do {
            idx = func_8001E9DC(D_800A31DC);
        } while (idx == exclude);
    } while (D_800A3084[idx].unk16 == 3);
    return idx;
}

s16 func_80043CC4(s16 idx) {
    Unk80043CC4 *node;
    Unk80043CC4 *nodes;
    s16 tries = 0;
    s16 dir = func_8001E9DC(4);
    s16 next;

    nodes = D_800A3084;
    node = &D_800A3084[idx];
retry:
    next = node->links[dir];
    if (next != -1 && nodes[next].unk16 != 3) {
        return next;
    }
    dir = (dir + 1) & 3;
    if (++tries < 7) {
        goto retry;
    }
    return node->links[0];
}

short func_80043D68(short a, short b, short scale) {
    SVECTOR va;
    SVECTOR vb;
    int d;

    func_8004379C(a, &va);
    func_8004379C(b, &vb);
    d = func_80043A90(&vb, &va);
    return d != 0 ? (scale << 12) / d : 0x1000;
}

extern MATRIX *RotMatrix(SVECTOR *r, MATRIX *m);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX D_801FB868;
extern MATRIX *func_80023C7C(SVECTOR *r, MATRIX *m);

void func_80043E14(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80023C7C(rot, &D_801FB868);
    ApplyMatrix(&D_801FB868, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80043EA8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AD98);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80044470);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004475C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80044B74);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80044E9C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007ADB0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007ADC8);

extern void func_8003E384(Unk80045164 *obj);
extern void func_80031320(Unk80045164 *obj);
extern s16 func_80023E80(void *obj, s32 *a, s32 *b);
extern s32 func_8004BF0C(Unk8002A35C *pos);
extern void func_8004525C(void);
extern void func_8004BFB8(void);

void func_80045164(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    s16 tmp;

    func_8003E384(obj);
    func_8002A270(&obj->pos, 4);
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320(obj);
    obj->unkEC = func_8001E9DC(4) + 1;
    obj->unkEE = 0;
    D_800A317C->func = func_8004525C;
    if (obj->unk158 == 0 && (s16)func_8004BF0C(&obj->pos) != 0) {
        if ((s16)func_8001E9DC(2) != 0) {
            tmp = 0x2A;
        } else {
            tmp = 0x2B;
        }
        func_80024DA8(&obj->anim, tmp, 0, 0x52, 8);
        D_800A317C->func = func_8004BFB8;
    }
}

extern void func_80049064(Unk80045164 *obj, s16 flag);
extern s16 func_80042DD0();
extern s16 func_80043814(s16 from, s16 to, s32 step);
extern void func_80045478(void);

void func_8004525C(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    Unk8002A35C *target;
    u16 *anim;
    s16 angle;
    s16 tmp;

    func_8003E384(obj);
    func_8002A270(&obj->pos, 4);
    if (obj->unk158 == 0) {
        func_80024EF0(&obj->anim);
    }
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320(obj);
    if (obj->unk124 == NULL) {
        D_800A317C->func = D_800A317C->saved;
        return;
    }
    target = (Unk8002A35C *)obj->unk124->vals;
    if (obj->unk158 == 0 && (s16)func_8004BF0C(&obj->pos) != 0) {
        if ((s16)func_8001E9DC(2) != 0) {
            tmp = 0x2A;
        } else {
            tmp = 0x2B;
        }
        func_80024DA8(&obj->anim, tmp, 0, 0x52, 8);
        D_800A317C->func = func_8004BFB8;
        return;
    }
    anim = (u16 *)D_800A353C[obj->anim.id].p;
    func_80049064(obj, 0);
    if (obj->unk158 != 0) {
        obj->unk158--;
        return;
    }
    if (obj->unkF0 != 0) {
        obj->unkF0--;
    }
    angle = func_80028B04(target, &obj->pos) - 0x400;
    obj->model.unk12 = angle & 0xFFF;
    if (obj->model.rot.vy == obj->model.unk12 && obj->anim.time >= anim[11]) {
        if (func_80042DD0(obj, target, -1) == 0) {
            func_80024DA8(&obj->anim, 0xF, 0, 0xA4, 3);
            D_800A317C->func = D_800A317C->saved;
        } else {
            D_800A317C->func = func_80045478;
        }
        return;
    }
    obj->model.rot.vy = func_80043814(obj->model.rot.vy, angle, 0xA0);
}


void func_80045478(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    s32 params[6];
    s16 tmp;

    func_8003E384(obj);
    obj->model.rot.vy = func_80043814(obj->model.rot.vy, obj->model.unk12, 0xA0);
    func_8002A270(&obj->pos, 4);
    if (obj->unk158 == 0) {
        func_80024EF0(&obj->anim);
    }
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320(obj);
    if (obj->unk158 == 0 && (s16)func_8004BF0C(&obj->pos) != 0) {
        if ((s16)func_8001E9DC(2) != 0) {
            tmp = 0x2A;
        } else {
            tmp = 0x2B;
        }
        func_80024DA8(&obj->anim, tmp, 0, 0x52, 8);
        D_800A317C->func = func_8004BFB8;
        return;
    }
    func_80049064(obj, 0);
    if (obj->unk158 != 0) {
        obj->unk158--;
        return;
    }
    obj->unkF0 = 2;
    obj->unkEE = -1;
    obj->unk156 = -1;
    func_80056ADC((SVECTOR *)obj, 0x800);
    obj->model.rot.vy += 0x400;
    func_800369FC(obj, 1, 0, 0, 0);
    obj->model.rot.vy -= 0x400;
    params[0] = 6;
    params[1] = func_80050974((SVECTOR *)obj, 0x3FFF);
    params[2] = func_800508F0((SVECTOR *)obj) * 4;
    params[3] = 0x400;
    params[4] = 0;
    params[5] = 0;
    func_8004FB78(params);
    func_80024DA8(&obj->anim, 0xF, 0, 0xA4, 3);
    D_800A317C->func = D_800A317C->saved;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004566C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007ADD8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AE00);

extern void func_80039518(Unk80045EF4 *obj);
extern s16 func_80024EF0(Anim *anim);

s16 func_80045EF4(Unk80045EF4 *obj, s32 speed) {
    s16 step;

    if (obj->unk12 == obj->unk22) {
        obj->anim.unk6 = 0xA4;
        obj->unk4C = 0;
        obj->unk4E = 0;
        obj->unk50 = func_80031C58(&obj->anim);
        func_80039518(obj);
        obj->pos.x += obj->unk3C;
        obj->pos.y += obj->unk40;
        obj->pos.z += obj->unk44;
        obj->prev.x = obj->pos.x;
        obj->prev.y = obj->pos.y;
        obj->prev.z = obj->pos.z;
        func_80024EF0(&obj->anim);
        step = func_800296F8(obj->anim.unk6 * 4, 1, (s16)((speed << 12) / 0x600));
        if (step < 0) {
            step = 0;
        }
        obj->unkD4 += step;
    } else {
        step = 0;
    }
    return step;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80046030);

extern const s16 D_8007C550[];
s16 func_80043C60(s16 exclude);
void func_80046030(void);

void func_80046598(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;
    SVECTOR unused[2];

    obj->unk12 = obj->unk112 = obj->unk116 << 9;
    obj->unkDC = func_80043C60(-1);
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    if (obj->unk114 != 0) {
        if (obj->unk28 == 11) {
            func_80024DA8(obj->unk64, 0x28, 0, 0xF6, 0);
            obj->unk28 = 7;
        } else {
            func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0x52, 0);
        }
    }
    D_800A317C->func = func_80046030;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004667C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AE28);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80046D2C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80046ED4);

void func_80046ED4(void);

void func_80047258(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;
    SVECTOR unused[2];

    obj->unk126 = 0;
    obj->unk114 <<= 9;
    if (obj->unk116 >= 0) {
        obj->unk116 += 0x10;
    } else {
        obj->unk116 = 0;
    }
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0x52, 0);
    D_800A317C->func = func_80046ED4;
}

s16 func_80043770(s16, s16);

void func_80047314(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;
    SVECTOR unused[2];

    obj->unk12 = obj->unk112 = obj->unk116 << 9;
    obj->unkDC = func_80043C60(-1);
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkD4 = 0;
    obj->unkDA = func_80043D68(obj->unkD6, obj->unkD8, obj->unkD2);
    obj->unkDE = 0;
    obj->unkE0 = 0;
    obj->unk4C = 0;
    obj->unk4E = 0;
    obj->unk50 = 0;
    obj->unk8 = obj->unk0;
    obj->unkA = obj->unk2;
    obj->unkC = obj->unk4;
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    func_80021554();
}

s32 func_800473CC(SVECTOR *out, Obj80047314 *obj, SVECTOR *target) {
    s32 dist;
    s32 t;

    out->vx = func_800296F8(obj->unk0, target->vx, obj->unkD4);
    out->vy = func_800296F8(obj->unk2, target->vy, obj->unkD4);
    out->vz = func_800296F8(obj->unk4, target->vz, obj->unkD4);
    dist = func_80043A90(out, (SVECTOR *)obj);
    t = dist * 2;
    out->vx += func_800296F8(obj->unkDE, 0, t);
    out->vz += func_800296F8(obj->unkE0, 0, t);
    return dist;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800474AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AE50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AE78);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AE88);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80047B68);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80047F7C);

void func_80047F7C(void);

void func_800482FC(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;

    obj->unk116 = 0;
    obj->unk114 *= 30;
    if (obj->unk118 > 0) {
        func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0x52, 0);
    } else {
        obj->unk118 = 0;
    }
    obj->unkDC = func_80043C60(obj->unkD6);
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    D_800A317C->func = func_80047F7C;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800483C8);

typedef struct {
    SVECTOR pos[20];
    s16 unkA0[20];
    s16 unkC8[20];
    s16 count;
} Unk80056ADC;

extern struct {
    u8 pad[0x1C];
    Unk80056ADC *unk1C;
} *D_801F7D70;

extern s16 func_80056B8C(Unk8002A35C *from, s16 range);
extern void func_80044E9C(void);

typedef struct {
    s16 timer;
    u8 pad2[0xE];
    s16 angle;
    s16 state;
    u8 pad14[0x2A];
    s16 heading;
} Unk800487B4_Sub;

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0xC];
    s16 rotY;
    u8 pad14[0x14];
    s16 unk28;
    u8 pad2A[0x3A];
    Anim anim;
    u8 pad84[0x5E];
    s16 unkE2;
    u8 padE4[0x20];
    s16 unk104;
    s16 unk106;
    s16 unk108;
    u8 pad10A[2];
    s16 unk10C;
    s16 unk10E;
    u8 pad110[4];
    union {
        Unk800487B4_Sub sub;
        u8 bytes[16];
    } u;
    u8 pad154[4];
    s16 unk158;
} Unk800487B4;

void func_800487B4(void) {
    Unk800487B4 *obj = (Unk800487B4 *)D_800A317C->vals;
    SVECTOR *pts = (SVECTOR *)D_801F7D70->unk1C;
    Unk800487B4_Sub *sub;
    s16 tmp;

    func_8003E384((Unk80045164 *)obj);
    func_8002A270(&obj->pos, 4);
    func_80031200((Unk80031200 *)obj);
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320((Unk80045164 *)obj);
    sub = &obj->u.sub;
    if (obj->unk158 == 0 && (s16)func_8004BF0C(&obj->pos) != 0) {
        if ((s16)func_8001E9DC(2) != 0) {
            tmp = 0x2A;
        } else {
            tmp = 0x2B;
        }
        func_80024DA8(&obj->anim, tmp, 0, 0x52, 8);
        D_800A317C->saved = D_800A317C->func;
        D_800A317C->func = func_8004BFB8;
        return;
    }
    if ((s16)func_800493D0(obj) != 0) {
        obj->unk104 = 0;
        obj->unkE2 = 5;
        obj->unk106 = 0;
        obj->unk108 = 100;
        obj->anim.unk1C = obj->unk104;
        sub->state = 1;
        D_800A317C->func = func_800487B4;
        D_800A317C->saved = D_800A317C->func;
        D_800A317C->func = func_80044E9C;
        return;
    }
    switch (sub->state) {
    case 0:
        if (obj->unk108 != 0) {
            obj->unk108--;
        } else {
            if (obj->unk104 != obj->unk106) {
                obj->unk104 = func_800437C8(obj->unk104, obj->unk106, 0x40);
            } else {
                obj->unk106 = (func_8001E9DC(3) - 1) << 10;
                obj->unk108 = func_8001E9DC(16) + 16;
            }
            obj->anim.unk1C = obj->unk104;
        }
        if (obj->unk10E == 0) {
            tmp = func_80056B8C(&obj->pos, obj->unk10C);
            if (tmp != -1) {
                obj->unk10E = 100;
                sub->angle = func_80028B04((Unk8002A35C *)&pts[tmp], &obj->pos);
                sub->state = 2;
                obj->unk104 = 0;
                obj->unk106 = 0;
                obj->unk108 = 32;
                obj->anim.unk1C = obj->unk104;
            } else if (obj->rotY != sub->heading) {
                sub->state = 1;
            }
        }
        break;
    case 1:
        obj->rotY = func_80043814(obj->rotY, sub->heading, 0x40);
        if (obj->rotY == sub->heading) {
            sub->state = 0;
        }
        break;
    case 2:
        obj->rotY = func_80043814(obj->rotY, sub->angle, 0x80);
        if (obj->rotY == sub->angle) {
            sub->state = 0;
        }
        break;
    }
    if (obj->unk10E != 0) {
        obj->unk10E--;
    } else {
        obj->unk10E = func_8001E9DC(4);
    }
    if (sub->timer != 0) {
        sub->timer--;
    } else {
        obj->unk28 = 7;
        for (tmp = 0; tmp < 16; tmp++) {
            obj->u.bytes[tmp] = 0;
        }
        obj->unk104 = 0;
        obj->anim.unk1C = 0;
        D_800A317C->func = func_80046030;
    }
    func_80049064((Unk80045164 *)obj, -1);
    func_80049744((Obj80047314 *)obj);
}

void func_800487B4();

void func_80048B50(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;

    obj->unk126 = 0;
    obj->unk152 = obj->unk12;
    obj->unk114 *= 30;
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    D_800A317C->func = func_800487B4;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80048BD4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AE98);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AEB0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AEC0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AED0);

extern s16 D_800A336C;
extern s16 D_800A61B4;
extern void func_80039858(void);
extern void func_8003B850(void);
extern void func_80049820(u32);

void func_80049064(Unk80045164 *obj, s16 flag) {
    s16 hit = obj->unk94.f2A;
    void (*prev)(void);

    if (hit == 0) {
        return;
    }
    if (hit < 0) {
        obj->unk158 = 200;
        if (flag != 0) {
            obj->unk94.f2A = 0;
            prev = D_800A317C->func;
            D_800A317C->func = func_8003B850;
            D_800A317C->saved = prev;
            return;
        }
    } else {
        obj->unkF2 -= hit;
        if (obj->unkF2 <= 0) {
            if (D_800A7A20[obj->unkCA].id == D_800A336C) {
                func_80049820(5000);
            } else {
                func_80049820(5);
            }
            D_800A61B4 = -1;
            D_800A317C->func = func_80039858;
            return;
        }
        if (obj->unk158 != 0) {
            obj->unk158 = 0;
        }
    }
    obj->unk94.f2A = 0;
}

extern s16 func_80039458(Unk80045164 *obj);
extern void func_800495F8(void);

void func_8004916C(Unk80045164 *obj, s32 dist) {
    s16 prev;

    if (obj->unkEA != 0) {
        obj->unkEA--;
    }
    if ((dist > 0x600 && obj->unkEA == 0) || (obj->unkDA > obj->unk160 && obj->unkEA == 0)) {
        obj->unkEA = func_8001E9DC(0x14) + 0x32;
        obj->unkD4 = 0;
        obj->unkDA = 0;
        obj->unk160 = func_8001E9DC(0x14) + 0x5A;
        prev = obj->unkD6;
        obj->unkD6 = func_80039458(obj);
        obj->unkD8 = func_80043770(obj->unkD6, func_80043CC4(obj->unkD6));
        if (prev == obj->unk162 && obj->unkD6 == prev) {
            if (++obj->unkE8 >= 2) {
                func_80024DA8(&obj->anim, D_8007C550[obj->unkF4], 0, 0x52, 8);
                obj->unkE8 = func_8001E9DC(0x3C) + 0xF;
                obj->unk94.f18 = 100;
                D_800A317C->saved = D_800A317C->func;
                D_800A317C->func = func_800495F8;
                return;
            }
        }
        obj->unk162 = prev;
    }
}

extern s16 D_800A322C;
extern s16 D_801C1EF6;

void func_800492F8(SVECTOR *pos) {
    s32 params[6];

    if (D_800A322C == 0 || --D_800A322C == 0) {
        params[0] = (s16)func_8001E9DC(2) + 0x39;
        params[1] = func_80050974(pos, 0x3FFF);
        params[2] = func_800508F0(pos) * 4;
        params[3] = (s16)func_8001E9DC(0x100) + 0x380;
        params[3] += D_801C1EF6;
        params[4] = 0;
        params[5] = 1;
        func_8004FB78(params);
        D_800A322C = func_8001E9DC(4);
    }
}

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0xC];
    u16 unk12;
    u8 pad14[0x14];
    s16 unk28;
    u8 pad2A[0xB8];
    s16 unkE2;
    s16 unkE4;
    u8 padE6[0x1E];
    u16 unk104;
    u8 pad106[4];
    s16 unk10A;
    u8 pad10C[0x1C];
    s16 unk128;
    u8 pad12A[0x2A];
    s16 unk154;
} Unk800493D0;

extern s16 func_80042DD0(Unk800493D0 *obj, Unk8002A35C *target, s32 arg2);
extern void func_8004566C(void);

s32 func_800493D0(Unk800493D0 *obj) {
    Unk8002A35C *target;
    s32 angle;

    if (D_801F7D50 != NULL) {
        target = (Unk8002A35C *)D_801F7D50->vals;
        if (--obj->unkE2 >= 0) {
            return 0;
        }
        obj->unkE2 = func_8001E9DC(10) + 10;
        if (obj->unk154 != 0 && obj->unk28 != 0x12) {
            return 0;
        }
        if (obj->unk28 == 0x12) {
            target = (Unk8002A35C *)D_801C08F8[obj->unk128];
        }
        angle = (func_80028B04(target, &obj->pos) - (obj->unk12 + obj->unk104)) << 20 >> 20;
        if (ABS(angle) < obj->unk10A) {
            if (func_80042DD0(obj, target, 0) == 0) {
                return 0;
            }
            func_800492F8((SVECTOR *)obj);
            obj->unkE4 = -1;
            D_800A317C->func = func_8004566C;
            return -1;
        }
    }
    return 0;
}

typedef struct {
    Unk80043930 pos;
    u8 pad6[0x5C];
    s16 unk62;
} Unk80049510;

s32 func_80049510(Unk80049510 *self) {
    Unk80041178List *list = D_801F7D28->list;
    Unk80043930 *ref;
    Unk80041178 *obj;
    s16 i;

    if (D_801F7D50 == NULL) {
        return 0;
    }
    ref = (Unk80043930 *)D_801F7D50->vals;
    func_8002A35C((Unk8002A35C *)ref, (Unk8002A35C *)self);
    for (i = 0; i < list->count; i++) {
        obj = list->entries[i].obj;
        if (((u8 *)obj)[0x37] != self->unk62 && func_80043930(&self->pos, ref, (Unk80043930 *)obj) < 0x400) {
            return -1;
        }
    }
    return 0;
}

extern const s16 D_8007C560[];

void func_800495F8(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    Anim *anim;
    s32 tmp;

    func_8003E384(obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031200((Unk80031200 *)obj);
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_8002A270(&obj->pos, obj->unk28 != 4 ? 4 : 0);
    anim = &obj->anim;
    func_80024EF0(anim);
    func_80031320(obj);
    if (obj->unk158 == 0 && (s16)func_8004BF0C(&obj->pos) != 0) {
        obj->unkE8 = 0;
        func_80024DA8(anim, D_8007C560[obj->unkF4], 0, 0x52, 8);
        obj->unk94.f18 = 200;
        D_800A317C->func = D_800A317C->saved;
    } else if (obj->unk94.f2A != 0) {
        obj->unkE8 = 0;
        func_80024DA8(&obj->anim, D_8007C560[obj->unkF4], 0, 0x52, 8);
        obj->unk94.f18 = 200;
        D_800A317C->func = D_800A317C->saved;
    } else if (--obj->unkE8 == 0) {
        func_80024DA8(&obj->anim, D_8007C560[obj->unkF4], 0, 0x52, 8);
        obj->unk94.f18 = 200;
        D_800A317C->func = D_800A317C->saved;
    }
}

extern s16 D_800A3274;
extern const s16 D_8007C560[];
void func_80047F7C(void);

void func_80049744(Obj80047314 *obj) {
    if (D_800A3274 >= 600) {
        obj->unk28 = 2;
        obj->unk114 = 0x7D00;
        obj->unk116 = 0;
        obj->unk118 = 0;
        if ((u16)obj->unk66 != (u16)D_8007C560[obj->unkF4]) {
            func_80024DA8(obj->unk64, D_8007C560[obj->unkF4], 0, 0x52, 8);
        }
        obj->unkDC = func_80043C60(obj->unkD6);
        obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
        obj->unkE2 = func_8001E9DC(0x14) + 0x14;
        obj->unkE4 = 0;
        obj->unk104 = 0;
        obj->unk80 = 0;
        D_800A317C->func = func_80047F7C;
    }
}

extern s32 D_801D2068[];
extern s32 D_801D206C;

void func_80049820(u32 arg0) {
    D_801D2068[1] += arg0;
}

void func_8004983C(void) {
    s32 step;

    if (D_801D206C != 0) {
        step = D_801D206C / 2;
        if (step == 0) {
            step = D_801D206C > 0 ? 1 : -1;
        }
        D_801D2068[0] += step;
        D_801D206C -= step;
        if (D_801D2068[0] < 0) {
            D_801D2068[0] = 0;
            D_801D206C = 0;
        }
    }
}

typedef struct {
    u8 pad[0x44];
    s16 unk44;
} Unk800498B0_Data;

extern void func_80049C9C();
extern s16 D_800A315C;
extern s16 D_801D2070;
extern s16 D_801D2072;
extern s16 D_801D2074;
extern s16 D_801D2076;
extern s16 D_801D2096;
extern s16 D_801D2098;
extern s16 D_801D209A;
extern s16 D_801D209E[];
extern s16 D_801D20A0;
extern s16 D_801D20A2;
extern s16 D_801D20A4;
extern s16 D_801D20A6;
extern s16 D_801D20A8;
extern s16 D_801D20AA;

void func_800498B0(void) {
    Unk800498B0_Data *data;

    data = (Unk800498B0_Data *)func_80021264(func_80049C9C, 1, 0x48)->data;
    if (D_800A315C != 0) {
        D_801D2068[0] = 0;
        D_801D2070 = 0;
        D_801D2072 = 0;
        D_801D2074 = 0;
        D_801D2076 = 0;
        D_801D20A2 = 12;
        D_801D209E[0] = 1;
        D_801D20A0 = 15;
        D_801D2096 = 0;
        D_801D209C = 2;
        D_801D20A6 = 2;
        D_801D20A8 = 0;
        D_801D20AA = 0;
    }
    D_801D2098 = 0;
    D_801D209A = 0x40;
    D_801D206C = 0;
    D_801D2078.count = 0;
    D_801D2078.idx = 0;
    D_801D2078.unk4 = 0;
    D_801D20A4 = 0;
    data->unk44 = 15;
}

typedef struct {
    u8 addr[3];
    u8 len;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 r1, g1, b1, p1;
    s16 x1, y1;
} Unk800499A4_Line;

void func_800499A4(u8 *c0, u8 *c1) {
    Unk800499A4_Line *p = D_800A3374;
    u32 *ot;
    s16 y = 0x25;

    p->x0 = 0x2C;
    p->y0 = y;
    p->x1 = 0x32;
    p->y1 = y + 6;
    p->r0 = c0[0];
    p->g0 = c0[1];
    p->b0 = c0[2];
    p->r1 = c1[0];
    p->g1 = c1[1];
    p->b1 = c1[2];
    p->len = 4;
    p->code = 0x50;
    ot = D_800A32E4 + D_800A3104;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    p->x0 = 0x2D;
    p->y0 = y;
    p->x1 = 0x33;
    p->y1 = y + 6;
    p->r0 = c0[0];
    p->g0 = c0[1];
    p->b0 = c0[2];
    p->r1 = c1[0];
    p->g1 = c1[1];
    p->b1 = c1[2];
    p->len = 4;
    p->code = 0x50;
    ot = D_800A32E4 + D_800A3104;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    p->x0 = 0x32;
    p->y0 = y;
    p->x1 = 0x2C;
    p->y1 = y + 6;
    p->r0 = c0[0];
    p->g0 = c0[1];
    p->b0 = c0[2];
    p->r1 = c1[0];
    p->g1 = c1[1];
    p->b1 = c1[2];
    p->len = 4;
    p->code = 0x50;
    ot = D_800A32E4 + D_800A3104;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    p->x0 = 0x33;
    p->y0 = y;
    p->x1 = 0x2D;
    p->y1 = y + 6;
    p->r0 = c0[0];
    p->g0 = c0[1];
    p->b0 = c0[2];
    p->r1 = c1[0];
    p->g1 = c1[1];
    p->b1 = c1[2];
    p->len = 4;
    p->code = 0x50;
    ot = D_800A32E4 + D_800A3104;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    D_800A3374 = p;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80049C9C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2ACC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AD0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AD4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AD8);

int func_8004A7C4(int a, int b, int c) {
    int t;

    if (b <= 0) {
        t = (b * c) >> 12;
    } else {
        t = b >> 2;
    }
    return a + t;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004A7E8);

typedef struct {
    SVECTOR pos[12];
    s16 unk60;
    s16 pad62;
    s32 unk64[12];
    s32 unk94[12];
    s16 unkC4[12];
    s16 unkDC[12];
    s16 unkF4[12];
    s16 unk10C[12];
    s16 unk124[12];
    s16 unk13C[12];
} Unk8004ACD4;

extern void func_8004A7E8();

void func_8004ACD4(SVECTOR *pos) {
    Unk8003BA6C_Task *task;
    Unk8004ACD4 *d;
    s16 i;
    s16 t;
    s16 r;
    s16 ang;

    task = (Unk8003BA6C_Task *)func_80021358(func_8004A7E8, 1, 0x158);
    if (task == NULL) {
        return;
    }
    task->unk28 = 0xFF;
    task->unk29 = 0xFF;
    task->unk2A = 0xFF;
    i = 11;
    d = (Unk8004ACD4 *)task->data;
    do {
        if (i < 4) {
            t = func_8001E9DC(0x400);
        } else {
            t = func_8001E9DC(3000) + 0x400;
        }
        ang = i * 0x155;
        r = func_800296F8(0, 1000, t);
        d->unk94[i] = func_800296F8(0x1000, 0x1000, t);
        d->unkC4[i] = func_800296F8(0x800, 0x100, t);
        d->unk64[i] = func_800296F8(120, 300, t);
        if (t < 0x800) {
            d->unk13C[i] = 0;
        } else {
            d->unk13C[i] = func_800296F8(0, 0x30, t);
        }
        d->unk10C[i] = func_800296F8(0x30, 0x30, t);
        d->pos[i].vx = pos->vx + ((D_800854C0[ang & 0xFFF] * r) >> 12);
        d->pos[i].vy = pos->vy;
        d->pos[i].vz = pos->vz + ((D_800854C0[(ang + 0x400) & 0xFFF] * r) >> 12);
        d->unkDC[i] = func_8001E9DC(800) + 100;
        d->unkF4[i] = func_8001E9DC(8) + 16;
        if ((s16)func_8001E9DC(2)) {
            d->unkF4[i] = -d->unkF4[i];
        }
    } while (i--);
    d->unk60 = 0xFF;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004AF54);

extern void func_8004AF54();

void func_8004B3C8(SVECTOR *pos) {
    Unk8003BA6C_Task *task;
    Unk8004ACD4 *d;
    s16 i;
    s16 t;
    s16 r;
    s16 ang;

    task = func_80021264(func_8004AF54, 1, 0x158);
    if (task == NULL) {
        return;
    }
    task->unk28 = 0xFF;
    task->unk29 = 0xFF;
    task->unk2A = 0xFF;
    i = 11;
    d = (Unk8004ACD4 *)task->data;
    do {
        if (i < 4) {
            t = func_8001E9DC(0x400);
        } else {
            t = func_8001E9DC(3000) + 0x400;
        }
        ang = i * 0x155;
        r = func_800296F8(0, 0x800, t);
        d->unk94[i] = 0x400;
        d->unkC4[i] = func_800296F8(0xC0, 0x20, t);
        d->unk64[i] = func_800296F8(240, 500, t);
        if (t < 0x800) {
            d->unk13C[i] = 0;
        } else {
            d->unk13C[i] = func_800296F8(10, 12, t);
        }
        d->unk10C[i] = func_800296F8(0x60, 0x60, t);
        d->pos[i].vx = pos->vx + ((D_800854C0[ang & 0xFFF] * r) >> 12);
        d->pos[i].vy = pos->vy;
        d->pos[i].vz = pos->vz + ((D_800854C0[(ang + 0x400) & 0xFFF] * r) >> 12);
        d->unkDC[i] = func_8001E9DC(800) + 100;
        d->unkF4[i] = func_8001E9DC(8) + 16;
        if ((s16)func_8001E9DC(2)) {
            d->unkF4[i] = -d->unkF4[i];
        }
    } while (i--);
    d->unk60 = 0xFF;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004B63C);

typedef struct {
    u8 pad0[8];
    s16 x, y, z;
    u8 padE[2];
    s16 unk10;
    u8 pad12[6];
} Unk8004BBF8_Part;

typedef struct {
    SVECTOR pos;
    SVECTOR rot;
    Unk8004BBF8_Part parts[32];
    s16 unk310;
    s16 unk312;
    s16 unk314;
    s16 unk316;
    s32 unk318;
} Unk8004BBF8;

extern void func_8004B63C();
s16 func_8004BE4C(void *item);

void func_8004BBF8(SVECTOR *pos) {
    Unk8003BA6C_Task *task = func_80021264(func_8004B63C, 1, sizeof(Unk8004BBF8));
    Unk8004BBF8 *obj;
    struct Task *saved;
    s32 params[6];
    s16 i;

    if (task == NULL) {
        return;
    }
    obj = (Unk8004BBF8 *)task->data;
    obj->unk316 = func_8004BE4C(obj);
    if (obj->unk316 == -1) {
        saved = D_800A317C;
        D_800A317C = (struct Task *)task;
        func_80021554();
        D_800A317C = saved;
        return;
    }
    obj->pos.vx = pos->vx;
    obj->pos.vy = pos->vy;
    obj->pos.vz = pos->vz;
    obj->rot.vx = 0;
    obj->rot.vy = func_8001E9DC(0x1000);
    obj->rot.vz = 0;
    obj->unk310 = 0x100;
    obj->unk312 = 0;
    if ((s16)func_8001E9DC(2) != 0) {
        obj->unk314 = 0x78;
    } else {
        obj->unk314 = -0x78;
    }
    for (i = 0; i < 32; i++) {
        obj->parts[i].x = 0;
        obj->parts[i].y = 0;
        obj->parts[i].z = 0;
        obj->parts[i].unk10 = 0;
    }
    params[0] = 0x19;
    params[1] = func_80050974(&obj->pos, 0x3FFF);
    params[2] = func_800508F0(&obj->pos) * 4;
    params[3] = 0x400;
    params[4] = 0;
    params[5] = 0;
    obj->unk318 = func_8004FB78(params);
    params[0] = 0x1A;
    params[1] = func_80050974(&obj->pos, 0x3FFF);
    params[2] = func_800508F0(&obj->pos) * 4;
    params[3] = 0x400;
    params[4] = 0;
    params[5] = 0;
    obj->unk318 = func_8004FB78(params);
}

typedef struct {
    void *slots[16];
    s16 count;
} SlotTable;

typedef struct {
    u8 pad0[0x1C];
    SlotTable *table;
} Unk801F7D80;

extern Unk801F7D80 *D_801F7D80;

extern void func_8004BE44();

void func_8004BDD0(void) {
    Unk801F7D80 *task;
    SlotTable *table;
    s16 i;

    task = (Unk801F7D80 *)func_80021264(func_8004BE44, 1, 0x44);
    if (task != NULL) {
        D_801F7D80 = task;
        table = *(SlotTable **)((u8 *)task + 0x1C);
        table->count = 0;
        for (i = 0; i < 16; i++) {
            table->slots[i] = NULL;
        }
    }
}

void func_8004BE44(void) {
}

s16 func_8004BE4C(void *item) {
    SlotTable *table = D_801F7D80->table;
    s16 i;

    if (table->count >= 16) {
        return -1;
    }
    for (i = 0; i < 16; i++) {
        if (table->slots[i] == 0) {
            table->slots[i] = item;
            table->count++;
            return i;
        }
    }
    return -1;
}

void func_8004BED8(s16 i) {
    SlotTable *table = D_801F7D80->table;

    table->slots[i] = 0;
    table->count--;
}

s32 func_8004BF0C(Unk8002A35C *pos) {
    SlotTable *table = D_801F7D80->table;
    s16 i;

    if (table->count == 0) {
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (table->slots[i] != NULL && func_8002A35C(table->slots[i], pos) < 0xA00) {
            return -1;
        }
    }
    return 0;
}

void func_8004BFB8(void) {
    Unk80045164 *obj = (Unk80045164 *)D_800A317C->vals;
    s32 tmp;

    func_8003E384(obj);
    if (obj->unk28 == 4) {
        func_8002A270(&obj->pos, 0);
    } else {
        func_8002A270(&obj->pos, 4);
    }
    func_80024EF0(&obj->anim);
    func_80031200((Unk80031200 *)obj);
    func_8003146C((Unk8003146C *)obj);
    obj->pos.y = func_80023E80(obj, &tmp, &tmp);
    func_80031320(obj);
    func_80049064(obj, 0);
    if ((s16)func_8004BF0C(&obj->pos) == 0) {
        switch (obj->unk28) {
        case 3:
        case 8:
        case 0x12:
            func_80024DA8(&obj->anim, D_8007C550[obj->unkF4], 0, 0x52, 8);
            break;
        default:
            func_80024DA8(&obj->anim, D_8007C560[obj->unkF4], 0, 0x52, 8);
            break;
        }
        D_800A317C->func = D_800A317C->saved;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004C104);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004C19C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004C38C);

typedef struct {
    s16 pos[3];
    u8 pad6[0x22];
    s16 unk28[16];
    s16 unk48[16];
    s16 unk68[16];
    s16 unk88[16];
    s16 unkA8;
    s16 unkAA;
    s16 unkAC[16];
    s16 unkCC[16];
    s16 unkEC[16];
    s16 unk10C[16];
    s16 unk12C;
    s16 unk12E;
    s16 unk130;
    s16 unk132;
    s16 unk134;
    s16 unk136;
} Unk8004C97C_Data;

void func_8004C38C();

void func_8004C97C(s16 *pos) {
    Unk8003BA6C_Task *task;
    Unk8004C97C_Data *d;
    s16 i;

    task = func_80021264(func_8004C38C, 5, 0x138);
    if (task != NULL) {
        d = (Unk8004C97C_Data *)task->data;
        d->pos[0] = pos[0];
        d->pos[1] = pos[1];
        d->pos[2] = pos[2];
        i = 15;
        do {
            func_8001E9DC(0x1000);
            d->unk28[i] = func_8001E9DC(0x1000);
            d->unk12C = 0;
            d->unk12E = 0x20;
        } while (i--);
        i = 15;
        do {
            d->unk48[i] = func_8001E9DC(0x1000);
            d->unkAC[i] = func_8001E9DC(0x1000);
            d->unk10C[i] = func_8001E9DC(0x1000);
            d->unk68[i] = func_8001E9DC(0x80) - 0x40;
            d->unk88[i] = func_8001E9DC(0x1000);
        } while (i--);
        d->unkA8 = 0;
        d->unkAA = 0x1E;
        d->unk130 = 0x10;
        d->unk132 = 0x80;
        d->unk134 = 0x1E;
        d->unk136 = 0x200;
    }
}

typedef struct {
    SVECTOR pos[32];
    SVECTOR vel[32];
    u8 pad200[0x10];
    SVECTOR dir;
    u8 unk218[32];
} Unk8004CAB0;

void func_8004CAB0(s16 i) {
    Unk8004CAB0 *d = (Unk8004CAB0 *)D_800A317C->vals;

    d->pos[i].vx = func_8001E9DC(8) - 4;
    d->pos[i].vy = func_8001E9DC(8) - 4;
    d->pos[i].vz = func_8001E9DC(8) - 4;
    d->vel[i].vx = -d->dir.vx >> 2;
    d->vel[i].vy = -d->dir.vy >> 2;
    d->vel[i].vz = -d->dir.vz >> 2;
    d->vel[i].vz = func_8001E9DC(16) + (s16)(d->vel[i].vz - 8);
    d->vel[i].vx = func_8001E9DC(16) + (s16)(d->vel[i].vx - 8);
    d->vel[i].vy = func_8001E9DC(16) + (s16)(d->vel[i].vy - 8);
    d->unk218[i] = 0xFF;
}

void func_8004CBB8(s16 i) {
    Unk8004CAB0 *d = (Unk8004CAB0 *)D_800A317C->vals;
    s16 j;
    s16 dx, dy, dz;

    j = func_8001E9DC(0x20);
    if (d->unk218[i] != 0) {
        d->pos[j].vx = d->pos[i].vx;
        d->pos[j].vy = d->pos[i].vy;
        d->pos[j].vz = d->pos[i].vz;
        dx = func_8001E9DC(0x20) - 0x10;
        dy = func_8001E9DC(0x20) - 0x10;
        dz = func_8001E9DC(0x20) - 0x10;
        d->vel[j].vx = dx + d->vel[i].vx;
        d->vel[j].vy = dy + d->vel[i].vy;
        d->vel[j].vz = dz + d->vel[i].vz;
        d->vel[i].vx -= dx;
        d->vel[i].vy -= dy;
        d->vel[i].vz -= dz;
        d->unk218[j] = d->unk218[i];
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004CCE8);

typedef struct {
    char pad0[0x200];
    s16 x;
    s16 y;
    s16 z;
    char pad206[0xA];
    s16 dx;
    s16 dy;
    s16 dz;
    char pad216[0x22];
    s16 unk238;
    s16 unk23A;
    s16 unk23C;
    s16 unk23E;
    s16 unk240;
} Unk8004D15C;

extern void func_8004CAB0(s16 i);
extern void func_8004CCE8(void);

void func_8004D15C(void) {
    Unk8004D15C *d = (Unk8004D15C *)D_800A317C->vals;
    s16 i = 31;

    do {
        func_8004CAB0(i);
    } while (i--);
    d->unk238 = 1;
    d->unk23A = 0;
    d->unk23C = -0x400;
    d->unk240 = 1;
    D_800A317C->func = func_8004CCE8;
}

void func_8004D1D8(SVECTOR *pos, SVECTOR *dir, s16 arg2) {
    s32 params[8];
    Unk8003BA6C_Task *task;
    Unk8004D15C *d;

    params[0] = (s16)func_8001E9DC(3);
    params[1] = func_80050974(pos, 0x1000);
    params[2] = func_800508F0(pos) * 4;
    params[3] = 0x400;
    params[4] = 0;
    params[5] = 0;
    func_8004FB78(params);
    if ((s16)func_8001E9DC(0x100) > 0x80) {
        params[0] = (s16)func_8001E9DC(2) + 3;
        params[1] = func_80050974(pos, 0x1000);
        params[2] = func_800508F0(pos) * 4;
        params[3] = 0x400 - (s16)func_8001E9DC(0xC0);
        params[4] = 0;
        params[5] = 0;
        func_8004FB78(params);
    }
    task = func_80021264(func_8004D15C, 3, 0x242);
    if (task != NULL) {
        d = *(Unk8004D15C **)((u8 *)task + 0x1C);
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
        d->dx = dir->vx;
        d->dy = dir->vy;
        d->dz = dir->vz;
        d->unk23E = arg2;
    }
}

void func_8004D360(SVECTOR *v) {
    s16 x = v->vx;
    s16 y = v->vy;
    s16 z = v->vz;
    s32 len = SquareRoot0(x * x + y * y + z * z);

    if (len != 0) {
        x = (x << 12) / len;
        y = (y << 12) / len;
        z = (z << 12) / len;
        v->vx = x;
        v->vy = y;
        v->vz = z;
    } else {
        v->vx = 0;
        v->vy = 0x1000;
        v->vz = 0;
    }
}

typedef struct {
    SVECTOR *v[4];
} Unk8004D4A0;

void func_8004D4A0(Unk8004D4A0 *f, SVECTOR *out) {
    if (f->v[3] != (SVECTOR *)-1) {
        out->vx = (f->v[0]->vx + f->v[1]->vx + f->v[2]->vx + f->v[3]->vx) >> 2;
        out->vy = (f->v[0]->vy + f->v[1]->vy + f->v[2]->vy + f->v[3]->vy) >> 2;
        out->vz = (f->v[0]->vz + f->v[1]->vz + f->v[2]->vz + f->v[3]->vz) >> 2;
    } else {
        out->vx = (f->v[0]->vx + f->v[1]->vx + f->v[2]->vx) / 3;
        out->vy = (f->v[0]->vy + f->v[1]->vy + f->v[2]->vy) / 3;
        out->vz = (f->v[0]->vz + f->v[1]->vz + f->v[2]->vz) / 3;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004D650);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004DA48);

void func_8004DDB4(u8 *a, u8 *b, s16 t, u8 *out) {
    out[0] = func_800296F8(a[0], b[0], t);
    out[1] = func_800296F8(a[1], b[1], t);
}

typedef struct {
    SVECTOR *v[4];
    u16 unk10;
    u16 flags;
} Unk8004DE24_Face;

typedef struct {
    SVECTOR *p[4];
    u16 unk10;
    u16 unk12;
} Unk8004DE24_Quad;

extern void RotTransSV(SVECTOR *v, SVECTOR *out, s32 *flag);
extern void func_8004E570(Unk8004DE24_Quad *q, s16 y, s16 arg2);

void func_8004DE24(Unk80032344 *obj, s16 arg1) {
    Unk8004DE24_Face *f;
    Unk8004DE24_Quad q;
    SVECTOR v[4];
    SVECTOR unused[2];

    PushMatrix();
    RotMatrix(&obj->rot, &D_801FB868);
    ScaleMatrix(&D_801FB868, &obj->scale);
    SetRotMatrix(&D_801FB868);
    D_801C1EC4.vx = obj->pos.vx;
    D_801C1EC4.vy = obj->pos.vy;
    D_801C1EC4.vz = obj->pos.vz;
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    f = (Unk8004DE24_Face *)(obj->data + 8);
    q.p[0] = &v[0];
    q.p[1] = &v[1];
    q.p[2] = &v[2];
    q.p[3] = &v[3];
    do {
        if ((s32)f->v[3] != -1) {
            RotTransSV(f->v[0], &v[0], &D_800A3394);
            RotTransSV(f->v[1], &v[1], &D_800A3394);
            RotTransSV(f->v[2], &v[2], &D_800A3394);
            RotTransSV(f->v[3], &v[3], &D_800A3394);
            q.unk10 = f->unk10;
            q.unk12 = f->flags;
            func_8004E570(&q, obj->pos.vy, arg1);
        }
    } while (!((f++)->flags & 0x80));
    PopMatrix();
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 vals[64];
} Unk8004DFD0_Data;

extern void *D_801F7D7C;
extern void func_8004E04C();

void func_8004DFD0(void) {
    void *task;
    Unk8004DFD0_Data *data;
    s16 i;

    task = func_80021358(func_8004E04C, 1, 0x86);
    if (task != NULL) {
        D_801F7D7C = task;
        data = *(Unk8004DFD0_Data **)((u8 *)task + 0x1C);
        data->unk0 = 0;
        data->unk2 = 0;
        data->unk4 = 0;
        for (i = 0; i < 64; i++) {
            data->vals[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004E04C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004E570);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2ADC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AE0);

void func_8004ED2C(s16 *angle, s16 *speed) {
    s16 i = 15;
    s16 n;

    while (1) {
        *angle += *speed;
        if (*angle > 0) {
            (*speed)--;
            if (*angle > 180) {
                *angle = 180;
            }
        } else {
            (*speed)++;
        }
        angle++;
        speed++;
        n = i--;
        if (n == 0) break;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004EDB0);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
} Unk8004F364_Pt;

typedef struct {
    Unk8002A35C pos;
    u8 pad6[2];
    Unk8004F364_Pt pts[8];
    u8 pad48[0x44];
    s32 unk8C;
    s16 unk90[8];
    s16 pad9[8];
    s16 unkB0[16];
    s16 unkD0[16];
    s16 padF0;
    s16 unkF2;
    s16 padF4[2];
    s16 unkF8;
    s16 unkFA[8];
    s16 unk10A;
} Unk8004F364;

extern void func_8004EDB0();

void func_8004F364(Unk8002A35C *pos, s32 arg1) {
    struct Task *task = func_80021358(func_8004EDB0, 3, sizeof(Unk8004F364));
    Unk8004F364 *data;
    s16 i;

    if (task != NULL) {
        data = (Unk8004F364 *)task->vals;
        data->pos.x = pos->x;
        data->pos.y = pos->y;
        data->pos.z = pos->z;
        i = 15;
        do {
            data->unkB0[i] = func_8001E9DC(180);
            data->unkD0[i] = 0;
        } while (i-- != 0);
        i = 7;
        do {
            data->unk90[i] = 0x40;
            data->pts[i].x = func_8001E9DC(0x40) - 0x20;
            data->pts[i].z = func_8001E9DC(0x40) - 0x20;
            data->pts[i].y = i * 8;
            data->unkFA[i] = 0;
        } while (i-- != 0);
        data->unkF2 = 0;
        data->unkF8 = func_8001E9DC(0x100) + 0x180;
        data->unk10A = 0;
        data->unk8C = arg1;
    }
}

typedef struct {
    SVECTOR v[9][5];
    SVECTOR pos;
    s16 unk170;
    s16 unk172;
    s16 unk174;
    s16 unk176;
    s16 unk178;
    u8 pad17A[2];
    s32 unk17C;
    s16 unk180;
    u8 pad182[2];
} Unk8004FA1C;

s16 func_8004F498(Unk8004FA1C *obj, s16 dstep, s16 step, s16 y) {
    s16 i;
    s16 j;
    s16 k;
    s16 r;
    s16 prev;
    s32 x;
    s32 z;

    for (i = 0; i < 5; i++) {
        r = i * 250 + 0x80;
        j = 8;
        do {
            k = j;
            if (j == 8) {
                k = 0;
            }
            k *= 2;
            r -= 0x20;
            x = D_800854C0[(k * 0x200) & 0xFFF] * r;
            z = D_800854C0[(k * 0x200 + 0x400) & 0xFFF] * r;
            obj->v[j][i].vx = (x >> 12) + obj->pos.vx;
            obj->v[j][i].vz = (z >> 12) + obj->pos.vz;
            obj->v[j][i].vy = y + func_8001E9DC(0x40);
        } while (j-- != 0);
        prev = y;
        y -= step;
        step += dstep;
    }
    return prev;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004F634);

extern void func_8004F634();
extern s16 func_80023E80(void *obj, s32 *a, s32 *b);

void func_8004FA1C(SVECTOR *pos) {
    Unk8003BA6C_Task *task;
    Unk8004FA1C *p;
    s32 params[6];
    s32 tmp;

    task = func_80021264(func_8004F634, 3, sizeof(Unk8004FA1C));
    if (task != NULL) {
        p = (Unk8004FA1C *)task->data;
        p->pos.vx = pos->vx;
        p->pos.vy = pos->vy;
        p->pos.vz = pos->vz;
        p->unk178 = func_80023E80(&p->pos, &tmp, &tmp);
        p->unk176 = 0xE00;
        p->unk172 = -1;
        p->unk180 = 0;
        p->unk174 = 0x40;
        p->unk170 = 600;
        func_8004F498(p, p->unk174, 0x40, p->unk176);
        params[0] = 0x14;
        params[1] = 0x2000;
        params[2] = func_800508F0(&p->pos) * 4;
        params[3] = 0x400;
        params[4] = 0;
        params[5] = 0;
        p->unk17C = func_8004FB78(params);
    }
}

extern u16 D_800A33DC;

u16 func_8004FB10(void) {
    D_800A33DC++;
    return D_800A33DC;
}

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    u16 id;
    short left;
    short right;
} VoiceState;

extern VoiceState D_801C1F14[];

void func_8004FB38(void) {
    VoiceState *v = D_801C1F14;
    s32 i;

    for (i = 0; i < 24; v++, i++) {
        v->unk0 = 0;
        v->unk2 = 0;
        v->id = 0;
    }
    D_800A33DC = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004FB78);

void func_8004FFE0(int volume, int pan) {
    SpuCommonAttr attr;

    if (D_800A350C->unk178C != 0) {
        pan = 0;
    }
    attr.mask = SPU_COMMON_MVOLL | SPU_COMMON_MVOLR;
    attr.mvol.left = volume - ((volume * pan) >> 14);
    attr.mvol.right = volume + ((volume * pan) >> 14);
    SpuSetCommonAttr(&attr);
}

void func_80050044(void) {
    SpuVoiceAttr attr;

    attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR;
    attr.voice = 0xFFFFFF;
    attr.volume.left = 0;
    attr.volume.right = 0;
    SpuSetVoiceAttr(&attr);
}

typedef struct {
    u8 id;
    u8 pad1;
    short left;
    short right;
    char pad6[6];
} VoiceVol;

extern VoiceVol D_801C1F1A[];

void func_80050080(void) {
    SpuVoiceAttr attr;
    int i;

    for (i = 0; i < 24; i++) {
        attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR;
        attr.volume.left = D_801C1F1A[i].left;
        attr.volume.right = D_801C1F1A[i].right;
        attr.voice = 1 << i;
        SpuSetVoiceAttr(&attr);
    }
}

void func_8005010C(s32 vol, s32 pan) {
    SpuCommonAttr attr;
    s32 d = (vol * pan) >> 14;

    attr.mask = 0xC0;
    attr.cd.volume.left = vol - d;
    attr.cd.volume.right = vol + d;
    SpuSetCommonAttr(&attr);
}

int func_80050158(int id, int volume, int pan) {
    SpuVoiceAttr attr;
    int voice;
    int d;

    if (D_800A350C->unk178C != 0) {
        pan = 0;
    }
    volume = func_800296F8(0, volume, D_800A350C->unk1786);
    voice = id & 0xFF;
    if (D_801C1F1A[voice].id == ((id >> 8) & 0xFF)) {
        attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR;
        volume >>= 1;
        d = func_800296F8(0, volume, ABS(pan));
        attr.volume.left = volume;
        attr.volume.right = volume;
        if (pan < 0) {
            attr.volume.left = d + volume;
            attr.volume.right = volume - d;
        } else {
            attr.volume.left = volume - d;
            attr.volume.right = d + volume;
        }
        attr.voice = 1 << voice;
        SpuSetVoiceAttr(&attr);
        D_801C1F1A[voice].left = attr.volume.left;
        D_801C1F1A[voice].right = attr.volume.right;
        return 0;
    }
    return -1;
}

int func_80050288(int handle, short pitch) {
    SpuVoiceAttr attr;
    int voice = handle & 0xFF;

    if (D_801C1F1A[voice].id == ((handle >> 8) & 0xFF)) {
        attr.mask = SPU_VOICE_PITCH;
        attr.pitch = pitch;
        attr.voice = 1 << voice;
        SpuSetVoiceAttr(&attr);
        return 0;
    }
    return -1;
}

int func_800502F0(int handle, short note) {
    SpuVoiceAttr attr;
    int voice = handle & 0xFF;

    if (D_801C1F1A[voice].id == ((handle >> 8) & 0xFF)) {
        attr.mask = SPU_VOICE_NOTE;
        attr.note = note;
        attr.voice = 1 << voice;
        SpuSetVoiceAttr(&attr);
        return 0;
    }
    return -1;
}

extern u16 D_800A33DC;
extern void SpuSetKey(long on_off, unsigned long voice_bit);

int func_80050358(int handle) {
    int voice = handle & 0xFF;

    if ((D_801C1F14[voice].id & 0xFF) == ((handle >> 8) & 0xFF)) {
        SpuSetKey(0, 1 << voice);
        D_801C1F14[voice].unk2 = 0;
        D_801C1F14[voice].unk0 = D_800A33DC;
        func_80050158(handle, 0, 0);
        return 0;
    }
    return -1;
}

int func_800503F0(s32 voice) {
    s32 ch = voice & 0xFF;

    if (D_801C1F1A[ch].id != ((voice >> 8) & 0xFF)) {
        return -1;
    }
    SpuSetReverbVoice(1, 1 << ch);
    return 0;
}

extern long SpuSetReverbVoice(long on_off, unsigned long voice_bit);

int func_80050448(int handle) {
    int voice = handle & 0xFF;

    if ((D_801C1F14[voice].id & 0xFF) == ((handle >> 8) & 0xFF)) {
        SpuSetReverbVoice(0, 1 << voice);
        D_801C1F14[voice].unk0 = D_800A33DC;
        return 0;
    }
    return -1;
}

int func_800504B8(int handle) {
    int voice = handle & 0xFF;

    if (D_801C1F1A[voice].id == ((handle >> 8) & 0xFF)) {
        return voice;
    }
    return -1;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800504F0);

extern void SpuFree(s32 addr);

void func_80050738(s32 arg0) {
    SpuFree(arg0);
}

extern char D_801F97D4[];

void func_80050758(void) {
    SpuVoiceAttr voice;
    SpuCommonAttr common;
    SpuReverbAttr reverb;

    SsUtReverbOff();
    SpuStart();
    SpuInitMalloc(16, D_801F97D4);
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);

    common.mask = SPU_COMMON_MVOLL | SPU_COMMON_MVOLR | SPU_COMMON_CDVOLL | SPU_COMMON_CDVOLR |
                  SPU_COMMON_CDREV | SPU_COMMON_CDMIX;
    common.mvol.left = 0x3FFF;
    common.mvol.right = 0x3FFF;
    common.cd.volume.left = 0x3FFF;
    common.cd.volume.right = 0x3FFF;
    common.cd.reverb = SPU_OFF;
    common.cd.mix = SPU_ON;
    SpuSetCommonAttr(&common);

    SpuReserveReverbWorkArea(SPU_ON);
    reverb.mask = SPU_REV_MODE | SPU_REV_DEPTHL | SPU_REV_DEPTHR | SPU_REV_DELAYTIME | SPU_REV_FEEDBACK;
    reverb.mode = SPU_REV_MODE_OFF;
    SpuSetReverbModeParam(&reverb);
    SpuSetReverb(SPU_ON);

    voice.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR | SPU_VOICE_PITCH | SPU_VOICE_WDSA | SPU_VOICE_ADSR_AMODE |
                 SPU_VOICE_ADSR_SMODE | SPU_VOICE_ADSR_RMODE | SPU_VOICE_ADSR_AR | SPU_VOICE_ADSR_DR |
                 SPU_VOICE_ADSR_SR | SPU_VOICE_ADSR_RR | SPU_VOICE_ADSR_SL;
    voice.voice = SPU_ALLCH;
    voice.volume.left = 0x3FFF;
    voice.volume.right = 0x3FFF;
    voice.pitch = 0x1000;
    voice.a_mode = SPU_VOICE_LINEARIncN;
    voice.s_mode = SPU_VOICE_LINEARIncN;
    voice.r_mode = SPU_VOICE_LINEARDecN;
    voice.ar = 0;
    voice.dr = 0;
    voice.sr = 0;
    voice.rr = 0;
    voice.sl = 0xF;
    SpuSetVoiceAttr(&voice);
}

void func_80050844(void) {
    VoiceState *v;
    short i;
    short j;

    D_800A33DC = 0;
    v = D_801C1F14;
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            func_80050358((v->id << 8) | j);
        }
        v->unk0 = 0;
        v->unk2 = 0;
        v->id = 0;
        v++;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800508F0);

s16 func_80050974(SVECTOR *pos, s32 arg1) {
    s32 d = func_8002A35C((Unk8002A35C *)pos, (Unk8002A35C *)D_801F7D44->vals) >> 1;

    if (d > 0x1000) {
        d = 0x1000;
    }
    return func_800296F8((s16)arg1, 0, d);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    SVECTOR unk4[20];
    SVECTOR unkA4[20];
    s32 unk144[20];
    s16 unk194[20];
    s16 unk1BC[20];
    s16 unk1E4[20];
    s16 unk20C[20];
    s16 unk234[20];
    s16 unk25C[20];
} Unk800509D0_Data;

extern void *D_801F7D5C;
extern s16 D_800A320C;
void func_80050A98(void);

void func_800509D0(void) {
    void *task;
    Unk800509D0_Data *data;
    s16 i;

    task = func_80021264(func_80050A98, 1, 0x284);
    if (task != NULL) {
        D_801F7D5C = task;
        data = *(Unk800509D0_Data **)((u8 *)task + 0x1C);
        data->unk0 = 0;
        data->unk2 = -1;
        for (i = 0; i < 20; i++) {
            data->unk4[i].vx = 0;
            data->unk4[i].vy = 0;
            data->unk4[i].vz = 0;
            data->unkA4[i].vx = 0;
            data->unkA4[i].vy = 0;
            data->unkA4[i].vz = 0;
            data->unk1BC[i] = 0;
            data->unk234[i] = 0;
            data->unk194[i] = 0x1000;
            data->unk144[i] = 0;
            data->unk20C[i] = 0;
            data->unk1E4[i] = 0;
            data->unk25C[i] = 0;
        }
        D_800A320C = 0;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80050A98);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AEE0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AF00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007AF38);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800514D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AF48);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AE4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AEC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AF4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AF8);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2AFC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B04);

typedef struct {
    s16 unk0;
    s16 pad2[2];
    s16 unk6;
    s16 pad8[14];
    s16 unk24;
    s16 pad26[2];
    s16 unk2A;
} Unk80051778_Ctl;

typedef struct {
    u8 pad0[0x2C];
    s16 unk2C;
    u8 pad2E[0x64 - 0x2E];
    Anim anim;
} Unk80051778_Obj;

extern void *D_801F7D60;
extern const s16 D_8007C570[];
extern const s16 D_8007C590[];

void func_80051778(s16 id, s16 flag) {
    Unk80051778_Ctl *c = (Unk80051778_Ctl *)((struct Task *)D_801F7D60)->vals;
    Unk80051778_Obj *obj;
    s16 *p;

    if (D_801F7D50 == NULL) {
        return;
    }
    obj = (Unk80051778_Obj *)D_801F7D50->vals;
    p = (s16 *)((u8 *)obj + 0x114);
    if (flag) {
        if (c->unk6 != id) {
            if (obj->unk2C == 12) {
                func_80024DA8(&obj->anim, D_8007C550[id], -1, 0x52, 3);
            } else if (obj->unk2C == 1) {
                func_80024DA8(&obj->anim, D_8007C590[id], -1, -0x15E, 3);
            } else if (obj->unk2C == 2) {
                func_80024DA8(&obj->anim, D_8007C590[id], -1, 0x15E, 3);
            } else if (obj->unk2C != 5 && obj->unk2C != 6) {
                func_80024DA8(&obj->anim, D_8007C570[id], -1, 0x52, 3);
            }
            c->unk6 = id;
            c->unk0 = 1;
            if (c->unk6 == 3 || c->unk6 == 4 || c->unk6 == 6) {
                p[5] = -1;
            }
            *(s16 *)((u8 *)obj + 0xF6) = 30;
        } else {
            if (c->unk6 == 3 || c->unk6 == 4 || c->unk6 == 6) {
                *(s16 *)((u8 *)obj + 0x11E) = -1;
            }
            *(s16 *)((u8 *)obj + 0xF6) += 30;
        }
    } else if (c->unk2A != id) {
        c->unk2A = id;
        c->unk24 = 1;
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 pad32;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 pad40;
    s32 unk44;
} Unk80051960;

extern void *D_801F7D60;
extern s16 D_80080E68[];
extern s16 D_80080E78[];
extern void func_80051AC0(void);

void func_80051960(void) {
    void *task;
    Unk80051960 *data;

    task = func_80021264(func_80051AC0, 1, 0x48);
    if (task != NULL) {
        D_801F7D60 = task;
        data = *(Unk80051960 **)((u8 *)task + 0x1C);
        data->unk0 = 0;
        data->unk2 = D_80080E78[D_801D209E[0]];
        data->unk4 = D_801D209E[0];
        data->unk6 = D_801D209E[0];
        data->unk10 = D_80080E78[D_801D209E[0]];
        data->unk14 = D_80080E78[D_801D209E[0]];
        data->unk18 = D_80080E78[D_801D209E[0]];
        data->unk8 = 0x800;
        data->unkA = 0;
        data->unkC = 0;
        data->unk20 = D_801D70F0[D_80080E68[D_801D209E[0]]];
        data->unk24 = 0;
        data->unk26 = 0x2000;
        data->unk28 = 0;
        data->unk2A = 0;
        data->unk34 = 0x2000;
        data->unk38 = 0x2000;
        data->unk3C = 0x2000;
        data->unk2C = 0x800;
        data->unk2E = 0;
        data->unk30 = -0x200;
        data->unk44 = D_801D70F0[30];
    }
}

typedef struct {
    s16 state;
    s16 val;
    s16 cur;
    s16 idx;
    SVECTOR rot;
    VECTOR scale;
    u8 *model;
} Unk80051AC0_Part;

typedef struct {
    Unk80051AC0_Part part[2];
} Unk80051AC0;

typedef struct {
    u8 pad0[0xF6];
    s16 unkF6;
    s16 unkF8[3];
    s16 unkFE;
} Unk80051AC0_Owner;

typedef struct {
    u8 r, g, b, a;
} Unk80051AC0_Color;

typedef struct {
    s16 v[3];
} Unk80051AC0_Tbl;

extern Unk80051AC0_Color D_800A2AF8;
extern Unk80051AC0_Tbl D_800A2AFC;
extern Unk80051AC0_Tbl D_800A2B04;
extern s16 D_80080E68[];
extern s16 D_80080E78[];
extern void func_800547B0(short x, short y, int value, int d, int a, int b, int c);
extern void func_80051DF8(u8 *model, SVECTOR *rot, VECTOR *scale);
extern void func_80070FBC(s32 a, s32 b);

void func_80051AC0(void) {
    Unk80051AC0 *d = (Unk80051AC0 *)D_800A317C->vals;
    Unk80051AC0_Color c = D_800A2AF8;
    Unk80051AC0_Tbl start = D_800A2AFC;
    Unk80051AC0_Tbl end = D_800A2B04;
    Unk80051AC0_Owner *o;
    s16 h;

    if (D_801F7D50 == NULL) {
        return;
    }
    o = (Unk80051AC0_Owner *)D_801F7D50->vals;
    switch (d->part[0].state) {
    case 1:
        d->part[0].val -= 0x400;
        if (d->part[0].val < 0x400) {
            d->part[0].val = 0x200;
            d->part[0].state++;
            d->part[0].model = (u8 *)D_801D70F0[D_80080E68[d->part[0].idx]];
            d->part[0].cur = d->part[0].idx;
        }
        break;
    case 2:
        d->part[0].val += 0x400;
        if (D_80080E78[d->part[0].idx] < d->part[0].val) {
            d->part[0].val = D_80080E78[d->part[0].idx];
            d->part[0].state = 0;
        }
        break;
    }
    d->part[0].scale.vx = d->part[0].scale.vy = d->part[0].scale.vz = d->part[0].val;
    switch (d->part[1].state) {
    case 1:
        d->part[1].val -= 0x400;
        if (d->part[1].val < 0x400) {
            d->part[1].val = 0x200;
            d->part[1].state++;
            d->part[1].model = (u8 *)D_801D70F0[start.v[d->part[1].idx]];
            d->part[1].cur = d->part[1].idx;
        }
        break;
    case 2:
        d->part[1].val += 0x400;
        if (end.v[d->part[1].idx] < d->part[1].val) {
            d->part[1].val = end.v[d->part[1].idx];
            d->part[1].state = 0;
        }
        break;
    }
    d->part[1].scale.vx = d->part[1].scale.vy = d->part[1].scale.vz = d->part[1].val;
    func_800547B0(0x5E, 0x20, o->unkF8[o->unkFE], 0x300, 0x140, (int)&c, (int)&c);
    func_800547B0(0xE6, 0x20, o->unkF6, 0x300, 0x140, (int)&c, (int)&c);
    PushMatrix();
    func_80070FBC(0xE6, 0x22);
    func_80051DF8(d->part[0].model + 8, &d->part[0].rot, &d->part[0].scale);
    func_80070FBC(0x5E, 0x22);
    func_80051DF8(d->part[1].model + 8, &d->part[1].rot, &d->part[1].scale);
    PopMatrix();
    h = D_800A33C4;
    func_80070FBC(0xA0, h >> 1);
    d->part[0].rot.vy += 0x20;
    d->part[1].rot.vy -= 0x20;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80051DF8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007AF60);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005217C);

typedef struct {
    RECT rect[2];
    u8 pad10[8];
    u32 start;
    u32 end;
    s16 mode;
} Unk8005231C_Info;

typedef struct {
    u32 *vlcbuf[2];
    u32 *imgbuf[2];
    u32 *ring;
    u8 loc[4];
    RECT rect[2];
    RECT slice;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    Unk8005231C_Info *info;
    u8 pad68[8];
    s16 unk70;
    u16 unk72;
    s16 unk74;
} Unk8005231C;

extern int CdRead2(long mode);
extern void func_8003E3CC(void);
extern void func_80052DB8(void);
extern u8 *D_800A2C0C;

s16 func_80052234(Unk8005231C *movie) {
    u8 result[8];
    s16 fail = -1;
    s16 i = 59;

    do {
        if (CdControl(0x15, movie->loc, 0) != 0) {
            fail = 0;
            break;
        }
        if (CdControl(0x15, D_800A2C0C + 0xCA8, 0) == 0) {
            func_8003E3CC();
        }
    } while (i--);

    if (fail) {
        func_80052DB8();
        func_8003E3CC();
        return 0;
    }

    fail = -1;
    i = 59;
    do {
        if (CdRead2(0x1C0) != 0) {
            fail = 0;
            break;
        }
    } while (i--);

    if (fail) {
        func_80052DB8();
        func_8003E3CC();
        return 0;
    }
    return -1;
}

extern void CdReadCallback(void (*func)());
extern void DecDCTReset(s32 mode);
extern void DecDCToutCallback(void (*func)());
extern void StSetRing(u32 *ring_addr, u32 ring_size);
extern void StSetStream(u32 mode, u32 start_frame, u32 end_frame, void (*func1)(), void (*func2)());

s16 func_8005231C(void (*outFunc)(), void (*endFunc)(), Unk8005231C *movie) {
    movie->unk4C = 0;
    CdReadCallback(0);
    DecDCTReset(0);
    DecDCToutCallback(outFunc);
    StSetRing(movie->ring, 0x23);
    StSetStream(movie->info->mode, movie->info->start, movie->info->end, 0, endFunc);
    return func_80052234(movie);
}

void func_800523AC(Unk8005231C *movie) {
    Unk8005231C_Info *info = movie->info;

    movie->unk40 = info->mode;
    movie->unk34 = movie->unk30 = D_800A333C;
    movie->unk74 = 0;
    movie->unk38 = 0;
    movie->unk3C = -1;
    movie->rect[0].x = info->rect[0].x;
    movie->rect[0].y = info->rect[0].y;
    movie->rect[0].w = info->rect[0].w;
    movie->rect[0].h = info->rect[0].h;
    movie->rect[1].x = info->rect[1].x;
    movie->rect[1].y = info->rect[1].y;
    movie->rect[1].w = info->rect[1].w;
    movie->rect[1].h = info->rect[1].h;
    if (movie->unk34 == 0) {
        movie->slice.x = info->rect[0].x;
        movie->slice.y = info->rect[0].y;
        movie->slice.w = 16;
        movie->slice.h = info->rect[0].h;
    } else {
        movie->slice.x = info->rect[1].x;
        movie->slice.y = info->rect[1].y;
        movie->slice.w = 16;
        movie->slice.h = info->rect[1].h;
    }
}

typedef struct {
    s16 x, y;
    s32 pad;
} Unk8005286C_Entry;

typedef struct {
    u8 pad0[0x18];
    Unk8005286C_Entry unk18[2];
    s16 unk28;
    s16 unk2A;
    u8 pad2C[8];
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x10];
    s32 unk4C;
} Unk8005286C;

extern struct {
    u8 pad[0x1C];
    Unk8005286C *unk1C;
} *D_801F7D64;

extern void LoadImage(RECT *rect, u32 *p);
extern void DecDCTout(u32 *buf, s32 size);

void func_80052488(void) {
    Unk8005231C *movie = (Unk8005231C *)D_801F7D64->unk1C;
    int rem;

    LoadImage(&movie->slice, movie->imgbuf[movie->unk74]);
    movie->unk74 = !movie->unk74;
    rem = movie->rect[movie->unk34].w % 16;
    if (movie->unk50 && rem) {
        movie->slice.x += rem;
        movie->unk50 = 0;
    } else {
        movie->slice.x += 16;
    }
    if (movie->slice.x < movie->rect[movie->unk34].x + movie->rect[movie->unk34].w) {
        DecDCTout(movie->imgbuf[movie->unk74], ((movie->slice.w - 1) / 16 + 1) * (((movie->slice.h - 1) / 16 + 1) << 8) >> 1);
    } else {
        movie->unk38 = 1;
        movie->unk50 = 1;
        movie->unk34 = !movie->unk34;
        movie->slice.x = movie->rect[movie->unk34].x;
        movie->slice.y = 31;
    }
}

typedef struct {
    u16 id;
    u16 type;
    u16 secCount;
    u16 nSectors;
    u32 frameCount;
    u32 frameSize;
    u16 width;
    u16 height;
    u32 headm;
    u32 headv;
} StHEADER;

extern s32 StGetNext(u32 **addr, u32 **header);
extern s32 StFreeRing(u32 *base);
extern s16 D_800A33EC;

u32 *func_800525F8(Unk8005231C *dec) {
    RECT rect;
    u32 *addr;
    StHEADER *sector;
    s32 cnt = 60000;

    while (StGetNext(&addr, (u32 **)&sector)) {
        if (--cnt == 0) {
            return NULL;
        }
    }
    dec->unk72++;
    if (addr[0] != sector->headm || addr[1] != sector->headv) {
        StFreeRing(addr);
        return NULL;
    }
    if (!dec->unk54) {
        dec->unk44 = dec->unk48 / 2048;
        dec->unk44 = dec->unk44 / sector->nSectors;
        dec->unk54 = 1;
    }
    if (sector->frameCount >= dec->info->end || sector->frameCount < dec->unk70) {
        dec->unk4C = 1;
    }
    if (sector->frameCount >= dec->info->end - 20) {
        D_800A33EC = -1;
    }
    dec->unk70 = sector->frameCount;
    if (dec->unk58 != sector->width || dec->unk5C != sector->height) {
        dec->unk58 = sector->width;
        dec->unk5C = sector->height;
        rect.x = 0;
        rect.y = 0;
        rect.w = dec->unk58;
        rect.h = dec->unk5C;
    }
    dec->rect[0].w = dec->rect[1].w = dec->unk58;
    dec->rect[0].h = dec->rect[1].h = dec->unk5C;
    dec->slice.h = dec->unk5C;
    return addr;
}

typedef struct {
    u32 *vlcbuf[2];
    u8 pad8[0x28];
    s32 vlcid;
} Unk800527E8;

extern s32 DecDCTvlc(u32 *bs, u32 *buf);
extern s32 StFreeRing(u32 *base);
u32 *func_800525F8(Unk8005231C *dec);

s32 func_800527E8(Unk800527E8 *dec) {
    u32 *frame;
    s32 tries;

    for (tries = 100; tries != 0;) {
        frame = func_800525F8((Unk8005231C *)dec);
        tries--;
        if (frame != NULL) {
            dec->vlcid ^= 1;
            DecDCTvlc(frame, dec->vlcbuf[dec->vlcid]);
            StFreeRing(frame);
            return 0;
        }
    }
    return -1;
}

void func_8005286C(void) {
    Unk8005286C *p = D_801F7D64->unk1C;
    volatile s32 timeout = 60000;

    while (p->unk38 == 0) {
        if (--timeout == 0) {
            p->unk38 = 1;
            p->unk34 = !p->unk34;
            p->unk28 = p->unk18[p->unk34].x;
            p->unk2A = p->unk18[p->unk34].y;
        }
    }
    p->unk38 = 0;
}

s32 func_80052910(void) {
    D_801F7D64->unk1C->unk4C = -1;
    return 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80052930);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B0C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B14);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B1C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B24);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B2C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B30);

extern s16 D_800A34BC;
extern s16 D_800A30CC;
extern void DecDCTin(u32 *buf, s32 mode);
extern void func_80074D48(void);
extern void CdDataCallback(void (*func)());
extern void CdReadyCallback(void (*func)());

void func_80052C14(void) {
    Unk8005231C *movie = (Unk8005231C *)D_800A317C->vals;
    s16 ok;
    u8 param[8];

    if (D_800A34BC != 0) {
        ok = -1;
        D_800A34BC = ok;
        if (D_800A30CC != 0) {
            ok = --D_800A30CC != 0 ? -1 : 0;
        }
        if (movie->unk4C == 0 && ok) {
            DecDCTin(movie->vlcbuf[movie->unk30], movie->unk60);
            DecDCTout(movie->imgbuf[movie->unk74], ((movie->slice.w - 1) / 16 + 1) * (((movie->slice.h - 1) / 16 + 1) << 8) >> 1);
            if (func_800527E8((Unk800527E8 *)movie) == -1) {
                func_80052DB8();
                func_8003E3CC();
            } else {
                func_8005286C();
                movie->unk3C = 0;
                return;
            }
        } else {
            param[0] = 0x80;
            CdControlB(0xE, param, 0);
            DecDCToutCallback(0);
            func_80074D48();
            CdDataCallback(0);
            CdReadyCallback(0);
            CdControlB(9, 0, 0);
            func_8005010C(D_800A350C->unk1784 * 4, 0);
        }
        D_800A34BC = 0;
    }
    func_80021554();
}

void func_80052DB8(void) {
    u8 param[4];

    DecDCTReset(0);
    param[0] = 0x80;
    CdControlB(0xE, param, 0);
    DecDCToutCallback(0);
    CdDataCallback(0);
    CdReadyCallback(0);
    CdControlB(9, 0, 0);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} Unk80052E18;

extern s16 D_800A347C;
void func_80052E88(void);

void func_80052E18(s32 arg0) {
    Unk8003BA6C_Task *task;
    Unk80052E18 *d;

    task = func_80021264(func_80052E88, 4, 0x12);
    if (task != NULL) {
        d = (Unk80052E18 *)task->data;
        D_800A347C = -1;
        d->unk0 = 0;
        d->unk2 = 0;
        d->unk4 = arg0;
        d->unk8 = 0x280;
        d->unkA = 0;
        d->unkC = 0x140;
        d->unkE = 0x100;
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
    s16 x2, y2;
    s16 x3, y3;
} Unk80052E88_Prim;

typedef struct {
    u32 tag;
    u32 code[2];
} DR_MODE;

typedef struct {
    s16 state;
    s16 alpha;
    s16 next;
    u8 pad6[2];
    RECT rect;
    s16 timer;
} Unk80052E88;

extern RECT D_800A2B14;
extern void (*D_80080EF4[])(void);
extern void *D_800A3094;
extern s16 D_800A335C;
extern s16 D_800A327C;
extern void StoreImage(RECT *rect, u32 *p);
extern void func_80050044(void);
extern void func_80050844(void);
extern void func_800689BC(void);
extern u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
extern void SetDrawMode(DR_MODE *p, s32 dfe, s32 dtd, s32 tpage, RECT *tw);

void func_80052E88(void) {
    Unk80052E88 *d = (Unk80052E88 *)D_800A317C->vals;
    RECT unused = D_800A2B14;
    Unk80052E88_Prim *p;

    switch (d->state) {
    case 0:
        d->alpha += 16;
        if (d->alpha == 0x100) {
            d->alpha = 0xFF;
        }
        if (d->alpha > 0x100) {
            D_800A327C = 0;
            d->alpha = 0xFF;
            d->timer = 2;
            d->state++;
        }
        func_8004FFE0(0x4000 - (d->alpha << 6), 0);
        break;
    case 1:
        if (d->timer != 0) {
            d->timer--;
            break;
        }
        func_80020340();
        if (D_800A335C != 0) {
            DrawSync(0);
            StoreImage(&d->rect, (u32 *)D_800A30B4);
            DrawSync(0);
            D_800A335C = 0;
            D_800A33E4 = D_800A3094;
        }
        if (D_800A2FFC != 0) {
            func_800689BC();
            D_800A2FFC = 0;
        }
        D_80080EF4[d->next]();
        d->state++;
        func_80050044();
        func_80050844();
        break;
    case 2:
        d->alpha -= 16;
        if (d->alpha < 0) {
            d->alpha = 0;
            D_800A347C = 0;
            func_80021554();
        }
        func_8004FFE0(0x4000 - (d->alpha << 6), 0);
        break;
    }
    p = D_800A3374;
    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 320;
    p->y1 = 0;
    p->x2 = 0;
    p->y2 = D_800A33C4;
    p->x3 = 320;
    p->y3 = D_800A33C4;
    p->r0 = d->alpha;
    p->g0 = d->alpha;
    p->b0 = d->alpha;
    setlen(p, 5);
    setcode(p, 0x2A);
    addPrim(D_800A32E4, p);
    p++;
    SetDrawMode((DR_MODE *)p, 1, 1, GetTPage(0, 2, 0, 0x100), NULL);
    addPrim(D_800A32E4, (DR_MODE *)p);
    D_800A3374 = (DR_MODE *)p + 1;
}

extern RECT D_800A2B1C;
extern s32 ClearImage(RECT *rect, u8 r, u8 g, u8 b);
extern s32 DrawSync(s32 mode);
extern void SetDispMask(s32 mask);
extern u32 *ClearOTagR(u32 *ot, s32 n);
extern u32 D_800A80E8[];
extern u32 D_800B5D10[];
extern s16 D_800A3514;
extern s16 D_800A315C;
extern s16 D_801D209C;
extern void func_8001F778(void);
extern void func_8001ED6C(void);
extern void func_80020468(void);

void func_800531B0(void) {
    RECT rect = D_800A2B1C;

    D_800A3514 = 0;
    func_80021698(0xF);
    SetDispMask(0);
    DrawSync(0);
    VSync(0);
    ClearOTagR(D_800A80E8, 0xA00);
    ClearOTagR(D_800B5D10, 0xA00);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    func_8001F778();
    if (D_801D209C < 0) {
        D_800A315C = -1;
    }
    func_8001ED6C();
    D_800A2F0C = 11;
    func_80020468();
    D_800A3514 = 0;
    ((struct Task *)D_801F7D24)->vals->pad0 = 0;
}

extern s16 D_800A34C4;
extern s16 D_800A346C;
extern void func_800534E0(void);
extern void func_80060370();

void func_800532BC(void) {
    s16 r;
    Unk8003BA6C_Task *task;

    func_80021698(0xF);
    func_8001FDE4();
    D_800A2F14 = 0;
    switch (D_800A307C) {
    case 3:
    case 8:
    case 13:
    case 18:
    case 22:
        if (D_800A2F74 == 0) {
            D_800A2EF0 = 0;
            D_800A307C++;
            r = 0;
        } else {
            D_800A2F14 = -1;
            D_800A2EF0 = -1;
            r = 0;
        }
        break;
    case 4:
    case 9:
    case 14:
    case 19:
    case 23:
        r = -(D_800A2EF0 != 0);
        break;
    default:
        r = 0;
        break;
    }
    if (D_801D209C >= 0) {
        if (D_800A34C4 == 0) {
            D_800A346C = 0;
        } else {
            D_800A346C = 4;
        }
    } else {
        D_800A346C = 1;
    }
    if (D_800A346C != 1) {
        if (r == 0) {
            func_800403C8();
            D_800A2F0C = 1;
            D_800A2FEC = 0;
            func_80021264(func_8003E85C, 1, 0x2C);
        } else {
            task = func_80021264(func_80060370, 1, 0x324);
            if (task != NULL) {
                D_800A2F0C = 6;
                task->data->unk0 = 0;
            }
        }
    } else {
        func_800534E0();
    }
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B034);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B040);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B04C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B060);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B070);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B090);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B0A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B0B4);

extern void func_80021698(s16);
extern void func_80052930(s32, s32);
extern void func_8006A4C4(void);
extern void func_8006A6A8(void);
extern void func_80053538();
extern s16 D_800A2F0C;
extern u8 D_801C1B9E;

void func_80053464(void) {
    Unk8003BA6C_Data *data;

    func_80021698(3);
    data = func_80021264(func_80053538, 1, 4)->data;
    D_800A2F0C = 7;
    func_8006A4C4();
    D_801C1B9E = 100;
    func_8006A6A8();
    data->unk0 = 16;
    data->unk2 = 0;
    func_80052930(1, -1);
}

void func_800534E0(void) {
    Unk8003BA6C_Task *task;
    Unk8003BA6C_Data *data;

    task = func_80021264(func_80053538, 1, 4);
    D_800A2F0C = 8;
    data = task->data;
    data->unk0 = 0x10;
    data->unk2 = 1;
    func_80052930(2, -1);
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk80053538;

extern char D_8007B034[];
extern char D_8007B040[];
extern u8 D_800A2A3C[];
extern u8 D_800A2A40[];
extern s16 D_800A33EC;
extern volatile u16 D_800A32AC[];
extern s16 D_800A30CC;

void func_80053538(void) {
    Unk80053538 *d = (Unk80053538 *)D_800A317C->vals;

    if (d->unk2 != 0) {
        func_80053864(160, D_800A33C4 >> 1, D_8007B034, 0x800, 0x400, D_800A2A3C, D_800A2A40);
    } else {
        func_80053864(160, D_800A33C4 >> 1, D_8007B040, 0x800, 0x400, D_800A2A3C, D_800A2A40);
    }
    if (d->unk0 != 0) {
        d->unk0--;
    } else if (D_800A33EC != 0 || (d->unk2 != 0 && ((D_800A32AC[0] & 0x40) || (D_800A32AC[0] & 0x800)))) {
        D_800A30CC = 15;
        func_80052E18(10);
        d->unk0 = -1;
    }
}

extern RECT D_800A2B1C;
extern s32 ClearImage(RECT *rect, u8 r, u8 g, u8 b);
extern s32 DrawSync(s32 mode);
extern void func_80020D60(void);
extern void func_80060370();

void func_8005366C(void) {
    RECT rect = D_800A2B1C;
    Unk8003BA6C_Task *task;

    func_80021698(3);
    task = func_80021264(func_80060370, 1, 0x324);
    if (task != NULL) {
        D_800A2F0C = 6;
        task->data->unk0 = 0;
        ClearImage(&rect, 0, 0, 0);
        DrawSync(0);
        func_80020D60();
    }
}

extern void func_800619C8(void);
extern void func_80063D8C(void);
extern s16 D_800A3114;

void func_80053710(void) {
    func_80021698(0xF);
    func_80021264(func_800619C8, 1, 0x16);
    func_80021264(func_80063D8C, 3, 0xE);
    D_800A3114 = 2;
    D_800A2F0C = 6;
}

extern s32 D_80080F24[];
extern s8 D_801FC098[];
extern s16 func_80054C70(void *data, s32 a1);

void func_80053770(void) {
    s16 i;

    for (i = 0; i < D_80080F24[0]; i++) {
        D_801FC098[i] = (func_80054C70(func_8003E414(D_80080F24, i), -1) << 5) / 200;
    }
    i = 9;
    do {
        D_801FC098[i] = 30;
    } while (i--);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80053864);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800540F4);

extern s16 D_800A3494;

void func_800544A8(s16 x, s16 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800A3494 = -1;
    func_80053864(x, y, text, a3, a4, a5, a6);
}

extern char D_801C1B8C[];

void func_800544F8(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    short i, j;

    i = len - 1;
    if (len != 0) {
        do {
            D_801C1B8C[i] = value % 10 + '0';
            value /= 10;
            j = i;
            i--;
        } while (j != 0);
    }
    D_801C1B8C[len] = 0;
    func_80053864(x, y, D_801C1B8C, d, a, b, c);
}

void func_800545BC(short x, short y, int value, int d, int a, u8 *b, u8 *c) {
    short i, j;

    value = ABS(value);
    i = 9;
    do {
        D_801C1B8C[i] = value % 10 + '0';
        value /= 10;
        j = i;
        i--;
    } while (j != 0);
    for (i = 0; i < 10; i++) {
        if (D_801C1B8C[i] != '0') {
            func_80053864(x, y, &D_801C1B8C[i], d, a, b, c);
            return;
        }
    }
    func_80053864(x, y, &D_801C1B8C[9], d, a, b, c);
}

void func_800540F4(short x, short y, char *str, int d, int a, int b, int c);

void func_800546EC(short x, short y, unsigned int value, int d, int a, int b, int c, short len) {
    short i, j;

    i = len - 1;
    if (len != 0) {
        do {
            D_801C1B8C[i] = value % 10 + '0';
            value /= 10;
            j = i;
            i--;
        } while (j != 0);
    }
    D_801C1B8C[len] = 0;
    func_800540F4(x, y, D_801C1B8C, d, a, b, c);
}

void func_800547B0(short x, short y, int value, int d, int a, int b, int c) {
    short i, j;

    value = ABS(value);
    i = 9;
    do {
        D_801C1B8C[i] = value % 10 + '0';
        value /= 10;
        j = i;
        i--;
    } while (j != 0);
    for (i = 0; i < 10; i++) {
        if (D_801C1B8C[i] != '0') {
            func_800540F4(x, y, &D_801C1B8C[i], d, a, b, c);
            return;
        }
    }
    func_800540F4(x, y, &D_801C1B8C[9], d, a, b, c);
}

void func_800548E0(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    D_800A3494 = -1;
    func_800544F8(x, y, value, d, a, b, c, len);
}

void func_80054940(s16 x, s16 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800A3494 = -1;
    func_800545BC(x, y, text, a3, a4, a5, a6);
}

typedef struct {
    s16 x;
    s16 y;
    s16 val;
} Unk800692B4_Arg;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
} Unk80054990_F3;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    s32 xy3;
} Unk80054990_F4;

typedef struct {
    SVECTOR *v[4];
    u16 unk10;
    s16 tri;
} Unk80054990_Face;

typedef struct {
    u8 pad[0xC];
    u16 count;
    u8 padE[6];
    Unk80054990_Face face[1];
} Unk80054990_Model;

extern SVECTOR D_800A2B24;
extern VECTOR D_8007B060;
extern void SetPolyF3(void *p);
extern void SetPolyF4(void *p);

s32 func_80054990(void *data, Unk800692B4_Arg *arg) {
    Unk80054990_Model *m = (Unk80054990_Model *)data;
    SVECTOR unused;
    SVECTOR rot = D_800A2B24;
    VECTOR scale = D_8007B060;
    Unk80054990_Face *f;
    u32 *ot;
    s16 n;

    if (m == NULL) {
        return 0;
    }
    D_801C1EC4.vx = arg->x - 0xA0;
    D_801C1EC4.vy = arg->y - 0xB4;
    D_801C1EC4.vz = arg->val;
    PushMatrix();
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    func_8002384C(&rot, &D_801FB868);
    ScaleMatrix(&D_801FB868, &scale);
    SetRotMatrix(&D_801FB868);
    f = m->face;
    n = m->count;
    while (n--) {
        if (f->tri != 0) {
            Unk80054990_F3 *p = D_800A3374;

            D_800A326C = RotTransPers3(f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy2, &D_800A2EFC, &D_800A3394);
            if (!(D_800A3394 & ~0x1FFF)) {
                SetPolyF3(p);
                p->b0 = p->g0 = p->r0 = 0;
                ot = D_800A32E4;
                if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                    AddPrim(ot, p++);
                }
                D_800A3374 = p;
            }
        } else {
            Unk80054990_F4 *p = D_800A3374;

            D_800A326C = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy3, &p->xy2, &D_800A2EFC, &D_800A3394);
            if (!(D_800A3394 & ~0x1FFF)) {
                SetPolyF4(p);
                p->b0 = p->g0 = p->r0 = 0;
                ot = D_800A32E4;
                if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                    AddPrim(ot, p++);
                }
                D_800A3374 = p;
            }
        }
        f++;
    }
    PopMatrix();
    return -1;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80054C70);

extern volatile u16 D_800A343C[];

void func_80054F48(void) {
    if ((D_800A343C[0] & 0x2000) || (D_800A343C[0] & 0x40)) {
        D_800A350C->unk1780++;
    }
    if (D_800A343C[0] & 0x8000) {
        D_800A350C->unk1780--;
    }
    D_800A350C->unk1780 &= 7;
}

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C[5];
    s16 unk26[5];
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
} Unk80054FEC;

void func_80054FEC(Unk80054FEC *obj) {
    s16 i;

    obj->unk3A = 0;
    for (i = 0; i < 5; i++) {
        obj->unk26[i] = 0;
        obj->unk1C[i] = 0x1000;
    }
    obj->unk32 = 0;
    obj->unk26[0] = 2;
    obj->unk36 = 0;
}

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} Unk8005503C;

extern s16 D_801C1ED6;
extern u8 D_80084B64[];
extern void func_80054FEC();

void func_8005503C(Unk8005503C *obj) {
    D_801C1ED6 = 0;
    obj->unk18 = (s32)D_80084B64;
    func_80054FEC(obj);
}

typedef struct {
    u8 pad0[0x34];
    s16 unk34;
    u8 pad36[8];
    s16 unk3E;
} Unk8005506C;

void func_8005506C(Unk8005506C *obj) {
    obj->unk34 = 0;
}

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} Unk80055074;

extern s32 D_800A8034[];
extern void func_80054FEC();

void func_80055074(Unk80055074 *obj, s16 i) {
    obj->unk18 = D_800A8034[i];
    func_80054FEC(obj);
}

void func_800550A8(Unk8005506C *obj) {
    obj->unk3E = -1;
}

extern s16 D_800A356C;

void func_800550B4(Unk8005506C *obj) {
    obj->unk3E = -1;
    D_800A356C = 2;
}

void func_800550D0(void) {
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 r1, g1, b1, pad1;
    s16 x1, y1;
    u8 r2, g2, b2, pad2;
    s16 x2, y2;
    u8 r3, g3, b3, pad3;
    s16 x3, y3;
} Unk800550D8_Prim;

extern void SetPolyG4(void *p);

void func_800550D8(s16 t, s32 y) {
    s16 top = y - 8;
    s16 bottom = y + 8;
    Unk800550D8_Prim *p = D_800A3374;
    s32 y2 = y;
    u32 *ot;
    s16 c;

    p->x0 = p->x2 = 0xD2;
    p->x1 = p->x3 = 0x12A;
    p->y0 = p->y1 = top;
    p->y2 = p->y3 = bottom;
    p->r0 = 0x64;
    p->g0 = 0;
    p->b0 = 0;
    p->r2 = 0x64;
    p->g2 = 0;
    p->b2 = 0;
    p->r3 = 0xA0;
    p->g3 = 0x3C;
    p->b3 = 0x1E;
    p->r1 = 0xA0;
    p->g1 = 0x3C;
    p->b1 = 0x1E;
    SetPolyG4(p);
    ot = D_800A32E4 + 2;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    p->x0 = p->x2 = func_800296F8(0xD2, 0x116, t);
    p->x1 = p->x3 = func_800296F8(0xD6, 0x12A, t);
    p->y0 = p->y1 = y2 - 9;
    p->y2 = p->y3 = y2 + 9;
    c = func_800296F8(0x78, 0xFF, t);
    p->r0 = c;
    p->g0 = c;
    p->b0 = c;
    p->r1 = c;
    p->g1 = c;
    p->b1 = c;
    c >>= 1;
    p->r2 = c;
    p->g2 = c;
    p->b2 = c;
    p->r3 = c;
    p->g3 = c;
    p->b3 = c;
    SetPolyG4(p);
    ot = D_800A32E4 + 1;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, p++);
    }
    D_800A3374 = p;
}

typedef struct {
    u8 pad0[0x48];
    struct {
        u16 unk48;
        u8 pad4A[2];
        s32 unk4C;
        u8 pad50[0x28];
    } e[1];
} Unk80055298_Table;

typedef struct {
    u8 pad0[0x18];
    Unk80055298_Table *unk18;
    u8 pad1C[0x16];
    s16 unk32;
    u8 pad34[0x12];
    s16 unk46;
} Unk80055298;

void func_80055298(Unk80055298 *obj) {
    Unk80055298_Table *t = obj->unk18;
    u16 state = t->e[obj->unk32].unk48;
    s32 params[6];

    if (D_800A32AC[0] & 0x2000) {
        t->e[obj->unk32].unk4C = func_800437C8((s16)t->e[obj->unk32].unk4C, 0x1000, 0x80);
    }
    if (D_800A32AC[0] & 0x8000) {
        t->e[obj->unk32].unk4C = func_800437C8((s16)t->e[obj->unk32].unk4C, 0, 0x80);
    }
    switch ((s16)state) {
    case 0:
        func_8005010C(D_800A350C->unk1784 * 4, 0);
        obj->unk46 = -1;
        break;
    case 1:
        if ((D_800A343C[0] & 0x40) || (D_800A34CC[0] & 0x8000) || (D_800A34CC[0] & 0x2000)) {
            params[0] = 6;
            params[1] = 0x3FFF;
            params[2] = 0;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
        }
        break;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005543C);

extern Unk800A8078 D_800A8078[2];
extern volatile s32 D_800A31F4;
extern void func_800207DC();
extern void func_8002076C(void);
extern void DrawOTag(u32 *ot);
extern s32 func_8006B350(unsigned long spec);
extern void func_8006B370(unsigned long spec);
extern DISPENV *PutDispEnv(DISPENV *env);
extern DRAWENV *PutDrawEnv(DRAWENV *env);

void func_80055D9C(void) {
    func_800207DC();
    func_8002076C();
    D_800A32AC[0] = D_800A3144[0];
    DrawOTag(D_800A32E4 + 0x9FF);
    DrawSync(0);
    VSync(0);
    while (D_800A31F4 < 3) {
        if (func_8006B350(0xF2000001) > 0x400) {
            break;
        }
    }
    func_8006B370(0xF2000001);
    D_800A31F4 = 0;
    PutDispEnv(&D_800A8078[D_800A333C].disp);
    ClearOTagR(D_800A32E4, 3);
    D_800A333C ^= 1;
    PutDrawEnv(&D_800A8078[D_800A333C].draw);
}

void func_80055EE0(void) {
    u8 unused[24];
}

typedef struct {
    char name[0x20];
    u16 key;
    u8 pad22[2];
    void (*func)(void *obj, s32 arg);
    s32 arg;
    u8 pad2C[4];
} MenuItem;

typedef struct {
    u8 pad0[0x1E];
    s16 back;
    MenuItem items[5];
} Menu;

typedef struct {
    u8 pad0[0x18];
    Menu *menu;
    s16 scale[5];
    s16 state[5];
    s16 unk30;
    s16 cursor;
} MenuObj;

extern u8 D_80084B64[];
extern char D_8007B070[];
extern char D_8007B090[];
extern u8 D_800A2A54[];
extern u8 D_800A2A58[];

void func_80055EEC(MenuObj *obj, s16 show, s16 y, s16 canBack) {
    Menu *m = obj->menu;
    MenuItem *item = &m->items[obj->cursor];
    s32 params[6];

    if (item->key == 0) {
        func_80055298((Unk80055298 *)obj);
    }
    if (D_800A343C[0] & 0x4000) {
        obj->state[obj->cursor] = 0;
        obj->cursor++;
        if (m->items[obj->cursor].name[0] == 0 || obj->cursor >= 5) {
            obj->cursor = 0;
        }
        obj->state[obj->cursor] = 2;
        obj->scale[obj->cursor] = 0x1000;
        params[0] = 0x1F;
        params[1] = 0x1000;
        params[2] = 0;
        params[3] = 0x400;
        params[4] = 0;
        params[5] = 0;
        func_8004FB78(params);
    }
    if (D_800A343C[0] & 0x1000) {
        obj->state[obj->cursor] = 0;
        obj->cursor--;
        if (obj->cursor == -1) {
            obj->cursor = 4;
            if (m->items[4].name[0] == 0) {
                do {
                    obj->cursor--;
                } while (m->items[obj->cursor].name[0] == 0);
            }
        }
        obj->state[obj->cursor] = 2;
        obj->scale[obj->cursor] = 0x1000;
        params[0] = 0x1F;
        params[1] = 0x1000;
        params[2] = 0;
        params[3] = 0x400;
        params[4] = 0;
        params[5] = 0;
        func_8004FB78(params);
    }
    if ((s16)D_800A343C[0] & item->key) {
        if (item->key != 0xFFFF) {
            params[0] = 0x1F;
            params[1] = 0x1000;
            params[2] = 0;
            params[3] = 0x800;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
        }
        item->func(obj, item->arg);
    }
    if (D_800A343C[0] & 0x10) {
        if (m != (Menu *)D_80084B64 && canBack && m->back) {
            func_80055074((Unk80055074 *)obj, m->back);
        }
    }
    if (show) {
        if (item->key == 0 || item->key > 0xFFF0) {
            func_80053864(160, y, D_8007B070, 0x400, 0x200, D_800A2A54, D_800A2A40);
            func_800544A8(164, y + 2, D_8007B070, 0x400, 0x200, D_800A2A58, D_800A2A58);
        } else {
            func_80053864(160, y, D_8007B090, 0x400, 0x200, D_800A2A54, D_800A2A40);
            func_800544A8(164, y + 2, D_8007B090, 0x400, 0x200, D_800A2A58, D_800A2A58);
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800562CC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B34);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B38);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B3C);

typedef struct {
    u8 pad0[0x30];
    s16 unk30;
    u8 pad32[6];
    s16 unk38;
} Unk80056918;

extern s16 D_800A33AC;
extern s16 D_800A356C;
extern u8 D_80084B64[];
extern u8 D_80084C74[];
extern u8 D_80084D84[];
extern u8 D_80084E94[];
extern u8 D_80084FA4[];
extern u8 D_800850B4[];
extern u8 *D_800A8038;
extern u8 *D_800A8040;
extern u8 *D_800A8044;
extern u8 *D_800A8048;
extern u8 *D_800A804C;
extern u8 *D_800A8050;
void func_800562CC(void);

void func_80056918(void) {
    Unk80056918 *d;

    d = (Unk80056918 *)D_800A317C->vals;
    D_800A317C->unk28 = 0xFF;
    D_800A317C->unk29 = 0;
    D_800A317C->unk2A = 0xFF;
    d->unk30 = -1;
    d->unk38 = 0;
    D_800A33AC = 0;
    D_800A356C = 0;
    D_800A8038 = D_80084B64;
    D_800A8040 = D_80084C74;
    D_800A8044 = D_80084D84;
    D_800A8048 = D_80084E94;
    D_800A804C = D_80084FA4;
    D_800A8050 = D_800850B4;
    D_800A317C->func = func_800562CC;
}


void func_80056A64(void);

void func_800569DC(void) {
    void *task;
    Unk80056ADC *p;
    s16 i;

    task = func_80021264(func_80056A64, 1, 0xF2);
    if (task != NULL) {
        D_801F7D70 = task;
        p = D_801F7D70->unk1C;
        for (i = 0; i < 20; i++) {
            p->pos[i].vx = 0;
            p->pos[i].vy = 0;
            p->pos[i].vz = 0;
            p->unkA0[i] = 0;
            p->unkC8[i] = 0;
        }
        p->count = 0;
    }
}

typedef struct {
    char pad0[0xC8];
    s16 timers[20];
    s16 active;
} Unk80056A64;

void func_80056A64(void) {
    Unk80056A64 *d = (Unk80056A64 *)D_800A317C->vals;
    s16 i;
    int unused[4];

    for (i = 0; i < 20; i++) {
        if (d->timers[i] != 0) {
            if (--d->timers[i] == 0) {
                d->active--;
            }
        }
    }
}

void func_80056ADC(SVECTOR *v, s16 arg1) {
    Unk80056ADC *p = D_801F7D70->unk1C;
    s16 i;

    if (p->count == 20) {
        return;
    }
    for (i = 0; i < 20; i++) {
        if (p->unkC8[i] == 0) {
            p->pos[i].vx = v->vx;
            p->pos[i].vy = v->vy;
            p->pos[i].vz = v->vz;
            p->unkA0[i] = arg1;
            p->unkC8[i] = 3;
            p->count++;
            return;
        }
    }
}

s16 func_80056B8C(Unk8002A35C *from, s16 range) {
    Unk80056ADC *p = D_801F7D70->unk1C;
    s32 best;
    s16 found;
    s16 i;
    s32 d;

    if (p->count == 0) {
        return -1;
    }
    best = 0x7FFF0000;
    found = -1;
    for (i = 0; i < p->count; i++) {
        d = func_8002A35C(from, (Unk8002A35C *)&p->pos[i]) - p->unkA0[i];
        if (d < 0) {
            d = 0;
        }
        if (d < range && d < best) {
            best = d;
            found = i;
        }
    }
    return found;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80056C94);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005704C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800572F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B0E4);

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0x218];
    s16 radius;
} Unk80057918;

extern s16 D_800854C0[];

void func_80057918(Unk80057918 *p, s16 color) {
    Unk8002A35C v;
    s16 a;
    s16 r;
    s32 dx, dz;

    func_8002A270(&p->pos, color);
    for (a = 0; a < 0x1000; a += 0x80) {
        r = p->radius;
        dx = D_800854C0[a & 0xFFF] * r;
        dz = D_800854C0[(a + 0x400) & 0xFFF] * r;
        v.x = (dx >> 12) + p->pos.x;
        v.y = p->pos.y;
        v.z = p->pos.z - (dz >> 12);
        func_8002A270(&v, (p->radius >> 7) + 7);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80057A10);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B12C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B144);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B18C);

typedef struct {
    s16 v[5];
} Unk800582A0_Models;

extern Unk800582A0_Models D_8007B18C;

void func_800582A0(Unk800584A4 *obj, s16 type, s16 arg2) {
    Unk800582A0_Models models = D_8007B18C;

    obj->unk8 = 0;
    obj->unkA = func_8001E9DC(0x1000);
    obj->unkC = 0;
    obj->unk10 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk18 = 0x1000;
    obj->unk94 = 0x100;
    obj->unk98 = 0x200;
    obj->unk9C = 0x100;
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2;
    obj->unk80 = obj->unk4;
    obj->unk86 = obj->unkA;
    obj->unk20 = D_801D70F0[models.v[type - 66]];
    obj->unk2C = arg2 & 0x1F;
    obj->unk30 = arg2 >> 5;
    obj->unk2E = models.v[type - 66];
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800583AC);

extern struct {
    s32 unk0;
} D_801D7184;

void func_800584A4(Unk800584A4 *obj) {
    obj->unk8 = 0;
    obj->unk0 = (obj->unk0 & ~0x1FF) + 0x100;
    obj->unk4 = (obj->unk4 & ~0x1FF) + 0x100;
    obj->unkA = func_8001E9DC(0x1000);
    obj->unkC = 0;
    obj->unk10 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk18 = 0x1000;
    obj->unk20 = D_801D7184.unk0;
    obj->unk2C = 1;
}

extern Unk800584A4 *D_800A3564;
extern void func_8004DA48(void *obj, s16 *pos, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);

void func_80058520(void *arg0, void *arg1, Unk800584A4 *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];

    if (--obj->unk2C <= 0) {
        obj->unkA += 0x20;
        func_8004DA48(obj, &obj->unk8, 0x25, 0, 0x40, 0, 0x1000, 0x10, (s16)func_8001E9DC(0x200));
        obj->unk2C = 10;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800585D4);

extern s16 D_800A3074;

void func_80058788(void) {
    s16 i;
    s16 count;
    Unk800584A4 *obj;
    GridCell *cell;
    s16 col;
    s16 row;

    count = 0;
    for (i = 0; i < D_800A3074; i++) {
        obj = &D_800A3564[i];
        if (obj->unk28 == 0xFF00) {
            col = (obj->unk0 >> 9) + D_800A79F0.x;
            row = (obj->unk4 >> 9) + D_800A79F0.z;
            count++;
            cell = D_800A79F0.cells + D_800A79F0.w * row + col;
            cell->unk4 = 0;
            cell->unkA = 0;
            obj->unk2A = 0;
        }
    }
    D_800A3074 -= count;
}

typedef struct {
    s16 model;
    s16 animModel;
    s16 frames;
    s16 unk6;
} Unk80058898_Def;

typedef struct {
    s32 model;
    s16 flags[10];
    s16 frames;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
} Unk80058898_Anim;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    u8 pad24[8];
    Unk80058898_Anim anim;
    u8 pad50[0x2C];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    u8 pad82[0x12];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
} Unk80058898;

extern Unk80058898_Def D_800851C4[];

void func_80058898(Unk80058898 *obj, s16 type) {
    s16 idx = type - 72;
    s16 model = D_800851C4[idx].model;
    s16 animModel = D_800851C4[idx].animModel;
    Unk80058898_Anim *anim;
    s16 i;

    obj->unkC = 0;
    obj->unkA = 0;
    obj->unk8 = 0;
    obj->unk18 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk10 = 0x1000;
    obj->unk20 = D_801D70F0[model];
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2;
    obj->unk94 = 0x80;
    obj->unk80 = obj->unk4;
    obj->unk98 = D_800851C4[idx].unk6;
    obj->unk9C = 0x80;
    obj->unkA6 = 0;
    obj->anim.unk1A = 0;
    obj->anim.unk1C = 0;
    anim = &obj->anim;
    if (animModel != -1) {
        anim->model = D_801D70F0[animModel];
        anim->unk20 = anim->frames = D_800851C4[idx].frames;
        anim->unk1E = -1;
        for (i = 0; i < anim->frames; i++) {
            anim->flags[i] = 1;
        }
    } else {
        anim->unk1E = 0;
        anim->frames = 0;
        anim->unk1A = 0;
        anim->unk20 = 0;
    }
}

extern s16 D_801C1EFC;
extern u16 D_8008523C[];

void func_800589E8(void *arg0, void *arg1, Unk800584A4 *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];
    Unk8003516C_Faces *faces = &((Unk8003516C *)obj)->faces;
    Unk80032344_Face *f;
    s32 params[6];
    s16 i;

    if (obj->unk2A == 0) {
        return;
    }
    if (obj->unkA6 != 0) {
        func_8003516C((Unk8003516C *)obj);
        if (D_801C1EFC != 0) {
            params[0] = 0x2B;
            params[1] = func_80050974((SVECTOR *)obj, 0x3FFF);
            params[2] = func_800508F0((SVECTOR *)obj) * 4;
            params[3] = 0x500;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
        }
    }
    obj->unkA6 = 0;
    obj->unk86 = obj->unkA;
    func_80042538((Obj *)&obj->unk7C);
    func_80032344((Unk80032344 *)obj, 1);
    if (faces->state != 0) {
        obj->unk8 = D_8008523C[faces->state];
        obj->unkA += 0x10;
        faces->state--;
    }
    if (faces->left == 0) {
        return;
    }
    if (faces->timer != 0) {
        faces->timer--;
    }
    SetRotMatrix(&D_801FB868);
    SetTransMatrix(&D_801FB868);
    f = (Unk80032344_Face *)(faces->data + 8);
    for (i = 0; i < faces->count; i++, f++) {
        if (faces->used[i] != 0) {
            D_8007FF9C[f->flags & 0x1F](f);
        }
    }
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 pad4;
    s16 unk6;
    u8 r;
    u8 g;
    u8 b;
    u8 pad9;
    s16 unkC;
} Unk80058C04_Glow;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    u8 pad24[8];
    Unk80058C04_Glow glow;
    u8 pad3A[0x42];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    u8 pad82[4];
    s16 unk86;
    u8 pad88[0xC];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
} Unk80058C04;

void func_80058C04(Unk80058C04 *obj, s16 type, s16 flags) {
    s16 idx;
    s16 on;
    s16 dir;
    Unk80058C04_Glow *glow;

    obj->unk2 = (flags & 0x3F) << 6;
    on = flags & 0x80;
    dir = (flags & 0xC0) << 4;
    idx = type - 0x30;
    glow = &obj->glow;
    obj->unk2 += D_80080A18[D_800A307C];
    obj->unkC = 0;
    obj->unkA = 0;
    obj->unk8 = 0;
    obj->unk18 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk10 = 0x1000;
    obj->unk20 = D_801D70F0[idx];
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2 - 0x180;
    obj->unk80 = obj->unk4;
    obj->unkA6 = 0;
    obj->unk86 = 0;
    obj->unk94 = 0x60;
    obj->unk98 = 0x800;
    obj->unk9C = 0x60;
    obj->glow.unk0 = func_8001E9DC(0x1000);
    obj->glow.unk6 = 0x2FD4;
    if (idx == 11) {
        obj->glow.unk2 = -1;
    } else {
        obj->glow.unk2 = 0;
    }
    glow->unkC = 0;
    switch (idx) {
    case 0:
        if (on) {
            glow->r = 0x40;
            glow->g = 0x40;
            glow->b = 0x40;
        } else {
            glow->r = 0x10;
            glow->g = 0x10;
            glow->b = 0x40;
        }
        break;
    case 1:
        if (on) {
            glow->r = 0x40;
            glow->g = 0x10;
            glow->b = 0x40;
        } else {
            glow->r = 0x50;
            glow->g = 0x10;
            glow->b = 0x10;
        }
        break;
    case 2:
        if (on) {
            glow->r = 0x10;
            glow->g = 0x40;
            glow->b = 0x10;
            break;
        }
    case 11:
        glow->r = 0x40;
        glow->g = 0x40;
        glow->b = 0x10;
        break;
    case 42:
        glow->r = 0x10;
        glow->g = 0x40;
        glow->b = 0x10;
        glow->unk6 = 0x4000;
        obj->unk20 = D_801D70F0[62];
        obj->unkA = dir;
        glow->unkC = 999;
        break;
    case 43:
        glow->r = 0x10;
        glow->g = 0x40;
        glow->b = 0x10;
        glow->unk6 = 0x4000;
        obj->unk20 = D_801D70F0[63];
        obj->unkA = dir;
        glow->unkC = 999;
        break;
    case 44:
        glow->r = 0x40;
        glow->g = 0x10;
        glow->b = 0x10;
        glow->unk6 = 0x4000;
        obj->unk20 = D_801D70F0[64];
        obj->unkA = dir;
        glow->unkC = 999;
        break;
    }
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B250);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80058E74);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 pad4[2];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    s32 pad24[2];
    s16 unk2C;
} Unk8005942C;

extern u16 D_80080A18[];
extern s32 D_801D7084[];

void func_8005942C(Unk8005942C *obj, s16 idx, s32 angle) {
    s16 speed;
    s32 off;

    angle *= 64;
    obj->unk2 = angle;
    off = D_80080A18[D_800A307C];
    obj->unkC = 0;
    obj->unkA = 0;
    obj->unk8 = 0;
    obj->unk18 = 0x1000;
    obj->unk14 = 0x1000;
    obj->unk10 = 0x1000;
    obj->unk2 = angle + off;
    obj->unk20 = D_801D7084[idx];
    speed = func_8001E9DC(16) + 48;
    if ((s16)func_8001E9DC(2)) {
        speed = -speed;
    }
    obj->unk2C = speed;
}

void func_800594E4(void *arg0, void *arg1, Unk800584A4 *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];

    obj->unkA = (obj->unkA + obj->unk2C) & 0xFFF;
    func_80032344((Unk80032344 *)obj, 1);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80059540);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005963C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
    u8 pad24[0x58];
    s16 unk7C;
    s16 unk7E;
    s16 unk80;
    s16 pad82[2];
    s16 unk86;
    u8 pad88[0xC];
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 padA0[6];
    s16 unkA6;
} Unk80059BC4;

extern s32 D_801D70B8[];

void func_80059BC4(Unk80059BC4 *obj, s16 idx, s32 angle) {
    s16 scale[5] = { 0x1800, 0x1000, 0x1000, 0x1000, 0x1800 };
    SVECTOR ofs[5] = {
        { 0x280, 0x80, 0x80, 0 },
        { 0x100, 0x80, 0x300, 0 },
        { 0x100, 0x7E, 0x100, 0 },
        { 0x90, 0x340, 0x90, 0 },
        { 0xA0, 0x200, 0xA0, 0 },
    };

    obj->unkC = 0;
    obj->unk8 = 0;
    obj->unkA = angle << 9;
    obj->unk7C = obj->unk0;
    obj->unk7E = obj->unk2;
    obj->unk80 = obj->unk4;
    obj->unk94 = ofs[idx - 0x5D].vx;
    obj->unk98 = ofs[idx - 0x5D].vy;
    obj->unk9C = ofs[idx - 0x5D].vz;
    obj->unkA6 = 0;
    obj->unk86 = obj->unkA;
    obj->unk10 = obj->unk14 = obj->unk18 = scale[idx - 0x5D];
    obj->unk20 = D_801D70B8[idx];
}

void func_80059D64(void *arg0, void *arg1, Unk800584A4 *self) {
    Unk800584A4 *obj = &D_800A3564[self->unkA];

    func_80032344((Unk80032344 *)obj, 1);
    func_80042538((Obj *)&obj->unk7C);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80059DB8);

typedef struct {
    SVECTOR pos[4][4];
    SVECTOR vel[4][4];
    s16 unk100;
    s16 unk102;
    s16 unk104;
} Unk8005A22C;

void func_80059DB8(void);

void func_8005A22C(SVECTOR *pos, s16 arg1) {
    s16 dx[4] = {-1, 1, -1, 1};
    s16 dz[4] = {-1, -1, 1, 1};
    Unk8003BA6C_Task *t;
    Unk8005A22C *p;
    s16 i;
    s16 j;

    if (D_800A350C->unk1788 == 0) {
        return;
    }
    t = func_80021264(func_80059DB8, 3, 0x106);
    if (t == NULL) {
        return;
    }
    p = (Unk8005A22C *)t->data;
    for (i = 0; i < 4; i++) {
        D_800A34B4.vx = pos->vx + func_8001E9DC(0x100) - 0x80;
        D_800A34B4.vz = pos->vz + func_8001E9DC(0x100) - 0x80;
        for (j = 0; j < 4; j++) {
            p->vel[j][i].vx = ((s16)func_8001E9DC(0x80) + 0x80) * dx[j];
            p->vel[j][i].vz = ((s16)func_8001E9DC(0x80) + 0x80) * dz[j];
            p->pos[j][i].vx = D_800A34B4.vx;
            p->pos[j][i].vy = pos->vy;
            p->pos[j][i].vz = D_800A34B4.vz;
        }
    }
    p->unk102 = arg1;
    p->unk100 = 0x4000;
    p->unk104 = 0;
}

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B50);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B58);

typedef struct {
    SVECTOR pos;
    SVECTOR vel[16];
    SVECTOR out[16];
    s16 angle[16];
    s16 unk128[16];
    s16 unk148;
    u8 unk14A[16];
    u8 pad15A[0x10];
    s16 unk16A;
    s16 unk16C;
} Unk8005A42C;

extern SVECTOR D_800A2B50;
extern void func_8005A670();

void func_8005A42C(SVECTOR *pos, s32 arg1, s16 arg2) {
    s32 y;
    SVECTOR v = D_800A2B50;
    Unk8005A42C *d;
    Unk8003BA6C_Task *task;
    s16 n;
    s16 i;

    y = arg1;
    n = func_800296F8(0, arg2, D_800A350C->unk1788);
    if (n == 0) {
        return;
    }
    task = func_80021264(func_8005A670, 3, 0x16E);
    if (task == NULL) {
        return;
    }
    d = (Unk8005A42C *)task->data;
    d->unk16C = func_800296F8(4, 0x10, n);
    d->unk148 = func_800296F8(30, 100, n);
    d->unk16A = 0x1000;
    d->pos.vx = pos->vx;
    d->pos.vy = pos->vy;
    d->pos.vz = pos->vz;
    d->unk16C = 1;
    i = 15;
    PushMatrix();
    do {
        D_800A34B4.vx = func_8001E9DC(0x1000);
        D_800A34B4.vy = func_8001E9DC(0x1000);
        D_800A34B4.vz = func_8001E9DC(0x1000);
        func_80043E14(&D_800A34B4, &v, (SVECTOR *)&D_800A2A10, &d->out[i]);
        d->out[i].vx >>= 1;
        d->out[i].vz >>= 1;
        d->vel[i].vx = func_8001E9DC(15) - 7;
        d->vel[i].vy = func_8001E9DC(15) - 7 + y;
        d->vel[i].vz = func_8001E9DC(15) - 7;
        d->angle[i] = func_8001E9DC(0x1000);
        d->unk128[i] = func_800296F8((s16)(func_8001E9DC(0x300) - 0x180), 0, n);
        if ((s16)func_8001E9DC(2)) {
            d->unk14A[i] = 8;
        } else {
            d->unk14A[i] = 9;
        }
    } while (i--);
    PopMatrix();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005A670);

extern s16 D_801C1EFE;
extern u16 D_800852B0[][16];

u16 func_8005AB1C(buttons, config)
u16 buttons;
s16 config;
{
    u16 *map;
    u16 out;
    s16 i;

    if (D_801C1EFE != 0) {
        config += 3;
    }
    map = D_800852B0[config];
    out = 0;
    for (i = 0; i < 16; i++) {
        if ((buttons >> i) & 1) {
            out |= map[i];
        }
    }
    return out;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005ABA8);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} Unk8005B554_114;

typedef struct {
    s16 pad0;
    s16 unk2;
    u8 pad4[0xE];
    u16 unk12;
    u8 pad14[0x18];
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    u16 unk34;
    u8 pad36[0x16];
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 pad52[0x10];
    s16 unk62;
    u8 unk64[2];
    u16 unk66;
    u8 pad68[2];
    s16 unk6A;
    u8 pad6C[4];
    u32 unk70;
    u8 pad74[4];
    u16 unk78;
    u8 pad7A[0x36];
    s32 unkB0;
    u8 padB4[0xA];
    s16 unkBE;
    u8 padC0[6];
    s16 unkC6;
    u8 padC8[6];
    s16 unkCE;
    u8 padD0[0x20];
    s16 unkF0;
    u8 padF2[2];
    s16 unkF4;
    u8 padF6[2];
    s16 unkF8[3];
    s16 unkFE;
    u8 pad100[0x14];
    Unk8005B554_114 unk114;
} Unk8005B554;

void func_8005B0F0(Unk8005B554 *obj) {
    if (obj->unkCE > -0x20) {
        obj->unkCE = func_800437C8(obj->unkCE, -0x20, 8);
    } else {
        obj->unkCE = func_800437C8(obj->unkCE, -0x40, 2);
    }
}

void func_8005B144(Unk8005B554 *obj) {
    if (obj->unkCE < 0x20) {
        obj->unkCE = func_800437C8(obj->unkCE, 0x20, 8);
    } else {
        obj->unkCE = func_800437C8(obj->unkCE, 0x40, 2);
    }
}

void func_8005B198(Unk8005B554 *obj) {
    obj->unkCE = func_800437C8(obj->unkCE, 0, 0x10);
}

void func_8005B1CC(Unk8005B554 *obj) {
    obj->unk6A = func_800437C8(obj->unk6A, 200, 24);
    obj->unk50 = func_80031C58((Anim *)obj->unk64) << 1;
}

void func_8005B210(Unk8005B554 *obj) {
    obj->unk6A = func_800437C8(obj->unk6A, -200, 24);
    obj->unk50 = func_80031C58((Anim *)obj->unk64);
}

void func_8005B250(Unk8005B554 *obj) {
    Unk8005B554_114 *p = &obj->unk114;

    if (obj->unk6A != 0) {
        obj->unk6A = func_800437C8(obj->unk6A, 0, 24);
    }
    obj->unk50 = func_80031C58((Anim *)obj->unk64);
    if (obj->unk4C > 0) {
        obj->unk4C -= 8;
        if (obj->unk4C < 0) {
            obj->unk4C = 0;
        }
    } else if (obj->unk4C < 0) {
        obj->unk4C += 8;
        if (obj->unk4C > 0) {
            obj->unk4C = 0;
        }
    }
    if (obj->unk6A == 0 && (p->unkC != 0 || obj->unkF0 == 0)) {
        func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0, 8);
        obj->unk2C = 12;
    }
}

extern s16 D_800A2E84;

extern Entry16 *D_800A353C;

extern volatile u16 D_800A32AC[];

void func_8005B34C(Unk8005B554 *obj) {
    if (obj->unk2C == 9) {
        return;
    }
    if (obj->unk2C == 0) {
        if (D_800A32AC[0] & 0x1000) {
            obj->unk50 = 100;
        } else if (D_800A32AC[0] & 0x4000) {
            obj->unk50 = -50;
        } else {
            obj->unk50 = 0;
        }
    }
    obj->unk2C = 4;
    obj->unk2E = 200;
    if (obj->unk50 == 0) {
        func_80024DA8(obj->unk64, 0x13, 0, 0xB8, 1);
    } else {
        func_80024DA8(obj->unk64, 0x12, ((u16 *)D_800A353C[18].p)[10], 0xB8, 8);
    }
}

extern const s16 D_8007C590[];

void func_8005B428(Unk8005B554 *obj) {
    obj->unk2C = 1;
    func_80024DA8(obj->unk64, D_8007C590[obj->unkF4], 0, -350, 3);
    obj->unk4C = 0x30;
    obj->unk50 = 0;
}

void func_8005B488(Unk8005B554 *obj) {
    obj->unk2C = 2;
    func_80024DA8(obj->unk64, D_8007C590[obj->unkF4], 0, 350, 3);
    obj->unk4C = -0x30;
    obj->unk50 = 0;
}

void func_8005B4E8(Unk8005B554 *obj) {
    D_800A2E84 = 0;
    obj->unk2C = 5;
    func_80024DA8(obj->unk64, 0x14, 2000, 500, 3);
    obj->unk4C = 0x60;
    obj->unk50 = 0;
    obj->unkB0 = 0x1C0;
    obj->unk78 |= 1;
}

void func_8005B554(Unk8005B554 *obj) {
    D_800A2E84 = 0;
    obj->unk2C = 6;
    func_80024DA8(obj->unk64, 0x15, 2000, 500, 3);
    obj->unk4C = -0x60;
    obj->unk50 = 0;
    obj->unkB0 = 0x1C0;
    obj->unk78 |= 1;
}

void func_8005B5C0(Unk8005B554 *obj) {
    s32 params[6];

    if (obj->unkF8[obj->unkFE] != 0) {
        obj->unk2C = 7;
        obj->unk32 = 0x18;
        obj->unk4C = 0;
        obj->unk50 = 0;
        obj->unk34 = obj->unk12;
        func_80024DA8(obj->unk64, 0x16, 0x800, 0xA4, 4);
        if (obj->unk114.unk8 == 0 || --obj->unk114.unk8 == 0) {
            params[0] = 0x30;
            params[1] = 0x3FFF;
            params[2] = 0;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 1;
            params[3] += D_801C1EF6;
            func_8004FB78(params);
            obj->unk114.unk8 = func_8001E9DC(3) + 3;
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005B6AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B290);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B2A8);

extern void func_8005B6AC(Unk8005B554 *obj);

void func_8005BD54(Unk8005B554 *obj) {
    u16 *e = (u16 *)D_800A353C[obj->unk66].p;
    s32 params[6];

    switch (obj->unk114.unk6) {
    case 0:
        if (e[10] < obj->unk70) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = -0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 1;
        }
        break;
    case 1:
        if (obj->unk70 < e[10]) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = 0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 0;
        }
        break;
    }
    func_8005B6AC(obj);
    if (obj->unk2C == 7) {
        return;
    }
    if (D_800A343C[0] & 0x10) {
        func_8005B34C(obj);
    } else if (D_800A32AC[0] & 2) {
        func_8005B554(obj);
    } else if (D_800A32AC[0] & 1) {
        func_8005B4E8(obj);
    } else if (!(D_800A32AC[0] & 4) && (D_800A32AC[0] & 8)) {
        func_8005B488(obj);
    } else if (!(D_800A32AC[0] & 4)) {
        func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0, 8);
        obj->unk2C = 12;
        obj->unk4C = 0;
    }
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
    } else if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
    } else {
        func_8005B198(obj);
    }
}

extern void func_8005B428(Unk8005B554 *obj);
extern void func_8005B0F0(Unk8005B554 *obj);
extern void func_8005B144(Unk8005B554 *obj);
extern void func_8005B198(Unk8005B554 *obj);

void func_8005BFCC(Unk8005B554 *obj) {
    u16 *e = (u16 *)D_800A353C[obj->unk66].p;
    s32 params[6];

    switch (obj->unk114.unk6) {
    case 0:
        if (e[10] < obj->unk70) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = -0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 1;
        }
        break;
    case 1:
        if (obj->unk70 < e[10]) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = 0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 0;
        }
        break;
    }
    func_8005B6AC(obj);
    if (obj->unk2C == 7) {
        return;
    }
    if (D_800A343C[0] & 0x10) {
        func_8005B34C(obj);
    } else if (D_800A32AC[0] & 1) {
        func_8005B4E8(obj);
    } else if (D_800A32AC[0] & 2) {
        func_8005B554(obj);
    } else if (!(D_800A32AC[0] & 8) && (D_800A32AC[0] & 4)) {
        func_8005B428(obj);
    } else if (!(D_800A32AC[0] & 8)) {
        func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0, 8);
        obj->unk2C = 12;
        obj->unk4C = 0;
    }
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
    } else if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
    } else {
        func_8005B198(obj);
    }
}

extern const s16 D_8007C570[];
extern volatile u16 D_800A32AC[];

void func_8005C244(Unk8005B554 *obj) {
    if (D_800A2E84 != 0) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 0, 0);
        obj->unk2C = 0;
        obj->unk4C = 0;
        obj->unkB0 = 0x380;
        obj->unk78 &= ~1;
    }
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
    } else {
        func_8005B198(obj);
    }
}

void func_8005C2E8(Unk8005B554 *obj) {
    if (D_800A2E84 != 0) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 0, 0);
        obj->unk2C = 0;
        obj->unk4C = 0;
        obj->unkB0 = 0x380;
        obj->unk78 &= ~1;
    }
    if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
    } else {
        func_8005B198(obj);
    }
}

extern s16 D_800A311C;
extern void func_8005B1CC(Unk8005B554 *obj);
extern void func_8005B210(Unk8005B554 *obj);
extern void func_8005B488(Unk8005B554 *obj);

void func_8005C38C(Unk8005B554 *obj) {
    u16 *e = (u16 *)D_800A353C[obj->unk66].p;
    s32 params[6];

    switch (obj->unk114.unk6) {
    case 0:
        if (e[10] < obj->unk70) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = -0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 1;
        }
        break;
    case 1:
        if (obj->unk70 < e[10]) {
            params[0] = 0x21;
            params[1] = 0x800;
            params[2] = 0x400;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            func_80056ADC((SVECTOR *)obj, 1);
            obj->unk114.unk6 = 0;
        }
        break;
    }
    func_8005B6AC(obj);
    if (obj->unk2C == 7) {
        return;
    }
    if (D_800A343C[0] & 0x10) {
        func_8005B34C(obj);
    } else if (D_800A32AC[0] & 1) {
        func_8005B4E8(obj);
    } else if (D_800A32AC[0] & 2) {
        func_8005B554(obj);
    } else if (D_800A32AC[0] & 0x1000) {
        func_8005B1CC(obj);
        D_800A311C = 0x80;
    } else if (D_800A32AC[0] & 0x4000) {
        func_8005B210(obj);
        D_800A311C = -0x40;
    } else if (!(D_800A32AC[0] & 8) && (D_800A32AC[0] & 4)) {
        func_8005B428(obj);
    } else if (!(D_800A32AC[0] & 4) && (D_800A32AC[0] & 8)) {
        func_8005B488(obj);
    } else {
        func_8005B250(obj);
    }
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
    } else if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
    } else {
        func_8005B198(obj);
    }
}

void func_8005C658(Unk8005B554 *obj) {
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
    } else if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
    } else {
        func_8005B198(obj);
    }
    obj->unk2E = func_800437C8(obj->unk2E, -500, 24);
    if (obj->unk2E <= 0) {
        obj->unk2C = 8;
    }
}

extern s16 func_80023E80(void *obj, s32 *a, s32 *b);

void func_8005C6F0(Unk8005B554 *obj) {
    s16 y = obj->unkC6;
    s16 h;
    s32 tmp;

    h = func_80023E80(obj, &tmp, &tmp);
    if (y == -1) {
        y = h;
    } else if (y < h) {
        y = h;
    }
    if (y >= obj->unk2) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 200, 3);
        obj->unk2C = 0;
        obj->unk2E = 0;
        obj->unk2 = y;
        obj->unk4C = 0;
    } else {
        obj->unk2E = func_800437C8(obj->unk2E, -500, 24);
    }
    obj->unkC6 = -1;
}

typedef struct {
    u8 pad[0xFA];
    s16 unkFA;
    s16 unkFC;
    s16 unkFE;
} Unk8005C8D0;

extern void func_80036FAC(Unk8005B554 *obj, s16 i);
void func_8005C8D0(Unk8005C8D0 *p);

void func_8005C7C4(Unk8005B554 *obj) {
    int *info = D_800A353C[obj->unk66].p;

    obj->unk12 = obj->unk34;
    if (obj->unk32 != 0) {
        if (obj->unk70 >= ((u16 *)info)[10]) {
            func_80036FAC(obj, obj->unkFE);
            obj->unkF8[obj->unkFE]--;
            if (obj->unkF8[obj->unkFE] == 0) {
                func_8005C8D0((Unk8005C8D0 *)obj);
            }
            obj->unk32 = 0;
        }
    } else if (obj->unk6A + obj->unk70 >= info[0]) {
        obj->unk12 = obj->unk34;
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 0, 0);
        obj->unk2C = 0;
    }
}

void func_80051778(s16, s16);

void func_8005C8D0(Unk8005C8D0 *p) {
    if (++p->unkFE >= 3) {
        p->unkFE = 0;
    }
    switch (p->unkFE) {
        case 1:
            if (p->unkFA == 0) {
                if (p->unkFC != 0) {
                    p->unkFE = 2;
                } else {
                    p->unkFE = 0;
                }
            }
            break;
        case 2:
            if (p->unkFC == 0) {
                p->unkFE = 0;
            }
            break;
    }
    func_80051778(p->unkFE, 0);
}

extern const s16 D_8007C550[];

void func_8005C978(Unk8005B554 *obj) {
    Unk8005B554_114 *p = &obj->unk114;

    if (obj->unk70 > 0x400) {
        if (obj->unk50 != 0) {
            func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 0, 0);
            obj->unk2C = 0;
        } else {
            func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0, 0);
            obj->unk2C = 12;
        }
        obj->unk4C = 0;
        obj->unk78 &= ~1;
        p->unk2 = 20;
    }
    func_8005B198(obj);
}

void func_8005CA3C(void) {
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005CA44);

typedef struct {
    u8 pad0[0x114];
    u8 unk114;
} Unk8005CA98;

extern s16 D_800A32CC;
extern s32 D_800A339C;
void func_80050738(s32 arg0);
void func_80052E18(s32 arg0);

void func_8005CA98(Unk8005CA98 *obj) {
    if (obj->unk114 != 0) {
        obj->unk114--;
    } else {
        D_800A32CC = -1;
        func_80050738(D_800A339C);
        func_80052E18(4);
        obj->unk114 = 0xFF;
    }
}

void func_8005CB00(Unk8005B554 *obj) {
    Unk8005B554_114 *p = &obj->unk114;

    if (D_800A343C[0] & 0x80) {
        func_8005B5C0(obj);
        return;
    }
    if (D_800A343C[0] & 0x10) {
        func_8005B34C(obj);
    } else if (D_800A32AC[0] & 1) {
        func_8005B4E8(obj);
    } else if (D_800A32AC[0] & 2) {
        func_8005B554(obj);
    } else if (D_800A32AC[0] & 0x1000) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 24, 8);
        obj->unk2C = 0;
    } else if (D_800A32AC[0] & 0x4000) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, -24, 8);
        obj->unk2C = 0;
    } else if (!(D_800A32AC[0] & 8) && (D_800A32AC[0] & 4)) {
        func_8005B428(obj);
    } else if (!(D_800A32AC[0] & 4) && (D_800A32AC[0] & 8)) {
        func_8005B488(obj);
    } else if ((D_800A32AC[0] & 0x40) && p->unkC == 0) {
        func_80024DA8(obj->unk64, D_8007C570[obj->unkF4], 0, 0, 0);
        obj->unk2C = 0;
        obj->unkF0 = 0;
        func_8005B6AC(obj);
    }
    if (D_800A32AC[0] & 0x8000) {
        func_8005B0F0(obj);
        return;
    }
    if (D_800A32AC[0] & 0x2000) {
        func_8005B144(obj);
        return;
    }
    func_8005B198(obj);
}

void func_8005CD64(void) {
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005CD6C);

s32 func_8005D170(Unk8005B554 *obj) {
    switch (obj->unk2C) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 12:
        return -1;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return 0;
    }
    return 0;
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B2EC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B2FC);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005D1B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B310);

extern s32 D_800A2EE0;
extern s32 D_800A3034;
extern s16 D_800A3174;
extern s16 D_800A3574;
extern s16 D_800A336C;
extern s16 D_801C1EF6;
extern s32 func_8004FB78(s32 *params);
extern s16 func_8003A430(void *);
extern void func_8005D1B4(void);

void func_8005D610(void) {
    Unk8005B554 *obj = (Unk8005B554 *)D_800A317C->vals;
    s32 params[6];

    D_800A2E84 = 0;
    D_800A2EE0 = 0;
    D_800A3034 = 0;
    obj->unk114.unk2 = 0;
    obj->unk2C = 0;
    obj->unk6A = 0;
    obj->unk4C = 0;
    obj->unk4E = 0;
    obj->unk50 = 0;
    func_80024DA8((Anim *)obj->unk64, D_8007C570[obj->unkF4], 0, 200, 3);
    obj->unkBE = 0;
    obj->unk30 = 0;
    obj->unk2E = 0;
    obj->unk114.unk4 = -1;
    obj->unk114.unk6 = 0;
    obj->unk114.unkA = 0;
    obj->unk114.unkC = 0;
    obj->unk114.unkE = 0;
    func_80031320((Unk80045164 *)obj);
    D_800A317C->func = func_8005D1B4;
    D_800A3174 = -1;
    obj->unkC6 = -1;
    D_800A3574 = obj->unk62;
    switch (D_800A307C) {
    case 0:
    case 3:
    case 8:
    case 13:
    case 18:
    case 22:
        params[0] = 0x35;
        params[1] = 0x3FFF;
        params[2] = 0;
        params[3] = 0x400;
        params[4] = 0;
        params[5] = 1;
        params[3] = D_801C1EF6 + 0x400;
        func_8004FB78(params);
        break;
    }
    D_800A336C = obj->unk62;
    func_8003A430(obj);
}

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B3A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B3B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B3C0);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[0x8E];
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 pad9A[2];
    s16 unk9E;
} Unk8005D780;

s16 func_8005D780(Unk8005D780 *obj) {
    MATRIX unused;
    SVECTOR v[4];
    s32 tmp[2];
    s32 c;
    s32 s;
    s32 dx;
    s32 dz;
    s16 h0;
    s16 h1;
    s16 h2;
    s16 h3;
    s16 best;
    s16 d0;
    s16 d1;
    s16 d2;
    s16 d3;

    c = D_800854C0[(obj->unk9E + 0x400) & 0xFFF] * 100;
    s = D_800854C0[(obj->unk9E + 0x800) & 0xFFF] * 100;
    v[0].vy = v[1].vy = v[2].vy = v[3].vy = obj->y;
    dx = (c + s) >> 12;
    dz = (s - c) >> 12;
    v[0].vx = obj->unk94 - dx;
    v[0].vz = obj->unk98 - dz;
    v[2].vx = obj->unk94 + dx;
    v[2].vz = obj->unk98 + dz;
    dx = (c - s) >> 12;
    dz = (c + s) >> 12;
    v[1].vx = obj->unk94 - dx;
    v[1].vz = obj->unk98 - dz;
    v[3].vx = obj->unk94 + dx;
    v[3].vz = obj->unk98 + dz;
    h0 = func_80023E80(&v[0], tmp, tmp);
    h1 = func_80023E80(&v[1], tmp, tmp);
    h2 = func_80023E80(&v[2], tmp, tmp);
    h3 = func_80023E80(&v[3], tmp, tmp);
    d0 = obj->y - h0;
    d1 = obj->y - h1;
    d2 = obj->y - h2;
    d3 = obj->y - h3;
    best = h0;
    if (ABS(d0) > ABS(d1)) {
        best = h1;
        d0 = d1;
    }
    if (ABS(d0) > ABS(d2)) {
        best = h2;
        d0 = d2;
    }
    if (ABS(d0) > ABS(d3)) {
        best = h3;
    }
    return best;
}

extern char *strcpy(char *dst, const char *src);

void func_8005D9D4(s16 value, char *out) {
    char buf[20];
    s16 div = 10000;
    char *p = buf;
    s16 neg = 0;
    s16 i;
    s16 d;

    if (value < 0) {
        value = ABS(value);
        neg = -1;
    }
    for (i = 0; i < 5; i++) {
        d = value / div;
        *p++ = d + '0';
        value -= d * div;
        div /= 10;
    }
    *p = 0;
    for (i = 0; i < 4; i++) {
        if (buf[i] != '0') {
            break;
        }
        buf[i] = ' ';
    }
    if (neg) {
        *out = '-';
        strcpy(out + 1, buf);
    } else {
        strcpy(out, buf);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005DB40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B3CC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B41C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B42C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B440);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B450);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B464);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B5C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk8005E260_Data;

extern s16 D_800A329C;
void func_8005DB40();

void func_8005E260(s16 arg0, s16 seconds) {
    Unk8003BA6C_Task *task;
    Unk8005E260_Data *data;

    if (D_800A329C == 0) {
        task = func_80021264(func_8005DB40, 1, 8);
        if (task != NULL) {
            task->unk28 = 0;
            task->unk29 = 0x80;
            task->unk2A = 0xFF;
            data = (Unk8005E260_Data *)task->data;
            data->unk0 = 0;
            data->unk2 = seconds * 30 - 1;
            data->unk4 = arg0;
            data->unk6 = 0x1000;
            D_800A32CC = 0;
        }
    }
}

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 unk8[12];
    s16 unk20;
    s16 unk22;
    s16 unk24;
} Unk8005E478_Data;

extern void func_80060A80(Unk8002A35C *, s16, s16);

void func_8005E300(void) {
    Unk8005E478_Data *d = (Unk8005E478_Data *)D_800A317C->vals;
    Unk8002A35C v;
    s16 i;
    s16 a = d->unk22;
    s16 r;
    s32 dx, dz;

    for (i = 0; i < 12; i++, a += 0x55) {
        if (d->unk8[i] == 0) {
            r = d->unk20; dx = D_800854C0[a & 0xFFF] * r; dz = D_800854C0[(u16)(a + 0x400) & 0xFFF] * r;
            v.x = (dx >> 12) + d->x;
            v.y = d->y + 0x200;
            v.z = (dz >> 12) + d->z;
            func_80060A80(&v, a, 0xC0);
            d->unk8[i] = 6;
        } else {
            d->unk8[i]--;
        }
    }
    if ((d->unk20 += 0xC0) > d->unk24) {
        d->unk20 = d->unk24 - 0x800;
        d->unk24 -= 0x400;
        if (d->unk24 < 0x800) {
            d->unk24 = 0x800;
        }
    }
}

extern SVECTOR D_800A3194;

void func_8005E478(SVECTOR *pos) {
    Unk8002A35C *from = (Unk8002A35C *)D_801F7D44->vals;
    Unk8003BA6C_Task *task;
    Unk8005E478_Data *data;
    s16 i;

    task = func_80021264(func_8005E300, 1, 0x304);
    if (task != NULL) {
        data = *(Unk8005E478_Data **)((u8 *)task + 0x1C);
        data->x = pos->vx;
        data->y = pos->vy;
        data->z = pos->vz;
        data->unk20 = 0;
        data->unk22 = -func_80028B04(from, (Unk8002A35C *)&D_800A3194) + 0x600;
        data->unk24 = 0x1400;
        for (i = 0; i < 12; i++) {
            /* ABS(i - 6) would fold -(i - 6) into 6 - i first and lose the abs */
            data->unk8[i] = ABS(i + -6);
        }
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005E55C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B64);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B6C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B74);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B7C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B80);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B84);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B88);

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[6];
    s16 unk1C;
    u8 pad1E[0x12];
} Unk8005E91C_Anim;

typedef struct {
    SVECTOR pos[6];
    SVECTOR unk30[6];
    SVECTOR rot[6];
    SVECTOR out[6];
    Unk8005E91C_Anim anim[6];
    s16 unk1E0[6];
    s16 state[6];
    s16 unk1F8[6];
    s16 unk204;
    s16 unk206;
    u8 pad208[2];
    s16 unk20A;
    s16 unk20C[6];
} Unk8005E91C;

extern SVECTOR D_800A2B74;
extern void func_80043E14(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out);
extern int func_80024D64(int);

void func_8005E91C(Unk8005E91C *obj, s16 idx, s16 arg2) {
    SVECTOR v = D_800A2B74;

    obj->pos[idx].vx = idx * 600 - 2100;
    obj->pos[idx].vy = 0;
    obj->pos[idx].vz = obj->unk20A;
    obj->rot[idx].vx = 0;
    obj->rot[idx].vy = func_8001E9DC(0x1000);
    obj->rot[idx].vz = 0;
    obj->state[idx] = 0;
    obj->unk1E0[idx] = func_8001E9DC(0x800);
    obj->unk1F8[idx] = 0;
    func_80043E14(&obj->rot[idx], &v, &obj->pos[idx], &obj->out[idx]);
    func_80024D00((Obj80024D00 *)&obj->anim[idx]);
    func_80024B28((Obj80024D00 *)&obj->anim[idx], arg2);
    func_80024DA8(&obj->anim[idx], 7, func_80024D64(7), 0xF6, 8);
    obj->anim[idx].unk1C = 0;
    obj->anim[idx].unk14 = 0;
    obj->unk20C[idx] = arg2;
}

typedef struct {
    u8 pad0[0x204];
    s16 unk204;
    s16 unk206;
    u8 pad208[2];
    s16 unk20A;
} Unk8005EA78;

typedef struct {
    u8 pad[0x1C];
    Unk8005EA78 *data;
} Unk8005EA78_Task;

extern void func_8005E55C();
extern void func_8005E91C();

s32 func_8005EA78(s16 a, s16 b) {
    Unk8005EA78_Task *task;
    Unk8005EA78 *obj;
    s16 i;
    s16 n;

    task = (Unk8005EA78_Task *)func_80021264(func_8005E55C, 9, 0x218);
    i = 5;
    if (task != NULL) {
        obj = task->data;
        obj->unk20A = a;
        while (1) {
            func_8005E91C(obj, i, b);
            n = i--;
            if (n == 0) break;
        }
        obj->unk206 = 0;
        obj->unk204 = 0;
        return (s32)obj;
    }
    return 0;
}

typedef struct {
    u8 pad0[0xC0];
    u8 unkC0[6][0x30];
    s16 unk1E0[6];
    s16 state[6];
} Unk8005EB14_Item;

typedef struct {
    s32 pad0;
    Unk8005EB14_Item *items[3];
} Unk8005EB14;

extern int func_80024D64(int);

void func_8005EB14(void) {
    Unk8005EB14 *obj = (Unk8005EB14 *)D_800A317C->vals;
    Unk8005EB14_Item *item;
    s16 i;
    s16 j;

    i = 2;
    do {
        item = obj->items[i];
        j = 5;
        do {
            if (item->state[j] == 2) {
                item->state[j] = 4;
                func_80024DA8(item->unkC0[j], 7, func_80024D64(7), 0xF6, 8);
            }
        } while (j-- != 0);
    } while (i-- != 0);
}

void func_8005EBF4(s16 arg0) {
    s16 v = 600;
    s16 i = 2;
    Unk800A317CVals *vals = D_800A317C->vals;

    do {
        vals->vals[i] = func_8005EA78(v, arg0);
        v -= 600;
    } while (i--);
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk8005EC74;

extern void func_80062F8C(s16 a, s16 b);
extern void func_800627B8(void);
extern u8 D_800A2A48[];
extern s16 D_800A2F54;
extern s16 D_800A346C;
extern s16 D_800A3114;
extern void func_80063E0C(void);

void func_8005EC74(void) {
    Unk8005EC74 *d = (Unk8005EC74 *)D_800A317C->vals;

    d->unk2 = func_800437C8(d->unk2, 0xC00, 0x40);
    func_80062F8C(d->unk0, d->unk2);
    d->unk0 += 8;
    func_800627B8();
    func_8004983C();
    func_800544F8(160, 34, D_801D2068[0], 0x600, 1200, D_800A2A48, D_800A2A30, 8);
    if (D_800A2F54 == 6) {
        if (D_800A346C == 1 || D_800A346C == 5) {
            func_80021698(8);
            D_800A3114 = 2;
            D_800A317C->func = func_80063E0C;
        } else {
            D_800A3114 = 0;
            D_800A2F54 = 7;
            func_80052E18(3);
        }
    }
}

void func_8005ED94(void) {
}

typedef struct {
    u8 c[4];
} Color4;

extern Color4 D_800A2B7C;
extern Color4 D_800A2B80;
extern Color4 D_800A2B84;
extern Color4 D_800A2B88;
extern char D_8007B41C[];
extern char D_800A2B8C[];

typedef struct {
    u8 pad0[0x22];
    s16 unk22;
    u8 pad24[6];
    s16 unk2A;
    s16 unk2C;
    u8 pad2E[0x18];
    s16 unk46;
    s16 unk48;
} Unk8005ED9C;

void func_8005ED9C(Unk8005ED9C *p) {
    Color4 top = D_800A2B7C;
    Color4 bottom = D_800A2B80;
    Color4 top2 = D_800A2B84;
    Color4 bottom2 = D_800A2B88;
    s16 w;
    s16 h;
    s32 n;

    n = p->unk46 / 100;
    if (n < 10) {
        D_800A2B8C[1] = n + '0';
        D_800A2B8C[4] = '\0';
    } else {
        D_800A2B8C[1] = p->unk46 / 1000 + '0';
        D_800A2B8C[2] = p->unk46 / 100 % 10 + '0';
        D_800A2B8C[4] = '0';
        D_800A2B8C[5] = '\0';
    }
    if (p->unk48 < 0x100) {
        p->unk48 += 20;
        if (p->unk48 >= 0x100) {
            top.c[0] = 0xFF;
            top.c[1] = 0xFF;
            top.c[2] = 0xFF;
            bottom.c[0] = 0xFF;
            bottom.c[1] = 0xFF;
            bottom.c[2] = 0xFF;
            p->unk48 = 0x100;
            func_80053864(160, 96, D_800A2B8C, 0xEA6, 600, top.c, bottom.c);
        }
    } else {
        p->unk48 = 0x100;
        func_80053864(160, 96, D_800A2B8C, 0xEA6, 600, top2.c, bottom2.c);
    }
    w = 0x75300 / p->unk48;
    h = 0x38400 / p->unk48;
    if (p->unk2C == 1) {
        func_80053864(160, 72, D_8007B41C, w, h, top.c, bottom.c);
        p->unk2A = 100 - p->unk22;
    }
}

char D_800A2B8C[8] = "X100";

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B94);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B98);

typedef struct {
    u8 pad0[0x48];
    s16 unk48;
    s16 pad4A;
    s16 unk4C;
} Unk8005F098;


void func_8005F098(Unk8005F098 *p) {
    Color4 top = D_800A2B7C;
    Color4 bottom = D_800A2B80;
    Color4 unused0 = D_800A2B84;
    Color4 unused1 = D_800A2B88;
    s16 w;
    s16 h;

    if (p->unk48 <= 0x300) {
        p->unk48 += 0x20;
        w = 0x75300 / p->unk48;
        h = 0x38400 / p->unk48;
        if (p->unk4C == 1) {
            func_80053864(160, 72, D_8007B41C, w, h, top.c, bottom.c);
        }
    }
}

typedef struct {
    u8 pad0[4];
    Unk8005E91C *subs[6];
    s16 unk1C;
    s16 unk1E;
    u8 pad20[2];
    s16 unk22;
    u8 pad24[0x10];
    s16 unk34;
    u8 pad36[0xA];
    s16 unk40;
    u8 pad42[2];
    s16 unk44;
} Unk8005F1F0;

void func_8005F1F0(Unk8005F1F0 *obj) {
    Unk8005E91C *sub;
    s32 params[6];
    s16 n;
    s16 idx;

    if (obj->unk1E < 0 && obj->unk22 != obj->unk44) {
        obj->unk1E = 1;
        n = obj->unk22 * 18 / 100;
        obj->unk1C = n;
        sub = obj->subs[n / 6];
        obj->unk34 = idx = n % 6;
        if (sub->state[idx] != 3) {
            params[0] = (s16)func_8001E9DC(3) + 41;
            params[1] = 0x2000;
            params[2] = ((s16)func_8001E9DC(5) << 10) - 0x800;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            params[0] = 0x11;
            params[1] = 0x17D0;
            params[2] = ((s16)func_8001E9DC(5) << 10) - 0x800;
            params[3] = 0x400;
            params[4] = 0;
            params[5] = 0;
            func_8004FB78(params);
            sub->state[idx] = 3;
            sub->unk1F8[idx] = 0x800;
            sub->unk30[idx].vx = func_8001E9DC(0x40) - 0x20;
            sub->unk30[idx].vz = func_8001E9DC(0x40) - 0x20;
            sub->unk30[idx].vy = 0xC0;
            func_80024DA8(&sub->anim[idx], 0x1C, 0, 0xF6, 8);
            sub->anim[idx].unk14 = 1;
            func_80060A80((Unk8002A35C *)&sub->pos[idx], 0, 0);
        }
        obj->unk40 = 0;
        obj->unk22++;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005F438);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2B9C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BA0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BA4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BA8);

typedef struct {
    u8 pad0[0x2A];
    s16 unk2A;
    u8 pad2C[0x1E];
    s16 unk4A;
} Unk8005F688;

extern Color4 D_800A2B94;
extern Color4 D_800A2B98;
extern void func_800545BC(short x, short y, int value, int d, int a, u8 *b, u8 *c);

void func_8005F688(Unk8005F688 *p) {
    Color4 top = D_800A2B94;
    Color4 bottom = D_800A2B98;

    if (p->unk4A >= 0x30) {
        p->unk4A -= 0x10;
        if (p->unk4A >= 0x30) {
            func_800545BC(160, 140, p->unk2A, 0x271000 / p->unk4A, 0xAF000 / p->unk4A, top.c, bottom.c);
        }
    }
}

typedef struct {
    u8 pad0[0x38];
    s32 value;
} Unk8005F790;

extern Color4 D_800A2B84;
extern Color4 D_800A2B88;
extern Color4 D_800A2BA0;
extern Color4 D_800A2BA4;
extern char D_800A2BA8[];

void func_8005F790(Unk8005F790 *p) {
    Color4 top1 = D_800A2BA0;
    Color4 bottom1 = D_800A2BA4;
    Color4 top2 = D_800A2B84;
    Color4 bottom2 = D_800A2B88;

    func_80053864(83, 198, D_800A2BA8, 0xC00, 1200, top1.c, bottom1.c);
    func_800545BC(237, 198, p->value, 0xC00, 1200, top2.c, bottom2.c);
}

typedef struct {
    u8 pad0[0x38];
    u32 unk38;
    u32 unk3C;
} Unk8005F880;

extern void func_80049820(u32);

void func_8005F880(Unk8005F880 *arg0) {
    if (arg0->unk38 != 0) {
        if (arg0->unk38 < arg0->unk3C) {
            func_80049820(arg0->unk38);
            arg0->unk38 = 0;
        } else {
            func_80049820(arg0->unk3C);
            arg0->unk38 -= arg0->unk3C;
        }
    }
}

typedef struct {
    u8 pad0[0x2A];
    s16 unk2A;
    u8 pad2C[0xC];
    u32 unk38;
    u32 unk3C;
    u8 pad40[6];
    s16 unk46;
} Unk8005F8F0;

void func_8005F8F0(Unk8005F8F0 *obj) {
    obj->unk38 = obj->unk2A * obj->unk46;
    obj->unk3C = obj->unk38 >> 6;
    if (obj->unk3C == 0) {
        obj->unk3C = 1;
    }
}

extern char D_8007B42C[];

void func_8005F92C(void) {
    if (D_800A30DC & 8) {
        func_80053864(160, 226, D_8007B42C, 0x320, 0x12C, D_800A2A3C, D_800A2A30);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8005F98C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B474);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B48C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B49C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B4AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B4C0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BB0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BB4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BB8);

extern void SetTile(TILE *p);
extern void SetSemiTrans(void *p, s32 abe);
extern u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
extern void SetDrawMode(DR_MODE *p, s32 dfe, s32 dtd, s32 tpage, RECT *tw);

void func_80060064(u8 shade) {
    TILE *tile = D_800A3374;
    DR_MODE *mode;
    u32 *ot;

    tile->x0 = 0;
    tile->y0 = 0;
    tile->w = 0x1FF;
    tile->h = 0xFF;
    SetTile(tile);
    tile->r0 = shade;
    tile->g0 = shade;
    tile->b0 = shade;
    SetSemiTrans(tile, 1);
    ot = D_800A32E4 + 1;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, tile++);
    }
    mode = (DR_MODE *)tile;
    SetDrawMode(mode, 1, 1, GetTPage(0, 2, 0, 0), NULL);
    ot = D_800A32E4 + 1;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, mode++);
    }
    D_800A3374 = mode;
}

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80060168;

void func_80060168(void) {
    Unk80060168 *obj = (Unk80060168 *)D_800A317C->vals;

    func_80060064(obj->unk32);
    obj->unk32 -= 0x20;
    if (obj->unk32 < 0) {
        func_80021554();
    }
}

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80060200;

void func_80060168(void);

void func_800601C4(void) {
    ((Unk80060200 *)D_800A317C->vals)->unk32 = 0xFF;
    D_800A317C->func = func_80060168;
    func_80060168();
}

extern s16 D_800A3334;

void func_80060200(void) {
    Unk80060200 *data = (Unk80060200 *)D_800A317C->vals;
    TILE *tile = D_800A3374;
    s16 w, h;
    u32 *ot;

    data->unk32 += 0x100;
    w = func_800296F8(0, D_800A3334 / 2, data->unk32);
    h = func_800296F8(0, D_800A33C4 / 2, data->unk32);
    tile->w = w * 2;
    tile->h = h * 2;
    tile->x0 = D_800A3334 / 2 - w;
    tile->y0 = D_800A33C4 / 2 - h;
    SetTile(tile);
    tile->r0 = 0;
    tile->g0 = 0;
    tile->b0 = 0;
    ot = D_800A32E4 + 1;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, tile++);
    }
    D_800A3374 = tile;
    if (data->unk32 > 0x1068) {
        D_800A3114 = 2;
    }
}

void func_80060348(void) {
    ((Unk80060200 *)D_800A317C->vals)->unk32 = 0;
    D_800A317C->func = func_80060200;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x18];
    s16 unk1C;
    u8 pad1E[4];
    s16 unk22;
    u8 pad24[2];
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 pad32[2];
    s16 unk34;
    u8 pad36[2];
    s32 unk38;
    u8 pad3C[4];
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u8 pad48[8];
    s32 unk50;
} Unk80060370;

extern void func_80063DEC(void);
extern void func_8005F98C(void);

void func_80060370(void) {
    Unk80060370 *obj = (Unk80060370 *)D_800A317C->vals;

    D_800A2FEC = 0;
    func_80021264(func_8003E85C, 1, 0x2C);
    D_800A30EC = -1;
    D_800A305C[0] = 0;
    D_800A305C[1] = 0;
    func_80063DEC();
    obj->unk2 = 8000;
    obj->unk0 = 0;
    if (D_800A346C == 2) {
        func_80021264(func_80063D8C, 3, 0xE);
        D_800A3114 = 2;
        D_800A317C->func = func_800619C8;
        return;
    }
    obj->unk1C = 0;
    obj->unk30 = 50;
    if (D_800A34AC != 0) {
        obj->unk26 = 100 - (D_800A2EE8 * 100) / D_800A34AC;
    } else {
        obj->unk26 = 100;
    }
    obj->unk28 = 0;
    obj->unk40 = -1;
    obj->unk38 = 0;
    obj->unk46 = ((s16)D_8007C268[D_800A307C].unk0 + 1) * 100;
    obj->unk50 = D_801D2068[0] + D_801D2068[1];
    obj->unk50 += (100 - obj->unk26) * obj->unk46;
    obj->unk22 = 0;
    obj->unk2C = 1;
    obj->unk2E = 1;
    obj->unk2A = -1;
    obj->unk34 = -1;
    obj->unk44 = obj->unk26;
    obj->unk42 = 4;
    func_8005EBF4(2);
    D_800A317C->func = func_8005F98C;
    func_8005F98C();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8006057C);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 size[16];
    s16 rotA[16];
    s16 life[16];
    s16 velX[16];
    s16 velY[16];
    s16 velZ[16];
    s16 rotB[16];
    s16 spin[16];
    s16 unk108;
    s16 pad10A;
    s16 unk10C;
    s16 pad10E[5];
    s16 dx;
    s16 pad11A;
    s16 dz;
    s16 pad11E;
} Unk80060A80_Data;

extern void func_8006057C();

void func_80060A80(Unk8002A35C *pos, s16 angle, s16 speed) {
    struct Task *t;
    Unk80060A80_Data *d;
    s16 i;

    if (D_800A2F0C == 11) {
        t = func_80021358(func_8006057C, 3, 0x120);
    } else {
        t = func_80021454(D_800A317C, func_8006057C, 3, 0x120);
    }
    if (t != NULL) {
        d = (Unk80060A80_Data *)t->vals;
        d->unk108 = 0;
        d->unk10C = 0x140;
        d->dx = (D_800854C0[angle & 0xFFF] * speed) >> 12;
        d->dz = (D_800854C0[(u16)(angle + 0x400) & 0xFFF] * speed) >> 12;
        d->x = pos->x;
        d->y = pos->y;
        d->z = pos->z;
        i = 15;
        do {
            d->size[i] = func_8001E9DC(0x10) + 0x10;
            d->rotA[i] = func_8001E9DC(0x1000);
            d->rotB[i] = func_8001E9DC(0x1000);
            d->spin[i] = func_8001E9DC(0x40) - 0x20;
            d->life[i] = func_8001E9DC(4) + 6;
            d->velX[i] = func_8001E9DC(0x40) - 0x20;
            d->velY[i] = func_8001E9DC(0x30) + 0x20;
            d->velZ[i] = func_8001E9DC(2) + 1;
        } while (i--);
    }
}

typedef struct {
    s16 next;
    u32 score;
    char name[12];
} Unk80060C3C_Entry;

typedef struct {
    Unk80060C3C_Entry e[10];
    s16 free;
    s16 head;
    s16 last;
} Unk80060C3C_Table;

s16 func_80060C3C(Unk80060C3C_Table *t, u32 score, char *name) {
    Unk80060C3C_Entry *e;
    s16 ret = 0;
    s16 prev = -1;
    s16 n = 9;
    s16 cur = t->head;
    s16 i;

    do {
        e = &t->e[cur];
        if (e->score < score) {
            if (name == NULL) {
                return -1;
            }
            strcpy(t->e[t->free].name, name);
            t->e[t->free].score = score;
            t->last = t->free;
            if (prev == -1) {
                t->head = t->free;
                t->e[t->free].next = cur;
            } else {
                t->e[prev].next = t->free;
                t->e[t->free].next = cur;
            }
            ret = -1;
            break;
        }
        prev = cur;
        cur = e->next;
    } while (n--);
    cur = t->head;
    for (i = 0; i < 9; i++) {
        cur = t->e[cur].next;
    }
    t->free = cur;
    return ret;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80060DCC);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80061174);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BBC);

typedef struct {
    SVECTOR rot;
    u8 pad8[0x16C];
} Unk80061844_Model;

typedef struct {
    Unk8002A35C pos;
    u8 pad6[0x26];
    Unk80061844_Model model;
    Anim anim;
    u8 pad1C0[0x10];
    SVECTOR vel;
    SVECTOR unk1D8;
    SVECTOR v1E0;
    SVECTOR v1E8;
    u8 pad1F0[0xC];
    struct Task *unk1FC;
    s32 unk200;
} Unk80061844;

void func_80061524(Unk80061844 *obj, s32 unused) {
    obj->v1E8.vx = 0;
    obj->v1E8.vy = 0;
    obj->v1E8.vz = 0x20;
    obj->vel.vx = 0;
    obj->vel.vy = 0;
    obj->vel.vz = 0;
}

void func_80061544(Unk80061844 *obj) {
    s16 id = func_8001E9DC(0x2E);

    func_80024EA0(&obj->anim, id, 0, 0xF6, 0x10);
    func_80061524(obj, 0);
    obj->vel.vx = 0;
    obj->vel.vz = 0;
}

extern SVECTOR D_800A2F04;
extern SVECTOR D_800A34B4;
extern SVECTOR D_800A3544;
extern s16 D_800A324C;

void func_800615A0(Unk80061844 *obj) {
    D_800A34B4.vx = 0;
    D_800A34B4.vz = 0;
    D_800A34B4.vy = func_8001E9DC(0x1000);
    D_800A3544.vx = 0;
    D_800A3544.vz = 0xAF0;
    D_800A3544.vy = 0;
    func_80043E14(&D_800A34B4, &D_800A3544, &D_800A2F04, (SVECTOR *)obj);
    obj->model.rot.vx = 0;
    obj->model.rot.vz = 0;
    obj->model.rot.vy = D_800A34B4.vy + 0x800;
    obj->unk1FC = 0;
    func_80024D00((Obj80024D00 *)&obj->anim);
    func_80024DA8(&obj->anim, 0, 0, 0xF6, 0x10);
    func_80024DA8(&obj->anim, 0, 0, 0xF6, 0x10);
    func_80024B28((Obj80024D00 *)&obj->anim, (s16)func_8001E9DC(D_800A324C));
    func_80061544(obj);
}

void func_800616AC(Unk80061844 *obj) {
    VECTOR tmp;
    s16 saved;
    Unk80061844 *src;

    obj->model.rot.vx += obj->vel.vx;
    obj->model.rot.vy += obj->vel.vy;
    obj->model.rot.vz += obj->vel.vz;
    saved = obj->v1E8.vz;
    if (saved > 0) {
        if (obj->anim.unk16 == 0) {
            obj->v1E8.vz = func_80031C58(&obj->anim);
        }
        func_80043E14(&obj->model.rot, &obj->v1E8, (SVECTOR *)obj, (SVECTOR *)obj);
    } else {
        func_80023C7C(&obj->model.rot, &D_801FB868);
        ApplyMatrix(&D_801FB868, &obj->v1E8, &tmp);
        obj->pos.x += tmp.vx * 3;
        obj->pos.y += tmp.vy * 3;
        obj->pos.z += tmp.vz * 3;
    }
    obj->v1E8.vz = saved;
    if (obj->unk1FC != NULL) {
        if (obj->unk200 == obj->unk1FC->id) {
            src = (Unk80061844 *)obj->unk1FC->vals;
            obj->pos.x = src->pos.x;
            obj->pos.y = src->pos.y;
            obj->pos.z = src->pos.z;
            obj->model.rot.vx = src->model.rot.vx;
            obj->model.rot.vy = src->model.rot.vy;
            obj->model.rot.vz = src->model.rot.vz;
            func_80043E14(&obj->model.rot, &obj->v1E0, (SVECTOR *)obj, (SVECTOR *)obj);
        } else {
            obj->unk1FC = NULL;
            obj->unk200 = -1;
        }
    }
}

extern SVECTOR D_800A2F04;
extern u8 *D_800A2FAC;
extern s16 func_8002501C(void *obj, void *model, s16 fade, s32 arg3, Anim *anim);
extern void AddPrims(void *ot, void *p0, void *p1);
extern void func_80061544(Unk80061844 *obj);
extern void func_800615A0(Unk80061844 *obj);
extern void func_800616AC(Unk80061844 *obj);

void func_80061844(void) {
    Unk80061844 *obj = (Unk80061844 *)D_800A317C->vals;
    s16 fade = 0xFFF;
    s16 dist = func_8002A35C(&obj->pos, (Unk8002A35C *)&D_800A2F04);
    s16 n;
    u32 *ot;

    if (dist > 0x9F0) {
        fade = 0x1000 - (dist - 0x9F0) * 16;
        if (fade < 0) {
            fade = 0;
        }
    }
    n = func_8002501C(obj, &obj->model, fade, 0, &obj->anim);
    if (D_800A326C > 8 && n >= 8) {
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrims(ot, D_800A2FAC + 0x14, D_800A2FAC);
        }
    }
    func_800616AC(obj);
    if (func_80024EF0(&obj->anim) != 0) {
        func_80061544(obj);
    }
    if (dist > 0xAF1) {
        func_800615A0(obj);
    }
}

void func_80061988(void) {
    Unk8003BA6C_Task *task;

    task = func_80021264(func_80061844, 3, 0x298);
    if (task != NULL) {
        func_800615A0((Unk80061844 *)task->data);
    }
}

typedef struct {
    s16 pad0[2];
    s16 unk4;
    s16 unk6;
    s16 pad8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
} Unk800619C8;

void func_80061174(void);

void func_800619C8(void) {
    Unk800619C8 *d = (Unk800619C8 *)D_800A317C->vals;

    d->unk4 = 0x1000;
    d->unkA = 30;
    d->unk6 = 1488;
    d->unkC = 0;
    d->unk14 = 300;
    d->unk10 = 20;
    d->unk12 = 30;
    func_80061174();
    D_800A317C->func = func_80061174;
}

int func_80061A30(short i) {
    return *D_800A353C[i].p - 1;
}

extern s16 D_800A3554;
extern s16 D_800A3558;

s16 func_80061A58(SVECTOR *pos) {
    s16 dx = pos->vx - D_800A3554;
    s16 dz = pos->vz - D_800A3558;
    s16 dist = SquareRoot0(dx * dx + dz * dz);

    if (dist > 3000) {
        dist = 3000;
    }
    return 0x1000 - dist;
}

typedef struct {
    u8 pad0[0x292];
    u8 unk292[1];
} Unk80061AF0_Owner;

typedef struct {
    Anim anim;
    u8 pad20[0x10];
    SVECTOR pos;
    SVECTOR rot;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 pad46[2];
    s16 unk4A;
} Unk80061AF0;

extern struct Task *volatile D_801F7D74;
extern s16 D_800A3344;
extern void func_800620A8(SVECTOR *pos, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_80061AF0(void) {
    Unk80061AF0 *p = (Unk80061AF0 *)D_800A317C->vals;
    s16 fade = func_80061A58(&p->pos);
    Unk80061AF0_Owner *owner;
    SVECTOR pos;
    s16 n;
    u32 *ot;

    if (D_801F7D74 != NULL) {
        owner = (Unk80061AF0_Owner *)D_801F7D74->vals;
        if (p->unk4A != 0) {
            p->unk4A--;
            return;
        }
        pos.vx = p->pos.vx;
        pos.vy = p->pos.vy;
        pos.vz = p->pos.vz;
        pos.vy += p->unk44;
        SetRotMatrix(&D_801C0B64);
        SetTransMatrix(&D_801C0B64);
        n = func_8002501C(&pos, &p->rot, fade, 0, &p->anim);
        if (D_800A326C > 8 && n >= 8) {
            ot = D_800A32E4 + D_800A326C;
            if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
                AddPrims(ot, D_800A2FAC + 0x14, D_800A2FAC);
            }
        }
        func_800620A8(&pos, p->unk42 + 0x41, -0x200, D_800A3344, 0);
        p->unk44 += p->unk40;
        p->unk40 -= 8;
        if (p->unk44 >= 0) {
            return;
        }
        owner->unk292[p->unk42] = 0;
    }
    func_80021554();
}

void func_80061C90(s16 arg0, s16 arg1) {
    Unk80061AF0 *p;
    s16 n;
    struct Task *task = (struct Task *)func_80021264(func_80061AF0, 1, 0x4C);

    if (task != NULL) {
        p = (Unk80061AF0 *)task->vals;
        n = arg0;
        if (arg0 <= 0 || arg0 >= D_800A324C) {
            n = func_8001E9DC(D_800A324C - 1) + 1;
        }
        func_80024D00((Obj80024D00 *)&p->anim);
        func_80024DA8(&p->anim, 0x16, 0, 0xF6, 8);
        func_80024DA8(&p->anim, 0x16, 0, 0xF6, 8);
        func_80024B28((Obj80024D00 *)&p->anim, n);
        p->unk4A = arg1;
        p->unk40 = -0x30;
        p->unk42 = arg0;
        p->unk44 = D_800A3194.vy + 0x80;
        D_800A34B4.vz = 0x780;
        D_800A34B4.vy = 0;
        D_800A34B4.vx = 0;
        p->rot.vx = 0;
        p->rot.vz = 0;
        p->rot.vy = -arg0 * 0x9D;
        func_80043E14(&p->rot, &D_800A34B4, &D_800A2F04, &p->pos);
        SetRotMatrix(&D_801C0B64);
        SetTransMatrix(&D_801C0B64);
    }
}

typedef struct {
    Anim anim;
    u8 pad20[0x22];
    s16 unk42;
    u8 pad44[2];
    s16 unk46;
    s16 unk48;
} Unk80061E20;

extern s16 D_800A3344;
extern void func_800620A8(SVECTOR *pos, s32 size, s32 scale, s32 arg3, s32 arg4);

void func_80061E20(void) {
    Unk80061E20 *obj = (Unk80061E20 *)D_800A317C->vals;
    SVECTOR pos;
    u32 *ot;
    s16 vis;

    obj->unk46 -= 0x20;
    if (obj->unk46 < -0x1068) {
        func_80021554();
        return;
    }
    D_800A34B4.vz = obj->unk46;
    D_800A34B4.vy = 0;
    D_800A34B4.vx = 0;
    D_800A3544.vx = 0;
    D_800A3544.vz = 0;
    D_800A3544.vy = obj->unk48;
    func_80043E14(&D_800A3544, &D_800A34B4, &D_800A2F04, &pos);
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
    D_800A3544.vy += 0x800;
    func_80024B28((Obj80024D00 *)obj, obj->unk42 % D_800A324C);
    vis = func_8002501C(&pos, &D_800A3544, 0xFFF, 0, &obj->anim);
    if (D_800A326C > 8 && vis >= 8) {
        ot = D_800A32E4 + D_800A326C;
        if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
            AddPrims(ot, D_800A2FAC + 0x14, D_800A2FAC);
        }
    }
    func_800620A8(&pos, obj->unk42 + 0x41, 0x400, D_800A3344, 0);
    func_80024EF0(&obj->anim);
}

void func_80061E20();

void func_80061FF4(s32 arg0, s16 arg1, s16 arg2) {
    Unk8003BA6C_Task *task;
    Obj80024D00 *obj;

    task = func_80021264(func_80061E20, 1, 0x4C);
    if (task != NULL) {
        obj = (Obj80024D00 *)task->data;
        func_80024D00(obj);
        func_80024DA8(obj, 4, 0, 0xF6, 8);
        func_80024DA8(obj, 4, 0, 0xF6, 8);
        obj->unk46 = arg1;
        obj->unk48 = arg2;
        obj->unk42 = arg0 - 0x41;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800620A8);

void func_80062700(u8 *rgb, s16 x, s16 z) {
    s32 dx = (x - D_800A3554) >> 3;
    s32 dz = (z - D_800A3558) >> 3;
    s32 dist = SquareRoot0(dx * dx + dz * dz);
    s32 c;

    if (dist > 250) {
        dist = 250;
    }
    c = ((255 - dist) * 3800) >> 12;
    rgb[0] = c;
    rgb[1] = c;
    rgb[2] = 255 - dist;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800627B8);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80062A78);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BC4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BCC);

extern SVECTOR D_800A34B4;
extern SVECTOR D_800A3544;
extern SVECTOR D_800A2FC4;
extern SVECTOR D_800A3194;
extern s16 D_800A3334;
extern s16 D_800A33C4;
extern s16 D_800A33B4;
extern void func_80070FBC(s32 a, s32 b);
extern void SetFogNear(s32 a, s32 h);
extern void func_80021BE4(void);

void func_80062F8C(s16 angle, s16 height) {
    D_800A34B4.vx = 0;
    D_800A34B4.vz = 0;
    D_800A34B4.vy = angle;
    D_800A3544.vx = 0;
    D_800A3544.vz = -0x1130;
    D_800A3544.vy = height;
    func_80043E14(&D_800A34B4, &D_800A3544, &D_800A2F04, &D_800A3194);
    func_80028E14((Unk8002A35C *)&D_800A2F04, (Unk8002A35C *)&D_800A3194, (Unk8002A35C *)&D_800A2FC4);
    if (height > 1500) {
        height = 1500;
    }
    D_800A2FC4.vx -= func_800296F8(-0x80, 0x1B8, height);
    func_80070FBC(D_800A3334 / 2, D_800A33C4 / 2);
    SetFogNear(0x7D00, 0x100);
    func_80070FDC(0x100);
    D_800A33B4 = 0x100;
    func_80021BE4();
    D_800A2FC4.vy = -D_800A2FC4.vy;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800630D0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BD4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BDC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BE0);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Unk80063C60;

extern SVECTOR D_800A2F04;

void func_80063C60(void) {
    Unk80063C60 *p = (Unk80063C60 *)D_800A317C->vals;
    SVECTOR v;
    SVECTOR rot;

    v.vz = p->unk0;
    v.vy = 0;
    v.vx = 0;
    rot.vy = p->unk2;
    rot.vx = 0;
    rot.vz = 0;
    func_80043E14(&rot, &v, &D_800A2F04, (SVECTOR *)&D_800A3554);
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
    p->unk0 += p->unk4;
    p->unk2 += p->unk6;
    if (p->unkC-- < 0) {
        p->unkC = func_8001E9DC(0x20);
        p->unkA = func_8001E9DC(0x80) - 0x40;
        p->unk8 = func_8001E9DC(0xC4E);
    }
    p->unk6 = func_800437C8(p->unk6, p->unkA, 1);
    if (p->unk0 < p->unk8) {
        p->unk4 = func_800437C8(p->unk4, 0x40, 2);
    } else {
        p->unk4 = func_800437C8(p->unk4, -0x40, 2);
    }
}

void func_80063D8C(void) {
    Unk80063C60 *p = (Unk80063C60 *)D_800A317C->vals;

    p->unk0 = 0;
    p->unk8 = 0x500;
    p->unk4 = 0;
    p->unk6 = 0x20;
    p->unkC = func_8001E9DC(0x20);
    D_800A317C->func = func_80063C60;
}

extern s16 D_800A3556;

void func_80063DEC(void) {
    D_800A3554 = 0;
    D_800A3556 = 0;
    D_800A3558 = 0;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80063E0C);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80064088);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B4D0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BE8);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80064D80);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B4F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B520);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B52C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B538);

typedef struct {
    u8 pad0[0x16];
    s16 unk16;
    u8 pad18[6];
    s16 unk1E;
} Unk80065094_Sub;

typedef struct {
    u8 pad0[0x114];
    Unk80065094_Sub sub;
} Unk80065094_Obj;

typedef struct {
    u8 pad0[0x16];
    s16 count;
} Unk80065094_Owner;

extern Unk80065094_Obj *D_801D20CC[];

void func_80065094(Unk80065094_Owner *owner, Unk80065094_Obj *obj) {
    Unk80065094_Sub *sub = &obj->sub;
    s16 i = 4;
    s16 n;

    while (1) {
        if (D_801D20CC[i] == NULL) {
            sub->unk1E = 0;
            sub->unk16 = i * 0x333;
            D_801D20CC[i] = obj;
            owner->count++;
            return;
        }
        n = i--;
        if (n == 0) break;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80065110);

typedef struct {
    s16 x, y, z;
    u8 pad6[2];
    s16 unk8, unkA, unkC;
    u8 padE[2];
    s16 unk10, unk12, unk14;
    u8 pad16[2];
    s16 unk18, unk1A, unk1C;
    u8 pad1E[0xA];
    s16 unk28;
    u8 pad2A[2];
    s16 unk2C;
    u8 pad2E[2];
    s16 unk30;
    u8 pad32[0x1A];
    s16 unk4C, unk4E, unk50;
    u8 pad52[0x10];
    s16 unk62;
    Anim anim;
    u8 pad84[0x10];
    s16 unk94, unk96, unk98;
    u8 pad9A[2];
    s16 unk9C, unk9E, unkA0;
    u8 padA2[2];
    s16 unkA4, unkA6, unkA8;
    u8 padAA[2];
    s32 unkAC, unkB0, unkB4;
    u8 padB8[6];
    s16 unkBE, unkC0;
    u8 padC2[6];
    s16 unkC8;
    u8 padCA;
    u8 unkCB;
    u8 padCC[6];
    s16 unkD2;
    u8 padD4[2];
    s16 unkD6;
    u8 padD8[6];
    s16 unkDE, unkE0;
    u8 padE2[6];
    s16 unkE8, unkEA, unkEC;
    u8 padEE[2];
    s16 unkF0, unkF2, unkF4;
    u8 padF6[2];
    s16 unkF8[3];
    s16 unkFE;
    s16 unk100;
    s16 unk102;
    s16 unk104, unk106, unk108, unk10A, unk10C;
    u8 pad10E[2];
    s16 unk110, unk112;
    u8 pad114[2];
    s16 unk116, unk118, unk11A;
    u8 pad11C[8];
    void *parent;
    s16 radius, angle, unk12C;
    u8 pad12E[2];
    s16 unk130, unk132;
    u8 pad134[0x24];
    s16 unk158, unk15A, unk15C, unk15E;
    u8 pad160[4];
} Unk80065B74;

extern void func_80065110(void);

void func_80065B74(Unk80065B74 *parent, s16 anim, s16 f2, s16 f4, s16 f102) {
    Unk80065B74 *obj;
    Unk8003BA6C_Task *t;
    s16 i = 4;
    s16 j;

    do {
        t = func_80021264(func_80065110, 1, 0x164);
        if (t == NULL) {
            return;
        }
        obj = (Unk80065B74 *)t->data;
        obj->unk28 = 10;
        obj->unk62 = func_8003D890((Unk80045164 *)obj);
        D_801D20CC[i] = (Unk80065094_Obj *)obj;
        obj->parent = parent;
        obj->radius = 0x180;
        obj->angle = i * 0x333;
        obj->unk12C = 0;
        obj->unk130 = 0;
        obj->unk132 = 0;
        obj->unk116 = 1;
        obj->unk118 = func_8001E9DC(20) + 90;
        obj->unk11A = func_8001E9DC(40) + 280;
        obj->x = parent->x + ((D_800854C0[obj->angle & 0xFFF] * obj->radius) >> 12);
        obj->y = parent->y;
        obj->z = parent->z + ((D_800854C0[(obj->angle + 0x400) & 0xFFF] * obj->radius) >> 12);
        obj->unk10 = 0;
        obj->unk12 = parent->unk12;
        obj->unk14 = 0;
        obj->unk18 = 0;
        obj->unk1A = 0;
        obj->unk1C = 0;
        obj->unk4C = 0;
        obj->unk4E = 0;
        obj->unk50 = 0;
        obj->unk30 = 0;
        obj->unk2C = 0;
        obj->unkA = obj->y;
        obj->unkC = obj->z;
        obj->unk112 = obj->unk12;
        obj->unk8 = obj->x;
        obj->anim.time = (s16)func_8001E9DC(0x1000);
        obj->anim.unk6 = 0xA4;
        obj->anim.id = 0;
        obj->anim.unk16 = 0;
        obj->unk9C = 0;
        obj->unk9E = 0;
        obj->unkA0 = 0;
        obj->unkA4 = 0;
        obj->unkA6 = 0;
        obj->unkA8 = 0;
        obj->unkAC = 200;
        obj->unkB0 = 0x340;
        obj->unkB4 = 200;
        obj->unkC0 = 0;
        obj->unkBE = 0;
        obj->unkC8 = 0;
        obj->unk104 = 0;
        obj->unk106 = 0;
        obj->unk108 = 1;
        obj->unkFE = 0;
        obj->unk94 = obj->x;
        obj->unk96 = obj->y;
        obj->unk98 = obj->z;
        obj->unkCB = obj->unk62;
        for (j = 0; j < 3; j++) {
            obj->unkF8[i] = 0;
        }
        obj->unkF4 = f4;
        obj->unkD2 = 0x40;
        obj->unkF2 = f2;
        obj->unk102 = f102;
        obj->unk10A = 0x2A8;
        obj->unk10C = 0x1000;
        obj->unk110 = 8;
        obj->unkD6 = parent->unkD6;
        obj->unkF0 = 0;
        obj->unkEC = 3;
        obj->unk158 = 0;
        obj->unkF8[0] = 100;
        obj->unkF8[1] = 100;
        obj->unkF8[2] = 100;
        func_80024D00((Obj80024D00 *)&obj->anim);
        func_80024DA8(&obj->anim, 8, 0, 0xA4, 4);
        func_80024DA8(&obj->anim, D_8007C560[obj->unkF4], 0, 0xA4, 4);
        func_80024B28((Obj80024D00 *)&obj->anim, anim);
        obj->unkDE = 0;
        obj->unkE0 = 0;
        obj->unkE8 = -1;
        obj->unk15C = 0;
        obj->unk15E = 0;
        obj->unk15A = 0;
        obj->unkEA = func_8001E9DC(20) + 50;
    } while (i--);
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80065F10);

typedef struct Unk80066474 {
    u8 pad0[0x28];
    s16 unk28;
    u8 pad2A[0xAA];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
    s16 unkDC;
    u8 padDE[4];
    s16 unkE2;
    s16 unkE4;
    u8 padE6[4];
    s16 unkEA;
    u8 padEC[0x28];
    s16 unk114;
    s16 unk116;
    s16 unk118;
    s16 unk11A;
    u8 pad11C[8];
    struct Unk80066474 *unk124;
    s16 unk128;
    s16 unk12A;
    s16 unk12C;
    u8 pad12E[2];
    s16 unk130;
    s16 unk132;
} Unk80066474;

extern struct Task *volatile D_801F7D58;
void func_80065110(void);

void func_80066474(void) {
    Unk80066474 *obj = (Unk80066474 *)D_800A317C->vals;
    Unk80066474 *other;
    SVECTOR unused[2];

    if (D_801F7D58 == NULL) {
        obj->unkDC = func_80043C60(-1);
        obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
        obj->unkE2 = func_8001E9DC(20) + 20;
        obj->unkE4 = 0;
        obj->unk28 = 7;
        obj->unk114 = 0;
        obj->unk116 = 0;
        obj->unk118 = 0;
        D_800A317C->func = func_80046030;
    } else {
        other = (Unk80066474 *)D_801F7D58->vals;
        obj->unk128 = 0x180;
        obj->unk124 = other;
        obj->unk12A = (s16)func_8001E9DC(5) * 819;
        obj->unk12C = 0;
        obj->unkDC = other->unkD8;
        obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
        obj->unkD4 = 0;
        obj->unkEA = func_8001E9DC(20) + 50;
        obj->unkDA = 0;
        obj->unk118 = func_8001E9DC(20) + 90;
        obj->unk130 = -1;
        obj->unk132 = -1;
        obj->unk116 = 1;
        obj->unk11A = func_8001E9DC(40) + 280;
        obj->unkE2 = func_8001E9DC(10) + 10;
        D_800A317C->func = func_80065110;
    }
}

void func_800666C4(void);

void func_800665E8(void) {
    Obj80047314 *obj = (Obj80047314 *)D_800A317C->vals;
    s16 *speed = &obj->unk114;
    SVECTOR unused[2];

    if (obj->unk116 >= 0) {
        obj->unk116 += 0x10;
    } else {
        obj->unk116 = 0;
    }
    speed[0] <<= 9;
    speed[9] = 0;
    obj->unk12 = speed[0];
    obj->unkD8 = func_80043770(obj->unkD6, obj->unkDC);
    obj->unkDA = func_80043D68(obj->unkD6, obj->unkD8, obj->unkD2);
    obj->unkE2 = func_8001E9DC(0x14) + 0x14;
    obj->unkE4 = 0;
    func_80024DA8(obj->unk64, D_8007C550[obj->unkF4], 0, 0x52, 0);
    D_800A317C->func = func_800666C4;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800666C4);

extern MATRIX *func_80023450(SVECTOR *r, MATRIX *m);

void func_80066AB0(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80023450(rot, &D_801FB868);
    ApplyMatrix(&D_801FB868, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern MATRIX *func_80023660(SVECTOR *r, MATRIX *m);

void func_80066B44(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80023660(rot, &D_801FB868);
    ApplyMatrix(&D_801FB868, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

void func_80066BD8(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    RotMatrix(rot, &D_801FB868);
    ApplyMatrix(&D_801FB868, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0xAC];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    u8 padC0[0x5A];
    s16 unk11A;
} Unk80066C6C;

void func_80066C6C(Unk80066C6C *obj) {
    s32 step;
    s32 limit;

    switch (obj->unk11A) {
    case 2:
    case 3:
        step = 0x300;
        limit = 30;
        obj->unkB8 = obj->unkB4 + 0x10000;
        break;
    case 1:
    case 4:
        step = 0xC00;
        limit = 120;
        obj->unkB8 = obj->unkB4 + 0x30000;
        break;
    default:
        step = 0;
        limit = 0;
        break;
    }
    obj->unk4 += obj->unkBC;
    if (obj->unk4 < obj->unkB8) {
        obj->unkBC = func_800437C8(obj->unkBC, step, limit);
    } else {
        obj->unkBC = func_800437C8(obj->unkBC, -step, limit);
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80066D40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B550);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B564);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B574);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BF0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2BF8);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C00);

u8 D_800A2C08 = 0;

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C0C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C10);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C18);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C20);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C28);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C30);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C38);

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80067670);

void func_80067A28(void) {
}

typedef struct {
    u8 pad0[0x12];
    u16 type;
} Unk80067A30_Prim;

typedef struct {
    s16 x, y, z;
    char pad6[2];
    s16 rx, ry, rz;
    char padE[0xA];
    s32 sx, sy, sz;
} Unk80067A30_Obj;

extern VECTOR D_8007B564;
extern SVECTOR D_800A3194;
extern Unk80067A30_Obj D_800A8000;
extern s32 D_800A30DC;
extern void (*D_8008009C[])(Unk80067A30_Prim *);

s32 func_80067A30(Unk80067A30_Prim *p, SVECTOR *pos, SVECTOR *ang) {
    s16 sxy[2];
    VECTOR scale = D_8007B564;
    MATRIX m;
    SVECTOR rot;
    s16 z;

    PushMatrix();
    D_800A349C.vx = pos->vx - D_800A3194.vx;
    D_800A349C.vy = pos->vy - D_800A3194.vy;
    D_800A349C.vz = pos->vz - D_800A3194.vz;
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    rot.vx = 0;
    rot.vz = 0;
    rot.vy = D_800A30DC * 500;
    D_800A8000.x = pos->vx;
    D_800A8000.y = pos->vy - 0x40;
    D_800A8000.z = pos->vz;
    D_800A8000.rx = 0;
    D_800A8000.ry = -rot.vy;
    D_800A8000.rz = 0;
    D_800A8000.sx = 0x800;
    D_800A8000.sy = 0x80;
    D_800A8000.sz = 0x800;
    func_80042538((Obj *)&D_800A8000);
    func_80023660(ang, &m);
    MulMatrix2(&D_801C0B64, &m);
    func_8002384C(&rot, &D_801FB868);
    MulMatrix2(&m, &D_801FB868);
    ScaleMatrix(&D_801FB868, &scale);
    SetRotMatrix(&D_801FB868);
    func_80070C9C(&D_801FB868, &D_801C1EC4);
    SetTransMatrix(&D_801FB868);
    z = RotTransPers((SVECTOR *)&D_800A2A10, (s32 *)sxy, &D_800A2EFC, &D_800A3394) >> 1;
    if ((D_800A3394 & ~0x1FFF) || z < 0x20 || z >= 0x980 || sxy[0] < -0x50 || sxy[0] > 0x190 || sxy[1] < -0x50 || sxy[1] > 0x190) {
        PopMatrix();
        return -1;
    }
    p = (Unk80067A30_Prim *)((u8 *)p + 8);
    do {
        D_8008009C[p->type & 0x1F](p);
    } while (!(p++->type & 0x80));
    PopMatrix();
    return 0;
}

extern s16 D_801C1ED4[];

void func_80067D08(s16 i) {
    D_801C1ED4[i] = -1;
}

void func_80067D28(s16 i) {
    D_801C1ED4[i] = D_801C1ED4[i] == 0;
}

extern s16 D_8007C582;
extern s16 D_8007C552;

void func_80067D50(void) {
    s16 *p = &D_8007C582;

    if (*p == 11) {
        *p = 0x2E;
        D_8007C552 = 0x29;
    } else {
        *p = 11;
        D_8007C552 = 0;
    }
}

void func_80067D98(void) {
    s16 *p = &D_801C1EF6;

    if (*p == 0) {
        *p = 0x400;
    } else if (*p == 0x400) {
        *p = -0x180;
    } else {
        *p = 0;
    }
}

extern s16 D_801C1EF8;

void func_80067DD8(void) {
    s16 *p = &D_801C1EF8;
    s16 v = ++*p;

    if (v >= 7) {
        *p = 1;
    } else if (v == 1) {
        *p = 2;
    }
}

extern u8 D_800A2C08;
extern u8 D_800A7FF0[];

void func_80067E20(void) {
    s16 i;

    for (i = 0; i < 16; i++) {
        D_800A7FF0[i] = 0;
    }
    D_800A2C08 = 0;
}

void func_80067E60(u8 c) {
    D_800A2C08 = (D_800A2C08 + 1) % 16;
    D_800A7FF0[D_800A2C08] = c;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_80067EA0);

typedef struct {
    u8 pad0[0x18];
    void *unk18;
    u8 pad1C[0x20];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 pad46;
    s16 unk48;
} Unk800683E4;

extern s16 D_800A34FC;
extern s16 D_800A303C;
extern s16 D_800A2FFC;
extern s16 D_800A30CC;
extern s16 D_800A329C;
extern char D_8007B574[];
extern void func_80052E18(s32);
extern void func_80055EEC(MenuObj *, s16, s16, s16);
extern void func_8005543C(void *, s32);

void func_800680A4(void) {
    Unk800683E4 *data = (Unk800683E4 *)D_800A317C->vals;
    u16 c = 0;
    s16 hold;
    s16 draw;
    s16 text;
    s16 on;
    Unk80052E88_Prim *p;
    s16 h;

    if (D_800A350C->unk178E != 0 && D_800A32AC[0] != 0) {
        D_800A350C->unk178E = 0;
    }
    hold = 0;
    draw = 0;
    on = -1;
    switch (data->unk3C) {
    case 0:
        if (D_800A34FC == 3) {
            data->unk3C++;
            data->unk40 = 0xFF;
            data->unk42 = 0;
            draw = on;
        }
        c = 0xFF;
        break;
    case 1:
        func_80052930(0, -1);
        c = 0xFF;
        draw = on;
        data->unk3C++;
        break;
    case 2:
        data->unk40 -= 8;
        draw = on;
        if (data->unk40 < 0) {
            data->unk40 = 0;
            data->unk3C++;
        }
        c = data->unk40;
        break;
    case 3:
        if (D_800A33EC != 0 || data->unk44 == 0) {
            D_800A30CC = 15;
            D_800A329C = on;
            if (D_800A303C != 0) {
                D_800A2FFC = on;
            }
            func_80052E18(3);
            data->unk3C++;
        } else {
            data->unk44--;
            hold = on;
        }
        break;
    }
    text = on;
    if (text) {
        func_80053864(160, 105, D_8007B574, 0xA28, 0x800, D_800A2A40, D_800A2A3C);
    }
    if (hold) {
        func_80055EEC(data, 0, 0, 0);
    }
    func_8005543C(data, 0);
    if (draw) {
        p = D_800A3374;
        h = D_800A33C4;
        p->r0 = c;
        p->g0 = c;
        p->b0 = c;
        setlen(p, 5);
        setcode(p, 0x2A);
        p->x0 = p->x2 = 0;
        p->y0 = p->y1 = 0;
        p->x1 = p->x3 = 320;
        p->y2 = p->y3 = h;
        addPrim(D_800A32E4 + 0x9FE, p);
        p++;
        SetDrawMode((DR_MODE *)p, 1, 1, GetTPage(0, 2, 0, 0x100), NULL);
        addPrim(D_800A32E4 + 0x9FE, (DR_MODE *)p);
        D_800A3374 = (DR_MODE *)p + 1;
    }
}

extern u8 D_80087A88[];
extern u8 D_80087B98[];
extern s16 D_801F97BC;
extern s16 D_800A34FC;
extern s16 D_800A34BC;
extern void func_800680A4(void);
extern void func_80054FEC();

void func_800683E4(void) {
    Unk800683E4 *data;

    if (D_800A2F0C != 13) {
        func_80021698(15);
    }
    D_800A30CC = 1;
    D_800A329C = 0;
    data = (Unk800683E4 *)func_80021264(func_800680A4, 1, 0x4C)->data;
    if (D_800A350C->players[D_800A350C->unk1780].unk4) {
        data->unk18 = D_80087B98;
    } else {
        data->unk18 = D_80087A88;
    }
    func_80054FEC(data);
    D_801F97BC = 0;
    data->unk44 = 600;
    if (D_800A2F0C == 13) {
        D_800A34FC = 0;
        data->unk3C = 0;
        if (D_800A333C) {
            data->unk48 = 10;
        } else {
            data->unk48 = 11;
        }
    } else {
        data->unk3C = 2;
        data->unk48 = 2;
        data->unk40 = 0xFF;
        func_80052930(0, -1);
        if (!D_800A34BC) {
            data->unk44 = 0;
        }
    }
    D_800A2F0C = 12;
    data->unk3E = 0;
    D_801D209C = 0;
}

typedef struct {
    u8 pad0[0x3C];
    s16 state;
} Unk80068540;

extern s16 D_800A315C;
extern s16 D_800A2EF0;
extern s16 D_800A2F14;
extern s16 D_800A303C;
extern s16 D_800A2FFC;
extern s16 D_800A30CC;
extern void func_80052E18(s32);
extern void func_80068DD0(void);

void func_80068540(void) {
    Unk80068540 *d = (Unk80068540 *)D_800A317C->vals;

    D_800A315C = -1;
    D_800A2EF0 = 0;
    D_800A2F14 = 0;
    d->state = 5;
    if (D_800A307C == 0) {
        if (D_800A303C != 0) {
            D_800A2FFC = -1;
        }
        func_80052E18(3);
    } else {
        D_800A307C = 0;
        func_80052E18(4);
        D_800A33F4 = D_800A307C - 1;
    }
    D_800A30CC = 15;
    func_80068DD0();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800685FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007B584);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B5D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B5E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B5FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B618);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B634);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B650);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B668);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B674);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B684);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B690);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B6A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B6C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B6DC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B6FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B708);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B714);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B724);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B758);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B774);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B790);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B7AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B7BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B7D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B7E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B7FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B80C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B824);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B830);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B83C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B858);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B874);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B880);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B88C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B8C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B8E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B8F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B90C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B938);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B94C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B968);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B97C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B990);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B99C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9B0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9CC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007B9FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BA14);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BA28);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BA40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BA5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BA74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BAA8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BAC0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BAD0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BAEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB20);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB2C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB44);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB68);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB78);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB84);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BB94);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBA0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBA8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBB4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBC0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBC8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBD4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBE0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BBF8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC0C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC14);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC1C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC28);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC30);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC3C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC54);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC6C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC88);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BC94);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BCB0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BCC4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007BCD0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BCE4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BCEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BCF8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD10);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD4C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD58);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD64);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD70);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BD8C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BDA4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BDC0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BDE0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BDEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BDFC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BE28);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BE30);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BE60);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BE84);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BEA4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BEB8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BEDC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BEFC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF1C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF20);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF3C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BF8C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BFA0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BFB8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BFC8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BFD8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007BFEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007C000);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007C020);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007C040);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007C060);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C080);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C09C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C0AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C0BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C0E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C11C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C12C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C140);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", jtbl_8007C154);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C208);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C20C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C230);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C234);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C23C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C240);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C244);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C250);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C254);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C268);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C270);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C394);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C3BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C3CC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C42C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C434);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C450);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C4FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C500);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C550);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C560);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C570);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C580);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C590);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C6F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C730);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007C734);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007F528);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007F9A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FB14);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FC48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FDB4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FF40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FF9C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8007FFB4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080000);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008001C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008008C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008009C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008011C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080254);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008041C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080420);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080424);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800804BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800804C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800804C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008055C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080574);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080594);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080598);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080614);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080618);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008065C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080660);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800806BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800806C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800806C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800806C8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008073C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080740);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080744);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080748);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800807BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800807C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800807D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800807D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080994);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800809E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080A18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080A4C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080A50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080A54);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080AEC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080AF0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080AF4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080B8C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080BB8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080C38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080CB8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080CD8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080D38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080DA0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080DB0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080E30);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080E68);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080E78);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080E88);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080EF4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80080F24);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084B64);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084C74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084D84);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084DD0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084E94);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80084FA4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800850B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800851C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800851C8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008523C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80085250);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80085254);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800852B0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80085370);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80085388);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80085398);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008539C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800854C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800874C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80087A88);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80087B98);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80087CA8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800896A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A708);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A808);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A828);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A868);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A8E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A968);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008A9E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AA08);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AB18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AC28);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AD38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AE48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008AF58);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B068);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B178);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B288);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B294);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2D0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2DC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B2F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B304);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B314);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B324);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B330);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B33C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B348);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B354);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B360);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B36C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B378);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B37C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B380);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B39C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3A0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3B0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3B8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008B3F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C41C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C43C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C440);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C444);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C448);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C44C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C450);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C470);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C474);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C478);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C47C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C49C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4A0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4EC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4F8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C4FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C558);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C55C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C560);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C564);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C568);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C56C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C580);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C594);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C59C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5A0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5C8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5CC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5D0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5DC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5F8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C5FC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C600);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C604);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C608);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C60C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C61C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C79C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C7A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008C7AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008CA2C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8008CAAC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090ABC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B3C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B4C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B54);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B58);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090B60);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090BE0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090C00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090C80);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090D00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090D80);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090DE4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E04);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E08);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E0C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E10);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E14);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E1C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E34);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E38);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E3C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E40);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E44);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E4C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E54);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E58);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E60);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E64);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E68);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E6C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E70);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E78);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E7C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E90);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090E9C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F00);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F08);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F0C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F10);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F14);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F18);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F1C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F20);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F30);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F48);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F50);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F54);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F58);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F5C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F60);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F68);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F6C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F70);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F74);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090F78);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090FA8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090FAC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80090FB0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913B0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913B8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913BC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913C0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913C4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913C8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913CC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913D0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913DC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913E4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913E8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913EC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913F0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913F4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800913F8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091408);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8009140C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091410);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091414);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091418);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8009141C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091420);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091470);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091718);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_8009189C);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800918A0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800918E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091920);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_80091924);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919A4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919A8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919AC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919B0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919B4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919B8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919D4);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919D8);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800919DC);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800921E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800A21E0);

INCLUDE_RODATA("asm/dh1/nonmatchings/dh1", D_800A29E0);

typedef struct {
    u8 pad0[0x3C];
    s16 timer;
} Unk800688DC;

void func_800688DC(void);

void func_800688B4(void) {
    ((Unk800688DC *)D_800A317C->vals)->timer = 5;
    D_800A317C->func = func_800688DC;
}

extern u8 D_800A2A48[];
extern char D_800A2C10[];
extern int VSync(int mode);
extern void StopPAD(void);
extern void func_8001FDE4(void);
extern void func_800206CC(void);
extern void func_80076F04(void);
extern void func_8006B188(s16);

extern s16 D_800A34BC;
extern void func_80052DB8(void);

void func_800688DC(void) {
    s16 *timer = &((Unk800688DC *)D_800A317C->vals)->timer;

    if (*timer != 0) {
        (*timer)--;
        func_80053864(160, D_800A33C4 >> 1, D_800A2C10, 0x800, 0x400, D_800A2A30, D_800A2A48);
    } else {
        if (D_800A34BC != 0) {
            func_80052DB8();
        }
        func_8001FDE4();
        DrawSync(0);
        VSync(0);
        StopPAD();
        func_80076F04();
        func_800206CC();
        func_8006B188(1);
    }
}

extern void (*D_8008008C[])(Unk800584A4 *, s32, s32);

void func_800689BC(void) {
    Unk8003BFA8_Entry *e = (Unk8003BFA8_Entry *)D_800A3474;
    Unk800584A4 *p;
    s16 v;
    s32 hi;
    s32 lo;
    s16 i;

    for (i = 0; i < D_800A2F6C; e++, i++) {
        if ((e->used &= 0x3F) == 0 && e->timer != 1) {
            e->timer /= 30;
        }
    }
    for (i = 0; i < D_800A31DC; i++) {
        D_800A3084[i].unkE[0] = 0;
        D_800A3084[i].unkE[1] = 0;
        D_800A3084[i].unkE[2] = 0;
        D_800A3084[i].unkE[3] = 0;
    }
    func_80058788();
    for (i = 0; i < D_800A3074; i++) {
        p = &D_800A3564[i];
        v = p->unk28;
        if (v != -1) {
            hi = (v >> 8) & 0xFF;
            lo = v & 0xFF;
            if (hi >= 0x30) {
                D_8008008C[hi](p, hi, lo);
            }
            D_800A3564[i].unk2A = -1;
            D_800A3564[i].unkA6 = 0;
        }
    }
}

void func_80068BA4(void) {
    s32 *timer = (s32 *)D_800A317C->vals;

    if (*timer != 0) {
        (*timer)--;
        func_80053864(160, D_800A33C4 >> 1, D_800A2C10, 0x800, 0x400, D_800A2A30, D_800A2A48);
    } else {
        if (D_800A34BC != 0) {
            func_80052DB8();
        }
        func_8001FDE4();
        DrawSync(0);
        VSync(0);
        StopPAD();
        func_80076F04();
        func_800206CC();
        func_8006B188(1);
    }
}

void func_80068C80(void) {
    Unk8003BA6C_Task *task;

    func_80021698(15);
    task = func_80021264(func_80068BA4, 1, 4);
    if (task != NULL) {
        *(s32 *)task->data = 0x11;
    }
}

void func_80068CC8(void) {
    s32 *timer = (s32 *)D_800A317C->vals;

    if (*timer != 0) {
        (*timer)--;
        func_80053864(160, D_800A33C4 >> 1, D_800A2C10, 0x800, 0x400, D_800A2A30, D_800A2A48);
    } else {
        func_8001FDE4();
        DrawSync(0);
        VSync(0);
        StopPAD();
        func_80076F04();
        func_800206CC();
        func_8006B188(5);
    }
}

void func_80068D88(void) {
    Unk8003BA6C_Task *task;

    func_80021698(15);
    task = func_80021264(func_80068CC8, 1, 4);
    if (task != NULL) {
        *(s32 *)task->data = 0x11;
    }
}

extern s16 D_801C1ED4[];
extern s16 D_801C1ED6;
extern s16 D_801C1ED8;
extern s16 D_801C1EDA;
extern s16 D_801C1EDC;
extern s16 D_801C1EDE;
extern s16 D_801C1EE4;
extern s16 D_801C1EE6;
extern s16 D_801C1EE8;
extern s16 D_801C1EEA;
extern s16 D_801C1EEC;
extern s16 D_801C1EEE;
extern s16 D_801C1EF2;
extern s16 D_801C1EF4;
extern s16 D_801C1EF6;
extern s16 D_801C1EF8;
extern s16 D_801C1EFA;
extern s16 D_801C1EFC;
extern s16 D_801C1F00;
extern s16 D_801C1F02;

void func_80068DD0(void) {
    D_801C1ED4[0] = 0;
    D_801C1ED6 = 0;
    D_801C1ED8 = 0;
    D_801C1EDA = 0;
    D_801C1EDC = 0;
    D_801C1EDE = 0;
    D_801C1EE4 = 0;
    D_801C1EE6 = 0;
    D_801C1EE8 = 0;
    D_801C1EEA = 0;
    D_801C1EEC = 0;
    D_801C1EEE = 0;
    D_801C1EF2 = 0;
    D_801C1EF4 = 0;
    D_801C1EF6 = 0;
    D_801C1EF8 = 0;
    D_801C1EFA = 0;
    D_801C1EFC = 0;
    D_801C1EFE = 0;
    D_801C1F00 = 0;
    D_801C1F02 = 0;
}

MATRIX *func_80068E80(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800854C0[ax & 0xFFF];
    sy = D_800854C0[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800854C0[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800854C0[(az + 0x400) & 0xFFF];
    sz = D_800854C0[az & 0xFFF];
    cx = D_800854C0[(ax + 0x400) & 0xFFF];
    m->m[0][0] = -((cy * cz + (s16)(sxsy >> 12) * sz) >> 12);
    m->m[0][1] = -((-cx * sz) >> 12);
    m->m[0][2] = -((-sy * cz + (s16)(sxcy >> 12) * sz) >> 12);
    m->m[1][0] = -((cy * sz - (s16)(sxsy >> 12) * cz) >> 12);
    m->m[1][1] = -((cx * cz) >> 12);
    m->m[1][2] = -((-sy * sz - (s16)(sxcy >> 12) * cz) >> 12);
    m->m[2][1] = sx;
    m->m[2][0] = (u32)(cx * sy) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

extern MATRIX *func_80068E80(SVECTOR *r, MATRIX *m);

void func_80069098(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80068E80(rot, &D_801FB868);
    ApplyMatrix(&D_801FB868, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern SVECTOR D_800A2FC4;
extern SVECTOR D_800A3194;
extern SVECTOR D_800A349C;
extern VECTOR D_801C1EC4;
extern MATRIX *func_80070C9C(MATRIX *m, VECTOR *v);

void func_8006912C(void) {
    D_800A349C.vx = -D_800A3194.vx;
    D_800A349C.vy = -D_800A3194.vy;
    D_800A349C.vz = -D_800A3194.vz;
    func_80068E80(&D_800A2FC4, &D_801C0B64);
    ApplyMatrix(&D_801C0B64, &D_800A349C, &D_801C1EC4);
    func_80070C9C(&D_801C0B64, &D_801C1EC4);
    SetRotMatrix(&D_801C0B64);
    SetTransMatrix(&D_801C0B64);
}

typedef struct {
    u32 tag;
    u32 code[2];
} DR_AREA;

typedef struct {
    s16 clipX;
    u8 pad[0xDC26];
} Unk800A8094;

extern Unk800A8094 D_800A8094[];
extern u32 *D_800A32E4;
extern void *D_800A3374;
extern void SetDrawArea(DR_AREA *p, RECT *r);
extern void AddPrim(void *ot, void *p);

void func_800691F0(s16 top, s32 bottom) {
    DR_AREA *prim = D_800A3374;
    RECT r;
    u32 *ot;

    r.x = D_800A8094[(s16)(D_800A333C ^ 1)].clipX;
    r.y = top;
    r.w = 320;
    r.h = bottom - top;
    SetDrawArea(prim, &r);
    ot = D_800A32E4 + 0x9FE;
    if (ot >= D_800A32E4 && ot < D_800A32E4 + 0x9FF) {
        AddPrim(ot, prim++);
    }
    D_800A3374 = prim;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[6];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk800692B4;

extern char D_80087CA8[];
extern s16 D_800A2F44;
void func_80070FDC(s32 mask);
void func_8004C19C(s32 level);
s32 func_80054990(void *data, Unk800692B4_Arg *arg);

void func_800692B4(void) {
    Unk800692B4 *d = (Unk800692B4 *)D_800A317C->vals;
    Unk800692B4_Arg arg;

    func_80070FDC(0x200);
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    if (d->unk10 < 0x1000) {
        d->unk10 += 0x100;
        func_8004C19C(0x1000 - d->unk10);
    }
    if (d->unkC > 0) {
        d->unkC -= 0x400;
        func_80054990(D_80087CA8, &arg);
    } else {
        D_800A2F44 = 3;
        func_80021554();
    }
    func_80070FDC(0x100);
}

extern SVECTOR D_800A2C18;
extern SVECTOR D_800A2C20;
extern SVECTOR D_800A2C28;
extern SVECTOR D_800A2C30;

void func_8006937C(void) {
    Unk800692B4 *d = (Unk800692B4 *)D_800A317C->vals;
    SVECTOR rot = D_800A2C18;
    SVECTOR v = D_800A2C20;
    SVECTOR base = D_800A2C28;
    Unk800692B4_Arg arg;
    SVECTOR unused;
    SVECTOR end = D_800A2C30;

    func_80070FDC(0x200);
    D_800A2FC4.vz = 0;
    D_800A2FC4.vy = d->unk2;
    D_800A2FC4.vx = 0;
    v.vz = -1000;
    v.vy = -40;
    v.vx = 0;
    func_80069098(&D_800A2FC4, &v, &base, &D_800A3194);
    func_8006912C();
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_80054990(D_80087CA8, &arg);
    d->unk10 -= 0x200;
    func_8004C19C(0x1000 - d->unk10);
    if (d->unk10 < 0) {
        D_800A2F44 = 2;
        D_800A317C->func = func_800692B4;
        func_80070FDC(0x100);
    }
    func_80070FDC(0x100);
}

typedef struct {
    u8 r, g, b, cd;
} CVECTOR;

extern CVECTOR D_800A2C38;

void func_80069520(void) {
    Unk800692B4 *d = (Unk800692B4 *)D_800A317C->vals;
    SVECTOR rot = D_800A2C18;
    SVECTOR v = D_800A2C20;
    SVECTOR base = D_800A2C28;
    Unk800692B4_Arg arg;
    SVECTOR unused;
    SVECTOR end = D_800A2C30;
    CVECTOR col = D_800A2C38;
    s16 t;

    func_80070FDC(0x200);
    D_800A2FC4.vz = 0;
    D_800A2FC4.vy = d->unk2;
    D_800A2FC4.vx = 0;
    t = d->unkA;
    v.vz = func_800296F8(-1200, -800, t);
    v.vy = func_800296F8(-120, -40, t);
    v.vz = -2000;
    v.vy = -50;
    v.vx = 0;
    if (d->unkE != 0) {
        d->unkE--;
    } else if (d->unkA < 0x1000) {
        d->unkA += 0x40;
    }
    func_80069098(&D_800A2FC4, &v, &base, &D_800A3194);
    func_8006912C();
    if (D_800A2F44 == 1) {
        d->unk10 = 0x1000;
        D_800A317C->func = func_8006937C;
    }
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_80054990(D_80087CA8, &arg);
    func_80070FDC(0x100);
}

typedef struct {
    u8 pad[0xA];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk80069728Vals;

typedef struct {
    char str[8];
} Unk80069728Name;

extern void func_8004C97C(s16 *);
extern void func_80069520(void);

void func_80069728(void) {
    Unk80069728Vals *v = (Unk80069728Vals *)D_800A317C->vals;
    Unk80069728Name name = { "d" };

    v->unkC = 0x7210;
    v->unkA = 0;
    v->unkE = 10;
    v->unk10 = 0;
    func_8004C97C((s16 *)name.str);
    func_8004C97C((s16 *)name.str);
    func_8004C97C((s16 *)name.str);
    D_800A317C->func = func_80069520;
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_800697C0);

u8 func_8006994C(u8 *data, s32 len) {
    s32 sum = 5;

    while (len != 0) {
        sum = sum + *data++ + 1;
        len--;
    }
    return sum;
}

u8 func_8006994C(u8 *data, s32 len);

s32 func_80069974(u8 *data, s32 len, u8 *out) {
    s32 n = 0;

    while (len > 0x400) {
        out[n++] = func_8006994C(data, 0x400);
        len -= 0x400;
        data += 0x400;
    }
    if (len != 0) {
        out[n++] = func_8006994C(data, len);
    }
    return n;
}

extern void StartCARD(void);
extern void _bu_init(void);
extern void _card_auto(long val);
extern long D_800A2E8C;
extern long D_800A2E94;
extern long D_800A2E9C;
extern long D_800A2EA4;

void func_80069A14(void) {
    StopPAD();
    StartCARD();
    _bu_init();
    func_8006B3C0();
    D_800A2E8C = OpenEvent(0xF4000001, 0x0004, 0x2000, NULL);
    D_800A2E94 = OpenEvent(0xF4000001, 0x8000, 0x2000, NULL);
    D_800A2E9C = OpenEvent(0xF4000001, 0x0100, 0x2000, NULL);
    D_800A2EA4 = OpenEvent(0xF4000001, 0x2000, 0x2000, NULL);
    func_8006B3D0();
    EnableEvent(D_800A2E8C);
    EnableEvent(D_800A2E94);
    EnableEvent(D_800A2E9C);
    EnableEvent(D_800A2EA4);
    _card_auto(0);
}

extern long D_800A2E8C;
extern long D_800A2E94;
extern long D_800A2E9C;
extern long D_800A2EA4;
extern long TestEvent(long event);
extern long _card_info(long chan);

long func_80069B1C(s16 chan) {
    s32 i = 0;

    if (_card_info(chan) != 0) {
        for (; i < 120; i++) {
            if (TestEvent(D_800A2E8C) == 1) {
                return -1;
            }
            if (TestEvent(D_800A2E94) == 1) {
                return 0;
            }
            if (TestEvent(D_800A2E9C) == 1) {
                return 0;
            }
            if (TestEvent(D_800A2EA4) == 1) {
                return -1;
            }
            VSync(0);
        }
    }
    return 0;
}

extern long CloseEvent(long event);
extern long StartPAD(void);
extern long StopCARD(void);

void func_80069BD4(void) {
    StopCARD();
    CloseEvent(D_800A2E8C);
    CloseEvent(D_800A2E94);
    CloseEvent(D_800A2E9C);
    CloseEvent(D_800A2EA4);
    StartPAD();
}

extern char D_800A389C[];
extern char D_8007B5D4[];
extern int func_80079E58(char *buf, char *fmt, ...);
extern int delete(char *name);

void func_80069C3C(s32 arg0, s32 arg1) {
    func_80079E58(D_800A389C, D_8007B5D4, arg1, arg0);
    delete(D_800A389C);
}

typedef struct {
    char d[64];
} McTitle;

typedef struct {
    char d[32];
} McClut;

typedef struct {
    char d[128];
} McIcon;

typedef struct {
    u8 id0;
    u8 id1;
    u8 type;
    u8 blocks;
    McTitle title;
    u8 pad44[0x1C];
    McClut clut;
    McIcon icon[3];
} McHeader;

typedef struct {
    s32 size;
    u8 sum[0xFC];
} McData;

extern McHeader D_800A357C;
extern McData D_800A377C;
extern char D_8008A828[];
extern McClut D_8008A9E8;
extern McIcon D_8008A868;
extern McIcon D_8008A8E8;
extern McIcon D_8008A968;
extern s32 open(char *name, s32 mode);
extern s32 close(s32 fd);
extern s32 write(s32 fd, void *buf, s32 n);
extern char *strcpy(char *dst, const char *src);

s32 func_80069C84(s32 arg0, u8 *data, s32 size, s32 arg3) {
    s32 n;
    s32 fd;

    func_80020340();
    D_800A357C.id0 = 'S';
    D_800A357C.id1 = 'C';
    D_800A357C.type = 0x13;
    strcpy(D_800A357C.title.d, D_8008A828);
    D_800A357C.clut = D_8008A9E8;
    D_800A357C.icon[0] = D_8008A868;
    D_800A357C.icon[1] = D_8008A8E8;
    D_800A357C.icon[2] = D_8008A968;
    n = size + 0x300;
    n = n / 0x2000 * 0x2000 + ((n & 0x1FFF) ? 0x2000 : 0);
    D_800A357C.blocks = n / 0x2000 + ((n & 0x1FFF) != 0);
    D_800A377C.size = size;
    func_80069974(data, size, D_800A377C.sum);
    func_80079E58(D_800A389C, D_8007B5D4, arg3, arg0);
    fd = open(D_800A389C, 2);
    if (fd >= 0) {
        close(fd);
        func_80020300();
        return 0;
    }
    fd = open(D_800A389C, (D_800A357C.blocks << 16) | 0x200);
    if (fd == -1) {
        func_80020300();
        return 0;
    }
    close(fd);
    fd = open(D_800A389C, 2);
    if (fd == -1) {
        func_80020300();
        return 0;
    }
    if (write(fd, &D_800A357C, 0x200) == 0x200 && write(fd, &D_800A377C, 0x100) == 0x100 && write(fd, data, size) == size) {
        close(fd);
        func_80020300();
        return -1;
    }
    close(fd);
    delete(D_800A389C);
    func_80020300();
    return 0;
}

extern s16 D_800A323C;
extern s16 D_800A337C;
extern void func_8006A290(s32, s16);

void func_8006A108(s32 arg0) {
    D_800A323C = -1;
    func_8006A290(arg0, D_800A337C);
}

extern char D_8007B5E0[];
extern char D_8007B5FC[];
extern char D_8007B618[];
extern char D_8007B634[];

char *func_8006A13C(s16 arg0) {
    if (arg0 == 0) {
        if (D_800A350C->unk178A != 0) {
            return D_8007B5E0;
        }
        return D_8007B5FC;
    }
    if (D_800A350C->unk178A != 0) {
        return D_8007B618;
    }
    return D_8007B634;
}

extern s32 open(char *name, s32 mode);
extern s32 read(s32 fd, void *buf, s32 n);
extern s32 close(s32 fd);

s32 func_8006A1A8(s16 slot) {
    char *name;
    s32 fd;

    if (slot == 0) {
        name = func_8006A13C(0);
    } else {
        name = func_8006A13C(1);
    }
    fd = open(name, 1);
    if (fd == -1) {
        close(fd);
        return 0;
    }
    if (read(fd, &D_800A357C, 0x200) != 0x200) {
        close(fd);
        return 0;
    }
    close(fd);
    return -1;
}

extern u8 D_8008AC28[];

void func_8006A248(Unk80055074 *obj) {
    func_8006A6A8();
    obj->unk18 = (s32)D_8008AC28;
    func_80054FEC(obj);
    func_8001FD58();
    func_80020300();
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8006A290);

extern u8 D_801C1B9C[];

void func_8006A468(void) {
    u8 *src = (u8 *)&D_800A350C->players[D_800A350C->unk1780];
    u8 *dst = D_801C1B9C;
    u16 i;

    for (i = 0; i < 0x2F0; i++) {
        *dst++ = *src++;
    }
}

INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8006A4C4);

void func_8006A6A8(void) {
    u8 *dst = (u8 *)&D_800A350C->players[D_800A350C->unk1780];
    u8 *src = D_801C1B9C;
    u16 i;

    for (i = 0; i < 0x2F0; i++) {
        *dst++ = *src++;
    }
}

extern s32 func_8006A72C();

void func_8006A704(s32 arg0, s16 arg1) {
    D_800A337C = arg1;
    func_8006A72C(arg0, 0);
}

typedef struct {
    void *prims[2];
    u8 pad8[8];
    void *buf[2];
    s32 unk18;
} Unk8006A72C;

extern char D_8007B668[];
extern char D_8007B674[];
extern char D_800A2C44[];
extern char D_800A2C4C[];
extern u8 D_8008AA08[];
extern u8 D_8008AF58[];
extern u8 D_8008AE48[];
extern u8 D_800A2A5C[];
extern u8 D_800A2A64[];
extern long format(char *fs);

#define SET_MENU(obj, menu) do { (obj)->unk18 = (s32)(menu); func_80054FEC(obj); } while (0)

s32 func_8006A72C(Unk8006A72C *obj, s32 unused) {
    char buf[128];
    s16 i = 3;
    s16 card0;
    s16 card1;
    long r;

    do {
        func_80055D9C();
        D_800A30A4 = (Unk8002CE64_Prim *)obj->buf[D_800A333C];
        D_800A3374 = obj->prims[D_800A333C];
        func_80053864(160, 90, D_8007B668, 0x800, 0x400, D_800A2A5C, D_800A2A64);
        func_80053864(160, 120, D_8007B674, 0x800, 0x400, D_800A2A5C, D_800A2A64);
    } while (i--);
    func_8001FDE4();
    func_80069A14();
    card0 = func_80069B1C(0);
    card1 = func_80069B1C(0x10);
    if (D_800A337C == 1) {
        card1 = 0;
    } else if (D_800A337C == 2) {
        card0 = 0;
    }
    if (!card0 && !card1) {
        goto fail;
    }
    if (card0 && card1) {
        func_80069BD4();
        SET_MENU(obj, D_8008AA08);
        func_8001FD58();
        return 0;
    }
    if (card0) {
        r = format(D_800A2C44);
    } else {
        r = format(D_800A2C4C);
    }
    if (r) {
        SET_MENU(obj, D_8008AF58);
        func_8001FD58();
        func_80069BD4();
        return -1;
    }
fail:
    func_80069BD4();
    SET_MENU(obj, D_8008AE48);
    func_8001FD58();
    return 0;
}

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C44);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C4C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C54);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C5C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C64);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C6C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C74);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C7C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C84);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C8C);

extern long D_800A2EAC;
extern long D_800A2EB4;
extern long D_800A2EBC;
extern long D_800A2EC4;
extern long TestEvent(long event);
extern long _card_info(long chan);
extern long _card_read(long chan, long block, unsigned char *buf);

long func_8006A920(s16 chan) {
    unsigned char buf[128];
    s32 i = 120;

    func_8006B3C0();
    D_800A2EAC = OpenEvent(0xF0000011, 0x0004, 0x2000, NULL);
    D_800A2EB4 = OpenEvent(0xF0000011, 0x8000, 0x2000, NULL);
    D_800A2EBC = OpenEvent(0xF0000011, 0x0100, 0x2000, NULL);
    D_800A2EC4 = OpenEvent(0xF0000011, 0x2000, 0x2000, NULL);
    func_8006B3D0();
    EnableEvent(D_800A2EAC);
    EnableEvent(D_800A2EB4);
    EnableEvent(D_800A2EBC);
    EnableEvent(D_800A2EC4);
    buf[0] = 0;
    _card_read(chan, 0, buf);
    while (i--) {
        VSync(0);
    }
    if (_card_info(chan) != 0) {
        for (; i < 600; i++) {
            if (TestEvent(D_800A2EAC) == 1) {
                break;
            }
            if (TestEvent(D_800A2EB4) == 1) {
                break;
            }
            if (TestEvent(D_800A2EBC) == 1) {
                break;
            }
            if (TestEvent(D_800A2EC4) == 1) {
                break;
            }
            VSync(0);
        }
    }
    CloseEvent(D_800A2EAC);
    CloseEvent(D_800A2EB4);
    CloseEvent(D_800A2EBC);
    CloseEvent(D_800A2EC4);
    if (buf[0] != 'M' || buf[1] != 'C') {
        return 0;
    }
    return -1;
}

void func_8006AB6C(void);

void func_8006AB40(void) {
    func_80021264(func_8006AB6C, 1, 0);
}

extern Unk80045164 *D_801FBDC8[];

void func_8006AB6C(void) {
    Unk8002A35C *player;
    Unk80045164 *a;
    Unk80045164 *b;
    s16 i;
    s16 j;
    s32 dist;

    if (D_801F7D50 == NULL) {
        return;
    }
    player = (Unk8002A35C *)D_801F7D50->vals;
    for (i = 0; i < 0x80; i++) {
        a = D_801FBDC8[i];
        if (a == NULL) {
            continue;
        }
        if (a->unk28 == 0 || a->unk28 == 4 || (a->unk154 != 0 && a->unk28 != 0x12)) {
        hide:
            a->unk15C = 0;
        } else {
            dist = func_8002A35C(player, &a->pos);
            a->unk15C = -1;
            for (j = 0; j < 0x80; j++) {
                b = D_801FBDC8[j];
                if (b == NULL || j == i) {
                    continue;
                }
                if (b->unk28 == 0 || b->unk28 == 4) {
                    continue;
                }
                if (func_8002A35C(&b->pos, player) < dist && func_8002A35C(&b->pos, &a->pos) <= dist) {
                    if (func_80043930((Unk80043930 *)a, (Unk80043930 *)player, (Unk80043930 *)b) < 0x400) {
                        goto hide;
                    }
                }
            }
        }
    }
}

extern int CdReadSync(int mode, u8 *result);
extern int VSync(int mode);
extern int printf(const char *fmt, ...);
extern char D_8007B684[];

s32 func_8006AD2C(void) {
    s16 frames;
    s16 status;

    frames = 0;
retry:
    status = CdReadSync(1, 0);
    if (status == 0) {
        return 1;
    }
    if (status == -1) {
        return 0;
    }
    VSync(0);
    if (++frames < 601) {
        goto retry;
    }
    printf(D_8007B684);
    return 0;
}

typedef struct {
    u32 pc0;
    u32 gp0;
    u32 t_addr;
    u32 t_size;
    u32 d_addr;
    u32 d_size;
    u32 b_addr;
    u32 b_size;
    u32 s_addr;
    u32 s_size;
    u32 sp, fp, gp, ret, base;
} EXEC;

typedef struct {
    char key[8];
    u32 text;
    u32 data;
    EXEC exec;
    char title[60];
} XF_HDR;

extern XF_HDR D_801F7F24;

extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern int CdRead(int sectors, u32 *buf, int mode);
extern int CdPosToInt(CdlLOC *p);
extern CdlLOC *CdIntToPos(int i, CdlLOC *p);
extern char D_8007B690[];
extern char D_8007B6A8[];
extern char D_8007B6C4[];
extern char D_8007B6DC[];

typedef struct {
    u8 data[sizeof(XF_HDR)];
} Unk8006ADB0;

int func_8006ADB0(void) {
    CdlFILE file = *(CdlFILE *)0x80012804;
    u32 *p;

    printf(D_8007B690, file.pos.minute, file.pos.second, file.pos.track, file.pos.sector);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    if (CdRead(1, (u32 *)0x80013000, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_8006AD2C() == 0) {
        return 0;
    }
    *(Unk8006ADB0 *)&D_801F7F24 = *(Unk8006ADB0 *)0x80013000;
    CdIntToPos(CdPosToInt(&file.pos) + 1, &file.pos);
    if (D_801F7F24.exec.t_addr != 0x80013000) {
        return 0;
    }
    printf(D_8007B6A8, D_801F7F24.exec.t_addr, D_801F7F24.exec.s_addr);
    for (p = (u32 *)D_801F7F24.exec.t_addr; p < (u32 *)D_801F7F24.exec.s_addr; p++) {
        *p = 0;
    }
    printf(D_8007B6C4);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    printf(D_8007B6DC);
    if (CdRead((D_801F7F24.exec.t_size + 0x7FF) >> 11, (u32 *)D_801F7F24.exec.t_addr, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_8006AD2C() == 0) {
        return 0;
    }
    printf("Loaded\n");
    return 1;
}

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2C9C);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CAC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CB4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CB8);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CBC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CC0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CC4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CCC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CD0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CD4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CD8);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CDC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CE0);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CE4);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CE8);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CEC);

INCLUDE_SDATA("asm/dh1/nonmatchings/dh1", D_800A2CF0);

extern int CdSync(int mode, unsigned char *result);

void func_8006B03C(void) {
    u8 result[8];

    CdSync(0, result);
    CdControl(10, 0, result);
    CdSync(0, result);
}

extern char D_8007B6FC[];
extern char D_8007B708[];
extern int ResetCallback(void);
extern int func_8006ADB0(void);
extern int VSyncCallback(void (*f)(void));
extern void func_8006B03C(void);
extern int ResetGraph(int mode);
extern void PadStop(void);
extern long Exec(EXEC *exec, long argc, char **argv);
extern int CdReset(int mode);

void func_8006B07C(s16 next) {
    s32 *index = (s32 *)0x80012800;
    s16 i;

    ResetCallback();
    func_8003E3CC();
    while (1) {
        if (func_8006ADB0()) {
            printf(D_8007B6FC);
            VSyncCallback(0);
            for (i = 0; i < 60; i++) {
                VSync(0);
            }
            func_800206CC();
            func_8006B03C();
            ResetGraph(3);
            PadStop();
            D_801F7F24.exec.s_addr = 0x8001D4F0;
            D_801F7F24.exec.s_size = 0;
            *index = next;
            func_8006B3C0();
            Exec(&D_801F7F24.exec, 0, 0);
            printf(D_8007B708);
        }
        CdReset(0);
    }
}

extern void func_8006B3E0(s32);

void func_8006B188(s16 arg0) {
    func_8006B3E0(0x801FFF00);
    func_8006B07C(arg0);
}
