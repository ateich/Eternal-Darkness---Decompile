typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u8* lbl_8064D3D0;
extern u16 fn_801CAFAC(s32, u32, u8);
extern s32 fn_801B5C14(u8, u8, u8, u32, s32*);
extern s32 fn_801C0BC8(u32, u8, u32, u32, u32, u8, u8, u8, u8, u8,
                      u16, u16, u32, u8, u8, u32);
extern s32 fn_801B6270(void*, s16, u32, u32, u32, u8, u8, u8, u8, u8,
                       u16, u16, u32, u8, u8, u32);
extern s32 fn_801B5E9C(void*, s16, u32, u32, u32, u8, u8, u8, u8, u8,
                       u16, u16, u32, u8, u8, u32);
extern u32 fn_801C14D0(s32);

s32 fn_801B64D0(u32 flags, s32 pitch, u32 arg2, u32 arg3, u32 key,
                 u8 velocity, u8 channel, u8 arg7, u8 arg8, u16 arg9,
                 u16 arg10, u8 arg11, s16 pitch_add, u8 arg13, u32 arg14)
{
    s32 result;
    u32 next;
    u8 new_pitch = pitch + pitch_add;

    if (new_pitch > 255)
        new_pitch = 255;

    switch (flags & 0xC000) {
    case 0:
    {
        s32 status;
        if (fn_801CAFAC(0x41, channel, arg7) > 0x1F80) {
            result = fn_801B5C14(key & 0x7F, channel, arg7, 1, &status);
            next = !status;
        } else {
            result = -1;
            next = 1;
        }
        if (!next)
            return -1;
        if (result != -1)
            return result;
        return fn_801C0BC8(flags, (u8)new_pitch, arg2, flags, arg3, key,
                           velocity, channel, arg7, arg8, arg9, arg10, 1,
                           arg11, arg13, arg14);
    }
    case 0x4000:
        result = fn_801B6270((void*)flags, new_pitch, arg2, flags, arg3,
                             key, velocity, channel, arg7, arg8, arg9, arg10,
                             1, arg11, arg13, arg14);
        if (result != -1) {
            next = fn_801C14D0(result);
            while (next != 0xFFFFFFFF) {
                (lbl_8064D3D0 + (u8)next * 0x404)[0x11C] = 0;
                next = *(u32*)(lbl_8064D3D0 + (u8)next * 0x404 + 0xEC);
            }
        }
        return result;
    case 0x8000:
        result = fn_801B5E9C((void*)flags, new_pitch, arg2, flags, arg3, key,
                             velocity, channel, arg7, arg8, arg9, arg10, 1,
                             arg11, arg13, arg14);
        if (result != -1) {
            next = fn_801C14D0(result);
            while (next != 0xFFFFFFFF) {
                (lbl_8064D3D0 + (u8)next * 0x404)[0x11C] = 0;
                next = *(u32*)(lbl_8064D3D0 + (u8)next * 0x404 + 0xEC);
            }
        }
        return result;
    }
    return -1;
}
