typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#pragma pack(push, 1)
typedef struct SixBytes {
    u32 word;
    u16 half;
} SixBytes;
#pragma pack(pop)

extern u32 lbl_80651D00;
extern u16 lbl_80651D04;
extern void* lbl_8064D224;
extern float lbl_806509C8;
extern u32 lbl_802FC5BC[];
extern u8 lbl_80607120[];
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void fn_80179904(void*, s16);
extern void fn_801804AC(void*, void*, void*, void*);
extern void fn_80180554(void*, void*, void*, void*, u16, int);
extern void fn_801805E0(void*, int, u8, u8, void*, float);
extern void fn_80180518(void*, u8, int);
extern void fn_8018CB70(void*, u8, u16);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);
extern void* memset(void*, int, u32);
extern void* memcpy(void*, const void*, u32);

void fn_80183068(u8* self, void* arg1, void* arg2, u8* desc)
{
    void* table;
    u8 i;
    u8 count;
    u8* entry;
    SixBytes position;
    SixBytes setup;

    setup.word = lbl_80651D00;
    setup.half = lbl_80651D04;
    entry = *(u8**)(self + 0x4C);
    memcpy(&position, arg2, 6);
    fn_80179904(&position, 8);
    fn_801804AC(self, arg1, &position, &setup);
    self[0] = 0x80;
    self[2] = desc[2];
    self[4] = desc[3];
    *(u16*)(self + 0xC) = *(u16*)(desc + 6);
    *(u16*)(self + 0xA) = 0;
    *(u32*)(self + 0x44) = 0;
    *(u16*)(self + 0xE) = 8;
    *(void**)(self + 0x68) = lbl_8064D224;
    count = (*(u16*)(desc + 6) >> 3) + 1;
    self[1] = count;
    memset(self + 0x24, 0, 0x10);
    fn_80180518(self + 0x24, 0, 1);

    table = &lbl_802FC5BC[3];
    for (i = 0; i < count; entry += 0x38, i++) {
        fn_80180554(entry, arg1, &position, &setup, *(u16*)(desc + 8), 0);
        fn_801805E0(entry + 0x20, 4, desc[1], i * 4, table, lbl_806509C8);
    }
    fn_8018CB70(*(void**)(self + 0x54), count, *(u16*)(lbl_80607120 + 2));
    fn_8018C540(*(void**)(self + 0x58), table, count, 4,
                *(u16*)(lbl_80607120 + 2));
    *(u16*)(self + 0x22) = 4;
    if (*(s16*)(desc + 4) >= 0) {
        fn_801F5A04(self + 0x6C, *(s16*)(desc + 4), lbl_80606328,
                    lbl_80606318);
    }
}
