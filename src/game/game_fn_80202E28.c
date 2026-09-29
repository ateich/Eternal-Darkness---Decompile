typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct EventData80202E28 {
    char pad[0x1C];
    u32 value;
} EventData80202E28;

typedef struct State80202E28 {
    char pad0[8];
    u32 flags;
    char pad1[0x28];
    s16 counter;
} State80202E28;

extern int lbl_8064D18C;
extern void *lbl_8064D8A8;
extern int lbl_8064D8AC;
extern const float lbl_8065159C;
extern const float lbl_806515A0;
extern const float lbl_80651598;
extern u32 lbl_80651F48;
extern u32 lbl_80651F4C;
extern u32 lbl_80651F50;
extern u32 lbl_80651F54;
extern u32 lbl_80651F58;
extern u32 lbl_80651F5C;
extern u32 lbl_80651F60;
extern u32 lbl_80651F64;
extern u32 lbl_80651F68;
extern Vec3 lbl_8023B858[];

extern int fn_800073D8();
extern int fn_800459E0();
extern void fn_800C96D4(int, int, int, int, int, int, float);
extern int fn_8011EB04();
extern int fn_8011EBFC();
extern void fn_8011F0E8(Vec3 *, Vec3 *);
extern void fn_8011F114(Vec3 *, int);
extern u32 fn_8011F950();
extern int fn_8011FB4C();
extern int fn_8011FCEC();
extern int fn_8011FE54();
extern int fn_8011FE5C();
extern int fn_801261F4();
extern int fn_8012880C();
extern int fn_80128A84();
extern u32 fn_80128C34();
extern u32 fn_80128E30();
extern int fn_80128EAC();
extern int fn_80128F74();
extern int fn_801290D0();
extern int fn_801294DC();
extern int fn_80129FD0();
extern int fn_8012A100();
extern int fn_8012A1BC();
extern int fn_8012A1FC();
extern int fn_8012B344();
extern int fn_8012C478();
extern void fn_8012C62C(int, int, u32 *, u32 *, u32 *, int);
extern void fn_8012DBE8(int, int, u8 *);
extern void fn_8014F65C(float, Vec3 *, int, int, int, u32 *);
extern int fn_8015917C();
extern int fn_8016B400();
extern int fn_801A6F94();
extern void *fn_801AAE68(unsigned short, unsigned char, unsigned char, float, Vec3 *, signed char, unsigned char, unsigned char, unsigned short, int);
extern int fn_801AC980();
extern int fn_801E8328();
extern void fn_801D38BC(int, u32 *, s16 *);
extern int fn_80200C10();
extern int fn_80200C38();
extern int fn_8020123C();
extern int fn_80201B54();
extern int fn_80201B94();
extern int fn_80201BC8();
extern int fn_80201C7C();
extern int fn_80201CDC();
extern int fn_80201D14();
extern int fn_80201D2C();
extern int fn_80201E50();
extern int fn_80201EB8();
extern int fn_8020228C();
extern int fn_802022B4();
extern int fn_80202440();
extern int fn_802025D8();
extern int fn_802028AC();
extern int fn_80202C00();
extern int fn_80203D94();

static inline void set_result(int object, int result)
{
    fn_80201D2C(object, result);
    fn_80201D14(object, 1);
}

static inline void send_counter(int kind, int other, State80202E28 *state, int check_busy)
{
    if (state->counter != 0 && fn_8020228C() == 0 &&
        (!check_busy || fn_8015917C() == 0)) {
        s16 value = state->counter;
        if (value > 0)
            value--;
        state->counter = value;
        fn_8020123C(kind, other, other, 0);
    }
}

