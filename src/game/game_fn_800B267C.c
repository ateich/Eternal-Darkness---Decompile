typedef signed short s16;

extern int lbl_8064CDC8;
extern int fn_8017BB60(s16);
extern int fn_800B9460(void);
extern int fn_800B194C(void);
extern int fn_800B1944(void);
extern void fn_800B689C(int, int);
extern void fn_800B7E44(int, int);
extern void fn_800B8E28(s16);

void fn_800B267C(s16 value)
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
    case 0:
        fn_800B689C(value > 0, 0);
        break;
    case 1:
    case 2:
        if (lbl_8064CDC8 == 3 || fn_800B1944() != 0) {
            fn_800B7E44(value > 0, 0);
        }
        break;
    case 4:
    case 5:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 19: case 20: case 21:
    case 22: case 23: case 24: case 25: case 26: case 27: case 28:
    case 29: case 30: case 31: case 32: case 33:
    case 36: case 37: case 38: case 39: case 40: case 41: case 42:
    case 43:
    case 81: case 82: case 83: case 84: case 85: case 86: case 87:
    case 88:
        fn_800B8E28(value);
        break;
    }
}
