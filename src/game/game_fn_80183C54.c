typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);
extern int fn_80180430(void*, u8);
extern int fn_80180454(void*);
extern void fn_8017E1B0(void*, void*);

int fn_80183C54(u8* self)
{
    int count;
    u8* entry;
    int i;

    if ((*(u16*)(self + 0xA) & 1) != 0) {
        entry = *(u8**)(self + 0x4C);
        i = 0;
        count = self[1];
        while (i < count) {
            if (entry[0] != 0 && !fn_8018E26C(entry, entry + 0x2B)) {
                fn_80180518(self + 0x24, i, 0);
            }
            if (fn_80180430(self + 0x24, i) != 0) {
                fn_8017E1B0(entry + 0xA, entry + 0x10);
                if (*(u16*)(self + 0xA) >= 30) {
                    if (*(s16*)(entry + 0x10) > 0) {
                        --*(s16*)(entry + 0x10);
                    } else if (*(s16*)(entry + 0x10) < 0) {
                        ++*(s16*)(entry + 0x10);
                    }
                    if (*(s16*)(entry + 0x12) > 0) {
                        --*(s16*)(entry + 0x12);
                    } else if (*(s16*)(entry + 0x12) < 0) {
                        ++*(s16*)(entry + 0x12);
                    }
                }
            }
            entry += 0x38;
            i++;
        }
        if (fn_80180454(self + 0x24) != 0) {
            *(u16*)(self + 0x22) = 8;
        }
    }
    ++*(u16*)(self + 0xA);
    return 0;
}
