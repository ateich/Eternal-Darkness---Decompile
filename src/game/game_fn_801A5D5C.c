extern void* lbl_8064D264;
extern void* lbl_8064D268;
extern void fn_801446AC(void*, int);
extern void fn_801446B4(void*);
extern void fn_801A5E30(int*);

void fn_801A5D5C(int* state, int mode)
{
    if (mode == 1 || mode == 2) {
        fn_801A5E30(state);
        state[1] = 0;
        state[0] = 0;
        fn_801446AC(lbl_8064D264, 0);
        fn_801446B4(lbl_8064D268);
    }
}
