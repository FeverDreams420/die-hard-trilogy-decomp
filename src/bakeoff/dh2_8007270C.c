/* DH2 0x8007270C (also DH3 0x80071B54): field of the i-th 24-byte entry. */

typedef struct {
    int a;
    int b;
    int pad[4];
} Entry24;

extern Entry24 *D_800B679C;          /* gp+0x5B8 */

int func_8007270C(short i) {
    return D_800B679C[i].b;
}
