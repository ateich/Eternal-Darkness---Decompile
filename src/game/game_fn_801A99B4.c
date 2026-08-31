typedef unsigned int u32;

extern volatile u32 lbl_8064D5A8;

extern void fn_801A9CDC(void);
extern void fn_801AC0FC(void);
extern void fn_801AAB38(void);
extern void fn_801AD08C(void);
extern void fn_801AA9F8(void);
extern void fn_801B02F0(void);
extern void fn_801B1BA0(void);
extern void fn_801B0E6C(void);

void fn_801A99B4(void)
{
    fn_801A9CDC();
    fn_801AC0FC();
    fn_801AAB38();
    fn_801AD08C();
    fn_801AA9F8();
    fn_801B02F0();
    fn_801B1BA0();

    if ((lbl_8064D5A8 & 0x1F) == 0) {
        fn_801B0E6C();
    }
}
