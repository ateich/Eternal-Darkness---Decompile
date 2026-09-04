typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct VoiceLink {
    u8 previous;
    u8 next;
    u16 active;
} VoiceLink;

typedef struct VoiceState {
    u8 pad_000[0x8C0];
    VoiceLink links[64];
    u8 heads[256];
    u8 pad_AC0[0x400];
    VoiceLink free_links[64];
} VoiceState;

typedef struct Limits {
    u8 pad_000[0x210];
    u8 total;
} Limits;

extern Limits lbl_80619C20;
extern VoiceState lbl_80626DA0;
extern u16 lbl_8064D464;
extern u8 lbl_8064D466;
extern u8 lbl_8064D467;
extern u8 lbl_8064D468;
extern u8 lbl_8064D469;

void fn_801C1CB0(void)
{
    u32 i;

    for (i = 0; i < lbl_80619C20.total; i++) {
        lbl_80626DA0.free_links[i].previous = i - 1;
        lbl_80626DA0.free_links[i].next = i + 1;
        lbl_80626DA0.free_links[i].active = 1;
    }
    lbl_80626DA0.free_links[0].previous = 0xFF;
    lbl_80626DA0.free_links[lbl_80619C20.total - 1].next = 0xFF;
    lbl_8064D469 = 0;
    lbl_8064D468 = lbl_80619C20.total - 1;

    for (i = 0; i < lbl_80619C20.total; i++) {
        lbl_80626DA0.links[i].active = 0;
    }

    for (i = 0; i < 256; i++) {
        lbl_80626DA0.heads[i] = 0xFF;
    }
    lbl_8064D467 = 0;
    lbl_8064D464 = 0xFFFF;
    lbl_8064D466 = 0;
}
