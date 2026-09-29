typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef void (*UpdateCallback)(u32, u16*, u32);

typedef struct Ramp {
    float value;
    float target;
    float previous_target;
    float step;
    float step_delta;
    float aux_value;
    float aux_target;
    float aux_previous_target;
    float aux_step;
    float aux_step_delta;
    u32 voice;
    u8 type;
    u8 pad[3];
} Ramp;

extern u8 lbl_80619860[];
extern const float lbl_80650F00;
extern u8 lbl_8064D3A1;
extern u8 lbl_8064D3A4;
extern u8 lbl_8064D3AC;
extern u8 lbl_8064D3B4;
extern u8 lbl_8064D3BC;
extern u32 lbl_8064D3C4;
extern u32 lbl_8064D3C8;
extern u64 lbl_8064D3E0;

extern void fn_801C044C(u32);
extern void fn_801B797C(void*, void (*)(u32));
extern void fn_801B6768(u32);
extern void fn_801B75CC(u32);
extern void fn_801B6F1C(u32);
extern u8 fn_801CC6D4(void);
extern u16 fn_801CBCE0(u8, u8, u8, u8);
extern u16 fn_801CBD9C(u8, u8, u8, u8);
extern void fn_801CD400(void);
extern void fn_801B3770(void*);
extern void fn_801B35BC(void*);
extern void fn_801B3C14(void*, int, int);

#define U32(p, o) (*(u32*)((p) + (o)))

void fn_801B7A7C(u32 elapsed)
{
    u32 i;
    u32 bit;

    if (U32(lbl_80619860, 0x3C4) == 0) {
        return;
    }

    fn_801C044C(elapsed);
    {
        u8* lists = lbl_80619860 + 0x240 + lbl_8064D3A1 * 12;
        fn_801B797C(lists, fn_801B6768);
        fn_801B797C(lists + 4, fn_801B75CC);
        fn_801B797C(lists + 8, fn_801B6F1C);
    }
    lbl_8064D3A1 = (lbl_8064D3A1 + 1) & 0x1F;

    if (!fn_801CC6D4()) {
        if (lbl_8064D3C8 | lbl_8064D3C4) {
            const float zero = lbl_80650F00;
            Ramp* ramp = (Ramp*)(lbl_80619860 + 0x5D4);
            bit = 1;
            for (i = 0; i < 32; ++i, bit <<= 1, ++ramp) {
                if (lbl_8064D3C8 & bit) {
                    ramp->value =
                        ramp->target -
                        (float)(ramp->step *
                            (ramp->target - ramp->previous_target));
                    if ((ramp->step = ramp->step - ramp->step_delta) <= zero) {
                        ramp->value = ramp->target;
                        switch (ramp->type) {
                        case 1:
                            fn_801B3770((void*)ramp->voice);
                            break;
                        case 2:
                            fn_801B35BC((void*)ramp->voice);
                            break;
                        case 3:
                            fn_801B3C14((void*)ramp->voice, 0, 0);
                            break;
                        }
                        if ((lbl_8064D3C8 &= ~bit) == 0 && !lbl_8064D3C4) {
                            break;
                        }
                    }
                }
                if (lbl_8064D3C4 & bit) {
                    ramp->aux_value =
                        ramp->aux_target -
                        (float)(ramp->aux_step *
                            (ramp->aux_target - ramp->aux_previous_target));
                    if ((ramp->aux_step = ramp->aux_step - ramp->aux_step_delta) <=
                        zero) {
                        ramp->aux_value = ramp->aux_target;
                        if ((lbl_8064D3C4 &= ~bit) == 0 && !lbl_8064D3C8) {
                            break;
                        }
                    }
                }
            }
        }

        {
            u32* context = (u32*)(lbl_80619860 + 0xC14);
            UpdateCallback* callback =
                (UpdateCallback*)(lbl_80619860 + 0xC34);
            UpdateCallback* aux_callback =
                (UpdateCallback*)(lbl_80619860 + 0xC74);
            for (i = 0; i < 8; ++i, ++context, ++callback, ++aux_callback) {
                u16 values[4];
                u32 channel;
                u32* aux_context = context + 0x10;
                if ((&lbl_8064D3BC)[i] != 0xFF) {
                    for (channel = 0; channel < 4; ++channel) {
                        values[channel] = fn_801CBCE0(
                            (u8)i, (u8)channel, (&lbl_8064D3BC)[i],
                            (&lbl_8064D3B4)[i]);
                    }
                    (*callback)(1, values, *context);
                }
                if ((&lbl_8064D3AC)[i] != 0xFF) {
                    for (channel = 0; channel < 4; ++channel) {
                        values[channel] = fn_801CBD9C(
                            (u8)i, (u8)channel, (&lbl_8064D3AC)[i],
                            (&lbl_8064D3A4)[i]);
                    }
                    (*aux_callback)(1, values, *aux_context);
                }
            }
        }
    }

    fn_801CD400();
    lbl_8064D3E0 += elapsed;
}
