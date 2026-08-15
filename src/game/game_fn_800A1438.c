typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Target800A1438 {
    u8 pad00[0x38];
    u32 value;
} Target800A1438;

typedef struct Context800A1438 {
    u8 pad00[0x15];
    u8 count;
    u8 pad16[0xAE];
    Target800A1438* target;
} Context800A1438;

extern int fn_80070A6C(int);
extern int fn_800462C8(int);
extern void* fn_80201B9C();
extern void* fn_80204844(void*, int);
extern Context800A1438* fn_8006D444(void);
extern void* fn_80201B54();
extern int fn_80070CD8(int);
extern int fn_801E79FC(void*, int);
extern void fn_801E79A0(void*, int);
extern u64 fn_8020123C();
extern void* lbl_8064C4E0;

int fn_800A1438(void)
{
    int result = 0;
    void* object;
    Context800A1438* context;
    void* actor;

    if (fn_80070A6C(0x20) == 0) {
        if (fn_800462C8(0) == 0x22) {
            result = 1;
        } else {
            object = fn_80204844(fn_80201B9C(), 0x20);
            context = fn_8006D444();
            actor = fn_80201B54(object);
            if (fn_80070CD8(1) != 0 && fn_800462C8(0) == 0 &&
                fn_801E79FC(lbl_8064C4E0, 0x466) != 0 && context->count >= 2) {
                fn_8020123C(0x52, 0, actor, 0);
                context->target->value = 0x22;
                if ((u32)(fn_8020123C(0x53, 0, actor, &context->target->value) &
                          0xFFFFFFFFULL) == 1 &&
                    (u32)(fn_8020123C(0x54, 0, actor, 0) & 0xFFFFFFFFULL) == 1) {
                    result = 1;
                    fn_801E79A0(lbl_8064C4E0, 0x466);
                }
            }
        }
    }
    return result;
}
