#include "common.h"
#include "psyq/libspu.h"
#include "task.h"

extern struct Task *D_800B6DE0;

typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR;
typedef struct {
    s32 vx, vy, vz, pad;
} VECTOR;
typedef struct {
    s16 m[3][3];
    s32 t[3];
} MATRIX;
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
} Unk800B6F00;

extern void (*volatile D_800B7350)(void);

typedef struct {
    u8 pad0[0x38];
    SVECTOR unk38;
} Unk800B7398;

typedef struct {
    s16 x, y, z;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk800462F0_Obj;

typedef struct {
    SVECTOR v[16];
    u8 pad80[0x88];
    s16 unk108[16];
    u8 pad128[0x84];
} Unk800462F0_Mesh;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Unk8002A35C;

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

INCLUDE_RODATA("asm/dh2/nonmatchings/map", D_80087F7C);

INCLUDE_RODATA("asm/dh2/nonmatchings/map", D_80087F80);

INCLUDE_RODATA("asm/dh2/nonmatchings/map", D_80087F90);

INCLUDE_SDATA("asm/dh2/nonmatchings/map", D_800B61E4);

s32 D_800B61F0 = 0;

INCLUDE_SDATA("asm/dh2/nonmatchings/map", D_800B61F4);

INCLUDE_SDATA("asm/dh2/nonmatchings/map", D_800B61FC);

INCLUDE_SDATA("asm/dh2/nonmatchings/map", D_800B6214);

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x10];
} Entry18;

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001E470);

typedef struct {
    s16 x, y, w, h;
} RECT;

typedef struct {
    char text[32];
    u8 r, g, b, pad;
    s32 time;
    s16 unk28;
    s16 unk2A;
} CreditLine;

extern CreditLine D_80089568[];

extern CreditLine D_8008969C[];

extern RECT D_800B61E4;
extern int ClearImage(RECT *rect, u8 r, u8 g, u8 b);
void func_8001E470(const CreditLine *lines, s16 t);
s32 func_80025570(s32 value, s32 target, s32 step);
void func_80071FDC(void);
void func_800720E4(void);

void func_8001E6EC(void) {
    RECT r = D_800B61E4;

    if (D_800B6DE0->unk14 == 0) {
        func_8001E470(D_80089568, D_800B6DE0->unk16);
    } else if (D_800B6DE0->unk14 == 1) {
        func_8001E470(D_8008969C, D_800B6DE0->unk16);
    } else if (D_800B6DE0->unk16 >= 6) {
        ClearImage(&r, 0, 0, 0);
        func_80071FDC();
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_800720E4;
        }
    }
    D_800B6DE0->unk16 = func_80025570(D_800B6DE0->unk16, 0xF0, 1);
    if (D_800B6DE0->unk16 == 0xF0) {
        D_800B6DE0->unk16 = 0;
        D_800B6DE0->unk14++;
    }
}

void func_8001E834(void) {
}

void func_8001E83C(void) {
}

void func_8006C638(s32 arg0, s32 arg1);

void func_8001E844(void) {
    if (++D_800B6DE0->unk14 > 330) {
        func_8006C638(0, 0);
    }
}

typedef struct {
    u8 maps[8][0x2F0];
    s16 unk1780;
    u8 pad1782[2];
    s16 unk1784;
    s16 unk1786;
    s16 unk1788;
    s16 unk178A;
    s16 unk178C;
    s16 unk178E;
} Unk800B7370;

