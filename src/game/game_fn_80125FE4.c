typedef unsigned int u32;

extern unsigned char lbl_80514AE0[];
extern unsigned char lbl_8056FA80[];
extern unsigned char lbl_805A6500[];
extern u32 lbl_8064CF20;
extern u32 lbl_8064CF24;
extern void* memset(void*, int, u32);

void fn_80125FE4(void)
{
    memset(lbl_80514AE0, 0, 0x5AFA0);
    memset(lbl_8056FA80, 0, 0x36A80);
    memset(lbl_805A6500, 0, 0x48C8);
    lbl_8064CF24 = 0;
    lbl_8064CF20 = 0;
}
