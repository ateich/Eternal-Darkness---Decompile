extern int lbl_80607C00[];

int fn_801A6E5C(void)
{
    int count = lbl_80607C00[3];
    int result = 0;

    if (count > 0) {
        if (count > lbl_80607C00[2]) {
            result = 1;
        } else {
            result = 2;
        }
    }
    return result;
}
