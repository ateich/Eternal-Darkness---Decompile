typedef signed int s32;

extern s32 lbl_8064C89C;
extern s32 fn_800680C0(void *object, s32 excluded_id);

s32 fn_800681A0(void *object, s32 excluded_id)
{
    lbl_8064C89C = 0;
    return fn_800680C0(object, excluded_id);
}
