typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8061A494[];
extern u32 lbl_8061A4D4[];
extern u8 lbl_8061A4F4[];
extern u8 lbl_8064D3BC;
extern u8 lbl_8064D3AC;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801CCFC0(int, int, int);

void fn_801B9170(int arg0, int arg1, int arg2)
{
    fn_801CE2B8();
    {
        int zero;
        u8 index;
        index = (u8)arg0;
        zero = 0;
        lbl_8061A494[index] = zero;
        lbl_8061A4D4[index] = zero;
        (&lbl_8064D3BC)[index] = 0xFF;
        (&lbl_8064D3AC)[index] = 0xFF;
        lbl_8061A4F4[index * 2 + 1] = zero;
        lbl_8061A4F4[index * 2] = zero;
    }
    fn_801CCFC0(arg0, arg1, arg2);
    fn_801CE280();
}
