#include "common.h"
#include "psyq/libspu.h"

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
extern struct Task *D_800B6DE0;
extern void (*D_800B7350)(void);

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

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80087F7C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80087F80);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80087F90);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80087FA0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088098);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800880E0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800880F4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088100);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088110);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088154);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008817C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008818C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088198);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881A4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881B0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881C8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881D4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881E0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881EC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800881F8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088218);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008822C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088240);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088258);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088270);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008827C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008828C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008829C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882AC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882B8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882C4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882D4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800882F4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088304);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088310);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008831C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088328);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088334);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088340);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088350);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088360);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008836C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088378);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088384);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088390);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008839C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800883AC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800883C4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800883E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800883F0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800883FC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088408);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088488);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800884A0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800884AC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800884B8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800884C8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800884D4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800885FC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088614);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_8008864C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088684);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800886B4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800886C4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800887E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088804);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088824);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088834);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088848);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088858);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088868);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008887C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088888);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088898);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888A8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888B4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888C0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888D0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888DC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888E8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800888F4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008890C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088918);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088924);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088930);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008893C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088948);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088954);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088964);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088970);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088984);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088990);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800889A0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800889B8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800889D0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800889DC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800889F8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088A14);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088A2C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088A50);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088A64);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088A78);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088A94);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AA8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AB8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AC8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AD4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088AF8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088B14);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088B2C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088B4C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088B58);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088B64);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088B84);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088BA4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088BC4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088BE4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088BF4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C04);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C18);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C2C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C44);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C5C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C70);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C78);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C84);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C90);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088C9C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CA8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CB4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CC0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CCC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CD0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CDC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CEC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088CF8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D00);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D0C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D18);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D20);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D2C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D38);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D44);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D50);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D58);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D64);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D6C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D74);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D80);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D88);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088D94);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DA0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DAC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DB4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DC4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088DEC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E08);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E1C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80088E28);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E3C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E44);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E50);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E58);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E68);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088E70);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EA4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EB0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EBC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EC8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088EF0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088F0C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088F20);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088F38);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088F6C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088F88);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088FA4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088FC0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088FD0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80088FE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089014);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089034);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089048);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089060);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008908C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800890A0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800890BC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800890D0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800890E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800890F0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089104);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089108);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089114);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089120);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008912C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089138);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089150);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089168);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008917C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089194);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800891B0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800891C8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800891FC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089214);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008922C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008923C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089254);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089264);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008927C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089288);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089294);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800892B0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800892CC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800892D8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800892E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_800892FC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089380);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008939C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800893AC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800893BC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800893E4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008941C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008942C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089440);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", jtbl_80089454);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089508);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008950C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089530);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089534);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8008953C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089540);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089544);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089550);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089554);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001E470);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001E6EC);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001E890);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001ED90);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001F744);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001F90C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001FB8C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8001FD90);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80020030);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80020278);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80020444);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002090C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80020AFC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80020E50);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800214A8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80021624);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800217DC);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80021BC8);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80021EDC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002225C);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80022460);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80022528);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800226B0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80022974);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80022A10);

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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80022CA8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002318C);

extern s16 D_800B7430;
extern struct Task *D_801F759C;
extern struct Task *D_801F75A0;
struct Task *func_80072F2C(void (*fn)(), s16 size);
void func_8006E740(void);
void func_800469A8(void);
void func_8006FDB8(void);
void func_80046498(void);

void func_800234D8(void) {
    D_801F759C = func_80072F2C(func_8006E740, 0x4C);
    if (D_800B7430 == 5 || D_800B7430 == 6) {
        func_80072F2C(func_800469A8, 0);
    }
    if (D_800B7430 == 7) {
        func_80072F2C(func_8006FDB8, 0x164);
        func_80072F2C(func_8006FDB8, 0x164);
        func_80072F2C(func_8006FDB8, 0x164);
        func_80072F2C(func_8006FDB8, 0x164);
    }
    D_801F75A0 = func_80072F2C(func_80046498, 0x28);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002359C);

extern s16 D_800B6FC0;
int SetDispMask(int mask);

void func_8002370C(void) {
    if (D_800B6FC0 != 0 && --D_800B6FC0 == 0) {
        SetDispMask(1);
    }
}

extern s16 D_800B6FC0;
int SetDispMask(int mask);

void func_80023754(s32 mask) {
    VSync(0);
    SetDispMask(0);
    D_800B6FC0 = mask;
}

extern s16 D_800B6AF8;
extern s16 D_800B6AA0;
extern s16 D_800B70B8;
extern void func_800789FC(void);
extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern int VSync(int mode);
void func_800739C0(void);
void func_80071EEC(void);
void func_80022B58(void);
void func_80071FDC(void);
void func_800720E4(void);

void func_8002378C(void) {
    s16 i;

    if (D_800B6AF8 == 2) {
        D_800B6AA0 = 2;
        i = 19;
        func_800789FC();
        CdControlB(8, 0, 0);
        do {
            VSync(0);
        } while (i--);
        func_800739C0();
        func_80071EEC();
        D_800B70B8 = 2;
        func_80022B58();
        func_80071FDC();
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_800720E4;
        }
    }
}

extern s16 D_800B72E0;
extern s16 D_800B6AF8;
extern s16 D_800B6AA0;
extern s32 DrawSync(s32 mode);
extern void StopPAD(void);
extern s16 D_800B6D38;
void func_8003D7BC(void);
void func_80023754(s32 mask);
void func_800735F8(s16 mask);
void func_80073D10(void);
void func_80023920(void);

void func_80023858(void) {
    D_800B6DE0->unk14 = 0;
    if (D_800B72E0 == 0) {
        func_8003D7BC();
        D_800B6AF8 = 1;
        D_800B6D38 = 0;
        D_800B6AA0 = 2;
        func_80023754(2);
        DrawSync(0);
        func_8001EB30();
        StopPAD();
        func_800735F8(1);
        func_80073D10();
    }
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80023920;
    }
    func_80023920();
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800897A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800897F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089804);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80089808);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80092AD4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80092B14);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800932D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800932DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800933B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800933B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009348C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800934BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800934EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009351C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093520);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093524);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009357C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093594);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800935AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800935BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800935D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800935EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800935F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093604);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093610);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009361C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009362C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093638);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093648);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093658);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093668);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093674);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093680);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093694);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800936FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009370C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009371C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009372C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093738);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093744);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093750);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093760);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009376C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093780);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009378C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009379C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800937A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800937B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800937CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800937D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800937F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009380C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093818);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093828);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093834);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093844);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093858);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093868);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093874);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093888);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009389C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800938FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009390C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093918);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093924);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093934);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093944);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093958);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009396C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093980);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093990);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800939F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093A04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093A1C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093A3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093A4C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093A58);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093B80);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093C3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093CF4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093E08);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80093EC0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009402C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094198);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094304);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094470);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800945DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094710);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009487C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800949E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094B54);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094B64);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094B74);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094B94);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094BAC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094BB0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094C0C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094CAC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094CB0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094CFC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094E00);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80094E60);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095310);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095620);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095630);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095640);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095DC8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095E34);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095E84);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F70);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F78);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F88);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F8C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F90);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80095F94);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800960F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096104);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096108);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096728);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096734);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096738);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800967C8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096828);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800968E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800968F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800968FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800969C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800969D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096A80);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096A8C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096A90);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096CB0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096CB4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096CB8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F20);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F48);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F68);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F78);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F88);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096F90);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096FB4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096FC4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80096FE8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009700C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009701C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097020);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097024);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097028);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009702C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097030);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097034);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800971B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800971D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097250);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800972D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097350);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097358);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009735C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097364);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097368);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009739C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800973AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800973CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800973EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009748C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009749C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800974B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800974C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097540);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800975DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097678);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097714);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097734);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097748);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097770);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800977B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800977D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800977E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800977F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009780C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009784C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800978E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097984);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097A20);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097ABC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097BE4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097C04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097C24);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097CA4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097D24);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097DA4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097DC4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097E04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097EA0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097F3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80097FD8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80098074);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80098110);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800981AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_80098248);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800982E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009A2E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B344);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B444);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B464);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B468);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B46C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B470);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B474);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B478);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B47C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B480);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B484);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B488);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009B48C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009F164);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_8009F72C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1DEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1F0C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1FE4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1FE8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1FEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A1FF0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A200C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2190);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2194);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2198);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A219C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21C8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21F0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A21FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2200);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2208);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A220C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2210);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2214);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2218);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2248);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A224C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2250);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2650);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2654);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2658);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A265C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2660);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A26B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2958);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A295C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2960);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2964);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2968);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A296C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2970);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2974);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2978);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A297C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2980);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2984);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2988);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A08);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A0C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A14);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A18);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A1C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A20);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A24);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A28);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2A2C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2AAC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2ACC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2B4C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2BCC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2C4C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CB0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CCC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CD0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CD4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CD8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CDC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CE0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CE4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2CE8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D00);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D08);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D0C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D10);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D24);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D2C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D30);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D34);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D38);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D40);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D44);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D54);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2D6C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2DE4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2DE8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2DEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2DFC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2E00);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2E04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2E30);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2E34);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A2E3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E68);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E88);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E8C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E90);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E94);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E98);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3E9C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EA0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EC0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EC4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EE4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EE8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EF0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EF4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EF8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3EFC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F3C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F40);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F44);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F48);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F4C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F50);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3F54);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FB0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FB4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FB8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FBC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FC0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FC4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FD8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FF4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FF8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A3FFC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4000);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4014);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4018);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A401C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4020);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4024);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4028);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A402C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4030);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4034);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4038);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A403C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4040);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4048);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A404C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4050);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4054);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4058);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A405C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4060);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4064);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4074);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4080);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4084);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4088);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A408C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4090);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A41E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A41E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A41EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4BEC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4BF0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4BF4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4C00);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4C04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4E84);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4F04);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A4F14);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A5094);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A5098);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A50D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A5118);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A511C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A519C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A51D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800A59D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B59D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B61D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B61E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B61F0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B61F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B61FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6214);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B621C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6230);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6238);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6240);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6250);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6258);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B625C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6260);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6268);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B626C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6278);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6280);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6288);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6290);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6294);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6298);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62C8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B62FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6304);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B630C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6314);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B631C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6324);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B632C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6334);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B633C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6344);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B634C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6354);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B635C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6364);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B636C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6374);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80023920);

extern s16 D_800B6B08;
extern s16 D_800B6AF8;
void func_8002378C(void);

void func_80023A68(void) {
    struct Task *t;

    if (D_800B6B08 == 6) {
        D_800B6AF8 = 1;
        t = D_800B6DE0;
        if (t->func == D_800B7350) {
            TRAP();
        } else {
            t->func = func_8002378C;
        }
    }
}

void func_8003DAC4(void);

void func_80023AC0(void) {
    struct Task *t;

    func_80072F2C(func_8003DAC4, 0x10);
    t = D_800B6DE0;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_80023A68;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80023B20);

extern s16 D_800B7260;
extern s16 D_800B6A64;
extern s16 D_800B6C10;
extern s16 D_800B6430;
void func_80023E40(void);
void func_80023B20(void);

void func_80023DA0(void) {
    D_800B6B08 = 7;
    D_800B6A64 = 0;
    D_800B6C10 = 0;
    D_800B6430 = -1;
    D_800B7430 = D_800B7260;
    func_80023E40();
    func_80072F2C(func_8003DAC4, 0x10);
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80023B20;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80023E40);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024124);

typedef struct {
    u8 disp[0x14];
    u8 draw[0x5C];
} Unk801D9A20;

extern volatile u16 D_800B7400;
extern Unk801D9A20 D_801D9A20[];
extern volatile s16 D_800B6F80;
extern volatile s16 D_800B6F10;
extern void PutDispEnv(void *env);

void func_80024274(void) {
    PutDispEnv(&D_801D9A20[(s16)D_800B7400]);
    D_800B6F80 = D_800B7400;
    D_800B6F10 = 0;
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 w, h;
} TILE;

extern TILE D_800934EC;
extern s32 DrawSync(s32 mode);
extern void SetTile(TILE *p);
extern void DrawPrim(void *p);

void func_800242D4(void) {
    DrawSync(-1);
    SetTile(&D_800934EC);
    DrawPrim(&D_800934EC);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024314);

extern s32 D_800B7198;
extern s32 D_800B6F30;

s32 func_80024664(s16 n) {
    if (D_800B7198 & 0xFFFFE000) {
        return -1;
    }
    if (D_800B6F30 < n) {
        return -1;
    }
    if (D_800B6F30 > 6000) {
        return -1;
    }
    return 0;
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

extern Unk800B7370 *D_800B7370;
extern s16 D_800B70E8;
extern s16 D_800B71C8;

void func_800246A8(s16 arg0) {
    D_800B70E8 = arg0;
    if (D_800B7370->unk178A == 0) {
        D_800B71C8 = 0x100;
    } else {
        D_800B71C8 = 0xF0;
    }
}

s32 func_800246DC(u8 *p, s32 n) {
    s32 sum = 0;

    while (n--) {
        sum += *p++;
    }
    return sum;
}

extern s16 D_800B639E;
extern int func_80072734(s32 a, s32 b, s32 t);

s16 func_8002470C(s16 a, s16 b) {
    s16 t = D_800B639E * 682;

    if (D_800B639E < 3) {
        return a;
    }
    if (t > 0x1000) {
        t = 0x1000;
    }
    return func_80072734(a, b, t);
}

s16 func_80024790(s32 v, s32 lim) {
    s32 m = ABS(v);

    lim = ABS(lim);
    if (m < lim) {
        return v;
    }
    if (v < 0) {
        return -lim;
    }
    return lim;
}

extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
extern MATRIX D_801F9644;
extern MATRIX *func_8002702C(SVECTOR *r, MATRIX *m);

void func_800247D0(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_8002702C(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024864);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024914);

extern s32 *D_800B71F0;

void func_80024AF8(s32 *src, u32 size) {
    u32 n = (size + 15) >> 4;
    s32 *dst = D_800B71F0;

    while (n-- != 0) {
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
    }
    D_800B71F0 = (s32 *)func_80024F60((s32)dst);
}

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Unk8002A35C;

extern Unk8002A35C D_800B67D0;
s32 func_80025254(Unk8002A35C *a, Unk8002A35C *b);
s32 func_80077398(Unk8002A35C *a, Unk8002A35C *b);

void func_80024B8C(Unk8002A35C *from, Unk8002A35C *to, Unk8002A35C *out) {
    Unk8002A35C d;

    out->y = -func_80025254(from, to);
    d.z = func_80077398(from, to);
    d.x = to->y - from->y;
    out->x = func_80025254(&D_800B67D0, &d) - 0x800;
    out->z = 0;
}

extern VECTOR D_801F7848;
extern VECTOR D_80093A3C;
s32 func_800253D0(VECTOR *a, VECTOR *b);

void func_80024C0C(VECTOR *from, VECTOR *to, SVECTOR *rot) {
    rot->vy = -func_800253D0(from, to);
    D_801F7848.vx = to->vy - from->vy;
    D_801F7848.vz = func_800257F4(from, to);
    rot->vx = func_800253D0(&D_80093A3C, &D_801F7848) - 0x800;
    rot->vz = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024C98);

void func_80024DE4(MATRIX *m, s16 scale) {
    m->m[2][0] = (m->m[2][0] * scale) >> 12;
    m->m[2][1] = (m->m[2][1] * scale) >> 12;
    m->m[2][2] = (m->m[2][2] * scale) >> 12;
}

typedef struct {
    s16 x, y, z;
    s16 rx, ry, rz;
} Unk80024E40;

void func_80024E40(Unk80024E40 *p) {
    p->x = p->x * 2;
    p->y = p->y * 2;
    p->z = p->z * 2;
    p->rx = p->rx * 381 >> 9;
    p->ry = p->ry * 381 >> 9;
    p->rz = p->rz * 381 >> 9;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80024EBC);

s32 func_80024F08(s32 a, s32 b, s32 t) {
    s32 d = (b - a) << 20 >> 20;

    return a + (t * d >> 12);
}

s32 func_80024F30(s32 a, s32 b) {
    if (b < a) {
        return b;
    }
    return a;
}

s32 func_80024F4C(s32 base, s32 size) {
    return (base + size + 3) & ~3;
}

s32 func_80024F60(s32 size) {
    return (size + 3) & ~3;
}

extern MATRIX *func_80027898(SVECTOR *r, MATRIX *m);

void func_80024F70(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80027898(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern MATRIX *func_80026E04(SVECTOR *r, MATRIX *m);

void func_80025004(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80026E04(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

void func_80025098(SVECTOR *rot, SVECTOR *v, VECTOR *base, VECTOR *out) {
    VECTOR tmp;

    func_80027898(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

void func_8002512C(SVECTOR *rot, SVECTOR *v, VECTOR *base, VECTOR *out) {
    VECTOR tmp;

    func_8002702C(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern MATRIX *func_80027444(SVECTOR *r, MATRIX *m);

void func_800251C0(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80027444(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern s32 SquareRoot0(s32 a);
extern s32 func_80025B40(s32 x);
extern s16 D_8009F164[];

s32 func_80025254(Unk8002A35C *a, Unk8002A35C *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s32 adx = func_80025B40(dx);
    s32 adz = func_80025B40(dz);
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
        ang = 0x400 - D_8009F164[c];
    } else {
        ang = D_8009F164[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return (s16)(0x1000 - ang);
}

extern s16 D_8009F164[];
s32 func_80025B40(s32 x);

s32 func_800253D0(VECTOR *a, VECTOR *b) {
    s32 dx = a->vx - b->vx;
    s32 dz = a->vz - b->vz;
    s32 adx = func_80025B40(dx);
    s32 adz = func_80025B40(dz);
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
        ang = 0x400 - D_8009F164[c];
    } else {
        ang = D_8009F164[s];
    }
    if (dz < 0) {
        ang = 0x800 - ang;
    }
    if (dx < 0) {
        ang = 0x1000 - ang;
    }
    return (s16)(0x1000 - ang);
}

s32 func_80025570(s32 value, s32 target, s32 step) {
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

s32 func_800255BC(s32 value, s32 target, s32 step) {
    s32 d = (value - target) << 20 >> 20;

    if (func_80025B40(d) <= (s16)step) {
        return target & 0xFFF;
    }
    if (d < 0) {
        return (value + step) & 0xFFF;
    }
    return (value - step) & 0xFFF;
}

s32 func_80025634(SVECTOR *a, SVECTOR *b) {
    s32 dx = a->vx - b->vx;
    s32 dy = a->vy - b->vy;
    s32 dz = a->vz - b->vz;

    return SquareRoot0(dx * dx + dy * dy + dz * dz);
}

extern s32 func_80025B40(s32 x);

s32 func_800256A4(VECTOR *a, VECTOR *b) {
    s32 dx = (a->vx - b->vx) >> 4;
    s32 dy = (a->vy - b->vy) >> 4;
    s32 dz = (a->vz - b->vz) >> 4;

    if (func_80025B40(dx) <= 0x4000 && func_80025B40(dz) <= 0x4000) {
        return SquareRoot0(dx * dx + dy * dy + dz * dz) << 4;
    }
    return 0xFFFF;
}

s32 func_8002576C(SVECTOR *a, SVECTOR *b) {
    s32 dx = a->vx - b->vx;
    s32 dz = a->vz - b->vz;

    if ((dx < 0 ? -dx : dx) > 0x400 || (dz < 0 ? -dz : dz) > 0x400) {
        return 0xFFFF;
    }
    return SquareRoot0(dx * dx + dz * dz);
}

typedef struct {
    s32 vx;
    s32 vy;
    s32 vz;
} Vec32;

extern s32 SquareRoot0(s32 a);

s32 func_800257F4(Vec32 *a, Vec32 *b) {
    s32 dx = a->vx - b->vx;
    s32 dz;
    s32 sum;

    dx = (dx < 0) ? -dx : dx;
    sum = dx * dx;
    dz = a->vz - b->vz;
    dz = (dz < 0) ? -dz : dz;
    return SquareRoot0(sum + dz * dz);
}

extern s32 SquareRoot0(s32);

void func_80025860(SVECTOR *v) {
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

s32 func_80025998(SVECTOR *v) {
    return SquareRoot0(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
}

s32 func_800259F8(VECTOR *v) {
    return SquareRoot0(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80025A58);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80025AC0);

s32 func_80025B40(s32 x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

s32 func_80025B58(VECTOR *p, VECTOR *a, VECTOR *b) {
    s32 dot;
    s32 len;

    dot = ((p->vz - b->vz) * (p->vz - a->vz) - (p->vx - b->vx) * (a->vx - p->vx) + 0x800) >> 12;
    len = ((p->vx - a->vx) * (p->vx - a->vx) + (p->vz - a->vz) * (p->vz - a->vz) + 0x800) >> 12;
    if (len + 0x800 < dot) {
        return -1;
    }
    if (dot < -0x800 || len == 0) {
        return -1;
    }
    return (dot << 12) / len;
}

s32 func_80025C30(VECTOR *a, VECTOR *b, VECTOR *p) {
    s32 ax = a->vx;
    s32 az = a->vz;
    s32 bx = b->vx;
    s32 bz = b->vz;
    s32 dz = az - p->vz;
    s32 ux = bx - ax;
    s32 dx = ax - p->vx;
    s32 dist = func_80025B40(dz * ux - dx * (bz - az)) >> 16;
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

extern int func_80072734(s32 a, s32 b, s32 t);

void func_80025D44(s16 *a, s16 *b, s16 t, s16 *out) {
    out[0] = func_80072734(a[0], b[0], t);
    out[1] = func_80072734(a[1], b[1], t);
    out[2] = func_80072734(a[2], b[2], t);
}

void func_80025DC8(u8 *a, u8 *b, s16 t, u8 *out) {
    out[0] = func_80072734(a[0], b[0], t);
    out[1] = func_80072734(a[1], b[1], t);
}

extern u8 D_801F635C[];

void func_80025E38(void) {
    s16 i, j, t;

    i = 7;
    do {
        j = 0xFF;
        do {
            t = j - 20;
            if (t < 0) {
                t = 0;
            }
            t += i;
            if (t > 7) {
                t = 7;
            }
            D_801F635C[i * 256 + j] = t + 0x16;
        } while (j--);
    } while (i--);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80025EC4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002625C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80026464);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800267F0);

u8 func_80026988(u8 c, s16 k) {
    s16 v = ((c - 0x80) * k >> 12) + 0x80;

    if (v < 0) {
        return 0;
    }
    if (v < 0x100) {
        return v;
    }
    return 0xFF;
}

extern unsigned short D_801F9DCC[];
extern void SetFarColor(long rfc, long gfc, long bfc);
void func_800267F0(unsigned short *src, s16 t);

void func_800269D8(unsigned short *src, s16 t, u8 r, u8 g, u8 b, s16 flag) {
    unsigned short *dst;
    u8 col[3];
    unsigned short i;
    int semi;
    unsigned short stp;

    SetFarColor(r, g, b);
    dst = D_801F9DCC;
    if (flag) {
        func_800267F0(src, t);
        return;
    }
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
            col[0] = func_80072734(col[0], 0, t);
            col[1] = func_80072734(col[1], 0, t);
            col[2] = func_80072734(col[2], 0, t);
        }
        *dst++ = stp | (((col[0] >> 3) + ((col[1] >> 3) << 5) + ((col[2] >> 3) << 10)) & 0x7FFF);
    }
}

extern unsigned short D_801F9DCC[16];

void func_80026B68(unsigned short *src) {
    unsigned short *dst = D_801F9DCC;
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80026BB8);

extern s16 D_800982E4[];

MATRIX *func_80026E04(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    s16 cxsy, sxsy;

    cx = D_800982E4[(-(u16)r->vx + 0x400) & 0xFFF];
    sy = D_800982E4[-(u16)r->vy & 0xFFF];
    sx = D_800982E4[-(u16)r->vx & 0xFFF];
    cxsy = (cx * sy) >> 12;
    sxsy = (sx * sy) >> 12;
    cy = D_800982E4[(-(u16)r->vy + 0x400) & 0xFFF];
    cz = D_800982E4[(-(u16)r->vz + 0x400) & 0xFFF];
    sz = D_800982E4[-(u16)r->vz & 0xFFF];
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

MATRIX *func_8002702C(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    u16 ax, ay, az;
    s32 cxsy, cxcy, sxsy, sxcy;

    ax = r->vx;
    ay = r->vy;
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
    sy = D_800982E4[ay & 0xFFF];
    cxsy = cx * sy;
    cy = D_800982E4[(ay + 0x400) & 0xFFF];
    cxcy = cx * cy;
    sx = D_800982E4[ax & 0xFFF];
    sxsy = sx * sy;
    sxcy = sx * cy;
    az = r->vz;
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
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

MATRIX *func_80027230(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, cy, sy, cz, sz;
    u16 ax, ay, az;
    s32 cxsy, cxcy, sxsy, sxcy;

    ax = r->vx;
    ay = r->vy;
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
    sy = D_800982E4[-ay & 0xFFF];
    cxsy = cx * sy;
    cy = D_800982E4[(-ay + 0x400) & 0xFFF];
    cxcy = cx * cy;
    sx = D_800982E4[ax & 0xFFF];
    sxsy = sx * sy;
    sxcy = sx * cy;
    az = r->vz;
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
    m->m[0][0] = -(cy * cz >> 12);
    m->m[0][1] = -((-(s16)(cxcy >> 12) * sz - sxsy) >> 12);
    m->m[0][2] = -(((s16)(sxcy >> 12) * sz - cxsy) >> 12);
    m->m[1][0] = sz;
    m->m[1][1] = (u32)(cx * cz) >> 12;
    m->m[1][2] = (u32)(-sx * cz) >> 12;
    m->m[2][0] = (u32)(sy * cz) >> 12;
    m->m[2][1] = (u32)(-(s16)(cxsy >> 12) * sz + sxcy) >> 12;
    m->m[2][2] = (u32)((s16)(sxsy >> 12) * sz + cxcy) >> 12;
    return m;
}

MATRIX *func_80027444(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800982E4[ax & 0xFFF];
    sy = D_800982E4[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800982E4[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
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

MATRIX *func_80027674(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800982E4[ax & 0xFFF];
    sy = D_800982E4[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800982E4[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
    m->m[0][0] = (u32)(cy * cz + (s16)(sxsy >> 12) * sz) >> 12;
    m->m[0][1] = (u32)(-cx * sz) >> 12;
    m->m[0][2] = (u32)(-sy * cz + (s16)(sxcy >> 12) * sz) >> 12;
    m->m[1][0] = -((cy * sz - (s16)(sxsy >> 12) * cz) >> 12);
    m->m[1][1] = -((cx * cz) >> 12);
    m->m[1][2] = -((-sy * sz - (s16)(sxcy >> 12) * cz) >> 12);
    m->m[2][1] = sx;
    m->m[2][0] = (u32)(cx * sy) >> 12;
    m->m[2][2] = (u32)(cx * cy) >> 12;
    return m;
}

MATRIX *func_80027898(SVECTOR *r, MATRIX *m) {
    s16 cx, sx, sy, sz;
    s32 cy, cz;
    u16 ax, ay, az;
    s32 cxsy, sxsy;

    ax = r->vx;
    ay = r->vy;
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
    sy = D_800982E4[ay & 0xFFF];
    cxsy = cx * sy;
    sx = D_800982E4[ax & 0xFFF];
    sxsy = sx * sy;
    az = r->vz;
    cy = D_800982E4[(ay + 0x400) & 0xFFF];
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80027AB4);

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
} Unk8002B728_Prim;

typedef struct {
    SVECTOR *v[4];
    u16 tex;
    u16 clut;
} Unk8002B728_Face;

extern Unk8002B728_Prim *D_800B6B90;
extern s32 D_800B6A90;
extern s32 D_800B6F30;
extern s32 D_800B7198;
extern u8 D_8015EB78[];
extern s32 RotNclip4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *otz, s32 *flag);
extern void SetPolyFT4(void *p);
extern void SetShadeTex(void *p, s32 tge);
extern void SetSemiTrans(void *p, s32 abe);
extern void AddPrim(void *ot, void *p);
extern void *D_800B7140;
extern u32 *D_800B7018;
extern s32 RotTransPers4(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *sxy3, s32 *p, s32 *flag);

Unk8002B728_Face *func_80027F18(u8 n, Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    while (n--) {
        if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
            prim = D_800B6B90;
            tex = (u16 *)(D_8015EB78 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
            *(s16 *)&prim->uv2 = tex[4];
            *(s16 *)&prim->uv3 = tex[6];
            D_800B6B90 = prim + 1;
            prim->clut = tex[(f->clut >> 8) + 22];
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
        }
        f++;
    }
    return f;
}

Unk8002B728_Face *func_80028068(u8 n, Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    while (n--) {
        if (RotNclip4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B6B90->xy2, &D_800B6B90->xy3, &D_800B6B90->xy1, &D_800B6B90->xy0, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
            prim = D_800B6B90;
            tex = (u16 *)(D_8015EB78 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
            *(s16 *)&prim->uv2 = tex[4];
            *(s16 *)&prim->uv3 = tex[6];
            D_800B6B90 = prim + 1;
            prim->clut = tex[(f->clut >> 8) + 22];
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
        }
        f++;
    }
    return f;
}

Unk8002B728_Face *func_800281B8(u8 n, Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    while (n--) {
        D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), prim);
        f++;
    }
    return f;
}

void func_800282F4(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

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
} Unk8002BA84_Prim;

extern s32 RotTransPers3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *flag);
extern void SetPolyFT3(void *p);

extern s32 RotNclip3(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, s32 *sxy0, s32 *sxy1, s32 *sxy2, s32 *p, s32 *otz, s32 *flag);

extern u8 *D_800B70A8;

extern s32 D_800B6DA0;
extern s32 D_800B6DA8;
extern s32 D_800B6DB0;
extern void func_80085190(s32 *sz0, s32 *sz1, s32 *sz2);

void func_80028408(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    Unk8002BA84_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        D_800B6F30 = (D_800B6DA0 >> 2) - 0x80;
        if (D_800B6F30 > 0) {
            prim++;
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
            D_800B7140 = prim;
        }
    }
}

void func_800285C8(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    Unk8002BA84_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF)) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        D_800B6F30 = (D_800B6DA0 >> 2) - 0x80;
        if (D_800B6F30 >= 0x80 && D_800B6F30 < 0x1771) {
            prim++;
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
            D_800B7140 = prim;
        }
    }
}

extern s32 D_800B6DB8;
extern void func_800851B0(s32 *sz0, s32 *sz1, s32 *sz2, s32 *sz3);

void func_800287A8(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        func_800851B0(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0, &D_800B6DB8);
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        if (D_800B6DB8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB8;
        }
        D_800B6F30 = (D_800B6DA0 >> 2) - 0x80;
        if (D_800B6F30 > 0) {
            D_800B6B90 = prim + 1;
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80028978);

void func_80028CF0(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF) && D_800B6F30 >= 0x80 && D_800B6F30 < 0x1771) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[6];
        prim->tpage = tex[3];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

void func_80028E40(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[0], f->v[1], f->v[2], f->v[3], &D_800B6B90->xy2, &D_800B6B90->xy3, &D_800B6B90->xy1, &D_800B6B90->xy0, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[6];
        prim->tpage = tex[3];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

void func_80028F60(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    D_800B6B90 = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 22];
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80029064);

void func_80029334(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim = D_800B7140;
    Unk8002B728_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD75F) {
        return;
    }
    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800B6A90, &D_800B7198);
    if (!(D_800B7198 & ~0x1FFF)) {
        func_800851B0(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0, &D_800B6DB8);
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT4(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        if (D_800B6DB8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB8;
        }
        D_800B6F30 = D_800B6DA0 >> 2;
        if (D_800B6F30 > 0 && D_800B6F30 < 0x1771) {
            prim++;
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
            D_800B7140 = prim;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80029558);

void func_80029868(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[(f->clut >> 8) + 22];
    D_800B6B90 = prim + 1;
    AddPrim(D_800B7018 + 0x300, prim);
}

void func_80029960(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        D_800B6B90 = prim + 1;
        AddPrim(D_800B7018 + 0x300, prim);
    }
}

void func_80029A6C(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[2], f->v[3], f->v[0], f->v[1], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    D_800B6B90 = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 22];
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
}

void func_80029B70(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    D_800B6B90 = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 22];
    AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), prim);
}

void func_80029C74(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[6];
    prim->tpage = tex[3];
    D_800B6B90 = prim + 1;
    prim->clut = tex[(f->clut >> 8) + 22];
    AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), prim);
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

extern u8 D_800B73E0;

void func_80029D84(Unk8002B728_Face *f) {
    POLY_FT4 *prim;
    u16 *tex;
    u8 v;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        func_800851B0(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0, &D_800B6DB8);
        prim = (POLY_FT4 *)D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u16 *)&prim->u0 = tex[0];
        *(u32 *)&prim->u1 = *(u32 *)(tex + 18);
        *(u16 *)&prim->u2 = tex[4];
        *(u16 *)&prim->u3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        v = prim->v1 | D_800B73E0;
        prim->v1 = v;
        prim->v0 = v;
        prim->v3 = v + 0x1F;
        prim->v2 = v + 0x1F;
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        if (D_800B6DB8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB8;
        }
        D_800B6F30 = D_800B6DA0 >> 2;
        if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0 && D_800B6F30 < 0x1771) {
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        }
    }
}

void func_80029F98(Unk8002B728_Face *f) {
    POLY_FT4 *prim;
    u16 *tex;
    u8 v;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        func_800851B0(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0, &D_800B6DB8);
        prim = (POLY_FT4 *)D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u16 *)&prim->u0 = tex[0];
        *(u32 *)&prim->u1 = *(u32 *)(tex + 18);
        *(u16 *)&prim->u2 = tex[4];
        *(u16 *)&prim->u3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        v = prim->v1 | D_800B73E0;
        prim->v1 = v;
        prim->v0 = v;
        prim->v3 = v + 0x1F;
        prim->v2 = v + 0x1F;
        if (D_800B6DA8 > D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 > D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        if (D_800B6DB8 > D_800B6DA0) {
            D_800B6DA0 = D_800B6DB8;
        }
        D_800B6F30 = (D_800B6DA0 >> 2) + 0x80;
        if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0 && D_800B6F30 < 0x1771) {
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        }
    }
}

void func_8002A1B0(Unk8002B728_Face *f) {
    POLY_FT4 *prim;
    u16 *tex;
    u8 v;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        func_800851B0(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0, &D_800B6DB8);
        prim = (POLY_FT4 *)D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u16 *)&prim->u0 = tex[0];
        *(u32 *)&prim->u1 = *(u32 *)(tex + 18);
        *(u16 *)&prim->u2 = tex[4];
        *(u16 *)&prim->u3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        v = prim->v1 | (0x1F - D_800B73E0);
        prim->v1 = v;
        prim->v0 = v;
        prim->v3 = v + 0x1F;
        prim->v2 = v + 0x1F;
        if (D_800B6DA8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DA8;
        }
        if (D_800B6DB0 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB0;
        }
        if (D_800B6DB8 < D_800B6DA0) {
            D_800B6DA0 = D_800B6DB8;
        }
        D_800B6F30 = D_800B6DA0 >> 2;
        if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0 && D_800B6F30 < 0x1771) {
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002A3CC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002A86C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002ACD0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002B188);

void func_8002B61C(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B7018 + ((D_800B6F30 + 64) >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002B728(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim = D_800B7140;
    Unk8002B728_Prim *q = D_800B6B90;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &q->xy0, &q->xy1, &q->xy3, &q->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT4(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
        D_800B7140 = prim;
    }
}

void func_8002B86C(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002B974(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
        D_800B7140 = prim;
    }
}

void func_8002BA84(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    SetSemiTrans(prim, 1);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002BB98(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        prim->clut = tex[(f->clut >> 8) + 22];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        SetSemiTrans(prim, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
        D_800B7140 = prim;
    }
}

void func_8002BCB4(void) {
}

extern s16 D_800B6E20;
extern s16 D_800BD974[];

void func_8002BCBC(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF)) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex + D_800B6E20);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

void func_8002BDF4(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex + D_800BD974[f->tex & 7]);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        D_800B6B90 = prim + 1;
        prim->clut = tex[(f->clut >> 8) + 22];
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002BF28);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8002C2E8);

