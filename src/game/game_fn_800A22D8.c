extern void fn_800A4C98(void*, void*, int);
extern void fn_800A4D04(void*, void*, int);

void fn_800A22D8(void* first, void* second, int enabled)
{
    if (enabled) {
        fn_800A4C98(first, second, enabled);
    } else {
        fn_800A4D04(first, second, enabled);
    }
}
