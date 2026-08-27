typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);
extern void fn_801854B4(u8*, u8, u8);
extern void fn_8018E230(u8*, u8*, int, int, int, int);

int fn_8018560C(u8* self)
{
    u8 count;
    u8* header;
    u8* records;
    int i;
    u8* current;
    u8* previous;
    u8 active;
    int capped;

    header = self + 0x98;
    records = *(u8**)(self + 0x4C);
    count = self[1];
    *(u16*)(self + 0xA) += 1;

    if (*(u16*)(header + 0xC) & 1) {
        active = self[0x92];
        if (active >= 2) {
            i = active;
            current = records + (active - 1) * 0x38;
            previous = current - 0x38;
            while (i > 1) {
                memcpy(current + 0xA, previous + 0xA, 6);
                current -= 0x38;
                previous -= 0x38;
                i--;
            }
        }
        memcpy(records + 0xA, header, 6);
        *(u16*)(header + 0xC) &= ~1;
        fn_801854B4(self, 0xFE, 1);
        self[0x92]++;
        capped = self[0x92];
        if (capped > count - 1)
            capped = count - 1;
        self[0x92] = capped;
    }

    if (*(u16*)(header + 0xC) & 0x10) {
        u8* record = records;
        int zero = 0;
        for (i = 0; i < count; i++, record += 0x38) {
            if (record[0] != 0) {
                int value = record[0x2B] + (s8)record[5];
                if (value <= 0) {
                    record[0] = zero;
                    record[0x2B] = zero;
                } else {
                    record[0x2B] = value;
                }
            }
        }
    }

    if (*(u16*)(header + 0xC) & 8) {
        *(u16*)(header + 0xC) |= 0x10;
        *(u16*)(header + 0xC) &= ~8;
        for (i = 0; i < count; records += 0x38, i++) {
            fn_8018E230(records, records + 0x2B, 1, records[0x2B], self[4], 0);
        }
    }

    if (*(u16*)(header + 0xC) & 2)
        *(u16*)(self + 0x22) = 8;
    return 0;
}
