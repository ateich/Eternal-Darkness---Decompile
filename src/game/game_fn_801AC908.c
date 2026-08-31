typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Effect {
    u8 pad0[0x89];
    u8 value89;
} Effect;

extern Effect* fn_801AC7BC(u32);
extern void fn_801AC59C(Effect*, void*, u8, int);

int fn_801AC908(u32 key, void* position, u8 value)
{
    Effect* effect;
    int result = 1;

    effect = fn_801AC7BC(key);
    if (effect != 0) {
        if (value == 0xFF) {
            value = effect->value89;
        }
        fn_801AC59C(effect, position, value, 3);
    } else {
        result = 0;
    }
    return result;
}
