typedef signed int s32;

extern float lbl_80650A60;
extern float lbl_80650A64;
extern float lbl_80650A68;
extern s32 lbl_8064D240;
extern s32 lbl_8064D244;

void fn_8018807C(float first, float second)
{
    if (first > lbl_80650A60 || second > lbl_80650A60) {
        ++lbl_8064D240;
        if (lbl_8064D240 > 3) {
            lbl_8064D244 -= 50;
            if (lbl_8064D244 < 150) {
                lbl_8064D244 = 150;
            }
            lbl_8064D240 = 3;
        }
        return;
    }

    if (first < lbl_80650A64 && second < lbl_80650A64) {
        s32 value = 1000;
        if (lbl_8064D244 < 1000) {
            value = lbl_8064D244 + 10;
        }
        lbl_8064D244 = value;
        lbl_8064D240 = 0;
        return;
    }

    if (lbl_80650A68 == first && lbl_80650A68 == second) {
        lbl_8064D240 = 0;
        lbl_8064D244 = 1000;
    }
}
