typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern int fn_80180430(void*, u8);
extern void fn_80180518(void*, u8, int);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, u8, u8, int);

int fn_8019CC28(u8* object)
{
    register u8* cursor;
    register int count;
    register u8* transform;
    register u8* entry;
    register int i;

    transform = object + 0x8C;
    cursor = transform;
    entry = *(u8**)(object + 0x4C);
    count = object[1];
    for (i = 0; i < count; entry += 0x38, cursor += 2, i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            if (entry[0] != 0 && !fn_8018E26C(entry, entry + 0x2B)) {
                *(u16*)(cursor + 0x28) = 0;
                fn_80180518(object + 0x24, (u8)i, 0);
            }
            if (*(u16*)(object + 0xA) == *(u16*)(entry + 8)) {
                fn_8018E230(entry, entry + 0x2B, 1, object[2], object[4], 0);
            }
        } else {
            if (entry[0] != 0 && !fn_8018E26C(entry, entry + 0x2B)) {
                fn_80180518(object + 0x24, (u8)i, 1);
            }
            if (*(u16*)(cursor + 0x28) != 0) {
                *(u16*)(cursor + 0x28) -= 1;
                if (*(u16*)(cursor + 0x28) == 0) {
                    *(s16*)(entry + 0x10) = (s16)((float)*(s16*)(entry + 0xA) - *(float*)(transform + 0x38));
                    *(s16*)(entry + 0x12) = (s16)((float)*(s16*)(entry + 0xC) - *(float*)(transform + 0x3C));
                    *(s16*)(entry + 0x14) = (s16)*(float*)(transform + 0x40);
                    fn_8018E230(entry, entry + 0x2B, 1, 0, 0x19, 0xC8);
                }
            }
        }
    }
    *(u16*)(object + 0xA) += 1;
    if (*(u16*)(object + 0xA) >= *(u16*)(object + 0xC))
        *(u16*)(object + 0x22) = 8;
    return 0;
}
