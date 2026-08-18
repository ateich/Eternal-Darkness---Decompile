typedef unsigned char u8;
typedef unsigned int u32;

extern void* memset(void*, int, u32);
extern void fn_8019D66C(void);
extern void fn_80152E3C(void);
extern void fn_80152F04(void);
extern void fn_80149B60(void);
extern void fn_8019D560(void*);

void fn_80152D84(u8* config, u8* object, u8 alternate)
{
    memset(config, 0, 0xC0);
    *(u32*)(config + 0x94) = 0;
    *(void (**)(void))(config + 0x90) = fn_8019D66C;
    *(void (**)(void))(config + 0x98) = alternate ? fn_80152F04 : fn_80152E3C;
    *(u32*)(config + 0x9C) = 0;
    *(void (**)(void))(config + 0xA0) = fn_80149B60;
    *(u32*)(config + 0xA4) = 0;
    config[0xBC] = 1;
    object[0] = 1;
    fn_8019D560(config);
    memset(object + 0x88, 0, 0x40);
}
