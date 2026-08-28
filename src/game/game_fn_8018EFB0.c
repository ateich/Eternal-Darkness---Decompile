typedef signed short s16;
typedef unsigned short u16;

extern int fn_800FBFB0(void);

void fn_8018EFB0(s16* values, u16 amount, int index)
{
    values[index] += amount - (fn_800FBFB0() & ((amount << 1) - 1));
}
