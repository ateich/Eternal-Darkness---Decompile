typedef unsigned char u8;

extern void fn_8019D560(u8*);

void fn_8019D620(u8* config)
{
    fn_8019D560(config);
    config[0x18] = 0x60;
    config[0x19] = 0x60;
    config[0x1A] = 0x60;
    config[0x1B] = 0x80;
    config[0x21] = 0;
}
