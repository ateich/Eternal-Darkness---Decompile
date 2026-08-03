typedef int s32;

extern void* lbl_8064C4E0;

extern s32 fn_801E79FC(void*, s32);
extern void fn_801E79A0(void*, s32);
extern s32 fn_8006BE44(void);
extern void fn_800B9454(s32, s32);

s32 fn_8001A594(void)
{
    if (!fn_801E79FC(lbl_8064C4E0, 0x345) &&
        fn_801E79FC(lbl_8064C4E0, 0x34D) && fn_8006BE44() < 2) {
        fn_801E79A0(lbl_8064C4E0, 0x34D);
    }
    fn_800B9454(8, 0);
    return 0;
}
