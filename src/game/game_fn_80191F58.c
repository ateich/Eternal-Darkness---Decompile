typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_80180430(void*, u8);
extern void fn_80180518(void*, u8, int);
extern u8 fn_801911B0(void*, int);
extern void fn_80191E84(void*, u8, int);
extern void fn_801991E0(void*, void*, int);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8017E1B0(void*, void*);
extern void fn_8017D700(void*, void*, s16, void*, u8, u8, u8, u8);
extern int fn_801AC908(void*, Vec3*, u8);
extern void* fn_801AC8AC(int, int, int, Vec3*);
extern void fn_801AC980(void*, int);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern void* fn_80201814(void*);

int fn_80191F58(u8* object)
{
    Vec3 position;
    u8* stateEntry;
    u8* state;
    u8 count;
    s32 i;
    u8* entry;
    u8 value1;
    u8 value2;
    u8 value3;
    u8 value4;

    state = object + 0x8C;
    count = object[1];
    if (state[0] & 4) {
        fn_80191E84(state, count, 0x19);
        fn_801991E0(object, state + 0x2C, 0x10);
        goto done;
    }

    value1 = state[1];
    value2 = state[2];
    value3 = state[3];
    value4 = state[4];
    entry = *(u8**)(object + 0x4C);
    if (state[8] < count && *(u16*)(object + 0xA) >= state[7]) {
        entry[state[8] * 0x38 + 0x2B] = 0xFA;
        fn_80180518(object + 0x24, state[8], 1);
        state[8]++;
        state[7] += state[6];
    }

    stateEntry = state;
    for (i = 0; i < count; entry += 0x38, stateEntry += 4, i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            if (fn_801911B0(object, i)) {
                if (!fn_8018E26C(entry, entry + 0x2B)) {
                    fn_80180518(object + 0x24, (u8)i, 0);
                }
                fn_8017E1B0(entry + 0xA, entry + 0x10);
            } else {
                fn_8017D700(entry + 0xA, object + 0x10,
                            *(s16*)(entry + 0x1C), entry + 0x10,
                            value1, value3, value2, value4);
                if (state[0] & 8) {
                    if (state[0] & 0x10) {
                        position.x = *(s16*)(entry + 0xA);
                        position.y = *(s16*)(entry + 0xC);
                        position.z = *(s16*)(entry + 0xE);
                        if (!fn_801AC908(*(void**)(stateEntry + 0x10),
                                        &position, 0xFF)) {
                            *(void**)(stateEntry + 0x10) =
                                fn_801AC8AC(0x109, 0x64, 0xC8, &position);
                        }
                    } else if (*(void**)(stateEntry + 0x10) != 0) {
                        fn_801AC980(*(void**)(stateEntry + 0x10), 0xA);
                        *(void**)(stateEntry + 0x10) = 0;
                    }
                }
            }
        }
    }

    if ((state[0] & 2) || *(u16*)(object + 0xA) != *(u16*)(object + 0xC)) {
        if (fn_80201814(*(void**)(state + 0xC)) != 0)
            goto alive;
    }
    state[0] &= ~1;
alive:
    if (object[0x60]) {
        if (!fn_8018E26C(object + 0x60, object + 0x5F)) {
            if (!(state[0] & 1)) {
                fn_80191E84(state, count, 1);
                *(u16*)(object + 0x22) = 8;
            } else if (object[0x5F] == object[2] && (state[0] & 8)) {
                state[0] |= 0x10;
            }
        }
    } else if (!(state[0] & 1)) {
        if (object[0x5F]) {
            fn_80191E84(state, count, 0x19);
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        } else {
            fn_80191E84(state, count, 1);
            *(u16*)(object + 0x22) = 8;
        }
    } else if (state[0] & 0x20) {
        state[0] &= ~0x20;
        if (object[0x5F]) {
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        }
    } else if (state[0] & 0x40) {
        state[0] &= ~0x40;
        if (object[0x5F] != object[2]) {
            fn_8018E230(object + 0x60, object + 0x5F, 1, 0,
                        (s8)-object[4], object[2]);
        }
    }

done:
    (*(u16*)(object + 0xA))++;
    return 1;
}
