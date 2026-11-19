#include "common.h"
#include "psyq/libspu.h"

typedef struct {
    s32 vx, vy, vz, pad;
} VECTOR;
typedef struct {
    s16 m[3][3];
    s32 t[3];
} MATRIX;
typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR;

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
} Unk800B61A4;

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086BD4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086BD8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086BE8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086C58);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086C78);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086C84);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086CAC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086CBC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086CE4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086D00);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086D10);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086D58);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086D68);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086D8C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086DB4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086DC0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086DCC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086DD8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086EA8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086EB8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086ECC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086EDC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086EEC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80086F04);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F1C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F34);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F44);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F50);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F6C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086F88);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086FA0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086FC4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086FD8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80086FEC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80087008);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008701C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008702C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008703C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087048);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087054);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008706C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087088);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800870A0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800870C0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800870CC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_800870D8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_800870F8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80087118);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_80087138);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087158);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087168);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087178);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008718C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871A0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871B8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871D0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871E4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871EC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800871F8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087204);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087210);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008721C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087228);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087234);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087240);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087244);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087250);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087260);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008726C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087274);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087280);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008728C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087294);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872A0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872AC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872B8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872C4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872CC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872D8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872E0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872E8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872F4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800872FC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087308);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087314);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087320);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087328);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087338);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087354);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087360);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008737C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087390);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_8008739C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873B0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873B8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873C4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873CC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873DC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800873E4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087418);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087424);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087430);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008743C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087454);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087464);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087480);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087494);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800874AC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800874E0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800874FC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087518);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087534);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087544);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087554);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087588);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800875A8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800875BC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800875D4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087600);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087614);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087630);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087644);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087658);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087664);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087678);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008767C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087688);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087694);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800876A0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800876AC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800876C4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800876DC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800876F0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087708);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087724);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008773C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087770);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087788);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877A0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877B0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877C8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877D8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877F0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800877FC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087808);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087824);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087840);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8008784C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087858);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087874);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087884);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087894);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800878BC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800878F4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087904);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087918);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", jtbl_8008792C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800879E0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800879E4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A08);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A0C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A14);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A18);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A1C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A28);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A2C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001E470);

s32 func_8001E664(void) {
    return 0;
}

s32 func_8001E66C(void) {
    return 0xF0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001E674);

extern struct Task *D_800B604C;
extern s32 *D_800B6464;
extern void *D_800B5E4C;
extern s32 *D_800B6344;
extern s32 *D_800B5D3C;
extern s32 D_800B6544;
extern s32 *D_800B62EC;
extern s32 D_800B5D04;
u32 func_80071BC8(void *data, s16 i);
void func_8004FF54(void);

void func_8001E83C(void) {
    D_800B6344 = D_800B6464;
    D_800B5D3C = func_80071BB0(D_800B5E4C, 2);
    D_800B6544 = 0;
    D_800B62EC = D_800B6464;
    D_800B5D04 = func_80071BC8(D_800B5E4C, 2);
    D_800B6464 = (s32 *)((u8 *)D_800B6464 + D_800B5D04);
    D_800B604C->saved = D_800B604C->func;
    D_800B604C->func = func_8004FF54;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001E8D8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001EECC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001F1DC);

extern void func_8007F2B4(void);
extern void func_8007F53C(void);
extern long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
extern long EnableEvent(long event);
extern long SetRCnt(unsigned long spec, unsigned short target, long mode);
extern long StartRCnt(unsigned long spec);
extern long D_800B617C;
extern s32 D_800B5F64;
extern s32 D_800B5F8C;
extern s16 D_800B56A2;
extern s16 D_800B6514;
long func_80026230();

void func_8001F39C(void) {
    if (D_800B6514 == 0) {
        func_8007F2B4();
        D_800B617C = OpenEvent(0xF2000003, 2, 0x1000, func_80026230);
        EnableEvent(D_800B617C);
        SetRCnt(0xF2000003, 1, 0x1000);
        StartRCnt(0xF2000003);
        func_8007F53C();
        D_800B5F64 = 0;
        D_800B5F8C = 0;
        D_800B56A2 = 1;
        D_800B6514 = -1;
    }
}

extern s16 D_800B6514;
extern long D_800B617C;
extern void func_8007F2B4(void);
extern void func_8007F53C(void);
extern long CloseEvent(long event);

void func_8001F444(void) {
    if (D_800B6514 != 0) {
        func_8007F2B4();
        CloseEvent(D_800B617C);
        func_8007F53C();
        D_800B6514 = 0;
    }
}

typedef struct {
    VECTOR pos;
    u8 pad10[0x10];
} Unk801F83F8;

extern Unk801F83F8 D_801F83F8[];
extern MATRIX D_801981D4;
extern SVECTOR D_800B6574;
extern SVECTOR D_800B5EAC;
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);

void func_8001F490(void) {
    s32 i, j;

    for (i = 5; i != -1; i--) {
        for (j = 5; j != -1; j--) {
            D_800B6574.vx = (j << 12) - D_800B5EAC.vx;
            D_800B6574.vy = -D_800B5EAC.vy;
            D_800B6574.vz = (i << 12) - D_800B5EAC.vz;
            ApplyMatrix(&D_801981D4, &D_800B6574, &D_801F83F8[j + i * 6].pos);
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001F55C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001F86C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001F9C0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8001FAF4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80020B40);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80020EEC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800210B8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80021518);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80021704);

typedef struct {
    u8 pad[0x14];
    s32 unk14;
    s32 unk18;
} Unk80021854_Prim;

extern VECTOR D_80086BD8;
extern Unk800B61A4 *D_800B61A4;
extern void *D_800B63AC;
extern u8 *D_800B6334;
extern VECTOR D_801981F4;
extern SVECTOR D_800B6574;
extern MATRIX D_801981D4;
extern VECTOR D_801CA274;
extern s32 D_800B56AC;
extern MATRIX D_801FA428;
extern SVECTOR D_800B5A74;
extern s32 D_800B5CFC;
extern s32 D_800B642C;
extern s32 D_800B61CC;
extern void PushMatrix(void);
extern void PopMatrix(void);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX *MulMatrix2(MATRIX *m0, MATRIX *m1);
extern MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v);
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern s32 RotTransPers(SVECTOR *v0, s32 *sxy, s32 *p, s32 *flag);
extern MATRIX *func_8002C880(SVECTOR *r, MATRIX *m);
extern MATRIX *func_8002CA84(SVECTOR *r, MATRIX *m);
extern MATRIX *func_80084978(MATRIX *m, VECTOR *v);
extern void func_80038140(Unk80021854_Prim *p, s32 z);

s32 func_80021854(Unk80021854_Prim *p, VECTOR *pos, SVECTOR *ang) {
    s16 sxy[2];
    VECTOR scale = D_80086BD8;
    MATRIX m;
    SVECTOR rot;

    if (D_800B61A4->unk1A != 0) {
        return 0;
    }
    if ((u8 *)D_800B63AC - D_800B6334 > 0xD66FU) {
        return 0;
    }
    PushMatrix();
    D_800B6574.vx = pos->vx - D_801981F4.vx;
    D_800B6574.vy = pos->vy - D_801981F4.vy;
    D_800B6574.vz = pos->vz - D_801981F4.vz;
    ApplyMatrix(&D_801981D4, &D_800B6574, &D_801CA274);
    rot.vx = 0;
    rot.vz = 0;
    rot.vy = D_800B56AC * 500;
    func_8002C880(ang, &m);
    MulMatrix2(&D_801981D4, &m);
    func_8002CA84(&rot, &D_801FA428);
    MulMatrix2(&m, &D_801FA428);
    ScaleMatrix(&D_801FA428, &scale);
    SetRotMatrix(&D_801FA428);
    func_80084978(&D_801FA428, &D_801CA274);
    SetTransMatrix(&D_801FA428);
    D_800B61CC = RotTransPers(&D_800B5A74, (s32 *)sxy, &D_800B5CFC, &D_800B642C);
    if ((D_800B642C & ~0x1FFF) || D_800B61CC < 0x20 || D_800B61CC >= 0x1771 || sxy[0] < -0x50 || sxy[0] > 0x190 || sxy[1] < -0x50 || sxy[1] > 0x190) {
        PopMatrix();
        return -1;
    }
    p = (Unk80021854_Prim *)((u8 *)p + 8);
    while (p->unk14 != 0) {
        func_80038140(p, D_800B61CC >> 3);
        p++;
    }
    PopMatrix();
    return 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80021AFC);

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
} Unk80021FC4_Src;

typedef struct {
    u8 pad0[0x1C];
    SVECTOR rot;
    SVECTOR vel;
    u8 pad2C[0x46];
    s16 unk72;
} Unk80021FC4;

extern struct Task *D_801F80BC;
extern SVECTOR D_800B6124;
void func_80028310(SVECTOR *rot, SVECTOR *v, VECTOR *base, VECTOR *out);
s32 func_80028BF0(void *p);
s32 func_8002881C(s32 value, s32 target, s32 step);
void func_8002924C(VECTOR *from, VECTOR *to, SVECTOR *rot);
void func_800221C8(void);

void func_80021FC4(void) {
    Unk80021FC4_Src *src = (Unk80021FC4_Src *)D_801F80BC->vals;
    Unk80021FC4 *p = (Unk80021FC4 *)D_800B604C->vals;
    VECTOR v;

    v.vx = src->pos.vx;
    v.vy = src->pos.vy;
    v.vz = src->pos.vz;
    func_80028310(&p->rot, &p->vel, &v, &D_801981F4);
    p->vel.vz -= D_800B56A2 * 16;
    p->rot.vy += D_800B56A2 * 3;
    D_801981F4.vy = (s16)func_80028BF0(&D_801981F4) + p->unk72;
    p->unk72 = func_8002881C(p->unk72, 0x200, D_800B56A2 * 10);
    func_8002924C(&v, &D_801981F4, &D_800B6124);
    func_800221C8();
    func_8001F86C();
}

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 pad22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 pad2A;
    struct Task *unk2C;
    u8 pad30[0x3A];
    s16 unk6A;
    s16 pad6C;
    s16 unk6E;
    s16 unk70;
    s16 unk72;
} Unk800220D0;

extern struct Task *D_801F80B0[];
extern struct Task *D_800B604C;
void func_80021FC4(void);

void func_800220D0(void) {
    Unk800220D0 *p = (Unk800220D0 *)D_801F80B0[0]->vals;

    D_801F80B0[0]->saved = D_801F80B0[0]->func;
    D_801F80B0[0]->func = func_80021FC4;
    p->unk6A = 0x20;
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk1E = func_80074910(0x1000);
    p->unk70 = 0;
    p->unk72 = 0x3FF;
    p->unk24 = 0;
    p->unk26 = 0;
    p->unk28 = -0x400;
    p->unk6E = 0x3C;
    p->unk2C = D_800B604C;
}

extern VECTOR D_801981F4;
extern SVECTOR D_800B5EAC;
extern SVECTOR D_800B6124;
void func_800221C8(void);

void func_80022160(void) {
    D_801981F4.vx = 0;
    D_801981F4.vy = 0;
    D_801981F4.vz = 0;
    D_800B5EAC.vx = 0;
    D_800B5EAC.vy = 0;
    D_800B5EAC.vz = 0;
    D_800B6124.vx = 0;
    D_800B6124.vy = 0;
    D_800B6124.vz = 0;
    func_800221C8();
}

extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern SVECTOR D_800B6124;
extern VECTOR D_801981F4;
extern SVECTOR D_800B6574;
extern MATRIX D_801981D4;
extern VECTOR D_801CA274;
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern MATRIX *func_8002CA84(SVECTOR *r, MATRIX *m);
extern MATRIX *func_80084978(MATRIX *m, VECTOR *v);

void func_800221C8(void) {
    u8 unused[32];

    D_800B6574.vx = -D_801981F4.vx;
    D_800B6574.vy = -D_801981F4.vy;
    D_800B6574.vz = -D_801981F4.vz;
    func_8002CA84(&D_800B6124, &D_801981D4);
    ApplyMatrix(&D_801981D4, &D_800B6574, &D_801CA274);
    func_80084978(&D_801981D4, &D_801CA274);
    SetRotMatrix(&D_801981D4);
    SetTransMatrix(&D_801981D4);
}

extern SVECTOR D_800B5EAC;
extern void func_80028028(MATRIX *m);

void func_8002228C(void) {
    u8 unused[32];

    D_800B6574.vx = -D_800B5EAC.vx;
    D_800B6574.vy = -D_800B5EAC.vy;
    D_800B6574.vz = -D_800B5EAC.vz;
    func_8002CA84(&D_800B6124, &D_801981D4);
    ApplyMatrix(&D_801981D4, &D_800B6574, &D_801CA274);
    func_80084978(&D_801981D4, &D_801CA274);
    func_80028028(&D_801981D4);
    SetRotMatrix(&D_801981D4);
    SetTransMatrix(&D_801981D4);
}

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
    u8 pad20[2];
    u16 unk22;
    u8 pad24[0x2C];
    VECTOR unk50;
    u8 pad60[0x44];
    s16 unkA4;
    s16 padA6;
    s16 unkA8;
    u8 padAA[0x4A];
    s32 unkF4[4];
    u8 pad104[0x70];
    s16 unk174;
    s16 unk176;
    u8 pad178[0x1E];
    s16 unk196;
    u8 pad198[0x12];
    s16 unk1AA;
} Unk800B659C;

extern Unk800B659C *D_800B659C;
void func_80023310(void);

void func_80022360(void) {
    VECTOR *pos = (VECTOR *)D_801F80B0[0]->vals;

    if ((D_800B604C->unk14 += D_800B56A2) >= 0x79) {
        D_801F80B0[0]->func = func_80023310;
    } else {
        func_8002924C(&D_800B659C->pos, pos, &D_800B6124);
        D_801981F4.vx = pos->vx;
        D_801981F4.vy = pos->vy;
        D_801981F4.vz = pos->vz;
        func_800221C8();
        func_8001F86C();
        D_800B659C->unk196 = -1;
    }
    if (func_80028A48(&D_800B659C->pos, &D_801981F4) < 0x100) {
        D_800B604C->unk14 = 200;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002246C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800224B4);

typedef struct {
    u8 pad0[0x196];
    s16 unk196;
} Unk80022604_Obj;

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
} Unk80022604;

extern struct Task *volatile D_801F810C;
extern struct Task *D_801F80BC;

void func_80022604(void) {
    SVECTOR rot;
    VECTOR v;
    Unk80022604 *p;

    if (D_801F810C != NULL) {
        p = (Unk80022604 *)D_801F810C->vals;
        D_801981F4.vy = p->pos.vy + 0x200;
        D_801981F4.vx = p->pos.vx + 0x100;
        D_801981F4.vz = p->pos.vz - 0x800;
        func_8002924C(&p->pos, &D_801981F4, &D_800B6124);
    }
    if (D_801F80BC != NULL) {
        ((Unk80022604_Obj *)D_801F80BC->vals)->unk196 = -1;
    }
    func_800221C8();
    func_8001F86C();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800226B4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002276C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800229C4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80022B38);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80022C50);

extern Unk800B61A4 *D_800B61A4;

void func_800231A8(void) {
    Unk800B61A4 *p = D_800B61A4;
    s16 max = 8;

    p->unk0++;
    if (p->unkC != 0) {
        max = 9;
    }
    if (p->unk0 == max) {
        p->unk0 = 5;
    }
}

typedef struct {
    u8 maps[8][0x2F0];
    s16 unk1780;
    u8 pad1782[2];
    s16 unk1784;
    s16 unk1786;
    u8 pad1788[2];
    s16 unk178A;
    s16 unk178C;
    s16 unk178E;
} Unk800B6614;

extern Unk800B6614 *D_800B6614;

typedef struct {
    s32 unk0;
    u8 pad4[0x14];
    void (*unk18)();
    u8 pad1C[0x4A];
    s16 unk66;
    u8 pad68[0x16];
    s16 unk7E;
} Unk800231EC;

extern s32 D_801F80E4;
extern char *D_800915D0[];
extern u8 D_800B56D4[];
extern u16 D_800972FC;
extern s32 D_800B64FC[];

void func_800231EC(void) {
    Unk800231EC *p = (Unk800231EC *)D_800B604C->vals;
    s16 y;

    if (D_801F80E4 != 0) {
        if (p->unk7E != 0) {
            p->unk7E--;
            y = 0xE6;
            if (D_800B6614->unk178A != 0) {
                y = 0xD0;
            }
            func_800758C0(0xF0, y, func_80077DC8(D_800915D0[D_800B61A4->unk0]), 0x708, 0x320, D_800B56D4, D_800B56D4);
        }
        if (D_800972FC & ((volatile s32 *)D_800B64FC)[0]) {
            func_800231A8();
            p->unk7E = 30;
            p->unk0 += 5000;
        }
        p->unk66++;
        p->unk18();
    }
}

typedef struct {
    u8 pad0[0x18];
    void (*unk18)(void);
    u8 pad1C[0x4A];
    s16 unk66;
    u8 pad68[0xE];
    s16 unk76;
    u8 pad78[8];
    s16 unk80;
    s16 unk82;
    s16 unk84;
} Unk80023310;

extern struct Task *D_800B604C;
void func_80022C50(void);
void func_800231EC(void);
void func_800221C8(void);

void func_80023310(void) {
    Unk80023310 *d = (Unk80023310 *)D_800B604C->vals;

    d->unk80 = 0;
    d->unk84 = 0;
    d->unk82 = 0;
    d->unk76 = 1;
    d->unk18 = func_80022C50;
    d->unk66 = 0;
    func_800231EC();
    func_800221C8();
    D_800B604C->func = func_800231EC;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80023374);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80023694);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002391C);

extern struct Task *D_801F80B0[];
extern s16 D_800B5D74;
extern s16 D_800B650C;
void func_80023310(void);
void func_8002B5A8(void);
void func_8005027C(void);

void func_80024088(void) {
    D_801F80B0[0]->func = func_80023310;
    D_801F80B0[3]->func = func_8002B5A8;
    D_800B659C->unk1AA = 0;
    if (D_800B5D74 == 0) {
        D_800B650C--;
        func_8005027C();
    }
}

extern s16 D_800B56AA;
s16 func_8004C998(void);
void func_80024088(void);
extern void func_800728A4(void);

void func_80024100(void) {
    if (func_8004C998() != 0 || D_800B56AA != 0) {
        func_80024088();
        func_800728A4();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80024150);

extern s32 D_800B64FC[];

s16 func_80024428(void) {
    return *(volatile s32 *)D_800B64FC;
}

typedef struct {
    u8 data[0x28];
} Unk8019990C_Poly;

typedef struct {
    u32 unk0;
    Unk8019990C_Poly polys[2000];
    u8 pad[0x1020];
} Unk80199908;

extern Unk80199908 D_80199908[2];

void func_80024444(void) {
    s16 i;
    s16 j;
    Unk8019990C_Poly *p;

    i = 1;
    do {
        j = 1999;
        do {
            p = &D_80199908[i].polys[j];
            SetPolyFT4(p);
            SetShadeTex(p, 1);
        } while (j--);
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80024504);

extern u32 *D_800B62CC;
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 w, h;
} TILE;

void func_80024504(void);

void func_800246B0(void) {
    TILE *t = D_800B63AC;

    t->x0 = 0xDF;
    t->y0 = 4;
    t->w = 0x52;
    t->h = 0x66;
    t->r0 = 0x80;
    t->g0 = 0;
    t->b0 = 0;
    SetTile(t);
    AddPrim(D_800B62CC, t);
    t++;
    D_800B63AC = t;
    func_80024504();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80024730);

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[8];
} Unk800B5F34;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x6C];
} Unk801FA65C;

extern s16 D_800B6694;
extern s16 D_800B5E5C;
extern s16 D_800B5E64;
extern Unk800B5F34 *D_800B5F34;
extern Unk801FA65C D_801FA65C[];
void func_80072E40(void);

void func_80024A84(void) {
    s16 i = D_800B6694 + 1;
    s16 a;
    s16 b;

    if (D_800B5F34[i].unk0 == -1) {
        i = 0;
    }
    a = D_801FA65C[D_800B5F34[i].unk2].unk0;
    D_800B5E5C = a >> 1;
    b = D_801FA65C[D_800B5F34[i].unk2].unk2;
    D_800B5E64 = b >> 1;
    func_80072E40();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80024B5C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80025158);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80025460);

extern s16 D_800B5D0C;
extern s16 D_800B5D5C;
extern s16 D_800B5FB4;
extern s16 D_800B62F4;
extern s16 D_800B5728;
extern s16 D_800B6504;
void func_80065A84(void);
void func_80024B5C(void);
void func_80068DFC(void);
void func_80070EBC(void);
void func_8004FFE4(s16 a);
void func_80025158(void);

void func_80025764(void) {
    func_8005D33C();
    DrawSync(0);
    VSync(0);
    func_80024B5C();
    D_800B56A2 = 1;
    func_80068DFC();
    if (D_800B5D0C == 9) {
        func_800258A4();
        return;
    }
    if (D_800B5D5C == 6 && D_800B5FB4 == 0) {
        D_800B62F4 = 0;
        DrawSync(0);
        VSync(0);
        func_8001F39C();
        D_800B5728 = 0;
        func_80026158();
        func_80072374(func_80065A84, 0x58);
        if (D_800B5D0C == 2) {
            func_80070D34();
            func_80070DC4();
            D_800B604C->func = func_80070EBC;
        } else {
            func_8004FFE4(D_800B6504);
            func_8001F39C();
            D_800B604C->func = func_80025158;
        }
    }
}

extern s16 D_800B5D0C;
extern s16 D_800B5FB4;
extern s16 D_800B5D4C;
extern s16 D_800B658C;
void func_80053B1C(void);
void func_8002593C(void);

void func_800258A4(void) {
    D_800B604C->unk14 = 0;
    if (D_800B658C == 0) {
        func_80053B1C();
        D_800B5D4C = 1;
        D_800B5FB4 = 0;
        D_800B5D0C = 2;
        func_80026710(2);
        DrawSync(0);
        func_8001F444();
        StopPAD();
        func_80072A40(1);
        func_80073158();
    }
    D_800B604C->func = func_8002593C;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002593C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80025A98);

extern s16 D_800B5D5C;
extern s16 D_800B5D4C;
void func_80025A98(void);

void func_80025B54(void) {
    if (D_800B5D5C == 6) {
        D_800B5D4C = 1;
        D_800B604C->func = func_80025A98;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80025B8C);

extern s16 D_800B6504;
extern s16 D_800B5D5C;
extern s16 D_800B5CD8;
extern s16 D_800B5EA4;
extern s16 D_800B5728;
extern s16 D_800B66DC;
void func_80025E50(void);
void func_80025B8C(void);
void func_8005CF28(void);

void func_80025DA0(void) {
    D_800B5D5C = 7;
    D_800B5CD8 = 0;
    D_800B5EA4 = 0;
    D_800B5728 = -1;
    D_800B66DC = D_800B6504;
    func_80025E50();
    func_80072374(func_8005CF28, 0x10);
    D_800B604C->func = func_80025B8C;
}

void func_8005CF28(void);
void func_80025B54(void);
struct Task *func_80072374(void (*fn)(), s16 size);

void func_80025E18(void) {
    func_80072374(func_8005CF28, 0x10);
    D_800B604C->func = func_80025B54;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80025E50);

void func_80065C54(void);
void func_80025764(void);
void func_80025158(void);

void func_80026158(void) {
    func_80025E50();
    if (D_800B6504 != D_800B66DC) {
        D_800B66DC = D_800B6504;
        D_800B5D5C = 7;
        func_80072374(func_8005CF28, 0x10)->flags = 0;
        func_80072374(func_80065C54, 1000);
        D_800B604C->func = func_80025764;
    } else if (D_800B5FB4 == 2) {
        func_80072374(func_80065C54, 1000);
        D_800B604C->func = func_80025764;
    } else {
        D_800B604C->func = func_80025158;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026230);

extern s16 D_800B624C;
int SetDispMask(int mask);

void func_800266C8(void) {
    if (D_800B624C != 0 && --D_800B624C <= 0) {
        SetDispMask(1);
    }
}

extern s16 D_800B624C;
int SetDispMask(int mask);

void func_80026710(s32 mask) {
    VSync(0);
    SetDispMask(0);
    D_800B624C = mask;
}

s32 func_80026748(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

s32 func_80026764(s32 a, s32 b) {
    if (b < a) {
        return a;
    }
    return b;
}

s32 func_80026780(s32 a, s32 b) {
    return (a - b) << 20 >> 20;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026790);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026908);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026A74);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026BDC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80026D44);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Unk800272A0Pos;

typedef struct {
    u8 pad0[0x22];
    s16 unk22;
    u8 pad24[0x2C];
    Unk800272A0Pos unk50;
    u8 pad5C[0x1A8];
    Unk800272A0Pos unk204;
    u8 pad210[4];
    s16 unk214;
} Unk800272A0;

