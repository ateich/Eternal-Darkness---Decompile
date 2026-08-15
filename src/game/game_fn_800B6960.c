typedef signed short s16;

#pragma use_lmw_stmw on

extern void* lbl_8064CA24;

extern int fn_801E8D44(void*);
extern int fn_801E8D4C(void*);
extern int fn_800B1AA0(int);
extern void fn_801E8B24();

void fn_800B6960(int value, int mode)
{
    s16 offset;
    s16 limit;
    s16 width;
    s16 half_width;
    int previous;

    if (lbl_8064CA24 != 0) {
        offset = 0;
        limit = fn_801E8D44(lbl_8064CA24) + 1;
        width = fn_801E8D4C(lbl_8064CA24);
        half_width = width >> 1;
        if (mode != 0) {
            previous = fn_800B1AA0(mode);
        }
        if (value > half_width) {
            offset = value - half_width;
        }
        if ((s16)offset + width > limit) {
            offset -= (s16)((s16)offset + width - limit);
        }
        fn_801E8B24(lbl_8064CA24, value, offset);
        if (mode != 0) {
            fn_800B1AA0(previous);
        }
    }
}