extern void SetFogFar(long a, long h);
extern void SetGraphDebug(int level);
void func_80066474(void);
void func_80070C98(void);
void func_8003D6D4(void);
void func_80025E38(void);
void func_80031B9C(void);
void func_80023AC0(void);
extern s16 D_800B6FD8;
extern s16 D_800B63DC;
extern s16 D_800B6E68;
extern s16 D_800B6D38;
extern u16 D_800B6C30;
extern s16 D_800B6C68;
extern s16 D_800B7030;
extern Unk800B7370 *D_800B7370;
extern Unk800B6F00 *D_800B6F00;
extern s16 D_800B6AA0;
extern s16 D_800B6CE0;
extern s32 D_800B6CC8;
extern s32 D_800B6D08;
extern s32 D_800B6A6C;
extern s32 D_800B6C48;
extern u8 D_800B71D0;
extern s16 D_800B72A0;
extern s16 D_800B6AD8;
extern s16 D_800B7238;
extern s16 D_800B7250;
extern s16 D_800B6E48;
extern s16 D_800B7430;
extern s16 D_800B7260;
extern s16 D_800B73A0;
extern s16 D_800B67DE;
extern s16 D_800B7110;
extern s16 D_800B70C8;

void func_8001E890(void) {
    SVECTOR unused;

    D_800B6FD8 = 0;
    D_800B63DC = 0;
    SsUtReverbOff();
    func_80066474();
    SetFogFar(0x10400, 0xFF);
    D_800B6E68 = 0;
    D_800B6D38 = 0;
    D_800B6C30 = 0;
    D_800B6C68 = 0;
    D_800B7030 = 0;
    D_800B7370 = (Unk800B7370 *)0x80011000;
    func_80070C98();
    D_800B6F00 = (Unk800B6F00 *)&D_800B7370->maps[D_800B7370->unk1780][0x2B0];
    func_8003D6D4();
    D_800B6AA0 = 2;
    D_800B6CE0 = 0;
    D_800B6CC8 = 0;
    D_800B6D08 = 0;
    D_800B6A6C = 0;
    D_800B6C48 = 0;
    D_800B71D0 = 0;
    func_80025E38();
    SetGraphDebug(0);
    D_800B72A0 = 0;
    D_800B6AD8 = 0;
    D_800B7238 = 2;
    D_800B7250 = 1;
    D_800B7350 = (void (*)(void))-1;
    func_80031B9C();
    D_800B6E48 = -1;
    D_800B7430 = D_800B7260;
    D_800B70C8 = D_800B7370->maps[D_800B7370->unk1780][0xF];
    D_800B73A0 = 2;
    D_800B67DE = 0;
    D_800B7110 = 0;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80023AC0;
    }
}

s32 func_8001EA74(void) {
    return 0x39;
}

s32 func_8001EA7C(void) {
    return 0xB1;
}

extern void func_8007FD1C(void);
extern void func_8007FFB4(void);
extern long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
extern long EnableEvent(long event);
extern long SetRCnt(unsigned long spec, unsigned short target, long mode);
extern long StartRCnt(unsigned long spec);
extern long ResetRCnt(unsigned long spec);
extern long D_800B6ED0;
extern s32 D_800B6CC8;
extern s16 D_800B639E;
extern s16 D_800B63DC;
long func_80024314();

void func_8001EA84(void) {
    if (D_800B63DC == 0) {
        func_8007FD1C();
        D_800B6ED0 = OpenEvent(0xF2000003, 2, 0x1000, func_80024314);
        EnableEvent(D_800B6ED0);
        SetRCnt(0xF2000003, 1, 0x1000);
        StartRCnt(0xF2000003);
        ResetRCnt(0xF2000003);
        func_8007FFB4();
        D_800B6CC8 = 0;
        D_800B639E = 1;
        D_800B63DC = -1;
    }
}

extern s16 D_800B63DC;
extern long D_800B6ED0;
extern long CloseEvent(long event);
extern long DisableEvent(long event);
extern void func_8007FD1C(void);
extern void func_8007FFB4(void);

void func_8001EB30(void) {
    if (D_800B63DC != 0) {
        func_8007FD1C();
        CloseEvent(D_800B6ED0);
        DisableEvent(D_800B6ED0);
        func_8007FFB4();
        D_800B63DC = 0;
    }
}

