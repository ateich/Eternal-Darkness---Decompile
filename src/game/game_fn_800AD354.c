extern int lbl_803003C8[];
extern void* fn_8000696C(void);

int fn_800AD354(void)
{
    int result = 1;
    if (lbl_803003C8[2] == 13 && fn_8000696C() != 0) {
        result = 0;
    }
    return result;
}
