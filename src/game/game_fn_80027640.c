typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u32 lbl_8064C6F8;
extern s32 lbl_8064C5E8;
extern s32 lbl_8064C704;
extern s32 lbl_8064C708;

extern u32* fn_801E5D20(u32);
extern void fn_801E5FB0(u32);
extern void fn_80144C40(void);
extern void fn_80144680(u32);
extern void fn_80045B3C(s32);
extern void fn_8016B400(s32, s32, s32);
extern void fn_80028198(void);

void fn_80027640(s16 value, u32 handle)
{
    s32 next;

    if (lbl_8064C6F8 == 0) {
        return;
    }

    if (handle != 0) {
        if (value != 0) {
            if ((*fn_801E5D20(handle) & 0x4000) == 0) {
                return;
            }
            fn_801E5FB0(handle);
        } else {
            u32 flags = *fn_801E5D20(handle);
            if ((flags & 0x4000) == 0) {
                return;
            }
            if ((flags & 8) == 0) {
                return;
            }
            fn_801E5FB0(handle);
        }
    }

    fn_80144C40();
    fn_80144680(lbl_8064C6F8);
    lbl_8064C6F8 = 0;
    if (lbl_8064C5E8 != 3) {
        fn_80045B3C(0);
    }

    next = lbl_8064C704;
    lbl_8064C708 = value;
    if (next > 0) {
        fn_8016B400(next, 0, 0);
        return;
    }
    switch (next) {
    case -2:
        fn_80028198();
        break;
    }
}
