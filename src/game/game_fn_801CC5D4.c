typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8064D4E6;
extern u8 lbl_8064D4E7;
extern u32 lbl_8064D4B0;

extern void fn_801CC468(void);
extern void fn_801CE250(void);
extern u32 fn_801CDF50(void (*callback)(void), u32 flags, void* config);
extern u32 fn_801C40D4(u8 count, u8 arena_count, int enable);
extern u32 fn_801CE09C(u32 flags);
extern void fn_801CE280(void);
extern void fn_801CE01C(void);

int fn_801CC5D4(void* config, u32 count, u32 arena_count, u32 flags)
{
    fn_801CE250();
    lbl_8064D4E7 = 0;
    lbl_8064D4E6 = 0;
    lbl_8064D4B0 = 0;
    if (fn_801CDF50(fn_801CC468, flags, config) != 0 &&
        fn_801C40D4(count, arena_count, (flags & 1) != 0) != 0 &&
        fn_801CE09C(flags) != 0) {
        fn_801CE280();
        fn_801CE01C();
        return 0;
    }
    return -1;
}
