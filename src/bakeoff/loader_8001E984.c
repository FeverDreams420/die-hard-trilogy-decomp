/* LOADER 0x8001E984: clear one field (16-byte frame in the original). */

typedef struct {
    char pad[0x58];
    short f58;
} Obj;

extern void printf(char *fmt, ...);

void func_8001E984(Obj *o) {
    o->f58 = 0;
    if (0) {
        printf("debug
");
    }
}