extern u8 D_801F635C[];

Unk8002B728_Face *func_8002C6A8(u8 n, Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    while (n--) {
        if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
            prim = D_800B6B90;
            tex = (u16 *)(D_8015EB78 + f->tex);
            prim->uv0 = tex[0];
            *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
            *(s16 *)&prim->uv2 = tex[4];
            *(s16 *)&prim->uv3 = tex[6];
            prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
            D_800B6B90 = prim + 1;
            AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
        }
        f++;
    }
    return f;
}

Unk8002B728_Face *func_8002C810(u8 n, Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    while (n--) {
        D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
        D_800B6B90 = prim + 1;
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
        f++;
    }
    return f;
}

void func_8002C964(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        *(s16 *)&prim->uv2 = tex[4];
        *(s16 *)&prim->uv3 = tex[6];
        prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
        D_800B6B90 = prim + 1;
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

void func_8002CA94(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv1 = tex[0];
        prim->uv0 = tex[2];
        *(s16 *)&prim->uv3 = tex[4];
        *(s16 *)&prim->uv2 = tex[6];
        prim->tpage = tex[3];
        prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
        D_800B6B90 = prim + 1;
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
    }
}

void func_8002CBCC(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    D_800B6B90 = prim + 1;
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim);
}

void func_8002CCE8(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    D_800B6B90 = prim + 1;
    AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), prim);
}

void func_8002CE08(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[6];
    prim->tpage = tex[3];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    D_800B6B90 = prim + 1;
    AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), prim);
}

void func_8002CF34(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    Unk8002BA84_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        prim->uv0 = tex[0];
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        *(s16 *)&prim->uv2 = tex[4];
        prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        prim++;
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
        D_800B7140 = prim;
    }
}

void func_8002D08C(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    Unk8002BA84_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    prim++;
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
    D_800B7140 = prim;
}

void func_8002D1D0(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    Unk8002BA84_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    prim++;
    AddPrim(D_800B7018 + ((D_800B6F30 + 0x200) >> 3), start);
    D_800B7140 = prim;
}

extern void RotTrans(SVECTOR *v, VECTOR *out, s32 *flag);
s16 func_8003BE74(Unk8002B728_Prim *p);

void func_8002D318(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    func_8002EDC4((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    D_800B6F30 += 0x40;
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
}

void func_8002D5AC(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

void func_8002D920(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) <= 0) {
        return;
    }
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

void func_8002DCA0(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[2], f->v[3], f->v[0], f->v[1], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    func_8002EDC4((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    D_800B6F30 += 0x40;
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
}

void func_8002DF34(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[2], f->v[3], f->v[0], f->v[1], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    u16 uv0;
    u16 clut;
    u8 r1, g1, b1, p1;
    s32 xy1;
    u16 uv1;
    u16 tpage;
    u8 r2, g2, b2, p2;
    s32 xy2;
    u16 uv2;
    u16 pad2;
    u8 r3, g3, b3, p3;
    s32 xy3;
    u16 uv3;
    u16 pad3;
} Unk8002E2A8_Prim;

extern void SetPolyGT4(void *p);

void func_8002E2A8(Unk8002B728_Face *f) {
    Unk8002E2A8_Prim *prim = D_800B7140;
    Unk8002E2A8_Prim *start = prim;
    u16 *tex;

    if ((u8 *)prim - D_800B70A8 > 0xD7CB) {
        return;
    }
    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy3, &prim->xy2, &D_800B6A90, &D_800B7198);
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    prim->uv2 = tex[4];
    prim->uv3 = tex[6];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    prim->r0 = 0;
    prim->g0 = 0;
    prim->b0 = 0;
    prim->r1 = 0;
    prim->g1 = 0;
    prim->b1 = 0;
    prim->r2 = 0x80;
    prim->g2 = 0x80;
    prim->b2 = 0x80;
    prim->r3 = 0x80;
    prim->g3 = 0x80;
    prim->b3 = 0x80;
    SetPolyGT4(prim);
    prim++;
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), start);
    D_800B7140 = prim;
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
} Unk8002F510_Prim;

void func_8002E434(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
        if (D_800B6F30 < 0) {
            D_800B6F30 = 0;
        }
    } else {
        if (prim->y0 > 0x154) {
            prim->y0 = 0x154;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x154) {
            prim->y1 = 0x154;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x154) {
            prim->y2 = 0x154;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0xc8) {
            prim->x0 = -0xc8;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0xc8) {
            prim->x1 = -0xc8;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0xc8) {
            prim->x2 = -0xc8;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    *(s16 *)&prim->uv2 = tex[4];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002E75C(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B6F30, &D_800B7198) <= 0) {
        return;
    }
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
        if (D_800B6F30 < 0) {
            D_800B6F30 = 0;
        }
    } else {
        if (prim->y0 > 0x154) {
            prim->y0 = 0x154;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x154) {
            prim->y1 = 0x154;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x154) {
            prim->y2 = 0x154;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0xc8) {
            prim->x0 = -0xc8;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0xc8) {
            prim->x1 = -0xc8;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0xc8) {
            prim->x2 = -0xc8;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    *(s16 *)&prim->uv2 = tex[4];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002EA90(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
        if (D_800B6F30 < 0) {
            D_800B6F30 = 0;
        }
    } else {
        if (prim->y0 > 0x154) {
            prim->y0 = 0x154;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x154) {
            prim->y1 = 0x154;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x154) {
            prim->y2 = 0x154;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0xc8) {
            prim->x0 = -0xc8;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0xc8) {
            prim->x1 = -0xc8;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0xc8) {
            prim->x2 = -0xc8;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    *(s16 *)&prim->uv2 = tex[4];
    prim->clut = tex[D_801F635C[(D_800B6F30 >> 7) + (f->clut & 0x700)]];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    D_800B6F30 += 0x40;
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002EDC4(POLY_FT4 *p, POLY_FT4 *q) {
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

void func_8002EEBC(POLY_FT4 *p, POLY_FT4 *q) {
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

void func_8002EFF8(POLY_FT4 *p, POLY_FT4 *q) {
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

extern s16 D_800B70E8;
extern s16 D_800B71C8;

void func_8002F144(s16 *out, VECTOR *v) {
    s32 x, y;

    if (v->vz < 16) {
        x = D_800B70E8 / 2 + v->vx * 16;
        y = D_800B71C8 / 2 + v->vy * 16;
        if (x > 800) {
            x = 800;
        }
        if (x < -300) {
            x = -300;
        }
        if (y > 511) {
            y = 511;
        }
        if (y < -250) {
            y = -250;
        }
        out[0] = x;
        out[1] = y;
    }
}

void func_8002F1E4(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
    } else {
        if (prim->y0 > 0x1ff) {
            prim->y0 = 0x1ff;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x1ff) {
            prim->y1 = 0x1ff;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x1ff) {
            prim->y2 = 0x1ff;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0x12c) {
            prim->x0 = -0x12c;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0x12c) {
            prim->x1 = -0x12c;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0x12c) {
            prim->x2 = -0x12c;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002F510(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    if (RotNclip3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B6F30, &D_800B7198) <= 0) {
        return;
    }
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
    } else {
        if (prim->y0 > 0x1ff) {
            prim->y0 = 0x1ff;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x1ff) {
            prim->y1 = 0x1ff;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x1ff) {
            prim->y2 = 0x1ff;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0x12c) {
            prim->x0 = -0x12c;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0x12c) {
            prim->x1 = -0x12c;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0x12c) {
            prim->x2 = -0x12c;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002F834(Unk8002B728_Face *f) {
    Unk8002F510_Prim *prim = D_800B7140;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    if ((u8 *)prim - D_800B70A8 > 0xD7DF) {
        return;
    }
    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], (s32 *)&prim->x0, (s32 *)&prim->x1, (s32 *)&prim->x2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0) {
            return;
        }
        func_8002F144(&prim->x0, &v2);
        func_8002F144(&prim->x1, &v1);
        func_8002F144(&prim->x2, &v0);
        D_800B6F30 = v0.vz >> 2;
    } else {
        if (prim->y0 > 0x1ff) {
            prim->y0 = 0x1ff;
        }
        if (prim->y0 < -0xfa) {
            prim->y0 = -0xfa;
        }
        if (prim->y1 > 0x1ff) {
            prim->y1 = 0x1ff;
        }
        if (prim->y1 < -0xfa) {
            prim->y1 = -0xfa;
        }
        if (prim->y2 > 0x1ff) {
            prim->y2 = 0x1ff;
        }
        if (prim->y2 < -0xfa) {
            prim->y2 = -0xfa;
        }
        if (prim->x0 > 0x320) {
            prim->x0 = 0x320;
        }
        if (prim->x0 < -0x12c) {
            prim->x0 = -0x12c;
        }
        if (prim->x1 > 0x320) {
            prim->x1 = 0x320;
        }
        if (prim->x1 < -0x12c) {
            prim->x1 = -0x12c;
        }
        if (prim->x2 > 0x320) {
            prim->x2 = 0x320;
        }
        if (prim->x2 < -0x12c) {
            prim->x2 = -0x12c;
        }
    }
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
    prim->uv2 = tex[4];
    prim->clut = tex[(f->clut >> 8) + 22];
    SetPolyFT3(prim);
    SetShadeTex(prim, 1);
    D_800B6F30 += 0x40;
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), prim++);
    D_800B7140 = prim;
}

void func_8002FB58(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[(f->clut >> 8) + 22];
    func_8002EDC4((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    D_800B6F30 += 0x40;
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
}

void func_8002FDCC(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[(f->clut >> 8) + 22];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

s32 func_80086B40(s32 xy0, s32 xy1, s32 xy2);

void func_80030120(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = v0.vz >> 2;
    }
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    if (func_80086B40(D_800B6B90->xy0, D_800B6B90->xy1, D_800B6B90->xy3) < 0) {
        return;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[(f->clut >> 8) + 22];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

void func_800304A4(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[0], &v0, &D_800B7198);
        RotTrans(f->v[1], &v1, &D_800B7198);
        RotTrans(f->v[2], &v2, &D_800B7198);
        RotTrans(f->v[3], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = v0.vz >> 2;
    }
    if (func_80086B40(D_800B6B90->xy0, D_800B6B90->xy1, D_800B6B90->xy3) < 0) {
        return;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[6];
    prim->tpage = tex[3];
    prim->clut = tex[(f->clut >> 8) + 22];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

void func_80030834(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[3], &v0, &D_800B7198);
        RotTrans(f->v[2], &v1, &D_800B7198);
        RotTrans(f->v[1], &v2, &D_800B7198);
        RotTrans(f->v[0], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv1 = tex[0];
    prim->uv0 = tex[2];
    *(s16 *)&prim->uv3 = tex[4];
    *(s16 *)&prim->uv2 = tex[6];
    prim->tpage = tex[3];
    prim->clut = tex[(f->clut >> 8) + 22];
    func_8002EDC4((POLY_FT4 *)prim, (POLY_FT4 *)(prim + 1));
    D_800B6F30 += 0x40;
    if (D_800B6F30 < 0x58) {
        D_800B6F30 = 0x58;
    }
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
    AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
}

void func_80030AB4(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    Unk8002BA84_Prim *t;
    u16 *tex;
    VECTOR v0;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;

    D_800B6F30 = RotTransPers4(f->v[2], f->v[3], f->v[0], f->v[1], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (D_800B7198 & ~0x1FFF) {
        RotTrans(f->v[3], &v0, &D_800B7198);
        RotTrans(f->v[2], &v1, &D_800B7198);
        RotTrans(f->v[1], &v2, &D_800B7198);
        RotTrans(f->v[0], &v3, &D_800B7198);
        if (v0.vz < 0 && v1.vz < 0 && v2.vz < 0 && v3.vz < 0) {
            return;
        }
        func_8002F144((s16 *)&D_800B6B90->xy0, &v3);
        func_8002F144((s16 *)&D_800B6B90->xy1, &v2);
        func_8002F144((s16 *)&D_800B6B90->xy3, &v1);
        func_8002F144((s16 *)&D_800B6B90->xy2, &v0);
        D_800B6F30 = 0x58;
    }
    prim = D_800B6B90;
    tex = (u16 *)(D_8015EB78 + f->tex);
    prim->uv0 = tex[0];
    *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
    *(s16 *)&prim->uv2 = tex[4];
    *(s16 *)&prim->uv3 = tex[6];
    prim->clut = tex[(f->clut >> 8) + 22];
    switch (func_8003BE74(prim)) {
    case 1:
        t = D_800B7140;
        *(u32 *)&t->uv0 = *(u32 *)&D_800B6B90->uv0;
        *(u32 *)&t->uv1 = *(u32 *)&D_800B6B90->uv1;
        *(u32 *)&t->uv2 = *(u32 *)&D_800B6B90->uv2;
        *(u32 *)&t->xy0 = *(u32 *)&D_800B6B90->xy0;
        *(u32 *)&t->xy1 = *(u32 *)&D_800B6B90->xy1;
        *(u32 *)&t->xy2 = *(u32 *)&D_800B6B90->xy2;
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        SetPolyFT3(t);
        SetShadeTex(t, 1);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), t++);
        D_800B7140 = t;
        break;
    case 0:
        func_8002EDC4((POLY_FT4 *)D_800B6B90, (POLY_FT4 *)(D_800B6B90 + 1));
        if (D_800B6F30 < 0x58) {
            D_800B6F30 = 0x58;
        }
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        AddPrim(D_800B7018 + (D_800B6F30 >> 3), D_800B6B90++);
        break;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80030E08);

void func_8003101C(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        if (D_800B6F30 > 0x40) {
            D_800B6B90 = prim + 1;
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim);
        }
    }
}

void func_80031138(Unk8002B728_Face *f) {
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&D_800B6B90->uv0 = *(u32 *)tex;
        *(u32 *)&D_800B6B90->uv1 = *(u32 *)(tex + 18);
        D_800B6B90->uv2 = tex[4];
        D_800B6B90->uv3 = tex[6];
        SetPolyFT4(D_800B6B90);
        SetShadeTex(D_800B6B90, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), D_800B6B90++);
        }
    }
}

void func_80031290(Unk8002B728_Face *f) {
    u16 *tex;

    if (RotNclip4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        tex = (u16 *)(D_8015EB78 + f->tex);
        D_800B6B90->uv1 = tex[0];
        D_800B6B90->uv0 = tex[2];
        D_800B6B90->uv3 = tex[4];
        D_800B6B90->uv2 = tex[6];
        D_800B6B90->tpage = tex[3];
        D_800B6B90->clut = tex[1];
        SetPolyFT4(D_800B6B90);
        SetShadeTex(D_800B6B90, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), D_800B6B90++);
        }
    }
}

void func_80031400(Unk8002B728_Face *f) {
    Unk8002B728_Prim *prim;
    u16 *tex;

    D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &D_800B6B90->xy0, &D_800B6B90->xy1, &D_800B6B90->xy3, &D_800B6B90->xy2, &D_800B6A90, &D_800B7198);
    if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        prim = D_800B6B90;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 18);
        prim->uv2 = tex[4];
        prim->uv3 = tex[6];
        if (D_800B6F30 > 0x40) {
            D_800B6B90 = prim + 1;
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim);
        }
    }
}

void func_8003151C(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        D_800B6F30 = (D_800B6DA0 + D_800B6DA8 + D_800B6DB0) / 12;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim++);
        }
        D_800B7140 = prim;
    }
}

void func_800316B0(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    if (RotNclip3(f->v[2], f->v[1], f->v[0], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        D_800B6F30 = (D_800B6DA0 + D_800B6DA8 + D_800B6DB0) / 12;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim++);
        }
        D_800B7140 = prim;
    }
}

void func_80031858(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    D_800B6F30 = RotTransPers3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B7198);
    if (!(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        D_800B6F30 = (D_800B6DA0 + D_800B6DA8 + D_800B6DB0) / 12;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim++);
        }
        D_800B7140 = prim;
    }
}

void func_800319EC(Unk8002B728_Face *f) {
    Unk8002BA84_Prim *prim = D_800B7140;
    u16 *tex;

    if (RotNclip3(f->v[0], f->v[1], f->v[2], &prim->xy0, &prim->xy1, &prim->xy2, &D_800B6A90, &D_800B6F30, &D_800B7198) > 0 && !(D_800B7198 & ~0x1FFF) && D_800B6F30 > 0) {
        func_80085190(&D_800B6DA0, &D_800B6DA8, &D_800B6DB0);
        D_800B6F30 = (D_800B6DA0 + D_800B6DA8 + D_800B6DB0) / 12;
        tex = (u16 *)(D_8015EB78 + f->tex);
        *(u32 *)&prim->uv0 = *(u32 *)tex;
        *(u32 *)&prim->uv1 = *(u32 *)(tex + 2);
        prim->uv2 = tex[4];
        SetPolyFT3(prim);
        SetShadeTex(prim, 1);
        if (D_800B6F30 > 0x40) {
            AddPrim(D_800B7018 + ((D_800B6F30 - 0x40) >> 3), prim++);
        }
        D_800B7140 = prim;
    }
}

void func_80031B94(void) {
}

extern s16 D_800B7260;

void func_80031B9C(void) {
    if (D_800B7370->unk178E != 0) {
        D_800B7260 = 0;
    } else {
        D_800B7260 = D_800B7370->maps[D_800B7370->unk1780][0xE];
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80031C00);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80031DA8);

void func_80031F90(void) {
    u8 unused[16];
}

extern s32 D_800BDB04[];
extern s32 *D_800B71F0;

void func_80031F9C(void) {
    D_800B71F0 = D_800BDB04;
}

void func_80031FB4(void) {
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80031FBC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800321A8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003239C);

void func_80032584(s16 n, s32 *a) {
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

void func_800325FC(SVECTOR **v) {
    s16 mid = (v[0]->vy + v[1]->vy + v[2]->vy + v[3]->vy) >> 2;

    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_80032584(1, (s32 *)v);
    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_80032584(1, (s32 *)v);
    if (v[0]->vy < mid && v[1]->vy < mid) {
        return;
    }
    func_80032584(1, (s32 *)v);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800326FC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80032BAC);

typedef struct {
    s32 unk0;
    u8 pad4[8];
} Unk800BD644;

extern u16 D_800BD632;
extern u16 D_800BD634;
extern Unk800BD644 *D_800BD644;

s32 func_80032D24(s32 key, Unk800BD644 *skip) {
    Unk800BD644 *p = D_800BD644;
    s16 n = D_800BD632 * D_800BD634;

    while (n--) {
        if (skip != p && key == p->unk0) {
            return -1;
        }
        p++;
    }
    return 0;
}

void func_80032D94(void) {
    u8 unused[32];
}

typedef struct {
    u8 pad0[6];
    s16 unk6;
} Unk80032DA0_Sub;

typedef struct {
    u8 pad0[4];
    Unk80032DA0_Sub *unk4;
    u8 pad8[4];
    Unk80032DA0_Sub *unkC;
} Unk80032DA0;

void func_80032DA0(Unk80032DA0 *obj) {
    if (obj->unk4->unk6 != 0x80 || obj->unkC->unk6 != 0x80) {
        func_80032584(1, (s32 *)obj);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80032DF4);

void func_80032DF4(s32);

void func_80032E50(s32 *p) {
    if (p != NULL) {
        func_80032DF4(p[0]);
        func_80032DF4(p[1]);
        func_80032DF4(p[2]);
        func_80032DF4(p[3]);
    }
}

s16 func_80032EA8(s16 v, s16 lim) {
    if (v > lim) {
        return lim;
    }
    if (v < -lim) {
        return -lim;
    }
    return v;
}

s16 func_80032EEC(s32 v, s16 dir, s32 step) {
    if (dir == 0) {
        return v;
    }
    if (dir > 0) {
        return v - step;
    }
    return v + step;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80032F1C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80032F7C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80033518);

extern s16 D_800BD994[];
extern s16 D_80169F98[];

void func_800336C0(void) {
    s16 i = 15;

    do {
        D_800BD994[i] = func_800754C8(0xB4);
        D_80169F98[i] = 0;
    } while (i--);
}

void func_80033730(s16 *angle, s16 *speed) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800337B4);

typedef struct {
    s16 x, y, z;
    u8 pad6[0xA];
    SVECTOR v[8];
    u8 pad50[4];
    s16 unk54[8];
    s16 unk64[8];
    s16 unk74[8];
    u8 pad84[2];
    s16 unk86;
} Unk80033D4C;

void func_800337B4();

void func_80033D4C(Unk8002A35C *pos) {
    struct Task *t = (struct Task *)func_8007307C(func_800337B4, 0x10, 0x8C);
    Unk80033D4C *p;
    s16 i;

    if (t != NULL) {
        i = 15;
        p = (Unk80033D4C *)t->vals;
        p->x = pos->x;
        p->y = pos->y;
        p->z = pos->z;
        do {
            p->unk64[i] = func_800754C8(0xB4);
            p->unk74[i] = 0;
        } while (i--);
        i = 7;
        do {
            p->unk54[i] = 0x80;
            p->v[i].vx = func_800754C8(0x40) - 0x20;
            p->v[i].vz = func_800754C8(0x40) - 0x20;
            p->v[i].vy = i * 16;
        } while (i--);
        p->unk86 = 0;
    }
}

extern u32 D_8015EEFC[];
extern void SetPolyFT4(void *p);
extern void SetShadeTex(void *p, s32 tge);
extern void SetSemiTrans(void *p, s32 abe);
extern u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
extern void func_8007345C(void);

void func_80033E54(void) {
    s16 *s = (s16 *)D_800B6DE0->vals;
    POLY_FT4 *p = D_800B7140;
    u32 *uv = D_8015EEFC;
    s16 c;

    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 320;
    p->y1 = 0;
    p->x3 = 320;
    p->y3 = 240;
    p->x2 = 0;
    p->y2 = 240;
    *(u32 *)&p->u0 = *uv++;
    *(u32 *)&p->u1 = *uv++;
    *(u32 *)&p->u2 = *uv++;
    *(u32 *)&p->u3 = *uv++;
    p->tpage = GetTPage(0, 1, 320, 0);
    SetPolyFT4(p);
    SetShadeTex(p, 0);
    c = s[0];
    p->r0 = c;
    p->g0 = c;
    p->b0 = c;
    SetSemiTrans(p, 1);
    AddPrim(D_800B7018 + 16, p);
    c = s[0] - 4;
    D_800B7140 = p + 1;
    s[0] = c;
    if (c < 0x20) {
        func_8007345C();
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80033F74);

void func_80033F74(void);

void func_80034154(void) {
    struct Task *t = D_800B6DE0;

    *(s16 *)t->vals = 0x20;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_80033F74;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800341A4);

void func_8003456C(SVECTOR *a, SVECTOR *b, SVECTOR *out) {
    out->vx = a->vx + b->vx;
    out->vy = a->vy + b->vy;
    out->vz = a->vz + b->vz;
}

typedef struct {
    int *p;
    int pad[3];
} Entry16;

extern Entry16 *D_800B73F0;

typedef struct {
    u8 pad[0x20];
    SVECTOR pt[8];
    u8 pad60[0x78];
} Unk800345AC_Ent;

typedef struct {
    u8 pad[4];
    u16 count;
    u8 pad6[0x12];
    Unk800345AC_Ent ent[1];
} Unk800345AC_Obj;

void func_800345AC(s16 id) {
    Unk800345AC_Obj *obj = (Unk800345AC_Obj *)D_800B73F0[id].p;
    SVECTOR d;
    s16 n = obj->count;

    while (n--) {
        SVECTOR *pt = obj->ent[n].pt;

        func_80025D44((s16 *)&pt[0], (s16 *)&pt[1], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[0], (s16 *)&d, 0x200, (s16 *)&pt[0]);
        func_80025D44((s16 *)&pt[1], (s16 *)&d, 0x200, (s16 *)&pt[1]);
        func_80025D44((s16 *)&pt[2], (s16 *)&pt[3], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[2], (s16 *)&d, 0x200, (s16 *)&pt[2]);
        func_80025D44((s16 *)&pt[4], (s16 *)&pt[5], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[4], (s16 *)&d, 0x200, (s16 *)&pt[4]);
        func_80025D44((s16 *)&pt[5], (s16 *)&d, 0x200, (s16 *)&pt[5]);
        func_80025D44((s16 *)&pt[6], (s16 *)&pt[7], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[6], (s16 *)&d, 0x200, (s16 *)&pt[6]);
        func_80025D44((s16 *)&pt[0], (s16 *)&pt[4], 0x400, (s16 *)&d);
        d.vx = pt[0].vx - d.vx;
        d.vy = pt[0].vy - d.vy;
        d.vz = pt[0].vz - d.vz;
        func_8003456C(&d, &pt[0], &pt[0]);
        func_8003456C(&d, &pt[1], &pt[1]);
        func_8003456C(&d, &pt[2], &pt[2]);
        func_8003456C(&d, &pt[3], &pt[3]);
        d.vx = -d.vx;
        d.vy = -d.vy;
        d.vz = -d.vz;
        func_8003456C(&d, &pt[4], &pt[4]);
        func_8003456C(&d, &pt[5], &pt[5]);
        func_8003456C(&d, &pt[6], &pt[6]);
        func_8003456C(&d, &pt[7], &pt[7]);
        func_80025D44((s16 *)&pt[2], (s16 *)&pt[3], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[2], (s16 *)&d, 0x400, (s16 *)&pt[2]);
        func_80025D44((s16 *)&pt[3], (s16 *)&d, 0x400, (s16 *)&pt[3]);
        func_80025D44((s16 *)&pt[6], (s16 *)&pt[7], 0x800, (s16 *)&d);
        func_80025D44((s16 *)&pt[6], (s16 *)&d, 0x400, (s16 *)&pt[6]);
        func_80025D44((s16 *)&pt[7], (s16 *)&d, 0x400, (s16 *)&pt[7]);
    }
}

extern Unk800B7398 *D_800B7398;

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
} Unk800348D4;

void func_800348D4(Unk800348D4 *f) {
    s16 i = 0;

    while (f[i].v0 != -1) {
        f[i].v0 = f[i].v0 * 8 + (s32)D_800B7398;
        f[i].v1 = f[i].v1 * 8 + (s32)D_800B7398;
        f[i].v2 = f[i].v2 * 8 + (s32)D_800B7398;
        f[i].unk12 = f[i].unk12 * 60;
        f[i].unk14 = f[i].unk14 * 60;
        f[i].unkC = f[i].unkC * 375 >> 8;
        f[i].unkE = f[i].unkE * 375 >> 8;
        f[i].unk10 = f[i].unk10 * 375 >> 8;
        f[i].unk16 = f[i].unk16;
        f[i].unk18 = f[i].unk18;
        f[i].unk1A = f[i].unk1A;
        i++;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80034A18);

extern s32 D_800B7288;
extern s32 *D_800B7038;
extern void *D_800B6BC8;
extern void (*D_800B72C8)(void);
void func_800341A4(s16 id);
void func_800345AC(s16 id);
void func_80072B00(void *, s32);
void func_80072884(void);
void func_8003CF4C(void);

typedef struct {
    s16 unk0;
} Unk80034BA0;

void func_80034BA0(void) {
    s16 i = 9;
    Unk80034BA0 *p = (Unk80034BA0 *)D_800B6DE0->vals;

    do {
        func_800341A4(D_800B7288);
        func_800345AC(D_800B7288);
        if (++D_800B7288 == (s32)D_800B7038) {
            p->unk0 = 0;
            func_80072B00(D_800B6BC8, D_800B7430 + 0x2D);
            D_800B72C8 = func_8003CF4C;
            if (D_800B6DE0->func == D_800B7350) {
                TRAP();
            } else {
                D_800B6DE0->func = func_80072884;
            }
            return;
        }
    } while (i--);
}

void func_80034C88(SVECTOR *pos, SVECTOR *vel, s32 count, s32 scale) {
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
    u8 unk14;
    u8 unk15;
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
    u8 unk2A;
} Unk80034D1C;

void func_80034D1C(Unk80034D1C *src, Unk80034D1C *dst) {
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
    dst->unk26 = src->unk26;
    dst->unk2A = src->unk2A;
    dst->unk15 = src->unk15;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80034DF4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80034FD8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800351A4);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 pad15;
    s16 unk16;
    u8 pad18[2];
    s16 unk1A;
    u16 unk1C;
    u8 pad1E[0xA];
    s16 unk28;
    u8 unk2A;
} Unk80035384;

void func_800351A4(Unk80035384 *obj);

void func_80035384(Unk80035384 *obj) {
    obj->unk14 = 0;
    obj->unk16 = 0;
    obj->unkC = 0;
    obj->unk8 = 0;
    obj->unk10 = 0;
    obj->unk1A = obj->unk28 = 0x1000;
    obj->unk0 = obj->unk2 = 0;
    obj->unk4 = 0;
    obj->unk2A = 0x40;
    obj->unk1C = 0xFFFF;
    func_800351A4(obj);
}

s32 func_800754C8(s32);

int func_800353DC(int i) {
    return (s16)func_800754C8(*D_800B73F0[(s16)i].p);
}

int func_80035420(short i) {
    return *D_800B73F0[i].p - 1;
}

typedef struct {
    u16 prevId;
    u16 id;
    u8 pad4[2];
    u16 unk6;
    u32 prevTime;
    u32 time;
    u32 unk10;
    u8 unk14;
    u8 pad15;
    u16 unk16;
    u8 pad18[2];
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
} Anim;

void func_80035448(anim, id, time, arg3, blend)
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
    anim->time = anim->time / D_800B73F0[id].p[2] * D_800B73F0[id].p[2];
    anim->id = id;
    anim->unk6 = arg3;
    if (blend != 0) {
        anim->unk16 = 1;
        anim->unk1A = 0x1000 / blend;
    } else {
        anim->unk16 = 0;
    }
}

