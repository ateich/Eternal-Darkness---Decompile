typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern s16 lbl_80243A40[];

s32 fn_80054BCC(s32 value)
{
    s32 different = 1;
    u32 i = 0;

    while (i < 62 && different != 0) {
        different = value != lbl_80243A40[i];
        i++;
    }

    return different;
}
