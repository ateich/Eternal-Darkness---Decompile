typedef unsigned char u8;

extern void* lbl_8064D348;
extern void* lbl_8064D344;
extern void* lbl_8064D340;
extern int lbl_8064D33C;
extern int lbl_8064D338;
extern int lbl_8064D334;
extern int lbl_8064D330;
extern u8 lbl_8064D32D;
extern u8 lbl_8064D32C;

extern void fn_801B1344(void);
extern void fn_8021A140(void (*)(void));
extern void fn_8021A184(void);
extern void fn_8021A1A8(int);
extern void fn_8021A468(int);
extern void fn_8021A494(int);

void fn_801B1440(void)
{
    lbl_8064D348 = 0;
    lbl_8064D344 = 0;
    lbl_8064D340 = 0;
    lbl_8064D33C = 0;
    lbl_8064D338 = 0;
    lbl_8064D334 = 0;
    lbl_8064D330 = 48000;
    lbl_8064D32D = 255;
    lbl_8064D32C = 255;
    fn_8021A468(0);
    fn_8021A494(0);
    fn_8021A140(fn_801B1344);
    fn_8021A184();
    fn_8021A1A8(0);
}
