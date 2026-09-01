typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 lbl_8064D370;
extern s32 lbl_8064D354;
extern s32 lbl_8064D364;
extern u8 lbl_8064D358;
extern void* fn_801AD4B4(s32, s32, s32, s32);
extern void fn_801AD46C(u8*, s32);
extern void fn_801AD404(u32, u32, s32);

void fn_801B1B0C(s32 value, u32 kind)
{
    u8 current;

    if (fn_801AD4B4(value, 0, 0, 0) != 0) {
        fn_801AD46C(&current, 0);
        if (current != (u8)kind) {
            fn_801AD404(kind, kind, 3);
        }
        lbl_8064D370++;
        lbl_8064D354 = 0;
        lbl_8064D364 = value;
        lbl_8064D358 = kind;
    }
}