void func_8003553C(Anim *anim, u16 id, s16 time, s16 arg3, s16 blend) {
    if (anim->id != id) {
        func_80035448(anim, id, time, arg3, blend);
    }
}

typedef struct {
    SVECTOR v[27];
} AnimFrame;

typedef struct {
    s32 len;
    s32 count;
    s32 step;
    s32 scale;
    s32 unk10;
    s32 unk14;
    AnimFrame frames[1];
} AnimInfo;

extern s16 D_800B639E;

s16 func_80035584(Anim *anim) {
    AnimInfo *info = (AnimInfo *)D_800B73F0[anim->id].p;
    s16 t;
    s16 frame;
    s16 from;
    s16 to;
    s16 a;
    s16 wrap;

    t = anim->time % info->len;
    frame = t / info->step;
    D_800B6A90 = (t % info->step) * info->scale >> 12;
    if (frame == 0) {
        from = 0;
        to = info->frames[0].v[26].vz;
    } else {
        from = info->frames[frame - 1].v[26].vz;
        to = info->frames[frame].v[26].vz;
    }
    a = func_80072734(from, to, D_800B6A90);
    t = anim->time + anim->unk6 * D_800B639E;
    if (t > info->len) {
        wrap = info->frames[info->count - 1].v[26].vz;
        t = t - info->len;
    } else {
        wrap = 0;
    }
    frame = t / info->step;
    D_800B6A90 = (t % info->step) * info->scale >> 12;
    if (frame == 0) {
        from = 0;
        to = info->frames[0].v[26].vz;
    } else {
        from = info->frames[frame - 1].v[26].vz;
        to = info->frames[frame].v[26].vz;
    }
    return a - (wrap + func_80072734(from, to, D_800B6A90));
}

typedef struct {
    u8 pad0[0x208];
    s16 unk208;
} Unk8003580C_Vals;

extern s16 D_800B641C;

s16 func_8003580C(Anim *a) {
    AnimInfo *info;
    s16 ret = 0;
    u16 spd;
    s32 t;

    if (a->id >= 0x58) {
        D_800B641C = ((Unk8003580C_Vals *)D_800B6DE0->vals)->unk208;
        a->id = 0x55;
        return 0;
    }
    info = (AnimInfo *)D_800B73F0[a->id].p;
    if (a->unk16 == 2) {
        a->unk10 += a->unk1A * D_800B639E;
        if (a->unk10 >= 0x1000) {
            a->unk16 = 0;
            a->unk10 = 0x1000;
        }
    }
    spd = a->unk6;
    t = spd * D_800B639E + a->time;
    if (a->unk14 & 1) {
        if (spd == 0) {
            ret = -1;
        } else if (t + info->step * 2 >= info->len) {
            a->unk6 = 0;
            ret = -1;
        }
    }
    if (t >= info->len) {
        ret = -1;
        t -= info->len;
    }
    if (t < 0) {
        t += info->len;
    }
    a->time = t;
    return ret;
}

s32 func_8003594C(s16 a, s16 b) {
    s32 m;

    if (a <= b) {
        m = b - 0x100;
    } else {
        m = a - 0x100;
    }
    return m >> 6;
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

void func_80035974(s16 rot, Unk80035974 *p) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80035A18);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003BE74);

extern s32 *D_800B6DF0;
extern s16 D_800B7430;
extern s32 D_800B63AC;
extern s16 D_800B6C10;
extern s16 D_800B6B08;
extern s32 func_8007270C(s32 n);
extern void func_8007345C(void);

void func_8003CC44(void) {
    D_800B6DF0 = D_800B71F0;
    D_800B71F0 = (s32 *)((u8 *)D_800B71F0 + func_8007270C(D_800B7430 + 0x35));
    D_800B63AC = 0;
    D_800B6C10 = 100;
    D_800B6B08 = 6;
    DrawSync(0);
    func_8007345C();
}

extern void *D_800B6BC8;
extern s32 *D_800B6AE8;
extern s32 D_800B7288;
extern s32 *D_800B7038;
extern s32 D_800B6A88;
extern s32 *D_800B71F0;
extern Unk800462F0_Mesh *D_800B71B8;
extern Unk800462F0_Obj *D_800B6E70;
extern u8 *D_800B7100;
s32 func_80024F4C(s32 base, s32 size);
s32 func_80024F60(s32 size);
void *func_80072768(void *data, s16 i);
u32 func_80072780(void *data, s16 i);
void func_8003D10C(void);

void func_8003CCC0(void) {
    D_800B71F0 = (s32 *)func_80024F60((s32)D_800B71F0);
    D_800B6AE8 = func_80072768(D_800B6BC8, 3);
    D_800B7288 = 0;
    D_800B7038 = D_800B71F0;
    func_80072780(D_800B6BC8, 3);
    D_800B6A88 = 0x6B80;
    D_800B71B8 = (Unk800462F0_Mesh *)D_800B7038;
    D_800B71F0 = (s32 *)func_80024F4C((s32)D_800B71F0, 0x6B80);
    D_800B6DE0->saved = D_800B6DE0->func;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8003D10C;
    }
}

void func_8003CD9C(void) {
    D_800B71F0 = (s32 *)func_80024F60((s32)D_800B71F0);
    D_800B6AE8 = func_80072768(D_800B6BC8, 4);
    D_800B7288 = 0;
    D_800B7038 = D_800B71F0;
    D_800B6A88 = func_80072780(D_800B6BC8, 4) + 0x80;
    D_800B7100 = (u8 *)D_800B71F0;
    D_800B71F0 = (s32 *)func_80024F4C((s32)D_800B71F0, D_800B6A88);
    D_800B6DE0->saved = D_800B6DE0->func;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8003D10C;
    }
}

void func_8003CE70(void) {
    D_800B71F0 = (s32 *)func_80024F60((s32)D_800B71F0);
    D_800B6AE8 = func_80072768(D_800B6BC8, 1);
    D_800B7288 = 0;
    D_800B7038 = D_800B71F0;
    D_800B6A88 = func_80072780(D_800B6BC8, 1) + 0x80;
    D_800B6E70 = (Unk800462F0_Obj *)D_800B71F0;
    D_800B71F0 = (s32 *)func_80024F4C((s32)D_800B71F0, D_800B6A88);
    D_800B6DE0->saved = D_800B6DE0->func;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8003D10C;
    }
}

void func_8003CF44(void) {
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003CF4C);

void func_8003D10C(void) {
    s32 n = D_800B6A88 - D_800B7288;
    u16 count;

    if (n < 0x1000) {
        count = n >> 2;
    } else {
        count = 0x400;
    }
    while (count--) {
        *D_800B7038++ = *D_800B6AE8++;
    }
    D_800B7288 += 0x1000;
    if (D_800B7288 >= D_800B6A88) {
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = D_800B6DE0->saved;
        }
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    u8 pad8[2];
    s16 unkA;
    u8 padC[0x10];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
} Unk8005A018;

extern Unk8005A018 D_801F77E8[2];
extern s16 D_800B73D0;
extern s16 D_800B7220;
void func_8002625C(void);
void func_800326FC(s32 *p);
void func_80066474(void);
void func_800234D8(void);
void func_8004A8EC(Unk8005A018 *p);

void func_8003D1F8(s16 arg) {
    func_8002625C();
    if (D_800B73D0 == 0) {
        D_800B73D0 = -1;
        func_800326FC(D_800B6DF0);
        func_80020634();
    }
    func_80070CFC();
    if (D_801F77E8[0].unk22 != 0) {
        func_8004A8EC(&D_801F77E8[0]);
    }
    if (D_801F77E8[1].unk22 != 0) {
        func_8004A8EC(&D_801F77E8[1]);
    }
    D_800B7220 = arg;
    func_80066474();
    func_800234D8();
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003D2B4);

extern s16 D_800B6C60[3];
extern s16 D_800B7188;
void func_8003D2B4(void);

void func_8003D51C(s16 arg0) {
    if (D_800B7188 == 0) {
        D_800B7188 = -1;
        D_800B6C60[0] = arg0;
        D_800B6C60[1] = 0;
        func_8007307C(func_8003D2B4, 0x10, 0);
    }
}

extern s32 D_800B6C48;

void func_8003D570(s32 n) {
    D_800B6C48 += n;
}

extern s32 D_800B6A6C;

void func_8003D590(s32 delta) {
    delta += D_800B6A6C;
    if (delta < 0) {
        D_800B6A6C = 0;
    } else {
        D_800B6A6C = delta;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003D5C8);

extern Unk800B6F00 *D_800B6F00;
extern s16 D_800B641A;
extern s16 D_800B6418;
extern SVECTOR D_800B6F18;
extern SVECTOR D_800B6F20;
void func_8006C8E4(void *a, void *b, s16 c);

void func_8003D6D4(void) {
    D_800B641A = func_80072734(0x400, 0x1000, D_800B6F00->unk6);
    D_800B6418 = func_80072734(0x200, 0x960, D_800B6F00->unk4);
    func_8006C8E4(&D_800B6F18, &D_800B6F20, D_800B6F00->unk12);
}

void func_8003D750(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0x3FFF;
    attr.mvol.right = 0x3FFF;
    attr.cd.volume.left = func_80072734(0, 0x3FFF, D_800B7370->unk1784);
    attr.cd.volume.right = func_80072734(0, 0x3FFF, D_800B7370->unk1784);
    attr.mask = 0xC3;
    SpuSetCommonAttr(&attr);
}

void func_8003D7BC(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0;
    attr.mvol.right = 0;
    attr.cd.volume.left = 0;
    attr.cd.volume.right = 0;
    attr.mask = 0xC3;
    SpuSetCommonAttr(&attr);
}

void func_8003D7F4(void) {
    SpuCommonAttr attr;

    attr.cd.volume.left = 0;
    attr.cd.volume.right = 0;
    attr.mask = 0xC0;
    SpuSetCommonAttr(&attr);
}

void func_8003D824(void) {
    SpuCommonAttr attr;

    attr.mvol.left = 0x3FFF;
    attr.mvol.right = 0x3FFF;
    attr.mask = 0x3;
    SpuSetCommonAttr(&attr);
}

extern s16 D_800B73C8;
extern s16 D_800B6C10;
void func_80034A18(void);

void func_8003D858(void) {
    D_800B73C8 = 3;
    func_80034A18();
    D_800B6C10 = 0x19;
}

void func_8003D890(s16 n) {
    while (n--) {
        VSync(0);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003D8D4);

extern s16 D_800B6C10;
extern s16 D_800B73D0;
extern s32 D_800B63AC;
extern s16 D_800B6B18;
extern s32 D_800BDB04[];
extern s32 D_800BDF04[];
extern s16 D_800B6C30;
void func_800336C0(void);
void func_8003D8D4(void);

typedef struct {
    s16 unk0;
    u8 pad2[0xA];
    s16 unkC;
} Unk8003DAC4;

void func_8003DAC4(void) {
    Unk8003DAC4 *p = (Unk8003DAC4 *)D_800B6DE0->vals;

    D_800B6C10 = 0;
    D_800B73D0 = 0;
    D_800B63AC = 0;
    D_800B6B18 = -1;
    D_800B6BC8 = (void *)func_80024F60((s32)D_800BDB04);
    D_800B71F0 = (s32 *)func_80024F60((s32)D_800BDF04);
    func_800336C0();
    func_80072B00(D_800B71F0, D_800B7430 + 0x3D);
    D_800B72C8 = func_8003D8D4;
    func_80066474();
    p->unk0 = 0;
    p->unkC = 0;
    D_800B6C30 = 0;
    D_800B73C8 = 0;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80072884;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003DBC4);

extern s16 D_800B7238;
extern s16 D_800B6EB0;
extern u8 D_801DA1CC[][4];
extern s32 D_800B6D80;
extern s16 D_800B6C60[3];
extern int CdControl(unsigned char com, unsigned char *param, unsigned char *result);

s32 func_8003DC78(s16 track) {
    u8 unused[56];
    s16 t;

    D_800B7238 = 0;
    D_800B6EB0 = t = track + 2;
    D_800B6D80 = D_801DA1CC[t + 1][1] + D_801DA1CC[t + 1][0] * 90 - 2;
    CdControlB(2, D_801DA1CC[t], 0);
    CdControlB(0xE, (unsigned char *)5, 0);
    CdControl(3, 0, 0);
    D_800B6C60[0] = track;
    D_800B6C60[1] = 30;
    return -1;
}

extern int CdControlB(unsigned char com, unsigned char *param, unsigned char *result);
extern s16 D_800B7238;
extern int VSync(int mode);

void func_8003DD54(void) {
    u8 result[8];

    if (D_800B7238 != 2) {
        CdControlB(8, 0, result);
        VSync(0);
        D_800B7238 = 2;
    }
}

void func_8003DDA0(void) {
    u8 result[8];

    if (D_800B7238 == 1) {
        CdControlB(3, 0, result);
        D_800B7238 = 0;
    }
}

void func_8003DDE0(void) {
    u8 result[8];

    if (D_800B7238 == 0) {
        CdControlB(9, 0, result);
        D_800B7238 = 1;
    }
}

extern s16 D_800B7430;

void func_8003DE20(void) {
    func_8003DC78(D_800B7430);
    func_8003DE50(0x3FF);
}

typedef struct {
    u8 val0;
    u8 val1;
    u8 val2;
    u8 val3;
} CdlATV;
int CdMix(CdlATV *vol);

void func_8003DE50(void) {
    CdlATV atv;

    atv.val0 = 0xFF;
    atv.val2 = 0xFF;
    atv.val3 = 0;
    atv.val1 = 0;
    CdMix(&atv);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003DE84);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003E210);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003E550);

typedef struct {
    SVECTOR *v[4];
} Unk8004D4A0;

void func_8003E6F4(Unk8004D4A0 *f, SVECTOR *out) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003E8A4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003E9A4);

extern void func_8003E8A4(s32 id, s16 *pos);

void func_8003EA90(s32 id, s16 value, u8 *col) {
    s16 pos[2];
    s16 v;

    func_8003E8A4(id, pos);
    v = value < 0 ? -value : value;
    if (pos[0] < 0) {
        pos[0] = 0;
    }
    if (pos[0] > D_800B70E8 - 20) {
        pos[0] = D_800B70E8 - 20;
    }
    if (pos[1] < 0) {
        pos[1] = 0;
    }
    if (pos[1] > 200) {
        pos[1] = 200;
    }
    func_80076EF4(pos[0], pos[1], v, 1500, 500, col, col);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003EB60);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003ECAC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003EE98);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003F134);

typedef struct {
    u8 ft4[0x960][0x28];
    u8 pad17700[0x1024];
} Unk8016B318;

extern Unk8016B318 D_8016B318[];
extern s16 D_800B73C0;
extern u8 *D_800B7100;
void func_8005F604();

void func_8003F314(s32 id, s16 from, s32 to) {
    Unk8016B318 *dst = &D_8016B318[(D_800B73C0 + 1) % 2];
    u8 *src;
    s32 size;

    DrawSync(0);
    src = D_800B7100 + from * 0xC0;
    size = (s16)(to - from + 1) * 0xC0;
    memcpy(dst, src, size);
    func_8005F604(id, dst, size, 0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003F408);

void func_8003F528(void) {
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003F530);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003F624);

typedef struct {
    u8 pad0[0x10];
    s16 x, y, z;
    u8 pad16[2];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
} Unk8003F6D0_Src;

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
} Unk8003F6D0_Cfg;

extern Unk800462F0_Obj *D_800B6E70;
extern struct Task *D_801F7550;
extern s16 D_800B63C6;
extern s16 D_800B63C8;
extern SVECTOR *D_800B73B8;

void func_8003F6D0(void) {
    Unk8003F6D0_Src *src = (Unk8003F6D0_Src *)D_800B6DE0->vals;
    Unk8003F6D0_Cfg *cfg = (Unk8003F6D0_Cfg *)D_801F7550->vals;
    SVECTOR *v;
    Unk800462F0_Obj *o;

    if (D_800B63C6 == 1) {
        v = &D_800B73B8[D_800B63C8];
        src->x = v->vx;
        src->y = v->vy;
        src->z = v->vz;
        src->unk18 = v[16].vx;
        src->unk1A = v[16].vy;
        src->unk1C = v[16].vz;
    }
    if (D_800B63C6 == 2) {
        o = &D_800B6E70[D_800B63C8];
        src->x = o->x;
        src->y = o->y;
        src->z = o->z;
        src->unk1A = o->unk1A;
        cfg->unkC = o->unk10;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003F7D4);

typedef struct {
    u8 pad0[0x10];
    SVECTOR unk10;
} Unk8003FA60;

extern Unk800462F0_Mesh *D_800B71B8;
extern Unk800462F0_Obj *D_800B6E70;
extern s16 D_800B6CF0;
extern s16 D_800B63D0;
extern s16 D_800B63C6;
extern s16 D_800B63C8;
extern SVECTOR *D_800B73B8;

void func_8003FA60(void) {
    s32 best = 0x8000;
    s32 type = 0;
    s32 idx = 0;
    Unk8003FA60 *p = (Unk8003FA60 *)D_800B6DE0->vals;
    Unk800462F0_Mesh *m;
    Unk800462F0_Obj *o;
    s16 i;
    s16 j;
    s16 mi;
    s32 d;

    i = 0x3F;
    do {
        m = &D_800B71B8[i];
        for (j = 0; j < 15; j++) {
            if (m->unk108[j] == 0) {
                break;
            }
            d = func_8002576C(&m->v[j], &p->unk10);
            if (d < best) {
                best = d;
                type = 1;
                idx = j;
                mi = i;
            }
        }
    } while (i--);
    i = 0xFF;
    do {
        if (D_800B6CF0 == -1 || D_800B6E70[i].unk14 == D_800B6CF0) {
            o = &D_800B6E70[i];
            if (o->unk12 == D_800B63D0 && o->unk16 != 0) {
                d = func_8002576C((SVECTOR *)o, &p->unk10);
                if (d < best) {
                    best = d;
                    type = 2;
                    idx = i;
                }
            }
        }
    } while (i--);
    if (best != 0x8000) {
        D_800B63C6 = type;
        D_800B63C8 = idx;
        if (type == 1) {
            D_800B6CF0 = mi;
            D_800B73B8 = D_800B71B8[mi].v;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003FC9C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8003FF64);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6384);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6390);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6394);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63C8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63E0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63F0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B63F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6400);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6404);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6418);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B641C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6420);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6424);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B642C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6430);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6434);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6438);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6444);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6448);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B645C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6460);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6464);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80040054);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80040248);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800405E4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80040718);

extern s16 D_800B63C6;
extern s16 D_800B7118;
extern s16 D_800B6CF0;
extern s32 D_800B6CC8;
void func_800408FC(s32 mode, s32 i);

void func_80040844(void) {
    s16 i;

    if (D_800B63C6 == 2 || D_800B7118 == 2) {
        func_800408FC(0, D_800B6CF0);
        return;
    }
    i = 0x3F;
    do {
        if (i == D_800B6CF0 && (D_800B6CC8 & 8)) {
            func_800408FC(0, i);
        } else {
            func_800408FC((i & 3) + 1, i);
        }
    } while (i--);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800408FC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80040BA4);

s16 func_80040D2C(s32 n) {
    return (u16)D_800B639E * n;
}

typedef struct {
    SVECTOR *v[4];
} Unk80040D54;

void func_80040D54(Unk80040D54 *f, VECTOR *out) {
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

extern s32 D_800B6FEC[];
extern u16 D_8009B468[];
extern s16 D_800B7048[];

void func_80040F04(s32 i) {
    if (D_8009B468[1] & *(volatile s32 *)D_800B6FEC) {
        if (++D_800B7048[i] == 0x100) {
            D_800B7048[i] = 0;
        }
    }
    if (D_8009B468[0] & *(volatile s32 *)D_800B6FEC) {
        if (--D_800B7048[i] == -1) {
            D_800B7048[i] = 0xFF;
        }
    }
}

extern s16 D_800B6EC8;

void func_80040FB4(void) {
    if (D_8009B468[1] & *(volatile s32 *)D_800B6FEC) {
        if (++D_800B6EC8 == 0x100) {
            D_800B6EC8 = 0;
        }
    }
    if (D_8009B468[0] & *(volatile s32 *)D_800B6FEC) {
        if (--D_800B6EC8 == -1) {
            D_800B6EC8 = 0xFF;
        }
    }
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
    s16 x2, y2;
} Unk80041064_PolyF3;

extern void SetPolyF3(Unk80041064_PolyF3 *p);

void func_80041064(s16 x, s32 y, u8 r, u8 g, u8 b) {
    Unk80041064_PolyF3 *p = D_800B7140;

    p->y0 = y + 1;
    p->y1 = y + 4;
    p->y2 = y + 7;
    p->x0 = x;
    p->x1 = x + 7;
    p->x2 = x;
    SetPolyF3(p);
    p->r0 = r;
    p->g0 = g;
    p->b0 = b;
    AddPrim(D_800B7018 + 10, p++);
    D_800B7140 = p;
}

extern s32 D_800B6D60;
extern u16 D_8009B472;
extern s16 D_800B7118;
void func_80041064(s16, s32, u8, u8, u8);

void func_8004110C(void) {
    if (D_8009B472 & *(volatile s32 *)&D_800B6D60) {
        func_80041064(0x12, D_800B7118 * 8 + 0x18, 0xFF, 0, 0);
    }
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6470);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6478);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6480);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6488);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6490);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80041168);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80041228);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80041558);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800418C4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800419C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64B8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80041DD8);

extern s16 D_800B63CC;

void func_80042548(void) {
    Unk8003F6D0_Src *src = (Unk8003F6D0_Src *)D_800B6DE0->vals;
    Unk8003F6D0_Cfg *cfg = (Unk8003F6D0_Cfg *)D_801F7550->vals;
    SVECTOR *v;
    Unk800462F0_Obj *o;

    if (D_800B63C6 == 1) {
        v = &D_800B73B8[D_800B63C8];
        v->vx = src->x;
        v->vy = src->y;
        v->vz = src->z;
        v[16].vx = src->unk18;
        v[16].vy = src->unk1A;
        v[16].vz = src->unk1C;
    }
    if (D_800B63C6 == 2 && D_800B63CC != 0) {
        o = &D_800B6E70[D_800B63C8];
        o->x = src->x;
        o->y = src->y;
        o->z = src->z;
        o->unk1A = src->unk1A;
        o->unk10 = cfg->unkC;
    }
}

extern struct Task *D_801F7550;
extern s16 D_800B6CE0;
extern s16 D_800B63C6;
extern s16 D_800B63CA;
extern s16 D_800B63D0;
extern s16 D_800B6EC8;
extern s16 D_800B7118;
void func_80066474(void);
void func_80042AD8(void);

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
} Unk8004265C;

void func_8004265C(void) {
    Unk8004265C *p = (Unk8004265C *)D_801F7550->vals;

    if (D_800B6CE0 != 0) {
        D_800B6CE0 = 0;
        D_800B6F00->unk0 = 1;
        func_800735F8(0x12);
        func_80066474();
        p->unk14 = 0;
        D_800B63C6 = 0;
        D_800B63CA = 0;
        D_800B63D0 = 0;
        D_800B6EC8 = 0;
        D_800B7118 = 0;
        D_800B6AA0 = 1;
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_80042AD8;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80042728);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80042908);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80042AD8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80043368);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64C8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800434A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64D8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800435FC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800436BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64F0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B64FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6504);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6508);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6510);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6518);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6520);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6528);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B652C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6534);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B653C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6544);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B654C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800446B8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80044844);

extern s32 D_800B63B0;
extern char D_8008839C[];
extern char D_800B64D8[];
extern char D_801F92B8[][16];
extern int FntPrint(s32 id, char *fmt, ...);

void func_80044A04(void) {
    s16 i;

    FntPrint(D_800B63B0, D_8008839C);
    for (i = 0; D_801F92B8[i][0] != 0; i++) {
        FntPrint(D_800B63B0, D_800B64D8, D_801F92B8[i]);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80044AA0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80044E08);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800451F4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800454AC);

void func_800454AC(void);

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
} Unk80046224;

void func_80046224(void) {
    struct Task *t = D_800B6DE0;
    Unk80046224 *p = (Unk80046224 *)t->vals;

    p->unkE = 0;
    p->unk0 = 0;
    p->unkC = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unk6 = 0;
    p->unkA = 0;
    p->unk2 = 1;
    p->unk10 = D_800B7430;
    p->unk12 = 0;
    p->unk14 = 0;
    p->unk16 = 0;
    p->unk1A = 0;
    p->unk1C = 0;
    p->unk1E = 10;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_800454AC;
    }
}

void func_80042908(s32 a, s32 b);

void func_800462B4(void) {
    s32 i;

    for (i = 0x20; i < 0x40; i++) {
        func_80042908(i, 0);
    }
}

extern Unk800462F0_Mesh *D_800B71B8;

void func_800462F0(s32 dx, s32 dy, s32 dz) {
    s32 i, j;

    for (i = 255; i != -1; i--) {
        D_800B6E70[i].x = dx + D_800B6E70[i].x;
        D_800B6E70[i].y = dy + D_800B6E70[i].y;
        D_800B6E70[i].z = dz + D_800B6E70[i].z;
    }
    for (i = 63; i != -1; i--) {
        for (j = 15; j != -1; j--) {
            D_800B71B8[i].v[j].vx = dx + D_800B71B8[i].v[j].vx;
            D_800B71B8[i].v[j].vy = dy + D_800B71B8[i].v[j].vy;
            D_800B71B8[i].v[j].vz = dz + D_800B71B8[i].v[j].vz;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046394);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046498);

extern s32 D_800B7258[];
extern s16 D_800B6B70;
extern volatile s32 D_800B725C;

s16 func_80046658(void) {
    if (*(volatile s32 *)D_800B7258 != 0) {
        return -1;
    }
    if (D_800B6B70 == 2 || D_800B6B70 == 4) {
        return D_800B725C;
    }
    return 0;
}

typedef struct {
    s16 vx;
    s16 vy;
} DVECTOR;

void func_800466B4(DVECTOR *p) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046764);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800469A8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046C30);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046E68);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80046FE0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800471B4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800474F0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80047968);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80047B48);

