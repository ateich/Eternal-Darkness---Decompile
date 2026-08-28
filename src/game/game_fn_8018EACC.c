typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct WordTriple {
    u32 x;
    u32 y;
    u32 z;
} WordTriple;

extern float lbl_80650AC0;

extern int fn_8013F680(u8*);
extern void fn_8013F6DC(u8*, u8*);
extern u8* fn_8017E40C(u8*, s16, float, u8*);
extern int fn_80180430(u8*, u8);
extern int fn_80180454(u8*);
extern void fn_80180518(u8*, u8, int);
extern int fn_8018E230(u8*, u8*, int, u8, u8, int);
extern u8 fn_8018E26C(u8*, u8*);
extern void fn_80189C14(void);

int fn_8018EACC(u8* object)
{
    u8* record = *(u8**)(object + 0x4C);
    u8 count = object[1];
    int i = 0;

    for (; i < count; record += 0x38, i++) {
        u8* found;

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
            found = fn_8017E40C(record + 0xA, *(s16*)(record + 0x1C),
                                lbl_80650AC0, record + 0x10);
            if (found == 0) {
                continue;
            }
            if (fn_8013F680(found + 0x14) == 2) {
                *(s16*)(record + 0x1E) |= 1;
            } else {
                *(u16*)(record + 0x10) = 0;
                *(u16*)(record + 0x12) = 0;
                *(u16*)(record + 0x14) = 0;
                *(s16*)(record + 0x1E) |= 1;
            }

            if (count == 1) {
                fn_8013F6DC(object + 0x94, found);
                *(WordTriple*)(object + 0xB8) = *(WordTriple*)(found + 0x14);
                *(void (**)(void))(object + 0x148) = fn_80189C14;
            }
        } else if (record[0] == 0 &&
                   *(u16*)(object + 0xA) >= *(u16*)(record + 8)) {
            fn_8018E230(record, record + 0x2B, 1, object[2], object[4], 0);
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
