typedef signed short s16;
typedef unsigned int u32;

extern void *fn_800DE3F8(void *);
extern int fn_80201B44();
extern unsigned long long fn_8020123C();
extern int fn_80038308(void *, int, s16 *);
extern int fn_80038464(void *, int, s16 *);
extern void fn_800389E0(void *, int, s16, int);

void fn_800E0330(void *object)
{
    void *value = fn_800DE3F8(object);

    if (value != 0) {
        int id = fn_80201B44(value);
        u32 result = fn_8020123C(0x3B, id, value, 0) & 0xFFFFFFFFULL;

        if (result != 0) {
            s16 first;
            s16 second;
            fn_80038308(object, 0, &first);
            fn_80038464(object, 0, &second);
            fn_800389E0(object, 0, second, 0);
        }
    }
}