extern void SetFogNear(s32 a, s32 h);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern MATRIX D_80169F78;
extern SVECTOR D_800B6E90;
extern SVECTOR D_800B6E00;
extern SVECTOR D_800B6F28;
extern SVECTOR D_800B6F50;
extern s16 D_800B70D0;

void func_8001EB8C(void) {
    SetFogNear(0x7D00, 0x100);
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
    D_800B70D0 = 0;
    D_800B6F28.vx = D_800B6E90.vx;
    D_800B6F28.vy = D_800B6E90.vy;
    D_800B6F28.vz = D_800B6E90.vz;
    D_800B6F50.vx = D_800B6E00.vx;
    D_800B6F50.vy = D_800B6E00.vy;
    D_800B6F50.vz = D_800B6E00.vz;
}

extern SVECTOR D_800B6E90;
extern SVECTOR D_800B6E00;
extern SVECTOR D_800B6F28;
extern SVECTOR D_800B6F50;
void func_8001ED90();

void func_8001EC38(void) {
    SVECTOR rot;
    SVECTOR pos;

    rot.vx = D_800B6E90.vx;
    rot.vy = D_800B6E90.vy;
    rot.vz = D_800B6E90.vz;
    pos.vx = D_800B6E00.vx;
    pos.vy = D_800B6E00.vy;
    pos.vz = D_800B6E00.vz;
    D_800B6E90.vx = D_800B6F28.vx;
    D_800B6E90.vy = D_800B6F28.vy;
    D_800B6E90.vz = D_800B6F28.vz;
    D_800B6E00.vx = D_800B6F50.vx;
    D_800B6E00.vy = D_800B6F50.vy;
    D_800B6E00.vz = D_800B6F50.vz;
    func_8001ED90();
    D_800B6E90.vx = rot.vx;
    D_800B6E90.vy = rot.vy;
    D_800B6E90.vz = rot.vz;
    D_800B6E00.vx = pos.vx;
    D_800B6E00.vy = pos.vy;
    D_800B6E00.vz = pos.vz;
}

extern MATRIX D_80169F78;
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern s16 D_800B70D0;

void func_8001ED4C(void) {
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
    D_800B70D0 = 1;
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001ED90);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001F744);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001F90C);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001FB8C);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8001FD90);

typedef struct {
    SVECTOR *v[4];
    u16 tex;
    u16 pad12;
    s32 unk14;
    s32 unk18;
} Unk80020030_Prim;

extern VECTOR D_80087F80;
extern void *D_800B7140;
extern u8 *D_800B70A8;
extern SVECTOR D_800B6E00;
extern SVECTOR D_800B72C0;
extern MATRIX D_80169F78;
extern VECTOR D_801C9980;
extern s32 D_800B63A8;
extern MATRIX D_801F9644;
extern Unk8002A35C D_800B67D0;
extern s32 D_800B6A90;
extern s32 D_800B7198;
extern s32 D_800B6F30;
extern void PushMatrix(void);
extern void PopMatrix(void);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX *MulMatrix2(MATRIX *m0, MATRIX *m1);
extern MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern s32 RotTransPers(SVECTOR *v0, s32 *sxy, s32 *p, s32 *flag);
extern MATRIX *func_8002702C(SVECTOR *r, MATRIX *m);
extern MATRIX *func_80027444(SVECTOR *r, MATRIX *m);
extern MATRIX *func_80085EA0(MATRIX *m, VECTOR *v);
extern void func_80030E08(Unk80020030_Prim *p);

