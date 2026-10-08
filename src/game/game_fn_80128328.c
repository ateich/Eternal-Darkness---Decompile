typedef unsigned char u8;

typedef struct Entry48C8 {
    int state;
    u8 pad[0x48C4];
} Entry48C8;

extern Entry48C8 lbl_80514AE0[];

int fn_80128328(void)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < 20; i++) {
        if (lbl_80514AE0[i].state == 0) {
            count++;
        }
    }
    return count > 4 ? count : 0;
}
