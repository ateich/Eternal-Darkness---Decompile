typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Voice Voice;
struct Voice {
    u8 bytes[0x404];
};

#define U8(v, n)  (*(u8*)((v)->bytes + (n)))
#define U16(v, n) (*(u16*)((v)->bytes + (n)))
#define U32(v, n) (*(u32*)((v)->bytes + (n)))

extern Voice* lbl_8064D3D0;
extern Voice* lbl_8064D43C;
extern void* fn_801BCEB0(u16);
extern u16 fn_801B8D68(u8, u8);
extern s32 fn_801C1790(u8, u8, u16, u8);
extern void fn_801C106C(Voice*);
extern void fn_801C08E8(Voice*, u32);
extern s32 fn_801CC6DC(s32);
extern void fn_801CAEB8(u8, u8, u8);
extern void fn_801CB274(u8, u8);
extern void fn_801C1600(Voice*, u8);
extern s32 fn_801C13D4(Voice*, u8);
extern void fn_801CC8C4(s32);
extern void fn_801C1BCC(Voice*);

s32 fn_801C0BC8(u16 flags, u8 pitch, u8 arg2, u16 arg3, u8 options,
                 u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u16 arg10,
                 u8 arg11, u8 resolve, u8 arg13, u8 arg14, u32 arg15)
{
    void* resource;
    Voice* voice;
    s32 index;
    s32 result;
    u8 special;

    resource = fn_801BCEB0(flags);
    if (resource == 0)
        return -1;

    special = options & 0x80;
    if (!special) {
        u16 mapped = fn_801B8D68(arg8, arg7);
        if (mapped != 0xFFFF)
            pitch = (u8)mapped;
    }

    index = fn_801C1790(pitch, arg2, arg3, special != 0);
    if (index == -1)
        return -1;

    voice = &lbl_8064D3D0[index];
    fn_801C106C(voice);
    if (U32(voice, 0x4C) != 2) {
        fn_801C08E8(voice, 1);
        U32(voice, 0x4C) = 2;
    }

    U32(voice, 0x118) = (U32(voice, 0x118) & 0x10) | 2;
    U32(voice, 0x114) = 0;
    if (fn_801CC6DC(index))
        U32(voice, 0x118) |= 1;

    U32(voice, 0x98) = 0;
    U32(voice, 0x9C) = 0;
    if (special) {
        U8(voice, 0x11D) = 1;
        options &= 0x7F;
        fn_801CAEB8((u8)index, 0xFF, 1);
        fn_801CB274((u8)index, 0xFF);
        U8(voice, 0x20A) = (u8)index;
        U8(voice, 0x20B) = 0xFF;
        U8(voice, 0x20C) = 0;
    } else {
        U8(voice, 0x11D) = 0;
        U8(voice, 0x20A) = arg7;
        U8(voice, 0x20B) = arg8;
        U8(voice, 0x20C) = arg9;
    }

    U16(voice, 0x102) = flags;
    U16(voice, 0x100) = arg3;
    U32(voice, 0x110) = 30000 << 16;
    U16(voice, 0x10E) = 1024;
    U32(voice, 0x34) = (u32)resource;
    U32(voice, 0x38) = (u32)resource + arg10 * 8;
    U16(voice, 0x12C) = options;
    U8(voice, 0x12E) = 0;
    U8(voice, 0x12F) = options;
    U8(voice, 0x208) = arg5;
    U8(voice, 0x209) = arg6;
    U8(voice, 0x20D) = arg11;
    U8(voice, 0x20E) = arg13;
    U8(voice, 0x20F) = arg14;
    U8(voice, 0x210) = arg15 ? resolve : 1;
    U8(voice, 0x3EC) = U8(voice, 0x3ED) = U8(voice, 0x3EE) = 0;
    U32(voice, 0xF4) = ((u32)flags << 16) | ((u32)options << 8) | index;

    fn_801C1600(voice, pitch);
    result = fn_801C13D4(voice, resolve);
    if (result != -1)
        return result;

    if (fn_801CC6DC(index))
        fn_801CC8C4(index);
    fn_801C1BCC(voice);
    return -1;
}
