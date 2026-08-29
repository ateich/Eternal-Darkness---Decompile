typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_8017FE14(void*, void*);
extern void fn_8019DDBC(void);

void fn_8019DF5C(u8* object)
{
    *(u16*)(object + 0xA) = 0;
    *(u16*)(object + 0xC) = 125;
    *(u32*)(object + 0x44) = 0;
    fn_8017FE14(object, fn_8019DDBC);
}