void func_8006576C(s32 arg);
void func_80055298(s32 *obj, s32 x0, s32 x1, s32 z0, s32 z1);

void func_80047E50(s32 *obj) {
    s16 i;
    s16 j;

    func_8006576C(obj[0]);
    for (i = 0; i < 0x1000; i += 0x800) {
        for (j = 0; j < 0x1000; j += 0x400) {
            func_80055298(obj, i, i + 0x800, j, j + 0x400);
        }
    }
}

extern SVECTOR D_800B73F8;
void func_80024914(s32 x, s32 y, s32 z, SVECTOR *out);
void func_80056E74(SVECTOR *a, SVECTOR *b, s16 c);

void func_80047EF8(VECTOR *pos, void *obj) {
    func_80024914(pos->vx, pos->vy, pos->vz, &D_800B73F8);
    func_80056E74(obj, &D_800B73F8, -1);
}

extern SVECTOR D_800B72E8;

void func_80047F4C(void *arg0) {
    func_8003E6F4(arg0, &D_800B72E8);
    func_80033D4C(&D_800B72E8);
}

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 pad;
    u16 unk10;
} Unk80047F84;

void func_80056E74(SVECTOR *a, SVECTOR *b, s16 c);
void func_8006684C();
void func_80065E44(s16 id, void *pos);
void func_80055ED4();
void func_800565F0();
void func_800577F8();

void func_80047F84(Unk80047F84 *a, void *obj) {
    func_80024914(a->x, a->y, a->z, &D_800B73F8);
    if ((s16)func_800754C8(2)) {
        func_80056E74((SVECTOR *)obj, &D_800B73F8, 0);
        func_8006684C((s16)func_800754C8(2) + 0x3A, obj);
    }
    if ((s16)func_800754C8(2)) {
        func_80065E44(0x39, obj);
        func_80055ED4(obj, &D_800B73F8, a->unk10);
    }
    if ((s16)func_800754C8(2)) {
        func_800565F0(obj);
    }
    func_800577F8(obj, a);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048064);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004816C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800482BC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048414);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048584);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048880);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048B34);

extern struct Task *volatile D_801F7548;
typedef struct {
    s16 unk0, unk2, unk4, unk6, unk8, unkA;
} Unk80048D40_Ent;

typedef struct {
    u8 pad0[0x2CA];
    s16 count;
    Unk80048D40_Ent ent[12];
    u8 unk35C[12];
} Unk80048D40;

void func_80048D40(Unk80048D40_Ent *src, s32 id) {
    Unk80048D40 *p;
    s16 n;

    if ((u32)D_801F7548 >= 8) {
        p = (Unk80048D40 *)D_801F7548->vals;
        n = p->count;
        if (n != 12) {
            p->ent[n].unk0 = src->unk0;
            p->ent[n].unk2 = src->unk2;
            p->ent[n].unk4 = src->unk4;
            p->ent[n].unk6 = src->unk6;
            p->ent[n].unkA = src->unkA;
            p->ent[n].unk8 = src->unk8;
            p->unk35C[n] = id;
            p->count++;
        }
    }
}

extern struct Task *volatile D_801F7548;
typedef struct {
    u8 pad0[0x38];
    s16 unk38;
    s16 pad3A;
    struct Task *unk3C[8];
    s32 unk5C[8];
} Unk80048DEC;

void func_80048DEC(void) {
    Unk80048DEC *p;
    s16 n;

    if ((u32)D_801F7548 >= 8) {
        p = (Unk80048DEC *)D_801F7548->vals;
        n = p->unk38;
        if (n != 8) {
            p->unk3C[n] = D_800B6DE0;
            p->unk5C[p->unk38++] = D_800B6DE0->id;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80048E64);

void func_800492A8(s16 *pos, s16 idx, s16 size) {
    POLY_FT4 *p;
    u16 *tex;

    if ((u8 *)D_800B7140 - D_800B70A8 <= 0xD7D7) {
        p = (POLY_FT4 *)D_800B6B90;
        p->x0 = pos[0] - size;
        p->x1 = size + pos[0];
        p->x2 = pos[0] - size;
        p->x3 = size + pos[0];
        p->y0 = pos[1] - size;
        p->y1 = pos[1] - size;
        p->y2 = size + pos[1];
        p->y3 = size + pos[1];
        tex = (u16 *)(D_8015EB78 + idx * 60);
        *(u32 *)&p->u0 = *(u32 *)tex;
        *(u32 *)&p->u1 = *(u32 *)(tex + 18);
        *(u16 *)&p->u2 = tex[4];
        *(u16 *)&p->u3 = tex[6];
        D_800B6B90 = (Unk8002B728_Prim *)(p + 1);
        AddPrim(D_800B7018 + 20, p);
    }
}

extern void SetPolyFT4(void *p);
extern void SetShadeTex(void *p, s32 tge);
extern void SetSemiTrans(void *p, s32 abe);

void func_800493CC(s16 *pos, s16 idx, s16 size) {
    POLY_FT4 *p = D_800B7140;
    POLY_FT4 *prim = p;
    u16 *tex;

    if ((u8 *)p - D_800B70A8 <= 0xD7D7) {
        p->x0 = pos[0] - size;
        p->x1 = size + pos[0];
        p->x2 = pos[0] - size;
        p->x3 = size + pos[0];
        p->y0 = pos[1] - size;
        p->y1 = pos[1] - size;
        p->y2 = size + pos[1];
        p->y3 = size + pos[1];
        tex = (u16 *)(D_8015EB78 + idx * 60);
        *(u32 *)&p->u0 = *(u32 *)tex;
        *(u32 *)&p->u1 = *(u32 *)(tex + 18);
        *(u16 *)&p->u2 = tex[4];
        *(u16 *)&p->u3 = tex[6];
        SetPolyFT4(p);
        SetShadeTex(p, 1);
        SetSemiTrans(p, 1);
        p++;
        AddPrim(D_800B7018 + 20, prim);
        D_800B7140 = p;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80049518);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800496B0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80049888);

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
    u8 pad18[8];
    s16 unk20;
} Unk8015EB3C;

typedef struct {
    s16 unk0;
    u8 pad2[0x28];
} Unk80097032;

extern Unk8015EB3C D_8015EB3C;
extern Unk80097032 D_80097032[];
void func_80065C10(s16 arg);
void func_800655BC(void);

void func_80049BBC(s16 id) {
    if (id == 2) {
        D_8015EB3C.unk0 = 0xDAC;
        D_8015EB3C.unk6 = func_800754C8(50) + 0x3A2;
    } else {
        D_8015EB3C.unk0 = 0x200;
        D_8015EB3C.unk6 = func_800754C8(50) + 0x406;
    }
    if (id == 4) {
        func_80065C10(0x3E);
        D_800B6C60[0] = 0x29;
        D_800B6C60[1] = 0x1A;
        func_80072F2C(func_800655BC, 0);
    } else {
        func_80065C10(D_80097032[id].unk0);
    }
}

typedef struct {
    u8 pad0[0x2C];
    s16 unk2C;
} Unk80049C9C;

extern Unk8015EB3C D_8015EB3C;
extern Unk80097032 D_80097032[];
s32 func_800754C8(s32);
void func_80066B70(Unk8015EB3C *arg0, s32 arg1);
void func_80065C10(s16 arg);

void func_80049C9C(Unk80049C9C *p) {
    if (p->unk2C == 2) {
        D_8015EB3C.unk0 = 0xDAC;
        D_8015EB3C.unk6 = func_800754C8(50) + 0x3A2;
        D_8015EB3C.unk4 = 0xFFF;
        D_8015EB3C.unk2 = 0;
        D_8015EB3C.unk8 = D_80097032[2].unk0 + 1;
        func_80066B70(&D_8015EB3C, 0);
    } else {
        func_80065C10(D_80097032[p->unk2C].unk0 + 2);
    }
}

typedef struct {
    u8 pad0[0x24];
    s16 unk24;
} Unk80049D50;

void func_80049D50(Unk80049D50 *p) {
    if (p->unk24 == 2) {
        D_8015EB3C.unk0 = 0xDAC;
        D_8015EB3C.unk6 = func_800754C8(50) + 0x3A2;
        D_8015EB3C.unk4 = 0xFFF;
        D_8015EB3C.unk2 = 0;
        D_8015EB3C.unk8 = D_80097032[2].unk0 + 1;
        func_80066B70(&D_8015EB3C, 0);
    } else {
        func_80065C10(D_80097032[p->unk24].unk0 + 1);
    }
}

typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[2];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[0x10];
    s16 unk1C;
    s16 unk1E;
    u8 pad20[4];
    s16 unk24;
    u8 pad26[4];
    s16 unk2A;
} Unk80049E04_Src;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[8];
    s32 unk10;
    s32 unk14;
    u8 pad18[8];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
} Unk80049E04;

void func_80049888(void);
extern Unk8003BA6C_Task *func_8007307C(void (*fn)(), s16 flags, s16 size);

void func_80049E04(Unk80049E04_Src *src, s16 flip) {
    Unk8003BA6C_Task *t;
    Unk80049E04 *p;

    t = func_8007307C(func_80049888, 0x10, 0x2C);
    if (t != NULL) {
        p = (Unk80049E04 *)t->data;
        p->unk0 = src->unk8 << 8;
        if (flip) {
            p->unk0 += 0x800;
        }
        p->unk4 = (src->unkA - 9) << 8;
        p->unk10 = (s16)func_800754C8(0x200) - 0x100;
        p->unk14 = -1500 - (s16)func_800754C8(0x200);
        p->unk20 = 0;
        p->unk22 = func_800754C8(0x80) - 0x40;
        p->unk24 = 15;
        p->unk26 = func_800754C8(0x40) + 0x80;
        if (src->unk2A == 1) {
            p->unk28 = -1;
        } else {
            p->unk28 = 0;
        }
        if ((s16)func_800754C8(2)) {
            p->unk26 = -p->unk26;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80049F28);

typedef struct {
    u8 pad0[0x388];
    s16 unk388;
    u8 pad38A[0x22];
    s16 unk3AC;
} Unk8004A0A8;

typedef struct {
    u16 unk0;
    u8 pad2[0x28];
} Unk80097034;

extern Unk80097034 D_80097034[];
extern s16 D_800B6C20;

s16 func_8004A0A8(s16 hit, Unk80049E04_Src *o) {
    Unk8004A0A8 *p = (Unk8004A0A8 *)D_800B6DE0->vals;

    if (p->unk3AC > 0 || hit == 0) {
        return 0;
    }
    if (o->unk1E == 2) {
        if (o->unk6 != 0) {
            func_80048880(o);
            func_80049BBC(o->unk24);
            p->unk3AC += D_80097034[o->unk24].unk0;
            D_800B6C20 = -1;
            func_80049E04(o, o->unk6 & 1);
            o->unk6--;
            return -1;
        }
        if (p->unk388 == 0) {
            p->unk388 = 0x800;
        }
        func_80049D50((Unk80049D50 *)o);
        o->unk2 = 0xFF;
        o->unk1C++;
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004A1D4);

typedef struct {
    u16 unk0;
    u8 pad2[8];
    u16 unkA;
    u8 padC[2];
    u16 unkE;
    u8 pad10[4];
    u16 unk14;
    u8 pad16[0x14];
} Unk8009701C;

extern Unk8009701C D_8009701C[];

void func_8004A8EC(Unk8005A018 *p) {
    s32 t;
    s16 e;

    p->unk6 = D_8009701C[p->unk24].unk0;
    t = D_8009701C[p->unk24].unkA * p->unk6;
    p->unk2 = 0;
    e = D_8009701C[p->unk24].unkE;
    p->unk0 = 0x80;
    p->unk1E = 0;
    p->unk22 = -1;
    p->unk1C = 0;
    p->unk26 = 4;
    p->unkA = e;
    p->unk4 = e + t - 26;
    p->unk28 = D_8009701C[p->unk24].unk14;
    switch (p->unk2A) {
    case 1:
        p->unk28 *= 2;
    case 2:
        p->unk28 = 5;
    case 3:
        p->unk28 = 4;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004AA38);

void func_8004AE3C(void) {
    u8 unused[16];
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004AE48);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004B0B4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004B348);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004B4A8);

typedef struct {
    u8 pad0[0x25C];
    u8 unk25C[5];
    u8 unk261[5];
} Unk8004B990;

extern u16 D_80096F78[];
extern s16 D_800B6CB0;
void func_80046C30();

void func_8004B990(void) {
    Unk8004B990 *p = (Unk8004B990 *)D_800B6DE0->vals;
    DVECTOR pos;
    s16 y;
    s16 i;

    y = 0xE0;
    if (D_800B7370->unk178A != 0) {
        y = 0xC8;
    }
    if (D_800B6CB0 != -1) {
        i = D_800B6CB0;
        while (i--) {
            if (p->unk25C[i] != 0) {
                pos.vx = i * 33 + 28;
                pos.vy = y;
                func_80046C30(&pos, (s16)(p->unk25C[i] + D_80096F78[p->unk261[i]] - 1), 4, 0x80);
            }
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004BA84);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004BD7C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004C16C);

typedef struct {
    u8 pad0[0x39C];
    s16 unk39C[9];
    s16 unk3AE[9];
} Unk8004C490;

extern s16 D_800B71E0;
extern s16 D_800B7388;
extern s16 D_801F6C60[2];
void func_8004C16C(void);

void func_8004C490(s16 hit, s16 i, s16 reset) {
    Unk8004C490 *p = (Unk8004C490 *)D_801F7548->vals;

    if ((u32)D_801F7548 < 8) {
        return;
    }
    if (reset) {
        p->unk3AE[i] = -1;
    }
    if (p->unk39C[i] == 0) {
        if (hit) {
            p->unk39C[i] = 4;
            D_800B71E0 = -1;
        }
        if (p->unk39C[i] == 0) {
            return;
        }
    }
    p->unk39C[i]--;
    if (D_800B7388 == 0) {
        return;
    }
    if (func_8004A0A8(-1, (Unk80049E04_Src *)&D_801F77E8[i])) {
        D_800B6C60[2] = 0;
        D_800B6C60[0] = D_801F6C60[0];
        D_800B6C60[1] = D_801F6C60[1];
        func_80072F2C(func_8004C16C, 4);
    }
    D_800B71E0 = 0;
    p->unk3AE[i] = 0;
    p->unk39C[i] = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004C5C4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004D00C);

extern s16 D_800B73E8;
extern s16 D_800B7290;
extern s16 D_800B6E58;
extern s16 D_800B6CC0;

void func_8004D264(void) {
    D_800B73E8 = 1;
    D_800B7290 = 0;
    D_801F77E8[0].unk2A = 0;
    D_801F77E8[0].unk24 = 1;
    D_801F77E8[1].unk2A = 0;
    D_801F77E8[1].unk24 = 1;
    D_801F77E8[0].unk2E = 0;
    D_801F77E8[0].unk2C = 1;
    D_801F77E8[1].unk2E = 0;
    D_801F77E8[1].unk2C = 1;
    func_8004A8EC(&D_801F77E8[0]);
    func_8004A8EC(&D_801F77E8[1]);
    D_801F77E8[1].unk22 = 0;
    D_801F77E8[0].unk20 = 0;
    D_801F77E8[1].unk20 = 1;
    D_800B6E58 = 10;
    D_800B6CC0 = 10;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004D31C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004D810);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004DB64);

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
} Unk8004DD70;

extern SVECTOR D_800B65EC;
extern struct Task *volatile D_801F7548;
extern Unk8003BA6C_Task *func_8007307C(void (*fn)(), s16 flags, s16 size);
void func_8004DFC0();

void func_8004DD70(SVECTOR *pos, s32 arg1, s16 arg2) {
    s32 y;
    SVECTOR v = D_800B65EC;
    Unk8004DD70 *d;
    Unk8003BA6C_Task *task;
    s16 n;
    s16 i;

    y = arg1;
    if (D_800B7370->unk1788 == 0) {
        return;
    }
    if (D_801F7548 == NULL) {
        return;
    }
    n = (arg2 * D_800B7370->unk1788) >> 12;
    task = func_8007307C(func_8004DFC0, 0x10, 0x16E);
    if (task == NULL) {
        return;
    }
    d = (Unk8004DD70 *)task->data;
    d->unk16C = func_80072734(4, 0x10, n);
    d->unk148 = func_80072734(20, 80, n);
    d->unk16A = 10;
    d->pos.vx = pos->vx;
    d->pos.vy = pos->vy;
    d->pos.vz = pos->vz;
    i = 15;
    do {
        D_800B72E8.vx = func_800754C8(0x1000);
        D_800B72E8.vy = func_800754C8(0x1000);
        D_800B72E8.vz = func_800754C8(0x1000);
        func_80024F70(&D_800B72E8, &v, (SVECTOR *)&D_800B67D0, &d->out[i]);
        d->out[i].vx >>= 1;
        d->out[i].vz >>= 1;
        d->vel[i].vx = func_800754C8(10) - 5;
        d->vel[i].vy = func_800754C8(10) - 5 + y;
        d->vel[i].vz = func_800754C8(10) - 5;
        d->angle[i] = func_800754C8(0x1000);
        d->unk128[i] = func_80072734((s16)(func_800754C8(0x200) - 0x100), 0, n);
        if ((s16)func_800754C8(2)) {
            d->unk14A[i] = 1;
        } else {
            d->unk14A[i] = 4;
        }
    } while (i--);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004DFC0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004E3E4);

s32 func_8004E6D8(SVECTOR *a, SVECTOR *b, SVECTOR *c) {
    s32 bx = b->vx;
    s32 by = b->vy;

    return (by - a->vy) * (c->vx - bx) > (bx - a->vx) * (c->vy - by);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004E720);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004EB78);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004ED08);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004F238);

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 pad1C[0x26A];
    u8 unk286;
} Unk8004F6F4;

void func_8004F6F4(Unk8004F6F4 *p) {
    if (p->unk286 == 6) {
        p->unk14 = -175;
        p->unk18 = 350;
    } else {
        p->unk14 = -150;
        p->unk18 = 300;
    }
    p->unk16 = -350;
    p->unk1A = 700;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004F734);

extern SVECTOR D_800B65F4;
extern SVECTOR D_800B65FC;
extern void *D_801F9ABC;
extern void func_80020030(void *a, SVECTOR *b, SVECTOR *c);

void func_8004F7DC(SVECTOR *base, SVECTOR *rot) {
    SVECTOR out;
    SVECTOR unused;

    if (D_800B7430 == 0) {
        func_800247D0(rot, &D_800B65F4, base, &out);
    } else {
        func_800247D0(rot, &D_800B65FC, base, &out);
    }
    func_80020030(D_801F9ABC, &out, rot);
}

extern SVECTOR D_800B6604;
extern void *D_801F9A94;
extern void func_8001F90C(void *a, SVECTOR *b, SVECTOR *c, s32 d);

void func_8004F844(SVECTOR *base, SVECTOR *rot) {
    SVECTOR out;
    SVECTOR v = D_800B6604;
    SVECTOR unused;

    func_800247D0(rot, &v, base, &out);
    func_8001F90C(D_801F9A94, &out, rot, 0);
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6558);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6560);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6568);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B656C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6570);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6574);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6588);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B658C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6590);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6598);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65A8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65B0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65B8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65C0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65C8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B65FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6604);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004F8B8);

void func_8004F8B8(void);

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
} Unk8004F9B4;

void func_8004F9B4(void) {
    struct Task *t = D_800B6DE0;

    ((Unk8004F9B4 *)t->vals)->unk40 = 300;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_8004F8B8;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004FA04);

typedef struct {
    u8 pad0[0x10];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 pad13[0x2C];
    u8 unk3F;
    u8 pad40[0x204];
    s16 unk244;
    u8 pad246[0x56];
    s16 unk29C;
    s16 unk29E;
} Unk8004FA88;

void func_8004FA88(Unk8004FA88 *obj) {
    if (obj->unk29E != 0x1000) {
        obj->unk29E = func_80025570(obj->unk29E, 0x1000, 0x200);
    }
}

s32 func_8004FAC4(void) {
    Unk8004FA88 *p = (Unk8004FA88 *)D_800B6DE0->vals;

    if ((u32)D_801F7548 < 8) {
        return 0;
    }
    if (p->unk29C != 0) {
        func_8004FA88(p);
        p->unk29C--;
        return 0;
    }
    if (p->unk10 != 0) {
        if (p->unk10 == 2) {
            p->unk244 -= p->unk11;
            if (p->unk29E == 0x1000 && p->unk12 == 0) {
                p->unk29E = 0x1FFF;
            } else {
                func_8004FA88(p);
            }
            if (p->unk3F != 0) {
                if (p->unk12 != 0) {
                    func_8004DD70((SVECTOR *)p, 200, 0x1000);
                    func_8004DD70((SVECTOR *)p, 600, 0x1000);
                } else {
                    func_8004DD70((SVECTOR *)p, 400, 0x200);
                }
            }
            return p->unk244 <= 0;
        }
    }
    func_8004FA88(p);
    return 0;
}

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 pad6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 padE[0x12];
} Unk80095F88;

typedef struct {
    u8 pad0[0x1D4];
    u16 unk1D4;
    u16 unk1D6;
    u16 unk1D8;
    u8 pad1DA[0x12];
    u16 unk1EC;
    u16 unk1EE;
    u16 unk1F0;
} Unk8004FBEC;

extern Unk80095F88 D_80095F88[];

void func_8004FBEC(Unk8004FBEC *p, s16 i) {
    p->unk1EC = D_80095F88[i].unk0;
    p->unk1EE = D_80095F88[i].unk2;
    p->unk1F0 = D_80095F88[i].unk4;
    p->unk1D4 = D_80095F88[i].unk8;
    p->unk1D6 = D_80095F88[i].unkA;
    p->unk1D8 = D_80095F88[i].unkC;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004FC84);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8004FDC4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80051048);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800511BC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80051820);

typedef struct {
    u8 pad0[0x3C];
    s16 unk3C;
    u8 pad3E;
    u8 unk3F;
    u8 pad40[0x246];
    u8 unk286;
    u8 pad287[2];
    u8 unk289;
} Unk80051ACC;

extern s16 D_800B6B88;
extern s16 D_800B6DF8;
extern void func_8004F734(void *p);
extern void func_800524D8(void *p, s16 arg1);

void func_80051ACC(void) {
    Unk80051ACC *p = (Unk80051ACC *)D_800B6DE0->vals;

    if (p->unk3F == 0xFF) {
        func_8004F734(p);
        if (p->unk286 == 6) {
            D_800B6B88++;
        } else {
            D_800B6DF8++;
        }
        if (p->unk289 != 0xFF) {
            func_800524D8(p, p->unk3C);
        }
        func_8004DD70((SVECTOR *)p, 200, 0x1000);
        func_8004DD70((SVECTOR *)p, 600, 0x1000);
    }
    func_8007345C();
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80051B9C);

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
    u8 pad44[0x1C6];
    s16 unk20A;
    s16 unk20C;
    u8 pad20E[2];
    s16 unk210;
} Unk80051D68;

void func_80051D68(Unk80051D68 *p) {
    p->unk40++;
    if (p->unk210 < p->unk40) {
        if (--p->unk20C != 0) {
            p->unk40 = 0;
        } else {
            p->unk20A++;
            func_80051048(p);
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80051DD0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80051FD0);

typedef struct {
    u8 pad0[0x1D4];
    s16 unk1D4;
    s16 unk1D6;
    s16 unk1D8;
} Unk800521B8;

void func_800521B8(Unk800521B8 *obj) {
    obj->unk1D4 = func_800754C8(0x80) - 0x40;
    obj->unk1D6 = func_800754C8(0x80) - 0x40;
    obj->unk1D8 = func_800754C8(0x80) - 0x40;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80052208);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800524D8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80052640);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80052A14);

typedef struct {
    SVECTOR pos;
    u8 pad8[0xB];
    u8 type;
} Unk80052CD8;

extern VECTOR D_801F6C7C;
extern SVECTOR D_800B6C98;
extern Unk800B7398 *D_800B7398;
void func_80059118(SVECTOR *pos, s32 type, s32 flag, struct Task *t);

void func_80052CD8(Unk80052CD8 *p) {
    func_80027898(&D_800B6C98, &D_801F9644);
    ApplyMatrix(&D_801F9644, &D_800B7398->unk38, &D_801F6C7C);
    D_800B73F8.vx = D_801F6C7C.vx + p->pos.vx;
    D_800B73F8.vy = D_801F6C7C.vy + p->pos.vy;
    D_800B73F8.vz = D_801F6C7C.vz + p->pos.vz;
    func_80059118(&D_800B73F8, p->type, 0, D_800B6DE0);
}

void func_80052D94(Unk80052CD8 *p) {
    func_80027898(&D_800B6C98, &D_801F9644);
    ApplyMatrix(&D_801F9644, &D_800B7398->unk38, &D_801F6C7C);
    D_800B73F8.vx = D_801F6C7C.vx + p->pos.vx;
    D_800B73F8.vy = D_801F6C7C.vy + p->pos.vy;
    D_800B73F8.vz = D_801F6C7C.vz + p->pos.vz;
    func_80059118(&D_800B73F8, p->type, 1, D_800B6DE0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80052E50);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053014);

typedef struct {
    u8 pad0[0x268];
    s16 unk268;
} Unk800532A4_Data;

typedef struct {
    u8 pad0[0x13];
    u8 unk13;
    u8 pad14[0x232];
    s16 unk246;
} Unk800532A4;

extern struct Task *volatile D_801F7548;
void func_80065E44(s16 id, void *pos);

void func_800532A4(Unk800532A4 *obj) {
    Unk800532A4_Data *d;

    if (D_801F7548 != NULL) {
        d = (Unk800532A4_Data *)D_801F7548->vals;
        func_80065E44(0x24, obj);
        if (obj->unk246 == 1) {
            d->unk268 = obj->unk13;
        }
    }
}

typedef struct {
    SVECTOR pos;
    s16 unk8;
    u8 padA[6];
    u8 unk10;
    u8 pad11;
    u8 unk12;
    u8 pad13[0x21];
    SVECTOR unk34;
    u8 pad3C[0x1A8];
    SVECTOR unk1E4;
    u8 pad1EC[0x14];
    struct Task *unk200;
    s32 unk204;
    s16 unk208;
    s16 unk20A;
    u8 pad20C[0xA];
    s16 unk216;
    s16 unk218;
    s16 unk21A;
} Unk800536A8;

void func_80053310(Unk800536A8 *p) {
    struct Task *t = p->unk200;
    Unk800536A8 *q;

    if (t != NULL) {
        if (p->unk204 == t->id) {
            q = (Unk800536A8 *)t->vals;
            if (q->unk8 != 0) {
                if (p->unk218 == -1) {
                    p->unk12 = 0;
                    p->unk216 = 1;
                } else {
                    p->unk10 = 0;
                    p->unk208 = p->unk21A;
                    p->unk20A = p->unk218;
                    func_80051048();
                }
            } else {
                p->pos.vx = q->pos.vx;
                p->pos.vy = q->pos.vy;
                p->pos.vz = q->pos.vz;
                p->unk34.vx = q->unk34.vx;
                p->unk34.vy = q->unk34.vy;
                p->unk34.vz = q->unk34.vz;
                func_80024F70(&p->unk34, &p->unk1E4, &p->pos, &p->pos);
            }
        } else {
            p->unk200 = NULL;
            p->unk204 = -1;
        }
    }
}

typedef struct {
    SVECTOR pos;
    u8 pad8[0x2C];
    SVECTOR rot;
    u8 pad3C[0x16C];
    u8 anim[0x16];
    u16 unk1BE;
    u8 pad1C0[0x14];
    SVECTOR spin;
    u8 pad1DC[0x10];
    SVECTOR vel;
} Unk80053404;

void func_80053404(Unk80053404 *p) {
    VECTOR v;
    s16 n;
    s32 dt;

    p->rot.vx += p->spin.vx;
    p->rot.vy += p->spin.vy;
    p->rot.vz += p->spin.vz;
    n = p->vel.vz;
    if (n > 0) {
        if (p->unk1BE == 0) {
            p->vel.vz = func_80035584((Anim *)p->anim);
        }
        func_80024F70(&p->rot, &p->vel, &p->pos, &p->pos);
    } else {
        func_80027898(&p->rot, &D_801F9644);
        ApplyMatrix(&D_801F9644, &p->vel, &v);
        dt = D_800B639E;
        p->pos.vx += dt * v.vx;
        p->pos.vy += dt * v.vy;
        p->pos.vz += dt * v.vz;
    }
    p->vel.vz = n;
    func_80053310((Unk800536A8 *)p);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053544);

extern s32 func_8004FAC4(void);
extern void func_8004FA04(void);
void func_80051048();

void func_800536A8(Unk800536A8 *p) {
    if ((s16)func_8004FAC4() != 0) {
        p->unk10 = 0;
        if (p->unk218 == -2) {
            return;
        }
        if (p->unk218 == -1) {
            p->unk216 = 1;
        }
        p->unk208 = p->unk21A;
        p->unk20A = p->unk218;
        func_80051048();
        p->unk218 = -2;
    }
    func_8004FA04();
}

typedef struct {
    u8 pad0[0x36];
    s16 unk36;
    u8 pad38[0x24A];
    u8 unk282;
} Unk8005371C;

void func_8005371C(Unk8005371C *p) {
    s16 a = func_80025254((Unk8002A35C *)&D_800B6E00, (Unk8002A35C *)p);

    if (p->unk282 == 2) {
        p->unk36 = func_800255BC(p->unk36, a, 0x60);
    } else {
        p->unk36 = func_800255BC(p->unk36, a, 0x20);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053794);

typedef struct {
    u8 pad0[0x34];
    u8 unk34[8];
    u8 pad3C[2];
    u8 unk3E;
    u8 unk3F;
    u8 pad40[0x168];
    u8 unk1A8[0x62];
    s16 unk20A;
    s16 unk20C;
    u8 pad20E[0x71];
    u8 unk27F;
    u8 pad280[9];
    u8 unk289;
    u8 pad28A;
    u8 unk28B;
    u8 pad28C[0x12];
    s16 unk29E;
} Unk80054100;

void func_80053544(Unk80054100 *obj);
void func_80051DD0();
void func_80051FD0();

void func_800538F4(Unk80054100 *p) {
    if (p->unk3F != 0) {
        p->unk3E = 0;
        func_800536A8((Unk800536A8 *)p);
        p->unk27F = func_80035A18(p, p->unk34, p->unk29E, p->unk28B, p->unk1A8);
        if (p->unk27F >= 4) {
            if (p->unk289 == 1) {
                func_80051DD0(p);
            }
            if (p->unk289 == 0) {
                func_80051FD0(p);
            }
        }
        func_8004FA04();
        func_80053544(p);
    }
    if (--p->unk20C <= 0) {
        p->unk20A++;
        func_80051048();
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800539D0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053B58);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053D44);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80053E20);

