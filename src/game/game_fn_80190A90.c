typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

extern void* lbl_8064D224;
extern float lbl_80650B14;
extern u8 lbl_80607130[];
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void fn_801805E0(void*, int, int, int, void*, float);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern void fn_8018CFB4(void*, void*);
extern void fn_8018CD18(void*, int, int);
extern void fn_8018C540(void*, void*, int, int, int);
extern void fn_801F5A04(void*, int, void*, void*);
extern void* memset(void*, int, unsigned int);

void fn_80190A90(u8* data, void* arg1, void* arg2, u8* config)
{
    u32 value;
    u8* object;
    u8* table;

    object = *(u8**)(data + 0x4C);
    data[0] = 0x80;
    data[1] = 1;
    data[2] = config[2];
    data[4] = config[3];
    *(s16*)(data + 0xE) = *(s16*)(config + 4);
    *(u16*)(data + 0xC) = *(u16*)(config + 6);
    *(void**)(data + 0x68) = lbl_8064D224;
    *(u16*)(data + 0xA) = 0;
    *(u32*)(data + 0x44) = 0;
    data[7] = 0xFF;
    memset(data + 0x24, 0, 0x10);

    value = *(u32*)(config + 0x10);
    fn_801805E0(object + 0x20, 4, config[1], 0, &value, lbl_80650B14);
    fn_8018E230(object, object + 0x2B, 1, 0, (signed char)config[0x14], config[0x15]);
    fn_8018CFB4(*(void**)(data + 0x50), config + 0x1C);

    table = lbl_80607130;
    fn_8018CD18(*(void**)(data + 0x54), 1, *(u16*)(table + 2));
    fn_8018C540(*(void**)(data + 0x58), &value, 1, 4, *(u16*)(table + 2));
    if (*(s16*)(config + 4) >= 0) {
        fn_801F5A04(data + 0x6C, *(s16*)(config + 4), lbl_80606328, lbl_80606318);
    }
}
