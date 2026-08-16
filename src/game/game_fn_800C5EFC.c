typedef unsigned int u32;
typedef signed short s16;

extern int fn_80200C38();
extern int fn_80200C10(void *);
extern u32 fn_801A7530(void *);
extern s16 fn_801A74F8(void *);
extern void *fn_801A7498(void *);
extern unsigned long long fn_8020123C();

void fn_800C5EFC(void *context, void *object)
{
    void *data;
    u32 flags;
    s16 count;
    void *value;

    data = (void *)fn_80200C38(object);
    if (data != 0 && fn_80200C10(object) == 0x27) {
        flags = fn_801A7530(data);
        count = fn_801A74F8(data);
        value = fn_801A7498(data);
        if ((flags & 2) != 0 && count > 0) {
            fn_8020123C(0xC9, context, value, 1);
        }
    }
}
