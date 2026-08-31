typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct Effect {
    u8 pad0[0x84];
    u16 owner;
    u16 id;
    u8 pad88;
    u8 value89;
    u8 pad8A;
    u8 value8B;
    u8 pad8C[3];
    s8 active;
    u8 pad90[2];
    s8 detailed;
    u8 pad93;
    u8 selector;
    u8 pad95[3];
} Effect;

extern Effect lbl_806080E0[80];
extern int lbl_8064D18C;
extern void fn_801AB0C4(Effect*, s8, int);
extern void fn_801AC59C(Effect*, void*, u8, int);

void fn_801AC5E4(u16 id, u8 selector, u8 value, int mode, s8 amount,
                 int detailed, int any_owner)
{
    Effect* effect;
    int i;
    int current_owner;

    if (id == 0xFFFF) {
        return;
    }
    effect = lbl_806080E0;
    current_owner = lbl_8064D18C;
    for (i = 0; i < 80; i++, effect++) {
        int match = 0;
        if (effect->active != 0 &&
            (any_owner != 0 || effect->owner == current_owner)) {
            if (selector != 0) {
                if (effect->selector == selector) {
                    match = 1;
                }
            } else if (effect->id == id) {
                if (detailed == 1) {
                    if (effect->detailed == 0) {
                        match = 1;
                    }
                } else if (effect->detailed != 0) {
                    match = 1;
                }
            }
        }
        if (match != 0) {
            if (mode == 1) {
                if (effect->detailed != 0) {
                    fn_801AB0C4(effect, amount, 6);
                } else {
                    fn_801AB0C4(effect, amount, 4);
                }
            } else if (amount > 1) {
                if (value == 0) {
                    if (effect->detailed != 0) {
                        fn_801AB0C4(effect, amount, 7);
                    } else {
                        fn_801AB0C4(effect, amount, 3);
                    }
                } else {
                    if (effect->detailed != 0) {
                        effect->value89 = value;
                    } else {
                        effect->value8B = value;
                    }
                    fn_801AB0C4(effect, amount, 5);
                }
            } else {
                fn_801AC59C(effect, 0, value, 1);
            }
        }
    }
}
