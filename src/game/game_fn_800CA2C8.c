typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern void *fn_80201B8C(void *);
extern u32 fn_80036D5C(void *);
extern void *fn_80201B54(void *);
extern void fn_80036DA4(void *, u32);
extern void fn_8016B400(int, void *, int);

int fn_800CA2C8(void *object)
{
    u8 *info;
    u32 flags;
    void *model;
    int id;

    if (object != 0) {
        int has_id;
        info = fn_80201B8C(object);
        flags = fn_80036D5C(object);
        model = fn_80201B54(object);

        has_id = 0;
        if (info != 0 && *(void **)(info + 0x8C) != 0) {
            has_id = 1;
        }
        if (has_id != 0) {
            id = *(s16 *)(*(u8 **)(info + 0x8C) + 0x148);
        } else {
            id = 0;
        }
        if (id != 0 && id != -1 && (flags & 0x20) == 0) {
            fn_80036DA4(object, flags | 0x20);
            fn_8016B400(id, model, 0);
            return 1;
        }
    }
    return 0;
}