s32 func_80020030(Unk80020030_Prim *p, SVECTOR *pos, SVECTOR *ang) {
    s16 sxy[2];
    VECTOR scale = D_80087F80;
    MATRIX m;
    SVECTOR rot;

    if ((u8 *)D_800B7140 - D_800B70A8 > 0xD66F) {
        return 0;
    }
    PushMatrix();
    D_800B72C0.vx = pos->vx - D_800B6E00.vx;
    D_800B72C0.vy = pos->vy - D_800B6E00.vy;
    D_800B72C0.vz = pos->vz - D_800B6E00.vz;
    ApplyMatrix(&D_80169F78, &D_800B72C0, &D_801C9980);
    rot.vx = 0;
    rot.vz = 0;
    rot.vy = D_800B63A8 * 300;
    func_8002702C(ang, &m);
    MulMatrix2(&D_80169F78, &m);
    func_80027444(&rot, &D_801F9644);
    MulMatrix2(&m, &D_801F9644);
    ScaleMatrix(&D_801F9644, &scale);
    SetRotMatrix(&D_801F9644);
    func_80085EA0(&D_801F9644, &D_801C9980);
    SetTransMatrix(&D_801F9644);
    D_800B6F30 = RotTransPers((SVECTOR *)&D_800B67D0, (s32 *)sxy, &D_800B6A90, &D_800B7198);
    if ((D_800B7198 & ~0x1FFF) || D_800B6F30 < 0x20 || D_800B6F30 >= 0x1771) {
        PopMatrix();
        return -1;
    }
    p = (Unk80020030_Prim *)((u8 *)p + 8);
    while (p->unk14 != 0) {
        func_80030E08(p);
        p++;
    }
    PopMatrix();
    return 0;
}

extern s32 D_800B61F0;
extern s32 D_801F9A5C[];
extern s32 *D_800B71F0;
u32 func_80072780(void *data, s16 i);
s32 func_80072798(void *data, s16 i);
void *func_80072768(void *data, s16 i);
s32 *func_80031FBC(void *src, s32 *dst, s32 size);
void func_80031FB4();
void func_80031F90();

s32 func_80020278(void *bank, s16 n) {
    s16 i;
    s16 same;
    u32 size;
    s32 *a;
    s32 *b;
    s32 *p;

    for (i = 0; i < n; i++) {
        if (func_80072780(bank, i) == func_80072780(bank, n) && func_80072798(bank, i) == func_80072798(bank, n)) {
            size = func_80072780(bank, n) & 0xFFFC;
            if (size != 0) {
                a = func_80072768(bank, n);
                b = func_80072768(bank, i);
                same = -1;
                for (size -= 4; size != 0; size -= 4) {
                    if (*a != *b) {
                        same = 0;
                        break;
                    }
                    a++;
                    b++;
                }
                if (same) {
                    return D_801F9A5C[i];
                }
            }
        }
    }
    D_800B61F0++;
    p = D_800B71F0;
    D_800B71F0 = func_80031FBC(func_80072768(bank, n), p, func_80072798(bank, n));
    func_80031FB4(p);
    func_80031F90(p);
    return (s32)p;
}

extern s32 D_801F9A5C[];
extern s32 *D_800B71F0;
s32 func_80024F60(s32 size);
s32 func_80020278(void *, s16);
u32 func_80072780(void *data, s16 i);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    void *unk8;
} Unk80020444;

void func_80020444(void) {
    Unk80020444 *p = (Unk80020444 *)D_800B6DE0->vals;
    s16 n = 0;

    do {
        if (func_80072780(p->unk8, p->unk2) < 8) {
            D_801F9A5C[p->unk2] = 0;
        } else {
            n++;
            D_801F9A5C[p->unk2] = func_80020278(p->unk8, p->unk2);
        }
        if (++p->unk2 == *(s32 *)p->unk8) {
            D_800B71F0 = (s32 *)func_80024F60((s32)D_800B71F0);
            if (D_800B6DE0->func == D_800B7350) {
                TRAP();
            } else {
                D_800B6DE0->func = D_800B6DE0->saved;
                return;
            }
        }
    } while (n < 20);
}

