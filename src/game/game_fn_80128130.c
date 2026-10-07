typedef unsigned char u8;

typedef struct Entry48C8 {
    int state;
    u8 pad[0x48C4];
} Entry48C8;

extern Entry48C8 lbl_80514AE0[];

int fn_80128130(void)
{
    int i;

    for (i = 19; i >= 0; i--) {
        if (lbl_80514AE0[i].state == 0) {
            return 1;
        }
    }
    return 0;
}
