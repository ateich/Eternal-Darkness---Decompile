typedef int s32;

extern s32 lbl_8064D374;
extern s32 lbl_8064D378;

void fn_801B2348(s32 group)
{
    if (group == 1) {
        if (lbl_8064D374 == 1) {
            lbl_8064D374 = 2;
        }
    } else if (lbl_8064D378 == 1) {
        lbl_8064D378 = 2;
    }
}
