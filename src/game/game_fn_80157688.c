extern void* fn_801E880C(void*, int, int);
extern void* lbl_8064D100;

void* fn_80157688(int index, int value)
{
    if (index < 0) {
        return 0;
    }
    return fn_801E880C(lbl_8064D100, index, value);
}