void func_800272A0(Unk800272A0 *p) {
    if (p == (Unk800272A0 *)D_800B659C) {
        p->unk50.x = p->unk204.x;
        p->unk50.y = p->unk204.y;
        p->unk50.z = p->unk204.z;
        p->unk22 = p->unk214;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800272DC);

typedef struct {
    s32 x, y, z, pad;
} Unk80027744_Vec;

typedef struct {
    u8 pad0[0x50];
    s32 unk50, unk54, unk58;
    s32 pad5C[2];
    Unk80027744_Vec unk64[4];
    s32 padA4[4];
    Unk80027744_Vec unkB4[4];
    u8 padF4[0x1B4 - 0xF4];
    s32 unk1B4, unk1B8, unk1BC;
} Unk80027744;

void func_80027744(Unk80027744 *p) {
    s32 i;

    for (i = 3; i != -1; i--) {
        p->unkB4[i].x = p->unk64[i].x;
        p->unkB4[i].y = p->unk64[i].y;
        p->unkB4[i].z = p->unk64[i].z;
    }
    p->unk1B4 = p->unk50;
    p->unk1B8 = p->unk54;
    p->unk1BC = p->unk58;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80027794);

extern s16 D_800B636C;
extern s16 D_800B645C;

void func_800279E4(s16 arg0) {
    D_800B636C = arg0;
    if (D_800B6614->unk178A == 0) {
        D_800B645C = 0x100;
    } else {
        D_800B645C = 0xF0;
    }
}

extern int func_80071B7C(s32 a, s32 b, s32 t);

void func_80027A18(u8 *a, u8 *b, s16 t, u8 *out) {
    out[0] = func_80071B7C(a[0], b[0], t);
    out[1] = func_80071B7C(a[1], b[1], t);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80027A88);

s32 func_80027C84(void) {
    return GetRCnt(0xF2000001) > 0x400;
}

typedef struct {
    SVECTOR *v[4];
} Unk8004D4A0;

void func_80027CAC(Unk8004D4A0 *f, SVECTOR *out) {
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

extern s32 SquareRoot0(s32);

void func_80027E5C(SVECTOR *v) {
    s16 x = v->vx;
    s16 y = v->vy;
    s16 z = v->vz;
    s32 len = SquareRoot0(x * x + y * y + z * z);

    if (len != 0) {
        v->vx = (x << 12) / len;
        v->vy = (y << 12) / len;
        v->vz = (z << 12) / len;
    } else {
        v->vx = 0;
        v->vy = 0x1000;
        v->vz = 0;
    }
}

extern s32 *D_800B6464;

void func_80027F94(s32 *src, u32 size) {
    u32 n = (size + 15) >> 4;
    s32 *dst = D_800B6464;

    while (n-- != 0) {
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
    }
    D_800B6464 = (s32 *)func_8002826C((s32)dst);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80028028);

s32 func_80028220(s32 a, s32 b) {
    if (b < a) {
        return b;
    }
    return a;
}

s16 func_8002823C(s16 *v) {
    return 0xFFF - v[3] * 16;
}

s32 func_80028258(s32 base, s32 size) {
    return (base + size + 3) & ~3;
}

s32 func_8002826C(s32 size) {
    return (size + 3) & ~3;
}

extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX D_801FA428;
extern MATRIX *func_8002CCB4(SVECTOR *r, MATRIX *m);

void func_8002827C(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_8002CCB4(rot, &D_801FA428);
    ApplyMatrix(&D_801FA428, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

void func_80028310(SVECTOR *rot, SVECTOR *v, VECTOR *base, VECTOR *out) {
    VECTOR tmp;

    func_8002CCB4(rot, &D_801FA428);
    ApplyMatrix(&D_801FA428, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern MATRIX *func_8002C880(SVECTOR *r, MATRIX *m);

void func_800283A4(SVECTOR *rot, SVECTOR *v, VECTOR *base, VECTOR *out) {
    VECTOR tmp;

    func_8002C880(rot, &D_801FA428);
    ApplyMatrix(&D_801FA428, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern MATRIX *func_8002CA84(SVECTOR *r, MATRIX *m);

void func_80028438(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_8002CA84(rot, &D_801FA428);
    ApplyMatrix(&D_801FA428, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern s32 SquareRoot0(s32 a);
extern s32 func_80028CEC(s32 x);
extern s16 D_8009AFF4[];

s16 func_800284CC(SVECTOR *a, SVECTOR *b) {
    s32 dx = a->vx - b->vx;
    s32 dz = a->vz - b->vz;
    s32 adx = func_80028CEC(dx);
    s32 adz = func_80028CEC(dz);
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
    if (s >= 0x400) {
        s = 0x3FF;
    }
    if (c >= 0x400) {
        c = 0x3FF;
    }
    if (s >= 0x2D5) {
        ang = 0x400 - D_8009AFF4[c];
    } else {
        ang = D_8009AFF4[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return 0x1000 - ang;
}

s32 func_80028648(VECTOR *a, VECTOR *b) {
    s32 dx = a->vx - b->vx;
    s32 dz = a->vz - b->vz;
    s32 adx = func_80028CEC(dx);
    s32 adz = func_80028CEC(dz);
    s32 dist;
    s32 s;
    s32 c;
    s32 ang;
    s32 t;
    s32 unused[2];

    if (adx > 0x8000 || adz > 0x8000) {
        adx >>= 8;
        adz >>= 8;
    }
    dist = (SquareRoot0((adx * adx + adz * adz) >> 4) + 2) << 2;
    if (dist < 2) {
        return 0;
    }
    s = (adx << 10) / dist;
    c = (adz << 10) / dist;
    if (c < 0) {
        c = 0;
    }
    if (s < 0) {
        s = 0;
    }
    if (s >= 0x2D5) {
        if (c >= 0x2D4) {
            t = D_8009AFF4[0x2D3];
        } else {
            t = D_8009AFF4[c];
        }
        ang = 0x400 - t;
    } else if (s >= 0x2D4) {
        ang = D_8009AFF4[0x2D3];
    } else {
        ang = D_8009AFF4[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return (s16)(0x1000 - ang);
}

s32 func_8002881C(s32 value, s32 target, s32 step) {
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

s32 func_80028868(s32 value, s32 target, s32 step) {
    s32 d = (value - target) << 20 >> 20;

    if (func_80028CEC(d) <= (s16)step) {
        return target & 0xFFF;
    }
    if (d < 0) {
        return (value + step) & 0xFFF;
    }
    return (value - step) & 0xFFF;
}

extern s32 SquareRoot0(s32 a);

s32 func_800288E0(SVECTOR *a, SVECTOR *b) {
    s32 dx = (a->vx - b->vx) >> 4;
    s32 dy = (a->vy - b->vy) >> 4;
    s32 dz = (a->vz - b->vz) >> 4;

    return SquareRoot0(dx * dx + dy * dy + dz * dz) << 4;
}

s32 func_8002895C(VECTOR *a, VECTOR *b) {
    s32 dx = (a->vx - b->vx) / 16;
    s32 dy = (a->vy - b->vy) / 16;
    s32 dz = (a->vz - b->vz) / 16;

    if (func_80028CEC(dx) > 0x4000) {
        return 0xFFFF;
    }
    if (func_80028CEC(dz) > 0x4000) {
        return 0xFFFF;
    }
    return SquareRoot0(dx * dx + dy * dy + dz * dz) * 16;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80028A48);

s32 func_80028AF8(SVECTOR *v) {
    return SquareRoot0(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
}

s32 func_80028B58(VECTOR *v) {
    return SquareRoot0(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
}

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7;
} Unk800B62C4;

extern Unk800B62C4 *D_800B62C4;

u8 func_80028BB8(VECTOR *v) {
    return D_800B62C4[((v->vx >> 12) & 0x3F) + ((v->vz >> 6) & 0x1FC0)].unk6;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80028BF0);

s32 func_80028CEC(s32 x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80028D04);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80028DC0);

s32 func_80028E80(VECTOR *p, VECTOR *a, VECTOR *b) {
    s32 dot;
    s32 len;

    dot = ((p->vz - b->vz) * (p->vz - a->vz) - (p->vx - b->vx) * (a->vx - p->vx) + 0x800) >> 12;
    len = ((p->vx - a->vx) * (p->vx - a->vx) + (p->vz - a->vz) * (p->vz - a->vz) + 0x800) >> 12;
    if (len + 0x800 < dot) {
        return -1;
    }
    if (dot < -0x800) {
        return -1;
    }
    return (dot << 12) / len;
}

s32 func_80028F4C(VECTOR *a, VECTOR *b, VECTOR *p) {
    s32 ax = a->vx;
    s32 az = a->vz;
    s32 bx = b->vx;
    s32 bz = b->vz;
    s32 dz = az - p->vz;
    s32 ux = bx - ax;
    s32 dx = ax - p->vx;
    s32 dist = func_80028CEC(dz * ux - dx * (bz - az)) >> 16;
    s32 vz = az - bz;
    s32 dot = (dz * vz - dx * ux + 0x800) >> 12;
    s32 vx = ax - bx;

    if (((vx * vx + vz * vz + 0x800) >> 12) + 0x800 < dot) {
        return -1;
    }
    if (dot < -0x800) {
        return -1;
    }
    return dist;
}

void func_80029060(s16 *a, s16 *b, s16 t, s16 *out) {
    out[0] = func_80071B7C(a[0], b[0], t);
    out[1] = func_80071B7C(a[1], b[1], t);
    out[2] = func_80071B7C(a[2], b[2], t);
}

void func_800290E4(VECTOR *a, VECTOR *b, s16 t, VECTOR *out) {
    out->vx = func_80071B7C(a->vx, b->vx, t);
    out->vy = func_80071B7C(a->vy, b->vy, t);
    out->vz = func_80071B7C(a->vz, b->vz, t);
}

typedef struct {
    VECTOR pos;
    u8 pad10[0x24];
    SVECTOR rot;
    u8 pad3C[0x138];
    SVECTOR drot;
    u8 pad17C[0x10];
    SVECTOR v;
} Unk80029168;

void func_80029168(Unk80029168 *obj) {
    obj->rot.vx += obj->drot.vx;
    obj->rot.vy += obj->drot.vy;
    obj->rot.vz += obj->drot.vz;
    func_80028310(&obj->rot, &obj->v, &obj->pos, &obj->pos);
}

extern SVECTOR D_800B5A74;
extern SVECTOR D_800B66BC;

void func_800291C4(SVECTOR *from, SVECTOR *to, SVECTOR *out) {
    out->vy = -func_800284CC(from, to);
    D_800B66BC.vz = func_800767E0(from, to);
    D_800B66BC.vx = to->vy - from->vy;
    out->vx = func_800284CC(&D_800B5A74, &D_800B66BC) - 0x800;
    out->vz = 0;
}

extern VECTOR D_80091BA8;
extern VECTOR D_801F83D4;
s32 func_80028648(VECTOR *a, VECTOR *b);

void func_8002924C(VECTOR *from, VECTOR *to, SVECTOR *rot) {
    rot->vy = -func_80028648(from, to);
    D_801F83D4.vx = to->vy - from->vy;
    D_801F83D4.vz = func_80028A48(from, to);
    rot->vx = func_80028648(&D_80091BA8, &D_801F83D4) - 0x800;
    rot->vz = 0;
}

extern u8 D_801F6C20[];

void func_800292D8(void) {
    s16 i, j, t;

    i = 7;
    do {
        j = 0x3F;
        do {
            t = j - 20;
            if (t < 0) {
                t = 0;
            }
            t += i;
            if (t > 7) {
                t = 7;
            }
            D_801F6C20[i * 256 + j] = t + 0xC;
        } while (j--);
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80029364);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80029648);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80029854);

typedef struct {
    u8 r, g, b, cd;
} CVECTOR;

extern unsigned short D_801FADE0[16];
void SetFarColor(s32 r, s32 g, s32 b);
void DpqColor(CVECTOR *in, s32 p, CVECTOR *out);

void func_80029A7C(unsigned short *src, s16 depth, u8 r, u8 g, u8 b) {
    unsigned short *dst;
    unsigned short i;
    s32 semi;
    u16 stp;
    CVECTOR c;

    SetFarColor(r, g, b);
    dst = D_801FADE0;
    i = 0;
    semi = 0;
    do {
        stp = 0;
        if (*src == 0) {
            c.r = 0;
            c.g = 0;
            c.b = 0;
            src++;
        } else {
            if (semi) {
                stp = (i < 4) << 15;
            } else {
                stp = 0x8000;
            }
            c.r = (*src & 0x1F) << 3;
            c.g = ((*src >> 5) & 0x1F) << 3;
            c.b = ((*src >> 10) & 0x1F) << 3;
            src++;
            DpqColor(&c, depth, &c);
        }
        i++;
        *dst++ = stp | (((c.r >> 3) + ((c.g >> 3) << 5) + ((c.b >> 3) << 10)) & 0x7FFF);
    } while (i < 16);
}

extern unsigned short D_801FADE0[16];

void func_80029BB8(unsigned short *src) {
    unsigned short *dst = D_801FADE0;
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

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
    s16 x1, y1;
    u8 u1, v1;
    u16 tpage;
    s16 x2, y2;
    u8 u2, v2;
    u16 pad1;
    s16 x3, y3;
    u8 u3, v3;
    u16 pad2;
} POLY_FT4;

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
    u16 pad1;
    s32 xy3;
    u16 uv3;
    u16 pad2;
} Unk80030328_Prim;

typedef struct {
    u32 uv0;
    u32 uv1;
    u16 uv2;
    u16 uv3;
    u8 padC[0x1C];
} Unk8018CDD4;

extern Unk80030328_Prim *D_800B5E0C;
extern u8 D_8018CDD4[];
extern u32 *D_800B62CC;
void AddPrim(void *ot, void *p);

void func_80029C08(void) {
    POLY_FT4 *p;
    Unk8018CDD4 *t;
    s16 idx = 0x200;
    s16 y;
    s16 x;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            p = (POLY_FT4 *)D_800B5E0C;
            p->x0 = p->x2 = x * 17 + 16;
            p->x1 = p->x3 = x * 17 + 32;
            p->y0 = p->y1 = y * 17 + 16;
            p->y2 = p->y3 = y * 17 + 32;
            t = &((Unk8018CDD4 *)D_8018CDD4)[idx++];
            *(u32 *)&p->u0 = t->uv0;
            *(u32 *)&p->u1 = t->uv1;
            *(u16 *)&p->u2 = t->uv2;
            *(u16 *)&p->u3 = t->uv3;
            D_800B5E0C = (Unk80030328_Prim *)(p + 1);
            AddPrim(D_800B62CC + 5, p);
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80029D54);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80029F84);

typedef struct {
    u8 pad0[0x118];
    s16 unk118;
    u8 pad11A[0x46];
    s16 unk160;
} Unk8002A190;

void func_8002A190(Unk8002A190 *p, s16 n) {
    if (p->unk160 > 0x800) {
        p->unk118 += n * 25;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002A1D0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002A340);

typedef struct {
    u8 pad0[0x60];
    s16 unk60;
    u8 pad62[0x42];
    SVECTOR unkA4;
    s16 unkAC;
    s16 padAE;
    s16 unkB0;
    u8 padB2[0x62];
    s16 unk114;
    u8 pad116[0x5E];
    s16 unk174;
    s16 unk176;
    s16 unk178;
    s16 unk17A;
} Unk8002A81C;

s32 func_80028AF8(SVECTOR *v);
s32 func_8002881C(s32 value, s32 target, s32 step);

void func_8002A81C(void) {
    Unk8002A81C *p = (Unk8002A81C *)D_800B604C->vals;
    s32 h = func_80028AF8(&p->unkA4);

    p->unk174 += p->unk17A;
    p->unk176 += p->unk178;
    if (p->unk174 > 0x800) {
        p->unk174 = 0x800;
        p->unk17A = 0;
    }
    if (p->unk174 < -0x800) {
        p->unk174 = -0x800;
        p->unk17A = 0;
    }
    if (p->unk176 > 0x800) {
        p->unk176 = 0x800;
        p->unk178 = 0;
    }
    if (p->unk176 < -0x800) {
        p->unk176 = -0x800;
        p->unk178 = 0;
    }
    p->unk176 = func_8002881C(p->unk176, 0, 0x20);
    p->unk174 = func_8002881C(p->unk174, 0, 0x20);
    p->unkAC += p->unk176 >> 6;
    p->unkB0 += p->unk174 >> 6;
    if (p->unk178 < 0x200 && p->unk176 < 0) {
        p->unk178 += 0x10;
    }
    if (p->unk178 > -0x200 && p->unk176 > 0) {
        p->unk178 -= 0x10;
    }
    if (p->unk17A < 0x200 && p->unk174 < 0) {
        p->unk17A += 0x10;
    }
    if (p->unk17A > -0x200 && p->unk174 > 0) {
        p->unk17A -= 0x10;
    }
    if (p->unk17A > -0x200 && p->unk17A < 0x200) {
        p->unk17A -= p->unk114 * 3;
    }
    if (p->unk178 > -0x320 && p->unk178 < 0x200) {
        p->unk178 -= p->unk60 - h;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002AA48);

void func_8002AC8C(void) {
}

extern s16 D_800B56A2;
typedef struct {
    u8 pad0[0x1FE];
    s16 unk1FE;
    s16 unk200;
} Unk8002AC94;

extern s16 D_800B613C;
extern s16 D_800B5DE4;
extern s16 D_800B5DEC;

void func_8002AC94(Unk8002AC94 *p, s16 on) {
    if (D_800B613C == 7) {
        return;
    }
    if (on != 0) {
        p->unk1FE -= D_800B56A2;
        if (p->unk1FE < 0) {
            p->unk1FE = 0x10;
            if (p->unk200 != 0) {
                D_800B5DE4 = 1;
                D_800B5DEC = 0;
                p->unk200 = 0;
            } else {
                D_800B5DE4 = 0;
                D_800B5DEC = 1;
                p->unk200 = 1;
            }
            return;
        }
    }
    D_800B5DE4 = 0;
    D_800B5DEC = 0;
}

typedef struct {
    s32 x0;
    s32 z0;
    s32 x1;
    s32 z1;
} Unk8002AD34;

extern u16 D_800B6024;
extern u16 D_800B64C4;
extern Unk8002AD34 D_801F7724[];
extern Unk8002AD34 D_8018C780[];
extern s16 D_800B571A;
extern void func_8007633C(s32 x, s32 y, s32 value, s32 a3, s32 a4, u8 *a5, u8 *a6);
extern u8 D_800B56D4[];

s32 func_8002AD34(s32 x, s32 z) {
    s16 i;

    if (D_800B5D0C == 5) {
        return 0;
    }
    i = D_800B6024;
    while (i--) {
        if (D_801F7724[i].x0 < x && x < D_801F7724[i].x1 && D_801F7724[i].z0 < z && z < D_801F7724[i].z1) {
            if (D_800B571A != 0) {
                func_8007633C(0x122, 0x28, i, 0x7D0, 0x7D0, D_800B56D4, D_800B56D4);
            }
            return 1;
        }
    }
    i = D_800B64C4;
    while (i--) {
        if (D_8018C780[i].x0 < x && x < D_8018C780[i].x1 && D_8018C780[i].z0 < z && z < D_8018C780[i].z1) {
            if (D_800B571A != 0) {
                func_8007633C(0x122, 0x28, i, 0x7D0, 0x7D0, D_800B56D4, D_800B56D4);
            }
            return 2;
        }
    }
    return 0;
}

typedef struct {
    SVECTOR *v[3];
    u8 padC[6];
    u16 unk12;
    void (*unk14)(void);
    u8 pad18[4];
} Unk8002AF48_Face;

typedef struct {
    SVECTOR *verts;
    u16 nverts;
    u16 pad6;
    Unk8002AF48_Face faces[1];
} Unk8002AF48_Level;

extern u8 D_800B8730[];
void func_800391CC(void);

s16 func_8002AF48(s16 step) {
    Unk8002AF48_Face *f;
    SVECTOR *v;
    s16 n;
    s16 ret = 0;

    n = ((Unk8002AF48_Level *)D_800B8730)->nverts;
    v = ((Unk8002AF48_Level *)D_800B8730)->verts;
    while (n--) {
        v->vy = func_8002881C(v->vy, 0, step);
        if (v->vy > 0) {
            ret = -1;
        }
        v++;
    }
    for (f = ((Unk8002AF48_Level *)D_800B8730)->faces; f->unk14 != NULL; f++) {
        if (f->v[0]->vy == 0 && f->v[1]->vy == 0 && f->v[2]->vy == 0) {
            f->unk14 = func_800391CC;
        } else if ((f->unk12 & 0x3F) == 12) {
            f->unk14 = func_800391CC;
        } else if ((f->unk12 & 0x3F) == 13) {
            f->unk14 = func_800391CC;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002B08C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002B3BC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002B404);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002B5A8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002BFF4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002C118);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002C234);

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
    s16 unk20;
    s16 unk22;
    s16 unk24;
} Unk8002C58C;

extern u16 D_80097304[];
extern volatile s32 D_800B6224[];
extern u8 D_800B8730[];
extern s16 D_800B61F4;
s16 func_800210B8(void *a, VECTOR *pos, s16 *rot);
s16 func_800564EC(s16 id, void *p);
void func_80021AFC(void *p);

void func_8002C58C(void) {
    Unk8002C58C *p = (Unk8002C58C *)D_800B604C->vals;

    p->unk20 = 0;
    p->unk24 = 0;
    func_8002AC94((Unk8002AC94 *)p, (D_80097304[2] & D_800B6224[0]) || (D_80097304[0] & D_800B6224[0]));
    if (func_800210B8(D_800B8730, &p->pos, &p->unk20)) {
        func_800564EC(D_800B61F4, p);
    }
    func_80021AFC(p);
}

extern struct Task *D_801F80BC;

void func_8002C640(void) {
    s16 *d = (s16 *)D_801F80BC->vals;

    d[0xB0] = 0;
}

extern s16 D_80094174[];

MATRIX *func_8002C658(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    s16 cxsy, sxsy;

    cx = D_80094174[(-(u16)r->vx + 0x400) & 0xFFF];
    sy = D_80094174[-(u16)r->vy & 0xFFF];
    sx = D_80094174[-(u16)r->vx & 0xFFF];
    cxsy = (cx * sy) >> 12;
    sxsy = (sx * sy) >> 12;
    cy = D_80094174[(-(u16)r->vy + 0x400) & 0xFFF];
    cz = D_80094174[(-(u16)r->vz + 0x400) & 0xFFF];
    sz = D_80094174[-(u16)r->vz & 0xFFF];
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

MATRIX *func_8002C880(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    u16 ax, ay, az;
    s32 cxsy, cxcy, sxsy, sxcy;

    ax = r->vx;
    ay = r->vy;
    cx = D_80094174[(ax + 0x400) & 0xFFF];
    sy = D_80094174[ay & 0xFFF];
    cxsy = cx * sy;
    cy = D_80094174[(ay + 0x400) & 0xFFF];
    cxcy = cx * cy;
    sx = D_80094174[ax & 0xFFF];
    sxsy = sx * sy;
    sxcy = sx * cy;
    az = r->vz;
    cz = D_80094174[(az + 0x400) & 0xFFF];
    sz = D_80094174[az & 0xFFF];
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

MATRIX *func_8002CA84(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_80094174[ax & 0xFFF];
    sy = D_80094174[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_80094174[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_80094174[(az + 0x400) & 0xFFF];
    sz = D_80094174[az & 0xFFF];
    cx = D_80094174[(ax + 0x400) & 0xFFF];
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

MATRIX *func_8002CCB4(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, sy, sz;
    s32 cy, cz;
    u16 ax, ay, az;
    s32 cxsy, sxsy;

    ax = r->vx;
    ay = r->vy;
    cx = D_80094174[(ax + 0x400) & 0xFFF];
    sy = D_80094174[ay & 0xFFF];
    cxsy = cx * sy;
    sx = D_80094174[ax & 0xFFF];
    sxsy = sx * sy;
    az = r->vz;
    cy = D_80094174[(ay + 0x400) & 0xFFF];
    cz = D_80094174[(az + 0x400) & 0xFFF];
    sz = D_80094174[az & 0xFFF];
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

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk800B853C_Ent;

typedef struct {
    Unk800B853C_Ent *ent;
} Unk800B853C;

extern Unk800B853C D_800B853C;
extern s32 D_800B8528;

void func_8002CED0(void) {
    u16 *tbl = (u16 *)D_800B604C->vals;
    s16 i;
    Unk800B853C_Ent *e;
    s16 n;

    i = 0x7F;
    do {
        e = &D_800B853C.ent[tbl[i]];
        if (e->unk2 > 0x200) {
            e->unk2 -= 2;
        }
    } while (i--);
    n = func_80074910(0x80);
    tbl[n] = func_80074910(D_800B8528);
}

extern s32 D_800B8528;
void func_8002CED0(void);

void func_8002CF80(void) {
    s16 *d = (s16 *)D_800B604C->vals;
    s16 i = 0x7F;

    do {
        d[i] = func_80074910(D_800B8528);
    } while (i--);
    D_800B604C->func = func_8002CED0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002CFF8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002D190);

typedef struct {
    SVECTOR *v[4];
    u16 tex;
    u16 clut;
} Unk80030328_Face;

extern Unk80030328_Prim *D_800B5E0C;
extern s32 D_800B5CFC;
extern s32 D_800B642C;
extern s32 D_800B61CC;
extern u8 D_8018CDD4[];
extern s32 RotTransPers4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *flag);
extern void SetPolyFT4(void *p);
extern void SetShadeTex(void *p, s32 tge);
extern void SetSemiTrans(void *p, s32 abe);
extern void AddPrim(void *ot, void *p);
extern void *D_800B63AC;
extern u32 *D_800B62CC;

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
    u16 pad1;
} Unk800307C0_Prim;

extern s32 RotTransPers3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *flag);
extern void SetPolyFT3(void *p);

extern s32 RotNclip3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *otz, s32 *flag);

extern s32 RotNclip4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *otz, s32 *flag);

Unk80030328_Face *func_8002D358(u8 n, Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    while (n--) {
        if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
            prim = D_800B5E0C;
            tex = (u16 *)(D_8018CDD4 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
            *(s16 *)&prim->uv2 = tex[4];
            *(s16 *)&prim->uv3 = tex[5];
            prim->clut = tex[(f->clut >> 8) + 12];
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
        }
        f++;
    }
    return f;
}

Unk80030328_Face *func_8002D4A8(u8 n, Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    while (n--) {
        D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + 0x3FB, prim);
        f++;
    }
    return f;
}

void func_8002D5DC(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_8002D6F0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        prim->uv2 = tex[4];
        prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        D_800B61CC -= 0x40;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_8002D84C(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (!(D_800B642C & ~0x1FFF)) {
        D_800B61CC -= 0x40;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002D98C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002DA20);

void func_8002DC70(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[5];
        prim->tpage = tex[3];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_8002DD90(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[5];
        prim->tpage = tex[3];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_8002DEB0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    D_800B5E0C = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 12];
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002DFB4);

void func_8002E174(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FC, prim);
}

extern s16 D_800B5A7C;

void func_8002E26C(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + D_800B5A7C, prim);
    }
}

void func_8002E368(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B62CC + D_800B5A7C, prim++);
        D_800B63AC = prim;
    }
}

void func_8002E454(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FB, prim);
}

void func_8002E54C(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FC, prim);
}

void func_8002E644(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + 0x3FC, prim);
    }
}

void func_8002E750(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    prim++;
    AddPrim(D_800B62CC + 0x3FC, start);
    D_800B63AC = prim;
}

void func_8002E864(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FC, start);
        D_800B63AC = prim;
    }
}

void func_8002E988(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FB, start);
        D_800B63AC = prim;
    }
}

void func_8002EAAC(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FC, start);
        D_800B63AC = prim;
    }
}

void func_8002EBD0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    D_800B5E0C = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 12];
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
}

extern s32 D_800B56AC;
extern s32 D_800B64F4;
extern SVECTOR D_800B5A74;
extern VECTOR D_801F76D0;
extern VECTOR D_801F83D4;
extern s16 D_800B5710;
extern s16 D_800B5712;
extern s16 D_800B5714;
extern s16 D_800B5716;
extern void RotTrans(SVECTOR *v, VECTOR *out, s32 *flag);

void func_8002ECD4(void) {
    SVECTOR v;

    v.vx = 0;
    v.vy = -0x400;
    v.vz = 0;
    D_800B64F4 = D_800B56AC;
    RotTrans(&v, &D_801F76D0, &D_800B642C);
    RotTrans(&D_800B5A74, &D_801F83D4, &D_800B642C);
    D_800B5710 = D_801F76D0.vx - D_801F83D4.vx;
    D_800B5712 = D_801F76D0.vy - D_801F83D4.vy;
    D_800B5714 = -((D_801F76D0.vy - D_801F83D4.vy) * 400) >> 10;
    D_800B5716 = ((D_801F76D0.vx - D_801F83D4.vx) * 25U) >> 6;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002EDE4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002F038);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8002F748);

void func_8002F9B0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FB, prim);
}

void func_8002FAB0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FC, prim);
}

void func_8002FBA8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FC, prim);
}

void func_8002FCA8(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    prim++;
    AddPrim(D_800B62CC + 0x3FC, start);
    D_800B63AC = prim;
}

void func_8002FDBC(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FC, prim);
}

void func_8002FEB4(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FC, start);
        D_800B63AC = prim;
    }
}

void func_8002FFD8(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FC, start);
        D_800B63AC = prim;
    }
}

void func_800300FC(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + 0x3FB, start);
        D_800B63AC = prim;
    }
}

void func_80030220(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[5];
    prim->tpage = tex[3];
    prim->clut = tex[(f->clut >> 8) + 12];
    D_800B5E0C = prim + 1;
    AddPrim(D_800B62CC + 0x3FB, prim);
}

void func_80030328(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &q->xy0, &q->xy1, &q->xy3, &q->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    prim->uv2 = tex[4];
    prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT4(prim);
    SetShadeTex(prim, 1);
    SetSemiTrans(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

extern s32 RotNclip4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *otz, s32 *flag);

void func_80030464(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &q->xy0, &q->xy1, &q->xy3, &q->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        prim->uv2 = tex[4];
        prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT4(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_800305A8(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_800306B0(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_800307C0(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    SetSemiTrans(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_800308D4(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_800309F0(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_80030B00(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + ((D_800B61CC + 64) >> 3), prim++);
    D_800B63AC = prim;
}

void func_80030C0C(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &q->xy2, &q->xy3, &q->xy1, &q->xy0, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    prim->uv2 = tex[4];
    prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT4(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + ((D_800B61CC + 0x40) >> 3), prim++);
    D_800B63AC = prim;
}

void func_80030D40(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    if (RotNclip4(f->v[0], f->v[1], f->v[2], f->v[3], &q->xy2, &q->xy3, &q->xy1, &q->xy0, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        prim->uv2 = tex[4];
        prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT4(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_80030E78(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &q->xy2, &q->xy3, &q->xy1, &q->xy0, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    prim->uv2 = tex[4];
    prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT4(prim);
    SetShadeTex(prim, 1);
    SetSemiTrans(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80030FB4(Unk80030328_Face *f) {
    Unk80030328_Prim *prim = D_800B63AC;
    Unk80030328_Prim *q = D_800B5E0C;
    u16 *tex;

    if (RotNclip4(f->v[0], f->v[1], f->v[2], f->v[3], &q->xy2, &q->xy3, &q->xy1, &q->xy0, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        prim->uv2 = tex[4];
        prim->uv3 = tex[5];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT4(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_800310F8(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80031200(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_80031310(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    SetSemiTrans(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80031424(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 12];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
        D_800B63AC = prim;
    }
}

void func_80031540(void) {
}

extern s16 D_800B60CC;
extern s16 D_800B5696;
extern s16 D_800B5694;
extern s16 D_800BA1E8[];

void func_80031548(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex + D_800B60CC * 40);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_80031674(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex + D_800BA1E8[f->tex & 7]);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_800317A8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex + D_800B5694 * 40);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_800318D4(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex + D_800B5696 * 40);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        D_800B5E0C = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 12];
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80031A00);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80031D38);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80032070);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80032354);

extern u8 D_801F6C20[];

Unk80030328_Face *func_80032638(u8 n, Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    while (n--) {
        if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0 && D_800B61CC >= 0x21 && D_800B61CC < 0x1770 && !(D_800B642C & ~0x1FFF)) {
            prim = D_800B5E0C;
            tex = (u16 *)(D_8018CDD4 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
            *(s16 *)&prim->uv2 = tex[4];
            *(s16 *)&prim->uv3 = tex[5];
            prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
        }
        f++;
    }
    return f;
}

Unk80030328_Face *func_800327CC(u8 n, Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    while (n--) {
        D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
        if (D_800B61CC < 0x21 || D_800B61CC >= 0x1770 || (D_800B642C & ~0x1FFF)) {
            continue;
        }
        D_800B61CC += 0x12C;
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
        f++;
    }
    return f;
}

void func_8003295C(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0 && D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_80032AB8(void) {
}

void func_80032AC0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0 && D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[5];
        prim->tpage = tex[3];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_80032C28(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_80032D70(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C) + 0x12C;
    if (D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_80032EB8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C) + 0x12C;
    if (D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[5];
        prim->tpage = tex[3];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), prim);
    }
}

void func_8003300C(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0 && D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), start);
        D_800B63AC = prim;
    }
}

void func_80033190(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), start);
        D_800B63AC = prim;
    }
}

void func_80033300(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    Unk800307C0_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B6334 > 0xD7DFU) {
        return;
    }
    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C) + 0x12C;
    if (D_800B61CC >= 0x20 && D_800B61CC < 0x1771 && !(D_800B642C & ~0x1FFF)) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B62CC + (D_800B61CC >> 3), start);
        D_800B63AC = prim;
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u16 uv0;
    u16 clut;
    s16 x1, y1;
    u16 uv1;
    u16 tpage;
    s16 x2, y2;
    u16 uv2;
    u16 pad1;
} Unk80036008_Prim;

void func_800358C0(s32 *xy, VECTOR *v);
s16 func_8004ED7C(Unk80030328_Prim *p);
void func_80035540(POLY_FT4 *p, POLY_FT4 *q);

void func_80033470(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    D_800B61CC += 0x12C;
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

void func_800337E4(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

void func_80033B50(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[5];
    prim->tpage = tex[3];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    D_800B61CC += 0x12C;
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80033ECC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80034240);

extern u8 D_801F6C20[];

void func_80034414(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0) {
            D_800B61CC = 0;
        }
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    if (D_800B61CC < 0x20 || D_800B61CC > 0x1770 || (D_800B642C & ~0x1FFF)) {
        return;
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80034768(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B61CC, &D_800B642C) <= 0) {
        return;
    }
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0) {
            D_800B61CC = 0;
        }
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    if (D_800B61CC < 0x20 || D_800B61CC > 0x1770 || (D_800B642C & ~0x1FFF)) {
        return;
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80034AC8(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0) {
            D_800B61CC = 0;
        }
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    *(s16 *)&prim->uv2 = tex[4];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    D_800B61CC += 0x12C;
    if (D_800B61CC < 0x20 || D_800B61CC > 0x1770 || (D_800B642C & ~0x1FFF)) {
        return;
    }
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

s32 func_800857A8(s32 xy0, s32 xy1, s32 xy2);
s16 func_8004ED7C(Unk80030328_Prim *p);

void func_80034E24(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0) {
            D_800B61CC = 0;
        }
    }
    if (D_800B61CC < 0x20 || D_800B61CC > 0x1770 || (D_800B642C & ~0x1FFF)) {
        return;
    }
    if (func_800857A8(D_800B5E0C->xy0, D_800B5E0C->xy1, D_800B5E0C->xy3) <= 0) {
        return;
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[D_801F6C20[(D_800B61CC >> 7) + (f->clut & 0x700)]];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

s16 func_8004ED7C(Unk80030328_Prim *p);
void func_800358C0(s32 *xy, VECTOR *v);

void func_800351E8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[5];
    prim->tpage = tex[3];
    prim->clut = tex[(f->clut >> 8) + 12];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

void func_80035540(POLY_FT4 *p, POLY_FT4 *q) {
    *(u32 *)&q->u0 = *(u32 *)&p->u0;
    *(u32 *)&q->u1 = *(u32 *)&p->u1;
    *(u16 *)&q->u3 = *(u16 *)&p->u3;
    *(u32 *)&q->x0 = *(u32 *)&p->x0;
    *(u32 *)&q->x3 = *(u32 *)&p->x3;
    *(u32 *)&q->x1 = *(u32 *)&p->x2;
    q->x2 = p->x2 = (p->x0 + p->x1 + p->x2 + p->x3) >> 2;
    q->y2 = p->y2 = (p->y0 + p->y1 + p->y2 + p->y3) >> 2;
    *(u16 *)&q->u1 = *(u16 *)&p->u2;
    q->u2 = p->u2 = (p->u0 + p->u1 + p->u2 + p->u3) >> 2;
    q->v2 = p->v2 = (p->v0 + p->v1 + p->v2 + p->v3) >> 2;
}

void func_80035638(POLY_FT4 *p, POLY_FT4 *q) {
    *(u32 *)&q->u2 = *(u32 *)&p->u2;
    *(u32 *)&q->u3 = *(u32 *)&p->u3;
    q->clut = p->clut;
    q->tpage = p->tpage;
    *(u32 *)&q->x2 = *(u32 *)&p->x2;
    *(u32 *)&q->x3 = *(u32 *)&p->x3;
    q->x0 = p->x2 = (p->x0 + p->x2 + 1) >> 1;
    q->y0 = p->y2 = (p->y0 + p->y2 + 1) >> 1;
    q->x1 = p->x3 = (p->x1 + p->x3 + 1) >> 1;
    q->y1 = p->y3 = (p->y1 + p->y3 + 1) >> 1;
    q->u0 = p->u2 = (p->u0 + p->u2) >> 1;
    q->v0 = p->v2 = (p->v0 + p->v2) >> 1;
    q->u1 = p->u3 = (p->u1 + p->u3) >> 1;
    q->v1 = p->v3 = (p->v1 + p->v3) >> 1;
}

void func_80035774(POLY_FT4 *p, POLY_FT4 *q) {
    *(u32 *)&q->u1 = *(u32 *)&p->u1;
    *(u32 *)&q->u3 = *(u32 *)&p->u3;
    q->clut = p->clut;
    q->tpage = p->tpage;
    *(u32 *)&q->x1 = *(u32 *)&p->x1;
    *(u32 *)&q->x3 = *(u32 *)&p->x3;
    q->x0 = p->x1 = (p->x0 + p->x1 + 1) >> 1;
    q->y0 = p->y1 = (p->y0 + p->y1 + 1) >> 1;
    q->x2 = p->x3 = (p->x3 + p->x2 + 1) >> 1;
    q->y2 = p->y3 = (p->y3 + p->y2 + 1) >> 1;
    q->u0 = p->u1 = (p->u0 + p->u1 + 1) >> 1;
    q->v0 = p->v1 = (p->v0 + p->v1 + 1) >> 1;
    q->u2 = p->u3 = (p->u3 + p->u2 + 1) >> 1;
    q->v2 = p->v3 = (p->v3 + p->v2 + 1) >> 1;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800358C0);

void func_800359E4(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_80035CF0(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B61CC, &D_800B642C) <= 0) {
        return;
    }
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), prim++);
    D_800B63AC = prim;
}

void func_800358C0(s32 *xy, VECTOR *v);

void func_80036008(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + 0x3FB, prim++);
    D_800B63AC = prim;
}

void func_800362D4(Unk80030328_Face *f) {
    Unk80036008_Prim *prim = D_800B63AC;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u32)((u8 *)prim - D_800B6334) > 0xD7DF) {
        return;
    }
    RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_800358C0((s32 *)&prim->x0, &v2);
        func_800358C0((s32 *)&prim->x1, &v1);
        func_800358C0((s32 *)&prim->x2, &v0);
    } else {
        if (prim->y0 > 0x1FE) {
            prim->y0 = 0x1FE;
        }
        if (prim->y0 < -0x1F4) {
            prim->y0 = -0x1F4;
        }
        if (prim->y1 > 0x1FE) {
            prim->y1 = 0x1FE;
        }
        if (prim->y1 < -0x1F4) {
            prim->y1 = -0x1F4;
        }
        if (prim->y2 > 0x1FE) {
            prim->y2 = 0x1FE;
        }
        if (prim->y2 < -0x1F4) {
            prim->y2 = -0x1F4;
        }
        if (prim->x0 > 0x26C) {
            prim->x0 = 0x26C;
        }
        if (prim->x0 < -0x12C) {
            prim->x0 = -0x12C;
        }
        if (prim->x1 > 0x26C) {
            prim->x1 = 0x26C;
        }
        if (prim->x1 < -0x12C) {
            prim->x1 = -0x12C;
        }
        if (prim->x2 > 0x26C) {
            prim->x2 = 0x26C;
        }
        if (prim->x2 < -0x12C) {
            prim->x2 = -0x12C;
        }
    }
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 12];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B62CC + 0x3FC, prim++);
    D_800B63AC = prim;
}

void func_800358C0(s32 *xy, VECTOR *v);

void func_800365A0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    D_800B61CC = 0x1FD8;
    prim->clut = tex[(f->clut >> 8) + 12];
    func_80035540((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
}

void func_80036810(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    D_800B61CC = 0x1FE0;
    prim->clut = tex[(f->clut >> 8) + 12];
    func_80035540((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
}

void func_80036A80(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[5];
    prim->tpage = tex[3];
    D_800B61CC = 0x1FD8;
    prim->clut = tex[(f->clut >> 8) + 12];
    func_80035540((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
}

s16 func_8004ED7C(Unk80030328_Prim *p);

void func_80036CFC(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

void func_80037048(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[5];
    prim->tpage = tex[3];
    prim->clut = tex[(f->clut >> 8) + 12];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

s32 func_800857A8(s32 xy0, s32 xy1, s32 xy2);

void func_800373A0(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    if (func_800857A8(D_800B5E0C->xy0, D_800B5E0C->xy1, D_800B5E0C->xy3) <= 0) {
        return;
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

void func_80037714(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    D_800B61CC = 0x1FD8;
    prim->clut = tex[(f->clut >> 8) + 12];
    func_80035540((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
    AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
}

void func_80037984(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    Unk80036008_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B61CC = RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B642C);
        RotTrans(f->v[1], &v1, &D_800B642C);
        RotTrans(f->v[2], &v2, &D_800B642C);
        RotTrans(f->v[3], &v3, &D_800B642C);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_800358C0(&D_800B5E0C->xy0, &v3);
        func_800358C0(&D_800B5E0C->xy1, &v2);
        func_800358C0(&D_800B5E0C->xy3, &v1);
        func_800358C0(&D_800B5E0C->xy2, &v0);
        D_800B61CC = v0.vz >> 2;
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
    }
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 8);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    prim->clut = tex[(f->clut >> 8) + 12];
    switch (func_8004ED7C(prim)) {
    case 1:
        t = D_800B63AC;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B5E0C->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B5E0C->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B5E0C->uv2;
        *(s32 *)&t->x0 = D_800B5E0C->xy0;
        *(s32 *)&t->x1 = D_800B5E0C->xy1;
        *(s32 *)&t->x2 = D_800B5E0C->xy2;
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        if (D_800B61CC < 0x58) {
            D_800B61CC = 0x58;
        }
        AddPrim(D_800B62CC + (D_800B61CC >> 3), t++);
        D_800B63AC = t;
        break;
    case 0:
        func_80035540((POLY_FT4 *)D_800B5E0C, (POLY_FT4 *)(D_800B5E0C + 1));
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        AddPrim(D_800B62CC + (D_800B61CC >> 3), D_800B5E0C++);
        break;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80037CD0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80037E70);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80037FC8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80038140);

extern void func_80037CD0(Unk80030328_Face *f);

void func_800382A8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B642C);
    prim = D_800B5E0C;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    *(u32 *)&prim->uv0 = *(u32 *)tex;
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[5];
    if (D_800B642C & ~0x1FFF) {
        func_80037CD0(f);
    } else if (D_800B61CC > 0x40) {
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + ((D_800B61CC - 0x40) >> 3), prim);
    } else {
        D_800B5E0C = prim + 1;
        AddPrim(D_800B62CC + 3, prim);
    }
}

void func_800383E8(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy0, &D_800B5E0C->xy1, &D_800B5E0C->xy3, &D_800B5E0C->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        if (D_800B642C & ~0x1FFF) {
            func_80037CD0(f);
        } else if (D_800B61CC > 0x40) {
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + ((D_800B61CC - 0x40) >> 3), prim);
        } else {
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + 3, prim);
        }
    } else if (D_800B642C & ~0x1FFF) {
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&D_800B5E0C->uv0 = *(u32 *)tex;
        *(u32 *)&D_800B5E0C->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&D_800B5E0C->uv2 = tex[4];
        *(s16 *)&D_800B5E0C->uv3 = tex[5];
        func_80037CD0(f);
    }
}

void func_800385AC(Unk80030328_Face *f) {
    Unk80030328_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        prim = D_800B5E0C;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[5];
        if (D_800B642C & ~0x1FFF) {
            func_80037CD0(f);
        } else if (D_800B61CC > 0x40) {
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + ((D_800B61CC - 0x40) >> 3), prim);
        } else {
            D_800B5E0C = prim + 1;
            AddPrim(D_800B62CC + 3, prim);
        }
    } else if (D_800B642C & ~0x1FFF) {
        RotTransPers4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B5E0C->xy2, &D_800B5E0C->xy3, &D_800B5E0C->xy1, &D_800B5E0C->xy0, &D_800B5CFC, &D_800B642C);
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&D_800B5E0C->uv0 = *(u32 *)tex;
        *(u32 *)&D_800B5E0C->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&D_800B5E0C->uv2 = tex[4];
        *(s16 *)&D_800B5E0C->uv3 = tex[5];
        func_80037CD0(f);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800387C8);

