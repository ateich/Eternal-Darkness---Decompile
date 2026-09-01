typedef unsigned char u8;

extern int lbl_8064D330;
extern void* lbl_8064D348;
extern u8 lbl_8060BF90[];

extern void fn_801B1204(int);
extern void fn_8021A19C(int);
extern void fn_80215A64(void*, void (*)(int));

void fn_801B1344(int value)
{
    fn_8021A19C(value + lbl_8064D330);
    if (lbl_8064D348 != 0) {
        fn_80215A64(lbl_8060BF90, fn_801B1204);
    }
}
