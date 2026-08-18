extern void fn_801E7DC8(int);
extern unsigned int lbl_8064D0B8;

#pragma opt_propagation off

void fn_80155B5C(int count)
{
    unsigned int b;
    unsigned int a;
    unsigned int c;

    fn_801E7DC8(7);
    a = count * 40;
    b = count * 104;
    c = count * 44;
    b = a + b;
    a = b + c;
    lbl_8064D0B8 = a + 44;
    fn_801E7DC8(256);
}