extern s32 D_800B6014;
extern s32 D_800B601C;
extern s32 D_800B602C;
extern void func_80083C68(s32 *sz0, s32 *sz1, s32 *sz2);
extern void func_80037E70(Unk80030328_Face *f, Unk800307C0_Prim *prim);

void func_80038E58(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B642C);
    if (D_800B642C & ~0x1FFF) {
        func_80037E70(f, prim);
        return;
    }
    func_80083C68(&D_800B6014, &D_800B601C, &D_800B602C);
    D_800B61CC = (D_800B6014 + D_800B601C + D_800B602C) / 12;
    tex = (u16 *)(D_8018CDD4 + f->tex);
    *(u32 *)&prim->uv0 = *(u32 *)tex;
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    if (D_800B61CC > 0x40) {
        AddPrim(D_800B62CC + ((D_800B61CC - 0x40) >> 3), prim++);
    } else {
        AddPrim(D_800B62CC + 3, prim++);
    }
    D_800B63AC = prim;
}

void func_8003900C(Unk80030328_Face *f) {
    Unk800307C0_Prim *prim = D_800B63AC;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B5CFC, &D_800B61CC, &D_800B642C) > 0) {
        if (D_800B642C & ~0x1FFF) {
            func_80037E70(f, prim);
            return;
        }
        func_80083C68(&D_800B6014, &D_800B601C, &D_800B602C);
        D_800B61CC = (D_800B6014 + D_800B601C + D_800B602C) / 12;
        tex = (u16 *)(D_8018CDD4 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B61CC > 0x40) {
            AddPrim(D_800B62CC + ((D_800B61CC - 0x40) >> 3), prim++);
        } else {
            AddPrim(D_800B62CC + 3, prim++);
        }
        D_800B63AC = prim;
    }
}

void func_800391CC(void) {
}

void func_800391F4(void);

void func_800391D4(void) {
    func_800391F4();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800391F4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80039654);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800398E0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80039A78);

extern s16 D_800B640C;
typedef struct {
    u16 unk0;
    u8 pad2[0xA];
} Unk800936C4;

extern Unk800936C4 D_800936C4[];

void func_8003A130(void) {
    Unk800B6614 *p = D_800B6614;

    if (p->unk178E != 0) {
        D_800B640C = 0;
    } else {
        D_800B640C = p->maps[p->unk1780][0x18];
    }
    D_800B6504 = D_800936C4[D_800B640C].unk0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003A1C8);

extern s32 *D_800B6464;
extern s32 D_800BA780[];

void func_8003A428(void) {
    D_800B6464 = D_800BA780;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003A440);

void func_8003A660(s16 n, s32 *a) {
    s32 t;

    while (n-- != 0) {
        if (a[3] != -1) {
            t = a[0];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = a[3];
            a[3] = t;
        } else {
            t = a[0];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = t;
        }
    }
}

void func_8003A6D8(SVECTOR **v) {
    s16 mid = (v[0]->vy + v[1]->vy + v[2]->vy + v[3]->vy) >> 2;

    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_8003A660(1, (s32 *)v);
    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_8003A660(1, (s32 *)v);
    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_8003A660(1, (s32 *)v);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003A7D8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003AA90);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003ABF0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003AD48);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003B178);

typedef struct {
    VECTOR pos;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 pad16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 pad22;
    u8 *unk24;
    VECTOR unk28;
    VECTOR unk38;
    s16 unk48;
    s16 unk4A;
} Unk8003B40C;

extern VECTOR D_801F76D0;
void func_8003B178(void);
struct Task *func_80072768(struct Task *parent, void (*fn)(), s16 size);
s32 func_80074910(s32);

void func_8003B40C(s16 x, s16 z, u8 *obj) {
    struct Task *t;
    Unk8003B40C *p;

    D_801F76D0.vx = (x << 9) + 0x100;
    D_801F76D0.vz = (z << 9) + 0x100;
    t = func_80072768(D_801F80BC, func_8003B178, 0x4C);
    if (t != NULL) {
        obj[4] = 0;
        p = (Unk8003B40C *)t->vals;
        p->unk1E = func_80074910(100) + 50;
        p->unk20 = (s16)func_80074910(2) * 0x800;
        p->unk24 = obj;
        p->unk4A = 0;
        p->pos.vx = D_801F76D0.vx;
        p->pos.vz = D_801F76D0.vz;
        p->pos.vy = (s16)func_80028BF0(&p->pos);
        p->unk28.vx = p->pos.vx;
        p->unk28.vy = p->pos.vy;
        p->unk28.vz = p->pos.vz;
        p->unk38.vx = p->pos.vx;
        p->unk38.vy = p->pos.vy;
        p->unk38.vz = p->pos.vz;
        p->unk48 = 0;
        p->unk12 = 0;
        p->unk10 = 0;
        p->unk14 = 0;
        p->unk18 = 200;
        p->unk1A = 0;
        p->unk1C = func_80074910(0x40);
    }
}

void func_8003B540(s16 *angle, s16 *speed) {
    s16 i;

    for (i = 0; i < 16; i++) {
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
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003B5CC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003B978);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003BB68);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003C014);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003C214);

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
} Unk8003C5C0;

s32 func_80028A48(VECTOR *a, VECTOR *b);

s32 func_8003C5C0(Unk8003C5C0 *obj) {
    return -(func_80028A48(&D_800B659C->pos, &obj->pos) < 350);
}

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
    u8 pad20[0x83];
    u8 unkA3;
} Unk8003C5F0;

s32 func_80056B14(VECTOR *pos);

void func_8003C5F0(Unk8003C5F0 *obj) {
    if ((func_80056B14(&obj->pos) >> 12) == 15 && obj->unkA3 != 5) {
        obj->unkA3 = 5;
        obj->pos.vy -= 0x40;
    }
}

extern s16 D_800B64CC;
extern s16 D_800B6374;

void func_8003C648(void) {
    if ((s16)func_80074910(2)) {
        if (func_80074910(13) & 2) {
            D_800B64CC = func_80074910(2) + 0x30;
        } else {
            D_800B6374 = func_80074910(2) + 0x2E;
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003C6B8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003C838);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003CAF8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003CD1C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003CFE0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003D180);

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    s16 unkE;
    u8 pad10[0x18];
    s32 unk28;
    u8 pad2C[4];
    s32 unk30;
    u8 pad34[4];
    s16 unk38;
    u8 pad3A[2];
    s16 unk3C;
} Unk8003D55C;

void func_8003D55C(Unk8003D55C *p) {
    p->unk28 = 0x32000;
    p->unk30 = 0x32000;
    p->unk38 = 0;
    p->unk3C = 0;
    p->unkC = 0;
    p->unkE = 0;
}

typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[0x46];
    s16 unk6C;
    u8 pad6E[6];
    s16 unk74;
    u8 pad76[2];
    u8 anim[0x20];
    u8 pad98[0x18];
    s16 unkB0;
    s16 unkB2;
    s16 unkB4;
    s16 unkB6;
} Unk8003D580;

void func_8003D180();

void func_8003D580(void) {
    Unk8003D580 *p = (Unk8003D580 *)D_800B604C->vals;

    p->unk20 = 0;
    p->unk22 = func_80074910(0x1000) & 0xC00;
    p->unk24 = 0;
    p->unk6C = 20;
    p->unkB2 = 0;
    p->unkB6 = 0;
    if ((s16)func_80074910(0x24) <= 0) {
        p->unkB0 = func_80074910(10) + 1;
    } else {
        p->unkB0 = 0;
    }
    p->unk74 = 0;
    func_80048B74(p->anim);
    func_80048C14(p->anim, 4, 0, 0x54, 4);
    func_80048C14(p->anim, (s16)func_80074910(2) + 1, 0, 0x54, 4);
    func_8003D55C((Unk8003D55C *)p);
    p->unkB4 = func_80028BF0(&p->pos);
    D_800B604C->func = func_8003D180;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003D688);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003D7E4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003D9F8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003DC64);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003DFE0);

typedef struct {
    u8 pad0[0x10];
    VECTOR unk10;
    u8 pad20[2];
    u16 unk22;
    u8 pad24[0x2E];
    u16 unk52;
    u8 pad54[0x68];
    s16 unkBC;
} Unk8003E25C;

extern u16 D_80097304[];

s32 func_8003E25C(Unk8003E25C *p) {
    s32 a;
    s32 r;

    if (!(D_80097304[2] & D_800B6224[0]) && !(D_80097304[0] & D_800B6224[0])) {
        return 0;
    }
    if ((s16)func_80074910(5) != 0) {
        return 0;
    }
    if (func_80028A48(&p->unk10, &D_800B659C->pos) < 0x17D1) {
        a = func_80028648(&p->unk10, &D_800B659C->pos);
        r = D_800B659C->unk22;
        if (((a - r) << 20) < 0) {
            p->unk52 = r + 0x600;
        } else {
            p->unk52 = r - 0x600;
        }
        p->unkBC = ((p->unk22 - p->unk52) << 20) >> 20;
        return -1;
    }
    return 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003E35C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003E40C);

void func_8003E40C(void);

void func_8003E624(void) {
    func_80048C14((u8 *)D_800B604C->vals + 0x78, 0, 0, 0x78, 4);
    D_800B604C->func = func_8003E40C;
    func_8003E40C();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003E67C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003E92C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003EAA4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003EC04);

void func_8003EEE4(s16 a, s16 b, s16 c, s16 d, s16 e);
void func_8005DB00(s16 a, s16 b, u8 *c, s32 d, s16 e);

void func_8003EDDC(s16 a, s16 b, s16 c, s16 d, s16 e) {
    func_8003EEE4(a, b, 0, d, e);
    func_8005DB00(a, b, 0, (d << 8) | 0x11, e);
}

void func_8003EE60(s16 a, s16 b, s16 c, s16 d, s16 e) {
    func_8003EEE4(a, b, 0, d, e);
    func_8005DB00(a, b, 0, (d << 8) | 0x12, e);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003EEE4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003F0FC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003F254);

s32 func_80043704(void *obj);

void func_8003F428(void) {
    if (func_80043704(D_800B604C->vals) == 0) {
        func_800728A4();
    }
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
    u8 pad0[0x50];
    s16 unk50;
    s16 pad52;
    s16 unk54;
    u8 pad56[0xA];
    s32 unk60;
    s32 unk64;
    s32 unk68;
    u8 pad6C[4];
    SVECTOR unk70[32];
    SVECTOR unk170[32];
} Unk8003F464;

extern Unk8003BA6C_Task *func_800724C4(void (*fn)(), s16 flags, s16 size);
void func_8003F428(void);
void func_80043DCC();

void func_8003F464(VECTOR *pos) {
    Unk8003BA6C_Task *t;
    Unk8003F464 *p;

    t = func_800724C4(func_8003F428, 0x31, 0x2B4);
    if (t != NULL) {
        p = (Unk8003F464 *)t->data;
        p->unk50 = (D_800B659C->unkA4 >> 5) * 625 >> 9;
        p->unk54 = (D_800B659C->unkA8 >> 5) * 625 >> 9;
        func_80043DCC(p, t);
        p->unk60 = pos->vx;
        p->unk64 = pos->vy;
        p->unk68 = pos->vz;
    }
}

typedef struct {
    u8 pad0[0x1A0];
    s32 unk1A0;
} Unk8003F540;

void func_8004DCC4(s32 arg);
extern void func_800728A4(void);

void func_8003F540(void) {
    func_8004DCC4(((Unk8003F540 *)D_800B604C->vals)->unk1A0);
    func_800728A4();
}

extern s32 D_801CA298[];

void func_8003F57C(void) {
    s16 i = 3;

    do {
        D_801CA298[i] = 0;
    } while (i--);
}

s16 func_8003F5B0(void) {
    s16 n = 0;
    s16 i = 3;

    do {
        if (D_801CA298[i] != 0) {
            n++;
        }
    } while (i--);
    return n;
}

void func_8003F5F8(s32 v) {
    s16 i = 3;

    do {
        if (D_801CA298[i] == v) {
            D_801CA298[i] = 0;
            break;
        }
    } while (i--);
}

extern s32 D_801CA298[];
extern s16 D_800B6204[];

void func_8003F63C(s32 id, s16 val) {
    s16 i;

    i = 3;
    do {
        if (D_801CA298[i] == id) {
            return;
        }
    } while (i--);
    i = 3;
    do {
        if (D_801CA298[i] == 0) {
            D_801CA298[i] = id;
            D_800B6204[i] = val;
            return;
        }
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003F6CC);

extern s32 *D_800B6234;
s32 func_80028258(s32 base, s32 size);

void func_8003F7B4(void) {
    D_800B6464 = (s32 *)func_8002826C((s32)D_800B6464);
    D_800B5D3C = func_80071BB0(D_800B5E4C, 9);
    D_800B6544 = 0;
    D_800B62EC = D_800B6464;
    D_800B5D04 = func_80071BC8(D_800B5E4C, 9);
    D_800B6234 = D_800B6464;
    D_800B6464 = (s32 *)func_80028258((s32)D_800B6464, D_800B5D04);
    D_800B604C->saved = D_800B604C->func;
    D_800B604C->func = func_8004FF54;
}

typedef struct {
    s32 x;
    s32 z;
    s32 targetX;
    s32 targetZ;
} Unk800B8540;

extern Unk800B8540 *D_800B8540[];
extern s16 D_800B609C;
extern s16 D_800BA628[];
extern s32 *D_801F7540[];
extern s32 D_8018C990[];
s32 func_8003F6CC(Unk800B8540 *p, s32 *dst, s16 n);

void func_8003F868(void) {
    s32 cnt;
    s16 i;
    s16 k;

    D_800B609C = 0;
    i = ((s16 *)D_800B6234)[0] / 4;
    if (i == 0) {
        return;
    }
    i--;
    do {
        k = i << 2;
        D_800B8540[i] = (Unk800B8540 *)((s16 *)D_800B6234 + ((s16 *)D_800B6234)[k]);
        cnt = ((u16 *)D_800B6234)[k + 1];
        D_800BA628[i] = cnt;
        if ((u32)(cnt - 1) >= 0x200) {
            D_800B609C = -1;
            return;
        }
        D_801F7540[i] = D_800B6464;
        D_8018C990[i] = func_8003F6CC(D_800B8540[i], D_800B6464, D_800BA628[i]);
        D_800B6464 = (s32 *)func_80028258((s32)D_800B6464, D_800BA628[i] * 8);
    } while (i--);
}

typedef struct {
    u8 pad0[0x10];
    VECTOR unk10;
    s16 pad20;
    s16 unk22;
    u8 pad24[0x2C];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 pad5C[0xB8];
    s16 unk114;
    u8 pad116[0x38];
    u16 unk14E;
    u8 pad150[0xA];
    s16 unk15A;
    s16 unk15C;
    s16 unk15E;
    u8 pad160[0xA];
    s16 unk16A;
    s16 pad16C;
    s16 unk16E;
    u8 pad170[0x2E];
    s16 unk19E;
    u8 pad1A0[4];
    s16 unk1A4;
    s16 unk1A6;
    s16 unk1A8;
    u8 pad1AA[0x22];
    s16 unk1CC;
} Unk80040450;

extern VECTOR D_801F76D0;

void func_8003F9A0(Unk80040450 *p) {
    Unk800B8540 *e = D_800B8540[p->unk15A];

    p->unk15C = 1;
    p->unk50 = e->x << 5;
    p->unk58 = e->z << 5;
    p->unk10.vx = p->unk50 >> 5;
    p->unk10.vz = p->unk58 >> 5;
    p->unk54 = (s16)func_80028BF0(&p->unk10) << 5;
    p->unk10.vy = p->unk54 >> 5;
    D_801F76D0.vx = e->targetX;
    D_801F76D0.vz = e->targetZ;
    p->unk22 = func_80028648(&D_801F76D0, &p->unk10);
    p->unk15E = 0;
    p->unk16A = 0;
    p->unk16E = 0;
    p->unk19E = 0;
    p->unk1A4 = 0;
    p->unk1A6 = 0;
    p->unk1A8 = 0;
}

typedef struct {
    s32 x;
    s32 z;
} Unk8003FA90;

s32 func_80028648(VECTOR *a, VECTOR *b);
s32 func_80028868(s32 value, s32 target, s32 step);

s16 func_8003FA90(Unk80040450 *p) {
    Unk8003FA90 *tbl = (Unk8003FA90 *)D_800B8540[p->unk15A];
    s32 a;
    s32 d;
    s16 r;

    p->unk14E = 0;
    D_801F76D0.vx = tbl[p->unk15C].x;
    D_801F76D0.vz = tbl[p->unk15C].z;
    a = func_80028648(&D_801F76D0, &p->unk10);
    d = ((a - (u16)p->unk22 - p->unk114 * 2) << 20) >> 20;
    r = func_80028CEC(d);
    if (D_800B5D0C != 5) {
        p->unk22 = func_80028868(p->unk22, (s16)a, 0x40);
    } else if (r < 0x20) {
        p->unk114 = func_8002881C(p->unk114, 0, 0x20);
    } else if (d < 0) {
        p->unk114 = func_8002881C(p->unk114, -0x80, 0x10);
    } else {
        p->unk114 = func_8002881C(p->unk114, 0x80, 0x10);
    }
    return r;
}

extern s16 D_800B640C;
typedef struct {
    u8 pad0[0x10];
    VECTOR pos;
    u8 pad20[0x144];
    void (*unk164)(void);
    u8 pad168[0x34];
    s16 unk19C;
    u8 pad19E[0x28];
    s16 unk1C6;
} Unk8003FBDC;

void func_800597F8(void);
s32 func_80040450();

void func_8003FBDC(void) {
    Unk8003FBDC *p = (Unk8003FBDC *)D_800B604C->vals;

    func_800597F8();
    if (func_80028A48(&p->pos, &D_800B659C->pos) < 4000) {
        p->unk19C = func_80071B7C(4, 9, D_800B640C << 8);
        p->unk1C6 = 1;
        p->unk164 = func_80040450;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8003FC58);

s32 func_800401A8(s16 a, s16 b) {
    return a < 0x200 && b > 0x400;
}

extern u16 D_80097302;

void func_800401D0(void) {
    s16 *d = (s16 *)D_800B604C->vals;

    d[0xA7] = D_80097302;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800401F0);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Unk800B6234;

extern VECTOR D_801F76D0;
extern u16 D_80097300;
s16 func_8003FA90();

func_80040450(void) {
    Unk80040450 *p = (Unk80040450 *)D_800B604C->vals;
    s16 a = func_8003FA90(p);
    s32 d = func_80028A48(&p->unk10, &D_801F76D0);

    if ((s16)func_8003FC58(d, a)) {
        p->unk14E |= D_80097300;
    }
    if (d < 0x5E8) {
        p->unk15C++;
        p->unk15E = 0;
        p->unk1CC = 0;
        if (p->unk15C == ((Unk800B6234 *)D_800B6234)[p->unk15A].unk2) {
            p->unk15C = 2;
            p->unk16A = -1;
        }
    }
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087A40);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087AC8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087AE4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087AF4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087B04);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80087B08);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80090DD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80090E14);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091254);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800915FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009166C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091674);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800916E4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091708);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091738);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009178C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091798);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800917F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091800);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091814);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091844);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091850);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091860);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091870);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091880);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009188C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091898);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80040534);

void func_8004090C(Unk80040450 *p) {
    p->unk19E += p->unk1A4;
    if (p->unk19E > 0) {
        p->unk1A4 -= 10;
    } else {
        p->unk1A4 += 10;
    }
    p->unk19E = func_8002881C(p->unk19E, 0, 16);
    p->unk1A6 += p->unk1A8;
    if (p->unk1A6 > 0) {
        p->unk1A8 -= 8;
    } else {
        p->unk1A8 += 8;
    }
    p->unk1A6 = func_8002881C(p->unk1A6, 0, 10);
    if (p->unk1A6 > 300) {
        p->unk1A6 = 300;
    }
    if (p->unk1A6 < -300) {
        p->unk1A6 = -300;
    }
}

extern s16 D_800B5F4C;
extern volatile s16 D_800B61AC;
void func_800409F8(void) {
    s16 *d = (s16 *)D_800B604C->vals;

    d[0xEE] += D_800B56A2;
    if (d[0xEE] >= 0xB5) {
        if (D_800B66DC == 10) {
            D_800B5D0C = 0xB;
        } else {
            D_800B61AC = 0x32;
            D_800B5F4C = 10;
            D_801F80B0[0]->func = func_80023310;
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80040A8C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80041AE0);

typedef struct {
    u8 pad0[0x1A0];
    s32 unk1A0;
} Unk80041CD0;

void func_80041CD0(void) {
    func_8004DCC4(((Unk80041CD0 *)D_800B604C->vals)->unk1A0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80041D04);

void func_8004206C(void) {
    if ((s16)func_80074910(2)) {
        D_800B64CC = func_80074910(2) + 0x1C;
    } else {
        D_800B6374 = func_80074910(2) + 0x1E;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800420C8);

extern s32 D_801FAB28[];
extern s32 D_80092594;
extern s32 D_800924CC;
extern s32 D_80092530;
extern s32 D_800925F8;
extern s32 D_8009265C;
extern s32 D_800926C0;
extern s32 D_800B660C;
extern s32 D_800B5ED4;
extern s32 D_800B664C;
extern s32 D_800B5CE0;
extern s32 D_800B5F2C;
extern s32 D_800B6064;
extern s32 D_800B6624;
extern s32 D_800B6194;

void func_80042274(void) {
    D_80092594 = D_801FAB28[20];
    D_800924CC = D_801FAB28[21];
    D_80092530 = D_801FAB28[22];
    D_800925F8 = D_801FAB28[23];
    D_8009265C = D_801FAB28[20];
    D_800926C0 = D_801FAB28[21];
    D_800B660C = D_801FAB28[0];
    D_800B5ED4 = D_801FAB28[10];
    D_800B664C = D_801FAB28[45];
    D_800B5CE0 = D_801FAB28[40];
    D_800B5F2C = D_801FAB28[41];
    D_800B6064 = D_801FAB28[44];
    D_800B6624 = D_801FAB28[42];
    D_800B6194 = D_801FAB28[43];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004234C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    void *unk8;
} Unk80042538;

extern s16 D_800B6C50[];
void func_8004234C(void);

void func_80042538(void *data) {
    Unk80042538 *p = (Unk80042538 *)D_800B604C->vals;
    s16 i = 99;

    D_800B6464 = (s32 *)func_8002826C((s32)D_800B6464);
    p->unk8 = data;
    p->unk2 = 0;
    do {
        D_801FAB28[i] = 0;
        D_800B6C50[i] = func_80071BF8(p->unk8, i);
    } while (i--);
    D_800B604C->saved = D_800B604C->func;
    D_800B604C->func = func_8004234C;
}

typedef struct {
    u8 pad0[0x90];
    s32 unk90;
} Unk80042610;

void func_80042610(void) {
    func_8004DCC4(((Unk80042610 *)D_800B604C->vals)->unk90);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80042644);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80042D10);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80042F0C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80043560);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80043704);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80043AF4);

void func_80043DCC(Unk8003F464 *p) {
    s16 i = 31;

    do {
        p->unk70[i].vx = func_80074910(0x40) - 0x20;
        p->unk70[i].vz = func_80074910(0x40) - 0x20;
        p->unk70[i].vy = func_80074910(0x30) + 0x20;
        p->unk170[i].vx = p->unk50 + func_80074910(8) - 4;
        p->unk170[i].vz = p->unk54 + func_80074910(8) - 4;
        p->unk170[i].vx = p->unk50 + func_80074910(0x20) - 0x10;
        p->unk170[i].vz = p->unk54 + func_80074910(0x20) - 0x10;
        p->unk170[i].vy = func_80074910(0x1E) + 6;
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80043EBC);

typedef struct {
    u8 pad0[0x270];
    s32 unk270;
} Unk800441E4;

void func_800441E4(void) {
    func_8004DCC4(((Unk800441E4 *)D_800B604C->vals)->unk270);
}

typedef struct {
    u8 pad0[4];
    u8 unk4;
} Unk80044218Src;

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
    VECTOR unk10;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    s32 unk28;
    u8 pad2C[4];
    s32 unk30;
    u8 pad34[4];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 pad3E[0x22];
    VECTOR unk60;
    u8 pad70[0x200];
    Unk80044218Src *unk270;
} Unk80044218;

void func_80043EBC(void);

void func_80044218(s16 x, s16 z, Unk80044218Src *src) {
    struct Task *t;
    Unk80044218 *p;

    if (D_800B61A4->unk6 >= 0x400) {
        t = func_80072768(D_801F80BC, func_80043EBC, 0x2B4);
        if (t != NULL) {
            t->flags = 0x31;
            t->cleanup = func_800441E4;
            p = (Unk80044218 *)t->vals;
            p->unk270 = src;
            src->unk4 = 0;
            p->unk60.vx = p->unk10.vx = x << 9;
            p->unk60.vz = p->unk10.vz = z << 9;
            p->unk60.vy = p->unk10.vy = (s16)func_80028BF0(&p->unk10) + 0x80;
            p->unk22 = 0;
            p->unk20 = 0;
            p->unk24 = 0;
            p->unkE = 0;
            p->unk28 = 0x3C000;
            p->unk30 = 0x3C000;
            p->unk38 = 0;
            p->unk3A = 0;
            p->unk3C = 0;
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80044314);

typedef struct {
    u8 pad0[0x90];
    s32 unk90;
} Unk80044C04;

void func_80044C04(void) {
    func_8004DCC4(((Unk80044C04 *)D_800B604C->vals)->unk90);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80044C38);

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 padE[2];
    VECTOR pos;
    u8 pad20[0x78];
    s32 unk98;
} Unk80044DE8;

void func_80044DE8(void) {
    Unk80044DE8 *d = (Unk80044DE8 *)D_800B604C->vals;

    if (func_80028A48(&d->pos, &D_800B659C->pos) > d->unkC) {
        func_8004DCC4(d->unk98);
        func_800728A4();
    }
}

typedef struct {
    u8 pad0[0x98];
    s32 unk98;
} Unk80044E4C;

void func_80044E4C(void) {
    func_8004DCC4(((Unk80044E4C *)D_800B604C->vals)->unk98);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80044E80);

typedef struct {
    u8 pad0[4];
    u8 unk4;
} Unk800451B4Src;

typedef struct {
    u8 pad0[8];
    s16 unk8;
    s16 padA;
    s16 unkC;
    s16 unkE;
    VECTOR unk10;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 pad26;
    s32 unk28;
    s32 pad2C;
    s32 unk30;
    s32 pad34;
    s16 unk38;
    s16 pad3A;
    s16 unk3C;
    u8 pad3E[0x3A];
    VECTOR unk78;
    u8 pad88[0x10];
    Unk800451B4Src *unk98;
    u8 pad9C[0x16];
    s16 unkB2;
} Unk800451B4;

void func_80044E80(void);

void func_800451B4(s32 x, s32 z, s32 c, s16 d) {
    Unk800451B4Src *src = (Unk800451B4Src *)c;
    struct Task *t;
    Unk800451B4 *p;

    t = func_80072768(D_801F80BC, func_80044E80, 0xC4);
    if (t != NULL) {
        if (src != NULL) {
            src->unk4 = 0;
        }
        p = (Unk800451B4 *)t->vals;
        t->flags = 0x31;
        p->unk98 = src;
        p->unk10.vx = x;
        p->unk78.vx = x;
        p->unk10.vz = z;
        p->unk78.vz = z;
        p->unk78.vy = p->unk10.vy = (s16)func_80028BF0(&p->unk10) + 200;
        p->unk22 = func_80074910(0x1000);
        p->unk20 = 0;
        p->unk24 = 0;
        p->unk28 = 0x12C000;
        p->unk30 = 0x12C000;
        p->unk38 = 0;
        p->unk3C = 0;
        p->unk8 = d;
        p->unkC = 0;
        p->unkE = 1;
    }
}

void func_800451B4(s32 x, s32 z, s32 c, s16 d);

void func_800452A4(s16 x, s16 z, s32 c, s16 d) {
    func_800451B4((x << 9) | 0x100, (z << 9) | 0x100, c, d);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800452E0);

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    u8 padAA[0x138];
    s16 unk1E2;
} Unk80045358;

