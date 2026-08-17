typedef unsigned char u8;

extern int fn_8012948C(void*);
extern void fn_80129CE8(void*, u8*, int, int, int);
extern void fn_80129BA4(u8*, float, float);

u8* fn_80129AF4(void* owner, int value, int flags, float a, float b)
{
    u8* entry = 0;
    int index = fn_8012948C(owner);
    if (index >= 0) {
        entry = *(u8**)((u8*)owner + 0x40) + index * 0x110;
        fn_80129CE8(owner, entry, value, flags, 5);
        fn_80129BA4(entry, a, b);
        *(unsigned short*)(entry + 0xFC) = 2;
    }
    return entry;
}
