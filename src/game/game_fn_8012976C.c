typedef unsigned char u8;
#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern int fn_80129C2C(void*, u8*, int, int, int);
extern void fn_80129CE8(void*, u8*, int, int, int);
extern void fn_801299DC(u8*, int*);
extern void fn_80129BA4(u8*, float, float);
extern void fn_80129DE0(void*, u8*, int, int);

u8* fn_8012976C(int* position, int kind, int flags, int value, float scale)
{
    u8* entry = fn_80128E30(position);
    if (fn_80129C2C(position, entry, kind, flags, 5)) {
        u8* resource = *(u8**)(entry + 0xB8);
        if (resource) *(*(u8**)((u8*)position + 0x40) + 0x884) = resource[0xD];
        fn_80129CE8(position, entry, kind, flags, 5);
        fn_801299DC(entry, &value);
        *(int*)(entry + 0xD8) = position[0]; *(int*)(entry + 0xDC) = position[1]; *(int*)(entry + 0xE0) = position[2];
        if ((*(int*)(entry + 0xF4) & 0x40) == 0) fn_80129BA4(entry, 1.0f, scale);
        fn_80129DE0(position, entry, (flags & 0x10000) == 0, 1);
    } else entry = 0;
    return entry;
}
