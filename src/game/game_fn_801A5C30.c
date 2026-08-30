extern void* lbl_8064D264;
extern void* lbl_8064D268;
extern void* lbl_8064D26C;

extern int* fn_801446F4(void*);
extern void fn_801446AC(void*, int);
extern void fn_801446B4(void*);
extern void fn_8015C8A4(int, int);
extern void fn_801A5E68(int*, int);
extern void fn_801A64F8(void);

void fn_801A5C30(int enabled)
{
    int* state = fn_801446F4(lbl_8064D264);

    fn_801A5E68(state, 1);
    fn_801446B4(lbl_8064D268);
    if (enabled != 0) {
        fn_801446AC(lbl_8064D26C, 0);
        fn_801446AC(lbl_8064D264, 0);
    } else {
        fn_801446B4(lbl_8064D264);
        fn_801446B4(lbl_8064D26C);
        *state = 0;
        fn_801A64F8();
    }

    if (enabled == 1) {
        fn_8015C8A4(2, 0);
    } else {
        fn_8015C8A4(2, 1);
    }
}