void func_80045358(void) {
    Unk80045358 *p = (Unk80045358 *)D_800B659C;
    s16 ax = ABS(p->unkA4);
    s16 az = ABS(p->unkA8);

    if (ax > az) {
        p->unkA8 = 0;
        if (p->unkA4 < 0) {
            p->unkA4 = -0x800;
            p->unk1E2 = 0x400;
        } else {
            p->unkA4 = 0x800;
            p->unk1E2 = 0xC00;
        }
    } else {
        p->unkA4 = 0;
        if (p->unkA8 < 0) {
            p->unkA8 = -0x800;
            p->unk1E2 = 0x800;
        } else {
            p->unkA8 = 0x800;
            p->unk1E2 = 0;
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80045410);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80045B60);

extern s16 D_800B622C;
typedef struct {
    u8 pad[0xF0];
    s16 unkF0;
} Unk80077300;

extern struct {
    u8 pad[0x1C];
    Unk80077300 *unk1C;
} *D_801F8100;

typedef struct {
    u8 *obj;
    s16 timer;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk80045B60;

extern VECTOR D_801984F0;
void func_80045B60(void);

void func_80045CB4(s16 x, s16 z, u8 *obj) {
    VECTOR v;
    struct Task *t;
    Unk80045B60 *p;

    if (D_800B622C != 0 && D_801F8100 == NULL) {
        v.vx = (x << 9) + 0x100;
        v.vz = (z << 9) + 0x100;
        if (func_80028A48(&v, &D_800B659C->pos) < 0x17D1) {
            if (func_80028A48(&D_800B659C->pos, &(&D_801984F0)[D_800B650C]) >= 0x2000) {
                t = func_80072374(func_80045B60, 0xC);
                if (t != NULL) {
                    p = (Unk80045B60 *)t->vals;
                    p->obj = obj;
                    p->timer = func_80074910(0x3C) + 0x78;
                    p->unk6 = 0;
                    p->unk8 = 0;
                    p->unkA = -1;
                    obj[4] = 0;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80045DAC);

void func_80045410(void);

void func_80046084(s16 x, s16 z, Unk800451B4Src *src, s16 type) {
    struct Task *t;
    Unk800451B4 *p;
    s16 kind = type;

    t = func_80072768(D_801F80BC, func_80045410, 0xC4);
    if (t != NULL) {
        if (src != NULL) {
            src->unk4 = 0;
        }
        t->flags = 0x31;
        p = (Unk800451B4 *)t->vals;
        p->unk98 = src;
        p->unk78.vx = p->unk10.vx = (x << 9) + 0x100;
        p->unk78.vz = p->unk10.vz = (z << 9) + 0x100;
        p->unk78.vy = p->unk10.vy = (s16)func_80028BF0(&p->unk10) + 200;
        p->unk22 = func_80074910(0x1000);
        p->unk20 = 0;
        p->unk24 = 0;
        p->unk28 = 0x12C000;
        p->unk30 = 0x12C000;
        p->unk38 = 0;
        p->unk3C = 0;
        if (type == 6 && D_800B5F4C == 9) {
            kind = 0;
        }
        p->unkB2 = kind >> 8;
        p->unk8 = kind & 0xFF;
        p->unkC = 0;
        p->unkE = 1;
    }
}

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    s16 unkC;
    s16 unkE;
    VECTOR pos;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    u8 unk28[0x10];
    s16 unk38;
    u8 pad3A[2];
    s16 unk3C;
    u8 pad3E[0x32];
    s16 unk70;
    u8 pad72[6];
    VECTOR start;
    s16 unk88;
    u8 pad8A[0xE];
    u8 *obj;
} Unk800462E4;

extern s16 D_800B61DC;
extern s16 D_800B6294;
void func_8005CC44(s16 x, s16 z, u8 *obj, s16 d);
void func_80045DAC(void);
struct Task *func_80072768(struct Task *parent, void (*fn)(), s16 size);

void func_800461D0(s16 x, s16 z, u8 *obj, s16 d) {
    struct Task *t;
    Unk800462E4 *p;

    if (D_800B61DC == 0) {
        if (D_800B5D74 != 0) {
            func_8005CC44(x, z, obj, d);
        } else if (D_800B650C == D_800B6294 + 1 && func_8003F5B0() == 0) {
            t = func_80072768(D_801F80BC, func_80045DAC, 0xC4);
            if (t != NULL) {
                obj[4] = 0;
                p = (Unk800462E4 *)t->vals;
                p->obj = obj;
                p->pos.vx = (x << 9) + 0x100;
                p->pos.vz = (z << 9) + 0x100;
                p->pos.vy = (s16)func_80028BF0(&p->pos) + 600;
            }
        }
    }
}

void func_80054D3C(void);
void func_800570A8();

void func_800462E4(void) {
    Unk800462E4 *p = (Unk800462E4 *)D_800B604C->vals;

    func_80056E84();
    if (func_800210B8((void *)D_801FAB28[p->unk8], &p->pos, &p->unk20) == 0) {
        if (func_80028A48(&p->pos, &D_801981F4) >= 0x2001) {
            if (p->unk70 >= 0x79) {
                func_8004DCC4((s32)p->obj);
                D_800B604C->func = func_80054D3C;
            }
            func_800564EC(0, p);
            return;
        }
    } else {
        p->unk70 = 0;
    }
    p->unk70 += D_800B56A2;
    if (func_800564EC(D_800B61F4, p)) {
        func_800570A8(p);
    }
}

struct Task *func_80072768(struct Task *parent, void (*fn)(), s16 size);

void func_800463F0(s16 x, s16 z, u8 *obj, s16 type) {
    s16 ang = ((type >> 8) << 9) + 0x400;
    struct Task *t = func_80072768(D_801F80BC, func_800462E4, 0xC4);
    Unk800462E4 *p;
    s32 y;

    if (t != NULL) {
        obj[4] = 0;
        t->flags = 0x21;
        p = (Unk800462E4 *)t->vals;
        p->obj = obj;
        p->start.vx = p->pos.vx = (x << 9) + 0x100;
        p->start.vz = p->pos.vz = (z << 9) + 0x100;
        y = (s16)func_80028BF0(&p->pos);
        p->unk8 = type & 0xFF;
        p->start.vy = p->pos.vy = y;
        p->unk22 = ang;
        p->unk20 = 0;
        p->unk24 = 0;
        p->unk38 = 0;
        p->unk3C = 0;
        p->unkC = 0;
        p->unkE = 4;
        func_8006B48C(p->unk8, p->unk28);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800464FC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004667C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004699C);

typedef struct {
    u8 pad0[0xD8];
    s32 unkD8;
} Unk80046CC8;

void func_80046CC8(void) {
    func_8004DCC4(((Unk80046CC8 *)D_800B604C->vals)->unkD8);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80046CFC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80046E98);

typedef struct {
    u8 pad0[0x80];
    SVECTOR unk80[16];
    s16 unk100[16];
    s16 unk120[16];
    s16 unk140[16];
} Unk800471C8;

void func_80046E98(void);

void func_800471C8(void) {
    struct Task *t = func_80072374(func_80046E98, 0x160);
    Unk800471C8 *p;
    s16 i;
    s16 r;

    if (t != NULL) {
        p = (Unk800471C8 *)t->vals;
        i = 15;
        do {
            r = func_80074910(0x1000);
            p->unk100[i] = func_80071B7C(1, 4, r);
            p->unk140[i] = func_80071B7C(6, 8, r);
            if ((s16)func_80074910(2) != 0) {
                p->unk100[i] = -p->unk100[i];
            }
            p->unk120[i] = func_80074910(6000) + 1500;
            p->unk80[i].vx = 0;
            p->unk80[i].vy = func_80074910(0x1000);
            p->unk80[i].vz = 0;
        } while (i--);
    }
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800918F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091908);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091918);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091924);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091930);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009193C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009194C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091958);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009196C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091978);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091988);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091994);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800919A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800919B8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800919C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800919DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800919F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A14);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A28);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A3C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A48);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A5C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A70);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A84);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091A90);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AA0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AB0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AC8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AD8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AE8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091AF8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B14);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B28);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B38);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B48);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B5C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B68);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B80);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B8C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091B98);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091BA8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091BB8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091BBC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091BC0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091BD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091CA8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091CAC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091CB0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091CB4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091DD8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091DE4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091DE8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E04);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E0C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E20);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E70);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091E98);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091F08);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80091FDC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800920A0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092164);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092238);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800922B8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092330);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800923A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800923C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800923E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800923E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800923F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092400);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092408);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092428);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092444);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092460);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092474);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092480);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092484);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800924CC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800924D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092530);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092594);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800925F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009265C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800926C0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800928CC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800928D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800928D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800929B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092B1C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092C88);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092DF4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80092F60);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093024);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093078);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009315C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800931FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093284);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009330C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009332C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093340);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093368);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093394);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800933B4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800933C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800933F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009341C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800934A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009352C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800935B4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009363C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800936C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800936C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800936CC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800936DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093784);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800937C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800937C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009386C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093894);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800938BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800938C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009390C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093918);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093950);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093960);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093970);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093990);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800939F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093A14);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093A24);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093B54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093BD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093C54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093CD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093CF4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093D34);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093DBC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093E44);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093ECC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093F54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80093FDC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80094064);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800940EC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80094174);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80096174);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800971D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800972D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800972F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800972F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800972FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80097300);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80097304);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80097308);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009730C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_80097314);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009731C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009AFF4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009B5BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DC7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DD9C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DE74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DE78);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DE7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DE80);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009DE9C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E020);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E024);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E028);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E02C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E030);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E034);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E038);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E03C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E040);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E044);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E048);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E04C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E050);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E054);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E058);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E05C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E060);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E064);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E074);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E078);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E07C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E080);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E084);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E088);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E08C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E090);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E098);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E09C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0A0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E0E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E4E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E4E4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E4E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E4EC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E4F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E540);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7EC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E7FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E800);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E804);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E808);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E80C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E810);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E814);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E818);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E898);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E89C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8AC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8B4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8B8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E8BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E93C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E95C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009E9DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EA5C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EADC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB40);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB5C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB60);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB64);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB68);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB6C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB70);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB78);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB90);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB94);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB98);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EB9C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBA0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBB4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBBC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBC0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBC4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBC8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBCC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBD0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBE4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EBFC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC78);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC8C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC90);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009EC94);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009ECC0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009ECC4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009ECCC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FCF8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD18);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD1C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD20);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD24);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD28);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD2C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD30);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD50);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD78);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD80);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD84);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD88);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FD8C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDCC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDD0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDD4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDD8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDDC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDE0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FDE4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE40);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE44);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE48);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE4C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE50);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE54);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE68);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE84);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE88);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE8C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FE90);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEA4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEA8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEAC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEB0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEB4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEB8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEBC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEC0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEC4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEC8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FECC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FED0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FED8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEDC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEE0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEE4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEE8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEEC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEF0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FEF4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FF00);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_8009FF04);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A0184);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A0204);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A0214);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A0394);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A4394);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A4398);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A43D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A4418);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A441C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A449C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44A0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44AC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44CC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A44D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800A4CD8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B4CD8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B54D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B54E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B54F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5500);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5508);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5510);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5518);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5520);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5528);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5530);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5538);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5540);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5548);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5550);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5568);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5570);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5578);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5580);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5588);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B558C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5590);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800472C4);

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80060200;
extern struct Task *D_800B604C;
extern void func_800472C4(void);

typedef struct {
    u8 pad0[0xA0];
    s16 unkA0;
} Unk80047CAC;

void func_80047CAC(void) {
    ((Unk80047CAC *)D_800B604C->vals)->unkA0 = 0;
    D_800B604C->func = func_800472C4;
}

typedef struct {
    u32 tag;
    u32 code;
    s32 xy0;
    s32 uv0;
    s32 xy1;
    s32 uv1;
    s32 xy2;
    s32 uv2;
    s32 xy3;
    s32 uv3;
} Unk80035974;

void func_80047CD4(s16 rot, Unk80035974 *p) {
    s32 xy[4];

    xy[0] = p->xy0;
    xy[1] = p->xy1;
    xy[3] = p->xy2;
    xy[2] = p->xy3;
    p->xy0 = xy[rot & 3];
    p->xy1 = xy[(rot + 1) & 3];
    p->xy3 = xy[(rot + 2) & 3];
    p->xy2 = xy[(rot + 3) & 3];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80047D78);

void func_80047FF8(SVECTOR *a, SVECTOR *b, SVECTOR *out) {
    out->vx = a->vx + b->vx;
    out->vy = a->vy + b->vy;
    out->vz = a->vz + b->vz;
}

typedef struct {
    int *p;
    int pad[3];
} Entry16;

extern Entry16 *D_800B66AC;

typedef struct {
    u8 pad[0x20];
    SVECTOR pt[8];
    u8 pad60[0x78];
} Unk80048038_Ent;

typedef struct {
    u8 pad[4];
    u16 count;
    u8 pad6[0x12];
    Unk80048038_Ent ent[1];
} Unk80048038_Obj;

void func_80048038(s16 id) {
    Unk80048038_Obj *obj = (Unk80048038_Obj *)D_800B66AC[id].p;
    SVECTOR d;
    s16 n = obj->count;

    while (n--) {
        SVECTOR *pt = obj->ent[n].pt;

        func_80029060((s16 *)&pt[0], (s16 *)&pt[1], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[0], (s16 *)&d, 0x200, (s16 *)&pt[0]);
        func_80029060((s16 *)&pt[1], (s16 *)&d, 0x200, (s16 *)&pt[1]);
        func_80029060((s16 *)&pt[2], (s16 *)&pt[3], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[2], (s16 *)&d, 0x200, (s16 *)&pt[2]);
        func_80029060((s16 *)&pt[4], (s16 *)&pt[5], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[4], (s16 *)&d, 0x200, (s16 *)&pt[4]);
        func_80029060((s16 *)&pt[5], (s16 *)&d, 0x200, (s16 *)&pt[5]);
        func_80029060((s16 *)&pt[6], (s16 *)&pt[7], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[6], (s16 *)&d, 0x200, (s16 *)&pt[6]);
        func_80029060((s16 *)&pt[0], (s16 *)&pt[4], 0x400, (s16 *)&d);
        d.vx = pt[0].vx - d.vx;
        d.vy = pt[0].vy - d.vy;
        d.vz = pt[0].vz - d.vz;
        func_80047FF8(&d, &pt[0], &pt[0]);
        func_80047FF8(&d, &pt[1], &pt[1]);
        func_80047FF8(&d, &pt[2], &pt[2]);
        func_80047FF8(&d, &pt[3], &pt[3]);
        d.vx = -d.vx;
        d.vy = -d.vy;
        d.vz = -d.vz;
        func_80047FF8(&d, &pt[4], &pt[4]);
        func_80047FF8(&d, &pt[5], &pt[5]);
        func_80047FF8(&d, &pt[6], &pt[6]);
        func_80047FF8(&d, &pt[7], &pt[7]);
        func_80029060((s16 *)&pt[2], (s16 *)&pt[3], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[2], (s16 *)&d, 0x400, (s16 *)&pt[2]);
        func_80029060((s16 *)&pt[3], (s16 *)&d, 0x400, (s16 *)&pt[3]);
        func_80029060((s16 *)&pt[6], (s16 *)&pt[7], 0x800, (s16 *)&d);
        func_80029060((s16 *)&pt[6], (s16 *)&d, 0x400, (s16 *)&pt[6]);
        func_80029060((s16 *)&pt[7], (s16 *)&d, 0x400, (s16 *)&pt[7]);
    }
}

typedef struct {
    s32 v0;
    s32 v1;
    s32 v2;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} Unk80048360;

extern s32 D_800B663C;

void func_80048360(Unk80048360 *f) {
    s16 i = 0;

    while (f[i].v0 != -1) {
        f[i].v0 = f[i].v0 * 8 + D_800B663C;
        f[i].v1 = f[i].v1 * 8 + D_800B663C;
        f[i].v2 = f[i].v2 * 8 + D_800B663C;
        f[i].unk12 = f[i].unk12 * 40;
        f[i].unk14 = f[i].unk14 * 40;
        f[i].unkC = f[i].unkC * 775 >> 10;
        f[i].unkE = f[i].unkE * 775 >> 10;
        f[i].unk10 = f[i].unk10 * 775 >> 10;
        f[i].unk16 = f[i].unk16;
        f[i].unk18 = f[i].unk18;
        f[i].unk1A = f[i].unk1A;
        i++;
    }
}

extern s16 D_800B60F4;
extern u8 D_801FA350[];
extern s32 D_801C1A34[];
extern Unk80048360 D_80092C88;
extern Unk80048360 D_80092B1C;
extern Unk80048360 D_80092DF4;
extern Unk80048360 D_80093078;
extern Unk80048360 D_80093024;
extern Unk80048360 D_80092F60;
extern Unk80048360 D_800929B0;
void func_800485EC();

void func_800484A4(void) {
    s32 n;
    Entry16 *e;
    s32 *base;

    if (D_800B60F4 == 0) {
        D_800B60F4 = -1;
        D_800B663C = func_8002826C((s32)D_801FA350);
        func_80048360(&D_80092C88);
        func_80048360(&D_80092B1C);
        func_80048360(&D_80092DF4);
        func_80048360(&D_80093078);
        func_80048360(&D_80093024);
        func_80048360(&D_80092F60);
        func_80048360(&D_800929B0);
        n = D_801C1A34[0];
        D_800B66AC = (Entry16 *)&D_801C1A34[1];
        base = D_801C1A34;
        while (n--) {
            e = D_800B66AC++;
            e->p = (int *)((s32)base + (s32)e->p);
        }
        D_800B66AC = (Entry16 *)&D_801C1A34[1];
        D_800B6544 = 0;
        D_800B62EC = (s32 *)D_801C1A34[0];
        D_800B604C->func = func_800485EC;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800485EC);

void func_800486B4(SVECTOR *pos, SVECTOR *vel, s32 count, s32 scale) {
    s32 unused;
    s32 i;

    for (i = 0; i < count; i++) {
        pos[i].vx += (vel[i].vx * scale) >> 12;
        pos[i].vy += (vel[i].vy * scale) >> 12;
        pos[i].vz += (vel[i].vz * scale) >> 12;
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
    u8 pad26[4];
    u8 unk2A;
} Unk80048748;

void func_80048748(Unk80048748 *src, Unk80048748 *dst) {
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
    dst->unk1E = src->unk1E;
    dst->unk20 = src->unk20;
    dst->unk22 = src->unk22;
    dst->unk24 = src->unk24;
    dst->unk2A = src->unk2A;
}

typedef struct {
    u8 pad0[0x1E];
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 pad28[3];
    u8 unk2B;
} Unk80048808;

void func_80048808(Unk80048808 *p) {
    p->unk2B = 0;
    p->unk1E = 0x4920;
    p->unk20 = 0x4A60;
    p->unk22 = 0x4948;
    p->unk24 = 0x4948;
    p->unk26 = 0;
}

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA;
    u8 padB;
} Unk800928CC;

extern Unk800928CC D_800928CC[];

void func_80048830(void *anim, s16 idx) {
    Unk80048808 *p = anim;

    idx %= 16;
    if (D_800B61A4->unk1A != 0) {
        func_80048808(p);
        return;
    }
    p->unk2B = D_800928CC[idx].unkA;
    p->unk1E = D_800928CC[idx].unk0 * 40;
    p->unk20 = D_800928CC[idx].unk2 * 40;
    p->unk22 = D_800928CC[idx].unk4 * 40;
    p->unk24 = D_800928CC[idx].unk6 * 40;
    p->unk26 = D_800928CC[idx].unk8 * 40;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004896C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    u8 pad18[2];
    s16 unk1A;
    u16 unk1C;
    u8 pad1E[0xA];
    s16 unk28;
    u8 unk2A;
} Unk80048B74;

void func_8004896C(Unk80048B74 *obj);

void func_80048B74(Unk80048B74 *obj) {
    obj->unk8 = 0;
    obj->unk10 = 0;
    obj->unk4 = 0;
    obj->unk14 = 0;
    obj->unk16 = 0;
    obj->unkC = 0;
    obj->unk1C = 0xFFFF;
    obj->unk28 = 3500;
    obj->unk1A = 0x1000;
    obj->unk0 = obj->unk2 = 0;
    obj->unk2A = 0x40;
    func_8004896C(obj);
}

s32 func_80074910(s32);

int func_80048BD0(int i) {
    return (s16)func_80074910(*D_800B66AC[(s16)i].p);
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

void func_80048C14(anim, id, time, arg3, blend)
Anim *anim;
s16 id;
s16 time;
s16 arg3;
s16 blend;
{
    if (anim->unk1C != 0) {
        blend = 0;
        anim->unk1C = 0;
    }
    anim->prevId = anim->id;
    anim->prevTime = anim->time;
    if (time != -1) {
        anim->time = time;
    }
    anim->time = anim->time / D_800B66AC[id].p[2] * D_800B66AC[id].p[2];
    anim->id = id;
    anim->unk6 = arg3;
    if (blend != 0) {
        anim->unk16 = 1;
        anim->unk1A = 0x1000 / blend;
    } else {
        anim->unk16 = 0;
    }
}

void func_80048D08(Anim *anim, s16 id, s16 time, s16 arg3, s16 blend) {
    if ((s16)anim->id != id) {
        func_80048C14(anim, id, time, arg3, blend);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80048D54);

s32 func_80048E50(s16 a, s16 b) {
    return (a + b - 0x100) >> 6;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80048E70);

typedef struct {
    u8 pad0[0x1C];
    SVECTOR rot;
    SVECTOR v;
    u8 pad2C[0x46];
    s16 unk72;
    u8 pad74[0x14];
    VECTOR base;
} Unk8004C828;

s32 func_80028BF0(void *p);

void func_8004C828(void) {
    VECTOR unused;
    Unk8004C828 *p = (Unk8004C828 *)D_800B604C->vals;

    func_80028310(&p->rot, &p->v, &p->base, &D_801981F4);
    p->rot.vy += D_800B56A2 * 3;
    D_801981F4.vy = (s16)func_80028BF0(&D_801981F4) + p->unk72;
    func_8002924C(&p->base, &D_801981F4, &D_800B6124);
    func_800221C8();
    func_8001F86C();
}

typedef struct {
    u8 pad0[0x1C];
    SVECTOR rot;
    SVECTOR v;
    struct Task *parent;
    u8 pad30[0x3A];
    s16 unk6A;
    u8 pad6C[2];
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    u8 pad74[0x14];
    VECTOR base;
} Unk8004C8DC;

void func_8004C8DC(VECTOR *pos) {
    Unk8004C8DC *p = (Unk8004C8DC *)D_801F80B0[0]->vals;

    D_801F80B0[0]->saved = D_801F80B0[0]->func;
    D_801F80B0[0]->func = func_8004C828;
    p->unk6A = 0x20;
    p->rot.vx = 0;
    p->rot.vz = 0;
    func_80074910(0x1000);
    p->rot.vy = 0x400;
    p->base.vx = pos->vx;
    p->base.vy = pos->vy;
    p->base.vz = pos->vz;
    p->unk70 = 0;
    p->unk72 = 800;
    p->v.vx = 0;
    p->v.vy = 0;
    p->v.vz = -0x800;
    p->parent = D_800B604C;
    p->unk6E = 60;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004C998);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55AC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55B4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55C4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55CC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B55DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5604);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5608);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5610);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5618);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5620);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5628);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5630);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5638);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5640);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5648);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5650);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5658);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5660);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5668);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5670);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5674);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B567C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004CBB0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004CE18);

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[4];
    s16 unkE;
    VECTOR pos;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    u8 unk28[0xFC];
    s32 unk124;
    s16 unk128;
    u8 pad12A[0x62];
    s16 unk18C;
} Unk8004CF74;

typedef struct {
    void (*func)();
    s16 unk4;
    s16 unk6;
} Unk800B615C;

extern Unk800B615C *D_800B615C;
extern void *D_801FAB78[];
void func_8004DB54();
void func_80054D3C(void);
void func_8004DCC4(s32 arg);

void func_8004CF74(void) {
    u8 unused[16];
    Unk8004CF74 *p = (Unk8004CF74 *)D_800B604C->vals;

    func_80028A48(&D_800B659C->pos, &p->pos);
    p->unkE = 4;
    D_800B5DE4 = 0;
    D_800B5DEC = 0;
    if (func_800210B8(D_801FAB78[p->unk8], &p->pos, &p->unk20)) {
        func_80021AFC(p);
        func_800564EC(D_800B61F4, p);
    } else {
        D_800B615C[p->unk128].unk6 = p->unk8 + 0x14;
        D_800B615C[p->unk128].func = func_8004DB54;
        func_8004DCC4(p->unk124);
        D_800B604C->func = func_80054D3C;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004D07C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004D2D0);

extern s16 D_800B622C;
void func_8006CD18(struct Task *t, s32 flag);
void func_8006CB7C(struct Task *t, s32 flag);
void func_800669C0(VECTOR *v, s32 arg);
void func_8002C58C(void);

void func_8004D4A4(VECTOR *pos) {
    func_8006CD18(D_801F80B0[3], 0x10);
    func_8006CB7C(D_801F80B0[3], 0x20);
    func_800669C0(&D_800B659C->pos, 0);
    D_800B622C = 0;
    func_80050730();
    func_8004C8DC(pos);
    D_800B659C->unk1AA = -1;
    D_801F80B0[3]->saved = D_801F80B0[3]->func;
    D_801F80B0[3]->func = func_8002C58C;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004D554);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004D70C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004D9A4);

void func_8004DB54(x, z, obj, d, e)
s16 x;
s16 z;
u8 *obj;
s16 d;
s16 e;
{
    struct Task *t;
    Unk8004CF74 *p;

    t = func_80072374(func_8004CF74, 0x1C0);
    if (t != NULL) {
        t->flags |= 0x21;
        p = (Unk8004CF74 *)t->vals;
        p->unk18C = 0;
        p->pos.vx = (x << 9) + 0x80;
        p->pos.vz = (z << 9) + 0x100;
        p->pos.vx = ((p->pos.vx >> 12) << 12) + 0x800;
        p->pos.vz = ((p->pos.vz >> 12) << 12) + 0xA80;
        p->pos.vy = (s16)func_80028BF0(&p->pos);
        p->unk8 = d - 20;
        p->unk20 = 0;
        p->unk22 = 0x400;
        p->unk24 = 0;
        p->unk124 = (s32)obj;
        p->unk128 = e;
        func_8006B48C(p->unk8 + 20, p->unk28);
        obj[4] = 0;
        func_80043560(x, z, 0, 0);
    }
}

void func_8004DC84(s16 i, s32 v) {
    if (i != -1 && i >= -1 && i <= 0x1000) {
        D_800B615C[i].unk4 = v;
    }
}

extern u8 *D_800B8530;

void func_8004DCC4(s32 arg) {
    u8 *p = (u8 *)arg;

    if (p != NULL && ((u32)p & 3) == 0 && p >= D_800B8530 && p <= D_800B8530 + 0x38E00) {
        p[4] = 0xFF;
    }
}

extern u16 D_801F82AC[];

void func_8004DD0C(s16 x, s16 z, void *arg) {
    void (*fn)();
    s16 i;
    s16 cell;

    i = D_801F82AC[((z & 7) << 3) + (x & 7)];
    cell = ((x >> 3) & 0x3F) + ((z & 0x3F8) << 3);
    if (D_800B61DC != 0) {
        return;
    }
    while ((fn = D_800B615C[i].func) != NULL) {
        if (D_800B615C[i].unk4 == cell) {
            PushMatrix();
            fn(x, z, arg, D_800B615C[i].unk6, i);
            PopMatrix();
        }
        i++;
    }
}

extern s32 *D_800B6464;
extern void *D_800B5E4C;
extern s32 *D_800B65AC;
void *func_80071BB0(void *data, s16 i);
u32 func_80071BC8(void *data, s16 i);
s32 func_8002826C(s32 size);
void func_8004FF54(void);

void func_8004DE58(void) {
    D_800B6464 = (s32 *)func_8002826C((s32)D_800B6464);
    D_800B5D3C = func_80071BB0(D_800B5E4C, 1);
    D_800B6544 = 0;
    D_800B62EC = D_800B6464;
    D_800B5D04 = func_80071BC8(D_800B5E4C, 1);
    D_800B65AC = D_800B6464;
    D_800B6464 = (s32 *)((u8 *)D_800B6464 + D_800B5D04);
    D_800B604C->saved = D_800B604C->func;
    D_800B604C->func = func_8004FF54;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004DF04);

typedef struct {
    s32 unk0;
    u8 pad4[0xC];
} Unk801984F4;

extern Unk801984F4 D_801984F4[];

void func_8004E1B0(void) {
    s16 i = 0xB;

    do {
        D_801984F4[i].unk0 = 0;
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004E1E4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004ED7C);

extern u8 D_800B63EC;
extern VECTOR D_801FA448[];

void func_8004FB4C(void) {
    VECTOR v;
    s16 i;
    s16 j;
    u8 k;
    s32 d;
    s32 best;
    u8 bestk;

    i = 0x7F;
    do {
        j = 0x3F;
        do {
            k = D_800B63EC;
            best = 32000;
            bestk = 0xFF;
            while (k--) {
                v.vx = (j << 12) + 0x800;
                v.vz = (i << 12) + 0x800;
                d = func_80028A48(&v, &D_801FA448[k]);
                if (d < best) {
                    best = d;
                    bestk = k;
                }
            }
            D_800B62C4[(j & 0x3F) + ((i & 0x7F) << 6)].unk5 = bestk;
        } while (j--);
    } while (i--);
}

extern s32 *D_800B6074;
extern s16 D_800B66DC;
extern s16 D_800B5EA4;
extern s16 D_800B5D5C;
s32 func_80071B54(s32 arg);

void func_8004FC6C(void) {
    D_800B6074 = D_800B6464;
    D_800B6464 = (s32 *)((u8 *)D_800B6464 + func_80071B54(D_800B66DC + 0x20));
    D_800B5EA4 = 100;
    D_800B5D5C = 6;
    func_800728A4();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004FCD8);

extern s32 *D_800B5E74;

void func_8004FEC0(void) {
    D_800B5D3C = func_80071BB0(D_800B5E4C, 3);
    D_800B6544 = 0;
    D_800B62EC = D_800B6464;
    D_800B5D04 = func_80071BC8(D_800B5E4C, 3);
    D_800B5E74 = D_800B6464;
    D_800B6464 = (s32 *)((u8 *)D_800B6464 + D_800B5D04);
    D_800B604C->saved = D_800B604C->func;
    D_800B604C->func = func_8004FF54;
}

extern s32 *D_800B62EC;
extern s32 *D_800B5D3C;
extern s32 D_800B6544;
extern s32 D_800B5D04;

void func_8004FF54(void) {
    u16 i;

    i = 0x3FF;
    do {
        *D_800B62EC++ = *D_800B5D3C++;
    } while (i--);
    D_800B6544 += 0x1000;
    if (D_800B6544 >= D_800B5D04) {
        D_800B604C->func = D_800B604C->saved;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8004FFE4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005017C);

void func_8005017C(void);

void func_80050244(void) {
    struct Task *t = D_800B604C;
    s16 *d = (s16 *)t->vals;

    d[0xE] = 0;
    d[0xF] = 0;
    d[0x10] = 0;
    t->func = func_8005017C;
}

void func_80050274(void) {
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005027C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800504A4);

extern VECTOR D_801984F0;
extern VECTOR D_801CA284;
void func_8003F57C(void);

void func_8005061C(void) {
    D_800B650C = 1;
    D_801CA284.vx = D_801984F0.vx;
    D_801CA284.vy = D_801984F0.vy;
    D_801CA284.vz = D_801984F0.vz;
    func_80072A40(0x20);
    func_8003F57C();
    func_80050DFC();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80050688);

extern struct Task *D_801F80D0;

void func_80050730(void) {
    if (D_801F80D0 != NULL) {
        ((s16 *)D_801F80D0->vals)[0x77] = -1;
    }
}

void func_80050758(void) {
    if (D_801F80D0 != NULL) {
        ((s16 *)D_801F80D0->vals)[0x77] = 0;
    }
}

typedef struct {
    u8 pad0[8];
    s16 unk8[16];
    s16 unk28[16];
    s32 unk48;
    s32 unk4C;
    s16 unk50;
    s16 unk52;
} Unk80050780;

extern s16 D_800B6126;
void func_800687A8();
void func_8005090C(void);

void func_80050780(void) {
    Unk80050780 *p = (Unk80050780 *)D_800B604C->vals;
    s16 i;

    func_800687A8(0x11);
    D_800B604C->flags = 0x21;
    if (D_800B5D74 != 0) {
        func_8005085C();
        func_800728A4();
        return;
    }
    i = 15;
    p->unk50 = -D_800B6126 & 0xFFF;
    do {
        p->unk8[i] = func_80074910(0xB4);
        p->unk28[i] = 0;
    } while (i--);
    p->unk52 = 0x19;
    p->unk48 = 0x2000;
    p->unk4C = 0x200;
    D_800B604C->func = func_8005090C;
}

s16 func_8006F7DC(s32 a, s32 b, s32 i);

s16 func_8005085C(void) {
    s16 r;

    if (D_800B5D74) {
        r = func_8006F7DC(0x20C, 0x3E80, 0);
        func_8006F7DC(0x400, 0x4268, 1);
        func_8006F7DC(0x5F4, 0x445C, 2);
        func_8006F7DC(0x7E8, 0x4650, 3);
    } else {
        r = func_8006F7DC(0x400, 0x3E80, 0);
        func_8006F7DC(0x7E8, 0x4268, 1);
        func_8006F7DC(0xFB8, 0x445C, 2);
        func_8006F7DC(0x1788, 0x4650, 3);
    }
    return r;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005090C);

void func_80050D40(s16 *angle, s16 *speed) {
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

void func_80050688(void);
void func_80050758(void);
void func_800511D8(void);

void func_80050DC4(void) {
    func_80050688();
    func_80050758();
    D_800B604C->func = func_800511D8;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80050DFC);

extern s16 D_800B5F4C;

void func_8005119C(void) {
    if (D_800B61A4->unk2 == 0) {
        D_800B5F4C--;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800511D8);

extern s16 D_800B5DF4;

void func_80051410(void) {
    D_800B5DF4 = -1;
}

extern volatile s32 D_800B6284[];
extern u16 D_800972F8;
extern u16 D_800972FA;
extern u16 D_80097300;

void func_80051424(void) {
    if ((D_800972FA & D_800B6284[0]) || (D_80097300 & D_800B6284[0])) {
        func_80069894();
        D_800B6614->unk1780++;
    }
    if (D_800972F8 & D_800B6284[0]) {
        func_80069894();
        D_800B6614->unk1780--;
    }
    D_800B6614->unk1780 &= 7;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80051500);

extern s16 D_800B5DC4;
extern u8 D_80091A28[];
extern u8 D_80091A14[];

u8 *func_8005160C(void) {
    if (D_800B5DC4 == 3) {
        return D_80091A28;
    }
    return D_80091A14;
}

extern s16 D_800B5D0C;
extern s16 D_800B5F54;
extern s16 D_800B61C4;
extern s32 D_800B5CD0;
extern s32 D_800B5EDC;
extern s16 D_800B5F4C;
extern s16 D_800B640C;
extern s32 D_800B5F8C;
extern volatile s16 D_800B61AC;

void func_80051638(void) {
    D_800B5D0C = 3;
    D_800B5F54 = 1;
    D_800B61C4 = 0;
    D_800B5CD0 = 0;
    D_800B5EDC = 0;
    D_800B5F4C = 3;
    D_800B5F8C = 0;
    D_800B61AC = 3;
    D_800B640C = 0;
    D_800B6504 = D_800936C4[0].unk0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800516A0);

extern s16 D_800B5D0C;

void func_800517DC(void) {
    D_800B5D0C = 9;
}

typedef struct {
    u8 pad0[0x20];
    s16 unk20[6];
    s16 unk2C[6];
    s16 unk38;
    s16 pad3A;
    s16 unk3C;
    s16 pad3E;
    s16 unk40;
} Unk800517F0;

void func_800517F0(Unk800517F0 *p) {
    s16 i;

    p->unk40 = 0;
    i = 5;
    do {
        p->unk2C[i] = 0;
        p->unk20[i] = 0x1000;
    } while (i--);
    p->unk38 = 0;
    p->unk2C[0] = 2;
    p->unk3C = 0;
}

typedef struct {
    u8 pad0[0x1C];
    u8 *unk1C;
} Unk80051864;

void func_800517F0();
extern u8 D_800931FC[];

void func_80051834(Unk80051864 *obj) {
    obj->unk1C = D_800931FC;
    func_800517F0(obj);
}

typedef struct {
    u8 pad0[0x3A];
    s16 unk3A;
} Unk8005185C;

void func_8005185C(Unk8005185C *obj) {
    obj->unk3A = 0;
}

extern u8 *D_800BA6EC[];
extern s16 D_800B5DC4;
extern u8 D_8009330C[];
extern u8 D_80093394[];
void func_800517F0();

void func_80051864(Unk80051864 *obj, s16 i) {
    u8 *p = D_800BA6EC[i];

    obj->unk1C = p;
    if (p == D_8009330C && D_800B5DC4 == 3) {
        obj->unk1C = D_80093394;
    }
    func_800517F0(obj);
}

void func_800518CC(Unk8005185C *obj) {
    obj->unk3A = 0;
}

void func_800518D4(Unk8005185C *obj) {
    D_800B5D0C = 2;
    obj->unk3A = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800518E8);

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
} POLY_G4;

extern void SetPolyG4(POLY_G4 *p);
extern void *D_800B63AC;
extern u32 *D_800B62CC;
extern void AddPrim(void *ot, void *p);

void func_80051C14(s16 t, s32 y) {
    s16 top = y - 8;
    s16 bottom = y + 8;
    POLY_G4 *p = D_800B63AC;
    s16 c;

    p->x0 = p->x2 = 0xC0;
    p->x1 = p->x3 = 0x11A;
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
    AddPrim(D_800B62CC + 2, p++);
    p->x0 = p->x2 = func_80071B7C(0xC0, 0x106, t);
    p->x1 = p->x3 = func_80071B7C(0xC4, 0x11A, t);
    p->y0 = p->y1 = y - 9;
    p->y2 = p->y3 = y + 9;
    c = func_80071B7C(0x78, 0xFF, t);
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
    AddPrim(D_800B62CC + 1, p++);
    D_800B63AC = p;
}

extern volatile s32 D_800B6284[];
extern u16 D_80097300;
extern s16 D_801F7520;

void func_80051DA4(void) {
    s16 v;

    func_80051500();
    v = D_801F7520 * 16;
    if (D_80097300 & D_800B6284[0]) {
        D_800B61A4->unk1C = v;
        D_800B61A4->unk8 = v;
        D_800B61A4->unk10 = v;
    }
    if (v < 0) {
        v = 0;
    }
    if (v >= 0xFFF) {
        v = 0x1000;
    }
    if (v < D_800B61A4->unk8) {
        D_800B61A4->unk8 = v;
    }
    if (D_800B61A4->unk10 < v) {
        D_800B61A4->unk10 = v;
    }
}

typedef struct {
    s32 vol;
    u8 pad4[0x10];
} Unk80051E7C_Ch;

typedef struct {
    u8 pad0[0x20];
    Unk80051E7C_Ch ch[1];
} Unk80051E7C_Chs;

typedef struct {
    u8 pad0[0x1C];
    Unk80051E7C_Chs *chs;
    u8 pad20[0x18];
    s16 cur;
} Unk80051E7C;

extern u32 D_800B5FC4[];
extern u16 D_800972F8;

void func_80051E7C(Unk80051E7C *s) {
    Unk80051E7C_Chs *chs = s->chs;

    if (D_800972FA & D_800B5FC4[0]) {
        chs->ch[s->cur].vol = func_8002881C((s16)chs->ch[s->cur].vol, 0x1000, 0x80);
        func_80053AA8();
    }
    if (D_800972F8 & D_800B5FC4[0]) {
        chs->ch[s->cur].vol = func_8002881C((s16)chs->ch[s->cur].vol, 0, 0x80);
        func_80053AA8();
    }
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B568C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5694);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56A0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56AC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56B4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56BC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56C0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56D4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56DC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56E4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56EC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B56FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5704);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80051F74);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80052638);

