typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern const float lbl_80650C48;

extern void fn_8017E850(void*, void*, s16, void*, float);
extern void fn_8017E958(void*, void*, s16, float);
extern void fn_8017E734(void*, void*, void*, void*, void*);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern u32 fn_80201814(void*);
extern int fn_80201B5C(void);

int fn_8019D390(u8* object)
{
    u8* entry;
    int i;

    if (*(int*)(object + 0x8C) == 0) {
        *(u16*)(object + 0x22) = 8;
        *(u32*)(object + 0x8C) = 1;
    } else {
        entry = *(u8**)(object + 0x4C);
        fn_8017E850(entry + 0xA, object + 0x10,
                    *(s16*)(object + 0x94), object + 0xA0,
                    *(float*)(object + 0xA4));
        if (entry[0] != 0) {
            fn_8018E26C(entry, entry + 0x2B);
        }

        fn_8017E958(entry + 0x42, object + 0x10,
                    *(s16*)(object + 0x94),
                    lbl_80650C48 + *(float*)(object + 0xA0));
        if (entry[0x38] != 0) {
            fn_8018E26C(entry + 0x38, entry + 0x63);
        }

        entry += 0x70;
        for (i = 0; i < 3; i++, entry += 0x38) {
            if (entry[0] != 0) {
                fn_8018E26C(entry, entry + 0x2B);
            }
            fn_8017E734(entry + 0xA, object + 0x10, entry + 0x10,
                        object + 0x96, entry + 0x16);
        }

        if (object[0x60] != 0) {
            if (fn_8018E26C(object + 0x60, object + 0x5F) == 0) {
                *(u16*)(object + 0x22) = 8;
            }
        } else if (!fn_80201814(*(void**)(object + 0x9C)) ||
                   fn_80201B5C() == 0x15) {
            fn_8018E230(object + 0x60, object + 0x5F, 1,
                        object[2], object[4], 0);
        }
    }

    (*(u16*)(object + 0xA))++;
    return 1;
}
