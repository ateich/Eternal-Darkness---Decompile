extern void (*lbl_8064D198)(void);

void fn_8015CA00(void (*callback)(void))
{
    lbl_8064D198 = callback;
}
