typedef unsigned char u8;

extern void fn_80128C50(u8*);
extern u8* fn_8012A13C(void*, int);

void fn_80129CE8(void* owner, u8* entry, int value, int flags, int kind)
{
    u8* resource;
    fn_80128C50(entry);
    resource = fn_8012A13C(owner, value);
    *(int*)(entry + 0xF0) = value;
    *(u8**)(entry + 0xB8) = resource;
    *(int*)(entry + 0xF4) = flags;
    *(unsigned short*)(entry + 0xFA) = kind;
    entry[0x101] = resource[0xC];
    *(int*)(entry + 0xC8) = *(int*)((u8*)owner + 0x258);
}