void func_80052818(void) {
    u8 unused[24];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80052824);

extern u8 D_800B56E4[];
extern u8 D_800B56D8[];
extern char D_80091A3C[];
extern char D_80091A5C[];
extern s32 D_800B5FC8;
void func_80068DCC(void);
void func_80052824(void *p, s32 a, s32 b, s32 c);
void func_80051F74(void *p, s32 a, s32 b);

void func_80052C70(void) {
    void *p = D_800B604C->vals;

    func_80051500();
    func_80068DCC();
    if (D_800B5D0C == 9) {
        func_800728A4();
        return;
    }
    func_800758C0(0xA0, 0x4B, func_80077DC8(D_80091A3C), 0xA28, 0x800, D_800B56E4, D_800B56D8);
    func_800758C0(0xA0, 0x87, func_80077DC8(D_80091A5C), 0x800, 0x400, D_800B56D8, D_800B56E4);
    func_80052824(p, 0, 0, 0);
    func_80051F74(p, 0, 0);
    if (*(volatile u32 *)D_800B5FC4 != 0 || D_800B5FC8 != 0) {
        D_800B6614->unk178E = 0;
    }
}

typedef struct {
    u8 pad0[0x1C];
    u8 *table;
    u8 pad20[0x26];
    s16 unk46;
} Unk80052DB4;

extern u8 D_8009363C[];
extern u8 D_800935B4[];
void func_80051500(void);
void func_80052C70(void);

void func_80052DB4(void) {
    Unk80052DB4 *p = (Unk80052DB4 *)D_800B604C->vals;

    func_80053B84();
    func_80068C70();
    func_80051500();
    if (D_800B6614->maps[D_800B6614->unk1780][0x18]) {
        p->table = D_8009363C;
    } else {
        p->table = D_800935B4;
    }
    p->unk46 = 1;
    func_800517F0((Unk800517F0 *)p);
    D_800B604C->func = func_80052C70;
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B570C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5710);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5714);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5718);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5720);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5728);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B572C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5730);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5734);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5738);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B573C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5748);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B574C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5754);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B575C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5764);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B576C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5780);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5788);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5794);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B579C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57B8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B57F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5800);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5804);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B580C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5810);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5814);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5818);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B581C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5824);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B582C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5834);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B583C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5840);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5848);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B584C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5854);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B585C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5864);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B586C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5874);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5880);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5888);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5890);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5898);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B589C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58A8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80052E70);

typedef struct {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x24];
    s16 unk3E;
    u8 pad40[2];
    s16 unk42;
    s16 unk44;
} Unk80053644;

extern s16 D_800B6434;
extern s16 D_800B66D4;
extern u8 D_800931FC[];
extern u8 D_80093284[];
extern u8 D_8009330C[];
extern u8 D_8009341C[];
extern u8 D_800934A4[];
extern u8 D_8009352C[];
extern u8 *D_800BA6F0;
extern u8 *D_800BA6F4;
extern u8 *D_800BA6F8;
extern u8 *D_800BA6FC;
extern u8 *D_800BA700;
extern u8 *D_800BA704;
extern u8 *D_800BA708;
void func_80052E70(void);

void func_80053644(void) {
    Unk80053644 *d;

    d = (Unk80053644 *)D_800B604C->vals;
    D_800B604C->unk28 = 0xFF;
    D_800B604C->unk29 = 0;
    D_800B604C->unk2A = 0;
    d->unk18 = -1;
    d->unk3E = 0;
    d->unk42 = -1;
    d->unk44 = 0;
    D_800B6434 = 0;
    D_800B66D4 = 0;
    D_800BA6F0 = D_800931FC;
    D_800BA6F4 = D_800931FC;
    D_800BA6F8 = D_80093284;
    D_800BA6FC = D_8009330C;
    D_800BA700 = D_8009341C;
    D_800BA704 = D_800934A4;
    D_800BA708 = D_8009352C;
    D_800B604C->func = func_80052E70;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80053718);

void func_80053718(void);

void func_80053A3C(void) {
    func_80072374(func_80053718, 2);
}

extern s16 D_800B65DC;
extern s16 D_800B65FC;
extern s16 D_800B628C;
extern s16 D_800B6254;
extern s16 D_800B6256;

void func_80053A64(void) {
    D_800B65DC = 0x30;
    D_800B65FC = 0x32;
    D_800B628C = 0x190;
    D_800B6254 = 0x580;
    D_800B6256 = 0x400;
}

void func_80053AA8(void) {
}

void func_80053AB0(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0x3FFF;
    attr.mvol.right = 0x3FFF;
    attr.cd.volume.left = func_80071B7C(0, 0x3FFF, D_800B6614->unk1784);
    attr.cd.volume.right = func_80071B7C(0, 0x3FFF, D_800B6614->unk1784);
    attr.mask = 0xC3;
    SpuSetCommonAttr(&attr);
}

void func_80053B1C(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0;
    attr.mvol.right = 0;
    attr.cd.volume.left = 0;
    attr.cd.volume.right = 0;
    attr.mask = 0xC3;
    SpuSetCommonAttr(&attr);
}

void func_80053B54(void) {
    SpuCommonAttr attr;

    attr.cd.volume.left = 0;
    attr.cd.volume.right = 0;
    attr.mask = 0xC0;
    SpuSetCommonAttr(&attr);
}

void func_80053B84(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0x3FFF;
    attr.mvol.right = 0x3FFF;
    attr.mask = 0x3;
    SpuSetCommonAttr(&attr);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80053BB8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005420C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800545F8);

typedef struct {
    u8 pad0[0x28];
    s16 limit[3];
    u8 pad2E[0x16];
    s16 step;
    u8 pad46[0x1E];
} Unk80092480;

typedef struct {
    u8 pad0[8];
    s16 type;
    u8 padA[0x56];
    s16 unk60;
    u8 pad62[0xB4];
    s16 level;
} Unk80054A04;

extern Unk80092480 D_80092480[];

void func_80054A04(Unk80054A04 *p) {
    Unk80092480 *e = &D_80092480[p->type];

    if (p->level < 3 && p->unk60 > e->limit[p->level]) {
        p->level++;
        p->unk60 -= e->step;
    }
    if (p->level != 0 && p->unk60 < e->limit[p->level - 1] - e->step - 1) {
        p->level--;
    }
}

typedef struct {
    u8 pad0[0x22];
    s16 unk22;
    u8 pad24[0xF4];
    s16 unk118;
} Unk80054ABC;

void func_80054ABC(Unk80054ABC *obj) {
    obj->unk22 += obj->unk118 >> 2;
    obj->unk118 = func_8002881C(obj->unk118, 0, 4);
}

typedef struct {
    u8 pad0[0x22];
    s16 unk22;
    u8 pad24[0x2C];
    VECTOR pos;
    u8 pad60[0x44];
    SVECTOR vel;
    u8 padAC[0x68];
    s16 unk114;
    u8 pad116[0x36];
    s16 unk14C;
} Unk80054B08;

void func_80053BB8();
void func_8005420C();
void func_800545F8();

void func_80054B08(void) {
    Unk80054B08 *p = (Unk80054B08 *)D_800B604C->vals;
    s16 d;

    if (p->unk14C < 8 || func_80028AF8(&p->vel) < 0x80) {
        func_80053BB8(p);
        func_8005420C(p);
        func_80054ABC((Unk80054ABC *)p);
        func_800545F8(p);
        func_80054A04((Unk80054A04 *)p);
    }
    p->pos.vx += p->vel.vx;
    p->pos.vz += p->vel.vz;
    d = func_80028AF8(&p->vel);
    if (d >= 0x40) {
        if (d < 0x400) {
            p->unk22 += (p->unk114 * (s16)func_80071B7C(0x800, 0x400, d * 4)) >> 12;
        } else {
            p->unk22 += p->unk114 >> 2;
        }
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
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} Unk8015EB3C;

extern Unk8015EB3C D_8018CC68;

void func_80054C10(s16 i) {
    s16 v;

    D_8018CC68.unk0 = 0;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk16 = 0;
    if (D_800B6C50[i] == 4) {
        D_8018CC68.unk12 = 0x3FFF;
        v = 0x3A;
    } else if (D_800B6C50[i] == 6) {
        D_8018CC68.unk12 = 0x3FFF;
        v = 0x29;
    } else if (D_800B6C50[i] == 5) {
        D_8018CC68.unk12 = 0x3FFF;
        v = 0x47;
    } else if (D_800B6C50[i] == 1) {
        D_8018CC68.unk12 = 0x2EDF;
        v = 0x28;
    } else {
        D_8018CC68.unk12 = 0x3FFF;
        v = 0x34;
    }
    D_8018CC68.unk8 = v;
}

void func_8006B42C(void);
void func_80068BD4(s16);

void func_80054CE4(s16 i) {
    if (i != -1) {
        if (i < 0 || i >= 0x18) {
            func_80072374(func_8006B42C, 0);
        }
        func_80068BD4(i);
    }
}

void func_80054D3C(void) {
    func_800728A4();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80054D5C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80054EB0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80055018);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80055180);

typedef struct Unk800555EC_Node {
    s32 id;
    struct Unk800555EC_Node *next;
} Unk800555EC_Node;

typedef struct {
    u8 pad0[0x20];
    Unk800555EC_Node n[32];
} Unk800555EC;

extern struct Task *D_801F80DC;

void func_800555EC(void) {
    Unk800555EC *p = (Unk800555EC *)D_801F80DC->vals;
    s16 i;

    for (i = 0; i < 32; i++) {
        p->n[i].next = &p->n[i + 1];
        p->n[i].id = i;
    }
    p->n[31].id = 0xFFFF;
    p->n[0].id = 1;
}

void func_80055648(void) {
    u8 unused[24];
}

extern s16 D_800B5E84;
extern s16 D_800B62A4;
extern s16 D_800B6454;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 pad4;
    s16 unk6;
    s16 unk8;
    s16 padA;
    s32 unkC;
    s32 pad10;
    s32 unk14;
    s32 pad18;
    s16 unk1C;
} Unk80055654;

extern s16 D_800B56B4;
void func_800556D8(void);

void func_80055654(void) {
    Unk80055654 *p = (Unk80055654 *)D_800B604C->vals;

    D_800B6454 = 0;
    D_800B62A4 = 0;
    D_800B5E84 = 0;
    D_800B56B4 = 10;
    p->unk6 = 1;
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk14 = 0;
    p->unk1C = 0;
    func_800555EC();
    func_80055648();
    D_800B604C->func = func_800556D8;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800556D8);

void func_80055868(void) {
    s16 i = 3;

    D_800B659C->unk174 = D_800B659C->unk176 = 0xA00;
    do {
        if (D_800B659C->unkF4[i] == 0) {
            D_800B659C->unkF4[i] = -(s16)func_80074910(0x4B);
        }
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800558FC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80055A9C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800562F8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005648C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800564EC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80056690);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005676C);

void func_80056B08(void) {
    u8 unused[24];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80056B14);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80056B74);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80056BCC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80056C24);

typedef struct {
    u8 pad0[0x9E];
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
} Unk80056E84;

void func_80056E84(void) {
    Unk80056E84 *p = (Unk80056E84 *)D_800B604C->vals;

    p->unk9E -= p->unkA0;
    if (p->unk9E < 0) {
        p->unk9E = 64;
        p->unkA2 ^= 3;
        D_800B5DE4 = p->unkA2;
    } else {
        D_800B5DE4 = 0;
    }
    p->unkA4 -= p->unkA6;
    if (p->unkA4 < 0) {
        p->unkA4 = 64;
        p->unkA8 ^= 3;
        D_800B5DEC = p->unkA8;
    } else {
        D_800B5DEC = 0;
    }
}

extern SVECTOR D_800B6594;

s32 func_80056F30(void) {
    Unk800462E4 *p = (Unk800462E4 *)D_800B604C->vals;

    func_80056E84();
    D_800B6594.vx = p->unk20;
    D_800B6594.vy = p->unk22;
    D_800B6594.vz = p->unk24;
    if (func_800210B8((void *)D_801FAB28[p->unk8], &p->pos, &D_800B6594.vx) == 0) {
        p->unk70++;
        if (p->unk88 < 20) {
            return 0;
        }
        if ((s16)func_80028A48(&p->pos, &D_801981F4) <= 0x800 && p->unk70 <= 60) {
            return 0;
        }
        if (p->unk70 <= 30) {
            return 0;
        }
        p->pos.vx = -0x2000;
        p->pos.vz = -0x2000;
        D_800B604C->func = func_80054D3C;
        return -1;
    }
    func_80021AFC(p);
    p->unk70 = 0;
    return 0;
}

typedef struct {
    u8 pad0[0xC2];
    s16 unkC2;
} Unk80057064;

extern s16 D_800B56A2;

void func_80057064(Unk80057064 *obj) {
    if (obj->unkC2 != 0) {
        obj->unkC2 = func_8002881C(obj->unkC2, 0, D_800B56A2);
    }
}

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
    u8 unk10[0xB2];
    s16 unkC2;
} Unk800570A8;

void func_80067394(void *p, s16 arg);

void func_800570A8(Unk800570A8 *obj) {
    if (obj->unkC2 == 0) {
        func_80067394(obj->unk10, obj->unkE);
        obj->unkC2 = func_80074910(30) + 30;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800570F4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005727C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80057400);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800576E8);

void func_80057400(void);

void func_800577E4(void) {
    struct Task *t = D_800B604C;
    s16 *d = (s16 *)t->vals;

    d[0x39] = 0x60;
    d[0x45] = 0x40;
    d[0x46] = 0x40;
    t->func = func_80057400;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80057818);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80057CE4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80057F88);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058154);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058418);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800585A4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058724);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58C0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58DC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058AEC);

typedef struct {
    u8 pad0[0x88];
    s16 unk88;
    u8 pad8A[0x12];
    s16 unk9C;
} Unk80058C44;

extern s16 D_800B5D74;
extern s16 D_800B6554;
extern s16 D_800B66DC;
extern s16 D_800B6504;
extern void func_800728A4(void);

void func_80058C44(void) {
    Unk80058C44 *p = (Unk80058C44 *)D_800B604C->vals;

    p->unk88 += D_800B56A2;
    if (p->unk88++ >= 0x8D && p->unk9C != 0) {
        if (D_800B5D74 != 0) {
            D_800B6554 = 0;
            D_800B66DC = -1;
            D_800B640C++;
            D_800B6504 = D_800936C4[D_800B640C].unk0;
            p->unk9C = 0;
            return;
        }
        func_8005027C();
        p->unk9C = 0;
    }
    if (p->unk88 > 0xF0) {
        func_800728A4();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058D48);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80058F44);

typedef struct {
    u8 pad0[8];
    s16 unk8[16];
    s16 unk28[16];
    s32 unk48;
    s32 unk4C;
    s16 pad50;
    s16 unk52;
    u8 pad54[0x10];
    s16 unk64;
    s16 unk66;
} Unk8005919C;

s32 func_80074910(s32);
extern void func_8005923C(void);

void func_8005919C(void) {
    Unk8005919C *p = (Unk8005919C *)D_800B604C->vals;
    s16 i;

    i = 15;
    do {
        p->unk8[i] = func_80074910(180);
        p->unk28[i] = 0;
    } while (i--);
    p->unk52 = 25;
    p->unk48 = 0x2000;
    p->unk4C = 0x200;
    p->unk64 = 0x400;
    p->unk66 = func_80074910(0x1000);
    D_800B604C->func = func_8005923C;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005923C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005940C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800596B8);

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[6];
    VECTOR pos;
    u8 pad20[8];
    u8 unk28[0x60];
    s16 unk88;
    s16 unk8A;
    u8 pad8C[0xC];
    s32 unk98;
} Unk80059744;

void func_800596B8(void);
void func_8005940C(void);
struct Task *func_80072768(struct Task *parent, void (*fn)(), s16 size);
void func_8006B48C(s16 id, void *p);

s32 func_80059744(VECTOR *pos, s16 id) {
    struct Task *t;
    Unk80059744 *p;

    func_800596B8();
    t = func_80072768(D_801F80BC, func_8005940C, 0xC4);
    if (t != NULL) {
        p = (Unk80059744 *)t->vals;
        p->unk98 = 0;
        p->unk8 = id;
        p->pos.vx = pos->vx;
        p->pos.vz = pos->vz;
        p->pos.vy = (s16)func_80028BF0(&p->pos);
        p->unk88 = 0;
        p->unk8A = 60;
        func_8006B48C(p->unk8, p->unk28);
        return -1;
    }
    return 0;
}

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 padE[2];
    VECTOR pos;
} Unk800597F8;

extern VECTOR D_801F76D0;

void func_800597F8(void) {
    Unk800597F8 *p = (Unk800597F8 *)D_800B604C->vals;
    s16 s;
    s16 v;
    s32 dt = D_800B56A2;

    p->unkC += dt << 5;
    if (p->unkC >= 0x1000) {
        p->unkC = 0x1000;
        D_801F76D0.vx = p->pos.vx;
        D_801F76D0.vy = p->pos.vy + 0x100;
        D_801F76D0.vz = p->pos.vz;
        func_8005A7A4(&D_801F76D0, &D_801981F4, 0x1000);
    } else {
        for (s = 0x400; s >= 0; s -= 0x200) {
            v = s + p->unkC;
            if (v > 0x1000) {
                v = 0x1000;
            }
            D_801F76D0.vx = p->pos.vx;
            D_801F76D0.vy = p->pos.vy + 0x100;
            D_801F76D0.vz = p->pos.vz;
            func_8005A7A4(&D_801F76D0, &D_801981F4, v);
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80059924);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80059DC0);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[4];
    s16 unk14;
    s16 unk16;
    s16 unk18;
} Unk80059F74;

void func_8005A03C();

void func_80059F74(s16 a, s16 b, VECTOR *pos) {
    Unk8003BA6C_Task *t = func_800724C4(func_8005A03C, 0x10, 0x1C);
    Unk80059F74 *d;

    if (t != NULL) {
        d = (Unk80059F74 *)t->data;
        d->unk2 = a;
        d->unk0 = a + 200;
        d->unk4 = pos->vx;
        d->unkC = pos->vz;
        d->unk8 = (s16)func_80028BF0(pos);
        d->unk14 = 0xFF;
        d->unk16 = 0;
        d->unk18 = b / 2;
    }
}

void func_8005A034(void) {
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005A03C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005A520);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005A7A4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005A9C4);

void func_8005AB64(void) {
    u8 unused[24];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005AB70);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005AD38);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005AE34);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005AF8C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005B274);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005B7B0);

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[4];
    s16 unkE;
    u8 pad10[0x10];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    u8 unk28[0x10];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 pad3E[0x12];
    VECTOR unk50;
    u8 pad60[0xFA];
    s16 unk15A;
    u8 pad15C[0x14];
    s16 unk170;
    u8 pad172[0x66];
    s16 unk1D8;
    s16 unk1DA;
    u8 pad1DC[8];
    s16 unk1E4;
    u8 pad1E6[0x12];
    s32 unk1F8;
    s16 unk1FC;
} Unk8005BA74;

extern s16 D_800B618C;
void func_8005AE34(s32 a, VECTOR *v, s16 b);
void func_8002C234(s16 a, void *p);
void func_8005B7B0(void);
void func_8006738C(void);
s32 func_800691E8(Unk8015EB3C *arg0, s32 arg1);

void func_8005BA74(void) {
    struct Task *t = D_800B604C;
    Unk8005BA74 *p;
    VECTOR v;

    t->flags = 3;
    p = (Unk8005BA74 *)t->vals;
    p->unk15A = D_800B618C + 1;
    func_8005AE34(0x14, &p->unk50, p->unk15A);
    func_8005AE34(0x200, &v, p->unk15A);
    p->unk8 = 2;
    p->unk20 = 0;
    p->unk24 = 0;
    p->unk22 = func_80028648(&v, &p->unk50);
    p->unk8 = 2;
    p->unk170 = 100;
    p->unk38 = 0;
    p->unk3A = 0;
    p->unk3C = 0;
    p->unk1D8 = 100;
    p->unk1DA = -1;
    p->unk1F8 = 0;
    p->unk1E4 = 0;
    p->unk50.vx <<= 5;
    p->unk50.vz <<= 5;
    func_80054C10(p->unk8);
    p->unk1FC = func_800691E8(&D_8018CC68, (s32)func_8006738C);
    func_8006B48C(0x1E, p->unk28);
    func_8002C234(p->unk8, p);
    p->unkE = 3;
    D_800B604C->func = func_8005B7B0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005BBA8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005BCF8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005C1BC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005C2CC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005C544);

typedef struct {
    u8 pad0[0x200];
    s16 unk200[32];
    u8 pad240[8];
    u8 unk248[4];
    s32 unk24C;
} Unk8005C850;

s32 func_80028BF0(void *p);
void func_8005C544(void);

void func_8005C850(void) {
    Unk8005C850 *d = (Unk8005C850 *)D_800B604C->vals;
    s16 i;

    d->unk24C = (s16)func_80028BF0(d->unk248);
    i = 0x1F;
    do {
        d->unk200[i] = 0;
    } while (i--);
    D_800B604C->func = func_8005C544;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005C8C4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005CADC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005CC44);

extern s16 D_800B5EA4;
extern s16 D_800B6674;
void func_800484A4(void);

void func_8005CD78(void) {
    D_800B6674 = 3;
    func_800484A4();
    D_800B5EA4 = 0x19;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005CDB0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005CF28);

extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern s16 D_800B64D4;
extern int VSync(int mode);

void func_8005D108(void) {
    u8 result[8];

    if (D_800B64D4 != 1) {
        CdControlB(8, 0, result);
        VSync(0);
        D_800B64D4 = 1;
    }
}

extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern s16 D_800B64D4;

void func_8005D154(void) {
    u8 result[8];

    if (D_800B64D4 == 2) {
        CdControlB(3, 0, result);
        D_800B64D4 = 0;
    }
}

void func_8005D194(void) {
    u8 result[8];

    if (D_800B64D4 == 0) {
        CdControlB(9, 0, result);
        D_800B64D4 = 2;
    }
}

extern s16 D_800B6164;
extern u8 D_801DAA90[][4];
extern s32 D_800B5FDC;
extern s16 D_800B5EFC[3];
extern int CdControl(unsigned char com, unsigned char *param, unsigned char *result);

s32 func_8005D1D4(s16 track) {
    u8 unused[56];
    s16 t;

    D_800B6164 = t = track + 2;
    D_800B5FDC = D_801DAA90[t + 1][1] + D_801DAA90[t + 1][0] * 90 - 2;
    CdControlB(2, D_801DAA90[t], 0);
    CdControlB(0xE, (unsigned char *)5, 0);
    CdControl(3, 0, 0);
    D_800B5EFC[0] = track;
    D_800B5EFC[1] = 30;
    D_800B64D4 = 0;
    return -1;
}

typedef struct {
    s16 v;
    u8 pad2[10];
} Unk800936CA;

extern Unk800936CA D_800936CA[];
extern s16 D_800B640C;

void func_8005D2B0(void) {
    func_80071C10();
    func_8005D1D4(D_800936CA[D_800B640C].v + 8);
    func_8005D308(0x3FF);
}

typedef struct {
    u8 val0;
    u8 val1;
    u8 val2;
    u8 val3;
} CdlATV;

int CdMix(CdlATV *vol);

void func_8005D308(void) {
    CdlATV atv;

    atv.val0 = 0xFF;
    atv.val2 = 0xFF;
    atv.val3 = 0;
    atv.val1 = 0;
    CdMix(&atv);
}

extern s16 D_800B64D4;
extern s16 D_800B5F1C;
extern u8 D_800B62BC[];
extern s32 D_800B5FDC;
extern s16 D_800B6164;
extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
s32 func_8005D1D4(s16 track);

void func_8005D33C(void) {
    if (D_800B64D4 == 0 && D_800B5F1C < 0) {
        CdControlB(0x11, 0, D_800B62BC);
        D_800B5F1C = 20;
        if (D_800B62BC[5] * 90 + D_800B62BC[6] >= (u32)D_800B5FDC) {
            func_8005D1D4(D_800B6164 - 2);
        }
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005D3DC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005D5A0);

typedef struct {
    u8 pad0[0x10];
    VECTOR unk10;
    u8 pad20[0x78];
    s32 unk98;
    u8 pad9C[0x22];
    s16 unkBE;
    s16 unkC0;
} Unk8005D7AC;

extern s32 func_80020EEC(VECTOR *v);
extern s32 func_80028A48(VECTOR *a, VECTOR *b);
extern VECTOR D_801981F4;
extern void func_8004DCC4(s32 arg);
extern void func_8004DC84(s16 i, s32 v);

void func_8005D7AC(void) {
    Unk8005D7AC *p = (Unk8005D7AC *)D_800B604C->vals;

    if ((s16)func_80020EEC(&p->unk10) == 0 && func_80028A48(&p->unk10, &D_801981F4) > 0x2000) {
        func_8004DCC4(p->unk98);
        func_8004DC84(p->unkBE, p->unkC0);
        func_800728A4();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005D838);

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[4];
    s16 unkE;
    VECTOR pos;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    u8 unk28[0x10];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 pad3E[0x5A];
    u8 *obj;
    u8 pad9C[0x22];
    s16 unkBE;
    s16 unkC0;
} Unk8005DB00;

void func_8005D838(void);

void func_8005DB00(s16 x, s16 z, u8 *obj, s32 type, s16 slot) {
    s16 ang = (((s16)type >> 8) << 9) + 0x400;
    struct Task *t = func_80072768(D_801F80BC, func_8005D838, 0xC4);
    Unk8005DB00 *p;

    if (t != NULL) {
        p = (Unk8005DB00 *)t->vals;
        p->obj = obj;
        t->flags = 0x21;
        if (obj != NULL) {
            obj[4] = 0;
        }
        p->unkBE = slot;
        if (slot != -1) {
            p->unkC0 = D_800B615C[slot].unk4;
            D_800B615C[slot].unk4 = -1;
        }
        p->pos.vx = (x << 9) + 0x80;
        p->pos.vz = (z << 9) + 0x80;
        p->pos.vy = (s16)func_80028BF0(&p->pos);
        p->unk20 = 0;
        p->unk22 = ang;
        p->unk24 = 0;
        p->unkE = 0;
        p->unk38 = 0;
        p->unk3A = 0;
        p->unk3C = 0;
        p->unk8 = type & 0xFF;
        func_8006B48C(p->unk8, p->unk28);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005DC4C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005E0E8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005E75C);

typedef struct {
    SVECTOR vel[16];
    s16 ang[16];
    s16 unkA0[16];
    s16 unkC0;
    s16 unkC2[16];
    s16 unkE2[16];
    u8 pad102[2];
    s32 x;
    s32 y;
    s32 z;
} Unk8005EBB8;

void func_8005E75C();

void func_8005EBB8(VECTOR *pos) {
    struct Task *t = func_80072374(func_8005E75C, 0x114);
    Unk8005EBB8 *d;
    s16 i;

    if (t != NULL) {
        t->flags = 0x31;
        d = (Unk8005EBB8 *)t->vals;
        d->x = pos->vx;
        d->y = pos->vy + 0x300;
        d->z = pos->vz;
        d->unkC0 = -0x300;
        i = 15;
        do {
            d->vel[i].vx = func_80074910(0x200) - 0x100;
            d->vel[i].vy = func_80074910(100) - 50;
            d->vel[i].vz = func_80074910(0x200) - 0x100;
            d->ang[i] = func_80074910(0x1000) - 0x800;
            d->unkA0[i] = 0;
            d->unkC2[i] = func_80074910(20) - 10;
            d->unkE2[i] = func_80074910(20) - 10;
        } while (i--);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005ECD0);

typedef struct {
    u8 pad0[4];
    u8 unk4;
} Unk8005F694Src;

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    s16 unkC;
    s16 unkE;
    VECTOR unk10;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[2];
    s32 unk28;
    u8 pad2C[4];
    s32 unk30;
    u8 pad34[4];
    s16 unk38;
    u8 pad3A[2];
    s16 unk3C;
    u8 pad3E[0x4A];
    s16 unk88;
    u8 pad8A[4];
    s16 unk8E;
    u8 pad90[8];
    Unk8005F694Src *unk98;
    u8 pad9C[0x1A];
    s16 unkB6;
    u8 unkB8;
    u8 padB9[9];
    s16 unkC2;
} Unk8005F694;

void func_8005ECD0(void);

void func_8005F694(s16 x, s16 z, Unk8005F694Src *src) {
    struct Task *t;
    Unk8005F694 *p;

    if (D_800B61A4->unk6 >= 0x800) {
        t = func_80072768(D_801F80BC, func_8005ECD0, 0xC4);
        if (t != NULL) {
            src->unk4 = 0;
            p = (Unk8005F694 *)t->vals;
            p->unk98 = src;
            p->unk10.vx = (x << 9) + 0x100;
            p->unk10.vz = (z << 9) + 0x100;
            p->unk10.vy = (s16)func_80028BF0(&p->unk10);
            p->unk22 = 0;
            p->unk20 = 0;
            p->unk24 = 0;
            p->unk28 = 0x1E000;
            p->unk30 = 0x1E000;
            p->unk38 = 0;
            p->unk3C = 0;
            p->unk8 = 0;
            p->unkC = 0;
            p->unkE = 4;
            p->unk88 = 0;
            p->unk8E = 0;
            p->unkC2 = 0;
            p->unkB8 = 0;
            p->unkB6 = 0;
        }
    }
}

typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
} Unk8005F790;

void func_8005F790(Unk8005F790 *p) {
    if (p != (Unk8005F790 *)-1) {
        p->unk6 = (p->unk0 + p->unk2) & 3;
    }
}

extern s32 func_80028AF8(SVECTOR *v);

s16 func_8005F7BC(SVECTOR *v) {
    if (v == (SVECTOR *)-1) {
        return -1;
    }
    return func_80028AF8(v);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005F7EC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005FA0C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8005FD10);


extern Unk8015EB3C D_8018CC68;
s32 func_800691E8(Unk8015EB3C *arg0, s32 arg1);
void func_80068200(s16 id, void *pos);
void func_80068500(s32 a);

void func_8005FFCC(void *p) {
    func_80067394(p, 2);
    func_80068200(0x10, p);
    func_80068200(0x10, p);
    func_80068500(0x11);
    D_8018CC68.unk0 = 0x400;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0xFFF;
    D_8018CC68.unk6 = 0x100;
    D_8018CC68.unk8 = 0x10;
    func_800691E8(&D_8018CC68, 0);
    D_8018CC68.unk0 = 0xC00;
    D_8018CC68.unk6 = 200;
    func_800691E8(&D_8018CC68, 0);
}

int func_8006007C(int a, int b, int c) {
    int t;

    if (b <= 0) {
        t = (b * c) >> 12;
    } else {
        t = b >> 2;
    }
    return a + t;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800600A0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800606D8);

int func_800609F8(short i) {
    return *D_800B66AC[i].p - 1;
}

extern VECTOR D_801FAE04;

s16 func_80060A20(VECTOR *pos) {
    s16 dx = pos->vx - D_801FAE04.vx;
    s16 dz = pos->vz - D_801FAE04.vz;
    s16 dist = SquareRoot0(dx * dx + dz * dz);

    if (dist > 3000) {
        dist = 3000;
    }
    return 0x1000 - dist;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80060AB8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80060C38);

typedef struct {
    u8 pad0[0x4A];
    s16 unk4A;
    u8 pad4C[2];
    s16 unk4E;
    s16 unk50;
} Unk80060D44;

extern SVECTOR D_800B6594;
extern VECTOR D_80091BB8;
extern s16 D_800B638C;
void func_80048E70(VECTOR *v, SVECTOR *rot, int a, int b, void *obj);
void func_80048D54(void *obj);
void func_80060F00(VECTOR *v, int a, int b, int c, int d);

void func_80060D44(void) {
    Unk80060D44 *d = (Unk80060D44 *)D_800B604C->vals;
    VECTOR v;

    d->unk4E -= 0x20;
    if (d->unk4E < -0x834) {
        func_800728A4();
        return;
    }
    D_800B6594.vz = d->unk4E;
    D_800B6594.vy = 0;
    D_800B6594.vx = 0;
    D_800B66BC.vx = 0;
    D_800B66BC.vz = 0;
    D_800B66BC.vy = d->unk50;
    func_80028310(&D_800B66BC, &D_800B6594, &D_80091BB8, &v);
    SetRotMatrix(&D_801981D4);
    SetTransMatrix(&D_801981D4);
    func_80048830(d, d->unk4A);
    func_80048E70(&v, &D_800B66BC, 0xFFF, 0, d);
    func_80060F00(&v, d->unk4A + 0x41, 0x400, D_800B638C, -1);
    func_80048D54(d);
}

typedef struct {
    u8 pad0[0x4A];
    s16 unk4A;
    u8 pad4C[2];
    s16 unk4E;
    s16 unk50;
} Unk80060E70;

void func_80060D44(void);

void func_80060E70(s16 a, s16 b, s16 c) {
    struct Task *t = func_80072374(func_80060D44, 0x54);
    Unk80060E70 *d;

    if (t != NULL) {
        d = (Unk80060E70 *)t->vals;
        func_80048B74(d);
        func_80048C14(d, 1, 0, 0x52, 8);
        d->unk4E = b;
        d->unk50 = c;
        d->unk4A = a - 0x41;
    }
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58E8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58F0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58F8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B58FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5904);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5908);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B590C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80060F00);

