typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8018E230(void*, void*, int, int, int, int);
extern int fn_8019B8B4(void*);

int fn_80190D0C(u8* data)
{
    if (*(u16*)(data + 0xA) >= *(u16*)(data + 0xC)) {
        u8* object = *(u8**)(data + 0x4C);

        fn_8018E230(object, object + 0x2B, 1, data[2], data[4], 0);
        *(void**)(data + 0x14C) = fn_8019B8B4;
    }
    (*(u16*)(data + 0xA))++;
    return 0;
}
