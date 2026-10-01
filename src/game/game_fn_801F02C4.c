typedef struct FloatTriple {
    float x;
    float y;
    float z;
} FloatTriple;

extern int lbl_8064D6C0;
extern float lbl_8064D6C8;
extern float lbl_8064D6CC;
extern int lbl_8064D6D0;
extern float lbl_8064D6D4;
extern int lbl_8064D6D8;

extern FloatTriple* fn_8015AB00(int);

void fn_801F02C4(void)
{
    FloatTriple* value;

    if (lbl_8064D6D8 == 0 && lbl_8064D6C0 == 0) {
        value = fn_8015AB00(2);
        if (value != 0) {
            if (lbl_8064D6D0 != 0) {
                lbl_8064D6D0--;
                if (lbl_8064D6D0 == 0) {
                    value->x = lbl_8064D6D4;
                    lbl_8064D6D0 = 0;
                    lbl_8064D6D4 = 0.0f;
                } else {
                    value->x += (lbl_8064D6D4 - value->x) / (float)lbl_8064D6D0;
                }
            }

            lbl_8064D6C8 += value->y;
            if (lbl_8064D6C8 > 1600.0f) {
                lbl_8064D6C8 -= 1600.0f;
            }

            lbl_8064D6CC += value->z;
            if (lbl_8064D6CC > 1600.0f) {
                lbl_8064D6CC -= 1600.0f;
            }
        }
    }
}
