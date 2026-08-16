extern void* lbl_80331720[6];
extern int lbl_8064CCC4;
extern int fn_801E8D34(void*);

int fn_8010B33C(int offset)
{
    int value = offset + 2 * fn_801E8D34(lbl_80331720[1]);
    int result = 0;
    if (value < lbl_8064CCC4 && value >= 0) {
        result = 1;
    }
    return result;
}