void func_800616B8(u8 *rgb, s16 x, s16 z) {
    s32 dx = (x - D_801FAE04.vx) / 4;
    s32 dz = (z - D_801FAE04.vz) / 4;
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

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80061784);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80061A64);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80061E48);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80061F48);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5914);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5918);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B591C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5920);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5928);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B592C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5930);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5934);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5938);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B593C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5940);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80062048);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Unk80062B88;

extern VECTOR D_80091BB8;

void func_80062B88(void) {
    Unk80062B88 *p = (Unk80062B88 *)D_800B604C->vals;
    SVECTOR v;
    SVECTOR rot;

    v.vz = p->unk0;
    v.vy = 0;
    v.vx = 0;
    rot.vy = p->unk2;
    rot.vx = 0;
    rot.vz = 0;
    func_80028310(&rot, &v, &D_80091BB8, &D_801FAE04);
    p->unk0 += p->unk4;
    p->unk2 += p->unk6;
    if (p->unkC-- < 0) {
        p->unkC = func_80074910(0x20);
        p->unkA = func_80074910(0x80) - 0x40;
        p->unk8 = func_80074910(0x514);
    }
    p->unk6 = func_8002881C(p->unk6, p->unkA, 1);
    if (p->unk0 < p->unk8) {
        p->unk4 = func_8002881C(p->unk4, 0x40, 2);
    } else {
        p->unk4 = func_8002881C(p->unk4, -0x40, 2);
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
} Unk80063C60;
extern struct Task *D_800B604C;
extern void func_80062B88(void);

void func_80062C94(void) {
    Unk80063C60 *p = (Unk80063C60 *)D_800B604C->vals;

    p->unk0 = 0;
    p->unk8 = 0x500;
    p->unk4 = 0;
    p->unk6 = 0x20;
    p->unkC = func_80074910(0x20);
    D_800B604C->func = func_80062B88;
}

void func_80062CF4(void) {
    D_801FAE04.vx = 0;
    D_801FAE04.vy = 0;
    D_801FAE04.vz = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80062D14);

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 pad6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 padE;
} Unk80091CA8;

typedef struct {
    u8 pad0[0x174];
    u16 unk174;
    u16 unk176;
    u16 unk178;
    u8 pad17A[0x12];
    u16 unk18C;
    u16 unk18E;
    u16 unk190;
} Unk80062F80;

extern Unk80091CA8 D_80091CA8[];

void func_80062F80(Unk80062F80 *p, s16 i) {
    p->unk18C = D_80091CA8[i].unk0;
    p->unk18E = D_80091CA8[i].unk2;
    p->unk190 = D_80091CA8[i].unk4;
    p->unk174 = D_80091CA8[i].unk8;
    p->unk176 = D_80091CA8[i].unkA;
    p->unk178 = D_80091CA8[i].unkC;
}

typedef struct {
    s16 next;
    u32 score;
    char name[12];
} ScoreEntry;

typedef struct {
    ScoreEntry e[10];
    s16 free;
    s16 head;
    s16 last;
} ScoreTable;

extern char *strcpy(char *, char *);

s16 func_80063018(ScoreTable *t, u32 score, char *name) {
    ScoreEntry *e;
    s16 ret = 0;
    s16 prev = -1;
    s16 n = 9;
    s16 cur = t->head;
    s16 i;

    do {
        e = &t->e[cur];
        if (e->score <= score) {
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

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800631A8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80063580);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80063924);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Unk8002A35C;
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

typedef struct {
    u8 pad0[0x34];
    SVECTOR rot;
    u8 pad3C[0x108];
    Anim anim;
    u8 pad164[0x3C];
    s32 unk1A0;
} Unk800639C0;

extern SVECTOR D_800B6594;
extern s16 D_80091BD4;
void func_80063924();

void func_800639C0(Unk80061844 *obj) {
    Unk800639C0 *p = (Unk800639C0 *)obj;

    D_800B6594.vx = 0;
    D_800B6594.vz = 0;
    D_800B6594.vy = func_80074910(0x1000);
    D_800B66BC.vx = 0;
    D_800B66BC.vz = -0xAF0;
    D_800B66BC.vy = 0;
    func_80028310(&D_800B6594, &D_800B66BC, &D_80091BB8, (VECTOR *)p);
    p->rot.vx = 0;
    p->rot.vz = 0;
    p->rot.vy = D_800B6594.vy + 0x800;
    p->unk1A0 = 0;
    func_80048B74(&p->anim);
    func_80048C14(&p->anim, D_80091BD4, 0, 0x52, 0x10);
    func_80048830(&p->anim, (s16)func_80074910(12));
    func_80063924(p);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80063AA8);

extern Unk8003BA6C_Task *func_800724C4(void (*fn)(), s16 flags, s16 size);
extern void func_800639C0(Unk80061844 *obj);
extern void func_80063AA8(void);

void func_80063B88(void) {
    Unk8003BA6C_Task *task;

    task = func_800724C4(func_80063AA8, 3, 0x22c);
    if (task != NULL) {
        func_800639C0((Unk80061844 *)task->data);
    }
}

typedef struct {
    u8 pad0[4];
    s16 unk4;
    s16 unk6;
    u8 pad8[2];
    s16 unkA;
    s16 unkC;
    u8 padE[2];
    s16 unk10;
    s16 unk12;
    s16 unk14;
} Unk80063BC8;

void func_80063580(void);

void func_80063BC8(void) {
    Unk80063BC8 *d = (Unk80063BC8 *)D_800B604C->vals;

    d->unk4 = 0x1000;
    d->unkA = 30;
    d->unk6 = 1488;
    d->unkC = 0;
    d->unk14 = 300;
    d->unk10 = 10;
    d->unk12 = 30;
    if (D_800B64D4 == 1) {
        func_8005D2B0();
    }
    D_800B604C->func = func_80063580;
    func_80063580();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80063C4C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80063DC0);

typedef struct {
    u8 pad0[0x30];
} Unk800640A8_Anim;

typedef struct {
    VECTOR pos[6];
    SVECTOR unk60[6];
    SVECTOR rot[6];
    VECTOR out[6];
    Unk800640A8_Anim anim[6];
    s16 unk240[6];
    s16 state[6];
    s16 unk258[6];
    s16 unk264;
    s16 unk266;
    u8 pad268[2];
    s16 unk26A;
    s16 unk26C[6];
} Unk800640A8;

extern SVECTOR D_800B5960;
extern void func_80048830(void *anim, s16 idx);

void func_800640A8(Unk800640A8 *obj, s16 idx, s16 arg2) {
    SVECTOR v = D_800B5960;

    obj->pos[idx].vx = idx * 350 - 525;
    obj->pos[idx].vy = 0;
    obj->pos[idx].vz = obj->unk26A;
    obj->rot[idx].vx = 0;
    obj->rot[idx].vy = func_80074910(0x1000);
    obj->rot[idx].vz = 0;
    obj->state[idx] = 0;
    obj->unk240[idx] = func_80074910(0x800);
    obj->unk258[idx] = 0;
    func_80028310(&obj->rot[idx], &v, &obj->pos[idx], &obj->out[idx]);
    func_80048B74(&obj->anim[idx]);
    func_80048830(&obj->anim[idx], arg2);
    func_80048C14(&obj->anim[idx], 0, func_80048BD0(3), 0xA4, 8);
    obj->unk26C[idx] = arg2;
}

typedef struct {
    u8 pad0[0x264];
    s16 unk264;
    s16 unk266;
    u8 pad268[2];
    s16 unk26A;
} Unk8005EA78;
typedef struct {
    u8 pad[0x1C];
    Unk8005EA78 *data;
} Unk8005EA78_Task;

extern void func_80063DC0();
extern void func_800640A8();

s32 func_8006420C(s16 a, s16 b) {
    Unk8005EA78_Task *task;
    Unk8005EA78 *obj;
    s16 i;
    s16 n;

    task = (Unk8005EA78_Task *)func_800724C4(func_80063DC0, 9, 0x278);
    i = 3;
    if (task != NULL) {
        obj = task->data;
        obj->unk26A = a;
        while (1) {
            func_800640A8(obj, i, b);
            n = i--;
            if (n == 0) break;
        }
        obj->unk266 = 0;
        obj->unk264 = 0;
        return (s32)obj;
    }
    return 0;
}

typedef struct {
    u8 pad0[0x24C];
    s16 unk24C[4];
} Unk800642A8_Obj;

typedef struct {
    s32 unk0;
    Unk800642A8_Obj *unk4[4];
} Unk800642A8;

void func_800642A8(void) {
    Unk800642A8 *d = (Unk800642A8 *)D_800B604C->vals;
    s16 i, j;

    i = 3;
    do {
        Unk800642A8_Obj *o = d->unk4[i];
        j = 3;
        do {
            o->unk24C[j] = 5;
        } while (j--);
    } while (i--);
}

typedef struct {
    s32 pad0;
    s32 objs[4];
} Unk80064308;

s32 func_8006420C(s16 a, s16 b);

void func_80064308(s32 b) {
    Unk80064308 *d = (Unk80064308 *)D_800B604C->vals;
    s16 i = 3;

    do {
        d->objs[i] = func_8006420C((s16)(i * 350 - 525), (s16)b);
    } while (i--);
}

typedef struct {
    s16 x;
    s16 y;
} Unk800643A8;

extern void func_80061E48(s16 x, s16 y);
extern void func_80061784(void);
extern void func_8006DE64(void);
extern void func_80062D14(void);
extern s16 D_800B6554;

void func_800643A8(void) {
    Unk800643A8 *p = (Unk800643A8 *)D_800B604C->vals;

    func_80061E48(p->x, p->y);
    p->x += 8;
    p->y += 0x40;
    func_80061784();
    func_8006DE64();
    if (D_800B5D5C == 6) {
        if (D_800B6554 == 1 || D_800B6554 == 4) {
            func_80072A40(8);
            D_800B604C->func = func_80062D14;
        } else {
            func_80026710(0x14);
            D_800B5FB4 = 0;
            func_80072A40(8);
            func_800728A4();
        }
    }
}

void func_80064478(void) {
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5950);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5958);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5960);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5968);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B596C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5970);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5974);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80064480);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80064884);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80064A7C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80064CD8);

typedef struct {
    u8 c[4];
} Color4;

typedef struct {
    u8 pad0[0x2A];
    s16 unk2A;
    u8 pad2C[0x1E];
    s16 unk4A;
} Unk80064E40;

extern Color4 D_800B5980;
extern Color4 D_800B5984;
extern s16 D_800B56A2;

void func_80064E40(Unk80064E40 *p) {
    Color4 top = D_800B5980;
    Color4 bottom = D_800B5984;

    if (p->unk4A >= 0x30) {
        p->unk4A -= D_800B56A2 * 32;
        if (p->unk4A >= 0x30) {
            func_8007633C(160, 127, p->unk2A, (0x3E8000 / p->unk4A) * 0xA00 >> 12, 0xAF000 / p->unk4A, top.c, bottom.c);
        }
    }
}

typedef struct {
    u8 pad0[0x38];
    s32 value;
} Unk80064F68;

extern Color4 D_800B5988;
extern Color4 D_800B598C;
extern Color4 D_800B5970;
extern Color4 D_800B5974;
extern char D_800B5638[];
extern char *func_80077DC8(char *);
extern void func_800758C0(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);
extern void func_8007633C(s32 x, s32 y, s32 value, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_80064F68(Unk80064F68 *p) {
    Color4 top1 = D_800B5988;
    Color4 bottom1 = D_800B598C;
    Color4 top2 = D_800B5970;
    Color4 bottom2 = D_800B5974;

    func_800758C0(90, 190, func_80077DC8(D_800B5638), 0xC00, 1280, top1.c, bottom1.c);
    func_8007633C(228, 188, p->value, 0xC00, 1280, top2.c, bottom2.c);
}

typedef struct {
    u8 pad0[0x38];
    u32 unk38;
    u32 unk3C;
} Unk8005F880;

void func_80065060(Unk8005F880 *arg0) {
    if (arg0->unk38 != 0) {
        if (arg0->unk38 < arg0->unk3C) {
            func_8006DE2C(arg0->unk38);
            arg0->unk38 = 0;
        } else {
            func_8006DE2C(arg0->unk3C);
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

void func_800650D0(Unk8005F8F0 *obj) {
    obj->unk38 = obj->unk2A * obj->unk46;
    obj->unk3C = obj->unk38 >> 5;
    if (obj->unk3C == 0) {
        obj->unk3C = 1;
    }
}

extern s32 D_800B5F64;
extern char D_80091B14[];
extern u8 D_800B56D0[];
extern u8 D_800B56D8[];

void func_8006510C(void) {
    if (D_800B5F64 & 8) {
        func_800758C0(160, 211, func_80077DC8(D_80091B14), 0x320, 0x12C, D_800B56D8, D_800B56D0);
    }
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5980);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5984);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5988);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B598C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5990);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5994);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5998);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80065178);

typedef struct {
    u32 tag;
    u32 code[2];
} DR_MODE;

extern u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
extern void SetDrawMode(DR_MODE *p, s32 dfe, s32 dtd, s32 tpage, void *tw);

void func_8006595C(u8 c) {
    TILE *t = D_800B63AC;
    DR_MODE *m;

    t->x0 = 0;
    t->y0 = 0;
    t->w = 0x1FF;
    t->h = 0x100;
    SetTile(t);
    t->r0 = c;
    t->g0 = c;
    t->b0 = c;
    SetSemiTrans(t, 1);
    AddPrim(D_800B62CC + 1, t++);
    m = (DR_MODE *)t;
    SetDrawMode(m, 1, 1, GetTPage(0, 2, 0, 0), 0);
    AddPrim(D_800B62CC + 1, m);
    D_800B63AC = m + 1;
}

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80060168;

extern void func_800728A4(void);
extern void func_8006595C(u8 shade);

void func_80065A28(void) {
    Unk80060168 *obj = (Unk80060168 *)D_800B604C->vals;

    func_8006595C(obj->unk32);
    obj->unk32 -= 0x20;
    if (obj->unk32 < 0) {
        func_800728A4();
    }
}

void func_80065A28(void);

void func_80065A84(void) {
    ((Unk80060200 *)D_800B604C->vals)->unk32 = 0xFF;
    D_800B604C->func = func_80065A28;
    func_80065A28();
}

extern void *D_800B63AC;
extern u8 *D_800B6334;
extern u32 *D_800B62CC;
extern s16 D_800B5FB4;
extern void SetTile(TILE *p);
extern void AddPrim(void *ot, void *p);
extern void func_800728A4(void);

void func_80065AC0(void) {
    Unk80060200 *data = (Unk80060200 *)D_800B604C->vals;
    TILE *tile = D_800B63AC;
    s16 w, h;

    if ((u32)((u8 *)tile - D_800B6334) > 0xD7EF) {
        func_8005D108();
        D_800B5FB4 = 2;
        func_800728A4();
        return;
    }
    data->unk32 += 0x100;
    w = func_80071B7C(0, D_800B636C / 2, data->unk32);
    h = func_80071B7C(0, D_800B645C / 2, data->unk32);
    tile->w = w * 2;
    tile->h = h * 2;
    tile->x0 = D_800B636C / 2 - w;
    tile->y0 = D_800B645C / 2 - h;
    SetTile(tile);
    tile->r0 = 0;
    tile->g0 = 0;
    tile->b0 = 0;
    AddPrim(D_800B62CC + 1, tile);
    D_800B63AC = tile + 1;
    if (data->unk32 > 0x1068) {
        D_800B5FB4 = 2;
    }
}

extern void func_80065AC0(void);

void func_80065C2C(void) {
    ((Unk80060200 *)D_800B604C->vals)->unk32 = 0;
    D_800B604C->func = func_80065AC0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80065C54);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80066030);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 padC;
    s16 size[32];
    s16 rotA[32];
    s16 life[32];
    s16 velX[32];
    s16 velY[32];
    s16 velZ[32];
    s16 rotB[32];
    s16 spin[32];
    s16 unk210;
    s16 unk212;
    s16 unk214;
} Unk8006661C;

extern void func_80066030();

void func_8006661C(VECTOR *pos) {
    Unk8003BA6C_Task *t = func_800724C4(func_80066030, 3, 0x218);
    Unk8006661C *d;
    s16 i = 3;

    if (t != NULL) {
        d = (Unk8006661C *)t->data;
        d->unk210 = 0;
        d->unk214 = 0x140;
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
        do {
            d->size[i] = func_80074910(0x10) + 0x10;
            d->rotA[i] = func_80074910(0x1000);
            d->rotB[i] = func_80074910(0x1000);
            d->spin[i] = func_80074910(0x40) - 0x20;
            d->life[i] = func_80074910(4) + 6;
            d->velX[i] = func_80074910(0x40) - 0x20;
            d->velY[i] = func_80074910(0x30) + 0x20;
            d->velZ[i] = func_80074910(2) + 1;
        } while (i--);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80066730);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800669C0);

extern s16 D_801F76F8;
extern volatile s16 D_800B5FFC;

void func_80066B1C(s32 v) {
    if (*(s16 *)&D_800B5FFC != 1) {
        D_801F76F8 = v;
    } else {
        D_801F76F8 = v / 2;
    }
}

extern SpuVoiceAttr D_801F76E4;
extern SpuVolume D_801FA254[];

void func_80066B58(s32 left, s32 right, s16 voice) {
    if (D_800B6614->unk178C != 0) {
        left = (left + right) >> 1;
        D_801F76E4.volume.left = (left * D_800B6614->unk1786) >> 12;
        D_801F76E4.volume.right = (left * D_800B6614->unk1786) >> 12;
    } else {
        D_801F76E4.volume.left = (left * D_800B6614->unk1786) >> 12;
        D_801F76E4.volume.right = (right * D_800B6614->unk1786) >> 12;
    }
    D_801FA254[voice].left = D_801F76E4.volume.left;
    D_801FA254[voice].right = D_801F76E4.volume.right;
}

extern SpuVoiceAttr D_801F76E4;

void func_80066C30(void) {
    D_801F76E4.volume.left = 0;
    D_801F76E4.volume.right = 0;
    D_801F76E4.mask = 3;
    D_801F76E4.voice = 0xFFFFFF;
    SpuSetVoiceAttr(&D_801F76E4);
}

extern SpuVoiceAttr D_801F6CB0;
extern SpuVolume D_801FA254[];

void func_80066C7C(void) {
    s16 i = 23;

    do {
        D_801F76E4.volume.left = D_801FA254[i].left;
        D_801F76E4.volume.right = D_801FA254[i].right;
        D_801F76E4.mask = 3;
        D_801F76E4.voice = 1 << i;
        SpuSetVoiceAttr(&D_801F76E4);
    } while (i-- != 0);
}

void func_8006902C();

void func_80066D18(s16 id) {
    s32 unused[2];

    D_8018CC68.unk0 = 0x800;
    D_8018CC68.unk10 = func_80074910(0x40) + 0x40;
    D_8018CC68.unk2 = 5;
    D_8018CC68.unk4 = 3000;
    D_8018CC68.unk12 = 100;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk14 = -func_80074910(3) - 3;
    D_8018CC68.unk8 = id;
    func_800691E8(&D_8018CC68, (s32)func_8006902C);
    D_8018CC68.unk10 = -func_80074910(0x40) - 0x40;
    D_8018CC68.unk14 = -func_80074910(3) - 3;
    D_8018CC68.unk8 = id;
    func_800691E8(&D_8018CC68, (s32)func_8006902C);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80066E0C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800670B8);

void func_80067210(void) {
    D_800B6374 = func_80074910(4) + 0x24;
}

void func_8006723C(void) {
    D_800B6374 = func_80074910(4) + 0x20;
}

void func_80067268(void) {
    if (D_800B604C->unk14-- < 0) {
        D_800B6374 = func_80074910(4) + 0x20;
        func_800728A4();
    }
}

void func_80067268(void);

void func_800672BC(void) {
    D_800B5EFC[0] = func_80074910(20) + 30;
    func_80072374(func_80067268, 0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800672F8);

void func_8006738C(void) {
}

extern s16 D_800B64E4;
s16 func_800672F8();
void func_800683FC(s16 id, void *pos);

void func_80067394(void *p, s16 arg) {
    if (D_800B64E4 == 0) {
        func_800683FC(func_800672F8(1), p);
    } else if (D_800B61A4->unk0 == 5) {
        func_80068200(func_800672F8(1), p);
        func_8006862C(5);
        func_80068500(func_800672F8(1));
    } else {
        func_80068200(func_800672F8(1), p);
        func_800683FC(func_800672F8(1), &D_800B659C->unk50);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067470);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800675D8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067630);

extern s16 D_800B5736;
extern s16 D_800B5738;
extern s16 D_800B65BC;

void func_8006772C(void) {
    D_800B5736 = 1;
    D_800B5738 = 0x226;
    D_800B65BC = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067754);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067CA8);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067DEC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80067F3C);

extern s16 D_800B622C;

void func_800681F0(void) {
    D_800B622C = 0;
}

extern s16 D_800B5D34;
extern s16 D_800B63DC;

void func_80068200(s16 id, void *pos) {
    u8 unused[8];
    s32 dist = func_80028A48(pos, &D_801981F4);

    if (dist < 0x2001) {
        s32 ang = func_80028648(&D_801981F4, pos);

        D_800B5D34 = (D_80094174[((u16)D_800B6126 + ang) & 0xFFF] + 0x1000) >> 1;
        D_800B63DC = func_80071B7C(0x3FFF, 0, dist / 2);
        D_8018CC68.unk0 = D_800B5D34;
        D_8018CC68.unk2 = 0;
        D_8018CC68.unk4 = D_800B63DC;
        D_8018CC68.unk6 = func_80074910(0x100) + 0x400;
        D_8018CC68.unk8 = id;
        func_800691E8(&D_8018CC68, 0);
    }
}

extern s16 D_800B5D34;
extern s16 D_800B63DC;

void func_80068304(s16 id, VECTOR *pos) {
    u8 unused[8];
    s32 dist = func_80028A48(pos, &D_801981F4);

    if (dist < 0x2001) {
        s32 ang = func_80028648(&D_801981F4, pos);

        D_800B5D34 = (D_80094174[((u16)D_800B6126 + ang) & 0xFFF] + 0x1000) >> 1;
        D_800B63DC = func_80071B7C(0x3FFF, 0, dist / 2);
        D_8018CC68.unk0 = D_800B5D34;
        D_8018CC68.unk2 = 0;
        D_8018CC68.unk4 = D_800B63DC;
        D_8018CC68.unk6 = 0x400;
        D_8018CC68.unk8 = id;
        func_800691E8(&D_8018CC68, 0);
    }
}

void func_800683FC(s16 id, void *pos) {
    u8 unused[8];
    s32 dist = func_80028A48(pos, &D_801981F4);

    if (dist < 0x2001) {
        s32 ang = func_80028648(&D_801981F4, pos);

        D_800B5D34 = (D_80094174[((u16)D_800B6126 + ang) & 0xFFF] + 0x1000) >> 1;
        D_800B63DC = func_80071B7C(0x3FFF, 0, dist / 2);
        D_8018CC68.unk0 = D_800B5D34;
        D_8018CC68.unk2 = 0;
        D_8018CC68.unk4 = D_800B63DC;
        D_8018CC68.unk6 = func_80074910(0x100) + 0x400;
        D_8018CC68.unk8 = id;
        func_800691E8(&D_8018CC68, 0);
    }
}

void func_80068500(s32 id) {
    u8 unused[8];
    s32 d;

    D_8018CC68.unk0 = 0;
    D_8018CC68.unk2 = 10;
    D_8018CC68.unk4 = 0x3FFF;
    D_8018CC68.unk6 = func_80074910(100) + 0x400;
    D_8018CC68.unk8 = id;
    func_800691E8(&D_8018CC68, 0);
    D_8018CC68.unk0 = 0x1000;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0x3FFF;
    d = func_80074910(0x20) - 0x10;
    D_8018CC68.unk6 += d;
    func_800691E8(&D_8018CC68, 0);
}

void func_800685C0(s16 arg0, s16 arg1, s16 arg2) {
    s32 unused[2];

    D_8018CC68.unk0 = arg2;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = arg1;
    D_8018CC68.unk6 = func_80074910(100) + 0x400;
    D_8018CC68.unk8 = arg0;
    func_800691E8(&D_8018CC68, 0);
}

void func_8006862C(s16 arg0) {
    s32 unused[2];

    D_8018CC68.unk0 = 0x800;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0x3FFF;
    D_8018CC68.unk6 = func_80074910(0x80) + 0x400;
    D_8018CC68.unk8 = arg0;
    func_800691E8(&D_8018CC68, 0);
}

void func_80067DEC();

void func_800686A0(s16 id, VECTOR *pos, s16 arg2) {
    u8 unused[8];
    s16 dist = func_80028A48(pos, &D_801981F4);

    if (dist < 0x2001) {
        s32 ang = func_80028648(&D_801981F4, pos);
        s16 pan = (D_80094174[((u16)D_800B6126 + ang) & 0xFFF] + 0x1000) >> 1;
        s16 vol = func_80071B7C(0x3FFF, 0, dist / 2);

        D_8018CC68.unk0 = pan;
        D_8018CC68.unk2 = 0;
        D_8018CC68.unk4 = vol;
        D_8018CC68.unk6 = func_80074910(0x200) + 0x300;
        D_8018CC68.unk8 = id;
        D_8018CC68.unk16 = arg2;
        func_800691E8(&D_8018CC68, (s32)func_80067DEC);
    }
}

void func_800687A8(id)
s16 id;
{
    s32 unused[2];
    s16 i = 3;

    do {
        D_8018CC68.unk0 = (i << 12) / 3;
        D_8018CC68.unk2 = 0;
        D_8018CC68.unk4 = 0x3FFF;
        D_8018CC68.unk6 = func_80074910(0x200) + 0x300;
        D_8018CC68.unk8 = id;
        func_800691E8(&D_8018CC68, 0);
    } while (i--);
    D_8018CC68.unk0 = 0x800;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0x3FFF;
    D_8018CC68.unk6 = 0x100;
    D_8018CC68.unk8 = id;
    func_800691E8(&D_8018CC68, 0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006889C);

void func_8006899C(s32 n) {
    u8 unused[8];

    D_800B64CC = n;
}

void func_8006889C(void);

void func_800689B0(void) {
    D_8018CC68.unk0 = 0x200;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk8 = 5;
    D_8018CC68.unk18 = 200;
    D_8018CC68.unk19 = 120;
    D_8018CC68.unk1A = 80;
    D_800B64CC = 0;
    func_800691E8(&D_8018CC68, (s32)func_8006889C);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80068A3C);

void func_80068B34(s32 n) {
    u8 unused[8];

    D_800B6374 = n;
}

void func_80068A3C(void);

void func_80068B48(void) {
    D_8018CC68.unk0 = 0x200;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk8 = 5;
    D_8018CC68.unk18 = 80;
    D_8018CC68.unk19 = 30;
    D_8018CC68.unk1A = 10;
    D_800B6374 = 0;
    func_800691E8(&D_8018CC68, (s32)func_80068A3C);
}

typedef struct {
    u32 unk0;
    u8 pad4[0x14];
    s32 unk18;
    u8 pad1C[0xC];
} Unk801DA6DC;

extern Unk801DA6DC D_801DA6DC[];
extern SpuVoiceAttr D_801F76E4;
extern void func_80066B58(s32 left, s32 right, s16 voice);

void func_80068BD4(s16 voice) {
    s32 bit;

    D_801DA6DC[voice].unk18 = 0;
    D_801DA6DC[voice].unk0 = -1;
    func_80066B58(0, 0, voice);
    D_801F76E4.mask = 3;
    bit = 1 << voice;
    D_801F76E4.voice = bit;
    SpuSetVoiceAttr(&D_801F76E4);
    SpuSetKey(0, bit);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80068C70);

extern u32 D_800B621C;
void SpuSetKey(long on_off, unsigned long voice_bit);

void func_80068DCC(void) {
    SpuSetKey(1, D_800B621C);
    D_800B621C = 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80068DFC);

void func_80068EE0(s16 voice) {
    s16 status = SpuGetKeyStatus(1 << voice);

    if (D_801DA6DC[voice].unk0 >= 6 && (status == 0 || status == 3)) {
        func_80068BD4(voice);
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 padA;
    u32 unkC;
    u8 pad10[0x18];
} Unk801DA6D0;

extern Unk801DA6D0 D_801DA6D0[];

void func_80068F58(s16 voice) {
    Unk801DA6D0 s;
    Unk801DA6D0 *e = &D_801DA6D0[voice];

    if (e->unkC == 8 && e->unk4 > 0x100) {
        s.unk0 = 0x1000 - e->unk0;
        s.unk2 = e->unk2;
        s.unk4 = e->unk4 >> 1;
        s.unk6 = e->unk6;
        s.unk8 = e->unk8;
        func_800691E8((Unk8015EB3C *)&s, (s32)func_80068F58);
    } else if (e->unkC > 8) {
        func_80068EE0(voice);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006902C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800691E8);

void func_80069590(s32 vol, s32 pan) {
    SpuCommonAttr attr;
    s32 d = (vol * pan) >> 14;

    attr.mask = 0x3;
    attr.mvol.left = vol - d;
    attr.mvol.right = vol + d;
    SpuSetCommonAttr(&attr);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800695DC);

typedef struct {
    u8 pad0[8];
    s32 offset;
    u8 padC[0x2C];
} Unk800697A8_Entry;

typedef struct {
    s32 count;
    s32 size;
    Unk800697A8_Entry entries[1];
} Unk800697A8;

extern int printf(const char *fmt, ...);
extern char D_80086F1C[];
extern s32 D_801FA0C4[];

s32 func_800697A8(s32 base, Unk800697A8 *bank) {
    s32 count = bank->count;
    Unk800697A8_Entry *e = bank->entries;
    u8 *data = (u8 *)(e + count);
    s32 addr = SpuMalloc(bank->size);
    s32 i;

    if (addr == -1) {
        printf(D_80086F1C);
    } else {
        SpuSetTransferStartAddr(addr);
        SpuRead(data, bank->size);
        for (i = count - 1; i != -1; i--) {
            D_801FA0C4[base++] = addr + e->offset;
            e++;
        }
    }
    return addr;
}

void func_80069894(void) {
    D_8018CC68.unk0 = 0x800;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0x3000;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk8 = 0x48;
    func_800691E8(&D_8018CC68, 0);
}

void func_800698F0(void) {
    D_8018CC68.unk0 = 0x800;
    D_8018CC68.unk2 = 0;
    D_8018CC68.unk4 = 0x3000;
    D_8018CC68.unk6 = 0x400;
    D_8018CC68.unk8 = func_80074910(20) + 20;
    func_800691E8(&D_8018CC68, 0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006995C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80069B48);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80069F1C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006A368);

typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    s32 pad2C;
    s32 unk30;
    u8 pad34[0x24];
    Unk800451B4Src *unk58;
    VECTOR unk5C;
    u8 pad6C[0x40];
    s16 unkAC;
    s16 unkAE;
    s16 unkB0;
    s16 padB2;
    s16 unkB4;
    s16 unkB6;
    s16 unkB8;
} Unk8006A638;

extern s16 D_800B61DC;
void func_8006A368(void);

void func_8006A638(s16 x, s16 z, Unk800451B4Src *src) {
    struct Task *t;
    Unk8006A638 *p;

    if (D_800B61DC == 0) {
        t = func_80072374(func_8006A368, 0xBC);
        if (t != NULL) {
            src->unk4 = 0;
            t->flags = 0x21;
            p = (Unk8006A638 *)t->vals;
            p->unkB8 = -1;
            p->unk58 = src;
            p->unk28 = 0x12C000;
            p->unk30 = 0x2BC000;
            p->unk5C.vx = x << 9;
            p->unk5C.vz = z << 9;
            p->unkAE = func_80028BF0(&p->unk5C);
            p->unk5C.vy = (s16)func_80028BF0(&p->unk5C) + 0xFD0;
            p->unkAC = 0;
            p->unkB4 = -1;
            p->unkB6 = 0;
            p->unkB0 = 0;
        }
    }
}

extern s16 D_8018CC90[];
extern s16 D_8018CB68[];

void func_8006A728(void) {
    s16 i = 0x7F;

    do {
        D_8018CC90[i] = func_80074910(0x200) + 0x100;
        D_8018CB68[i] = func_80074910(0xFFF);
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006A7A4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006AB3C);

typedef struct {
    u8 pad0[0x80];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    u8 pad8C[8];
    s32 unk94[16];
    s16 unkD4[16];
    s16 unkF4[16];
    s16 unk114[16];
    s16 unk134[16];
    s16 unk154[16];
    s16 unk174[16];
    s16 unk194[16];
    s16 unk1B4[16];
    s16 unk1D4;
    s16 unk1D6;
    s16 unk1D8;
    s16 unk1DA;
    s16 unk1DC;
} Unk8006B170;

void func_8006AB3C();

void func_8006B170(SVECTOR *pos) {
    struct Task *t = func_80072768(D_801F80B0[0], func_8006AB3C, 0x1E0);
    Unk8006B170 *d;
    s16 i;
    s16 r;
    s32 j;
    s32 x;

    if (t != NULL) {
        t->flags = 3;
        d = (Unk8006B170 *)t->vals;
        d->unk80 = pos->vx;
        d->unk84 = pos->vy;
        d->unk88 = pos->vz;
        i = 15;
        do {
            r = func_80074910(0x1000);
            x = func_80071B7C(0x32, 0x32, r);
            j = i;
            d->unk94[j] = x;
            d->unk174[j] = 1;
            d->unk1DA = 0xC;
            d->unkF4[j] = 0x100;
            d->unk154[j] = func_80071B7C(6, 10, r);
            d->unkD4[j] = j << 8;
            d->unk114[j] = 0xF0;
            d->unk194[j] = func_80074910(0x1000);
            d->unk1B4[j] = func_80074910(10) + 10;
            d->unk1D4 = 9;
            d->unk1DC = 2;
        } while (i--);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006B2B4);

void func_8006B424(void) {
}

void func_8006B42C(void) {
}

void func_8006B434(void) {
}

void func_8006B43C(void) {
}

void func_8006B444(void) {
}

void func_8006B44C(void) {
}

void func_8006B454(void) {
}

void func_8006B45C(void) {
}

void func_8006B464(void) {
}

void func_8006B46C(void) {
}

void func_8006B474(void) {
}

void func_8006B47C(void) {
}

void func_8006B484(void) {
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006B48C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006B670);

typedef struct {
    u8 pad0[0x10];
    s32 x;
    s32 y;
    s32 z;
} Unk8006CB7CParent;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    u8 padC[0x184];
    u8 unk190[16];
    u8 pad1A0[0x10];
    u8 unk1B0[16];
    u8 pad1C0[0x10];
    s16 unk1D0;
    s16 unk1D2;
    struct Task *parent;
    s32 parentId;
    s16 unk1DC;
} Unk8006BCF8;

void func_8006B670(void);

void func_8006BCF8(struct Task *parent, s32 arg1) {
    struct Task *t;
    Unk8006BCF8 *p;
    Unk8006CB7CParent *q;
    s16 i;

    t = func_80072768(parent, func_8006B670, 0x1E0);
    i = 15;
    if (t != NULL) {
        p = (Unk8006BCF8 *)t->vals;
        p->parent = parent;
        p->parentId = parent->id;
        p->unk1D2 = arg1;
        t->flags = 0x31;
        do {
            p->unk190[i] = 0;
            p->unk1B0[i] = func_80074910(0x1000);
        } while (i--);
        p->unk1D0 = 0;
        p->unk1DC = 0;
        q = (Unk8006CB7CParent *)parent->vals;
        p->x = q->x;
        p->y = q->y;
        p->z = q->z;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006BDD0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006C3E8);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    u8 padC[4];
    s16 unk10;
    s16 pad12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x204];
    s16 unk224;
    s16 unk226[16];
    s16 unk246;
    s16 unk248;
    s16 pad24A;
    s16 unk24C;
    s16 unk24E;
    s16 unk250;
    u8 pad252[0x22];
    struct Task *parent;
    s32 parentId;
} Unk8006CB7C;

extern void func_8006BDD0(void);

void func_8006CB7C(struct Task *parent, s32 arg1) {
    struct Task *t;
    Unk8006CB7C *p;
    Unk8006CB7CParent *q;
    s16 i;

    t = func_80072768(parent, func_8006BDD0, 0x27C);
    if (t != NULL) {
        p = (Unk8006CB7C *)t->vals;
        t->flags = 0x31;
        p->parent = parent;
        p->parentId = parent->id;
        p->unk248 = arg1;
        i = 15;
        do {
            p->unk226[i] = 0;
        } while (i--);
        p->unk246 = 0;
        p->unk224 = 0;
        p->unk10 = 0x263;
        p->unk24C = 0;
        p->unk24E = 8;
        q = (Unk8006CB7CParent *)parent->vals;
        p->x = q->x;
        p->y = q->y;
        p->z = q->z;
    }
}

void func_8006CC48(struct Task *parent, s32 arg1) {
    struct Task *t;
    Unk8006CB7C *p;
    Unk8006CB7CParent *q;
    s16 i;

    t = func_80072768(parent, func_8006BDD0, 0x27C);
    if (t != NULL) {
        p = (Unk8006CB7C *)t->vals;
        t->flags = 0x31;
        p->parent = parent;
        p->parentId = parent->id;
        p->unk248 = arg1;
        i = 15;
        do {
            p->unk226[i] = 0;
        } while (i--);
        p->unk246 = 0;
        p->unk224 = 0;
        p->unk10 = 0x242;
        p->unk24C = 0x20;
        p->unk24E = 0x10;
        q = (Unk8006CB7CParent *)parent->vals;
        p->x = q->x;
        p->y = q->y;
        p->z = q->z;
    }
}

void func_8006C3E8(void);

void func_8006CD18(struct Task *parent, s32 arg1) {
    struct Task *t;
    Unk8006CB7C *p;
    Unk8006CB7CParent *q;
    s16 i;

    if (D_800B66DC != 4 && D_800B66DC != 10) {
        t = func_80072768(parent, func_8006C3E8, 0x27C);
        if (t != NULL) {
            p = (Unk8006CB7C *)t->vals;
            t->flags = 0x31;
            p->parent = parent;
            p->parentId = parent->id;
            p->unk248 = arg1;
            i = 15;
            do {
                p->unk226[i] = 0;
            } while (i--);
            p->unk246 = 0;
            p->unk224 = 0;
            p->unk250 = 0;
            p->unk10 = 0x28;
            q = (Unk8006CB7CParent *)parent->vals;
            p->x = q->x;
            p->y = q->y;
            p->z = q->z;
            p->unk18 = p->y;
            p->unk14 = p->x;
            p->unk1C = p->z;
        }
    }
}

void func_8006C3E8(void);

void func_8006CE0C(struct Task *parent, s32 arg1) {
    struct Task *t;
    Unk8006CB7C *p;
    Unk8006CB7CParent *q;
    s16 i;

    t = func_80072768(parent, func_8006C3E8, 0x27C);
    if (t != NULL) {
        p = (Unk8006CB7C *)t->vals;
        t->flags = 0x31;
        p->parent = parent;
        p->parentId = parent->id;
        p->unk248 = arg1;
        i = 15;
        do {
            p->unk226[i] = 0;
        } while (i--);
        p->unk246 = 0;
        p->unk224 = 0;
        p->unk250 = 0;
        p->unk10 = 0x5528;
        q = (Unk8006CB7CParent *)parent->vals;
        p->x = q->x;
        p->y = q->y;
        p->z = q->z;
        p->unk18 = p->y;
        p->unk14 = p->x;
        p->unk1C = p->z;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006CEE4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006D474);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006D6A4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006D908);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006D988);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0x102];
    s16 unk108;
} Unk8006DAF4;