extern u8 D_801F9664[];
extern s32 *D_800B71F0;
extern Unk800B7398 *D_800B7398;
s32 func_80024F60(s32 size);
extern s32 D_801F9A5C[];
void func_80020444(void);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
} Unk80020560;

void func_80020560(s32 arg0) {
    Unk80020560 *p = (Unk80020560 *)D_800B6DE0->vals;
    s16 i;

    D_800B7398 = (Unk800B7398 *)func_80024F60((s32)D_801F9664);
    D_800B71F0 = (s32 *)func_80024F60((s32)D_800B71F0);
    i = 99;
    do {
        D_801F9A5C[i] = 0;
    } while (i--);
    p->unk2 = 0;
    p->unk8 = arg0;
    D_800B6DE0->saved = D_800B6DE0->func;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80020444;
    }
}

extern SVECTOR D_800B6E00;
extern SVECTOR D_800B6E90;
extern SVECTOR D_800B6C28;
void func_8007583C(void);

void func_80020634(void) {
    D_800B6E00.vx = 0;
    D_800B6E00.vy = 0;
    D_800B6E00.vz = 0;
    D_800B6C28.vx = 0;
    D_800B6C28.vy = 0;
    D_800B6C28.vz = 0;
    D_800B6E90.vx = 0;
    D_800B6E90.vy = 0;
    D_800B6E90.vz = 0;
    func_8007583C();
}

extern SVECTOR D_800B6E90;
extern SVECTOR D_800B6E00;
extern SVECTOR D_800B72C0;
extern MATRIX D_80169F78;
extern VECTOR D_801C9980;
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern MATRIX *func_80027444(SVECTOR *r, MATRIX *m);
extern void func_80024C98(MATRIX *m);
extern MATRIX *func_80085EA0(MATRIX *m, VECTOR *v);

void func_8002069C(void) {
    D_800B72C0.vx = -D_800B6E00.vx;
    D_800B72C0.vy = -D_800B6E00.vy;
    D_800B72C0.vz = -D_800B6E00.vz;
    func_80027444(&D_800B6E90, &D_80169F78);
    func_80024C98(&D_80169F78);
    ApplyMatrix(&D_80169F78, &D_800B72C0, &D_801C9980);
    func_80085EA0(&D_80169F78, &D_801C9980);
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
}

extern SVECTOR D_800B6C28;
extern SVECTOR D_800B72C0;
extern s16 D_800B7010;
extern SVECTOR D_800B6E90;
extern MATRIX D_80169F78;
extern VECTOR D_801C9980;
MATRIX *func_80027674(SVECTOR *rot, MATRIX *m);
extern MATRIX *func_80027444(SVECTOR *r, MATRIX *m);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX *func_80085EA0(MATRIX *m, VECTOR *v);
extern void func_80024C98(MATRIX *m);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);

void func_80020770(void) {
    D_800B72C0.vx = -D_800B6C28.vx;
    D_800B72C0.vy = -D_800B6C28.vy;
    D_800B72C0.vz = -D_800B6C28.vz;
    if (D_800B7010 != 0) {
        func_80027674(&D_800B6E90, &D_80169F78);
    } else {
        func_80027444(&D_800B6E90, &D_80169F78);
    }
    ApplyMatrix(&D_80169F78, &D_800B72C0, &D_801C9980);
    func_80085EA0(&D_80169F78, &D_801C9980);
    func_80024C98(&D_80169F78);
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
}

void func_80020874(void) {
}

void func_8002069C(void);
void func_80020874(void);

typedef struct {
    u8 pad0[0x74];
    s16 unk74;
    s16 unk76;
} Unk8002087C;

void func_8002087C(void) {
    Unk8002087C *p = (Unk8002087C *)D_800B6DE0->vals;

    p->unk74 = 0;
    p->unk76 = 1;
    if (p->unk74 == 1) {
        p->unk76 = 2;
    }
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80020874;
    }
    func_8002069C();
    func_80020874();
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8002090C);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80020AFC);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80020E50);

