typedef int s32;

extern s32 lbl_8064C674;
extern float lbl_8064C678;
extern float lbl_8064C67C;
extern s32 lbl_8064C680;
extern s32 lbl_8064C684;
extern s32 lbl_8064C688;
extern s32 lbl_8064C68C;
extern s32 lbl_8064C690;
extern s32 lbl_8064C694;
extern s32 lbl_8064C698;
extern s32 lbl_8064C6A4[2];
extern const float lbl_8064DEA8;
extern const float lbl_8064DEAC;

extern void fn_801AD404(s32, s32, s32);
extern void fn_801AD490(void);

void fn_8001DA7C(void)
{
    lbl_8064C6A4[0] = -1;
    lbl_8064C6A4[1] = -1;
    lbl_8064C698 = 0;
    lbl_8064C694 = 0;
    lbl_8064C690 = 1;
    lbl_8064C68C = 0;
    lbl_8064C688 = -1;
    lbl_8064C684 = -1;
    lbl_8064C680 = 0;
    lbl_8064C67C = lbl_8064DEA8;
    lbl_8064C678 = lbl_8064DEAC;
    lbl_8064C674 = 0;
    fn_801AD404(0, 0, 5);
    fn_801AD490();
    fn_801AD404(100, 100, 1);
}
