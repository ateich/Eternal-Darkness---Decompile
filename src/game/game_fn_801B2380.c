typedef int s32;

extern s32 lbl_8064D374;
extern s32 lbl_8064D378;
extern s32 lbl_8064D364;
extern s32 lbl_8064D354;
extern s32 fn_801AD72C(void);

void fn_801B2380(s32 group)
{
    s32 current;

    if (group == 1) {
        if (lbl_8064D374 == 2) {
            lbl_8064D374 = 1;
            current = fn_801AD72C();
            if (lbl_8064D364 != current) {
                lbl_8064D354 = 1;
                lbl_8064D364 = -2;
            }
        }
    } else if (lbl_8064D378 == 2) {
        lbl_8064D378 = 1;
        current = fn_801AD72C();
        if (lbl_8064D364 != current) {
            lbl_8064D354 = 1;
            lbl_8064D364 = -2;
        }
    }
}
