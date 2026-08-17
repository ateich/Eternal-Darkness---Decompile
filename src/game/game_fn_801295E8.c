typedef unsigned char u8;

extern int fn_8012948C(void*);
extern void fn_80129CE8(void*, u8*, int, int, int);

u8* fn_801295E8(void* owner, int kind, int flags, int mode)
{
    u8* result = 0;
    int index = fn_8012948C(owner);
    if (index >= 0) {
        result = *(u8**)((u8*)owner + 0x40) + index * 0x110;
        fn_80129CE8(owner, result, kind, flags, mode);
        *(unsigned short*)(result + 0xFC) = 2;
    }
    return result;
}
