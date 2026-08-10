typedef signed short s16;

typedef struct GameState {
    unsigned char pad[0x40];
    int value_40;
} GameState;

extern GameState lbl_80300368;

extern int fn_8011E83C(void);
extern int fn_801A5CE0(void);
extern int fn_801A5D04(void);
extern int fn_8011E86C(void);
extern void fn_8016ADF0(s16, int, int);
extern int fn_8011E84C(void);
extern int fn_8011E85C(void);
extern int fn_80201B44();
extern void fn_801D0D30(void);
extern void fn_8011E26C(int);
extern void fn_80027F44(int);
extern void fn_80028198(void);
extern void fn_8016B400(int, int, int);
extern void fn_80144C40(void);

void fn_80006F30(s16 id, int mode)
{
    int active = 0;
    int result = fn_8011E83C();

    if (mode == 3) {
        if (fn_801A5CE0() == 0 && fn_801A5D04() == 0) {
            switch (fn_8011E86C()) {
            case 6:
            case 7:
            case 11:
            case 13:
            case 19:
            case 26:
            case 34:
            case 58:
                if (result > 0) {
                    fn_8016ADF0((s16)result, 100, -1);
                }
                if (result != 0) {
                    active = 1;
                }
                break;
            }
        }
    } else if (id == fn_8011E84C() && result != 0) {
        active = 1;
    }

    if (active != 0) {
        int state = fn_8011E85C();

        if (id == 2) {
            fn_80201B44();
            fn_801D0D30();
        }
        fn_8011E26C(1);

        switch (result) {
        case -2:
            if (state == 2) {
                lbl_80300368.value_40 = 0;
            } else {
                lbl_80300368.value_40 = 1;
            }
            if (mode == 3) {
                fn_80027F44(1);
            } else {
                fn_80028198();
            }
            break;
        case -1:
        case 0:
            break;
        default:
            fn_8016B400(result, 0, 0);
        }
        fn_80144C40();
    }
}
