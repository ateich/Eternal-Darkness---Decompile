typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8064D3A0;
extern int fn_801C90A4(void*, void*, void*, u32, u16, u32, u32, u32,
                       void*, void*, u8);

int fn_801C92F4(void* object, void* position, void* velocity, u32 flags,
                u16 sound_id, u32 first, u32 second, void* owner)
{
    if (lbl_8064D3A0 != 0) {
        return fn_801C90A4(object, position, velocity, flags, sound_id,
                           (sound_id & 0xFFFF) | 0x80000000, first, second,
                           owner, 0, 0);
    }
    return -1;
}
