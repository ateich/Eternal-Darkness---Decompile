typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Data {
    u8 pad[4];
    signed char divisor;
} Data;

extern void fn_8018E230(u8*, u8*, int, int, int, int);
extern void fn_8018E26C(u8*, u8*);
extern void fn_8018E1C4(u8*, u8, u8, u8);
extern void fn_8019B8B4(void);

int fn_80190680(u8* data)
{
    u8* object = *(u8**)(data + 0x4C);

    if ((*(s32*)(data + 0x94) == 0 && *(u16*)(data + 0xA) == *(u16*)(data + 0xC)) ||
        *(s32*)(data + 0x98) == 0) {
        if (*(s32*)(data + 0x9C) != 0) {
            int one = 1;
            signed char divisor = ((Data*)data)->divisor;
            int zero = 0;
            object[0x2B] = (u8)(((int)object[0x2B] / divisor) * divisor);
            fn_8018E230(object, object + 0x2B, one, object[0x2B], data[4], zero);
        } else {
            fn_8018E230(object, object + 0x2B, 1, data[2], data[4], 0);
        }
        *(void (**)(void))(data + 0x14C) = fn_8019B8B4;
    } else if (object[0] == 4) {
        fn_8018E26C(object, object + 0x2B);
    } else if (*(s32*)(data + 0x9C) != 0 && *(u16*)(data + 0xA) >= data[0x92]) {
        fn_8018E1C4(data, data[0x90], data[0x93], data[0x91]);
    }

    (*(u16*)(data + 0xA))++;
    return 0;
}
