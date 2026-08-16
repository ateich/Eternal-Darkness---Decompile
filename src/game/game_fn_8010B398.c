extern void* lbl_80331720[6];
extern int lbl_8064CCC4;
extern int fn_801E8D34(void*);
extern void fn_801E8B24(void*, int, int);

int fn_8010B398(int offset)
{
    if (2 * offset + fn_801E8D34(lbl_80331720[0]) >= lbl_8064CCC4) {
        fn_801E8B24(lbl_80331720[0], 0, 0);
    }
    return 1;
}
