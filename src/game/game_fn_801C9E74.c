typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct VoiceChannel {
    char pad00[0x1C];
    u8 index;
} VoiceChannel;

typedef struct Voice Voice;
struct Voice {
    Voice* prev;
    Voice* next;
    VoiceChannel* channel;
    char pad0C[4];
    u32 flags;
    char pad14[0x28];
    u32 handle;
    char pad40[4];
    u16 sound_id;
    u8 fallback_channel;
    u8 limit;
    u16 delay_count;
    char pad4A[2];
    float gain;
};

extern u8 lbl_8064D4B8;
extern Voice* lbl_8064D4BC;
extern u8 lbl_8064D4D3;
extern u8 lbl_8064D4D4;
extern u8 lbl_8064D4D5;
extern float lbl_80650FB0;
extern float lbl_80650FD4;
extern float lbl_80650FF8;

extern void fn_801B80D8(u32);
extern u32 fn_801B7DC8(u16, int, int, int, int);
extern u32 fn_801B8F0C(u32);
extern void fn_801C87DC(Voice*, float*, float*, float*, float*, float*);
extern void fn_801C9A08(Voice*, float);
extern u32 fn_801C9B1C(Voice*, float, float, float, float, float);
extern void fn_801C8CC0(Voice*, float, float, float, float, float);
extern void fn_801C9C4C(void);
extern void fn_801C8224(void);
extern void fn_801C8600(void);

void fn_801C9E74(void)
{
    Voice* voice;
    Voice* next;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float one;
    float fade_step;
    float zero;

    if (lbl_8064D4B8 != 0) {
        lbl_8064D4B8--;
        return;
    }

    voice = lbl_8064D4BC;
    zero = lbl_80650FB0;
    lbl_8064D4B8 = 3;
    lbl_8064D4D3 = 0;
    fade_step = lbl_80650FF8;
    lbl_8064D4D4 = 0;
    one = lbl_80650FD4;
    lbl_8064D4D5 = 0;
    while (voice != 0) {
        next = voice->prev;
        if (voice->flags & 0x40000) {
            if (voice->prev != 0) {
                voice->prev->next = voice->next;
            }
            if (voice->next != 0) {
                voice->next->prev = voice->prev;
            } else {
                lbl_8064D4BC = voice->prev;
            }
            voice->flags &= 0xFFFF;
            if (voice->handle != 0xFFFFFFFF) {
                fn_801B80D8(voice->handle);
            }
            goto next_voice;
        }

        if (voice->flags & 0x20001) {
            fn_801C87DC(voice, &value1, &value5, &value2, &value3, &value4);
        }

        if (!(voice->flags & 0x80000)) {
            if (voice->flags & 0x20000) {
                if (zero == value1 && (voice->flags & 4)) {
                    voice->flags |= 0x80000;
                    voice->flags &= ~0x20000;
                    goto update_voice;
                }
                if (zero == value1 && (voice->flags & 0x40)) {
                    if (voice->prev != 0) {
                        voice->prev->next = voice->next;
                    }
                    if (voice->next != 0) {
                        voice->next->prev = voice->prev;
                    } else {
                        lbl_8064D4BC = voice->prev;
                    }
                    voice->flags &= 0xFFFF;
                    if (voice->handle != 0xFFFFFFFF) {
                        fn_801B80D8(voice->handle);
                    }
                    goto next_voice;
                }
                if (voice->flags & 1) {
                    if (fn_801C9B1C(voice, value1, value2, value3, value4, value5)) {
                        goto next_voice;
                    }
                    goto update_voice;
                } else {
                    VoiceChannel* channel = voice->channel;
                    if (channel == 0 || channel->index != 0xFF) {
                        int index;
                        if (channel != 0) {
                            index = channel->index;
                        } else {
                            index = voice->fallback_channel;
                        }
                        if ((voice->handle = fn_801B7DC8(voice->sound_id, 0x7F, 0x40,
                                                        index,
                                                        (voice->flags & 0x10) != 0)) != 0xFFFFFFFF) {
                            goto update_voice;
                        }
                    }
                    if (voice->flags & 2) {
                        goto next_voice;
                    }
                    voice->flags |= 0x40000;
                    voice->flags &= ~0x20000;
                    goto update_voice;
                }
            } else {
                if ((voice->handle = fn_801B8F0C(voice->handle)) == 0xFFFFFFFF) {
                    if (voice->flags & 2) {
                        voice->flags |= 0x20000;
                    } else {
                        voice->flags |= 0x40000;
                    }
                }
            }

update_voice:
            if (voice->handle != 0xFFFFFFFF) {
                if (voice->flags & 1) {
                    fn_801C9A08(voice, value1);
                }
                if (zero == value1 && (voice->flags & 4)) {
                    fn_801B80D8(voice->handle);
                    voice->handle = 0xFFFFFFFF;
                    if (voice->flags & 2) {
                        voice->flags |= 0x80000;
                    } else {
                        voice->flags |= 0x40000;
                    }
                } else {
                    fn_801C8CC0(voice, value1, value2, value3, value4, value5);
                }
            }
            if (voice->flags & 0x100000) {
                voice->gain += fade_step;
                if (voice->gain >= one) {
                    voice->flags &= ~0x100000;
                }
            }
        } else {
            if (voice->channel != 0) {
                if (voice->channel == 0 || voice->channel->index == 0xFF) {
                    goto next_voice;
                }
            }
            {
                if (zero != value1) {
                    voice->flags &= ~0x80000;
                    voice->flags |= 0x20000;
                }
            }
        }
next_voice:
        voice = next;
    }
    fn_801C9C4C();
    fn_801C8224();
    fn_801C8600();
}
