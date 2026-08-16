typedef unsigned char u8;
typedef unsigned short u16;

extern void*fn_80201B8C();

u16 fn_8008C750(void* object)
{
    u8* info = *(u8**)((u8*)fn_80201B8C(object) + 0x48);
    return *(u16*)(info + 6);
}
