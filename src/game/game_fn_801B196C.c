typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8064D32D;
extern u8 lbl_8064D32C;
extern u32 lbl_8064D33C;
extern void fn_8021A468(u32);
extern void fn_8021A494(u32);

void fn_801B196C(u32 first, u32 second)
{
    lbl_8064D32D = (u8)first;
    lbl_8064D32C = (u8)second;
    if (lbl_8064D33C == 1) {
        fn_8021A468(first);
        fn_8021A494(second);
    }
}
