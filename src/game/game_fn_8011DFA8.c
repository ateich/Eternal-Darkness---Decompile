extern void* lbl_8064CE94;
extern void* lbl_8064CE98;
extern int lbl_8064B9C0;

extern void* fn_801E6CA0(void*, int, int, int, int);

void fn_8011DFA8(void)
{
    if (lbl_8064B9C0 != -1) {
        lbl_8064CE98 = fn_801E6CA0(lbl_8064CE94, 0, lbl_8064B9C0, 0, 1);
    }
}