int fn_80202E28(int object, int action, EventData80202E28 *data, int extra)
{
    Vec3 *offsets = lbl_8023B858;
    int type = fn_80200C10(data);
    State80202E28 *state;
    int model;
    int other;
    int event;
    Vec3 position;
    Vec3 offset0;
    Vec3 offset1;
    Vec3 offset2;
    Vec3 effect_position;
    Vec3 effect_source;
    u32 effect_word;
    s16 effect_kind;
    u8 color[4];
    u32 color0c, color0b, color0a;
    u32 color1c, color1b, color1a;
    u32 color2c, color2b, color2a;
    u32 effect_copy;

    model = fn_80201BC8(object);
    state = (State80202E28 *)fn_80201B94(object);
    other = fn_80201B54(object);
    event = fn_8011EB04(model);
    fn_8011F114(&position, model);

    if (action == 0) {
        if (type == 1) {
            if (state->flags & 0x80) {
                set_result(object, 0xD);
                state->flags &= 0xFFFFFF7FU;
            } else {
                set_result(object, 0xE);
            }
            if (fn_80201EB8(object) == 0xEF) {
                switch (event) {
                case 0x127:
                    offset0 = offsets[0];
                    fn_8011F0E8((Vec3 *)model, &offset0);
                    break;
                case 0x13C:
                    offset1 = offsets[1];
                    fn_8011F0E8((Vec3 *)model, &offset1);
                    break;
                case 0x13D:
                    offset2 = offsets[2];
                    fn_8011F0E8((Vec3 *)model, &offset2);
                    break;
                }
            }
            return 1;
        }
        if (type == 6) {
            int value = fn_80201C7C(state);
            if (value != 0)
                fn_8016B400(value, 0, 0);
            return 1;
        }
        if (type == 0x39) {
            fn_801E8328(2, object);
            return 1;
        }
        if (type == 0x3E) {
            if (state->flags & 0x100000) {
                fn_8012C478(model, 0xF, 0);
                state->flags &= 0xFFEFFFFFU;
            }
            if (state->flags & 0x200000) {
                color0a = lbl_80651F50;
                color0b = lbl_80651F4C;
                color0c = lbl_80651F48;
                fn_8012C62C(model, 0xF, &color0c, &color0b, &color0a, 4);
                state->flags &= 0xFFDFFFFFU;
            }
            fn_80202C00(other, event, object);
            return 1;
        }
        if (type == 0x3D) {
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 == 0) {
                fn_801AC980(lbl_8064D8A8, 0x1E);
                lbl_8064D8A8 = 0;
            }
            if (fn_802022B4(object) != 0) {
                if (fn_8011F950(model) != 0) {
                    if (fn_801261F4(model) != 0 && fn_8011FCEC(model) != -1)
                        fn_8011EBFC(model);
                    {
                        u32 target = fn_80128E30(model);
                        state->counter = 0;
                        if (target != 0) {
                            fn_8012B344(model);
                            set_result(object, 0xE);
                        }
                    }
                } else {
                    set_result(object, 0xE);
                }
            }
            return 1;
        }
        if (type == 0x9A) {
            state->counter = data->value;
            return 1;
        }
        if (type == 0xB5) {
            u32 target = fn_80128E30(model);
            u32 victim;
            int player;
            fn_80201EB8(object);
            player = lbl_8064D18C;
            if (target == 0) {
                fn_800073D8(player);
                fn_801A6F94();
            }
            victim = target ? fn_80128C34(target) : 0;
            if (victim == 0) {
                fn_800073D8(lbl_8064D18C);
                fn_801A6F94();
            } else {
                fn_802025D8(other, object, model, victim, state);
            }
            return 1;
        }
    } else if (action == 0xE) {
        if (type == 1) {
            fn_8011FE5C(model, 0x1B);
            if (fn_8011F950(model) != 0 && lbl_8064D18C == fn_8011FB4C(model))
                fn_801294DC(model, 0x1B, 0x21, 8);
            return 1;
        }
        if (type == 3) {
            send_counter(0x12, other, state, 1);
            return 1;
        }
        if (type == 0x12) {
            if ((fn_802022B4(object) != 0 && fn_8020228C() == 0) ||
                fn_802022B4(object) == 0)
                fn_802028AC(object, other, model, state, data, 0);
            return 1;
        }
        if (type == 0x9A) {
            if (fn_8020228C() == 0) {
                state->counter = data->value;
                fn_8020123C(0x12, other, other, 0);
            }
            return 1;
        }
        if (type == 0x3B)
            return fn_80203D94(object, action, data, extra);
        if (type == 0x85)
            return fn_80203D94(object, action, data, extra);
    } else if (action == 0xD) {
        if (type == 1) {
            fn_8011FE5C(model, 0x1A);
            if (fn_8011F950(model) != 0 && lbl_8064D18C == fn_8011FB4C(model))
                fn_801294DC(model, 0x1A, 0x21, 8);
            send_counter(0x13, other, state, 0);
            return 1;
        }
        if (type == 3) {
            send_counter(0x13, other, state, 1);
            return 1;
        }
        if (type == 0x13) {
            if ((fn_802022B4(object) != 0 && fn_8020228C() == 0) ||
                fn_802022B4(object) == 0)
                fn_80202440(object, other, model, state, data, 0);
            return 1;
        }
        if (type == 0x3E) {
            if (fn_8012A100(model, 0x1A) != 0) {
                int target = fn_801294DC(model, 0x1A, 0x21, 8);
                if (target != 0) {
                    int slot;
                    fn_80128EAC(model);
                    slot = fn_8012A1BC(model, 0x1A);
                    fn_80129FD0(model, slot << 17, 0);
                    fn_80128A84(target, 0, slot);
                }
            }
            fn_80202C00(other, event, object);
            return 1;
        }
        if (type == 0x9A) {
            if (fn_8020228C() == 0) {
                state->counter = data->value;
                fn_8020123C(0x13, other, other, 0);
            }
            return 1;
        }
    } else if (action == 0xF) {
        if (type == 1) {
            int flags = fn_80201CDC(object);
            event = fn_8011EB04(model);
            fn_80201E50(state, flags & ~8);
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 == 0)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            return 1;
        }
        if (type == 0x1C) {
            if (fn_80200C38(data) == 0 && event == 0x9C && lbl_8064D18C == 0x128)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            return 1;
        }
        if (type == 0x3E) {
            if (state->flags & 0x100000) {
                fn_8012C478(model, 0xF, 0);
                state->flags &= 0xFFEFFFFFU;
            }
            if (state->flags & 0x200000) {
                color1a = lbl_80651F5C;
                color1b = lbl_80651F58;
                color1c = lbl_80651F54;
                fn_8012C62C(model, 0xF, &color1c, &color1b, &color1a, 4);
                state->flags &= 0xFFDFFFFFU;
            }
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 == 0)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            fn_80202C00(other, event, object);
            return 1;
        }
        if (type == 0x13) {
            if ((fn_802022B4(object) != 0 && fn_8020228C() == 0) ||
                fn_802022B4(object) == 0) {
                int mode = fn_8011FE54(model);
                int current = fn_80128EAC(model);
                if (current == mode) {
                    int slot = fn_8012A1BC(model, 0x19);
                    fn_802028AC(object, other, model, state, data, 0);
                    fn_80129FD0(model, slot << 17, 0);
                }
                mode = fn_80128E30(model);
                {
                    int flags = fn_801290D0(model);
                    fn_80128F74(model, flags | 2);
                }
                fn_8012880C(mode, 0, 0);
                fn_80202440(object, other, model, state, data, mode);
            }
            return 1;
        }
        if (type == 0x14) {
            fn_800459E0(object);
            if (fn_802022B4(object))
                set_result(object, 0xE);
            else
                set_result(object, 0xD);
            return 1;
        }
        if (type == 2) {
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 != 0) {
                fn_801AC980(lbl_8064D8A8, 0x1E);
                lbl_8064D8A8 = 0;
            }
            return 1;
        }
    } else if (action == 0x10) {
        if (type == 1) {
            int flags = fn_80201CDC(object);
            fn_80201E50(state, flags & ~8);
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 == 0)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            return 1;
        }
        if (type == 0x1C) {
            if (fn_80200C38(data) == 0 && event == 0x9C && lbl_8064D18C == 0x128)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            return 1;
        }
        if (type == 0x12) {
            if ((fn_802022B4(object) != 0 && fn_8020228C() == 0) ||
                fn_802022B4(object) == 0) {
                int mode = fn_8011FE54(model);
                int current = fn_80128EAC(model);
                if (current == mode) {
                    int slot = fn_8012A1FC(model, 0x19);
                    fn_80202440(object, other, model, state, data, 0);
                    fn_80129FD0(model, slot << 17, 0);
                }
                mode = fn_80128E30(model);
                {
                    int flags = fn_801290D0(model);
                    fn_80128F74(model, flags & ~2);
                }
                fn_8012880C(mode, 0, 0);
                fn_802028AC(object, other, model, state, data, mode);
            }
            return 1;
        }
        if (type == 0x3E) {
            if (state->flags & 0x100000) {
                fn_8012C478(model, 0xF, 0);
                state->flags &= 0xFFEFFFFFU;
            }
            if (state->flags & 0x200000) {
                color2a = lbl_80651F68;
                color2b = lbl_80651F64;
                color2c = lbl_80651F60;
                fn_8012C62C(model, 0xF, &color2c, &color2b, &color2a, 4);
                state->flags &= 0xFFDFFFFFU;
            }
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 == 0)
                lbl_8064D8A8 = fn_801AAE68(0x1DC, 0x64, 0, lbl_80651598,
                                                   &position, 1, 2, 0,
                                                   (unsigned short)lbl_8064D18C, 0);
            fn_80202C00(other, event, object);
            return 1;
        }
        if (type == 0x15) {
            set_result(object, 0xE);
            return 1;
        }
        if (type == 2) {
            if (event == 0x9C && lbl_8064D18C == 0x128 && lbl_8064D8A8 != 0) {
                fn_801AC980(lbl_8064D8A8, 0x1E);
                lbl_8064D8A8 = 0;
            }
            return 1;
        }
    } else if (action == 0x30) {
        if (type == 1) {
            fn_8011F114(&effect_source, model);
            effect_position = effect_source;
            fn_801D38BC(lbl_8064D8AC, &effect_word, &effect_kind);
            effect_copy = effect_word;
            fn_8014F65C(lbl_8065159C, &effect_position, 0x64, effect_kind, 0,
                        &effect_copy);
            fn_800C96D4(object, 0xFE, -2, 0, 0x64, 1, lbl_806515A0);
            return 1;
        }
        if (type == 3) {
            fn_8012DBE8(model, 0xF, color);
            if (color[3] <= 5)
                fn_8020123C(0x39, other, other, 0);
            return 1;
        }
        if (type == 0x3D)
            return fn_80203D94(object, action, data, extra);
    }

    else {
        return 0;
    }
    return 0;
}