void func_8006D908(s16 i);
void func_8006D988(void);

void func_8006DAF4(void) {
    Unk8006DAF4 *d = (Unk8006DAF4 *)D_800B604C->vals;
    s16 i = 0x1F;

    d->unk0 = 0x1002;
    d->unk2 = 0xD90;
    d->unk4 = -0x2000;
    d->unk108 = 0;
    do {
        func_8006D908(i);
    } while (i--);
    D_800B604C->func = func_8006D988;
}

typedef struct {
    s16 vx;
    s16 vy;
} DVECTOR;

void func_8006DB6C(DVECTOR *p) {
    s16 dx = 0xA0 - p->vx;
    s16 dy = 0x78 - p->vy;

    SquareRoot0(dx * dx + dy * dy);
    if (p->vy < -0x100) {
        p->vy = -0x100;
    }
    if (p->vx < -0x80) {
        p->vx = -0x80;
    }
    if (p->vx > 0x280) {
        p->vx = 0x280;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006DC1C);

extern s32 D_800B5EDC;
extern s32 D_800B6274;

void func_8006DE04(s32 n) {
    D_800B6274 = 0x1000;
    D_800B5EDC += n;
}

extern s32 D_800B5CD0;

void func_8006DE2C(s32 delta) {
    delta += D_800B5CD0;
    if (delta < 0) {
        D_800B5CD0 = 0;
    } else {
        D_800B5CD0 = delta;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006DE64);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006E128);

void func_8006E128(void);

void func_8006E2C4(void) {
    D_800B5EFC[0] = 0;
    func_80072374(func_8006E128, 4);
}

extern s16 D_800936DC;
extern s16 D_800B6554;

void func_8006E2F4(void) {
    D_800B61A4->unk1A = D_800B61A4->unk1A == 0;
    if (D_800B61A4->unk1A) {
        D_800B66DC = -1;
        D_800B6504 = D_800936DC;
        func_800728A4();
        D_800B6554 = 3;
    }
}

void func_8003C214(void);

void func_8006E358(void) {
    if (D_800B61A4->unk18 == 0) {
        func_80072374(func_8003C214, 0);
    }
    D_800B61A4->unk18 = D_800B61A4->unk18 == 0;
}

extern Unk800B61A4 *D_800B61A4;

void func_8006E3B0(void) {
    D_800B61A4->unk14 = D_800B61A4->unk14 == 0;
}

extern volatile s16 D_800B5FFC;

void func_8006E3D0(void) {
    D_800B5FFC = 1;
}

void func_80071A98(void);

void func_8006E3E4(void) {
    if (D_800B61A4->unk16 == 0) {
        D_800B5EFC[0] = 0x20;
        D_800B5EFC[1] = 4;
        D_800B5EFC[2] = 5;
        func_80072374(func_80071A98, 0x20);
        D_800B5EFC[0] = -0x20;
        D_800B5EFC[1] = 6;
        D_800B5EFC[2] = 6;
        func_80072374(func_80071A98, 0x20);
    }
    D_800B61A4->unk16 = !D_800B61A4->unk16;
}

void func_8002CF80(void);

void func_8006E494(void) {
    func_80072374(func_8002CF80, 0x100);
}

void func_8006E4BC(void) {
    D_800B61A4->unkC = 1;
}

void func_8006E4D0(void) {
    D_800B61A4->unk12 = D_800B61A4->unk12 == 0;
}

void func_8006E4F0(void) {
    D_800B61A4->unk2 = D_800B61A4->unk2 == 0;
}

void func_8006E510(void) {
    D_800B61A4->unkA = D_800B61A4->unkA == 0;
}

extern SVECTOR D_80091DE4;

void func_8006E530(void) {
    D_80091DE4.vx = func_80074910(0x2000) + 0x1000;
    D_80091DE4.vy = func_80074910(0x3000);
    D_80091DE4.vz = func_80074910(0x2000);
}

extern volatile s16 D_800B61AC;

void func_8006E57C(void) {
    D_800B61AC = 999;
}

extern s16 D_800B571A;

void func_8006E590(void) {
    D_800B571A = !D_800B571A;
}

void func_8006E5B0(void) {
    D_800B61A4->unkE = D_800B61A4->unkE == 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006E5D0);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006E6B4);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006E6F8);

extern s16 D_800B6454;
extern s16 D_800B5E84;
extern s16 D_800B62A4;
void func_80072A40(s16 mask);
void func_800555EC(void);
void func_80068C70(void);
void func_8004E1E4(void);
void func_80050DFC(void);
void func_800221C8(void);
void func_8001F86C(void);

void func_8006E984(void) {
    D_800B6454 = 0;
    D_800B5E84 = 0;
    D_800B62A4 = 0;
    func_80072A40(0x20);
    func_800555EC();
    func_80068C70();
    func_8004E1E4();
    func_80050DFC();
    func_800221C8();
    func_8001F86C();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006E9EC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006EC34);

typedef struct {
    u8 pad0[0xF8];
    s16 unkF8;
} Unk8006ED28;

extern s16 D_800B5DD4;
void func_8006EC34(s16);
extern void func_800728A4(void);

void func_8006ED28(void) {
    Unk8006ED28 *obj = (Unk8006ED28 *)D_800B604C->vals;

    D_800B5DD4 = 0;
    func_8006EC34(obj->unkF8);
    obj->unkF8 -= 8;
    if (obj->unkF8 < 0) {
        func_800728A4();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006ED8C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006F7DC);

extern s16 D_800B571A;
extern s16 D_800B6304;

void func_8006F8FC(char *text) {
    if (D_800B571A != 0) {
        func_800758C0(160, D_800B6304, text, 0x400, 0x200, D_800B56D0, D_800B56D8);
        D_800B6304 += 20;
    }
}

void func_8006F970(s32 value) {
    if (D_800B571A != 0) {
        func_8007633C(160, D_800B6304, value, 0x400, 0x200, D_800B56D0, D_800B56D8);
        D_800B6304 += 20;
    }
}

void func_8006F9E4(void) {
}

extern volatile s16 D_800B5F44;

void func_8006F9EC(void) {
    D_800B5F44 = 270;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006FA00);

extern u8 D_801985C4[];

void func_8006FBB0(void) {
    u8 *src = D_800B6614->maps[D_800B6614->unk1780];
    u8 *dst = D_801985C4;
    s16 i = 0x2EF;

    do {
        dst[i] = src[i];
    } while (i-- != 0);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8006FC14);

extern u8 D_801985C4[];

void func_8006FCD0(void) {
    u8 *src = D_801985C4;
    u8 *dst = (u8 *)D_800B6614 + D_800B6614->unk1780 * 0x2F0;
    s16 i;

    i = 0x2EF;
    do {
        dst[i] = src[i];
    } while (i--);
    D_800B61A4 = (Unk800B61A4 *)((u8 *)D_800B6614 + D_800B6614->unk1780 * 0x2F0 + 0x2D0);
}

u8 func_8006FD6C(u8 *data, s32 len) {
    s32 sum = 5;

    while (len != 0) {
        sum = sum + *data++ + 1;
        len--;
    }
    return sum;
}

u8 func_8006FD6C(u8 *data, s32 len);

s32 func_8006FD94(u8 *data, s32 len, u8 *out) {
    s32 n = 0;

    while (len > 0x400) {
        out[n++] = func_8006FD6C(data, 0x400);
        len -= 0x400;
        data += 0x400;
    }
    if (len != 0) {
        out[n++] = func_8006FD6C(data, len);
    }
    return n;
}

extern long D_800B5C7C;
extern long D_800B5C84;
extern long D_800B5C8C;
extern long D_800B5C94;
extern long EnableEvent(long event);
extern long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
extern void StartCARD(void);
extern void StopPAD(void);
extern void _bu_init(void);
extern void _card_auto(long val);
extern void func_8007F2B4(void);
extern void func_8007F53C(void);

void func_8006FE34(void) {
    StopPAD();
    StartCARD();
    _bu_init();
    func_8007F2B4();
    D_800B5C7C = OpenEvent(0xF4000001, 0x0004, 0x2000, NULL);
    D_800B5C84 = OpenEvent(0xF4000001, 0x8000, 0x2000, NULL);
    D_800B5C8C = OpenEvent(0xF4000001, 0x0100, 0x2000, NULL);
    D_800B5C94 = OpenEvent(0xF4000001, 0x2000, 0x2000, NULL);
    func_8007F53C();
    EnableEvent(D_800B5C7C);
    EnableEvent(D_800B5C84);
    EnableEvent(D_800B5C8C);
    EnableEvent(D_800B5C94);
    _card_auto(0);
}

extern long TestEvent(long event);
extern int VSync(int mode);
extern long _card_info(long chan);

long func_8006FF3C(s16 chan) {
    s32 i = 0;

    if (_card_info(chan) != 0) {
        for (; i < 120; i++) {
            if (TestEvent(D_800B5C7C) == 1) {
                return -1;
            }
            if (TestEvent(D_800B5C84) == 1) {
                return 0;
            }
            if (TestEvent(D_800B5C8C) == 1) {
                return 0;
            }
            if (TestEvent(D_800B5C94) == 1) {
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

void func_8006FFF4(void) {
    StopCARD();
    CloseEvent(D_800B5C7C);
    CloseEvent(D_800B5C84);
    CloseEvent(D_800B5C8C);
    CloseEvent(D_800B5C94);
    StartPAD();
}

extern char D_80086F44[];
extern char D_800B6A44[];
int delete(char *name);
int sprintf(char *buf, const char *fmt, ...);

void func_8007005C(s32 arg0, s32 arg1) {
    sprintf(D_800B6A44, D_80086F44, arg1, arg0);
    delete(D_800B6A44);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800700A4);

extern s16 D_800B616C;
extern s16 D_800B63E4;
extern void func_800706F0(s32, s16);

void func_800705B0(s32 arg0) {
    D_800B616C = -1;
    func_800706F0(arg0, D_800B63E4);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800705E4);

extern u8 D_800B6724[];
extern s32 close(s32 fd);
extern char *func_800705E4(s16 arg0);
extern s32 open(char *name, s32 mode);
extern s32 read(s32 fd, void *buf, s32 n);

s32 func_80070608(s16 slot) {
    char *name;
    s32 fd;

    if (slot == 0) {
        name = func_800705E4(0);
    } else {
        name = func_800705E4(1);
    }
    fd = open(name, 1);
    if (fd == -1) {
        close(fd);
        return 0;
    }
    if (read(fd, D_800B6724, 0x200) != 0x200) {
        close(fd);
        return 0;
    }
    close(fd);
    return -1;
}

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
} Unk80055074;

extern u8 D_80093E44[];
extern void func_8001F39C(void);
extern void func_8005D154(void);
extern void func_800517F0();
extern void func_8006FCD0(void);

void func_800706A8(Unk80055074 *obj) {
    func_8006FCD0();
    obj->unk1C = (s32)D_80093E44;
    func_800517F0(obj);
    func_8001F39C();
    func_8005D154();
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800706F0);

extern void func_800708F0(s32, s32);

void func_800708C8(s32 arg0, s16 arg1) {
    D_800B63E4 = arg1;
    func_800708F0(arg0, 0);
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59A4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59A8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59B0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59B8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59C0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59C8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59D0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59D8);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59E0);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59E4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59EC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59F4);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B59FC);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A0C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800708F0);

extern long D_800B5C9C;
extern long D_800B5CA4;
extern long D_800B5CAC;
extern long D_800B5CB4;
extern long _card_read(long chan, long block, unsigned char *buf);

long func_80070A14(s16 chan) {
    unsigned char buf[128];
    s32 i = 180;

    func_8007F2B4();
    D_800B5C9C = OpenEvent(0xF0000011, 0x0004, 0x2000, NULL);
    D_800B5CA4 = OpenEvent(0xF0000011, 0x8000, 0x2000, NULL);
    D_800B5CAC = OpenEvent(0xF0000011, 0x0100, 0x2000, NULL);
    D_800B5CB4 = OpenEvent(0xF0000011, 0x2000, 0x2000, NULL);
    func_8007F53C();
    EnableEvent(D_800B5C9C);
    EnableEvent(D_800B5CA4);
    EnableEvent(D_800B5CAC);
    EnableEvent(D_800B5CB4);
    buf[0] = 0;
    _card_read(chan, 0, buf);
    while (i--) {
        VSync(0);
    }
    if (_card_info(chan) != 0) {
        for (; i < 600; i++) {
            if (TestEvent(D_800B5C9C) == 1) {
                break;
            }
            if (TestEvent(D_800B5CA4) == 1) {
                break;
            }
            if (TestEvent(D_800B5CAC) == 1) {
                break;
            }
            if (TestEvent(D_800B5CB4) == 1) {
                break;
            }
            VSync(0);
        }
    }
    CloseEvent(D_800B5C9C);
    CloseEvent(D_800B5CA4);
    CloseEvent(D_800B5CAC);
    CloseEvent(D_800B5CB4);
    if (buf[0] != 'M' || buf[1] != 'C') {
        return 0;
    }
    return -1;
}

typedef struct {
    s16 x, y, w, h;
} RECT;

extern s32 DrawSync(s32 mode);
extern void StoreImage(RECT *rect, u32 *p);
extern RECT D_800B5A30;
extern RECT D_800B5A38;
extern s32 *D_800B632C;
extern s32 D_800B5CF4;
extern s32 D_800B5E24;
extern s32 func_80077128(s32 *buf, u32 size);

s32 func_80070C34(void) {
    RECT rect = D_800B5A30;
    RECT unused = D_800B5A38;
    s32 ret;

    DrawSync(0);
    StoreImage(&rect, (u32 *)D_800B632C);
    DrawSync(0);
    D_800B5E24 = func_80077128(D_800B632C, 0x28000);
    if (D_800B5E24 == D_800B5CF4) {
        D_800B632C = 0;
        ret = -1;
    } else {
        D_800B632C = 0;
        ret = 0;
    }
    return ret;
}

void func_80070D00(void) {
    SpuCommonAttr attr;

    attr.cd.volume.left = 0x3FFF;
    attr.cd.volume.right = 0x3FFF;
    attr.mask = 0xC0;
    SpuSetCommonAttr(&attr);
}

extern s16 D_800B5E64;
extern s16 D_800B5E5C;
void func_80026710(s32);
void func_8001F444(void);
void func_80073158(void);
void func_80072E40(void);
void func_80070D00(void);

void func_80070D34(void) {
    func_80026710(10);
    DrawSync(0);
    func_8001F444();
    func_80072A40(1);
    func_80073158();
    func_80068C70();
    func_800279E4(0x140);
    D_800B5E5C = D_800B636C >> 1;
    D_800B5E64 = D_800B645C >> 1;
    func_80072E40();
    func_80070D00();
}

void func_80052DB4(void);
struct Task *func_80072374(void (*fn)(), s16 size);

void func_80070DC4(void) {
    D_800B5FB4 = 0;
    D_800B5D0C = 2;
    D_800B604C->unk14 = 0;
    func_80077878(5, D_800BA780);
    func_80072374(func_80052DB4, 0x48);
}

void func_80070D34(void);
void func_80077878(s16 id, u32 *buf);

void func_80070E1C(void) {
    func_80070D34();
    D_800B5FB4 = 0;
    D_800B5D0C = 2;
    D_800B604C->unk14 = 0;
    func_80077878(6, D_800BA780);
}

void func_80070E6C(void) {
    func_80070D34();
    D_800B5FB4 = 0;
    D_800B5D0C = 2;
    D_800B604C->unk14 = 0;
    func_80077878(7, D_800BA780);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80070EBC);

extern char D_80091B5C[];
extern u16 D_8009730E;
extern u16 D_80097300;
s32 func_80070C34(void);
void func_80053AB0(void);
void func_8003A130(void);

void func_800711C0(void) {
    func_800279E4(0x140);
    func_800266C8();
    func_800758C0(0xA0, 0x78, func_80077DC8(D_80091B5C), 0x800, 0x400, D_800B56D8, D_800B56E4);
    func_80051500();
    if ((D_8009730E & ((volatile s32 *)D_800B64FC)[0]) || (D_80097300 & ((volatile s32 *)D_800B64FC)[0])) {
        D_800B5F54 = 1;
    }
    if (D_800B658C == 0) {
        if (D_800B632C != NULL && (s16)func_80070C34() == 0) {
            D_800B66DC = -1;
        }
        func_80053AB0();
        func_80072A40(0x14);
        func_80026710(0xA);
        D_800B6694 = 0;
        func_8003A130();
        D_800B5FB4 = 2;
        D_800B6554 = 1;
        func_80026158();
    }
}

extern char D_80091B38[];
extern u8 D_800B56E4[];

void func_80071308(void) {
    func_800279E4(320);
    func_800266C8();
    func_800758C0(160, 120, D_80091B38, 0x800, 0x400, D_800B56D8, D_800B56E4);
    if (D_800B658C == 0) {
        if (D_800B632C != NULL && !(s16)func_80070C34()) {
            D_800B66DC = -1;
        }
        func_80053AB0();
        func_80072A40(20);
        func_80026710(10);
        D_800B6694 = 0;
        func_8003A130();
        D_800B5FB4 = 2;
        D_800B6554 = 4;
        func_80026158();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800713F4);

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
} Unk80071A98;

void func_800713F4(void);

void func_80071A98(void) {
    Unk80071A98 *p = (Unk80071A98 *)D_800B604C->vals;

    p->unk10 = 1;
    p->unkC = func_80074910(0x1000);
    p->unkE = func_80074910(20) - 10;
    p->unkA = func_80074910(40);
    p->unk18 = func_80074910(0x1000) - 0x800;
    p->unk16 = 0;
    p->unk1A = 0;
    p->unk1E = func_80074910(0x100) - 0x80;
    p->unk12 = D_800B604C->unk18;
    p->unk2 = 0;
    p->unk4 = func_80074910(0x20);
    p->unk6 = 0;
    p->unk8 = 0;
    D_800B604C->func = func_800713F4;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80071B54);

s32 func_80071B7C(s32 a, s32 b, s32 t) {
    return (a * (0x1000 - t) + t * b) >> 12;
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

void *func_80071BB0(void *data, s16 i) {
    Pack *pack = data;
    return (u8 *)pack + pack->entries[i].offset;
}

u32 func_80071BC8(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk4;
}

s32 func_80071BE0(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk8;
}

s32 func_80071BF8(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unkC;
}

int CdGetToc(u8 (*loc)[4]);
extern s16 D_800B64AC;
extern u8 D_801DAA90[][4];

s32 func_80071C10(void) {
    u8 param[16];

    param[0] = 5;
    CdControlB(0xE, param, 0);
    D_800B64AC = CdGetToc(D_801DAA90);
    return -1;
}

extern volatile s16 D_800B5DA4;

void func_80071C58(void) {
    D_800B5DA4 = 20;
}

extern char D_80086FA0[];
void PadStop(void);
void *ResetCallback(void);
int ResetGraph(int mode);
void func_80072E08(void);
void func_8007B120(void);
int printf(const char *fmt, ...);

void func_80071C6C(void) {
    printf(D_80086FA0);
    ResetGraph(3);
    PadStop();
    StopPAD();
    ResetCallback();
    func_8007B120();
    func_80072E08();
    func_80078304(1);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80071CCC);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80071F48);

extern struct {
    s16 count[3];
    s16 size[3];
    s16 total;
    s16 unkE;
    s32 left;
} D_801DA42C;
extern u8 D_801CA2C8[];
extern u8 *D_801F7AAC[];
extern u8 *D_801F7CAC[];
extern u8 *D_801F7EAC[];
extern u8 D_801F792C[];
extern u8 D_801F79AC[];
extern u8 D_801F7A2C[];
extern s16 D_801F7924[3];
extern struct Task D_800B6D18[];
extern struct Task *D_800B623C;
extern struct Task *D_801F80AC[];
extern s32 D_800B5D9C;
extern s32 D_800B84F4;

void func_80072040(void) {
    s32 left;
    u8 *p;
    s16 i;

    D_801DA42C.count[0] = 0x20;
    D_801DA42C.count[1] = 0x20;
    D_801DA42C.count[2] = 0x10;
    D_801DA42C.size[0] = 0x400;
    D_801DA42C.size[1] = 0x200;
    D_801DA42C.size[2] = 0x100;
    D_801DA42C.unkE = 0x20;
    left = 0x10000;
    p = D_801CA2C8;
    for (i = 0; i < D_801DA42C.count[0]; i++) {
        if (left - D_801DA42C.size[0] < 0) {
            D_801DA42C.count[0] = i;
            break;
        }
        D_801F7AAC[i] = p;
        D_801F792C[i] = 0;
        p += D_801DA42C.size[0];
        left -= D_801DA42C.size[0];
    }
    if (left > 0) {
        for (i = 0; i < D_801DA42C.count[1]; i++) {
            if (left - D_801DA42C.size[1] < 0) {
                D_801DA42C.count[1] = i;
                break;
            }
            D_801F7CAC[i] = p;
            D_801F79AC[i] = 0;
            p += D_801DA42C.size[1];
            left -= D_801DA42C.size[1];
        }
    } else {
        D_801DA42C.count[1] = 0;
    }
    if (left > 0) {
        for (i = 0; ; i++) {
            if (left - D_801DA42C.size[2] < 0) {
                D_801DA42C.count[2] = i;
                break;
            }
            D_801F7EAC[i] = p;
            D_801F7A2C[i] = 0;
            p += D_801DA42C.size[2];
            left -= D_801DA42C.size[2];
        }
        D_801DA42C.count[2] = i;
    } else {
        D_801DA42C.count[2] = 0;
    }
    D_801DA42C.left = left;
    D_800B5D9C = 0;
    D_800B604C = D_800B6D18;
    D_800B6D18[0].unk2E = 0;
    D_800B6D18[0].unk2F = 0;
    D_801F792C[0] = 0xFF;
    D_800B623C = &D_800B6D18[1];
    D_800B6D18[0].next = D_800B6D18;
    D_800B6D18[0].prev = D_800B6D18;
    D_801DA42C.total = D_801DA42C.count[0] + D_801DA42C.count[1] + D_801DA42C.count[2];
    D_801F7924[0] = D_801DA42C.count[0];
    D_801F7924[1] = D_801DA42C.count[1];
    D_801F7924[2] = D_801DA42C.count[2];
    D_800B6D18[0].vals = (Unk800A317CVals *)D_801F7AAC[0];
    D_801F7924[0] = D_801DA42C.count[0] - 1;
    for (i = 1; i < 0x80; i++) {
        D_800B6D18[i].next = &D_800B6D18[i + 1];
        D_801F80AC[i] = NULL;
    }
    D_800B84F4 = 0;
}

extern struct Task *D_800B623C;
extern struct Task D_801F8874;
extern void (*D_800B6054)();
extern s32 D_800B5D9C;
extern s16 D_800B5EFC[3];
extern s16 func_8007374C(s16 size, struct Task *t);

struct Task *func_80072374(void (*fn)(), s16 size) {
    struct Task *t;

    if (D_800B623C == NULL) {
        return NULL;
    }
    D_800B6054 = fn;
    D_801F8874.flags = 1;
    if (func_8007374C(size, &D_801F8874) == 0) {
        return NULL;
    }
    t = D_800B623C;
    t->vals = D_801F8874.vals;
    D_800B623C = t->next;
    t->unk2E = D_801F8874.unk2E;
    t->unk2F = D_801F8874.unk2F;
    t->func = fn;
    t->saved = fn;
    D_800B604C->next->prev = t;
    t->next = D_800B604C->next;
    D_800B604C->next = t;
    t->prev = D_800B604C;
    t->unk14 = D_800B5EFC[0];
    t->unk16 = D_800B5EFC[1];
    t->unk18 = D_800B5EFC[2];
    t->id = D_800B5D9C++;
    t->unk28 = 0xFF;
    t->unk29 = 0xFF;
    t->unk2A = 0xFF;
    t->flags = 1;
    t->cleanup = NULL;
    t->unk2C = 0;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return t;
}

extern void *D_800B65EC;

Unk8003BA6C_Task *func_800724C4(void (*fn)(), s16 flags, s16 size) {
    struct Task *t;
    s16 f;

    if (D_800B623C == NULL) {
        return NULL;
    }
    D_800B6054 = fn;
    GET_RA(D_800B65EC); // FAKE: caller address store, see GET_RA
    D_801F8874.flags = f = flags | 1;
    if (func_8007374C(size, &D_801F8874) == 0) {
        return NULL;
    }
    t = D_800B623C;
    t->vals = D_801F8874.vals;
    D_800B623C = t->next;
    t->unk2E = D_801F8874.unk2E;
    t->unk2F = D_801F8874.unk2F;
    t->flags = f;
    t->func = fn;
    t->saved = fn;
    D_800B604C->next->prev = t;
    t->next = D_800B604C->next;
    D_800B604C->next = t;
    t->prev = D_800B604C;
    t->unk14 = D_800B5EFC[0];
    t->unk16 = D_800B5EFC[1];
    t->unk18 = D_800B5EFC[2];
    t->id = D_800B5D9C++;
    t->unk28 = 0xFF;
    t->unk29 = 0xFF;
    t->unk2A = 0xFF;
    t->cleanup = NULL;
    t->unk2C = 0;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return (Unk8003BA6C_Task *)t;
}

extern struct Task *D_801F80AC[];

struct Task *func_80072624(void (*fn)(), s16 size) {
    struct Task *anchor = D_801F80AC[0];
    struct Task *t;

    if (D_800B623C == NULL) {
        return NULL;
    }
    D_800B6054 = fn;
    D_801F8874.flags = 1;
    if (func_8007374C(size, &D_801F8874) == 0) {
        return NULL;
    }
    t = D_800B623C;
    t->vals = D_801F8874.vals;
    D_800B623C = t->next;
    t->unk2E = D_801F8874.unk2E;
    t->unk2F = D_801F8874.unk2F;
    t->flags = 1;
    t->func = fn;
    t->saved = fn;
    anchor->next->prev = t;
    t->next = anchor->next;
    anchor->next = t;
    t->prev = anchor;
    t->unk14 = D_800B5EFC[0];
    t->unk16 = D_800B5EFC[1];
    t->unk18 = D_800B5EFC[2];
    t->id = D_800B5D9C++;
    t->cleanup = NULL;
    t->unk2C = 0;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return t;
}

struct Task *func_80072768(struct Task *parent, void (*fn)(), s16 size) {
    struct Task *t;

    if (D_800B623C == NULL) {
        return NULL;
    }
    D_800B6054 = fn;
    D_801F8874.flags = 1;
    if (func_8007374C(size, &D_801F8874) == 0) {
        return NULL;
    }
    t = D_800B623C;
    t->vals = D_801F8874.vals;
    D_800B623C = t->next;
    t->unk2E = D_801F8874.unk2E;
    t->unk2F = D_801F8874.unk2F;
    t->func = fn;
    t->saved = fn;
    parent->next->prev = t;
    t->next = parent->next;
    parent->next = t;
    t->prev = parent;
    t->unk14 = D_800B5EFC[0];
    t->unk16 = D_800B5EFC[1];
    t->unk18 = D_800B5EFC[2];
    t->id = D_800B5D9C++;
    t->flags = 1;
    t->unk2C = 0;
    t->cleanup = NULL;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return t;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800728A4);

extern void *D_800B65EC;

void func_80072A40(s16 mask) {
    struct Task *cur = D_800B604C;

    GET_RA(D_800B65EC); // FAKE: caller address store, see GET_RA
    for (D_800B604C = cur->next; D_800B604C != cur; D_800B604C = D_800B604C->next) {
        if (mask & D_800B604C->flags) {
            if (D_800B604C->cleanup != NULL) {
                D_800B604C->cleanup();
            }
            func_800728A4();
        }
    }
}

extern s16 D_801DA432[3];
extern void func_80072C70(struct Task *task);

s16 func_80072AF4(s16 size) {
    struct Task *cur = D_800B604C;
    struct Task *t;

    if (D_801DA432[2] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 3) {
                func_80072C70(t);
                return -1;
            }
        }
    }
    if (D_801DA432[1] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 2) {
                func_80072C70(t);
                return -1;
            }
        }
    }
    if (D_801DA432[0] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 1) {
                func_80072C70(t);
                return -1;
            }
        }
    }
    return 0;
}

extern struct Task *D_801F80AC[];

