typedef unsigned char u8;

typedef struct EffectRuntime {
    u8 pad[0x88];
    void *owner;
} EffectRuntime;

extern u8 lbl_8031CD84[];

extern void fn_80080458(int, u8);
extern void *fn_80154340(float, int, u8, int, u8, int, int, int);
extern void *fn_80156938();
extern void fn_80180384(void *, int);

int fn_80080588(int object, int index, u8 enabled, float lifetime)
{
    u8 *slot;
    int created = 0;

    slot = lbl_8031CD84;
    slot += index * 4;
    if (*(void **)(slot += 0x46C) == 0) {
        fn_80080458(object, enabled);
        *(void **)slot = fn_80154340(lifetime, object,
                                    lbl_8031CD84[index + 0x488], 0xF,
                                    enabled, 0, 1, 0xFF);
        if (*(void **)slot != 0) {
            EffectRuntime *runtime = fn_80156938(*(void **)slot);
            if (runtime != 0) {
                fn_80180384(runtime->owner, 0x4B);
            }
        }
        created = 1;
    }
    return created;
}
