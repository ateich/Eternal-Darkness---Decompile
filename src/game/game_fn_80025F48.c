typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

typedef struct ObjectInfo {
    unsigned char pad_00[0x38];
    void* owner;
} ObjectInfo;

typedef struct Owner {
    unsigned char pad_00[0xC4];
    s32* state;
} Owner;

extern void* lbl_8064C4E0;
extern const f32 lbl_8064DF50;

extern void fn_801E79A0(void*, s32);
extern int fn_801E79FC(void*, int);
extern s32 fn_800462C8(s32);
extern void* fn_80201B9C();
extern void* fn_80204844(void*, int);
extern int fn_80201B54();
extern void* fn_80201B8C();
extern unsigned long long fn_8020123C();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void*)(b), (void*)(c), (d), (e))

void fn_80025F48(void)
{
    void* entry;
    u32 id;
    ObjectInfo* object;
    Owner* owner;
    u32 result;

    fn_801E79A0(lbl_8064C4E0, 0x3BF);
    fn_801E79A0(lbl_8064C4E0, 0x464);

    if (fn_801E79FC(lbl_8064C4E0, 0x34D) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0x345) == 0 &&
        fn_800462C8(0) == 0) {
        entry = fn_80204844(fn_80201B9C(), 0x20);
        if (entry != 0) {
            id = fn_80201B54();
            object = fn_80201B8C(entry);
            if (object != 0) {
                owner = object->owner;
                if (owner != 0) {
                    fn_8020123C(0x52, 0, id, 0);
                    owner->state[0xE] = 0xF;
                    result = fn_8020123C(0x53, 0, id, (s32)&owner->state[0xE]) & 0xFFFFFFFFULL;
                    if (result == 1) {
                        fn_8020104C(0x54, 0, id, 0, lbl_8064DF50);
                    }
                }
            }
        }
    }
}
