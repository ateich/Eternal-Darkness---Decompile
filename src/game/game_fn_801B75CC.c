typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8* lbl_8064D3D0;
extern u32 fn_801CC6DC(u32);
extern u16 fn_801CBB30(void*);
extern void fn_801C0738(void*, u32);
extern void fn_801CCB34(u32, u8);
extern void fn_801CCB70(u32);
extern u32 fn_801C2EF0(void*);

#define U8(p, o)  (*(u8*)((p) + (o)))
#define U32(p, o) (*(u32*)((p) + (o)))
#define U64(p, o) (*(u64*)((p) + (o)))

void fn_801B75CC(u32 index)
{
    u8* voice = lbl_8064D3D0 + index * 0x404;

    if (fn_801CC6DC(index) || U32(voice, 0x34) != 0) {
        fn_801C0738(voice, fn_801CBB30(voice) > 0x1F80);

        if (U64(voice, 0x114) & 0x20ULL) {
            U64(voice, 0x114) &= ~0x20ULL;
            U64(voice, 0x114) |= 0x10ULL;
            fn_801CCB34(index, U8(voice, 0x11F));
        }

        if ((U64(voice, 0x114) & 0x10000000090ULL) == 0x90ULL) {
            U64(voice, 0x114) &= ~0x90ULL;
            fn_801CCB70(index);
            if ((U64(voice, 0x114) & 0x20000000000ULL) &&
                fn_801C2EF0(voice + 0x1DC)) {
                U64(voice, 0x114) &= ~0x20000000000ULL;
            }
        }
    }

    if (U8(voice, 0xA8) != 0) {
        U8(voice, 0xA8) = 0;
        U32(voice, 0x214) = 0x1FFF;
    }
}
