typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_80180430(void*, u8);
extern int fn_80180454(void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8017D700(void*, void*, s16, void*, u8, u8, u8, u8);
extern int fn_8017E2B0(void*, void*, u8);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern void* fn_80201814(void*);

int fn_80192318(u8* object)
{
    u8 count;
    u8* entry;
    s32 i;

    count = object[1];
    entry = *(u8**)(object + 0x4C);
    switch (*(u16*)(object + 0xA)) {
    case 79:
        object[0x8C] = 1;
        object[0xAC] = 40;
        break;
    case 89:
        object[0x8C] = 2;
        object[0xAC] = 30;
        break;
    case 99:
        object[0x8C] = 3;
        object[0xAC] = 20;
        break;
    case 109:
        object[0x8C] = 2;
        object[0xAC] = 10;
        break;
    case 119:
        object[0x8C] = 1;
        object[0xAC] = 8;
        break;
    case 129:
        object[0x8C] = 1;
        object[0xAC] = 4;
        break;
    }

    for (i = 0; i < count; entry += 0x38, i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            fn_8017D700(entry + 0xA, object + 0x10, 0, entry + 0x10,
                        object[0x8C], object[0xAC],
                        object[0x8C], object[0xAC]);
            if (fn_8017E2B0(entry + 0xA, object + 0x10, object[0xB4])) {
                entry[0x2B] = 0;
                fn_80180518(object + 0x24, (u8)i, 0);
            }
        }
    }

    if ((object[0xB7] & 2) ||
        *(u16*)(object + 0xA) != *(u16*)(object + 0xC)) {
        if (fn_80201814(*(void**)(object + 0xC8)) != 0 &&
            fn_80180454(object + 0x24) == 0)
            goto alive;
    }
    object[0xB7] &= ~1;
alive:
    if (object[0x60]) {
        if (!fn_8018E26C(object + 0x60, object + 0x5F) &&
            !(object[0xB7] & 1)) {
            *(u16*)(object + 0x22) = 8;
        }
    } else if (!(object[0xB7] & 1)) {
        if (object[0x5F]) {
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        } else {
            *(u16*)(object + 0x22) = 8;
        }
    } else if (object[0xB7] & 0x20) {
        object[0xB7] &= ~0x20;
        if (object[0x5F]) {
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        }
    } else if (object[0xB7] & 0x40) {
        unsigned int current;

        object[0xB7] &= ~0x40;
        current = object[0x5F];
        if (current == object[2])
            goto done;
        fn_8018E230(object + 0x60, object + 0x5F, 1, 0,
                    (s8)-object[4], object[2]);
    }
done:
    (*(u16*)(object + 0xA))++;
    return 1;
}
