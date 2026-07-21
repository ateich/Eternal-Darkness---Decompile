extern void* lbl_8064C5F8;
extern int lbl_8064C600;

extern void fn_801446B4(void*);
extern void fn_801446AC(void*, int);

void fn_8000738C(void)
{
    fn_801446B4(lbl_8064C5F8);
}

void fn_800073B0(void)
{
    fn_801446AC(lbl_8064C5F8, 1);
}

void fn_800073D8(void)
{
}

void fn_800073DC(int value)
{
    lbl_8064C600 = value;
}