void func_80072C70(struct Task *task) {
    struct Task *saved = D_800B604C;
    s16 i;

    if (task->cleanup != NULL) {
        task->cleanup();
    }
    i = 0x7F;
    do {
        if (D_801F80AC[i] == task) {
            D_801F80AC[i] = NULL;
            break;
        }
    } while (i-- != 0);
    D_800B604C = task;
    func_800728A4();
    D_800B604C = saved;
}

extern void func_80072040(void);
extern void func_80073138(void);
extern s16 D_800B5F3C;
extern s16 D_800B5E3C;
extern s32 D_800B651C;
extern u16 D_800B5F14;
extern struct Task *D_800B6214;

void func_80072D08(void) {
    func_80072040();
    D_800B5F3C = 0;
    D_800B5E3C = 0;
    D_800B604C->func = func_80073138;
    while (D_800B5D0C != 10) {
        D_800B651C++;
        D_800B5F14++;
        D_800B604C->func();
        D_800B6214 = D_800B604C;
        D_800B604C = D_800B604C->next;
    }
}

void func_80072DC8(struct Task *task) {
    struct Task *saved = D_800B604C;

    D_800B604C = task;
    task->func();
    D_800B604C = saved;
}

extern s32 DrawSync(s32 mode);
extern void FlushCache(void);

void func_80072E08(void) {
    DrawSync(0);
    func_8007F2B4();
    FlushCache();
    func_8007F53C();
}

extern s16 D_800B5E5C;
extern s16 D_800B5E64;
extern s16 D_800B6364;
void func_80084EA8(s32 a, s32 b);

void func_80072E40(void) {
    func_80084EA8(D_800B5E5C, D_800B5E64 + D_800B6364);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80072E78);

extern void CdSetDebug(int level);
extern void SetGraphDebug(int level);
extern void InitGeom(void);
extern int ClearImage(RECT *rect, u8 r, u8 g, u8 b);
extern void func_8007F59C(s32 mode);
extern void func_80084D78(s32 a);
extern s16 D_800B6394;
extern s16 D_800B62FC;
extern s16 D_800B658C;
extern s16 D_800B629C;
extern s16 D_800B60F4;
extern s16 D_800B5E14;
extern s16 D_800B6314;
extern s16 D_800B644C;
extern s16 D_800B63CC;
extern u8 D_8009B5BC[];
extern s16 func_800754D4(void *data, s32 a1);
extern void func_80078304(s16 arg0);
extern void func_800783A4(void);
extern void func_800757C4(void);
extern int CdInit(void);

void func_80072F8C(void) {
    u8 unused[0x78];
    RECT rect;
    u8 unused2[0x28];

    func_800783A4();
    ResetGraph(0);
    D_800B6394 = 0;
    D_800B62FC = 0;
    D_800B658C = 0;
    ResetCallback();
    func_80072E08();
    D_800B629C = 0;
    D_800B60F4 = 0;
    D_800B5E14 = 0;
    D_800B6614 = (Unk800B6614 *)0x80011000;
    D_800B6314 = 0;
    CdInit();
    CdSetDebug(0);
    func_80071C10();
    SetGraphDebug(0);
    DrawSync(0);
    VSync(0);
    SetDispMask(0);
    InitGeom();
    if (D_800B6614->unk178A != 0) {
        D_800B5E5C = 0xA0;
        D_800B5E64 = 0x78;
        func_8007F59C(0);
    } else {
        D_800B5E5C = 0xA0;
        D_800B5E64 = 0x80;
        func_8007F59C(1);
    }
    func_80072E40();
    D_800B644C = 0x200;
    func_80084D78(0x200);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x3FF;
    rect.h = 0x100;
    ClearImage(&rect, 0, 0, 0);
    func_800754D4(D_8009B5BC, 0);
    func_800757C4();
    D_800B5D0C = 0;
    VSync(0);
    SetDispMask(1);
    func_80072D08();
    func_80078304(D_800B63CC);
}

extern s16 D_800B5FAC;
extern void func_80073384(void);

void func_80073138(void) {
    D_800B5FAC = 0;
    D_800B604C->func = func_80073384;
}

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
    DISPENV disp[2];
    DRAWENV draw[2];
    u32 *prim[2];
    u32 *ot[2];
    s16 id;
} Unk80074138;

void func_80073580(void);
void func_8007370C(void);
extern u8 D_801DAC20[];
extern u8 D_801E8C20[];
extern DISPENV *SetDefDispEnv(DISPENV *env, s32 x, s32 y, s32 w, s32 h);
extern DRAWENV *SetDefDrawEnv(DRAWENV *env, s32 x, s32 y, s32 w, s32 h);

void func_80073158(void) {
    struct Task *t;
    Unk80074138 *db;

    t = func_80073D98(func_80073580, 5);
    D_801F8100 = (void *)t;
    db = *(Unk80074138 **)((u8 *)t + 0x1C);
    db->prim[0] = (u32 *)D_801DAC20;
    db->prim[1] = (u32 *)D_801E8C20;
    if (D_800B6614->unk178A != 0) {
        SetDefDispEnv(&db->disp[0], 0, 0, 0x13A, 0xF0);
        SetDefDrawEnv(&db->draw[0], 0x140, 0, 0x140, 0xF0);
        SetDefDispEnv(&db->disp[1], 0x140, 0, 0x13A, 0xF0);
        SetDefDrawEnv(&db->draw[1], 0, 0, 0x140, 0xF0);
        db->disp[0].screen.y = 0;
        db->disp[1].screen.y = 0;
        db->disp[0].screen.h = 0xF0;
        db->disp[1].screen.h = 0xF0;
    } else {
        SetDefDrawEnv(&db->draw[0], 0x140, 0, 0x140, 0x100);
        SetDefDrawEnv(&db->draw[1], 0, 0, 0x140, 0x100);
        SetDefDispEnv(&db->disp[1], 0x140, 0, 0x13A, 0x100);
        SetDefDispEnv(&db->disp[0], 0, 0, 0x13A, 0x100);
        db->disp[0].screen.y = 0x12;
        db->disp[1].screen.y = 0x12;
        db->disp[0].screen.h = 0x100;
        db->disp[1].screen.h = 0x100;
    }
    db->draw[0].isbg = 0xFF;
    db->draw[1].isbg = 0xFF;
    db->id = 1;
    db->ot[0] = (u32 *)((Unk8003BA6C_Task *)func_800724C4(func_8007370C, 5, 0x400))->data;
    db->ot[1] = (u32 *)((Unk8003BA6C_Task *)func_800724C4(func_8007370C, 5, 0x400))->data;
    ClearOTagR(db->ot[0], 0xFA);
    ClearOTagR(db->ot[1], 0xFA);
    D_800B62CC = db->ot[0];
    D_800B6334 = D_800B63AC = db->prim[0];
    func_80072DC8((struct Task *)D_801F8100);
}

void func_80073348(void) {
    if (D_800B5D4C == 1) {
        D_800B5D4C = 2;
        func_800728A4();
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80073384);

extern void DrawOTag(u32 *ot);
extern u32 *ClearOTagR(u32 *ot, s32 n);
extern DRAWENV *PutDrawEnv(DRAWENV *env);
extern DISPENV *PutDispEnv(DISPENV *env);
void func_80074244(void);
void func_80073F2C(void);
extern s16 D_800B5EC4;

void func_80073580(void) {
    Unk80074138 *db = (Unk80074138 *)D_800B604C->vals;
    s16 n = 20;

    DrawOTag(db->ot[db->id] + 0xF9);
    while (DrawSync(1) != 0) {
        VSync(0);
        if (n-- == 0) {
            D_800B5D0C = 9;
            return;
        }
    }
    func_80074244();
    func_80073F2C();
    D_800B5F64++;
    PutDispEnv(&db->disp[db->id]);
    ClearOTagR(db->ot[db->id], 0xFA);
    D_800B62CC = db->ot[db->id];
    D_800B6334 = D_800B63AC = db->prim[db->id];
    PutDrawEnv(&db->draw[db->id]);
    db->id ^= 1;
    D_800B5EC4 = db->draw[db->id].ofs[0];
}

void func_8007370C(void) {
}

extern s16 D_800B62F4;
extern void func_8001E470(void);

void func_80073714(void) {
    if (D_800B5FAC != -1) {
        D_800B62F4 = 1;
        D_800B604C->func = func_8001E470;
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8007374C);

void func_80073AA0(void) {
    s32 left;
    u8 *p;
    s16 i;

    if (D_801DA42C.count[0] < D_801DA42C.unkE) {
        D_801DA42C.count[0] = D_801DA42C.unkE + 1;
    }
    if (D_801DA42C.size[0] & 3) {
        D_801DA42C.size[0] = (D_801DA42C.size[0] + 3) & ~3;
    }
    if (D_801DA42C.size[1] & 3) {
        D_801DA42C.size[1] = (D_801DA42C.size[1] + 3) & ~3;
    }
    if (D_801DA42C.size[2] & 3) {
        D_801DA42C.size[2] = (D_801DA42C.size[2] + 3) & ~3;
    }
    left = 0x10000;
    p = D_801CA2C8;
    left -= D_801DA42C.size[0] * D_801DA42C.unkE;
    p += D_801DA42C.size[0] * D_801DA42C.unkE;
    for (i = 0; i < D_801DA42C.count[0]; i++) {
        if (i >= D_801DA42C.unkE) {
            if (left - D_801DA42C.size[0] < 0) {
                D_801DA42C.count[0] = i;
                break;
            }
            D_801F7AAC[i] = p;
            D_801F792C[i] = 0;
            p += D_801DA42C.size[0];
            left -= D_801DA42C.size[0];
        }
    }
    if (left > 0) {
        for (i = 0; i < D_801DA42C.count[1]; i++) {
            if (left - D_801DA42C.size[1] < 0) {
                D_801DA42C.count[1] = i;
                break;
            }
            D_801F7CAC[i] = p;
            D_801F79AC[i] = 0;
            p += D_801DA42C.size[1];
            left -= D_801DA42C.size[1];
        }
    } else {
        D_801DA42C.count[1] = 0;
    }
    if (left > 0) {
        for (i = 0; ; i++) {
            if (left - D_801DA42C.size[2] < 0) {
                D_801DA42C.count[2] = i;
                break;
            }
            D_801F7EAC[i] = p;
            D_801F7A2C[i] = 0;
            p += D_801DA42C.size[2];
            left -= D_801DA42C.size[2];
        }
        D_801DA42C.count[2] = i;
    } else {
        D_801DA42C.count[2] = 0;
    }
    D_801DA42C.left = left;
    D_801DA42C.total = D_801DA42C.count[0] + D_801DA42C.count[1] + D_801DA42C.count[2];
    D_801F7924[2] = D_801DA42C.count[2];
    D_801F7924[1] = D_801DA42C.count[1];
    D_801F7924[0] = D_801DA42C.count[0] - D_801F7924[0];
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80073D98);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80073F2C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80074244);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80074910);

MATRIX *func_800749C0(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_80094174[ax & 0xFFF];
    sy = D_80094174[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_80094174[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_80094174[(az + 0x400) & 0xFFF];
    sz = D_80094174[az & 0xFFF];
    cx = D_80094174[(ax + 0x400) & 0xFFF];
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

extern MATRIX *func_800749C0(SVECTOR *r, MATRIX *m);

void func_80074BF0(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_800749C0(rot, &D_801FA428);
    ApplyMatrix(&D_801FA428, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern SVECTOR D_800B6124;
extern SVECTOR D_800B5E2C;
extern SVECTOR D_800B6574;
extern MATRIX D_801981D4;
extern VECTOR D_801CA274;
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern MATRIX *func_80084978(MATRIX *m, VECTOR *v);

void func_80074C84(void) {
    D_800B6574.vx = -D_800B5E2C.vx;
    D_800B6574.vy = -D_800B5E2C.vy;
    D_800B6574.vz = -D_800B5E2C.vz;
    func_800749C0(&D_800B6124, &D_801981D4);
    ApplyMatrix(&D_801981D4, &D_800B6574, &D_801CA274);
    func_80084978(&D_801981D4, &D_801CA274);
    SetRotMatrix(&D_801981D4);
    SetTransMatrix(&D_801981D4);
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A30);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A38);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A40);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A44);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A48);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A50);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A58);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A60);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A68);

extern void *D_800B63AC;
extern s16 D_800B6394;
extern u32 *D_800B62CC;
typedef struct {
    s16 x, y, w, h;
} Unk80074D48_Rect;

typedef struct {
    u32 tag;
    u32 code[2];
} Unk80074D48_Area;

extern s16 D_800B5EC4;
extern void SetDrawArea(Unk80074D48_Area *p, Unk80074D48_Rect *r);

void func_80074D48(s32 top, s32 bottom) {
    Unk80074D48_Rect r;
    Unk80074D48_Area *area = D_800B63AC;

    r.w = 320;
    r.h = bottom - top;
    r.x = D_800B5EC4;
    r.y = top + D_800B6394;
    SetDrawArea(area, &r);
    AddPrim(D_800B62CC + 0xF9, area++);
    D_800B63AC = area;
}

typedef struct {
    u8 u0, v0;
    u16 clut;
    u8 u1, v1;
    u16 tpage;
    u8 u2, v2;
    u16 pad0;
    u8 u3, v3;
    u16 pad1;
    u8 unk10[0x10];
    u8 u4, v4;
    u16 tpage2;
    u8 u5, v5;
    u16 tpage3;
    u8 unk28[0x14];
} Unk800B9EA4;

extern Unk800B9EA4 D_800B9EA4[8];
extern u16 D_800972D4[];

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[6];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk80074DC4;

typedef struct {
    s16 x;
    s16 y;
    s16 val;
} Unk80074DC4_Arg;

void func_80076920(s32 level);
s32 func_80076524(u8 *data, Unk80074DC4_Arg *arg);

void func_80074DC4(void) {
    Unk80074DC4 *d = (Unk80074DC4 *)D_800B604C->vals;
    Unk80074DC4_Arg arg;

    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    if (d->unk10 < 0x1000) {
        d->unk10 += 0x199;
        func_80076920(0x1000 - d->unk10);
    }
    if (d->unkC > 0) {
        d->unkC -= 0x400;
        func_80076524(D_8009B5BC, &arg);
    } else {
        D_800B5D4C = 3;
        func_800728A4();
    }
}

extern SVECTOR D_800B5A48;
extern SVECTOR D_800B5A50;
extern SVECTOR D_800B5A58;
extern SVECTOR D_800B5A60;
extern CVECTOR D_800B5A68;
void func_80074BF0(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out);
void func_80074C84(void);

void func_80074E7C(void) {
    Unk80074DC4 *d = (Unk80074DC4 *)D_800B604C->vals;
    SVECTOR a = D_800B5A48;
    SVECTOR v = D_800B5A50;
    SVECTOR base = D_800B5A58;
    Unk80074DC4_Arg arg;
    SVECTOR unused;
    SVECTOR e = D_800B5A60;

    D_800B6124.vz = 0;
    D_800B6124.vy = d->unk2;
    D_800B6124.vx = 0;
    v.vz = -1000;
    v.vy = -40;
    v.vx = 0;
    func_80074BF0(&D_800B6124, &v, &base, &D_800B5E2C);
    func_80074C84();
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_80076524(D_8009B5BC, &arg);
    d->unk10 -= 0x200;
    func_80076920(0x1000 - d->unk10);
    if (d->unk10 < 0) {
        D_800B5D4C = 2;
        D_800B604C->func = func_80074DC4;
    }
}

void func_80075008(void) {
    Unk80074DC4 *d = (Unk80074DC4 *)D_800B604C->vals;
    SVECTOR a = D_800B5A48;
    SVECTOR v = D_800B5A50;
    SVECTOR base = D_800B5A58;
    Unk80074DC4_Arg arg;
    SVECTOR unused;
    SVECTOR e = D_800B5A60;
    CVECTOR col = D_800B5A68;
    s16 t;

    D_800B6124.vz = 0;
    D_800B6124.vy = d->unk2;
    D_800B6124.vx = 0;
    t = d->unkA;
    v.vz = func_80071B7C(-1000, -1000, t);
    v.vy = func_80071B7C(-120, -40, t);
    v.vz = -2000;
    v.vy = -50;
    v.vx = 0;
    if (d->unkE != 0) {
        d->unkE--;
    } else if (d->unkA < 0x1000) {
        d->unkA += 0x40;
    }
    func_80074BF0(&D_800B6124, &v, &base, &D_800B5E2C);
    func_80074C84();
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_80076524(D_8009B5BC, &arg);
    if (D_800B5D4C == 1) {
        d->unk10 = 0x1000;
        D_800B604C->func = func_80074E7C;
    }
    if (d->unk10 != 0) {
        d->unk10 -= 0x3E;
        func_80076920(0x1000 - d->unk10);
        if (d->unk10 < 0) {
            D_800B604C->func = func_80074DC4;
            return;
        }
        if (d->unk10 >= 0x7D) {
            func_80074D48(0x60, 0xA8);
        }
    } else if (d->unkC >= 0xC80) {
        func_80074D48(0x60, 0xA8);
    }
}

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk80075270;

extern void func_80075008(void);

void func_80075270(void) {
    Unk80075270 *p = (Unk80075270 *)D_800B604C->vals;
    SVECTOR pos = {100, 0, 0};

    p->unkC = 0x7210;
    p->unkA = 0;
    p->unkE = 10;
    p->unk10 = 0;
    func_80076FF8(&pos);
    func_80076FF8(&pos);
    func_80076FF8(&pos);
    D_800B604C->func = func_80075008;
}

void func_80075308(void) {
    u16 *clut = D_800972D4;
    s16 i;

    for (i = 0; i < 8; i++) {
        s16 u = (i & 7) << 5;
        s16 v = ((i >> 3) & 7) << 5;

        D_800B9EA4[i].u0 = u;
        D_800B9EA4[i].v0 = v;
        D_800B9EA4[i].u1 = u + 0x1F;
        D_800B9EA4[i].v1 = v;
        D_800B9EA4[i].u4 = u + 0x1F;
        D_800B9EA4[i].v4 = v;
        D_800B9EA4[i].u5 = u + 0x1F;
        D_800B9EA4[i].v5 = v;
        D_800B9EA4[i].u2 = u;
        D_800B9EA4[i].v2 = v | 0x1F;
        D_800B9EA4[i].u3 = u + 0x1F;
        D_800B9EA4[i].v3 = v | 0x1F;
        D_800B9EA4[i].tpage = GetTPage(0, 0, 0x280, 0);
        D_800B9EA4[i].tpage2 = GetTPage(0, 2, 0x280, 0);
        D_800B9EA4[i].tpage3 = GetTPage(0, 1, 0x280, 0);
        D_800B9EA4[i].clut = GetClut(0x2C0, *clut++);
    }
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800754D4);

extern s32 D_8009731C[];
extern s8 D_801FADA0[];
extern void *func_80071BB0(void *data, s16 i);
extern s16 func_800754D4(void *data, s32 a1);

void func_800757C4(void) {
    s16 i;

    for (i = 0; i < D_8009731C[0]; i++) {
        D_801FADA0[i] = (func_800754D4(func_80071BB0(D_8009731C, i), -1) << 5) / 200;
    }
    i = 9;
    do {
        D_801FADA0[i] = 30;
    } while (i--);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_800758C0);

extern s16 D_800B6564;
extern void func_800758C0(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_80076220(s16 x, s16 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800B6564 = -1;
    func_800758C0(x, y, text, a3, a4, a5, a6);
}

extern char D_801985B4[];

void func_80076270(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    short i, j;

    i = len - 1;
    if (len != 0) {
        do {
            D_801985B4[i] = value % 10 + '0';
            value /= 10;
            j = i;
            i--;
        } while (j != 0);
    }
    D_801985B4[len] = 0;
    func_800758C0(x, y, D_801985B4, d, a, b, c);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8007633C);

void func_80076474(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    D_800B6564 = -1;
    func_80076270(x, y, value, d, a, b, c, len);
}

void func_800764D4(short x, short y, s32 value, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800B6564 = -1;
    func_8007633C(x, y, value, a3, a4, a5, a6);
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
} Unk80076524_F3;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    s32 xy3;
} Unk80076524_F4;

typedef struct {
    SVECTOR *v[4];
    u16 unk10;
    u16 tri;
} Unk80076524_Face;

typedef struct {
    u8 pad[0xC];
    u16 count;
    u8 padE[6];
    Unk80076524_Face face[1];
} Unk80076524_Model;

extern SVECTOR D_800B5A84;
extern VECTOR D_8008702C;
extern void SetPolyF3(void *p);
extern void SetPolyF4(void *p);

s32 func_80076524(u8 *data, Unk80074DC4_Arg *arg) {
    Unk80076524_Model *m = (Unk80076524_Model *)data;
    SVECTOR unused;
    SVECTOR rot = D_800B5A84;
    VECTOR scale = D_8008702C;
    Unk80076524_Face *f;
    s16 n;

    if (m == NULL) {
        return 0;
    }
    D_801CA274.vx = arg->x - 0xA0;
    D_801CA274.vy = arg->y - 0xB4;
    D_801CA274.vz = arg->val;
    PushMatrix();
    func_80084978(&D_801FA428, &D_801CA274);
    SetTransMatrix(&D_801FA428);
    func_800749C0(&rot, &D_801FA428);
    ScaleMatrix(&D_801FA428, &scale);
    SetRotMatrix(&D_801FA428);
    f = m->face;
    n = m->count;
    while (n--) {
        if (f->tri != 0) {
            Unk80076524_F3 *p = D_800B63AC;

            D_800B61CC = RotTransPers3(f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy2, &D_800B5CFC, &D_800B642C);
            if (!(D_800B642C & ~0x1FFF)) {
                SetPolyF3(p);
                p->b0 = p->g0 = p->r0 = 0;
                AddPrim(D_800B62CC, p);
                p++;
                D_800B63AC = p;
            }
        } else {
            Unk80076524_F4 *p = D_800B63AC;

            D_800B61CC = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy3, &p->xy2, &D_800B5CFC, &D_800B642C);
            if (!(D_800B642C & ~0x1FFF)) {
                SetPolyF4(p);
                p->b0 = p->g0 = p->r0 = 0;
                AddPrim(D_800B62CC, p);
                p++;
                D_800B63AC = p;
            }
        }
        f++;
    }
    PopMatrix();
}

s32 func_800767E0(Unk8002A35C *a, Unk8002A35C *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;

    if ((dx < 0 ? -dx : dx) > 0x4000) {
        return 0xFFFF;
    }
    if ((dz < 0 ? -dz : dz) > 0x4000) {
        return 0xFFFF;
    }
    return SquareRoot0(dx * dx + dz * dz);
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_8007686C);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80076920);

typedef struct {
    s16 x, y, z;
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
} Unk80076FF8;

extern struct Task *func_80073D98(void (*func)(void), s16 flags);
extern void func_80076A04(void);

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80076A04);

void func_80076FF8(SVECTOR *pos) {
    struct Task *t = func_80073D98(func_80076A04, 5);
    Unk80076FF8 *d;
    s16 i;

    if (t != NULL) {
        d = (Unk80076FF8 *)t->vals;
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
        i = 15;
        do {
            func_80074910(0x1000);
            d->unk28[i] = func_80074910(0x1000);
            d->unk12C = 0;
            d->unk12E = 32;
        } while (i--);
        i = 15;
        do {
            d->unk48[i] = func_80074910(0x1000);
            d->unkAC[i] = func_80074910(0x1000);
            d->unk10C[i] = func_80074910(0x1000);
            d->unk68[i] = func_80074910(0x80) - 0x40;
            d->unk88[i] = func_80074910(0x1000);
        } while (i--);
        d->unkA8 = 0;
        d->unkAA = 30;
        d->unk130 = 16;
        d->unk132 = 128;
        d->unk134 = 30;
        d->unk136 = 0x200;
    }
}

s32 func_80077128(s32 *buf, u32 size) {
    s32 sum = 0;
    s32 n = size >> 2;

    while (n-- != 0) {
        sum += buf[n];
    }
    return sum;
}

typedef struct {
    RECT rect[2];
    s16 file;
    u8 pad12[6];
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
    u8 pad68[4];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
    u16 unk72;
    s16 unk74;
} Unk8005231C;

extern int CdRead2(long mode);
extern void func_80077B54(void);
extern void func_80077E44(void);
extern int CdControl(u8 com, u8 *param, u8 *result);
extern s16 D_800B62FC;

s16 func_80077164(Unk8005231C *movie) {
    s16 fail = -1;
    s16 i = 59;

    do {
        if (CdControl(0x15, movie->loc, 0) != 0) {
            fail = 0;
            break;
        }
    } while (i--);

    if (fail) {
        func_80077E44();
        i = 59;
        do {
            if (CdControl(0x15, movie->loc, 0) != 0) {
                fail = 0;
                break;
            }
        } while (i--);
        if (fail) {
            D_800B62FC = -1;
            goto fail;
        }
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
    fail:
        func_80077B54();
        func_80077E44();
        return 0;
    }
    return -1;
}

extern void CdReadCallback(void (*func)());
extern void DecDCTReset(s32 mode);
extern void DecDCToutCallback(void (*func)());
extern void StSetRing(u32 *ring_addr, u32 ring_size);
extern void StSetStream(u32 mode, u32 start_frame, u32 end_frame, void (*func1)(), void (*func2)());
extern s16 func_80077164(Unk8005231C *movie);

s16 func_80077270(void (*outFunc)(), void (*endFunc)(), Unk8005231C *movie) {
    movie->unk4C = 0;
    CdReadCallback(0);
    DecDCTReset(0);
    DecDCToutCallback(outFunc);
    StSetRing(movie->ring, 0x23);
    StSetStream(movie->info->mode, movie->info->start, movie->info->end, 0, endFunc);
    return func_80077164(movie);
}

void func_80077300(Unk8005231C *movie) {
    Unk8005231C_Info *info = movie->info;
    Unk80077300 *p = D_801F8100->unk1C;

    movie->unk40 = info->mode;
    movie->unk30 = p->unkF0;
    movie->unk34 = p->unkF0;
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
} *D_801F80FC;

extern void LoadImage(RECT *rect, u32 *p);
extern void DecDCTout(u32 *buf, s32 size);

void func_800773F0(void) {
    Unk8005231C *movie = (Unk8005231C *)D_801F80FC->unk1C;
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

extern s16 D_800B646C;
extern s32 StFreeRing(u32 *base);
extern s32 StGetNext(u32 **addr, u32 **header);

u32 *func_80077560(Unk8005231C *dec) {
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
        D_800B646C = -1;
    }
    dec->unk70 = sector->frameCount;
    if (dec->unk58 != sector->width || dec->unk5C != sector->height) {
        dec->unk58 = sector->width;
        dec->unk5C = sector->height;
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
u32 *func_80077560(Unk8005231C *dec);

s32 func_80077730(Unk800527E8 *dec) {
    u32 *frame;
    s32 tries;

    for (tries = 100; tries != 0;) {
        frame = func_80077560((Unk8005231C *)dec);
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

void func_800777B4(void) {
    Unk8005286C *p = D_801F80FC->unk1C;
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

s32 func_80077858(void) {
    D_801F80FC->unk1C->unk4C = -1;
    return 0;
}

INCLUDE_ASM("asm/dh3/nonmatchings/dh3", func_80077878);

extern void CdDataCallback(void (*func)());
extern void CdReadyCallback(void (*func)());

void func_80077B54(void) {
    u8 param[4];

    DecDCTReset(0);
    param[0] = 0x80;
    CdControlB(0xE, param, 0);
    DecDCToutCallback(0);
    CdDataCallback(0);
    CdReadyCallback(0);
    CdControlB(9, 0, 0);
}

extern s16 D_800B5F54;
extern RECT D_800B5A8C;
extern void DecDCTin(u32 *buf, s32 mode);
extern void DecDCTout(u32 *buf, s32 size);
extern void DecDCTReset(s32 mode);
extern void DecDCToutCallback(void (*func)());
extern void CdDataCallback(void (*func)());
extern void CdReadyCallback(void (*func)());
extern s32 func_80077730(Unk800527E8 *dec);
extern void func_800777B4(void);
extern void func_80077B54(void);
extern void func_80077E44(void);

void func_80077BB4(void) {
    Unk8005231C *movie = (Unk8005231C *)D_800B604C->vals;
    RECT rect = D_800B5A8C;
    u8 param[8];
    s16 ok;

    if (D_800B658C != 0) {
        ok = -1;
        D_800B658C = ok;
        if (D_800B5F54 != 0) {
            ok = --D_800B5F54 != 0 ? -1 : 0;
        }
        if (movie->unk4C == 0 && ok) {
            DecDCTin(movie->vlcbuf[movie->unk30], movie->unk60);
            DecDCTout(movie->imgbuf[movie->unk74], ((movie->slice.w - 1) / 16 + 1) * (((movie->slice.h - 1) / 16 + 1) << 8) >> 1);
            if (func_80077730((Unk800527E8 *)movie) == -1) {
                func_80077B54();
                func_80077E44();
            } else {
                func_800777B4();
                movie->unk3C = 0;
                return;
            }
        } else {
            DecDCTReset(0);
            param[0] = 0x80;
            CdControlB(0xE, param, 0);
            DecDCToutCallback(0);
            CdDataCallback(0);
            CdReadyCallback(0);
            CdControlB(9, 0, 0);
        }
        D_800B658C = 0;
    }
    func_800728A4();
}

u8 *func_80077D64(u8 *s) {
    if ((u32)(*s - '0') >= 10) {
        return func_80077D64(s + 1);
    }
    return s;
}

u8 *func_80077D8C(u8 *s) {
    for (;;) {
        if ((u32)(*s - '0') < 10 && s[-1] == ' ') {
            return s;
        }
        s++;
    }
}

char *func_80077DC8(char *arg0) {
    return arg0;
}

extern u16 D_8009DD9C[];

u16 func_80077DD0(u16 bits, s16 idx) {
    u16 *tbl = &D_8009DD9C[idx * 16];
    u16 r = 0;
    s16 i;

    for (i = 0; i < 16; i++) {
        if ((bits >> i) & 1) {
            r |= tbl[i];
        }
    }
    return r;
}

int CdControl(u8 com, u8 *param, u8 *result);
int CdInit(void);
int CdSync(int mode, u8 *result);
extern char D_8008703C[];
extern u8 D_800B5F84[];

void func_80077E44(void) {
    printf(D_8008703C);
    CdSync(0, D_800B5F84);
    CdControl(0xA, 0, D_800B5F84);
    CdSync(0, D_800B5F84);
    CdInit();
}

extern int CdReadSync(int mode, u8 *result);
extern char D_80087048[];
extern int printf(const char *fmt, ...);

s32 func_80077EA8(void) {
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
    printf(D_80087048);
    return 0;
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A74);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A7C);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A80);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A84);

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A8C);

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

extern XF_HDR D_801F834C;

typedef struct {
    u8 minute, second, sector, track;
} CdlLOC;

typedef struct {
    CdlLOC pos;
    u32 size;
    char name[16];
} CdlFILE;

extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern int CdRead(int sectors, u32 *buf, int mode);
extern int CdPosToInt(CdlLOC *p);
extern CdlLOC *CdIntToPos(int i, CdlLOC *p);
extern char D_80087054[];
extern char D_8008706C[];
extern char D_80087088[];
extern char D_800870A0[];

typedef struct {
    u8 data[sizeof(XF_HDR)];
} Unk80077F2C;

int func_80077F2C(void) {
    CdlFILE file = *(CdlFILE *)0x80012804;
    u32 *p;

    printf(D_80087054, file.pos.minute, file.pos.second, file.pos.track, file.pos.sector);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    if (CdRead(1, (u32 *)0x80013000, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_80077EA8() == 0) {
        return 0;
    }
    *(Unk80077F2C *)&D_801F834C = *(Unk80077F2C *)0x80013000;
    CdIntToPos(CdPosToInt(&file.pos) + 1, &file.pos);
    if (D_801F834C.exec.t_addr != 0x80013000) {
        return 0;
    }
    printf(D_8008706C, D_801F834C.exec.t_addr, D_801F834C.exec.s_addr);
    for (p = (u32 *)D_801F834C.exec.t_addr; p < (u32 *)D_801F834C.exec.s_addr; p++) {
        *p = 0;
    }
    printf(D_80087088);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    printf(D_800870A0);
    if (CdRead((D_801F834C.exec.t_size + 0x7FF) >> 11, (u32 *)D_801F834C.exec.t_addr, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_80077EA8() == 0) {
        return 0;
    }
    printf("Loaded\n");
    return 1;
}

extern int CdControl(unsigned char com, unsigned char *param, unsigned char *result);
extern int CdSync(int mode, unsigned char *result);

void func_800781B8(void) {
    u8 result[8];

    CdSync(0, result);
    CdControl(10, 0, result);
    CdSync(0, result);
}

extern char D_800870C0[];
extern char D_800870CC[];
extern int func_80077F2C(void);
extern int VSyncCallback(void (*f)(void));
extern long Exec(EXEC *exec, long argc, char **argv);
extern int CdReset(int mode);
extern int VSync(int mode);

void func_800781F8(s16 next) {
    s32 *index = (s32 *)0x80012800;
    s32 i;

    ResetCallback();
    func_800781B8();
    CdInit();
    while (1) {
        if (func_80077F2C()) {
            printf(D_800870C0);
            VSyncCallback(0);
            for (i = 59; i != -1; i--) {
                VSync(0);
            }
            func_80072E08();
            func_800781B8();
            ResetGraph(3);
            PadStop();
            D_801F834C.exec.s_addr = 0x8001D4F0;
            D_801F834C.exec.s_size = 0;
            *index = next;
            func_8007F2B4();
            Exec(&D_801F834C.exec, 0, 0);
            printf(D_800870CC);
        }
        CdReset(0);
    }
}

void func_800781F8(s16 arg0);

void func_80078304(s16 arg0) {
    func_800781F8(arg0);
}

INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5A9C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AAC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AB4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AB8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5ABC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AC0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AC4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5ACC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AD0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AD4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AD8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5ADC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AE0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AE4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AE8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AEC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5AF0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B5C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B60);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B64);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B6C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B70);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B74);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B78);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B7C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B84);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5B90);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5BAC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C0C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C6C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C70);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C74);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C78);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C7C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C84);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C8C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C94);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5C9C);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CA4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CAC);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CB4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CC0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CD0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CD8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CE0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CE8);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CF0);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CF4);
INCLUDE_RODATA("asm/dh3/nonmatchings/dh3", D_800B5CFC);
