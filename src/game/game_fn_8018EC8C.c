typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern float lbl_80650AC0;

extern int fn_8017E32C(u8*, s16, float, u8*, u8);
extern int fn_80180430(u8*, u8);
extern int fn_80180454(u8*);
extern void fn_80180518(u8*, u8, int);
extern int fn_8018E230(u8*, u8*, int, int, int, int);
extern u8 fn_8018E26C(u8*, u8*);

int fn_8018EC8C(u8* object)
{
    u8* record;
    u8 special;
    int i;
    u8 count;

    i = 0;
    record = *(u8**)(object + 0x4C);
    special = object[0x8D];
    count = object[1];

    for (; i < count; record += 0x38, i++) {
        if (!fn_80180430(object + 0x24, (u8)i)) {
            continue;
        }
        if (record[0] != 0 && !fn_8018E26C(record, record + 0x2B)) {
            fn_80180518(object + 0x24, (u8)i, 0);
        }
        if (!fn_80180430(object + 0x24, (u8)i)) {
            continue;
        }

        if (!(*(s16*)(record + 0x1E) & 1)) {
            *(s16*)(record + 0x1E) |=
                fn_8017E32C(record + 0xA, *(s16*)(record + 0x1C),
                            lbl_80650AC0, record + 0x10, special);
        } else if (record[0] == 0 &&
                   *(u16*)(object + 0xA) >= *(u16*)(record + 8)) {
            fn_8018E230(record, record + 0x2B, 1, 0xF0, -0x50, 0);
        }
    }

    (*(u16*)(object + 0xA))++;
    if ((object[0x60] != 0 &&
         !fn_8018E26C(object + 0x60, object + 0x5F)) ||
        fn_80180454(object + 0x24)) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}
