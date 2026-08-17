typedef unsigned char u8;
extern int fn_8012948C(void*);
extern void fn_80129CE8(void*, u8*, int, int, int);
extern void fn_801299DC(u8*, int*);
extern void fn_80129BA4(u8*, float, float);
extern float lbl_806501A8;

u8* fn_80129878(void* owner, int kind, int flags, int* position, float scale)
{
    u8* entry = 0;
    int index = fn_8012948C(owner);
    if (index >= 0) {
        entry = *(u8**)((u8*)owner + 0x40) + index * 0x110;
        fn_80129CE8(owner, entry, kind, flags, 5);
        fn_801299DC(entry, position);
        if ((*(int*)(entry + 0xF4) & 0x40) == 0) fn_80129BA4(entry, lbl_806501A8, scale);
        *(unsigned short*)(entry + 0xFC) = 2;
    }
    return entry;
}
