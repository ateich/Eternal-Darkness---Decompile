typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_801991E0(void*, void*, int);
extern int fn_80180430(void*, unsigned int);
extern void fn_8017E850(void*, void*, short, float, void*);
extern void fn_8017E958(void*, void*, short, float);
extern int fn_8017D1E0(void*, void*, unsigned int, unsigned int, void*);
extern int fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern int fn_800AD2B4(void);
extern int fn_800AD538(void);
extern int fn_800AD4E8(void);
extern void fn_8020123C(int, void*, void*, int);

int fn_801A3DF8(u8* object)
{
    u8* state = object + 0x8C;
    u8* channel = *(u8**)(object + 0x4C);
    unsigned int count = object[1];
    unsigned int i;
    int any_active = 0;

    if (object[0x98] & 4) {
        fn_801991E0(object, state + 0x2C, 0x10);
        goto finish;
    }

    if (state[0x13] < count && *(u16*)(object + 0xA) >= state[0x12]) {
        channel[state[0x13] * 0x38 + 0x2B] = object[2];
        state[0x13]++;
        state[0x12] += state[0x11];
    }

    for (i = 0; i < count; i++, channel += 0x38) {
        int mask;
        if (!fn_80180430(object + 0x24, i))
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
                            *(float*)(state + 0x24) + (float)i);
            continue;
        }
        any_active = 1;
        if (fn_8017D1E0(channel + 0xA, object + 0x10,
                        *(u16*)(state + 0x22), state[0x15], state + i + 0x17)) {
            state[0x14] |= mask;
        }
    }

    if (!(state[0xC] & 1) && !state[0x20] && !any_active) {
        if (fn_800AD2B4() && *(int*)(state + 4) == fn_800AD538()) {
            fn_8020123C(0x39, *(void**)state, *(void**)state, 0);
        }
        state[0x20] = 1;
    }

    if (object[0x60]) {
        if (!fn_8018E26C(object + 0x60, object + 0x5F) && !(state[0xC] & 1))
            *(u16*)(object + 0x22) = 8;
    } else if (!(state[0xC] & 1) && object[0x5F]) {
        if (!fn_800AD2B4() || *(int*)(state + 4) != fn_800AD538())
            fn_8018E230(object + 0x60, object + 0x5F, 1, object[0x5F], object[4], 0);
        else
            *(u16*)(object + 0x22) = 8;
    }

finish:
    (*(u16*)(object + 0xA))++;
    return 1;
}
