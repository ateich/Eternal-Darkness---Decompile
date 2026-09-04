typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Voice {
    u8 pad_000[0xF4];
    u32 index;
    u8 pad_0F8[0x29];
    u8 field_121;
    u8 field_122;
} Voice;

extern u8 lbl_806275A0[][16];
extern u8 lbl_80627620[];

void fn_801C26F8(Voice* voice)
{
    u32 index = voice->index;
    u8 slot;

    if (index == (u32)-1) {
        return;
    }
    if (voice->field_121 == 0xFF) {
        return;
    }
    slot = (u8)index;
    if (voice->field_122 == 0xFF) {
        lbl_80627620[slot] = slot;
    } else {
        lbl_806275A0[voice->field_122][voice->field_121] = slot;
    }
}
