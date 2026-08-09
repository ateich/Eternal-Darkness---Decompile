typedef float f32;

typedef f32 Mtx[3][4];

extern f32 lbl_8064C65C;
extern f32 lbl_8064C660;
extern const f32 lbl_8064DEA8;
extern const f32 lbl_8064DEE0;
extern const f32 lbl_8064DEE4;
extern const f32 lbl_8064DEE8;

extern void fn_80211484(Mtx, f32, f32, f32);
extern void fn_80210FDC(Mtx, Mtx, Mtx);
extern void fn_8022B748(Mtx, int, int);

void fn_80021714(void)
{
    Mtx translation;
    Mtx scale;

    fn_80211484(translation, lbl_8064DEA8, lbl_8064DEA8, lbl_8064DEA8);

    scale[0][0] = lbl_8064DEE4;
    scale[0][1] = lbl_8064DEA8;
    scale[0][2] = lbl_8064DEA8;
    scale[0][3] = lbl_8064DEA8;
    scale[1][0] = lbl_8064DEA8;
    scale[1][1] = lbl_8064DEE4;
    scale[1][2] = lbl_8064DEA8;
    scale[1][3] = lbl_8064DEA8;
    scale[2][0] = lbl_8064DEA8;
    scale[2][1] = lbl_8064DEA8;
    scale[2][2] = lbl_8064DEA8;
    scale[2][3] = lbl_8064DEA8;

    lbl_8064C65C += lbl_8064DEE8;
    if (lbl_8064C65C > lbl_8064DEE0) {
        lbl_8064C65C -= lbl_8064DEE0;
    }
    if (lbl_8064C660 > lbl_8064DEE0) {
        lbl_8064C660 -= lbl_8064DEE0;
    }

    fn_80211484(translation, -lbl_8064C65C, -lbl_8064C660, lbl_8064DEA8);
    fn_80210FDC(scale, translation, scale);
    fn_8022B748(scale, 0x21, 1);
}
