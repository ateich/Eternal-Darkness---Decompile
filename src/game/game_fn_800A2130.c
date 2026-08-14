typedef signed short s16;

extern void* fn_80201B8C(void*);
extern void fn_80038308(void*, int, s16*);
extern void fn_80038464(void*, int, s16*);

int fn_800A2130(void* object)
{
    s16 second;
    s16 first;
    int value;
    int result;

    fn_80201B8C(object);
    fn_80038308(object, 0, &first);
    fn_80038464(object, 0, &second);
    value = (int)(100.0f * first / second);

    if (value <= 0) {
        result = 3;
    } else if (value <= 0x22) {
        result = 2;
    } else if (value <= 0x43) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
