typedef unsigned int u32;
typedef unsigned long long u64;
extern u64 lbl_8064D3E0;
extern void fn_801B775C(void*, u32, u32);

void fn_801B78AC(void* voice)
{
    *(u64*)((unsigned char*)voice + 0x24) = lbl_8064D3E0;
    *(u64*)((unsigned char*)voice + 0x2C) = lbl_8064D3E0;
    fn_801B775C(voice, 0, 0);
    fn_801B775C(voice, 1, 0);
}
