typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8064C368;
extern u32 lbl_8064D5E8;
extern float lbl_8064DF38;
extern char lbl_806391F0[];

extern void fn_8022CE20(void);
extern void fn_8022DA54(float);
extern void fn_8020EF80(void*);

void fn_800243E8(void)
{
    if (lbl_8064C368 == 0 && (lbl_8064D5E8 & 1) == 0) {
        fn_8022CE20();
        fn_8022DA54(lbl_8064DF38);
    }
    fn_8020EF80(lbl_806391F0);
}
