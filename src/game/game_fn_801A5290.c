typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_80180430(void*, u8);
extern int fn_80180454(void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8018E230(void*, void*, int, int, u8, u8);
extern u8 fn_8018E26C(void*, void*);

int fn_801A5290(u8* object)
{
    u8* record;
    unsigned int count;
    u8* records;
    unsigned int i;
    int j;

    i = 0;
    records = *(u8**)(object + 0x4c);
    count = object[1];
    record = records;
    for (; i < count; record += 0x38, i++) {
        if (fn_80180430(object + 0x24, (u8)i) != 0 &&
            record[0] != 0 && !fn_8018E26C(record, record + 0x2b) &&
            record[0x2b] == 0) {
            fn_80180518(object + 0x24, (u8)i, 0);
        }
    }

    if (*(u16*)(object + 0xc) != 0 &&
        *(u16*)(object + 0xa) >= *(u16*)(object + 0xc)) {
        record = records;
        j = 0;
        for (; j < (int)count; record += 0x38, j++) {
            if (fn_80180430(object + 0x24, (u8)j) != 0 &&
                record[0] == 0) {
                fn_8018E230(record, record + 0x2b, 1, record[0x2b],
                            object[4], 0);
            }
        }
    }

    (*(u16*)(object + 0xa))++;
    if (fn_80180454(object + 0x24) != 0)
        *(u16*)(object + 0x22) = 8;
    return 0;
}
