typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct KeyRecord {
    u16 flags;
    s8 transpose;
    u8 pan;
    s16 pitch_add;
    u16 pad;
} KeyRecord;

extern KeyRecord* fn_801BD0EC(void*);
extern u16 fn_801CAFAC(s32, u32, u8);
extern s32 fn_801B5C14(u8, u8, u8, void*, s32*);
extern s32 fn_801C0BC8(u16, u8, u32, u32, u32, u8, u8, u8, u8, u8,
                      u16, u16, u32, u8, u8, u32);
extern s32 fn_801B5E9C(u16, s16, u32, u32, u32, u8, u8, u8, u8, u8,
                      u16, u16, u32, u8, u8, u32);

s32 fn_801B6270(void* table, s16 pitch, u32 arg2, u32 arg3, u32 key_flags,
                 u8 velocity, u8 pan_base, u8 channel, u8 arg8, u8 arg9,
                 u16 arg10, u16 arg11, u32 resolve, u8 arg13, u8 arg14,
                 u32 arg15)
{
    KeyRecord* record;
    u32 raw_key;
    KeyRecord* records;
    u32 voice;
    s32 value;
    u32 index;

    records = fn_801BD0EC(table);
    if (records != 0) {
        raw_key = key_flags & 0xFF;
        index = key_flags & 0x7F;
        if (records[index].flags != 0xFFFF) {
            record = &records[index];
            if ((record->flags & 0xC000) != 0x4000) {
                if (!(record->pan & 0x80)) {
                    value = (s8)(records[raw_key].pan - 64) + pan_base;
                    if (value < 0)
                        pan_base = 0;
                    else if (value > 127)
                        pan_base = 127;
                    else
                        pan_base = value;
                } else {
                    pan_base = 128;
                }

                value = index + record->transpose;
                if (value > 127)
                    key_flags = 127;
                else if (value < 0)
                    key_flags = 0;
                else
                    key_flags = value;

                pitch += record->pitch_add;
                if (pitch > 255)
                    pitch = 255;
                else if (pitch < 0)
                    pitch = 0;

                if ((record->flags & 0xC000) == 0) {
                    s32 status;
                    if (fn_801CAFAC(0x41, channel, arg8) > 0x1F80) {
                        voice = fn_801B5C14(key_flags & 0x7F, channel, arg8,
                                            (void*)resolve, &status);
                        value = !status;
                    } else {
                        voice = -1;
                        value = 1;
                    }
                    if (!value)
                        return -1;
                    if (voice != -1)
                        return voice;

                    return fn_801C0BC8(record->flags, (u8)pitch, arg2, arg3,
                                       key_flags | (raw_key & 0x80), velocity,
                                       pan_base, channel, arg8, arg9, arg10,
                                       arg11, (u8)resolve, arg13, arg14, arg15);
                }

                return fn_801B5E9C(record->flags, pitch, arg2, arg3,
                                   key_flags | (raw_key & 0x80), velocity,
                                   pan_base, channel, arg8, arg9, arg10, arg11,
                                   (u8)resolve, arg13, arg14, arg15);
            }
        }
    }

    return -1;
}
