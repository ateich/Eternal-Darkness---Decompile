typedef signed char s8;

typedef struct Effect {
    unsigned char pad[0x8F];
    s8 active;
    unsigned char tail[8];
} Effect;

extern Effect lbl_806080E0[80];
extern void fn_801AC194(Effect*, int);

void fn_801AC2E8(void)
{
    Effect* effect;
    int i;

    effect = lbl_806080E0;
    for (i = 0; i < 80; i++, effect++) {
        if (effect->active != 0) {
            fn_801AC194(effect, i);
        }
    }
}
