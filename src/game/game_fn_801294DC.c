typedef unsigned char u8;

extern int fn_801261F4(void*);
extern u8* fn_80128E30(void*);
extern int fn_80129C2C(void*, u8*, int, int, int);
extern void fn_80129CE8(void*, u8*, int, int, int);
extern void fn_80129DE0(void*, u8*, int, int);

u8* fn_801294DC(void* owner, int kind, int flags, int mode)
{
    u8* entry;
    int ok;
    if (*(void**)((u8*)owner + 0x3C) == 0) return 0;
    fn_801261F4(owner);
    entry = fn_80128E30(owner);
    ok = fn_80129C2C(owner, entry, kind, flags, mode);
    if (!ok && **(int**)(entry + 0xB8) == kind && *(unsigned int*)(entry + 0xF4) != (unsigned int)flags &&
        (unsigned short)mode == *(unsigned short*)(entry + 0xFA)) {
        *(int*)(entry + 0xF4) = flags;
    }
    if (ok) {
        u8* resource = *(u8**)(entry + 0xB8);
        if (resource != 0) *(*(u8**)((u8*)owner + 0x40) + 0x884) = resource[0xD];
        fn_80129CE8(owner, entry, kind, flags, mode);
        fn_80129DE0(owner, entry, !(flags & 0x10000), 1);
    } else entry = 0;
    return entry;
}
