typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern void* fn_80201814(u32);
extern int fn_80201AE4(void);
extern void* fn_80201B8C(void*);
extern int fn_80038308(void*, int, s16*);
extern int fn_80038464(void*, int, s16*);
extern void fn_800389E0(void*, int, s16, int);

void fn_801D88D4(int flags, int subject)
{
    void* object = fn_80201814(subject);
    int local_player;
    s16 value;
    s16 value0;
    s16 value1;
    s16 case1_current;
    s16 case1_max;
    s16 case1_max3;
    s16 case2_current;
    s16 case4_current;
    s16 case4_max;
    s16 case8_current0;
    s16 case8_current1;
    s16 case8_max0;
    s16 case8_max3;
    s16 case8_max1;

    if (object == 0) {
        return;
    }
    value = 0;
    if (subject == fn_80201AE4()) {
        local_player = 1;
    } else {
        flags &= ~0xF;
        flags |= 1;
        local_player = 0;
    }
    if (*(u8*)((u8*)fn_80201B8C(object) + 0x9F) == 13) {
        return;
    }

    switch (flags & 0xF) {
    case 1:
        if (fn_80038464(object, 3, &case1_max3)) {
            fn_800389E0(object, 3, case1_max3, 0);
        }
        fn_80038308(object, 0, &case1_current);
        fn_80038464(object, 0, &case1_max);
        switch (flags & 0x70000) {
        case 0x10000:
            value = (s16)(0.25 * case1_max + case1_current);
            break;
        case 0x20000:
            value = (s16)(0.4 * case1_max + case1_current);
            break;
        case 0x40000:
            value = case1_max;
            break;
        }
        fn_800389E0(object, 0, value, local_player);
        break;
    case 2:
        fn_80038308(object, 2, &case2_current);
        switch (flags & 0x70000) {
        case 0x10000:
            value = case2_current + 30;
            break;
        case 0x20000:
            value = case2_current + 40;
            break;
        case 0x40000:
            value = case2_current + 50;
            break;
        }
        fn_800389E0(object, 2, value, local_player);
        break;
    case 4:
        fn_80038308(object, 1, &case4_current);
        fn_80038464(object, 1, &case4_max);
        switch (flags & 0x70000) {
        case 0x10000:
            value = (s16)(0.25 * case4_max + case4_current);
            break;
        case 0x20000:
            value = (s16)(0.4 * case4_max + case4_current);
            break;
        case 0x40000:
            value = case4_max;
            break;
        }
        fn_800389E0(object, 1, value, local_player);
        break;
    case 8:
        if (fn_80038464(object, 3, &case8_max3)) {
            fn_800389E0(object, 3, case8_max3, 0);
        }
        fn_80038308(object, 0, &case8_current0);
        fn_80038308(object, 1, &case8_current1);
        fn_80038464(object, 0, &case8_max0);
        fn_80038464(object, 1, &case8_max1);
        switch (flags & 0x70000) {
            case 0x10000:
                value0 = (s16)(0.25 * case8_max0 + case8_current0);
                value1 = (s16)(0.25 * case8_max1 + case8_current1);
                break;
            case 0x20000:
                value0 = (s16)(0.4 * case8_max0 + case8_current0);
                value1 = (s16)(0.4 * case8_max1 + case8_current1);
                break;
            case 0x40000:
                value0 = case8_max0;
                value1 = case8_max1;
                break;
        }
        fn_800389E0(object, 0, value0, local_player);
        fn_800389E0(object, 1, value1, local_player);
        break;
    }
}
