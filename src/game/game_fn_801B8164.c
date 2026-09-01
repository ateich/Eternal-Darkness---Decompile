typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Ramp {
    float current;
    float target;
    float previous;
    float step;
    float reciprocal;
    u8 pad14[0x14];
    s32 voice;
    u8 value;
    u8 type;
    u8 pad2E[2];
} Ramp;

extern u8 lbl_80619860[];
extern u32 lbl_8064D3C8;
extern void fn_801CC408(u32*);
extern void fn_801B7A10(Ramp*);

static inline void update_ramp(Ramp* ramp, u8 amount, u32 duration, u8 value,
                               s32 voice)
{
    float target = (1.0f / 127.0f) * amount;

    ramp->value = value;
    ramp->voice = voice;
    if (duration != 0) {
        ramp->previous = ramp->current;
        ramp->target = target;
        ramp->step = 0.0f;
        ramp->reciprocal = 1.0f / duration;
    } else {
        ramp->target = target;
        ramp->current = target;
        if (ramp->voice != -1) {
            fn_801B7A10(ramp);
        }
    }
}

void fn_801B8164(u8 amount, u16 duration_arg, u8 selector, u8 value,
                 s32 voice)
{
    u32 duration = duration_arg;
    u32 i;
    Ramp* ramp;
    u8 type;

    if (duration != 0) {
        fn_801CC408(&duration);
    }

    if (selector == 0xFF || selector == 0xFC) {
        u8 first = selector == 0xFF ? 0 : 2;
        for (i = 0, ramp = (Ramp*)(lbl_80619860 + 0x5D4); i < 32;
             ++i, ++ramp) {
            if (ramp->type == first || ramp->type == first + 1) {
                update_ramp(ramp, amount, duration, value, voice);
                lbl_8064D3C8 |= 1U << i;
            }
        }
        return;
    }

    switch (selector) {
    case 0xFA: type = 2; break;
    case 0xFB: type = 3; break;
    case 0xFD: type = 0; break;
    case 0xFE: type = 1; break;
    default:
        ramp = (Ramp*)(lbl_80619860 + 0x5D4) + selector;
        update_ramp(ramp, amount, duration, value, voice);
        lbl_8064D3C8 |= 1U << selector;
        return;
    }

    for (i = 0, ramp = (Ramp*)(lbl_80619860 + 0x5D4); i < 32;
         ++i, ++ramp) {
        if (ramp->type == type) {
            update_ramp(ramp, amount, duration, value, voice);
            lbl_8064D3C8 |= 1U << i;
        }
    }
}
