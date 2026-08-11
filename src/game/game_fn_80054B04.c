typedef signed int s32;

extern void* lbl_8024E388[];

extern s32 fn_80045240(s32);
extern void fn_80054A04(s32);
extern void fn_801E7974(void*, s32);

void fn_80054B04(void)
{
    s32 first = 0;
    s32 second = 0;
    s32 third = 0;

    if (fn_80045240(1) != 0) {
        fn_80054A04(1);
        first = 1;
    }

    if (fn_80045240(2) != 0) {
        fn_80054A04(2);
        second = 1;
    }

    if (fn_80045240(3) != 0) {
        fn_80054A04(3);
        third = 1;
    }

    if (first != 0 && second != 0 && third != 0) {
        fn_801E7974(lbl_8024E388[0], 0x35);
    }
}
