typedef unsigned char u8;

typedef struct Entry1238 {
    int state;
    u8 pad[0x1234];
} Entry1238;

extern Entry1238 lbl_8056FA80[];

int fn_80128258(void)
{
    int i;

    for (i = 47; i >= 0; i--) {
        if (lbl_8056FA80[i].state == 0) {
            return 1;
        }
    }
    return 0;
}
