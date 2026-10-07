typedef unsigned char u8;
typedef signed int s32;

extern s32 lbl_8064C814;
extern void fn_80047240(s32 value);

u8 fn_8004736C(s32 value)
{
    u8 previous = lbl_8064C814;

    lbl_8064C814 = value;
    fn_80047240(value);
    return previous;
}
