extern void* lbl_8064D264;
extern void* lbl_8064D268;
extern int lbl_8064D5A8;
extern void fn_801446AC(void*, int);
extern void fn_801446B4(void*);

void fn_801A5DBC(void* unused, int* state)
{
    int saved = lbl_8064D5A8;
    state[0] = 1;
    fn_801446AC(lbl_8064D268, 0);
    fn_801446B4(lbl_8064D264);
    state[11] = saved;
}
