typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8 lbl_80619C20[];
extern u8* lbl_8064D3D0;
extern int fn_801CC6DC(u32);
extern void fn_801C106C(void*);
extern int fn_801C13D4(void*, void*);
extern void fn_801C26F8(void*);
extern void fn_801CB470(u8, u8, u8);

s32 fn_801B5C14(u8 value, u8 owner, u8 channel, void* arg, s32* status)
{
    u32 i;
    s32 selected = -1;
    u32 saved_handle = 0;
    u8* selected_voice = 0;
    s32 found_special = 0;

    for (i = 0; i < lbl_80619C20[0x210]; i++) {
        u8* voice = lbl_8064D3D0 + i * 0x404;
        u64 flags;
        u32 handle;

        if (voice[0x11C] != 0)
            continue;
        handle = *(u32*)(voice + 0xF4);
        if (handle == 0xFFFFFFFF)
            continue;
        if (voice[0x121] != owner || voice[0x122] != channel)
            continue;

        flags = *(u64*)(voice + 0x114);
        if (flags & 2)
            found_special = 1;
        if (!(flags & 0x10))
            continue;
        if ((flags & 0x108ULL) == 8)
            continue;
        if (!fn_801CC6DC(i))
            continue;

        if (selected == -1 && flags == 0x20002ULL) {
            *status = 1;
            return -1;
        }

        *(u32*)(voice + 0x138) = ((u16)*(u16*)(voice + 0x12C) << 16)
            + (((s8)voice[0x12E] << 16) / 100);
        voice[0x130] = *(u16*)(voice + 0x12C);
        *(u16*)(voice + 0x12C) = (u8)*(u16*)(voice + 0x12C) - voice[0x12F] + value;
        voice[0x12F] = value;
        voice[0x12E] = 0;
        *(u32*)(voice + 0x13C) = 0;
        *(u64*)(voice + 0x114) = flags | 0x20000ULL;
        fn_801C106C(voice);

        if (selected == -1) {
            *(u32*)(voice + 0xEC) = 0xFFFFFFFF;
            *(u32*)(voice + 0xF0) = 0xFFFFFFFF;
            selected = fn_801C13D4(voice, arg);
            saved_handle = handle;
            selected_voice = voice;
        } else {
            *(u32*)(lbl_8064D3D0 + (saved_handle & 0xFF) * 0x404 + 0xEC) = handle;
            *(u32*)(voice + 0xF0) = saved_handle;
            saved_handle = handle;
            fn_801C13D4(voice, 0);
        }
    }

    if (selected != -1) {
        fn_801C26F8(selected_voice);
        fn_801CB470(selected_voice[0x121], selected_voice[0x122],
                    (u8)*(u16*)(selected_voice + 0x12C));
        *status = 0;
    } else {
        *status = found_special;
    }
    return selected;
}
