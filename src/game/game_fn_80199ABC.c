typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern u8 fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8017DCA8(void*, s16, void*);
extern int fn_80180454(void*);

int fn_80199ABC(u8* object)
{
    int count;
    u8* entry;
    int index = 0;

    entry = *(u8**)(object + 0x4c);
    count = object[1];

    for (; index < count; index++) {
        if (entry[0] != 0) {
            if (!fn_8018E26C(entry, entry + 0x2b)) {
                fn_80180518(object + 0x24, (u8)index, 0);
            }
            fn_8017DCA8(entry + 0xa, *(s16*)(entry + 0x1c), entry + 0x10);
        }
        entry += 0x38;
    }
    if (fn_80180454(object + 0x24)) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xa))++;
    return 0;
}
