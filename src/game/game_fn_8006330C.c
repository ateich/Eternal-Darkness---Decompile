typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct State {
    u8 pad0[0x14];
    s32 target;
    s32 next_phase;
    u8 pad1C[0x50];
    s32 value6C;
    u8 pad70[0xF0];
    s8 side;
} State;

typedef struct Data {
    u8 pad0[0x8C];
    State *state;
    s32 value90;
    s32 mode;
    s16 type;
    u8 pad9A[4];
    u8 flag9E;
    u8 kind9F;
} Data;

#pragma use_lmw_stmw on

extern s32 lbl_8064C4E0;
extern s32 lbl_8064D18C;
extern s32 lbl_8064D5A8;
extern f32 lbl_8064E63C;
extern f32 lbl_8064E640;
extern f32 lbl_8064E644;
extern const f32 lbl_8064E648;
extern unsigned char lbl_802FC5BC[];
extern void fn_80204810(void);

extern s32 fn_800359A0(s32, s32);
extern s32 fn_8003D7B4(s32);
extern s32 fn_8003DED0(s32, s32, void *);
extern s32 fn_80048708(s32);
extern s32 fn_80064B38(s32, s32, u32 *);
extern u32 fn_800654F8(s32);
extern s32 fn_800674E4(s32, s32);
extern s32 fn_80067650(s32, s32);
extern s32 fn_80067A18(s32);
extern s32 fn_80068290(s32, s32, u32 *);
extern s32 fn_80068994(s32, s32);
extern s32 fn_80072354(s32);
extern s32 fn_800BD2DC(s32, void *);
extern s32 fn_8011F114();
extern s32 fn_8011F778(s32, f32);
extern unsigned int fn_8011FA8C(s32, s32, s32);
extern s32 fn_8011FF38();
extern s32 fn_80128C28();
extern void *fn_801294DC(s32, s32, s32, s32);
extern s32 fn_8012B324(s32);
extern s32 fn_8012B344();
extern s32 fn_8014D100(s32, void *, s32, s32);
extern s32 fn_8016B400(s32, s32, s32);
extern s32 fn_801A5910(s32);
extern void *fn_801A717C(void);
extern void fn_801A7228(void *);
extern void fn_801A74A0(void *, u32);
extern void fn_801A74A8(void *, u32);
extern void fn_801A7518(void *, s16);
extern void fn_801A7538(void *, u16);
extern void fn_801A764C(void *, const f32 *);
extern s32 fn_801AAE68(u16, u8, u8, f32, f32 *, s8, u8, u8, u16, u32);
extern s32 fn_801E7974(s32, s32);
extern s32 fn_801E79A0(s32, s32);
extern s32 fn_801E8328(s32, s32);
extern s32 fn_80200C10(s32);
extern s32 fn_80200C20(s32);
extern s32 fn_80200C28(s32);
extern s32 fn_80200C38(s32);
extern s32 fn_8020104C(s32, s32, s32, s32, f32);
extern s32 fn_8020123C();
extern s32 fn_80201814();
extern s32 fn_80201B54();
extern Data *fn_80201B8C();
extern s32 fn_80201B94(s32);
extern s32 fn_80201BC8();
extern s32 fn_80201D14();
extern s32 fn_80201D1C(s32, s32);
extern s32 fn_80201D2C();
extern s32 fn_80201D34(s32, s32);
extern s32 fn_80204508(s32, s32);
s32 fn_8006330C(s32 context, s32 phase, s32 message, u32 *out) {
    f32 position[3];
    s16 type;
    s32 result;
    s32 object;
    void *event;
    s16 delay;
    void *handle;
    s32 kind;
    Data *data;
    State *state;
    s32 id;
    s32 value;

    kind = fn_80200C10(message);
    object = fn_80201BC8(context);
    data = fn_80201B8C(context);
    state = data->state;
    fn_80201B94(context);
    id = fn_80201B54(context);
    fn_8011F114(position, object);
    if (kind == 3) {
        fn_8003DED0(context, object, state);
    }
    if (phase == 0) {
        if (kind == 1) {
            fn_8011F778(object, lbl_8064E644);
            fn_80201D2C(context, 0x19);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 0x86) {
            fn_801A5910(fn_80200C38(message));
            return 1;
        }
        if (kind == 0xBB) {
            value = fn_80200C38(message);
            if (value != 0) {
                fn_801E7974(lbl_8064C4E0, value);
            }
            return 1;
        }
        if (kind == 0xBC) {
            value = fn_80200C38(message);
            if (value != 0) {
                fn_801E79A0(lbl_8064C4E0, value);
            }
            return 1;
        }
        if (kind == 0xBE) {
            value = fn_80200C38(message);
            if (value != 0) {
                fn_8016B400(value, id, 0);
            }
            return 1;
        }
        if (kind == 0x39) {
            fn_8012B324(object);
            fn_8003D7B4(id);
            fn_8011FA8C(object, 0xC0, 0);
            fn_80201D34(context, 0);
            fn_80201D1C(context, 1);
            fn_8020123C(0x26, id, state->target, 0);
            fn_801E8328(2, context);
            return 1;
        }
        if (kind == 0xEA) {
            if (data->kind9F != 0x25U) {
                fn_800674E4(context, message);
            }
            return 1;
        }
        if (kind == 0xEB) {
            fn_80067650(context, message);
            return 1;
        }
        if (kind == 0xC9) {
            if (fn_8011FF38() != 0) {
                fn_8011FA8C(object, 0, 0x20000000);
                fn_801AAE68(0x1F1, 0x64, 0, lbl_8064E648, position, 2, 2, 0,
                            (u16)lbl_8064D18C, 0);
            }
            return 1;
        }
        if (kind == 0x3D) {
            fn_800BD2DC(context, state);
            fn_8003D7B4(id);
            fn_80067A18(id);
            fn_8020123C(0x26, id, state->target, 0);
            fn_8020123C(0x26, id, id, 0);
            return 1;
        }
        if (kind == 0xED) {
            fn_8020123C(0xB, fn_80200C20(message), fn_80200C28(message), fn_80200C38(message));
            fn_801A7228((void *)fn_80200C38(message));
            return 1;
        }
        if (kind == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(message), fn_80200C28(message), fn_80200C38(message));
            fn_801A7228((void *)fn_80200C38(message));
            return 1;
        }
        if (kind == 0xB) {
            fn_800359A0(context, fn_80201814(fn_80200C20(message)));
            result = fn_800654F8(fn_80200C38(message));
            if (out != 0U) {
                *out = result;
            }
            return 1;
        }
        if (kind == 0x3F) {
            if (fn_80068290(context, message, out) != 0) {
                fn_8020123C(0x26, id, state->target, 0);
                state->target = 0;
                state->next_phase = 0;
            }
            return 1;
        }
        if (kind == 0x20) {
            if (out != 0U) {
                *out = 0;
            }
            return 1;
        }
        if (kind == 0x3B) {
            if (out != 0U) {
                *out = 1;
            }
            return 1;
        }
        if (kind == 0x4E) {
            if ((data->flag9E != 1U) && (out != 0U)) {
                *out = (u32) (state->value6C == 0);
            }
            return 1;
        }
        if (kind == 0xE) {
            fn_80068994(context, message);
            return 1;
        }
        if (kind == 0x27) {
            fn_80064B38(context, message, out);
            return 1;
        }
        if (kind == 8) {
            fn_8012B344(object);
            fn_8020123C(0x26, id, state->target, 0);
            fn_8020104C(8, fn_80200C20(message), id, 0, lbl_8064E640);
            fn_80201D34(context, state->next_phase);
            fn_80201D1C(context, 1);
            state->target = 0;
            state->next_phase = 0;
            return 1;
        }
    } else if (phase == 0x19) {
        if (kind == 0x21) {
            fn_80204508(fn_80201814(state->target), context);
            if (fn_801294DC(object,
                           state->side == 0 ? 0x5A : 0x60,
                           0x25, 6) != 0U) {
                fn_80201D2C(context, 0x1B);
                fn_80201D14(context, 1);
            } else {
                fn_8020123C(0x26, id, state->target, 0);
                fn_80201D34(context, state->next_phase);
                fn_80201D1C(context, 1);
                state->target = 0;
                state->next_phase = 0;
            }
            return 1;
        }
        if (kind == 0x26) {
            fn_8012B344(object);
            fn_80201D34(context, state->next_phase);
            fn_80201D1C(context, 1);
            state->target = 0;
            state->next_phase = 0;
            return 1;
        }
    } else if (phase == 0x1B) {
        if (kind == 1) {
            return 1;
        }
        if (kind == 0x24) {
            fn_8012B344(object);
            fn_8011F778(object, lbl_8064E63C);
            fn_80048708(object);
            fn_80201D34(context, state->next_phase);
            fn_80201D1C(context, 1);
            state->target = 0;
            state->next_phase = 0;
            return 1;
        }
        if (kind == 0x26) {
            fn_8012B344(object);
            fn_80201D34(context, state->next_phase);
            fn_80201D1C(context, 1);
            state->target = 0;
            state->next_phase = 0;
            return 1;
        }
        if (kind == 0x25) {
            fn_80204508(fn_80201814(state->target), context);
            handle = fn_801294DC(object,
                                    state->side == 0 ? 0x5C : 0x62,
                                    0x20, 8);
            if (handle != 0) {
                fn_80128C28(handle, fn_80204810, (id << 8) | 0x22);
                fn_80201D2C(context, 0x1D);
                fn_80201D14(context, 1);
                state->target = 0;
            } else {
                fn_8020123C(0x26, id, state->target, 0);
                fn_80201D34(context, state->next_phase);
                fn_80201D1C(context, 1);
                state->target = 0;
                state->next_phase = 0;
            }
            return 1;
        }
        if (kind == 3) {
            context = 3;
            if (data->flag9E == 1U) {
                context = 7;
            }
            if ((lbl_8064D5A8 & 0xF) == 0) {
                fn_8014D100(object, lbl_802FC5BC + 0x18, 2, 1);
            }
            if ((lbl_8064D5A8 & context) == 0) {
                fn_80072354(data->value90);
                event = fn_801A717C();
                type = data->type;
                delay = 1;
                switch (type) {
                case 0x40:
                case 0x41:
                case 0x42:
                    delay = 0;
                    break;
                }
                fn_801A74A0(event, id);
                fn_801A74A8(event, state->target);
                fn_801A7538(event, 1);
                fn_801A7518(event, delay);
                fn_801A764C(event, position);
                fn_8020123C(0x27, id, state->target, event);
                result = data->mode;
                if (result == 2) {
                    fn_801A7538(event, 4);
                    fn_801A7518(event, (s16) ((s16) delay * 2));
                    fn_8020123C(0x27, id, state->target, event);
                } else if (result == 3) {
                    fn_801A7538(event, 2);
                    fn_801A7518(event, delay);
                    fn_8020123C(0x27, id, state->target, event);
                }
                fn_801A7228(event);
            }
            return 1;
        }
    } else if (phase == 0x1D) {
        if (kind == 0x22) {
            fn_8011F778(object, lbl_8064E63C);
            fn_80048708(object);
            fn_8020104C(0x37, state->target, id, 0, lbl_8064E640);
            fn_80201D34(context, state->next_phase);
            fn_80201D1C(context, 1);
            state->target = 0;
            state->next_phase = 0;
            return 1;
        }
        if (kind == 0x3D) {
            fn_8012B344(object);
            fn_8020123C(0x22, id, id, 0);
            fn_8003D7B4(id);
            fn_80067A18(id);
            fn_800BD2DC(context, state);
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
