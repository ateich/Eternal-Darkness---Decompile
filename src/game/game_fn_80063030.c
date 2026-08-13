typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern void *fn_80201B9C();
extern void *fn_80201814();
extern int fn_80201EB8();
extern u8 fn_80204508(void *first, void *second);
extern s32 fn_80204180(void *first, void *second);
extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void *fn_80201BC0(void *object);

s32 fn_80063030(s32 context, s32 value)
{
    s32 object_group;
    void *current;
    void *object;

    current = fn_80201B9C();
    object = fn_80201814(value);

    while (current != 0 && object != 0) {
        object_group = fn_80201EB8(object);

        if (fn_80201EB8(current) != object_group) {
            /* Different groups do not interact. */
        } else if (current != object) {
            u8 compatible = fn_80204508(current, object);
            s32 distance = fn_80204180(object, current);

            if (compatible != 0 && distance != -1 && distance < 200) {
                object_group = fn_80201B54(current);
                fn_8020123C(0x37, fn_80201B54(object), object_group, 0);
            }
        }
        current = fn_80201BC0(current);
    }

    return 1;
}