typedef struct {
    u8 pad0[0x36];
    s16 unk36;
    u8 pad38[8];
    s32 unk40;
    u8 pad44[0xA];
    s16 unk4E;
    u8 pad50[0x1BC];
    u16 unk20C;
    u8 pad20E[0x10];
    s16 unk21E;
    u8 pad220[0x4E];
    u8 unk26E[16];
} Unk800540A8;

void func_800540A8(Unk800540A8 *p) {
    s16 i;

    p->unk40 = 0;
    p->unk4E = 0;
    p->unk21E = p->unk20C & 0xF;
    p->unk36 += 0x800;
    i = 15;
    do {
        p->unk26E[i] = 0;
    } while (i--);
}

typedef struct {
    u8 pad0[0x216];
    s16 unk216;
} Unk800540F4;

void func_800540F4(Unk800540F4 *obj) {
    obj->unk216 = 2;
}

u8 func_80024864(void);
void func_80051048();

void func_80054100(Unk80054100 *obj) {
    obj->unk27F = func_80024864();
    func_80053544(obj);
    if (obj->unk20C-- < 0) {
        obj->unk20A++;
        func_80051048();
    }
}

extern s16 D_800B6BF0;

typedef struct {
    u8 pad0[0x291];
    u8 unk291;
} Unk8005415C;

void func_8005415C(Unk8005415C *p) {
    if (p->unk291) {
        D_800B6BF0--;
    }
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6614);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B661C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B662C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005418C);

void func_8005418C(void);

void func_8005472C(void) {
    struct Task *t = D_800B6DE0;

    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_8005418C;
    }
    func_80051048();
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80054784);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005490C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80054C68);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80054F04);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80055298);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80055A30);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80055ED4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80056178);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800565F0);

typedef struct {
    SVECTOR pos[16];
    SVECTOR vel[16];
    u8 pad100[0x10];
    SVECTOR dir;
    u8 unk118[16];
} Unk8005673C;

void func_8005673C(s16 i) {
    Unk8005673C *d = (Unk8005673C *)D_800B6DE0->vals;

    d->pos[i].vx = func_800754C8(8) - 4;
    d->pos[i].vy = func_800754C8(8) - 4;
    d->pos[i].vz = func_800754C8(8) - 4;
    d->vel[i].vx = -d->dir.vx >> 7;
    d->vel[i].vy = -d->dir.vy >> 7;
    d->vel[i].vz = -d->dir.vz >> 7;
    d->vel[i].vz = func_800754C8(16) + (s16)(d->vel[i].vz - 8);
    d->vel[i].vx = func_800754C8(16) + (s16)(d->vel[i].vx - 8);
    d->vel[i].vy = func_800754C8(16) + (s16)(d->vel[i].vy - 8);
    d->unk118[i] = 0xFF;
}

void func_80056844(s16 i) {
    Unk8005673C *d = (Unk8005673C *)D_800B6DE0->vals;
    s16 j;
    s16 dx, dy, dz;

    j = func_800754C8(0x10);
    if (d->unk118[i] != 0) {
        d->pos[j].vx = d->pos[i].vx;
        d->pos[j].vy = d->pos[i].vy;
        d->pos[j].vz = d->pos[i].vz;
        dx = func_800754C8(0x20) - 0x10;
        dy = func_800754C8(0x20) - 0x10;
        dz = func_800754C8(0x20) - 0x10;
        d->vel[j].vx = dx + d->vel[i].vx;
        d->vel[j].vy = dy + d->vel[i].vy;
        d->vel[j].vz = dz + d->vel[i].vz;
        d->vel[i].vx -= dx;
        d->vel[i].vy -= dy;
        d->vel[i].vz -= dz;
        d->unk118[j] = d->unk118[i];
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80056974);

void func_8005673C(s16);
void func_80056974(void);

typedef struct {
    u8 pad0[0x128];
    s16 unk128;
    s16 unk12A;
    s16 unk12C;
    s16 pad12E;
    s16 unk130;
} Unk80056DD4;

void func_80056DD4(void) {
    s16 i = 15;
    Unk80056DD4 *p = (Unk80056DD4 *)D_800B6DE0->vals;

    do {
        func_8005673C(i);
    } while (i--);
    p->unk128 = 1;
    p->unk12A = 0;
    p->unk12C = -0x400;
    p->unk130 = 1;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80056974;
    }
}

typedef struct {
    u8 pad0[0x100];
    SVECTOR a;
    u8 pad108[8];
    SVECTOR b;
    u8 pad118[0x16];
    s16 unk12E;
} Unk80056E74;

void func_80056DD4(void);

void func_80056E74(SVECTOR *a, SVECTOR *b, s16 c) {
    struct Task *t = (struct Task *)func_8007307C(func_80056DD4, 0x10, 0x132);
    Unk80056E74 *d;

    if (t != NULL) {
        d = (Unk80056E74 *)t->vals;
        d->a.vx = a->vx;
        d->a.vy = a->vy;
        d->a.vz = a->vz;
        d->b.vx = b->vx;
        d->b.vy = b->vy;
        d->b.vz = b->vz;
        d->unk12E = c;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80056F14);

void func_80056F14(void);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk80057220_Entry;

typedef struct {
    Unk80057220_Entry a[30];
    Unk80057220_Entry b[90];
    s16 unk3C0;
} Unk80057220;

void func_80057220(void) {
    Unk80057220 *p = (Unk80057220 *)D_800B6DE0->vals;
    s16 i = 29;

    do {
        p->a[i].unk6 = 0;
        p->b[i].unk6 = 0;
    } while (i--);
    p->unk3C0 = 0;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80056F14;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80057298);

void func_80057298(void);

void func_80057660(void) {
    Unk80057220 *p = (Unk80057220 *)D_800B6DE0->vals;
    s16 i = 29;

    do {
        p->a[i].unk6 = 0;
        p->b[i].unk6 = 0;
    } while (i--);
    p->unk3C0 = 0;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80057298;
    }
}

void func_800576D8(SVECTOR *a, SVECTOR *b, SVECTOR *out) {
    out->vx = b->vx - a->vx;
    out->vy = b->vy - a->vy;
    out->vz = b->vz - a->vz;
    func_80025860(out);
}

void func_80057734(SVECTOR *out, SVECTOR *base, SVECTOR *dir, s16 n) {
    s16 k;

    k = func_800754C8(n);
    k += n;
    out->vx = base->vx + ((dir->vx * k) >> 12);
    out->vy = base->vy + ((dir->vy * k) >> 12);
    out->vz = base->vz + ((dir->vz * k) >> 12);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800577F8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80057AB0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80057E50);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80058338);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800589F4);

typedef struct {
    u8 pad0[8];
    s16 unk8;
} Unk80058DC4;

void func_800589F4(Unk80058DC4 *obj, s32 a, s32 b);
extern void func_8007345C(void);

void func_80058DC4(void) {
    Unk80058DC4 *obj = (Unk80058DC4 *)D_800B6DE0->vals;

    func_800589F4(obj, 0x400, 1);
    if (++obj->unk8 > 30) {
        func_8007345C();
    }
}

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[2];
    s16 unk8;
} Unk80058E28;

void func_80058E28(SVECTOR *pos) {
    struct Task *t = (struct Task *)func_8007307C(func_80058DC4, 0x10, 0xA);
    Unk80058E28 *d;

    if (t != NULL) {
        d = (Unk80058E28 *)t->vals;
        d->unk8 = 0;
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80058E94);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80059118);

typedef struct {
    u8 pad0[0x12C];
    s16 unk12C;
} Unk80059394;

typedef struct {
    u8 pad0[0x368];
    s16 unk368;
} Unk80059394_Ctl;

extern struct Task *volatile D_801F7548;
extern void func_8005B9F0(Unk80059394 *p);

void func_80059394(void) {
    Unk80059394 *p = (Unk80059394 *)D_800B6DE0->vals;
    Unk80059394_Ctl *ctl;

    if ((u32)D_801F7548 >= 8) {
        ctl = (Unk80059394_Ctl *)D_801F7548->vals;
        func_8005B9F0(p);
        p->unk12C += D_800B639E * 100;
        if (p->unk12C > 0x1000) {
            ctl->unk368--;
            func_8007345C();
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80059440);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800595DC);

typedef struct {
    u8 pad0[8];
    SVECTOR v[1];
} Unk80059978;

extern SVECTOR D_800B6644;

void func_80059978(Unk80059978 *p, s16 i) {
    SVECTOR a = D_800B6644;
    SVECTOR b = D_800B6644;
    s16 d;

    p->v[i].vx = func_800754C8(6000) - 3000;
    p->v[i].vz = func_800754C8(6000) - 3000;
    d = func_80077398((Unk8002A35C *)&D_800B6E00, (Unk8002A35C *)&p->v[i]);
    p->v[i].vy = D_800B6E00.vy + d / 4;
    p->v[i].pad = func_800754C8(16) + 16;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80059A68);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80059CF8);

void func_800669A0(void);

void func_80059DAC(void) {
    struct Task *t = D_800B6DE0;

    if (t->unk16 <= 0) {
        D_8015EB3C.unk4 = 0x3FFF;
        D_8015EB3C.unk0 = 0;
        D_8015EB3C.unk10 = 0x100;
        D_8015EB3C.unk2 = 0;
        D_8015EB3C.unk6 = 0x400;
        D_8015EB3C.unk14 = 5;
        D_8015EB3C.unk8 = 50;
        func_80066B70(&D_8015EB3C, (s32)func_800669A0);
        D_8015EB3C.unk0 = 0x1000;
        D_8015EB3C.unk10 = -0x100;
        D_8015EB3C.unk14 = 7;
        D_8015EB3C.unk8 = 50;
        func_80066B70(&D_8015EB3C, (s32)func_800669A0);
    } else {
        t->unk16 -= D_800B639E;
        t->unk14 += D_800B639E * 100;
        if (t->unk14 <= 0x1000) {
            return;
        }
    }
    func_8007345C();
}

void func_80059EE8(s16 n) {
    s16 *d = (s16 *)D_801F7548->vals;

    d[0x1C6] = 1;
    d[0x1C1] += n * 60;
}

extern s16 D_800B6CC0;
void func_8003D570(s32 arg);

void func_80059F20(void) {
    func_8003D570(4000);
    D_800B6CC0++;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80059F58);

extern s16 D_800B6E58;

void func_80059FE0(void) {
    func_8003D570(2000);
    D_800B6E58++;
}

extern s16 D_801F7808;
extern Unk8005A018 D_801F7818;
extern s16 D_801F7838;
extern s16 D_800B73E8;

void func_8005A018(s16 id, s16 arg) {
    Unk8005A018 *p;

    if (id == 2) {
        p = &D_801F7818;
        if (D_801F7838 != 0) {
            D_801F7838 = 1;
        }
    } else {
        p = &D_801F77E8[0];
        if (id != D_800B73E8) {
            D_801F7808 = 1;
        } else {
            D_801F7808 = 0;
        }
    }
    p->unk22 = -1;
    p->unk2C = id;
    p->unk2E = arg;
    p->unk1E = 1;
}

void func_8005A0A4(s16 a) {
    Unk8005A018 *p = &D_801F77E8[0];

    p->unk2C = p->unk24;
    if (a == D_800B7290) {
        if (p->unk1E == 2) {
            p->unk2C = p->unk24;
            p->unk22 = -1;
            p->unk1E = 1;
            p->unk2E = p->unk2A;
            if (p->unk20 == 3) {
                p->unk20 = 1;
            }
        }
    } else if (a != 1 || p->unk24 != 4) {
        if (a == -1) {
            p->unk2E = p->unk2A;
        } else {
            p->unk2E = a;
        }
        p->unk1E = 1;
        if (p->unk20 != 0) {
            p->unk20 = 1;
        }
    }
}

extern s16 D_801F780C;
extern s16 D_801F7808;
extern s16 D_801F7814;
extern s16 D_801F7816;
extern s16 D_801F7806;

void func_8005A1A0(s16 a, s16 b) {
    if (D_801F780C == a) {
        D_801F7814 = D_801F780C;
        D_801F7816 = b;
        D_801F7806 = 1;
        if (D_801F7808 == 3) {
            D_801F7808 = 1;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005A1FC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6634);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6638);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B663C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6640);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6644);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005A2F0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005A4CC);

void func_8003EB60(void *);
void func_8005A4CC(void);

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
    s16 unk44;
} Unk8005A9B0;

void func_8005A9B0(void) {
    Unk8005A9B0 *p = (Unk8005A9B0 *)D_800B6DE0->vals;

    if (--p->unk40 < 0) {
        p->unk44 = 0;
        func_8003EB60(p);
        if (D_800B6DE0->func == D_800B7350) {
            TRAP();
        } else {
            D_800B6DE0->func = func_8005A4CC;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005AA2C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005ABB8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005AFD0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005B9F0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005BE40);

typedef struct {
    u8 pad0[6];
    s16 unk6;
} Unk8005BF98Slot;

typedef struct {
    Unk8005BF98Slot slots[0x24];
    s16 unk120;
    s16 unk122;
} Unk8005BF98;

void func_8005BF98(Unk8005BF98 *p, s16 v) {
    s16 i = 0x17;

    do {
        p->slots[i].unk6 = -1;
    } while (i--);
    p->unk122 = v;
    p->unk120 = 0;
}

typedef struct {
    SVECTOR pts[24];
    s16 unkC0[24];
    s16 unkF0[24];
    s16 idx;
} Unk8005BFCC;

void func_8005BFCC(Unk8005BFCC *p, SVECTOR *v) {
    p->idx = (p->idx + 1) % 24;
    p->pts[p->idx].vx = v->vx;
    p->pts[p->idx].vy = v->vy;
    p->pts[p->idx].vz = v->vz;
    p->pts[p->idx].pad = 0x80;
    p->unkC0[p->idx] = func_800754C8(0x1000);
    p->unkF0[p->idx] = func_800754C8(200) - 100;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005C0AC);

void func_800669A0(void);

void func_8005C5C0(void) {
    D_8015EB3C.unk0 = 0x1000;
    D_8015EB3C.unk10 = -0x66;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3FFF;
    D_8015EB3C.unk12 = -0xCC;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk14 = -10;
    D_8015EB3C.unk8 = 0x21;
    func_80066B70(&D_8015EB3C, (s32)func_800669A0);
    D_8015EB3C.unk0 = 0;
    D_8015EB3C.unk10 = 0x66;
    D_8015EB3C.unk14 = -8;
    func_80066B70(&D_8015EB3C, (s32)func_800669A0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005C678);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005CB50);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005D0E0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005D24C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005D2DC);

void func_8005D24C(s16);
void func_8005D2DC(void);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0x102];
    s16 unk108;
} Unk8005D474;

void func_8005D474(void) {
    Unk8005D474 *p = (Unk8005D474 *)D_800B6DE0->vals;
    s16 i = 31;

    p->unk0 = 0x1002;
    p->unk2 = 0xD90;
    p->unk4 = -0x2000;
    p->unk108 = 0;
    do {
        func_8005D24C(i);
    } while (i--);
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8005D2DC;
    }
}

void func_8005D510(SVECTOR *v, s16 a, s16 b) {
    s16 n;

    if (v != (SVECTOR *)-1) {
        n = ((s16)(func_80025998(v) - b) << 2) / (a - b);
        if (n < 0) {
            n = 0;
        }
        if (n >= 4) {
            n = 3;
        }
        v->pad = n;
    }
}

s16 func_8005D5D8(SVECTOR *v) {
    if (v == (SVECTOR *)-1) {
        return -1;
    }
    return func_80025998(v);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005D608);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005D82C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005DF50);

typedef struct {
    SVECTOR pos;
    u8 pad8[4];
    SVECTOR v[9][5];
} Unk8005E250;

s16 func_8005E250(Unk8005E250 *obj, s16 dstep, s16 step, s16 y) {
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
            x = D_800982E4[(k * 0x200) & 0xFFF] * r;
            z = D_800982E4[(k * 0x200 + 0x400) & 0xFFF] * r;
            obj->v[j][i].vx = (x >> 12) + obj->pos.vx;
            obj->v[j][i].vz = (z >> 12) + obj->pos.vz;
            obj->v[j][i].vy = y + func_800754C8(0x40);
        } while (j-- != 0);
        prev = y;
        y -= step;
        step += dstep;
    }
    return prev;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005E3EC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005E6F4);

int func_8005E828(int a, int b, int c) {
    int t;

    if (b <= 0) {
        t = (b * c) >> 12;
    } else {
        t = b >> 2;
    }
    return a + t;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005E84C);

typedef struct {
    SVECTOR origin;
    SVECTOR pos[12];
    s16 unk68;
    s32 unk6C[12];
    s32 unk9C[12];
    s16 unkCC[12];
    s16 unkE4[12];
    s16 unkFC[12];
    s16 unk114[12];
    u8 pad12C[0x30];
    s16 unk15C[12];
    s16 unk174;
} Unk8005EDB8;

void func_8005E84C();

void func_8005EDB8(SVECTOR *pos) {
    Unk8003BA6C_Task *task;
    Unk8005EDB8 *d;
    s16 i;
    s16 t;
    s16 r;
    s16 ang;

    task = func_8007307C(func_8005E84C, 0x10, 0x17C);
    if (task == NULL) {
        return;
    }
    i = 11;
    d = (Unk8005EDB8 *)task->data;
    d->origin.vx = pos->vx;
    d->origin.vy = pos->vy;
    d->origin.vz = pos->vz;
    d->unk174 = 0x1000;
    do {
        if (i < 4) {
            t = func_800754C8(0x400);
        } else {
            t = func_800754C8(3000) + 0x400;
        }
        d->unk9C[i] = func_80072734(0x1000, 0x1000, t);
        d->unkCC[i] = func_80072734(1500, 0x200, t);
        d->unk15C[i] = func_80072734(0x20, 8, t);
        d->unk6C[i] = func_80072734(80, 120, t);
        ang = i * 0x155;
        r = func_80072734(0, 500, t);
        d->pos[i].vx = pos->vx + ((D_800982E4[ang] * r) >> 12);
        d->pos[i].vy = pos->vy;
        d->pos[i].vz = pos->vz + ((D_800982E4[(ang + 0x400) & 0xFFF] * r) >> 12);
        d->unkE4[i] = func_800754C8(800) + 100;
        d->unkFC[i] = func_800754C8(8) + 16;
        d->unk114[i] = 10;
        if ((s16)func_800754C8(2)) {
            d->unkFC[i] = -d->unkFC[i];
        }
    } while (i--);
    d->unk68 = 0xFF;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005F00C);

extern long D_800B6F60;
extern long D_800B6F68;
extern long D_800B6F70;
extern long D_800B6F78;

s32 func_8005F1EC(void) {
    while (1) {
        if (TestEvent(D_800B6F60) == 1) {
            return 0;
        }
        if (TestEvent(D_800B6F68) == 1) {
            return 1;
        }
        if (TestEvent(D_800B6F70) == 1) {
            return 2;
        }
        if (TestEvent(D_800B6F78) == 1) {
            return 3;
        }
    }
}

s32 func_8005F26C(s16 chan) {
    if (_card_info(chan) == 0) {
        return 2;
    }
    return func_8005F1EC();
}

extern s32 D_8009739C[];

s32 func_8005F2A0(s32 i) {
    return D_8009739C[i];
}

extern s32 D_80097368[];

s32 func_8005F2BC(s32 i) {
    return D_80097368[i];
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6650);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6658);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6660);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6670);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6674);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B667C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6684);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005F2D8);

extern char D_800B6690[];
char *func_8005F4E4(s16 n);
extern char *strcat(char *, char *);

void func_8005F3B0(char *name, s16 n) {
    char buf[128];

    strcpy(buf, func_8005F4E4(n));
    strcat(buf, D_800B6690);
    strcat(buf, name);
    delete(buf);
}

u8 func_8005F40C(u8 *p, s32 n) {
    u8 sum = 0;

    while (n--) {
        sum ^= *p++;
    }
    return sum;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005F440);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005F4E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6690);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005F604);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005FBB0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8005FD68);

typedef struct {
    s16 x, y, z;
    s16 pad6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
} Unk8006007C;

extern void func_8005FD68(void);

void func_8006007C(SVECTOR *pos) {
    struct Task *t = (struct Task *)func_8007307C(func_8005FD68, 0x10, 0x16);
    Unk8006007C *p;

    if (t != NULL) {
        p = (Unk8006007C *)t->vals;
        p->x = pos->vx;
        p->y = pos->vy;
        p->z = pos->vz;
        p->unkA = func_800754C8(8) + 16;
        p->unk8 = func_800754C8(8) - 4;
        p->unkC = func_800754C8(8) - 4;
        p->unk10 = 0;
        p->unk12 = func_800754C8(128) - 64;
        p->unk14 = 20;
    }
}

extern VECTOR D_801F6C7C;
extern SVECTOR D_800B6C98;
extern MATRIX D_801F9644;
extern Unk800B7398 *D_800B7398;
extern SVECTOR D_800B72E8;
extern MATRIX *func_8002702C(SVECTOR *r, MATRIX *m);
extern VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);

void func_80060130(SVECTOR *pos) {
    func_8002702C(&D_800B6C98, &D_801F9644);
    ApplyMatrix(&D_801F9644, &D_800B7398->unk38, &D_801F6C7C);
    D_800B72E8.vx = D_801F6C7C.vx + pos->vx;
    D_800B72E8.vy = D_801F6C7C.vy + pos->vy;
    D_800B72E8.vz = D_801F6C7C.vz + pos->vz;
    func_8006007C(&D_800B72E8);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800601E4);

typedef struct {
    SVECTOR unk0;
    SVECTOR unk8;
    SVECTOR unk10;
    SVECTOR unk18;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    void *unk28;
    struct Task *unk2C;
    s32 unk30;
    s32 unk34;
    struct Task *unk38;
    s32 unk3C;
} Unk80060AEC;

void func_800601E4();

void func_80060AEC(SVECTOR *pos, SVECTOR *vel, struct Task *owner, s32 arg3, s16 arg4, s16 arg5, struct Task *arg6) {
    struct Task *t = (struct Task *)func_8007307C(func_800601E4, 3, 0x40);
    Unk80060AEC *d;

    if (t != NULL) {
        d = (Unk80060AEC *)t->vals;
        if (owner != NULL) {
            void *v = owner->vals;

            d->unk2C = owner;
            d->unk28 = v;
            d->unk30 = owner->id;
        } else {
            d->unk28 = NULL;
        }
        d->unk38 = arg6;
        if (arg6 != NULL) {
            d->unk3C = arg6->id;
        }
        d->unk26 = arg5;
        if (arg5 != -1) {
            d->unk20 = 1;
        } else {
            d->unk20 = 0;
        }
        d->unk22 = (arg5 > 0) ? 100 : 0xFF;
        d->unk34 = arg3;
        d->unk24 = arg4;
        d->unk8.vx = pos->vx;
        d->unk8.vy = pos->vy;
        d->unk8.vz = pos->vz;
        d->unk18.vx = pos->vx;
        d->unk18.vy = pos->vy;
        d->unk18.vz = pos->vz;
        d->unk10.vx = vel->vx;
        d->unk10.vy = vel->vy;
        d->unk10.vz = vel->vz;
        d->unk0.vx = pos->vx;
        d->unk0.vy = pos->vy;
        d->unk0.vz = pos->vz;
        d->unk0.vx += d->unk10.vx * 8;
        d->unk0.vy += d->unk10.vy * 8;
        d->unk0.vz += d->unk10.vz * 8;
        d->unk8.vx -= d->unk10.vx * 3;
        d->unk8.vy -= d->unk10.vy * 3;
        d->unk8.vz -= d->unk10.vz * 3;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80060CFC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80061130);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80061314);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800618D0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80061A44);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80061F6C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0x9A];
    SVECTOR unkA0;
    u8 padA8[0xEA];
    s16 unk192;
    u8 pad194[0x58];
    s16 unk1EC;
} Unk800621F0;

extern s16 D_800B639E;
void func_80048B34(Unk800621F0 *p, s16 a, s16 b, s32 c, s32 d);
extern void func_8007345C(void);

void func_800620F8(void) {
    Unk800621F0 *p = (Unk800621F0 *)D_800B6DE0->vals;
    s16 n = D_800B639E;

    while (n--) {
        func_80048B34(p, p->unk1EC, p->unk1EC >> 1, 0x800, 1);
        p->unk0 += p->unkA0.vx;
        p->unk2 += p->unkA0.vy;
        p->unk4 += p->unkA0.vz;
        func_800589F4((Unk80058DC4 *)p, p->unk1EC / 2, 4);
        p->unk1EC += 0x20;
        p->unk192--;
    }
    if (p->unk192 < 0) {
        func_8007345C();
    }
}

extern SVECTOR D_800B66AC;
void func_800620F8(void);

void func_800621F0(Unk8002A35C *pos) {
    struct Task *t;
    Unk800621F0 *p;
    SVECTOR v;
    SVECTOR unused;
    SVECTOR out;

    t = func_8007307C(func_800620F8, 3, 0x1F0);
    v = D_800B66AC;
    if (t != NULL) {
        p = (Unk800621F0 *)t->vals;
        p->unk192 = 0x30;
        func_80024B8C(pos, (Unk8002A35C *)&D_800B6E00, (Unk8002A35C *)&out);
        func_80025004(&out, &v, (SVECTOR *)&D_800B67D0, &p->unkA0);
        p->unk0 = D_800B6E00.vx;
        p->unk2 = D_800B6E00.vy;
        p->unk4 = D_800B6E00.vz;
        p->unk1EC = 0x200;
    }
}

s32 func_800622D4(void) {
    if (D_800B6B70 == 1 && (D_8009B468[11] & *(volatile s32 *)D_800B7258)) {
        return -1;
    }
    if (D_800B6B70 == 4) {
        if (D_8009B468[15] & *(volatile s32 *)D_800B7258) {
            return -1;
        }
        if (D_8009B468[17] & *(volatile s32 *)D_800B7258) {
            return -1;
        }
        if (D_8009B468[11] & D_800B725C) {
            return -1;
        }
    }
    if (D_800B6B70 == 2) {
        if (D_8009B468[12] & *(volatile s32 *)D_800B7258) {
            return -1;
        }
        if (D_8009B468[13] & *(volatile s32 *)D_800B7258) {
            return -1;
        }
        if (D_8009B468[11] & D_800B725C) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80062400);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80062594);

typedef struct {
    u8 pad0[0x2C];
} Unk800628E4_Anim;

typedef struct {
    SVECTOR pos[6];
    SVECTOR unk30[6];
    SVECTOR rot[6];
    SVECTOR out[6];
    Unk800628E4_Anim anim[6];
    s16 unk1C8[6];
    s16 state[6];
    s16 unk1E0[6];
    s16 unk1EC;
    s16 unk1EE;
    u8 pad1F0[2];
    s16 unk1F2;
    s16 unk1F4[6];
} Unk800628E4;

extern SVECTOR D_800B66D4;
void func_80034DF4(void *anim, s16 arg);

void func_800628E4(Unk800628E4 *obj, s16 idx, s16 arg2) {
    SVECTOR v = D_800B66D4;

    obj->pos[idx].vx = idx * 500 - 750;
    obj->pos[idx].vy = 0;
    obj->pos[idx].vz = obj->unk1F2;
    obj->rot[idx].vx = 0;
    obj->rot[idx].vy = func_800754C8(0x1000);
    obj->rot[idx].vz = 0;
    obj->state[idx] = 0;
    obj->unk1C8[idx] = func_800754C8(0x800);
    obj->unk1E0[idx] = 0;
    func_80024F70(&obj->rot[idx], &v, &obj->pos[idx], &obj->out[idx]);
    func_80035384(&obj->anim[idx]);
    func_80034DF4(&obj->anim[idx], arg2);
    func_80035448(&obj->anim[idx], 14, func_800353DC(14), 0xA4, 8);
    obj->unk1F4[idx] = arg2;
}

typedef struct {
    u8 pad0[0x1EC];
    s16 unk1EC;
    s16 unk1EE;
    u8 pad1F0[2];
    s16 unk1F2;
} Unk8005EA78;
typedef struct {
    u8 pad[0x1C];
    Unk8005EA78 *data;
} Unk8005EA78_Task;

extern Unk8003BA6C_Task *func_8007307C(void (*fn)(), s16 flags, s16 size);
extern void func_80062594();
extern void func_800628E4();

s32 func_80062A3C(s16 a, s16 b) {
    Unk8005EA78_Task *task;
    Unk8005EA78 *obj;
    s16 i;
    s16 n;

    task = (Unk8005EA78_Task *)func_8007307C(func_80062594, 9, 0x200);
    i = 3;
    if (task != NULL) {
        obj = task->data;
        obj->unk1F2 = a;
        while (1) {
            func_800628E4(obj, i, b);
            n = i--;
            if (n == 0) break;
        }
        obj->unk1EE = 0;
        obj->unk1EC = 0;
        return (s32)obj;
    }
    return 0;
}

typedef struct {
    u8 pad0[0x1D4];
    s16 unk1D4[4];
} Unk80062AD8_Obj;

typedef struct {
    s32 unk0;
    Unk80062AD8_Obj *unk4[4];
} Unk80062AD8;

void func_80062AD8(void) {
    Unk80062AD8 *d = (Unk80062AD8 *)D_800B6DE0->vals;
    s16 i, j;

    i = 3;
    do {
        Unk80062AD8_Obj *o = d->unk4[i];
        j = 3;
        do {
            o->unk1D4[j] = 5;
        } while (j--);
    } while (i--);
}

typedef struct {
    s32 pad0;
    s32 objs[4];
} Unk80062B38;

void func_80062B38(s32 b) {
    Unk80062B38 *d = (Unk80062B38 *)D_800B6DE0->vals;
    s16 i = 3;

    do {
        d->objs[i] = func_80062A3C((s16)(i * 500 - 750), (s16)b);
    } while (i--);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80062BD0);

void func_80062D04(void) {
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80062D0C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80063004);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800631EC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B669C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66C4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66CC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66E0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66E4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66E8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66F4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66F8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B66FC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800634FC);

typedef struct {
    u8 c[4];
} Color4;

