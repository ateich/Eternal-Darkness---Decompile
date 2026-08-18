typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8019D560(void*);
extern void* fn_80152F90(void*, void*, void*, u8);

void fn_80153050(void* first, void* second, u8 field0, u8 field1,
                 u16 field6, u16 field8, u8* color, u8 field20,
                 u16 field14, s16 field3, u8 field22, u8 kind)
{
    u8 config[0x90];
    u8 alpha;

    fn_8019D560(config);
    config[0] = field0;
    config[1] = field1;
    *(u16*)(config + 6) = field6;
    *(u16*)(config + 8) = field8;
    config[3] = field3;
    alpha = color[3];
    config[2] = alpha;
    *(u16*)(config + 0x14) = field14;
    config[0x18] = color[0];
    config[0x19] = color[1];
    config[0x1A] = color[2];
    config[0x1B] = alpha;
    config[0x20] = field20;
    config[0x22] = field22;
    fn_80152F90(first, second, config, kind);
}
