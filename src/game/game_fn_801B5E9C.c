typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct LayerRecord {
    u16 flags;
    u8 key_min;
    u8 key_max;
    s8 transpose;
    u8 velocity_scale;
    s16 pitch_add;
    u8 pan;
    u8 pad[3];
} LayerRecord;

extern u8* lbl_8064D3D0;

extern LayerRecord* fn_801BD15C(void*, u16*);
extern u16 fn_801CAFAC(s32, u32, u8);
extern s32 fn_801B5C14(u8, u8, u8, void*, s32*);
extern s32 fn_801C13C0(void*);
extern s32 fn_801C0BC8(void*, u8, u32, u32, u32, u8, u8, u8, u8, u8,
                       u16, u16, u32, u8, u8, u32);
extern s32 fn_801B6270(void*, s16, u32, u32, u32, u8, u8, u8, u8, u8,
                       u16, u16, u32, u8, u8, u32);

s32 fn_801B5E9C(void* layer, s16 pitch, u32 arg2, u32 arg3, u32 key_flags,
                 u8 velocity, u8 pan_base, u8 owner, u8 channel, u8 arg9,
                 u16 arg10, u16 arg11, u32 resolve, u8 arg13, u8 arg14,
                 u32 arg15)
{
    u16 count;
    LayerRecord* record;
    u32 result = -1;
    u32 previous;

    record = fn_801BD15C(layer, &count);
    while (record != 0 && count != 0) {
        s32 note;
        s32 pan;
        u8 call_pan;
        u8 call_velocity;
        u32 voice;

        if (record->flags == 0xFFFF)
            goto next;
        if ((key_flags & 0x7F) < record->key_min)
            goto next;
        if ((key_flags & 0x7F) > record->key_max)
            goto next;

        note = (key_flags & 0x7F) + record->transpose;
        if (note > 127)
            owner = 127;
        else if (note < 0)
            owner = 0;
        else
            owner = note;

        if ((record->flags & 0xC000) == 0) {
            if (fn_801CAFAC(0x41, channel, arg9) > 0x1F80) {
                s32 status;
                voice = fn_801B5C14(owner & 0x7F, channel, arg9, 0, &status);
                pan = !status;
            } else {
                voice = -1;
                pan = 1;
            }
            if (pan == 0)
                goto next;
            if (voice != -1)
                goto accepted;
        }

        if ((record->pan & 0x80) == 0) {
            pan = (s8)(record->pan - 64) + pan_base;
            if (pan < 0)
                call_pan = 0;
            else if (pan > 127)
                call_pan = 127;
            else
                call_pan = (u8)pan;
        } else {
            call_pan = 128;
        }

        call_velocity = (u8)(((s32)velocity * record->velocity_scale) / 127);
        pitch += record->pitch_add;
        if (pitch > 255)
            pitch = 255;
        else if (pitch < 0)
            pitch = 0;

        switch (record->flags & 0xC000) {
        case 0:
            voice = fn_801C0BC8((void*)(u32)record->flags, (u8)pitch, arg2, arg3,
                                 owner | (key_flags & 0x80), call_velocity,
                                 call_pan, channel, 0, arg9, arg10, arg11,
                                 0, arg13, arg14, arg15);
            break;
        case 0x4000:
            voice = fn_801B6270((void*)(u32)record->flags, pitch, arg2, arg3,
                                owner | (key_flags & 0x80), call_velocity,
                                call_pan, channel, 0, arg9, arg10, arg11,
                                0, arg13, arg14, arg15);
            break;
        case 0x8000:
            voice = fn_801B5E9C((void*)(u32)record->flags, pitch, arg2, arg3,
                                owner | (key_flags & 0x80), call_velocity,
                                call_pan, channel, 0, arg9, arg10, arg11,
                                0, arg13, arg14, arg15);
            break;
        }

        if (voice == -1)
            goto next;

accepted:
        if (result == -1) {
            if (resolve != 0)
                result = fn_801C13C0(lbl_8064D3D0 + (u8)voice * 0x404);
            else
                result = voice;
        } else {
            *(s32*)(lbl_8064D3D0 + (u8)previous * 0x404 + 0xEC) = voice;
            *(s32*)(lbl_8064D3D0 + (u8)voice * 0x404 + 0xF0) = previous;
        }

        previous = voice;
        while (1) {
            u8* state = lbl_8064D3D0 + (u8)previous * 0x404;
            if (*(u32*)(state + 0xEC) == 0xFFFFFFFF)
                break;
            state[0x11C] = 1;
            previous = *(u32*)(state + 0xEC);
        }
        (lbl_8064D3D0 + (u8)previous * 0x404)[0x11C] = 1;

next:
        record++;
        count--;
    }

    return (s32)result;
}
