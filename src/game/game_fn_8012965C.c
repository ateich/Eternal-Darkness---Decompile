typedef unsigned char u8;

extern u8* fn_80128E30(void*);
extern void fn_80129CE8(void*, u8*, int, int, int);
extern void fn_80129DE0(void*, u8*, int, int);

u8* fn_8012965C(void* owner, int kind, int flags, int mode)
{
    u8* entry = fn_80128E30(owner);
    u8* resource = *(u8**)(entry + 0xB8);
    if (resource != 0) {
        *(*(u8**)((u8*)owner + 0x40) + 0x884) = resource[0xD];
    }
    fn_80129CE8(owner, entry, kind, flags, mode);
    fn_80129DE0(owner, entry, !(flags & 0x10000), 1);
    return entry;
}
