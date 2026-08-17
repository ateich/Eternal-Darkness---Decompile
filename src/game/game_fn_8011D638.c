extern int lbl_8064CE84;
extern int lbl_8064CE7C;

extern int fn_800B193C(void);
extern void fn_800B267C(short);
extern void fn_80144C40(void);
extern void fn_801E8B6C(int, int);

void fn_8011D638(int value)
{
    if (fn_800B193C() != 0) {
        fn_800B267C((short)value);
    } else {
        switch (lbl_8064CE84) {
        case 0:
            fn_801E8B6C(lbl_8064CE7C, value);
            break;
        }
    }
    fn_80144C40();
}
