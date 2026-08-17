typedef unsigned int u32;

extern unsigned char lbl_80500500[];
extern u32 lbl_8064CF1C;
extern u32 lbl_8064CF18;
extern void* memset(void*, int, u32);

void fn_80125D88(void)
{
    lbl_8064CF1C = 0;
    lbl_8064CF18 = 0;
    memset(lbl_80500500, 0, 0x145E0);
}
