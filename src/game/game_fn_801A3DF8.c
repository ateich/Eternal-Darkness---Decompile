typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_801991E0(void*, void*, int);
extern int fn_80180430(void*, unsigned int);
extern void fn_80180518(void*, int, int);
extern void fn_8017E850(void*, void*, short, float, void*);
extern void fn_8017E958(void*, void*, short, float);
extern void fn_8017D700(void*, void*, short, void*, int, int, int, int);
extern int fn_8017D1E0(void*, void*, u16, u16, u16, s16*);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern int fn_800AD2B4(void);
extern int fn_800AD538(void);
extern int fn_800AD4E8(void);
extern void fn_8020123C(int, void*, void*, int);
extern void fn_8020104C(int, void*, void*, int, float);
extern void* fn_80201814(u32);
extern void* fn_80201BC8(void*);
extern int fn_8006749C(int);
extern void fn_80120AD0(void*, const void*, u16, u32, float, float);

extern int lbl_8064D18C;
extern const float lbl_80650D50;
extern const float lbl_80650D54;
extern const float lbl_80650D68;
extern const float lbl_80650D6C;

int fn_801A3DF8(u8* object)
{
    u8* state = object + 0x8C;
    u8* channel;
    unsigned int count;
    int i;
    u8 any_active;
    float step;
    u8 update_a;
    u8 update_b;
    u8 update_c;

    if (object[0x98] & 4) {
        fn_801991E0(object, state + 0x2C, 0x10);
        goto finish;
    }

    count = object[1];
    any_active = 0;
    step = lbl_80650D50 / (float)count;
    channel = *(u8**)(object + 0x4C);
    update_a = state[0x0E];
    update_b = state[0x0F];
    update_c = state[0x10];
    if (state[0x13] < count && *(u16*)(object + 0xA) >= state[0x12]) {
        channel[state[0x13] * 0x38 + 0x2B] = object[2];
        fn_80180518(object + 0x24, state[0x13], 1);
        state[0x13]++;
        state[0x12] += state[0x11];
    }

    for (i = 0; i < (int)count; channel += 0x38, i++) {
        int mask;
        if (!fn_80180430(object + 0x24, (u8)i))
            continue;
        mask = 1 << i;
        if (state[0x14] & mask) {
            if (i == 0)
                fn_8017E850(channel + 0xA, object + 0x10,
                            *(short*)(state + 0x22), *(float*)(state + 0x28),
                            state + 0x24);
            else
                fn_8017E958(channel + 0xA, object + 0x10,
                            *(short*)(state + 0x22),
                            *(float*)(state + 0x24) + (float)i * step);
            continue;
        }
        any_active = 1;
        {
            s16 value = state[i + 0x17];

            fn_8017D700(channel + 0xA, object + 0x10,
                        *(s16*)(channel + 0x1C), channel + 0x10,
                        value, update_b, update_a, update_c);
            if (fn_8017D1E0(channel + 0xA, object + 0x10,
                            state[0x15], (u16)*(s16*)(state + 0x22), state[0x16],
                            &value)) {
                if (state[0x1F] == 0) {
                    void* owner = fn_80201814(*(u32*)(state + 4));
                    if (owner != 0) {
                        void* resolved = fn_80201BC8(owner);
                        if (resolved != 0) {
                            u16 flags = fn_8006749C(state[0x1E]) | 2;
                            fn_80120AD0(resolved, 0, 100, flags,
                                        lbl_80650D54, lbl_80650D68);
                        }
                    }
                    state[0x1F] = 1;
                    if (state[0x0C] & 0x80)
                        fn_8020123C(0xEA, *(void**)(state + 8),
                                    *(void**)(state + 4), 0);
                }
                state[0x14] |= mask;
            } else {
                state[i + 0x17] = (u8)value;
            }
        }
    }

    if (!(state[0xC] & 0x80) && !state[0x20] && !any_active) {
        if (lbl_8064D18C == 0x29)
            fn_8020123C(0xEA, *(void**)(state + 8), *(void**)(state + 4), -1);
        if (fn_800AD2B4()) {
            if (*(int*)(state + 4) == fn_800AD538()) {
                if (!fn_800AD4E8())
                    fn_8020123C(0x39, *(void**)state, *(void**)state, 0);
                else
                    fn_8020104C(0x39, *(void**)state, *(void**)state, 0,
                                lbl_80650D6C);
            } else {
                fn_8020104C(0xC4, *(void**)state, *(void**)state, 0,
                            lbl_80650D6C);
            }
        } else {
            fn_8020104C(0xC4, *(void**)state, *(void**)state, 0,
                        lbl_80650D6C);
        }
        state[0x20] = 1;
    }

    if (object[0x60]) {
        if (!fn_8018E26C(object + 0x60, object + 0x5F) && !(state[0xC] & 1))
            *(u16*)(object + 0x22) = 8;
    } else if (!(state[0xC] & 1)) {
        if (object[0x5F] &&
            (!fn_800AD2B4() || *(int*)(state + 4) != fn_800AD538()))
            fn_8018E230(object + 0x60, object + 0x5F, 1, object[0x5F], object[4], 0);
        else
            *(u16*)(object + 0x22) = 8;
    } else if (state[0xC] & 0x20) {
        state[0xC] &= ~0x20;
        if (object[0x5F])
            fn_8018E230(object + 0x60, object + 0x5F, 1, object[0x5F], object[4], 0);
    } else if (state[0xC] & 0x40) {
        state[0xC] &= ~0x40;
        if (object[0x5F] != object[2])
            fn_8018E230(object + 0x60, object + 0x5F, 1, 0,
                        (s8)-object[4], object[2]);
    } else if (fn_800AD2B4() && *(int*)(state + 4) == fn_800AD538() &&
               !fn_800AD4E8()) {
        fn_8020123C(0x39, *(void**)state, *(void**)state, 0);
    }

finish:
    (*(u16*)(object + 0xA))++;
    return 1;
}
