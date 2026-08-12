typedef signed int s32;

extern void *fn_80201BC8(s32 context);
extern s32 fn_8012DC94(void *object, s32 index);
extern s32 fn_80066BB8(void *object, s32 index);

s32 fn_80066D04(s32 context, s32 index)
{
    s32 result;
    void *object;

    object = fn_80201BC8(context);
    result = 1;
    if (object != 0) {
        s32 valid = 0;
        if (fn_8012DC94(object, index) && fn_80066BB8(object, index)) {
            valid = 1;
        }
        result = valid;
    }
    return result;
}
