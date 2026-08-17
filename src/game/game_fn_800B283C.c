typedef signed short s16;

extern int lbl_8064CDC8;
extern int fn_8017BB60(s16);
extern int fn_800B9460(void);
extern int fn_800B7EC0(void);
extern int fn_801A98F4(int, int);
extern int fn_800B194C(void);
extern int fn_800B1944(void);
extern void fn_800B3064(int);
extern void fn_800B3178(int, int);
extern void fn_800B3304(int, int);
extern void fn_800B34CC(int, int);
extern void fn_800B35AC(int, int, int);
extern void fn_800B36FC(int);
extern void fn_800B376C(int, int);
extern void fn_800B3898(int, int);
extern void fn_800B39A8(int, int);
extern void fn_800B3AF8(int, int);
extern void fn_800B3B90(int, int);
extern void fn_800B3C78(int, int);
extern void fn_800B3DB0(int, int);
extern void fn_800B3F24(void);
extern void fn_800B3F58(int);
extern void fn_800B3FC4(int);
extern void fn_800B4028(int);
extern void fn_800B4098(int, int);
extern void fn_800B40FC(int, int);
extern void fn_800B41CC(int, int);
extern void fn_800B4268(int);
extern void fn_800B4308(int);
extern void fn_800B433C(int);
extern void fn_800B43B4(int);
extern void fn_800B442C(int);
extern void fn_800B447C(int);
extern void fn_800B44CC(int);
extern void fn_800B451C(int);
extern void fn_800B4558(int);
extern void fn_800B4594(int);
extern void fn_800B45D0(int);
extern void fn_800B4818(void);
extern void fn_800B4844(int);
extern void fn_800B48E4(int);
extern void fn_800B4938(int);
extern void fn_800B4990(int, int);
extern void fn_800B4A48(int, int);
extern void fn_800B4ABC(int, int);

void fn_800B283C(s16 input)
{
    int special;
    int value;

    if (fn_8017BB60(input) != 0) {
        return;
    }
    if (fn_800B9460() != 0) {
        return;
    }
    special = lbl_8064CDC8 == 3;
    value = fn_800B7EC0();
    if (special) {
        fn_801A98F4(611, 50);
    }

    switch (fn_800B194C()) {
    case 0: fn_800B3064(0); break;
    case 1: case 2: fn_800B3178(value, 0); break;
    case 3: fn_800B3304(value, 0); break;
    case 6: fn_800B34CC(value, 1); break;
    case 4: case 5: fn_800B35AC(value, 1, 1); break;
    case 8: case 9: case 16: case 21: fn_800B3DB0(value, 3); break;
    case 10: fn_800B3F24(); break;
    case 11: fn_800B3F58(2); break;
    case 13: fn_800B36FC(2); break;
    case 14: fn_800B3898(value, 2); break;
    case 18: case 20: case 22: case 25: case 29:
        if (fn_800B1944() == 3) {
            fn_800B376C(value, 2);
        } else {
            fn_800B376C(value, 1);
        }
        break;
    case 30: case 31: case 38: case 39: fn_800B39A8(value, 3); break;
    case 32: case 33: fn_800B3AF8(value, 2); break;
    case 15: case 17: case 19: case 23: case 24: case 27: case 28:
        fn_800B3B90(value, 1); break;
    case 26: fn_800B3C78(value, 1); break;
    case 34: fn_800B3FC4(2); break;
    case 35: fn_800B4028(2); break;
    case 36: fn_800B4098(value, 2); break;
    case 37: fn_800B40FC(value, 2); break;
    case 40: case 41: case 42: case 43: fn_800B41CC(value, 2); break;
    case 86: fn_800B4990(value, 2); break;
    case 87: fn_800B4A48(value, 2); break;
    case 88: fn_800B4ABC(value, 2); break;
    case 89: fn_800B45D0(value); break;
    case 91: case 92: case 93: fn_800B4818(); break;
    case 44: case 45: fn_800B4268(value); break;
    case 46: case 47: case 48: case 49: fn_800B4308(value); break;
    case 50: case 51: case 52: case 53: fn_800B433C(value); break;
    case 54: case 55: case 56: case 57: fn_800B43B4(value); break;
    case 58: case 59: case 60: case 61: fn_800B442C(value); break;
    case 62: case 63: case 64: case 65: case 66: fn_800B447C(value); break;
    case 67: case 68: case 69: case 70: case 71: fn_800B44CC(value); break;
    case 72: case 73: case 74: case 75: case 76: fn_800B451C(value); break;
    case 77: case 78: case 79: case 80: fn_800B4558(value); break;
    case 81: case 82: case 83: case 84: case 85: fn_800B4594(value); break;
    case 95: fn_800B4844(value); break;
    case 96: fn_800B4938(value); break;
    case 97: fn_800B48E4(value); break;
    }
}