INCLUDE_RODATA("asm/dh2/nonmatchings/map", jtbl_80087FA0);

INCLUDE_RODATA("asm/dh2/nonmatchings/map", D_80088098);

extern SVECTOR D_800B7158;

void func_80021380(s16 x, s16 y, s16 z) {
    D_800B7158.vx = func_80025570(D_800B7158.vx, x, 1);
    D_800B7158.vy = func_80025570(D_800B7158.vy, y, 1);
    D_800B7158.vz = func_80025570(D_800B7158.vz, z, 1);
}

extern SVECTOR D_800B6ED8;

void func_80021414(s16 x, s16 y, s16 z) {
    D_800B6ED8.vx = func_80025570(D_800B6ED8.vx, x, 1);
    D_800B6ED8.vy = func_80025570(D_800B6ED8.vy, y, 1);
    D_800B6ED8.vz = func_80025570(D_800B6ED8.vz, z, 1);
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_800214A8);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80021624);

typedef struct {
    u8 pad0[0x16C];
    s32 unk16C;
} Unk80021780;

extern struct Task *volatile D_801F7544;
void func_800214A8(s32 arg);
void func_80021624(s32 arg);

void func_80021780(void) {
    s32 p = ((Unk80021780 *)D_801F7544->vals)->unk16C;

    func_80021414(0, 0, 0);
    func_80021380(0, 0, 0);
    func_800214A8(p);
    func_80021624(p);
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_800217DC);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Unk800219ECPos;

typedef struct {
    u8 pad0[0x162];
    Unk800219ECPos unk162;
    u8 pad168[4];
    s32 unk16C;
} Unk800219EC;

void func_800219EC(void) {
    Unk800219EC *p = (Unk800219EC *)D_801F7544->vals;
    s32 buf;

    p->unk16C += func_80077398(&D_800B6E00, &p->unk162) * 5;
    p->unk162.x = D_800B6E00.vx;
    buf = p->unk16C;
    p->unk162.z = D_800B6E00.vz;
    func_80021414(0x10, 0x10, 0x10);
    func_80021380(0, 0x10, 0);
    func_800214A8(buf);
    func_80021624(buf);
}

void func_80021A8C(void) {
    Unk800219EC *p = (Unk800219EC *)D_801F7544->vals;
    s32 buf;

    p->unk16C += func_80077398(&D_800B6E00, &p->unk162) * 5;
    p->unk162.x = D_800B6E00.vx;
    buf = p->unk16C;
    p->unk162.z = D_800B6E00.vz;
    func_80021414(0x10, 0x10, 0x10);
    func_80021380(0, 0x40, 0);
    func_800214A8(buf);
    func_80021624(buf);
}

void func_80021B2C(void) {
    Unk800219EC *p = (Unk800219EC *)D_801F7544->vals;
    s32 buf;

    p->unk16C += func_80077398(&D_800B6E00, &p->unk162) * 8;
    p->unk162.x = D_800B6E00.vx;
    buf = p->unk16C;
    p->unk162.z = D_800B6E00.vz;
    func_80021414(0x20, 0x20, 0x20);
    func_80021380(0, 0x40, 0);
    func_800214A8(buf);
    func_80021624(buf);
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80021BC8);

void func_80021D70(void) {
    Unk800219EC *p = (Unk800219EC *)D_801F7544->vals;
    s32 buf;

    p->unk16C += func_80077398(&D_800B6E00, &p->unk162) * 3;
    p->unk162.x = D_800B6E00.vx;
    buf = p->unk16C;
    p->unk162.z = D_800B6E00.vz;
    func_80021414(0x20, 0x20, 0x20);
    func_80021380(0, 0x20, 0);
    func_800214A8(buf);
    func_80021624(buf);
}

