typedef unsigned char u8;

extern float lbl_8064CF04;
extern float lbl_8064F32C;
extern float lbl_8064F330;
extern int fn_80128408(void);
extern void *fn_800CEC24(int, int, void *, void *, int, void *, float, float,
                         float);
extern int fn_80201B54();
extern void fn_8020104C(int, int, int, int, float);

#pragma use_lmw_stmw on
void fn_800CEB10(int kind, int value, void *first, void *second, int mode,
                 u8 count, void *data, float x, float y, float z)
{
    int available = fn_80128408();

    if (lbl_8064CF04 < lbl_8064F32C && available > 24) {
        u8 limit;
        u8 i;

        if (available - 24 < count) {
            count = available - 24;
        }
        limit = count;
        for (i = 0; i < limit; i++) {
            void *object = fn_800CEC24(kind, value, first, second, mode, data,
                                       x, y, z);
            if (object != 0) {
                int linked = fn_80201B54(object);
                fn_8020104C(0xDF, linked, linked, 0, lbl_8064F330);
            }
        }
    }
}
