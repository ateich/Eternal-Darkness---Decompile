typedef signed short s16;

extern int lbl_8064CDC8;
extern int fn_8017BB60(s16);
extern int fn_800B9460(void);
extern int fn_800B194C(void);
extern int fn_800B1944(void);
extern void fn_800B8E28(s16);
extern void fn_800B7E44(int, int);
extern void fn_800B692C(s16);

void fn_800B2778(s16 value)
{
    int state;

    if (fn_8017BB60(value) != 0) {
        return;
    }
    if (fn_800B9460() != 0) {
        return;
    }

    state = fn_800B194C();
    switch (state) {
    case 6:
    case 34:
    case 35:
        fn_800B8E28(-value);
        break;
    case 1:
    case 2:
        if (lbl_8064CDC8 != 3 && fn_800B1944() == 0) {
            fn_800B7E44(value < 0, 0);
        }
        break;
    case 3:
        fn_800B692C(-value);
        break;
    }
}
