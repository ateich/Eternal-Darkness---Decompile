typedef signed int s32;

typedef struct Object {
    unsigned char pad_0[0x38];
    void *value;
} Object;

extern void *fn_80201B9C();
extern Object *fn_80204844(void *object, s32 kind);
extern void *fn_80201B8C();
extern s32 fn_8006BCE4(void *object);

s32 fn_8006D4DC(s32 value)
{
    s32 result = 0;
    Object *object = fn_80204844(fn_80201B9C(), 0x20);

    if (object != 0) {
        Object *entry = fn_80201B8C(object);
        if (entry->value != 0) {
            s32 actual = fn_8006BCE4(entry->value);
            if (actual == value) {
                result = 1;
            }
        }
    }
    return result;
}
