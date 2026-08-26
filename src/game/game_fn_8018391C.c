typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80182FA8(u8*);
extern void* fn_80182FCC(void*, u16*, u8*);
extern void fn_8017FF1C(void*, int);

void fn_8018391C(void* self, u16* position, u8* desc)
{
    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
    fn_80182FA8(desc);
    desc[2] = 0x46;
    *(s8*)(desc + 3) = -7;
    *(u16*)(desc + 6) = 0x14;
    fn_8017FF1C(fn_80182FCC(self, position, desc), 4);
}
