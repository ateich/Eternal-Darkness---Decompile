typedef unsigned char u8;

extern void *fn_80201B8C();

void* fn_8008C778(void* object)
{
    u8* info = *(u8**)((u8*)fn_80201B8C(object) + 0x48);
    return *(void**)info;
}