typedef struct {
    u8 pad0[0x2A];
    s16 unk2A;
    u8 pad2C[0x1E];
    s16 unk4A;
} Unk80063748;

extern Color4 D_800B66F4;
extern Color4 D_800B66F8;
extern s16 D_800B639E;

void func_80063748(Unk80063748 *p) {
    Color4 top = D_800B66F4;
    Color4 bottom = D_800B66F8;

    if (p->unk4A >= 0x30) {
        p->unk4A -= D_800B639E * 32;
        if (p->unk4A >= 0x30) {
            func_80076EF4(160, 127, p->unk2A, 0x300000 / p->unk4A, 0xAF000 / p->unk4A, top.c, bottom.c);
        }
    }
}

typedef struct {
    u8 pad0[0x38];
    char *value;
} Unk8006385C;

extern Color4 D_800B6704;
extern Color4 D_800B6708;
extern Color4 D_800B66E4;
extern Color4 D_800B66E8;
extern char D_800B6374[];
extern char *func_80078980(char *);
extern void func_80076478(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_8006385C(Unk8006385C *p) {
    Color4 top1 = D_800B6704;
    Color4 bottom1 = D_800B6708;
    Color4 top2 = D_800B66E4;
    Color4 bottom2 = D_800B66E8;

    func_80076478(80, 190, func_80078980(D_800B6374), 0xC00, 1280, top1.c, bottom1.c);
    func_80076EF4(240, 188, p->value, 0xC00, 1280, top2.c, bottom2.c);
}

typedef struct {
    u8 pad0[0x38];
    u32 unk38;
    u32 unk3C;
} Unk8005F880;

void func_80063954(Unk8005F880 *arg0) {
    if (arg0->unk38 != 0) {
        if (arg0->unk38 < arg0->unk3C) {
            func_8003D590(arg0->unk38);
            arg0->unk38 = 0;
        } else {
            func_8003D590(arg0->unk3C);
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

void func_800639C4(Unk8005F8F0 *obj) {
    obj->unk38 = obj->unk2A * obj->unk46;
    obj->unk3C = obj->unk38 >> 5;
    if (obj->unk3C == 0) {
        obj->unk3C = 1;
    }
}

extern char D_800939A0[];
extern u8 D_800B63E8[];
extern u8 D_800B63E0[];

void func_80063A00(void) {
    if (D_800B6CC8 & 8) {
        if (D_800B70E8 == 0x200) {
            func_80076478(256, 210, func_80078980(D_800939A0), 0x400, 300, D_800B63E8, D_800B63E0);
        } else {
            func_80076478(160, 210, func_80078980(D_800939A0), 0x200, 300, D_800B63E8, D_800B63E0);
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80063ACC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800642A4);

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80060168;
extern void func_8007345C(void);
extern void func_800642A4(u8 shade);

void func_80064394(void) {
    Unk80060168 *obj = (Unk80060168 *)D_800B6DE0->vals;

    func_800642A4(obj->unk32);
    obj->unk32 -= 0x20;
    if (obj->unk32 < 0) {
        func_8007345C();
    }
}

void func_80064394(void);

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk800643F0;

void func_800643F0(void) {
    struct Task *t = D_800B6DE0;

    ((Unk800643F0 *)t->vals)->unk32 = 0xFF;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_80064394;
    }
    func_80064394();
}

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk80064454;

extern s16 D_800B6D38;
extern void *D_800B7140;
extern u8 *D_800B70A8;
extern u32 *D_800B7018;
extern void SetTile(TILE *p);
extern void AddPrim(void *ot, void *p);
extern void func_8003DD54(void);

void func_80064454(void) {
    Unk80064454 *data = (Unk80064454 *)D_800B6DE0->vals;
    TILE *tile = D_800B7140;
    s16 w, h;

    if ((u8 *)tile - D_800B70A8 > 0xD7EF) {
        return;
    }
    data->unk32 = func_80025570(data->unk32, 0x1068, 0x100);
    w = func_80072734(0, D_800B70E8 / 2, data->unk32);
    h = func_80072734(0, D_800B71C8 / 2, data->unk32);
    tile->w = w * 2;
    tile->h = h * 2;
    tile->x0 = D_800B70E8 / 2 - w;
    tile->y0 = D_800B71C8 / 2 - h;
    SetTile(tile);
    tile->r0 = 0;
    tile->g0 = 0;
    tile->b0 = 0;
    AddPrim(D_800B7018, tile);
    D_800B7140 = tile + 1;
    if (data->unk32 == 0x1068) {
        D_800B6D38 = 2;
        func_8003DD54();
    }
}

void func_80064454(void);

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Unk800645A8;

void func_800645A8(void) {
    struct Task *t = D_800B6DE0;

    ((Unk800645A8 *)t->vals)->unk32 = 0;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_80064454;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800645F8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80064C6C);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 size[32];
    s16 rotA[32];
    s16 life[32];
    s16 velX[32];
    s16 velY[32];
    s16 velZ[32];
    s16 rotB[32];
    s16 spin[32];
    s16 unk208;
    s16 unk20A;
    s16 unk20C;
} Unk800651C8;

void func_80064C6C(void);

void func_800651C8(SVECTOR *pos) {
    struct Task *t = (struct Task *)func_8007307C(func_80064C6C, 3, 0x218);
    Unk800651C8 *d;
    s16 i = 3;

    if (t != NULL) {
        d = (Unk800651C8 *)t->vals;
        d->unk208 = 0;
        d->unk20C = 0x140;
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
        do {
            d->size[i] = func_800754C8(8) + 0x10;
            d->rotA[i] = func_800754C8(0x1000);
            d->rotB[i] = func_800754C8(0x1000);
            d->spin[i] = func_800754C8(0x40) - 0x20;
            d->life[i] = func_800754C8(3) + 4;
            d->velX[i] = func_800754C8(0x40) - 0x20;
            d->velY[i] = func_800754C8(0x40) + 0x30;
            d->velZ[i] = func_800754C8(2) + 1;
        } while (i--);
    }
}

extern SpuVoiceAttr D_801F6CB0;

void func_800652DC(void) {
    D_801F6CB0.volume.left = 0;
    D_801F6CB0.volume.right = 0;
    D_801F6CB0.mask = 3;
    D_801F6CB0.voice = 0xFFFFFF;
    SpuSetVoiceAttr(&D_801F6CB0);
}

extern SpuVolume D_801F9548[];

void func_80065328(void) {
    s16 i = 23;

    do {
        D_801F6CB0.volume.left = D_801F9548[i].left;
        D_801F6CB0.volume.right = D_801F9548[i].right;
        D_801F6CB0.mask = 3;
        D_801F6CB0.voice = 1 << i;
        SpuSetVoiceAttr(&D_801F6CB0);
    } while (i-- != 0);
}

void func_80066B70(Unk8015EB3C *arg0, s32 arg1);

void func_800653C4(s16 arg0, s16 arg1, s16 arg2) {
    s32 unused[2];

    D_8015EB3C.unk0 = arg2;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = arg1;
    D_8015EB3C.unk6 = func_800754C8(100) + 0x400;
    D_8015EB3C.unk8 = arg0;
    func_80066B70(&D_8015EB3C, 0);
}

void func_80065430(s16 arg0) {
    s32 unused[2];

    D_8015EB3C.unk0 = 0x800;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3FFF;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = arg0;
    func_80066B70(&D_8015EB3C, 0);
}

extern SpuVoiceAttr D_801F6CB0;
extern SpuVolume D_801F9548[];

void func_8006548C(s32 left, s32 right, s16 voice) {
    if (D_800B7370->unk178C != 0) {
        left = (left + right) >> 1;
        D_801F6CB0.volume.left = (left * D_800B7370->unk1786) >> 12;
        D_801F6CB0.volume.right = (left * D_800B7370->unk1786) >> 12;
    } else {
        D_801F6CB0.volume.left = (left * D_800B7370->unk1786) >> 12;
        D_801F6CB0.volume.right = (right * D_800B7370->unk1786) >> 12;
    }
    D_801F9548[voice].left = D_801F6CB0.volume.left;
    D_801F9548[voice].right = D_801F6CB0.volume.right;
}

void func_80065D58(s16 arg);

void func_80065564(void) {
    struct Task *t = D_800B6DE0;

    t->unk16 -= D_800B639E;
    if (t->unk16 < 0) {
        func_80065D58(t->unk14);
        func_8007345C();
    }
}

void func_80065C10(s16 arg);

void func_800655BC(void) {
    struct Task *t = D_800B6DE0;

    t->unk16 -= D_800B639E;
    if (t->unk16 < 0) {
        func_80065C10(t->unk14);
        func_8007345C();
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80065614);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006576C);

void func_800658EC(s16 id) {
    s32 unused[2];

    D_8015EB3C.unk0 = 0x800;
    D_8015EB3C.unk10 = func_800754C8(0x40) + 0x40;
    D_8015EB3C.unk2 = 5;
    D_8015EB3C.unk4 = 9000;
    D_8015EB3C.unk12 = 400;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk14 = -func_800754C8(3) - 3;
    D_8015EB3C.unk8 = id;
    func_80066B70(&D_8015EB3C, (s32)func_800669A0);
    D_8015EB3C.unk10 = -func_800754C8(0x40) - 0x40;
    D_8015EB3C.unk14 = -func_800754C8(3) - 3;
    D_8015EB3C.unk8 = id;
    func_80066B70(&D_8015EB3C, (s32)func_800669A0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800659E0);

extern s16 D_800973EC[][10];
void func_800666F0(s16 voice);

void func_80065B0C(s16 id) {
    s16 i;
    s16 v;

    for (i = 0; i < 10; i++) {
        v = D_800973EC[D_800B7430][i];
        if (v == -1) {
            break;
        }
        if (v == id) {
            func_80065D58(id);
            return;
        }
    }
    if ((s16)func_800754C8(2)) {
        D_8015EB3C.unk0 = 0;
    } else {
        D_8015EB3C.unk0 = 0x1000;
    }
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3FFF;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = id;
    func_80066B70(&D_8015EB3C, (s32)func_800666F0);
}

void func_80065614();

void func_80065C10(s16 id) {
    u8 unused[8];

    D_8015EB3C.unk0 = 0;
    D_8015EB3C.unk2 = 5;
    D_8015EB3C.unk4 = 0x3FFF;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = id;
    D_8015EB3C.unk20 = 200;
    func_80066B70(&D_8015EB3C, (s32)func_80065614);
    D_8015EB3C.unk0 = 0x1000;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3FFF;
    func_80066B70(&D_8015EB3C, (s32)func_80065614);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 padA;
    u32 state;
    u8 pad10[0x18];
    s32 unk28;
} Unk801D9DAC;

extern Unk801D9DAC D_801D9DAC[];
extern SpuVoiceAttr D_801F6CB0;
extern s16 D_800B7020;
void func_800663D0(s16 voice);

void func_80065CB0(s16 voice) {
    s16 status = SpuGetKeyStatus(1 << voice);
    Unk801D9DAC *p = &D_801D9DAC[voice];

    if (D_801D9DAC[voice].state >= 6 && (status == 0 || status == 3) && p->state >= 11) {
        D_800B7020 = 0;
        func_800663D0(voice);
    }
}

extern s16 D_800B6E40;
extern s16 D_800B6F88;
void func_800666F0(s16 voice);

void func_80065D58(s16 voice) {
    s32 unused[2];

    if (D_800B7020 == 0 && (D_800B6E40 == 0 || voice != D_800B6F88)) {
        D_800B6F88 = voice;
        D_800B6E40 = 300;
        D_8015EB3C.unk0 = 0;
        D_8015EB3C.unk2 = 5;
        D_8015EB3C.unk4 = 0x3FFF;
        D_8015EB3C.unk6 = 0x400;
        D_8015EB3C.unk8 = voice;
        func_80066B70(&D_8015EB3C, (s32)func_800666F0);
        D_8015EB3C.unk0 = 0x1000;
        D_8015EB3C.unk2 = 0;
        D_8015EB3C.unk4 = 0x3FFF;
        func_80066B70(&D_8015EB3C, (s32)func_80065CB0);
        D_800B7020 = -1;
    }
}

extern s16 D_800B6E92;

void func_80065E44(s16 id, void *pos) {
    u8 unused[8];
    s16 dist = func_80077398(pos, (Unk8002A35C *)&D_800B6E00);
    s32 ang = func_80025254((Unk8002A35C *)&D_800B6E00, pos);
    s16 pan = (D_800982E4[((u16)D_800B6E92 + ang) & 0xFFF] + 0x1000) >> 1;
    s16 vol = func_80072734(0x3FFF, 0x2710, dist / 2);

    if (vol < 0x400) {
        vol = 0x400;
    }
    D_8015EB3C.unk0 = pan;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = vol;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = id;
    func_80066B70(&D_8015EB3C, 0);
}

void func_80065F3C(s16 id, void *pos) {
    u8 unused[8];
    s16 dist = func_80077398(pos, (Unk8002A35C *)&D_800B6E00);
    s32 ang = func_80025254((Unk8002A35C *)&D_800B6E00, pos);
    s16 pan = (D_800982E4[((u16)D_800B6E92 + ang) & 0xFFF] + 0x1000) >> 1;
    s16 vol = func_80072734(0x3FFF, 0x2710, dist / 2);

    if (vol < 0x400) {
        vol = 0x400;
    }
    D_8015EB3C.unk0 = pan + func_800754C8(0x200) - 0x100;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = vol;
    D_8015EB3C.unk6 = func_800754C8(0x100) + 0x380;
    D_8015EB3C.unk8 = id;
    func_80066B70(&D_8015EB3C, 0);
}

void func_80066058(s16 id, void *pos) {
    u8 unused[8];
    s16 dist = func_80077398(pos, (Unk8002A35C *)&D_800B6E00);
    s32 ang = func_80025254((Unk8002A35C *)&D_800B6E00, pos);
    s16 pan = (D_800982E4[((u16)D_800B6E92 + ang) & 0xFFF] + 0x1000) >> 1;
    s16 vol = func_80072734(0xFFF, 0x1388, dist);

    if (vol >= 0) {
        D_8015EB3C.unk0 = pan;
        D_8015EB3C.unk2 = func_800754C8(0x800);
        D_8015EB3C.unk4 = vol;
        D_8015EB3C.unk6 = dist / 256 + 0x400;
        D_8015EB3C.unk8 = id;
        func_80066B70(&D_8015EB3C, 0);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80066168);

extern void func_8006548C(s32 left, s32 right, s16 voice);

void func_800663D0(s16 voice) {
    s32 bit;

    D_801D9DAC[voice].unk28 = 0;
    D_801D9DAC[voice].state = -1;
    func_8006548C(0, 0, voice);
    D_801F6CB0.mask = 3;
    bit = 1 << voice;
    D_801F6CB0.voice = bit;
    SpuSetVoiceAttr(&D_801F6CB0);
    SpuSetKey(0, bit);
}

extern s16 D_800B72A8;
extern s16 D_800B6C50;
extern u8 D_800B7228;
extern u32 D_800B6FA8;
extern SpuVolume D_801F9548[];
void SpuSetKey(long on_off, unsigned long voice_bit);
void SpuSetVoiceAttr(SpuVoiceAttr *arg);

void func_80066474(void) {
    SpuVoiceAttr attr;
    s16 i;

    D_800B72A8 = -1;
    D_800B6C50 = 0;
    D_800B6FA8 = 0;
    D_800B7228 = 0;
    D_800B6F88 = -1;
    D_800B6E40 = 0;
    i = 0x17;
    do {
        D_801D9DAC[i].state = -1;
        D_801D9DAC[i].unk28 = 0;
        D_801F9548[i].left = 0;
        D_801F9548[i].right = 0;
    } while (i--);
    D_800B7020 = 0;
    SpuSetKey(0, 0xFFFFFF);
    attr.mask = 0xFF93;
    attr.voice = 0xFFFFFF;
    attr.volume.left = 0x3FFF;
    attr.volume.right = 0x3FFF;
    attr.pitch = 0x1000;
    attr.a_mode = 1;
    attr.s_mode = 1;
    attr.r_mode = 3;
    attr.ar = 0;
    attr.dr = 0;
    attr.sr = 0;
    attr.rr = 0;
    attr.sl = 15;
    SpuSetVoiceAttr(&attr);
    D_800B72A8 = 0;
}

extern u32 D_800B6FA8;
void SpuSetKey(long on_off, unsigned long voice_bit);

void func_800665B4(void) {
    SpuSetKey(1, D_800B6FA8);
    D_800B6FA8 = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800665E4);

void func_800666F0(s16 voice) {
    s16 status = SpuGetKeyStatus(1 << voice);

    if (D_801D9DAC[voice].state >= 11 && (status == 0 || status == 3)) {
        func_800663D0(voice);
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 padA[0x1E];
} Unk80066770;

void func_80066770(s16 voice) {
    Unk80066770 s;
    Unk801D9DAC *e = &D_801D9DAC[voice];

    if (e->state == 8 && e->unk4 > 0x100) {
        s.unk0 = 0x1000 - e->unk0;
        s.unk2 = e->unk2;
        s.unk4 = e->unk4 >> 1;
        s.unk6 = e->unk6;
        s.unk8 = e->unk8;
        func_80066B70((Unk8015EB3C *)&s, (s32)func_80066770);
    } else if (e->state > 8) {
        func_800666F0(voice);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006684C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800669A0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80066B70);

void func_80066ECC(s32 vol, s32 pan) {
    SpuCommonAttr attr;
    s32 d = (vol * pan) >> 14;

    attr.mask = 0x3;
    attr.mvol.left = vol - d;
    attr.mvol.right = vol + d;
    SpuSetCommonAttr(&attr);
}

extern char D_801F95B0[];

void func_80066F18(void) {
    SpuVoiceAttr v;
    SpuCommonAttr c;
    SpuReverbAttr r;

    SpuInitMalloc(16, D_801F95B0);
    SpuSetTransferMode(0);
    c.mask = 0x3F3;
    c.mvol.left = 0x3FFF;
    c.mvol.right = 0x3FFF;
    c.mvolx.left = 0x3FFF;
    c.mvolx.right = 0x3FFF;
    c.cd.volume.left = func_80072734(0, 0x3FFF, D_800B7370->unk1784);
    c.cd.volume.right = func_80072734(0, 0x3FFF, D_800B7370->unk1784);
    c.cd.reverb = 0;
    c.cd.mix = 1;
    SpuSetCommonAttr(&c);
    SpuReserveReverbWorkArea(0);
    r.mode = 5;
    r.mask = 0x1F;
    SpuSetReverbModeParam(&r);
    r.depth.left = 4000;
    r.depth.right = 4000;
    r.mask = 6;
    SpuSetReverb(0);
    v.mask = 0xFF93;
    v.voice = 0xFFFFFF;
    v.volume.left = 0x3FFF;
    v.volume.right = 0x3FFF;
    v.pitch = 0x1000;
    v.a_mode = 1;
    v.s_mode = 1;
    v.r_mode = 3;
    v.ar = 0;
    v.dr = 0;
    v.sr = 0;
    v.rr = 0;
    v.sl = 15;
    SpuSetVoiceAttr(&v);
}

typedef struct {
    u8 pad0[8];
    s32 offset;
    u8 padC[0x2C];
} Unk8006704C_Entry;

typedef struct {
    s32 count;
    s32 size;
    Unk8006704C_Entry entries[1];
} Unk8006704C;

extern int printf(const char *fmt, ...);
extern char D_800889B8[];
extern s32 D_801F93B8[];

s32 func_8006704C(s32 base, Unk8006704C *bank) {
    s32 count = bank->count;
    Unk8006704C_Entry *e = bank->entries;
    u8 *data = (u8 *)(e + count);
    s32 addr = SpuMalloc(bank->size);
    s32 i;

    if (addr == -1) {
        printf(D_800889B8);
    } else {
        SpuSetTransferStartAddr(addr);
        SpuRead(data, bank->size);
        for (i = count - 1; i != -1; i--) {
            D_801F93B8[base++] = addr + e->offset;
            e++;
        }
    }
    return addr;
}

void func_80067138(void) {
    D_8015EB3C.unk0 = 0x800;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3000;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = 0x4C;
    func_80066B70(&D_8015EB3C, 0);
}

void func_80067194(void) {
    D_8015EB3C.unk0 = 0x800;
    D_8015EB3C.unk2 = 0;
    D_8015EB3C.unk4 = 0x3000;
    D_8015EB3C.unk6 = 0x400;
    D_8015EB3C.unk8 = func_800754C8(8) + 0x42;
    func_80066B70(&D_8015EB3C, 0);
}

extern s16 D_800B7418;
extern s16 D_800B741C;

s16 func_80067200(SVECTOR *pos) {
    s16 dx = pos->vx - D_800B7418;
    s16 dz = pos->vz - D_800B741C;
    s16 dist = SquareRoot0(dx * dx + dz * dz);

    if (dist > 3000) {
        dist = 3000;
    }
    return 0x1000 - dist;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80067298);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800673DC);

extern SVECTOR D_800B63D4;
typedef struct {
    u8 pad0[0x3E];
    s16 unk3E;
    u8 pad40[2];
    s16 unk42;
    s16 unk44;
} Unk800674E8;

extern SVECTOR D_800B72E8;
extern s16 D_800B7108;

void func_800674E8(void) {
    Unk800674E8 *p = (Unk800674E8 *)D_800B6DE0->vals;
    SVECTOR v;

    p->unk42 -= 0x20;
    if (p->unk42 < -0x1068) {
        func_8007345C();
        return;
    }
    D_800B72E8.vz = p->unk42;
    D_800B72E8.vy = 0;
    D_800B72E8.vx = 0;
    D_800B73F8.vx = 0;
    D_800B73F8.vz = 0;
    D_800B73F8.vy = p->unk44;
    func_80024F70(&D_800B73F8, &D_800B72E8, &D_800B63D4, &v);
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
    D_800B73F8.vy += 0x800;
    func_80034FD8(p, p->unk3E);
    func_80035A18(&v, &D_800B73F8, 0xFFF, 0, p);
    func_800676BC(&v, p->unk3E + 0x41, 0x400, D_800B7108, -1);
    func_8003580C(p);
}

typedef struct {
    u8 pad0[0x3E];
    s16 unk3E;
    u8 pad40[2];
    s16 unk42;
    s16 unk44;
} Unk8006762C;

void func_800674E8(void);
struct Task *func_80072F2C(void (*fn)(), s16 size);

void func_8006762C(s16 a, s16 b, s16 c) {
    struct Task *t = func_80072F2C(func_800674E8, 0x48);
    Unk8006762C *d;

    if (t != NULL) {
        d = (Unk8006762C *)t->vals;
        func_80035384(d);
        func_80035448(d, 7, 0, 0x52, 8);
        d->unk42 = b;
        d->unk44 = c;
        d->unk3E = a - 0x41;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800676BC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80067CF8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80067E08);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80068104);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006851C);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006861C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6704);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6708);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B670C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6710);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6714);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6718);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B671C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6720);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6724);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6728);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6730);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6738);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B673C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6740);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6744);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6748);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B674C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6750);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006871C);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Unk80069368;

extern SVECTOR D_800B63D4;

void func_80069368(void) {
    Unk80069368 *p = (Unk80069368 *)D_800B6DE0->vals;
    SVECTOR v;
    SVECTOR rot;

    v.vz = p->unk0;
    v.vy = 0;
    v.vx = 0;
    rot.vy = p->unk2;
    rot.vx = 0;
    rot.vz = 0;
    func_80024F70(&rot, &v, &D_800B63D4, (SVECTOR *)&D_800B7418);
    p->unk0 += p->unk4;
    p->unk2 += p->unk6;
    if (p->unkC-- < 0) {
        p->unkC = func_800754C8(0x20);
        p->unkA = func_800754C8(0x80) - 0x40;
        p->unk8 = func_800754C8(0x834);
    }
    p->unk6 = func_80025570(p->unk6, p->unkA, 1);
    if (p->unk0 < p->unk8) {
        p->unk4 = func_80025570(p->unk4, 0x40, 2);
    } else {
        p->unk4 = func_80025570(p->unk4, -0x40, 2);
    }
}

void func_80069368(void);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Unk80069474;

void func_80069474(void) {
    Unk80069474 *p = (Unk80069474 *)D_800B6DE0->vals;

    p->unk0 = 0;
    p->unk8 = 0x500;
    p->unk4 = 0;
    p->unk6 = 0x20;
    p->unkC = func_800754C8(0x20);
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80069368;
    }
}

extern s16 D_800B741A;

void func_800694F8(void) {
    D_800B7418 = 0;
    D_800B741A = 0;
    D_800B741C = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80069518);

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

s16 func_80069864(ScoreTable *t, u32 score, char *name) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800699F4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80069DC4);

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0xE];
} Unk80096104;

extern Unk80096104 D_80096104[];

typedef struct {
    u8 pad0[0x1A8];
    Anim anim;
    u8 pad1C8[0xC];
    s16 unk1D4;
    u8 pad1D6[2];
    s16 unk1D8;
} Unk8006A1CC;

void func_8006A1CC(Unk8006A1CC *p) {
    s16 r = func_800754C8(0x57);

    func_8003553C(&p->anim, D_80096104[r].unk0, 0, 0x52, 0x10);
    func_8004FBEC((Unk8004FBEC *)p, D_80096104[r - 1].unk2);
    p->unk1D4 = 0;
    p->unk1D8 = 0;
}

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
    u8 pad3C[0x16C];
    Anim anim;
    u8 pad1C8[0x38];
    s32 unk200;
} Unk8006A268;

void func_8006A268(Unk80061844 *obj) {
    Unk8006A268 *p = (Unk8006A268 *)obj;

    D_800B72E8.vx = 0;
    D_800B72E8.vz = 0;
    D_800B72E8.vy = func_800754C8(0x1000);
    D_800B73F8.vx = 0;
    D_800B73F8.vz = 0xAF0;
    D_800B73F8.vy = 0;
    func_80024F70(&D_800B72E8, &D_800B73F8, &D_800B63D4, (SVECTOR *)p);
    p->rot.vx = 0;
    p->rot.vz = 0;
    p->rot.vy = D_800B72E8.vy + 0x800;
    p->unk200 = 0;
    func_80035384(&p->anim);
    func_80035448(&p->anim, D_80096104[0].unk0, 0, 0x52, 0x10);
    func_80034DF4(&p->anim, (s16)func_800754C8(20));
    func_8006A1CC(p);
}

void func_8006A1CC();

void func_8006A350(void) {
    Unk80054100 *p = (Unk80054100 *)D_800B6DE0->vals;
    s16 scale = 0x1000;
    s16 d = func_80077398((Unk8002A35C *)p, (Unk8002A35C *)&D_800B63D4);

    if (d > 0x9F0) {
        scale = 0x1000 - (d - 0x9F0) * 16;
        if (scale < 0) {
            scale = 0;
        }
    }
    func_80035A18(p, p->unk34, scale, 0, p->unk1A8);
    func_80053404(p);
    if ((s16)func_8003580C(p->unk1A8)) {
        func_8006A1CC(p);
    }
    if (d > 0xAF1) {
        func_8006A268(p);
    }
}

extern Unk8003BA6C_Task *func_8007307C(void (*fn)(), s16 flags, s16 size);
extern void func_8006A268(Unk80061844 *obj);
extern void func_8006A350(void);

void func_8006A434(void) {
    Unk8003BA6C_Task *task;

    task = func_8007307C(func_8006A350, 3, 0x2a0);
    if (task != NULL) {
        func_8006A268((Unk80061844 *)task->data);
    }
}

extern s16 D_800B7238;
extern s16 D_800B73C8;
extern s16 D_800B6AA0;
void func_8003DE20(void);
void func_80069DC4(void);

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
} Unk8006A474;

void func_8006A474(void) {
    Unk8006A474 *p = (Unk8006A474 *)D_800B6DE0->vals;

    D_800B73C8 = 7;
    D_800B6AA0 = 2;
    p->unk4 = 0x1000;
    p->unkA = 30;
    p->unk6 = 0x5D0;
    p->unkC = 0;
    p->unk14 = 300;
    p->unk10 = 6;
    p->unk12 = 30;
    if (D_800B7238 == 2) {
        func_8003DE20();
    }
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_80069DC4;
    }
    func_80069DC4();
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006A538);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006AC48);

extern Unk800B6F00 *D_800B6F00;

void func_8006AF40(void) {
    D_800B6F00->unk10 = D_800B6F00->unk10 == 0;
}

void func_8006AF60(void) {
    D_800B6F00->unk0 ^= 1;
}

void func_8006AF80(void) {
    D_800B6F00->unk2 ^= 1;
}

void func_8006AFA0(void) {
    D_800B6F00->unkC = D_800B6F00->unkC == 0;
}

void func_8006AFC0(void) {
    D_800B6F00->unkE = D_800B6F00->unkE == 0;
}

void func_8006AFE0(void) {
    D_800B6CC0 = 99;
    D_800B6E58 = 99;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006AFFC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006B040);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006B2C4);

typedef struct {
    u8 pad0[0x60];
    SVECTOR pos;
    u8 pad68[4];
    s32 unk6C[12];
    s16 unk9C[12];
    s16 unkB4[12];
    s16 unkCC[12];
    s16 unkE4[12];
    s16 unkFC[12];
    s16 unk114[12];
    s16 unk12C[12];
    s16 unk144[12];
    s16 unk15C;
    s16 unk15E;
    s16 unk160;
    s16 unk162;
    s16 unk164;
} Unk8006B800;

void func_8006B2C4(void);

void func_8006B800(SVECTOR *pos) {
    Unk8003BA6C_Task *t = func_8007307C(func_8006B2C4, 3, 0x168);
    Unk8006B800 *d;
    s16 i;
    s16 r;
    s32 j;
    s32 x;

    if (t != NULL) {
        d = (Unk8006B800 *)t->data;
        d->pos.vx = pos->vx;
        d->pos.vy = pos->vy;
        d->pos.vz = pos->vz;
        i = 11;
        do {
            r = func_800754C8(0x1000);
            x = func_80072734(0x32, 0x32, r);
            j = i;
            d->unk6C[j] = x;
            d->unk114[j] = func_80072734(2, 2, r);
            d->unkFC[j] = func_80072734(6, 10, r);
            d->unk9C[j] = j * 341;
            d->unkCC[j] = 0xF0;
            d->unkB4[j] = 0x80;
            d->unk12C[j] = func_800754C8(0x1000);
            d->unk144[j] = func_800754C8(10) + 10;
            d->unk15C = 9;
            d->unk162 = 0x1E;
            d->unk164 = 2;
        } while (i--);
    }
}

