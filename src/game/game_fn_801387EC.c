extern void* lbl_8064C4E4;
extern int lbl_8064D008;

extern void fn_80138F78(int);
extern void fn_801399CC(short);
extern void fn_8011F7E0(void*, int);
extern void fn_8011FC38(void*, int, int);
extern void fn_8012B344();
extern void fn_8011FE6C(void*);

void fn_801387EC(int value)
{
    fn_80138F78(0);
    if (lbl_8064C4E4 != 0) {
        fn_801399CC((short)lbl_8064D008);
        fn_8011F7E0(lbl_8064C4E4, 0);
        fn_8011FC38(lbl_8064C4E4, value, 1);
        fn_8012B344(lbl_8064C4E4);
        fn_8011FE6C(lbl_8064C4E4);
    }
}
