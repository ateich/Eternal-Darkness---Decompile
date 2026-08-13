typedef unsigned char u8;

extern u8 lbl_8031CD84[];
extern void fn_80154514(void *, int);

int fn_80080530(int index, int mode)
{
    u8 *slot = lbl_8031CD84 + index * 4;
    int released = 0;

    if (*(void **)(slot += 0x46C) != 0) {
        fn_80154514(*(void **)slot, mode);
        *(void **)slot = 0;
        released = 1;
    }
    return released;
}
