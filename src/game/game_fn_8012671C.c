typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry1238 {
    volatile u32 flags;
    u8 pad[0x1234];
} Entry1238;

typedef struct Entry48C8 {
    volatile u32 flags;
    u8 pad[0x48C4];
} Entry48C8;

extern Entry1238 lbl_8056FA80[];
extern Entry48C8 lbl_80514AE0[];

int fn_8012671C(void)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < 48; i++) {
        if (lbl_8056FA80[i].flags & 1) {
            count++;
        }
    }

    count = 0;
    for (i = 0; i < 20; i++) {
        if (lbl_80514AE0[i].flags & 1) {
            count++;
        }
    }
    return count;
}