typedef struct {
    u8 pad0[0x188];
    s16 unk188;
    s16 unk18A;
    s16 unk18C;
    s16 unk18E;
} Unk80021E10;

extern s16 D_800B639E;
extern s16 D_800B6E94[];

void func_80021E10(void) {
    Unk80021E10 *p = (Unk80021E10 *)D_800B6DE0->vals;

    p->unk188 += p->unk18A;
    p->unk18A -= D_800B639E * 4;
    D_800B6E94[0] += p->unk18C;
    p->unk18C += p->unk18E;
    if (p->unk188 <= 0x80) {
        p->unk188 = 0x80;
        p->unk18A = ABS(p->unk18A) / 2;
        p->unk18E = -p->unk18E / 2;
        if (p->unk18A < 0x10) {
            p->unk18A = 0;
            p->unk18E = 0;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80021EDC);

extern s16 D_800B6AA0;
extern Unk8002A35C D_800B67D0;
extern SVECTOR D_800B7158;
extern SVECTOR D_800B6ED8;
void func_80020E50(void *);
void func_8002090C(void *);
void func_80021EDC(void);

typedef struct {
    u8 pad0[0x10];
    u8 unk10[0x134];
    s32 unk144;
    s16 unk148;
    s16 unk14A;
    u8 pad14C[8];
    s32 unk154;
    u8 pad158[8];
    s16 unk160;
    u8 pad162[0xE];
    s16 unk170;
    s16 unk172;
    s16 unk174;
    s16 pad176;
    s16 unk178;
    s16 unk17A;
    u8 pad17C[8];
    s16 unk184;
    s16 unk186;
    s16 unk188;
    u8 pad18A[6];
    s16 unk190;
} Unk8002225C;

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_8002225C);

extern s16 D_800B72E0;
extern s32 *D_800B7088;

void func_800223A0(void) {
    D_800B72E0 = -1;
    D_800B7088 = 0;
}

extern s16 D_800B6FD8;
void func_8001EB30(void);

void func_800223BC(void) {
    func_8001EB30();
    DrawSync(0);
    VSync(0);
    ResetGraph(3);
    ResetCallback();
    if (D_800B6FD8 != 0) {
        SelectGun(0, 0);
        SelectGun(1, 0);
    }
    StopGun();
    ResetGun();
    StopPAD();
    PadStop();
    func_8003DD54();
    func_800739C0();
}

void func_80022454(void) {
    u8 unused[16];
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80022460);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80022528);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_800226B0);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80022974);

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80022A10);

extern s16 D_800B70B8;
extern s16 D_800B6B70;
extern s16 D_800B6CB0;
extern u8 *D_800B6C40;
extern u8 *D_800B6C44;

