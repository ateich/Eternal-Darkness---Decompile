extern void* lbl_8064D074;

int fn_80144608(void* value)
{
    if (lbl_8064D074 == 0) {
        lbl_8064D074 = value;
        return 1;
    }
    return 0;
}