void func_8006B95C(SVECTOR *pos) {
    Unk8003BA6C_Task *t = func_8007307C(func_8006B2C4, 3, 0x168);
    Unk8006B800 *d;
    s16 i;
    s16 r;
    s32 j;
    s32 x;

    if (t != NULL) {
        d = (Unk8006B800 *)t->data;
        func_800658EC(0x3E);
        d->pos.vx = pos->vx;
        d->pos.vy = pos->vy;
        d->pos.vz = pos->vz;
        i = 11;
        do {
            r = func_800754C8(0x1000);
            x = func_80072734(6, 8, r);
            j = i;
            d->unk114[j] = x;
            d->unk164 = 6;
            d->unk6C[j] = func_80072734(0x28, 0x28, r);
            d->unkFC[j] = func_80072734(0xF, 0x1E, r);
            d->unk9C[j] = j * 341;
            d->unkCC[j] = 0xF0;
            d->unkB4[j] = 0x80;
            d->unk12C[j] = func_800754C8(0x1000);
            d->unk144[j] = func_800754C8(10) + 10;
            d->unk15C = 7;
            d->unk162 = 0x28;
        } while (i--);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006BAC0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006BC98);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} Unk8006C1B4;

typedef struct {
    u8 pad0[0x378];
    s16 unk378;
    s16 unk37A;
} Unk8006C1B4Src;

void func_8006BC98(void);

void func_8006C1B4(void) {
    Unk8006C1B4Src *src = (Unk8006C1B4Src *)D_801F7548->vals;
    struct Task *t;
    Unk8006C1B4 *p;

    if (D_801F7548 != NULL) {
        t = func_8007307C(func_8006BC98, 0x10, 0xA);
        if (t != NULL) {
            p = (Unk8006C1B4 *)t->vals;
            p->unk0 = 0;
            p->unk2 = 0x80;
            p->unk4 = 0;
            p->unk6 = src->unk378;
            p->unk8 = src->unk37A;
            if (p->unk6 > D_800B70E8 || p->unk6 < 0 || p->unk8 < 0 || p->unk8 > D_800B71C8) {
                p->unk6 = D_800B70E8 >> 1;
                p->unk8 = D_800B71C8 >> 1;
            }
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006C298);

extern volatile s32 D_800B6FE8[];
extern s16 D_800B6DC8;
extern u16 D_8009B468[];

void func_8006C3DC(void) {
    if ((D_8009B468[1] & D_800B6FE8[D_800B6DC8]) || (D_8009B468[4] & D_800B6FE8[D_800B6DC8])) {
        func_80067138();
        D_800B7370->unk1780++;
    }
    if (D_8009B468[0] & D_800B6FE8[D_800B6DC8]) {
        func_80067138();
        D_800B7370->unk1780--;
    }
    D_800B7370->unk1780 &= 7;
}

extern s16 D_800B6AA0;
extern s16 D_800B6CB8;
extern s16 D_800B6CB0;
extern s32 D_800B6D08;
void func_8004D264(void);

void func_8006C4D8(void) {
    D_800B6AA0 = 3;
    D_800B6CB8 = 1;
    func_8004D264();
    D_800B6CB0 = 5;
    D_800B7260 = 0;
    D_800B6A6C = 0;
    D_800B6C48 = 0;
    D_800B6D08 = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006C53C);

extern s16 D_800B6AA0;

void func_8006C638(s32 arg0, s32 arg1) {
    D_800B6AA0 = 9;
}

typedef struct {
    u8 pad0[0x20];
    s16 unk20[7];
    s16 unk2E[7];
    s16 unk3C;
    s16 pad3E;
    s16 unk40;
    s16 pad42;
    s16 unk44;
} Unk8006C64C;

void func_8006C64C(Unk8006C64C *p) {
    s16 i;

    p->unk44 = 0;
    i = 4;
    do {
        p->unk2E[i] = 0;
        p->unk20[i] = 0x1000;
    } while (i--);
    p->unk3C = 0;
    p->unk2E[0] = 2;
    p->unk40 = 0;
}

typedef struct {
    u8 pad0[0x1C];
    u8 *unk1C;
} Unk8006C690;

extern u8 D_800975DC[];

void func_8006C690(Unk8006C690 *obj) {
    D_800B6F00->unk0 = 0;
    obj->unk1C = D_800975DC;
    func_8006C64C(obj);
}

typedef struct {
    u8 pad0[0x3E];
    s16 unk3E;
} Unk8006C714;

extern s16 D_800B6CE0;

void func_8006C6C4(Unk8006C714 *obj) {
    obj->unk3E = 0;
    D_800B6CE0 = -1;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006C6DC);

void func_8006C714(Unk8006C714 *obj) {
    obj->unk3E = 0;
}

void func_8006C71C(Unk8006C714 *obj) {
    D_800B6AA0 = 2;
    obj->unk3E = 0;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006C730);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006C8E4);

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

void func_8006C9F4(s16 t, s32 y) {
    POLY_G4 *p = D_800B7140;
    POLY_G4 *prim = p;
    s16 c;
    SVECTOR unused;

    if ((u8 *)p - D_800B70A8 > 0xD7B7) {
        return;
    }
    p->x0 = p->x2 = 0x128;
    p->x1 = p->x3 = 0x1B4;
    p->y0 = p->y1 = y - 8;
    p->y2 = p->y3 = y + 8;
    func_8006C8E4(&p->r0, &p->r2, t);
    func_8006C8E4(&p->r1, &p->r3, t);
    SetPolyG4(p);
    p++;
    AddPrim(D_800B7018 + 2, prim);
    p->x0 = p->x2 = func_80072734(0x128, 0x1A0, t);
    p->x1 = p->x3 = func_80072734(0x12C, 0x1B4, t);
    p->y0 = p->y1 = y - 9;
    p->y2 = p->y3 = y + 9;
    c = func_80072734(0x78, 0xFF, t);
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
    AddPrim(D_800B7018 + 1, p++);
    D_800B7140 = p;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006CB88);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006CD80);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006D640);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006D80C);

extern char D_8009361C[];
extern char D_8009380C[];
extern u8 D_800B63F0[];
extern s32 D_800B6D64;
s16 func_8006DE18(void);
void func_8006D80C(void *p, s32 a, s32 b, s32 c);
void func_8006CD80(void *p, s32 a);

void func_8006DC08(void) {
    void *p = D_800B6DE0->vals;

    if (D_800B6AA0 != 9) {
        func_800665B4();
        D_800B6DC8 = func_8006DE18();
        func_80076478(0xA0, 0x4B, func_80078980(D_8009361C), 0xA28, 0x800, D_800B63F0, D_800B63E8);
        func_80076478(0xA0, 0x87, func_80078980(D_8009380C), 0xC80, 0x400, D_800B63E8, D_800B63F0);
        func_8006D80C(p, 0, 0, 0);
        func_8006CD80(p, 0);
        if (*(volatile s32 *)&D_800B6D60 != 0 || D_800B6D64 != 0) {
            D_800B7370->unk178E = 0;
        }
    }
}

extern u8 D_80097ABC[];
extern u8 D_80097A20[];
void func_8003D824(void);
void func_8006DC08(void);

typedef struct {
    u8 pad0[0x1C];
    u8 *unk1C;
    u8 pad20[0x2A];
    s16 unk4A;
} Unk8006DD40;

void func_8006DD40(void) {
    Unk8006DD40 *p = (Unk8006DD40 *)D_800B6DE0->vals;

    func_8003D824();
    func_80066474();
    if (D_800B7370->maps[D_800B7370->unk1780][0xE] != 0) {
        p->unk1C = D_80097ABC;
    } else {
        p->unk1C = D_80097A20;
    }
    p->unk4A = 1;
    func_8006C64C(p);
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8006DC08;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006DE18);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006DF98);

extern u8 D_800975DC[];
extern u8 D_800977B0[];
extern u8 D_80097678[];
extern u8 D_80097714[];
extern u8 D_8009784C[];
extern u8 D_800978E8[];
extern u8 D_80097984[];
extern u8 *D_800BDA74[7];
extern s16 D_800B71A0;
extern s16 D_800B7428;
void func_8006DF98(void);

typedef struct {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x28];
    s16 unk42;
} Unk8006E740;

void func_8006E740(void) {
    struct Task *t = D_800B6DE0;
    Unk8006E740 *p;

    t->unk28 = 0xFF;
    p = (Unk8006E740 *)t->vals;
    D_800B6DE0->unk29 = 0;
    D_800B6DE0->unk2A = 0;
    p->unk18 = -1;
    p->unk42 = 0;
    D_800BDA74[0] = D_800975DC;
    D_800BDA74[1] = D_800977B0;
    D_800BDA74[2] = D_80097678;
    D_800BDA74[3] = D_80097714;
    D_800BDA74[4] = D_8009784C;
    D_800BDA74[5] = D_800978E8;
    D_800BDA74[6] = D_80097984;
    D_800B71A0 = 0;
    D_800B7428 = 0;
    if (D_800B6DE0->func == D_800B7350) {
        TRAP();
    } else {
        D_800B6DE0->func = func_8006DF98;
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
    u8 padE[2];
    s16 unk10;
    char unk12[0x20];
    s16 unk32;
} Unk8006E838;

extern u8 D_800B6400[];
extern u8 D_800B63E8[];

void func_8006E838(void) {
    Unk8006E838 *p = (Unk8006E838 *)D_800B6DE0->vals;
    SVECTOR v;

    if (p->unkC != 0) {
        p->unkC--;
        return;
    }
    v.vx = func_80072734(p->unk0, p->unk4, p->unkA);
    v.vy = func_80072734(p->unk2, p->unk6, p->unkA);
    func_80076478(v.vx, v.vy, p->unk12, 4000, p->unk10, D_800B6400, D_800B63E8);
    p->unkA -= p->unk8;
    if (p->unkA <= 0) {
        p->unkA = 0;
        if (--p->unk32 < 0 || (D_8009B468[4] & D_800B6FE8[D_800B6DC8])) {
            func_8007345C();
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006E960);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006EBA0);

typedef struct {
    s16 unk0[16];
    s16 unk20[16];
    s16 unk40[16];
    s16 unk60[16];
    s16 unk80[16];
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
} Unk8006F110;

typedef struct {
    u8 pad0[0x18A];
    s16 unk18A;
    s16 unk18C;
    s16 unk18E;
    s16 unk190;
} Unk8006F110_Vals;

struct Task *func_800731DC(void (*fn)(), s16 size);
void func_8006EBA0();

void func_8006F110(s16 arg0) {
    Unk8006F110_Vals *v = (Unk8006F110_Vals *)D_801F7544->vals;
    struct Task *t;
    Unk8006F110 *d;
    s16 i;
    s32 j;

    if (D_801F7544 != NULL) {
        t = func_800731DC(func_8006EBA0, 0xA8);
        if (t != NULL) {
            D_800B6AA0 = 8;
            d = (Unk8006F110 *)t->vals;
            i = 15;
            do {
                d->unk20[i] = 0;
                d->unk60[i] = func_800754C8(5) + 2;
                d->unk40[i] = 0;
                d->unk80[i] = func_800754C8(8) + 8;
            } while (i--);
            i = 15;
            do {
                j = i;
                d->unk0[j] = j << 8;
            } while (i--);
            d->unkA4 = 0x1000;
            d->unkA6 = 0x10;
            d->unkA0 = func_800754C8(0x1000);
            d->unkA2 = arg0;
            v->unk18A = 0x60;
            v->unk18E = 0x30;
            if ((s16)func_800754C8(2) != 0) {
                v->unk18E = -0x30;
            }
            v->unk18C = 0;
            v->unk190 = -1;
        }
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006F258);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006F9B0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006FD28);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8006FDB8);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800702F0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800705A0);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800707D8);

void func_800707D8(void);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0x82];
    s16 unk88;
    u8 pad8A[0x20];
    s16 unkAA;
    s16 unkAC;
    s16 padAE;
    s32 unkB0;
    u8 padB4[0x48];
    s16 unkFC;
} Unk80070C08;

void func_80070C08(void) {
    struct Task *t = D_800B6DE0;
    Unk80070C08 *p = (Unk80070C08 *)t->vals;

    p->unk88 = 0;
    p->unkAA = 0;
    p->unkAC = 0;
    p->unkB0 = -1;
    p->unkFC = 0;
    p->unk0 = D_800B6E00.vx;
    p->unk2 = D_800B6E00.vy;
    p->unk4 = D_800B6E00.vz;
    if (t->func == D_800B7350) {
        TRAP();
    } else {
        t->func = func_800707D8;
    }
}

extern u8 D_80169FD0[];

void func_80070C98(void) {
    u8 *src = D_800B7370->maps[D_800B7370->unk1780];
    u8 *dst = D_80169FD0;
    s16 i = 0x2EF;

    do {
        dst[i] = src[i];
    } while (i-- != 0);
}

extern u8 D_80169FDC;
extern u8 D_80169FDD;
extern u8 D_80169FDE;
extern s16 D_80169FE2;
extern s16 D_80169FE4;
extern s16 D_800B6CB0;
extern s32 D_800B6A6C;

void func_80070CFC(void) {
    func_80070C98();
    D_80169FDD = D_800B6CB0;
    D_80169FE2 = D_800B6A6C;
    D_80169FE4 = D_800B6A6C >> 16;
    D_80169FDE = D_800B7430;
    D_80169FDC = D_800B7430 * 100 / 8;
}

extern u8 D_80169FD0[];

void func_80070D90(void) {
    u8 *src = D_80169FD0;
    u8 *dst = (u8 *)D_800B7370 + D_800B7370->unk1780 * 0x2F0;
    s16 i;

    i = 0x2EF;
    do {
        dst[i] = src[i];
    } while (i--);
    D_800B6F00 = (Unk800B6F00 *)((u8 *)D_800B7370 + D_800B7370->unk1780 * 0x2F0 + 0x2B0);
}

u8 func_80070E2C(u8 *data, s32 len) {
    s32 sum = 5;

    while (len != 0) {
        sum = sum + *data++ + 1;
        len--;
    }
    return sum;
}

u8 func_80070E2C(u8 *data, s32 len);

s32 func_80070E54(u8 *data, s32 len, u8 *out) {
    s32 n = 0;

    while (len > 0x400) {
        out[n++] = func_80070E2C(data, 0x400);
        len -= 0x400;
        data += 0x400;
    }
    if (len != 0) {
        out[n++] = func_80070E2C(data, len);
    }
    return n;
}

extern long D_800B6A10;
extern long D_800B6A18;
extern long D_800B6A20;
extern long D_800B6A28;
extern long EnableEvent(long event);
extern long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
extern void StartCARD(void);
extern void StopPAD(void);
extern void _bu_init(void);
extern void _card_auto(long val);
extern void func_8007FD1C(void);
extern void func_8007FFB4(void);

void func_80070EF4(void) {
    StopPAD();
    StartCARD();
    _bu_init();
    func_8007FD1C();
    D_800B6A10 = OpenEvent(0xF4000001, 0x0004, 0x2000, NULL);
    D_800B6A18 = OpenEvent(0xF4000001, 0x8000, 0x2000, NULL);
    D_800B6A20 = OpenEvent(0xF4000001, 0x0100, 0x2000, NULL);
    D_800B6A28 = OpenEvent(0xF4000001, 0x2000, 0x2000, NULL);
    func_8007FFB4();
    EnableEvent(D_800B6A10);
    EnableEvent(D_800B6A18);
    EnableEvent(D_800B6A20);
    EnableEvent(D_800B6A28);
    _card_auto(0);
}

extern long TestEvent(long event);
extern long _card_info(long chan);

long func_80070FFC(s16 chan) {
    s32 i = 0;

    if (_card_info(chan) != 0) {
        for (; i < 120; i++) {
            if (TestEvent(D_800B6A10) == 1) {
                return -1;
            }
            if (TestEvent(D_800B6A18) == 1) {
                return 0;
            }
            if (TestEvent(D_800B6A20) == 1) {
                return 0;
            }
            if (TestEvent(D_800B6A28) == 1) {
                return -1;
            }
            VSync(0);
        }
    }
    return 0;
}

extern void StopCARD(void);
extern void StartPAD(void);
extern long CloseEvent(long event);

void func_800710B4(void) {
    StopCARD();
    func_8007FD1C();
    CloseEvent(D_800B6A10);
    CloseEvent(D_800B6A18);
    CloseEvent(D_800B6A20);
    CloseEvent(D_800B6A28);
    func_8007FFB4();
    StartPAD();
}

extern char D_800B7818[];
extern char D_800889D0[];
int sprintf(char *buf, const char *fmt, ...);
int delete(char *name);

void func_8007112C(s32 arg0, s32 arg1) {
    sprintf(D_800B7818, D_800889D0, arg1, arg0);
    delete(D_800B7818);
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

extern McHeader D_800B74F8;
extern McData D_800B76F8;
extern McTitle D_80097DC4;
extern McClut D_80097DA4;
extern McIcon D_80097C24;
extern McIcon D_80097CA4;
extern McIcon D_80097D24;
extern s32 open(char *name, s32 mode);
extern s32 close(s32 fd);
extern s32 write(s32 fd, void *buf, s32 n);
s32 func_80070E54(u8 *data, s32 len, u8 *out);

s32 func_80071174(s32 arg0, u8 *data, s32 size, s32 arg3) {
    s32 n;
    s32 fd;

    D_800B74F8.id0 = 'S';
    D_800B74F8.id1 = 'C';
    if (D_800B7370->unk178A != 0) {
        D_800B74F8.type = 0x13;
    } else {
        D_800B74F8.type = 0x11;
    }
    D_800B74F8.title = D_80097DC4;
    D_800B74F8.clut = D_80097DA4;
    D_800B74F8.icon[0] = D_80097C24;
    D_800B74F8.icon[1] = D_80097CA4;
    D_800B74F8.icon[2] = D_80097D24;
    n = size + 0x300;
    n = n / 0x2000 * 0x2000 + ((n & 0x1FFF) ? 0x2000 : 0);
    D_800B74F8.blocks = n / 0x2000 + ((n & 0x1FFF) != 0);
    D_800B76F8.size = size;
    func_80070E54(data, size, D_800B76F8.sum);
    sprintf(D_800B7818, D_800889D0, arg3, arg0);
    fd = open(D_800B7818, 2);
    if (fd >= 0) {
        close(fd);
        return 0;
    }
    fd = open(D_800B7818, (D_800B74F8.blocks << 16) | 0x200);
    if (fd == -1) {
        return 0;
    }
    close(fd);
    fd = open(D_800B7818, 2);
    if (fd == -1) {
        return 0;
    }
    if (write(fd, &D_800B74F8, 0x200) == 0x200 && write(fd, &D_800B76F8, 0x100) == 0x100 && write(fd, data, size) == size) {
        close(fd);
        return -1;
    }
    close(fd);
    delete(D_800B7818);
    return 0;
}

extern s16 D_800B6EB8;
extern s16 D_800B7170;
extern void func_800717CC(s32, s16);

void func_80071680(s32 arg0) {
    D_800B6EB8 = -1;
    func_800717CC(arg0, D_800B7170);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800716B4);

extern char *func_800716B4(s16 arg0);
extern s32 read(s32 fd, void *buf, s32 n);

s32 func_800716D8(s16 slot) {
    char *name;
    s32 fd;

    if (slot == 0) {
        name = func_800716B4(0);
    } else {
        name = func_800716B4(1);
    }
    fd = open(name, 1);
    if (fd == -1) {
        close(fd);
        return 0;
    }
    if (read(fd, &D_800B74F8, 0x200) != 0x200) {
        close(fd);
        return 0;
    }
    close(fd);
    return -1;
}

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
} Unk80071778;

extern u8 D_80097F3C[];
extern s16 D_800B70B8;
void func_80070D90(void);
void func_8006C64C();
void func_8001EA84(void);
void func_8003DDA0(void);

void func_80071778(Unk80071778 *obj) {
    func_80070D90();
    obj->unk1C = (s32)D_80097F3C;
    func_8006C64C(obj);
    func_8001EA84();
    D_800B70B8 = 1;
    func_8003DDA0();
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800717CC);

extern void func_80071A08(s32, s32);

void func_800719E0(s32 arg0, s16 arg1) {
    D_800B7170 = arg1;
    func_80071A08(arg0, 0);
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6760);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6768);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B676C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6770);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6774);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80071A08);

extern long CloseEvent(long event);
extern long D_800B6A30;
extern long D_800B6A38;
extern long D_800B6A40;
extern long D_800B6A48;
extern long _card_read(long chan, long block, unsigned char *buf);

long func_80071B54(s16 chan) {
    unsigned char buf[128];
    s32 i = 180;

    func_8007FD1C();
    D_800B6A30 = OpenEvent(0xF0000011, 0x0004, 0x2000, NULL);
    D_800B6A38 = OpenEvent(0xF0000011, 0x8000, 0x2000, NULL);
    D_800B6A40 = OpenEvent(0xF0000011, 0x0100, 0x2000, NULL);
    D_800B6A48 = OpenEvent(0xF0000011, 0x2000, 0x2000, NULL);
    func_8007FFB4();
    EnableEvent(D_800B6A30);
    EnableEvent(D_800B6A38);
    EnableEvent(D_800B6A40);
    EnableEvent(D_800B6A48);
    buf[0] = 0;
    _card_read(chan, 0, buf);
    while (i--) {
        VSync(0);
    }
    if (_card_info(chan) != 0) {
        for (; i < 600; i++) {
            if (TestEvent(D_800B6A30) == 1) {
                break;
            }
            if (TestEvent(D_800B6A38) == 1) {
                break;
            }
            if (TestEvent(D_800B6A40) == 1) {
                break;
            }
            if (TestEvent(D_800B6A48) == 1) {
                break;
            }
            VSync(0);
        }
    }
    CloseEvent(D_800B6A30);
    CloseEvent(D_800B6A38);
    CloseEvent(D_800B6A40);
    CloseEvent(D_800B6A48);
    if (buf[0] != 'M' || buf[1] != 'C') {
        return 0;
    }
    return -1;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80071D74);

typedef struct {
    s16 x, y, w, h;
} RECT;

extern s32 DrawSync(s32 mode);
extern void StoreImage(RECT *rect, u32 *p);
extern RECT D_800B678C;
extern RECT D_800B6794;
extern s32 *D_800B7088;
extern s32 D_800B6A80;
extern s32 D_800B6BA8;
extern s32 func_80077CE0(s32 *buf, u32 size);

s32 func_80071E20(void) {
    RECT rect = D_800B678C;
    RECT unused = D_800B6794;
    s32 ret;

    DrawSync(0);
    StoreImage(&rect, (u32 *)D_800B7088);
    DrawSync(0);
    D_800B6BA8 = func_80077CE0(D_800B7088, 0x28000);
    if (D_800B6BA8 == D_800B6A80) {
        D_800B7088 = 0;
        ret = -1;
    } else {
        D_800B7088 = 0;
        ret = 0;
    }
    return ret;
}

void func_80071EEC(void) {
    SpuCommonAttr attr;

    attr.cd.volume.left = 0x3FFF;
    attr.cd.volume.right = 0x3FFF;
    attr.mask = 0xC0;
    SpuSetCommonAttr(&attr);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80071F20);

extern s16 D_800B6D38;
void func_80031B9C(void);
void func_8006DD40(void);

void func_80071FDC(void) {
    D_800B6D38 = 0;
    D_800B6AA0 = 2;
    func_80031B9C();
    D_800B6DE0->unk14 = 0;
    DrawSync(0);
    func_80078430(2, D_800BDB04);
    func_80072F2C(func_8006DD40, 0x4C);
}

extern s16 D_800B6D38;
extern s16 D_800B6AA0;
extern s32 D_800BDB04[];
void func_80071F20(void);
void func_80078430(s16 id, u32 *buf);

void func_80072044(void) {
    func_80071F20();
    D_800B6D38 = 0;
    D_800B6AA0 = 2;
    D_800B6DE0->unk14 = 0;
    func_80078430(4, D_800BDB04);
}

void func_80072094(void) {
    func_80071F20();
    D_800B6D38 = 0;
    D_800B6AA0 = 2;
    D_800B6DE0->unk14 = 0;
    func_80078430(3, D_800BDB04);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800720E4);

extern char D_800939D8[];
extern u16 D_8009B47E;
extern u16 D_8009B470;
extern s16 D_800B73D8;
extern s16 D_800B72A0;
extern void func_80024124(void);

void func_80072484(void) {
    RECT unused = D_800B678C;

    func_800246A8(0x140);
    func_8002370C();
    func_80076478(0xA0, 0x78, func_80078980(D_800939D8), 0x800, 0x400, D_800B63E8, D_800B63F0);
    if ((D_8009B47E & ((volatile s32 *)D_800B7258)[0]) || (D_8009B470 & ((volatile s32 *)D_800B7258)[0])) {
        D_800B6CB8 = 1;
    }
    if (D_800B72E0 == 0) {
        if (D_800B7088 != NULL && (s16)func_80071E20() == 0) {
            D_800B7430 = -1;
        }
        func_8003D750();
        func_800735F8(0x14);
        func_80023754(0xA);
        D_800B73D8 = 0;
        D_800B6D38 = 2;
        D_800B72A0 = 1;
        func_80031B9C();
        func_80024124();
    }
}

extern char D_800939E4[];

