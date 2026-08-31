typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct Effect {
    u8 pad0[0x80];
    u32 key;
    u8 pad84[0xB];
    s8 active;
    u8 pad90[8];
} Effect;

extern Effect lbl_806080E0[80];

Effect* fn_801AC7BC(u32 key)
{
    Effect* effect;
    int i;

    effect = lbl_806080E0;
    for (i = 0; i < 80; i++, effect++) {
        if (effect->key == key && effect->active != 0) {
            return effect;
        }
    }
    return 0;
}
