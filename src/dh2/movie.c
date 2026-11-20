#include "common.h"
#include "psyq/libspu.h"
#include "psyq/libgpu.h"
#include "task.h"

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088AC8);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088AD4);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088AE0);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088AF8);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088B14);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088B2C);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088B4C);

INCLUDE_RODATA("asm/dh2/nonmatchings/movie", D_80088B58);

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
extern void func_8007870C(void);
extern void func_800789FC(void);
extern int CdControl(u8 com, u8 *param, u8 *result);
extern s16 D_800B7050;

s16 func_80077D1C(Unk8005231C *movie) {
    s16 fail = -1;
    s16 i = 59;

    do {
        if (CdControl(0x15, movie->loc, 0) != 0) {
            fail = 0;
            break;
        }
    } while (i--);

    if (fail) {
        func_800789FC();
        i = 59;
        do {
            if (CdControl(0x15, movie->loc, 0) != 0) {
                fail = 0;
                break;
            }
        } while (i--);
        if (fail) {
            D_800B7050 = -1;
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
        func_8007870C();
        func_800789FC();
        return 0;
    }
    return -1;
}

extern void CdReadCallback(void (*func)());
extern void DecDCTReset(s32 mode);
extern void DecDCToutCallback(void (*func)());
extern void StSetRing(u32 *ring_addr, u32 ring_size);
extern void StSetStream(u32 mode, u32 start_frame, u32 end_frame, void (*func1)(), void (*func2)());
extern s16 func_80077D1C(Unk8005231C *movie);

s16 func_80077E28(void (*outFunc)(), void (*endFunc)(), Unk8005231C *movie) {
    movie->unk4C = 0;
    CdReadCallback(0);
    DecDCTReset(0);
    DecDCToutCallback(outFunc);
    StSetRing(movie->ring, 0x23);
    StSetStream(movie->info->mode, movie->info->start, movie->info->end, 0, endFunc);
    return func_80077D1C(movie);
}

typedef struct {
    u8 pad[0xF0];
    s16 unkF0;
} Unk80077300;

extern struct {
    u8 pad[0x1C];
    Unk80077300 *unk1C;
} *D_801F7594;

void func_80077EB8(Unk8005231C *movie) {
    Unk8005231C_Info *info = movie->info;
    Unk80077300 *p = D_801F7594->unk1C;

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
} *D_801F7590;

extern void LoadImage(RECT *rect, u32 *p);
extern void DecDCTout(u32 *buf, s32 size);

void func_80077FA8(void) {
    Unk8005231C *movie = (Unk8005231C *)D_801F7590->unk1C;
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

extern s16 D_800B71F8;
extern s32 StFreeRing(u32 *base);
extern s32 StGetNext(u32 **addr, u32 **header);

u32 *func_80078118(Unk8005231C *dec) {
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
        D_800B71F8 = -1;
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
u32 *func_80078118(Unk8005231C *dec);

s32 func_800782E8(Unk800527E8 *dec) {
    u32 *frame;
    s32 tries;

    for (tries = 100; tries != 0;) {
        frame = func_80078118((Unk8005231C *)dec);
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

void func_8007836C(void) {
    Unk8005286C *p = D_801F7590->unk1C;
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

s32 func_80078410(void) {
    D_801F7590->unk1C->unk4C = -1;
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/movie", func_80078430);

extern void CdDataCallback(void (*func)());
extern void CdReadyCallback(void (*func)());

void func_8007870C(void) {
    u8 param[4];

    DecDCTReset(0);
    param[0] = 0x80;
    CdControlB(0xE, param, 0);
    DecDCToutCallback(0);
    CdDataCallback(0);
    CdReadyCallback(0);
    CdControlB(9, 0, 0);
}

extern s16 D_800B6CB8;
extern RECT D_800B67E8;
extern void DecDCTin(u32 *buf, s32 mode);
extern void DecDCTout(u32 *buf, s32 size);
extern void DecDCTReset(s32 mode);
extern void DecDCToutCallback(void (*func)());
extern void CdDataCallback(void (*func)());
extern void CdReadyCallback(void (*func)());
extern s32 func_800782E8(Unk800527E8 *dec);
extern void func_8007836C(void);
extern void func_8007870C(void);
extern void func_800789FC(void);

extern s16 D_800B72E0;

extern struct Task *D_800B6DE0;

void func_8007876C(void) {
    Unk8005231C *movie = (Unk8005231C *)D_800B6DE0->vals;
    RECT rect = D_800B67E8;
    u8 param[8];
    s16 ok;

    if (D_800B72E0 != 0) {
        ok = -1;
        D_800B72E0 = ok;
        if (D_800B6CB8 != 0) {
            ok = --D_800B6CB8 != 0 ? -1 : 0;
        }
        if (movie->unk4C == 0 && ok) {
            DecDCTin(movie->vlcbuf[movie->unk30], movie->unk60);
            DecDCTout(movie->imgbuf[movie->unk74], ((movie->slice.w - 1) / 16 + 1) * (((movie->slice.h - 1) / 16 + 1) << 8) >> 1);
            if (func_800782E8((Unk800527E8 *)movie) == -1) {
                func_8007870C();
                func_800789FC();
            } else {
                func_8007836C();
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
        D_800B72E0 = 0;
    }
    func_8007345C();
}

u8 *func_8007891C(u8 *s) {
    if ((u32)(*s - '0') >= 10) {
        return func_8007891C(s + 1);
    }
    return s;
}

u8 *func_80078944(u8 *s) {
    for (;;) {
        if ((u32)(*s - '0') < 10 && s[-1] == ' ') {
            return s;
        }
        s++;
    }
}

char *func_80078980(char *arg0) {
    return arg0;
}

extern u16 D_800A1F0C[];

u16 func_80078988(u16 bits, s16 idx) {
    u16 *tbl = &D_800A1F0C[idx * 16];
    u16 r = 0;
    s16 i;

    for (i = 0; i < 16; i++) {
        if ((bits >> i) & 1) {
            r |= tbl[i];
        }
    }
    return r;
}

extern char D_80088AC8[];
extern u8 D_800B6D00[];
int CdSync(int mode, u8 *result);
int CdControl(u8 com, u8 *param, u8 *result);
int CdInit(void);

void func_800789FC(void) {
    printf(D_80088AC8);
    CdSync(0, D_800B6D00);
    CdControl(0xA, 0, D_800B6D00);
    CdSync(0, D_800B6D00);
    CdInit();
}

extern int CdReadSync(int mode, u8 *result);
extern char D_80088AD4[];
extern int printf(const char *fmt, ...);

s32 func_80078A60(void) {
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
    printf(D_80088AD4);
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

extern XF_HDR D_801F7740;

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
extern char D_80088AE0[];
extern char D_80088AF8[];
extern char D_80088B14[];
extern char D_80088B2C[];
/* "Loaded\n", defined in the main game file's small data */
extern char D_800B67F0[];

typedef struct {
    u8 data[sizeof(XF_HDR)];
} Unk80078AE4;

int func_80078AE4(void) {
    CdlFILE file = *(CdlFILE *)0x80012804;
    u32 *p;

    printf(D_80088AE0, file.pos.minute, file.pos.second, file.pos.track, file.pos.sector);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    if (CdRead(1, (u32 *)0x80013000, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_80078A60() == 0) {
        return 0;
    }
    *(Unk80078AE4 *)&D_801F7740 = *(Unk80078AE4 *)0x80013000;
    CdIntToPos(CdPosToInt(&file.pos) + 1, &file.pos);
    if (D_801F7740.exec.t_addr != 0x80013000) {
        return 0;
    }
    printf(D_80088AF8, D_801F7740.exec.t_addr, D_801F7740.exec.s_addr);
    for (p = (u32 *)D_801F7740.exec.t_addr; p < (u32 *)D_801F7740.exec.s_addr; p++) {
        *p = 0;
    }
    printf(D_80088B14);
    if (CdControlB(2, (u8 *)&file.pos, 0) == 0) {
        return 0;
    }
    printf(D_80088B2C);
    if (CdRead((D_801F7740.exec.t_size + 0x7FF) >> 11, (u32 *)D_801F7740.exec.t_addr, 0x80) == 0) {
        return 0;
    }
    if ((s16)func_80078A60() == 0) {
        return 0;
    }
    printf(D_800B67F0);
    return 1;
}

extern int CdControl(unsigned char com, unsigned char *param, unsigned char *result);
extern int CdSync(int mode, unsigned char *result);

void func_80078D70(void) {
    u8 result[8];

    CdSync(0, result);
    CdControl(10, 0, result);
    CdSync(0, result);
}

extern char D_80088B4C[];
extern char D_80088B58[];
extern int func_80078AE4(void);
extern int VSyncCallback(void (*f)(void));
extern long Exec(EXEC *exec, long argc, char **argv);
extern int CdReset(int mode);
extern int VSync(int mode);

void func_80078DB0(s16 next) {
    s32 *index = (s32 *)0x80012800;
    s32 i;

    ResetCallback();
    func_80078D70();
    CdInit();
    while (1) {
        if (func_80078AE4()) {
            printf(D_80088B4C);
            VSyncCallback(0);
            for (i = 59; i != -1; i--) {
                VSync(0);
            }
            func_800739C0();
            func_80078D70();
            ResetGraph(3);
            PadStop();
            D_801F7740.exec.s_addr = 0x8001D4F0;
            D_801F7740.exec.s_size = 0;
            *index = next;
            func_8007FD1C();
            Exec(&D_801F7740.exec, 0, 0);
            printf(D_80088B58);
        }
        CdReset(0);
    }
}

void func_80078DB0(s16 arg0);

void func_80078EBC(s16 arg0) {
    func_80078DB0(arg0);
}
