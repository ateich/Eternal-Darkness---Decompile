typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void fn_80066754(s32 context, void *event, s32 *result);
extern u32 fn_8011FAEC(void *object);
extern s32 fn_80128EAC(void *object);
extern void fn_801A7470(void *event, u32 type);
extern u32 fn_801A7488(void *event);
extern void fn_801A7744(Vec3 *position, const void *event);
extern void *fn_80200C38(void **event);
extern u64 fn_8020123C(s32 type, s32 source, s32 target, s32 value);
extern u8 fn_80204578(void *context, const Vec3 *position);

void fn_80078310(void *context, s32 source, s32 target, void *object,
                 void **event, s32 *result)
{
    Vec3 position;

    if (fn_80128EAC(object) != 9) {
        fn_8020123C(0x74, source, target, 0);
        if (fn_8011FAEC(object) & 0x40) {
            void *entry = fn_80200C38(event);

            if ((s32)fn_801A7488(entry) == -1) {
                s32 type;
                u8 found;

                fn_801A7744(&position, entry);
                found = fn_80204578(context, &position);
                type = 0xC;
                if (found != 0) {
                    type = 0xB;
                }
                fn_801A7470(entry, type);
            }
            fn_80066754((s32)context, event, result);
        } else {
            fn_8020123C(0x74, source, source, 0);
        }
    }
}
