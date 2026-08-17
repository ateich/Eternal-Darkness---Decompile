extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern unsigned short lbl_8064B7E4[2];

unsigned short fn_800E4954(void)
{
    return lbl_8064B7E4[fn_800FBFB0() & 1];
}