void func_80022B58(void) {
    if (D_800B70B8 == 1) {
        if (D_800B6B70 == 4) {
            if (D_800B6FD8 != 0) {
                SelectGun(0, 0);
                SelectGun(1, 0);
            }
            StopGun();
            StopPAD();
            if (D_800B6FD8 == 0) {
                ResetCallback();
                InitGun(D_800B6C40 + 4, D_800B6C44 + 4, 0x12);
                D_800B6FD8 = -1;
            }
            StartPAD();
            StartGun();
            SelectGun(0, 1);
            D_800B70B8 = 0;
            if (D_800B6CB0 >= 6) {
                D_800B6CB0 = 5;
            }
        } else {
            D_800B70B8 = 0;
        }
    } else if (D_800B70B8 == 2) {
        if (D_800B6FD8 != 0) {
            SelectGun(0, 0);
            SelectGun(1, 0);
        }
        StopGun();
        StopCARD();
        D_800B70B8 = 0;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/map", func_80022CA8);

extern RECT D_800B6214;
extern volatile s32 D_800B725C;
extern u16 D_8009B47C;
extern s32 D_800B7258[];
extern s16 D_800B6C60[3];
extern s16 D_800B6390;
extern s16 D_800B72F8;
extern s16 D_800B63A6;
extern s16 D_800BD994[];
extern s16 D_80169F98[];
extern u8 D_801F9A57;
extern u8 D_80169FDC;
struct Task *func_80072F2C(void (*fn)(), s16 size);
void func_80033730(s16 *angle, s16 *speed);
void func_80072044(void);
void func_80072484(void);
void func_80070CFC(void);
void func_80070D90(void);
void func_80072094(void);
void func_800725EC(void);
void func_800645A8(void);
void func_8003DBC4(void);
void func_800665E4(void);
void func_80071F20(void);
void func_80023858(void);
void func_80024124(void);
extern s32 DrawSync(s32 mode);

void func_8002318C(void) {
    RECT r = D_800B6214;
    u8 *flag;

    func_8003DBC4();
    if (D_800B6F00->unk0 != 0 && (D_8009B47C & *(volatile s32 *)&D_800B725C)) {
        D_800B7260 = (D_800B7430 + 1) % 8;
        D_800B72A0 = 0;
    }
    D_800B6C60[0] = 100;
    D_800B6390 = 12;
    D_800B72F8 = 0;
    D_800B63A6 = *(volatile s32 *)D_800B7258 & D_8009B47C;
    DrawSync(0);
    func_80022CA8();
    func_800665E4();
    func_80033730(D_800BD994, D_80169F98);
    flag = &D_801F9A57;
    if (*flag) {
        *flag = 0;
        if (D_800B7430 == 7) {
            D_800B6AA0 = 11;
        } else {
            D_800B7260 = (D_800B7430 + 1) % 8;
            D_800B72A0 = 0;
        }
    }
    if (D_800B6AA0 == 2) {
        func_80071F20();
        func_80071FDC();
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_800720E4;
        }
    } else if (D_800B6AA0 == 4) {
        func_80072044();
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_80072484;
        }
    } else if (D_800B6AA0 == 11) {
        func_80070CFC();
        D_80169FDC = 100;
        func_80070D90();
        func_80072094();
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_800725EC;
        }
    } else {
        if (D_800B7260 != D_800B7430 && D_800B6D38 == 0) {
            func_80072F2C(func_800645A8, 0x3FF);
            D_800B6D38 = 1;
        }
        if (D_800B6D38 == 2) {
            if (D_800B6DE0->func == D_800B7350) {
                TRAP();
            } else {
                D_800B6DE0->func = func_80024124;
            }
        }
        if (D_800B6AA0 == 9) {
            func_80023858();
        }
    }
}

CreditLine D_80089568[] = {
    { "DIE HARD TRILOGY FROM", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "FOX INTERACTIVE", 0xFF, 0x40, 0x40, 0, 200, 0x800, 0x400 },
    { "3 EXPLOSIVE ADVENTURES", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "ON 1 DISC \\ TAKE AIM AND", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "PLAY A SEGMENT FROM", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "DIE HARD 2 ^ DIE HARDER", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "", 0xFF, 0xFF, 0xFF, 0, 255, 0x640, 0x3E8 },
};
CreditLine D_8008969C[] = {
    { " ", 0xFF, 0x40, 0x40, 0, 200, 0x708, 0x800 },
    { "DIE HARD TRILOGY", 0xFF, 0x40, 0x40, 0, 200, 0x708, 0x400 },
    { "e AND f  1996", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "FOX INTERACTIVE", 0xFF, 0x40, 0x40, 0, 200, 0x800, 0x400 },
    { "ALL RIGHTS RESERVED", 0xFF, 0x40, 0x40, 0, 200, 0x600, 0x400 },
    { "", 0xFF, 0xFF, 0xFF, 0, 255, 0x640, 0x3E8 },
};
INCLUDE_DATA("asm/dh2/nonmatchings/map", D_800897A4);
INCLUDE_DATA("asm/dh2/nonmatchings/map", D_800897F4);
