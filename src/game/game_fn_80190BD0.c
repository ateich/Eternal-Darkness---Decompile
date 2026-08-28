typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E1C4(void*, int, int, int);
extern int fn_80190680(void*);

int fn_80190BD0(u8* data)
{
    u8* object = *(u8**)(data + 0x4C);

    if (!fn_8018E26C(object, object + 0x2B)) {
        if (*(int*)(data + 0x9C) != 0 && *(u16*)(data + 0xA) >= data[0x92]) {
            fn_8018E1C4(data, data[0x90], data[0x93], data[0x91]);
        }
        *(void**)(data + 0x14C) = fn_80190680;
    }
    (*(u16*)(data + 0xA))++;
    return 0;
}
