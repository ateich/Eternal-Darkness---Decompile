extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern int lbl_8064B7D0;
extern unsigned short *lbl_8064CAE4;

/* NonMatching: size and relocations match; MWCC assigns the divisor/table
 * live ranges to r4/r5 in the opposite order (98.333336%). */

unsigned short fn_800E4918(void)
{
    int value = fn_800FBFB0();
    int count = lbl_8064B7D0;
    unsigned short *table = lbl_8064CAE4;
    return table[(unsigned short)(value % count)];
}
