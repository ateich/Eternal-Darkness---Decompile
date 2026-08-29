typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_80180430(void*, u8);
extern int fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8017E1B0(void*, void*);
extern int fn_80180454(void*);

int fn_80199358(u8* object)
{
    u8 count = object[1];
    u8* entry = *(u8**)(object + 0x4c);
    int i = 0;

    for (; i < count; entry += 0x38, i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            if (!(u8)fn_8018E26C(entry, entry + 0x2b)) {
                fn_80180518(object + 0x24, (u8)i, 0);
            }
            fn_8017E1B0(entry + 0xa, entry + 0x10);
        }
    }

    if (fn_80180454(object + 0x24)) {
        *(u16*)(object + 0x22) = 8;
    } else {
        (*(u16*)(object + 0xa))++;
    }
    return 0;
}