void func_800725EC(void) {
    RECT unused = D_800B678C;

    func_800246A8(0x140);
    func_8002370C();
    func_80076478(0xA0, 0x78, func_80078980(D_800939E4), 0x800, 0x400, D_800B63E8, D_800B63F0);
    if (D_800B72E0 == 0) {
        if (D_800B7088 != NULL && (s16)func_80071E20() == 0) {
            D_800B7430 = -1;
        }
        func_8003D750();
        func_800735F8(0x14);
        func_80023754(0xA);
        D_800B73D8 = 0;
        func_80031B9C();
        D_800B6D38 = 2;
        D_800B72A0 = 4;
        func_80024124();
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8007270C);

s32 func_80072734(s32 a, s32 b, s32 t) {
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

void *func_80072768(void *data, s16 i) {
    Pack *pack = data;
    return (u8 *)pack + pack->entries[i].offset;
}

u32 func_80072780(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk4;
}

s32 func_80072798(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unk8;
}

s32 func_800727B0(void *data, s16 i) {
    return ((Pack *)data)->entries[i].unkC;
}

extern s16 D_800B7218;
extern u8 D_801DA1CC[][4];
int CdGetToc(u8 (*loc)[4]);

s32 func_800727C8(void) {
    u8 param[16];

    param[0] = 5;
    CdControlB(0xE, param, 0);
    D_800B7218 = CdGetToc(D_801DA1CC);
    return -1;
}

extern volatile s16 D_800B6B50;

void func_80072810(void) {
    D_800B6B50 = 20;
}

extern char D_80088A2C[];
int printf(const char *fmt, ...);
int ResetGraph(int mode);
void PadStop(void);
void StopPAD(void);
void *ResetCallback(void);
void func_8007BC3C(void);
void func_800739C0(void);

void func_80072824(void) {
    printf(D_80088A2C);
    ResetGraph(3);
    PadStop();
    StopPAD();
    ResetCallback();
    func_8007BC3C();
    func_800739C0();
    func_80078EBC(1);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80072884);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80072B00);

extern struct {
    s16 count[3];
    s16 size[3];
    s16 total;
    s16 unkE;
    s32 left;
} D_801D9B18;
extern u8 D_801C99A4[];
extern u8 *D_801F6F40[];
extern u8 *D_801F7140[];
extern u8 *D_801F7340[];
extern u8 D_801F6DC0[];
extern u8 D_801F6E40[];
extern u8 D_801F6EC0[];
extern s16 D_801F6DB8[3];
extern struct Task D_800BBE2C[];
extern struct Task *D_800B6FB8;
extern struct Task *D_801F7540[];
extern s32 D_800B6B48;
extern s32 D_800BD608;

void func_80072BF8(void) {
    s32 left;
    u8 *p;
    s16 i;

    D_801D9B18.count[0] = 0x20;
    D_801D9B18.count[1] = 0x20;
    D_801D9B18.count[2] = 0x10;
    D_801D9B18.size[0] = 0x400;
    D_801D9B18.size[1] = 0x200;
    D_801D9B18.size[2] = 0x100;
    D_801D9B18.unkE = 0x20;
    left = 0x10000;
    p = D_801C99A4;
    for (i = 0; i < D_801D9B18.count[0]; i++) {
        if (left - D_801D9B18.size[0] < 0) {
            D_801D9B18.count[0] = i;
            break;
        }
        D_801F6F40[i] = p;
        D_801F6DC0[i] = 0;
        p += D_801D9B18.size[0];
        left -= D_801D9B18.size[0];
    }
    if (left > 0) {
        for (i = 0; i < D_801D9B18.count[1]; i++) {
            if (left - D_801D9B18.size[1] < 0) {
                D_801D9B18.count[1] = i;
                break;
            }
            D_801F7140[i] = p;
            D_801F6E40[i] = 0;
            p += D_801D9B18.size[1];
            left -= D_801D9B18.size[1];
        }
    } else {
        D_801D9B18.count[1] = 0;
    }
    if (left > 0) {
        for (i = 0; ; i++) {
            if (left - D_801D9B18.size[2] < 0) {
                D_801D9B18.count[2] = i;
                break;
            }
            D_801F7340[i] = p;
            D_801F6EC0[i] = 0;
            p += D_801D9B18.size[2];
            left -= D_801D9B18.size[2];
        }
        D_801D9B18.count[2] = i;
    } else {
        D_801D9B18.count[2] = 0;
    }
    D_801D9B18.left = left;
    D_800B6B48 = 0;
    D_800B6DE0 = D_800BBE2C;
    D_800BBE2C[0].unk2E = 0;
    D_800BBE2C[0].unk2F = 0;
    D_801F6DC0[0] = 0xFF;
    D_800B6FB8 = &D_800BBE2C[1];
    D_800BBE2C[0].next = D_800BBE2C;
    D_800BBE2C[0].prev = D_800BBE2C;
    D_801D9B18.total = D_801D9B18.count[0] + D_801D9B18.count[1] + D_801D9B18.count[2];
    D_801F6DB8[0] = D_801D9B18.count[0];
    D_801F6DB8[1] = D_801D9B18.count[1];
    D_801F6DB8[2] = D_801D9B18.count[2];
    D_800BBE2C[0].vals = (Unk800A317CVals *)D_801F6F40[0];
    D_801F6DB8[0] = D_801D9B18.count[0] - 1;
    for (i = 1; i < 0x80; i++) {
        D_800BBE2C[i].next = &D_800BBE2C[i + 1];
        D_801F7540[i] = NULL;
    }
    D_800BD608 = 0;
}

extern struct Task *D_800B6FB8;
extern struct Task D_801F7868;
extern void (*D_800B6DE8)();
extern s32 D_800B6B48;
extern s16 D_800B6C60[3];
extern s16 func_80074304(s16 size, struct Task *t);

struct Task *func_80072F2C(void (*fn)(), s16 size) {
    struct Task *t;

    if (D_800B6FB8 == NULL) {
        return NULL;
    }
    D_800B6DE8 = fn;
    D_801F7868.flags = 1;
    if (func_80074304(size, &D_801F7868) == 0) {
        return NULL;
    }
    t = D_800B6FB8;
    t->vals = D_801F7868.vals;
    D_800B6FB8 = t->next;
    t->unk2E = D_801F7868.unk2E;
    t->unk2F = D_801F7868.unk2F;
    t->func = fn;
    t->saved = fn;
    D_800B6DE0->next->prev = t;
    t->next = D_800B6DE0->next;
    D_800B6DE0->next = t;
    t->prev = D_800B6DE0;
    t->unk14 = D_800B6C60[0];
    t->unk16 = D_800B6C60[1];
    t->unk18 = D_800B6C60[2];
    t->id = D_800B6B48++;
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

extern void *D_800B7330;

Unk8003BA6C_Task *func_8007307C(void (*fn)(), s16 flags, s16 size) {
    struct Task *t;
    s16 f;

    if (D_800B6FB8 == NULL) {
        return NULL;
    }
    D_800B6DE8 = fn;
    GET_RA(D_800B7330); // FAKE: caller address store, see GET_RA
    D_801F7868.flags = f = flags | 1;
    if (func_80074304(size, &D_801F7868) == 0) {
        return NULL;
    }
    t = D_800B6FB8;
    t->vals = D_801F7868.vals;
    D_800B6FB8 = t->next;
    t->unk2E = D_801F7868.unk2E;
    t->unk2F = D_801F7868.unk2F;
    t->flags = f;
    t->func = fn;
    t->saved = fn;
    D_800B6DE0->next->prev = t;
    t->next = D_800B6DE0->next;
    D_800B6DE0->next = t;
    t->prev = D_800B6DE0;
    t->unk14 = D_800B6C60[0];
    t->unk16 = D_800B6C60[1];
    t->unk18 = D_800B6C60[2];
    t->id = D_800B6B48++;
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

extern struct Task *D_801F7540[];

struct Task *func_800731DC(void (*fn)(), s16 size) {
    struct Task *anchor = D_801F7540[0];
    struct Task *t;

    if (D_800B6FB8 == NULL) {
        return NULL;
    }
    D_800B6DE8 = fn;
    D_801F7868.flags = 1;
    if (func_80074304(size, &D_801F7868) == 0) {
        return NULL;
    }
    t = D_800B6FB8;
    t->vals = D_801F7868.vals;
    D_800B6FB8 = t->next;
    t->unk2E = D_801F7868.unk2E;
    t->unk2F = D_801F7868.unk2F;
    t->flags = 1;
    t->func = fn;
    t->saved = fn;
    anchor->next->prev = t;
    t->next = anchor->next;
    anchor->next = t;
    t->prev = anchor;
    t->unk14 = D_800B6C60[0];
    t->unk16 = D_800B6C60[1];
    t->unk18 = D_800B6C60[2];
    t->id = D_800B6B48++;
    t->cleanup = NULL;
    t->unk2C = 0;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return t;
}

struct Task *func_80073320(struct Task *parent, void (*fn)(), s16 size) {
    struct Task *t;

    if (D_800B6FB8 == NULL) {
        return NULL;
    }
    D_800B6DE8 = fn;
    D_801F7868.flags = 1;
    if (func_80074304(size, &D_801F7868) == 0) {
        return NULL;
    }
    t = D_800B6FB8;
    t->vals = D_801F7868.vals;
    D_800B6FB8 = t->next;
    t->unk2E = D_801F7868.unk2E;
    t->unk2F = D_801F7868.unk2F;
    t->func = fn;
    t->saved = fn;
    parent->next->prev = t;
    t->next = parent->next;
    parent->next = t;
    t->prev = parent;
    t->unk14 = D_800B6C60[0];
    t->unk16 = D_800B6C60[1];
    t->unk18 = D_800B6C60[2];
    t->id = D_800B6B48++;
    t->flags = 1;
    t->unk2C = 0;
    t->cleanup = NULL;
    t->unk28 = 200;
    t->unk29 = 200;
    t->unk2A = 200;
    return t;
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8007345C);

extern void *D_800B7330;

void func_800735F8(s16 mask) {
    struct Task *cur = D_800B6DE0;

    GET_RA(D_800B7330); // FAKE: caller address store, see GET_RA
    for (D_800B6DE0 = cur->next; D_800B6DE0 != cur; D_800B6DE0 = D_800B6DE0->next) {
        if (mask & D_800B6DE0->flags) {
            if (D_800B6DE0->cleanup != NULL) {
                D_800B6DE0->cleanup();
            }
            func_8007345C();
        }
    }
}

extern s16 D_801D9B1E[3];
extern void func_80073828(struct Task *task);

s16 func_800736AC(s16 size) {
    struct Task *cur = D_800B6DE0;
    struct Task *t;

    if (D_801D9B1E[2] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 3) {
                func_80073828(t);
                return -1;
            }
        }
    }
    if (D_801D9B1E[1] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 2) {
                func_80073828(t);
                return -1;
            }
        }
    }
    if (D_801D9B1E[0] >= size) {
        for (t = cur->next; t != cur; t = t->next) {
            if ((t->flags & 0x10) && t->unk2E == 1) {
                func_80073828(t);
                return -1;
            }
        }
    }
    return 0;
}

extern struct Task *D_801F7540[];

void func_80073828(struct Task *task) {
    struct Task *saved = D_800B6DE0;
    s16 i;

    if (task->cleanup != NULL) {
        task->cleanup();
    }
    i = 0x7F;
    do {
        if (D_801F7540[i] == task) {
            D_801F7540[i] = NULL;
            break;
        }
    } while (i-- != 0);
    D_800B6DE0 = task;
    func_8007345C();
    D_800B6DE0 = saved;
}

extern void func_80072BF8(void);
extern void func_80073CF0(void);
extern s16 D_800B6CA8;
extern s16 D_800B6BC0;
extern s32 D_800B7270;
extern u16 D_800B6C88;
extern struct Task *D_800B6FA0;

void func_800738C0(void) {
    func_80072BF8();
    D_800B6CA8 = 0;
    D_800B6BC0 = 0;
    D_800B6DE0->func = func_80073CF0;
    while (D_800B6AA0 != 10) {
        D_800B7270++;
        D_800B6C88++;
        D_800B6DE0->func();
        D_800B6FA0 = D_800B6DE0;
        D_800B6DE0 = D_800B6DE0->next;
    }
}

void func_80073980(struct Task *task) {
    struct Task *saved = D_800B6DE0;

    D_800B6DE0 = task;
    task->func();
    D_800B6DE0 = saved;
}

extern s32 DrawSync(s32 mode);
extern void FlushCache(void);

void func_800739C0(void) {
    DrawSync(0);
    func_8007FD1C();
    FlushCache();
    func_8007FFB4();
}

extern s16 D_800B6BD8;
extern s16 D_800B6BE0;
extern s16 D_800B70E0;
void func_800863D0(s32 a, s32 b);

void func_800739F8(void) {
    func_800863D0(D_800B6BD8, D_800B6BE0 + D_800B70E0);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80073A30);

extern void CdSetDebug(int level);
extern void SetGraphDebug(int level);
extern void InitGeom(void);
extern int ClearImage(RECT *rect, u8 r, u8 g, u8 b);
extern void func_80080024(s32 mode);
extern void func_800862A0(s32 a);
extern s16 D_800B7110;
extern s16 D_800B7050;
extern s16 D_800B72E0;
extern s16 D_800B6FF0;
extern s16 D_800B6E68;
extern s16 D_800B6B98;
extern s16 D_800B7068;
extern s16 D_800B71C0;
extern s16 D_800B7160;
extern u8 D_8009F72C[];
extern s16 func_8007608C(void *data, s32 a1);
extern void func_80078EBC(s16 arg0);
extern void func_80078F5C(void);
extern void func_8007637C(void);
extern int CdInit(void);

void func_80073B44(void) {
    u8 unused[0x78];
    RECT rect;
    u8 unused2[0x28];

    func_80078F5C();
    ResetGraph(0);
    D_800B7110 = 0;
    D_800B7050 = 0;
    D_800B72E0 = 0;
    ResetCallback();
    func_800739C0();
    D_800B6FF0 = 0;
    D_800B6E68 = 0;
    D_800B6B98 = 0;
    D_800B7370 = (Unk800B7370 *)0x80011000;
    D_800B7068 = 0;
    CdInit();
    CdSetDebug(0);
    func_800727C8();
    SetGraphDebug(0);
    DrawSync(0);
    VSync(0);
    SetDispMask(0);
    InitGeom();
    if (D_800B7370->unk178A != 0) {
        D_800B6BD8 = 0xA0;
        D_800B6BE0 = 0x78;
        func_80080024(0);
    } else {
        D_800B6BD8 = 0xA0;
        D_800B6BE0 = 0x80;
        func_80080024(1);
    }
    func_800739F8();
    D_800B71C0 = 0x200;
    func_800862A0(0x200);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x3FF;
    rect.h = 0x100;
    ClearImage(&rect, 0, 0, 0);
    func_8007608C(D_8009F72C, 0);
    func_8007637C();
    D_800B6AA0 = 0;
    VSync(0);
    SetDispMask(1);
    func_800738C0();
    func_80078EBC(D_800B7160);
}

extern s16 D_800B6D30;
extern void func_80073F3C(void);

void func_80073CF0(void) {
    D_800B6D30 = 0;
    D_800B6DE0->func = func_80073F3C;
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

void func_80074138(void);
void func_800742C4(void);
typedef struct {
    u8 pad[0xF0];
    s16 unkF0;
} Unk80077300;

extern struct {
    u8 pad[0x1C];
    Unk80077300 *unk1C;
} *D_801F7594;
extern u8 D_801DA35C[];
extern u8 D_801E835C[];
extern DISPENV *SetDefDispEnv(DISPENV *env, s32 x, s32 y, s32 w, s32 h);
extern DRAWENV *SetDefDrawEnv(DRAWENV *env, s32 x, s32 y, s32 w, s32 h);
void func_80073980(struct Task *task);

void func_80073D10(void) {
    struct Task *t;
    Unk80074138 *db;

    t = func_80074950(func_80074138, 5);
    D_801F7594 = (void *)t;
    db = *(Unk80074138 **)((u8 *)t + 0x1C);
    db->prim[0] = (u32 *)D_801DA35C;
    db->prim[1] = (u32 *)D_801E835C;
    if (D_800B7370->unk178A != 0) {
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
    db->ot[0] = (u32 *)func_8007307C(func_800742C4, 5, 0x400)->data;
    db->ot[1] = (u32 *)func_8007307C(func_800742C4, 5, 0x400)->data;
    ClearOTagR(db->ot[0], 0xFA);
    ClearOTagR(db->ot[1], 0xFA);
    D_800B7018 = db->ot[0];
    D_800B70A8 = D_800B7140 = db->prim[0];
    func_80073980((struct Task *)D_801F7594);
}

extern s16 D_800B6AF8;

void func_80073F00(void) {
    if (D_800B6AF8 == 1) {
        D_800B6AF8 = 2;
        func_8007345C();
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80073F3C);


extern void DrawOTag(u32 *ot);
extern u32 *ClearOTagR(u32 *ot, s32 n);
extern DRAWENV *PutDrawEnv(DRAWENV *env);
void func_80074DFC(void);
void func_80074AE4(void);
extern s16 D_800B6C38;

void func_80074138(void) {
    Unk80074138 *db = (Unk80074138 *)D_800B6DE0->vals;
    s16 n = 20;

    DrawOTag(db->ot[db->id] + 0xF9);
    while (DrawSync(1) != 0) {
        VSync(0);
        if (n-- == 0) {
            D_800B6AA0 = 9;
            return;
        }
    }
    func_80074DFC();
    func_80074AE4();
    D_800B6CC8++;
    PutDispEnv(&db->disp[db->id]);
    ClearOTagR(db->ot[db->id], 0xFA);
    D_800B7018 = db->ot[db->id];
    D_800B70A8 = D_800B7140 = db->prim[db->id];
    PutDrawEnv(&db->draw[db->id]);
    db->id ^= 1;
    D_800B6C38 = db->draw[db->id].ofs[0];
}

void func_800742C4(void) {
}

extern s16 D_800B7040;
extern void func_8001E890(void);

void func_800742CC(void) {
    if (D_800B6D30 != -1) {
        D_800B7040 = 1;
        D_800B6DE0->func = func_8001E890;
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80074304);

void func_80074658(void) {
    s32 left;
    u8 *p;
    s16 i;

    if (D_801D9B18.count[0] < D_801D9B18.unkE) {
        D_801D9B18.count[0] = D_801D9B18.unkE + 1;
    }
    if (D_801D9B18.size[0] & 3) {
        D_801D9B18.size[0] = (D_801D9B18.size[0] + 3) & ~3;
    }
    if (D_801D9B18.size[1] & 3) {
        D_801D9B18.size[1] = (D_801D9B18.size[1] + 3) & ~3;
    }
    if (D_801D9B18.size[2] & 3) {
        D_801D9B18.size[2] = (D_801D9B18.size[2] + 3) & ~3;
    }
    left = 0x10000;
    p = D_801C99A4;
    left -= D_801D9B18.size[0] * D_801D9B18.unkE;
    p += D_801D9B18.size[0] * D_801D9B18.unkE;
    for (i = 0; i < D_801D9B18.count[0]; i++) {
        if (i >= D_801D9B18.unkE) {
            if (left - D_801D9B18.size[0] < 0) {
                D_801D9B18.count[0] = i;
                break;
            }
            D_801F6F40[i] = p;
            D_801F6DC0[i] = 0;
            p += D_801D9B18.size[0];
            left -= D_801D9B18.size[0];
        }
    }
    if (left > 0) {
        for (i = 0; i < D_801D9B18.count[1]; i++) {
            if (left - D_801D9B18.size[1] < 0) {
                D_801D9B18.count[1] = i;
                break;
            }
            D_801F7140[i] = p;
            D_801F6E40[i] = 0;
            p += D_801D9B18.size[1];
            left -= D_801D9B18.size[1];
        }
    } else {
        D_801D9B18.count[1] = 0;
    }
    if (left > 0) {
        for (i = 0; ; i++) {
            if (left - D_801D9B18.size[2] < 0) {
                D_801D9B18.count[2] = i;
                break;
            }
            D_801F7340[i] = p;
            D_801F6EC0[i] = 0;
            p += D_801D9B18.size[2];
            left -= D_801D9B18.size[2];
        }
        D_801D9B18.count[2] = i;
    } else {
        D_801D9B18.count[2] = 0;
    }
    D_801D9B18.left = left;
    D_801D9B18.total = D_801D9B18.count[0] + D_801D9B18.count[1] + D_801D9B18.count[2];
    D_801F6DB8[2] = D_801D9B18.count[2];
    D_801F6DB8[1] = D_801D9B18.count[1];
    D_801F6DB8[0] = D_801D9B18.count[0] - D_801F6DB8[0];
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80074950);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80074AE4);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80074DFC);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800754C8);

MATRIX *func_80075578(SVECTOR *rot, MATRIX *m) {
    u16 ax, ay, az;
    s16 cx, sx, cy, sy, cz, sz;
    s32 sxsy, sxcy;

    ax = rot->vx;
    ay = rot->vy;
    sx = D_800982E4[ax & 0xFFF];
    sy = D_800982E4[ay & 0xFFF];
    sxsy = sx * sy;
    cy = D_800982E4[(ay + 0x400) & 0xFFF];
    sxcy = sx * cy;
    az = rot->vz;
    cz = D_800982E4[(az + 0x400) & 0xFFF];
    sz = D_800982E4[az & 0xFFF];
    cx = D_800982E4[(ax + 0x400) & 0xFFF];
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

extern MATRIX *func_80075578(SVECTOR *r, MATRIX *m);

void func_800757A8(SVECTOR *rot, SVECTOR *v, SVECTOR *base, SVECTOR *out) {
    VECTOR tmp;

    func_80075578(rot, &D_801F9644);
    ApplyMatrix(&D_801F9644, v, &tmp);
    out->vx = base->vx + tmp.vx;
    out->vy = base->vy + tmp.vy;
    out->vz = base->vz + tmp.vz;
}

extern SVECTOR D_800B6E90;
extern SVECTOR D_800B6BB0;
extern SVECTOR D_800B72C0;
extern MATRIX D_80169F78;
extern VECTOR D_801C9980;
extern void SetRotMatrix(MATRIX *m);
extern void SetTransMatrix(MATRIX *m);
extern MATRIX *func_80085EA0(MATRIX *m, VECTOR *v);

void func_8007583C(void) {
    D_800B72C0.vx = -D_800B6BB0.vx;
    D_800B72C0.vy = -D_800B6BB0.vy;
    D_800B72C0.vz = -D_800B6BB0.vz;
    func_80075578(&D_800B6E90, &D_80169F78);
    ApplyMatrix(&D_80169F78, &D_800B72C0, &D_801C9980);
    func_80085EA0(&D_80169F78, &D_801C9980);
    SetRotMatrix(&D_80169F78);
    SetTransMatrix(&D_80169F78);
}

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B678C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6794);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B679C);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67A0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67A4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67AC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67B4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67BC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67C4);

extern void *D_800B7140;
extern s16 D_800B7110;
extern u32 *D_800B7018;
typedef struct {
    s16 x, y, w, h;
} Unk80075900_Rect;

typedef struct {
    u32 tag;
    u32 code[2];
} Unk80075900_Area;

extern s16 D_800B6C38;
extern void SetDrawArea(Unk80075900_Area *p, Unk80075900_Rect *r);

void func_80075900(s32 top, s32 bottom) {
    Unk80075900_Rect r;
    Unk80075900_Area *area = D_800B7140;

    r.w = 320;
    r.h = bottom - top;
    r.x = D_800B6C38;
    r.y = top + D_800B7110;
    SetDrawArea(area, &r);
    AddPrim(D_800B7018 + 0xF9, area++);
    D_800B7140 = area;
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
} Unk800BD768;

extern Unk800BD768 D_800BD768[8];
extern u16 D_8009B444[];

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[6];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk8007597C;

typedef struct {
    s16 x;
    s16 y;
    s16 val;
} Unk8007597C_Arg;

void func_800774D8(s32 level);
s32 func_800770DC(u8 *data, Unk8007597C_Arg *arg);

void func_8007597C(void) {
    Unk8007597C *d = (Unk8007597C *)D_800B6DE0->vals;
    Unk8007597C_Arg arg;

    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    if (d->unk10 < 0x1000) {
        d->unk10 += 0x199;
        func_800774D8(0x1000 - d->unk10);
    }
    if (d->unkC > 0) {
        d->unkC -= 0x400;
        func_800770DC(D_8009F72C, &arg);
    } else {
        D_800B6AF8 = 3;
        func_8007345C();
    }
}

extern SVECTOR D_800B67A4;
extern SVECTOR D_800B67AC;
extern SVECTOR D_800B67B4;
extern SVECTOR D_800B67BC;
typedef struct {
    u8 r, g, b, cd;
} CVECTOR;

extern CVECTOR D_800B67C4;

void func_80075A34(void) {
    Unk8007597C *d = (Unk8007597C *)D_800B6DE0->vals;
    SVECTOR a = D_800B67A4;
    SVECTOR v = D_800B67AC;
    SVECTOR base = D_800B67B4;
    Unk8007597C_Arg arg;
    SVECTOR unused;
    SVECTOR e = D_800B67BC;

    D_800B6E90.vz = 0;
    D_800B6E90.vy = d->unk2;
    D_800B6E90.vx = 0;
    v.vz = -1000;
    v.vy = -40;
    v.vx = 0;
    func_800757A8(&D_800B6E90, &v, &base, &D_800B6BB0);
    func_8007583C();
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_800770DC(D_8009F72C, &arg);
    d->unk10 -= 0x200;
    func_800774D8(0x1000 - d->unk10);
    if (d->unk10 < 0) {
        D_800B6AF8 = 2;
        D_800B6DE0->func = func_8007597C;
    }
}

void func_80075BC0(void) {
    Unk8007597C *d = (Unk8007597C *)D_800B6DE0->vals;
    SVECTOR a = D_800B67A4;
    SVECTOR v = D_800B67AC;
    SVECTOR base = D_800B67B4;
    Unk8007597C_Arg arg;
    SVECTOR unused;
    SVECTOR e = D_800B67BC;
    CVECTOR col = D_800B67C4;
    s16 t;

    D_800B6E90.vz = 0;
    D_800B6E90.vy = d->unk2;
    D_800B6E90.vx = 0;
    t = d->unkA;
    v.vz = func_80072734(-1000, -1000, t);
    v.vy = func_80072734(-120, -40, t);
    v.vz = -2000;
    v.vy = -50;
    v.vx = 0;
    if (d->unkE != 0) {
        d->unkE--;
    } else if (d->unkA < 0x1000) {
        d->unkA += 0x40;
    }
    func_800757A8(&D_800B6E90, &v, &base, &D_800B6BB0);
    func_8007583C();
    arg.x = 0x302;
    arg.y = 0x4C4;
    arg.val = d->unkC;
    func_800770DC(D_8009F72C, &arg);
    if (D_800B6AF8 == 1) {
        d->unk10 = 0x1000;
        D_800B6DE0->func = func_80075A34;
    }
    if (d->unk10 != 0) {
        d->unk10 -= 0x3E;
        func_800774D8(0x1000 - d->unk10);
        if (d->unk10 < 0) {
            D_800B6DE0->func = func_8007597C;
            return;
        }
        if (d->unk10 >= 0x7D) {
            func_80075900(0x60, 0xA8);
        }
    } else if (d->unkC >= 0xC80) {
        func_80075900(0x60, 0xA8);
    }
}

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Unk80075E28;

extern void func_80075BC0(void);

void func_80075E28(void) {
    Unk80075E28 *p = (Unk80075E28 *)D_800B6DE0->vals;
    SVECTOR pos = {100, 0, 0};

    p->unkC = 0x7210;
    p->unkA = 0;
    p->unkE = 10;
    p->unk10 = 0;
    func_80077BB0(&pos);
    func_80077BB0(&pos);
    func_80077BB0(&pos);
    D_800B6DE0->func = func_80075BC0;
}

void func_80075EC0(void) {
    u16 *clut = D_8009B444;
    s16 i;

    for (i = 0; i < 8; i++) {
        s16 u = (i & 7) << 5;
        s16 v = ((i >> 3) & 7) << 5;

        D_800BD768[i].u0 = u;
        D_800BD768[i].v0 = v;
        D_800BD768[i].u1 = u + 0x1F;
        D_800BD768[i].v1 = v;
        D_800BD768[i].u4 = u + 0x1F;
        D_800BD768[i].v4 = v;
        D_800BD768[i].u5 = u + 0x1F;
        D_800BD768[i].v5 = v;
        D_800BD768[i].u2 = u;
        D_800BD768[i].v2 = v | 0x1F;
        D_800BD768[i].u3 = u + 0x1F;
        D_800BD768[i].v3 = v | 0x1F;
        D_800BD768[i].tpage = GetTPage(0, 0, 0x280, 0);
        D_800BD768[i].tpage2 = GetTPage(0, 2, 0x280, 0);
        D_800BD768[i].tpage3 = GetTPage(0, 1, 0x280, 0);
        D_800BD768[i].clut = GetClut(0x2C0, *clut++);
    }
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_8007608C);

extern s32 D_8009B48C[];
extern s8 D_801F9D8C[];
extern void *func_80072768(void *data, s16 i);
extern s16 func_8007608C(void *data, s32 a1);

void func_8007637C(void) {
    s16 i;

    for (i = 0; i < D_8009B48C[0]; i++) {
        D_801F9D8C[i] = (func_8007608C(func_80072768(D_8009B48C, i), -1) << 5) / 200;
    }
    i = 9;
    do {
        D_801F9D8C[i] = 30;
    } while (i--);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80076478);

extern s16 D_800B72B0;
extern void func_80076478(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_80076DD8(s16 x, s16 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800B72B0 = -1;
    func_80076478(x, y, text, a3, a4, a5, a6);
}

extern char D_80169FC0[];

void func_80076E28(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    short i, j;

    i = len - 1;
    if (len != 0) {
        do {
            D_80169FC0[i] = value % 10 + '0';
            value /= 10;
            j = i;
            i--;
        } while (j != 0);
    }
    D_80169FC0[len] = 0;
    func_80076478(x, y, D_80169FC0, d, a, b, c);
}

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80076EF4);

extern void func_80076EF4(s32 x, s32 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6);

void func_8007702C(short x, short y, unsigned int value, int d, int a, u8 *b, u8 *c, short len) {
    D_800B72B0 = -1;
    func_80076E28(x, y, value, d, a, b, c, len);
}

void func_8007708C(s16 x, s16 y, char *text, s32 a3, s32 a4, u8 *a5, u8 *a6) {
    D_800B72B0 = -1;
    func_80076EF4(x, y, text, a3, a4, a5, a6);
}

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
} Unk800770DC_F3;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s32 xy0;
    s32 xy1;
    s32 xy2;
    s32 xy3;
} Unk800770DC_F4;

typedef struct {
    SVECTOR *v[4];
    u16 unk10;
    u16 tri;
} Unk800770DC_Face;

typedef struct {
    u8 pad[0xC];
    u16 count;
    u8 padE[6];
    Unk800770DC_Face face[1];
} Unk800770DC_Model;

extern SVECTOR D_800B67E0;
extern VECTOR D_80088AB8;
extern void PushMatrix(void);
extern void PopMatrix(void);
extern MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v);
extern void SetPolyF4(void *p);

s32 func_800770DC(u8 *data, Unk8007597C_Arg *arg) {
    Unk800770DC_Model *m = (Unk800770DC_Model *)data;
    SVECTOR unused;
    SVECTOR rot = D_800B67E0;
    VECTOR scale = D_80088AB8;
    Unk800770DC_Face *f;
    s16 n;

    if (m == NULL) {
        return 0;
    }
    D_801C9980.vx = arg->x - 0xA0;
    D_801C9980.vy = arg->y - 0xB4;
    D_801C9980.vz = arg->val;
    PushMatrix();
    func_80085EA0(&D_801F9644, &D_801C9980);
    SetTransMatrix(&D_801F9644);
    func_80075578(&rot, &D_801F9644);
    ScaleMatrix(&D_801F9644, &scale);
    SetRotMatrix(&D_801F9644);
    f = m->face;
    n = m->count;
    while (n--) {
        if (f->tri != 0) {
            Unk800770DC_F3 *p = D_800B7140;

            D_800B6F30 = RotTransPers3(f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy2, &D_800B6A90, &D_800B7198);
            if (!(D_800B7198 & ~0x1FFF)) {
                SetPolyF3(p);
                p->b0 = p->g0 = p->r0 = 0;
                AddPrim(D_800B7018, p);
                p++;
                D_800B7140 = p;
            }
        } else {
            Unk800770DC_F4 *p = D_800B7140;

            D_800B6F30 = RotTransPers4(f->v[3], f->v[2], f->v[1], f->v[0], &p->xy0, &p->xy1, &p->xy3, &p->xy2, &D_800B6A90, &D_800B7198);
            if (!(D_800B7198 & ~0x1FFF)) {
                SetPolyF4(p);
                p->b0 = p->g0 = p->r0 = 0;
                AddPrim(D_800B7018, p);
                p++;
                D_800B7140 = p;
            }
        }
        f++;
    }
    PopMatrix();
}

s32 func_80077398(Unk8002A35C *a, Unk8002A35C *b) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80077424);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800774D8);

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
} Unk80077BB0;

extern struct Task *func_80074950(void (*func)(void), s16 flags);
extern void func_800775BC(void);

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_800775BC);

void func_80077BB0(SVECTOR *pos) {
    struct Task *t = func_80074950(func_800775BC, 5);
    Unk80077BB0 *d;
    s16 i;

    if (t != NULL) {
        d = (Unk80077BB0 *)t->vals;
        d->x = pos->vx;
        d->y = pos->vy;
        d->z = pos->vz;
        i = 15;
        do {
            func_800754C8(0x1000);
            d->unk28[i] = func_800754C8(0x1000);
            d->unk12C = 0;
            d->unk12E = 32;
        } while (i--);
        i = 15;
        do {
            d->unk48[i] = func_800754C8(0x1000);
            d->unkAC[i] = func_800754C8(0x1000);
            d->unk10C[i] = func_800754C8(0x1000);
            d->unk68[i] = func_800754C8(0x80) - 0x40;
            d->unk88[i] = func_800754C8(0x1000);
        } while (i--);
        d->unkA8 = 0;
        d->unkAA = 30;
        d->unk130 = 16;
        d->unk132 = 128;
        d->unk134 = 30;
        d->unk136 = 0x200;
    }
}

s32 func_80077CE0(s32 *buf, u32 size) {
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

INCLUDE_ASM("asm/dh2/nonmatchings/dh2", func_80078430);

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

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67D0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67D4);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67D8);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67DC);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67E0);

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67E8);

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
    printf("Loaded\n");
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

INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B67F8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6808);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6810);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6814);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6818);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B681C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6820);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6828);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B682C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6830);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6834);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6838);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B683C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6840);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6844);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6848);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B684C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68B8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68BC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68C0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68C8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68CC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68D0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68D4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68D8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68E0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B68EC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6908);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6968);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69C8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69CC);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69D0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69D4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69E0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69E8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B69F0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A10);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A18);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A20);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A28);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A30);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A38);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A40);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A48);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A54);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A64);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A6C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A74);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A7C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A80);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A88);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A90);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6A98);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6AA0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6AD8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6AE8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6AF8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B00);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B08);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B10);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B18);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B20);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B28);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B30);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B40);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B48);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B50);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B58);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B60);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B68);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B70);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B78);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B80);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B88);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B90);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6B98);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BA8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BB0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BB4);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BC0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BC8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BD8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6BF0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C00);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C10);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C18);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C20);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C28);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C2C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C30);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C38);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C40);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C44);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C48);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C50);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C58);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C60);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C64);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C68);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C70);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C80);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C88);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C90);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C98);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6C9C);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CA0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CA8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CB0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CB8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CC0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CC8);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CD0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CE0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CF0);
INCLUDE_RODATA("asm/dh2/nonmatchings/dh2", D_800B6CF8);
