typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Voice {
    u8 pad_000[0x34];
    u32 field_034;
    u8 pad_038[0xBC];
    u32 index;
    u8 pad_0F8[0x14];
    u8 active;
    u8 pad_10D[0x10];
    u8 special;
} Voice;

typedef struct FreeLink {
    u8 previous;
    u8 next;
    u16 active;
} FreeLink;

extern FreeLink lbl_80627C60[64];
extern u8 lbl_8064D466;
extern u8 lbl_8064D467;
extern u8 lbl_8064D468;
extern u8 lbl_8064D469;
extern void fn_801C0ACC(Voice*, int);
extern void fn_801C1520(Voice*);

void fn_801C1BCC(Voice* voice)
{
    register u32 index;
    register FreeLink* link;

    fn_801C0ACC(voice, 2);
    fn_801C1520(voice);
    voice->field_034 = 0;
    voice->active = 0;
    index = (u8)voice->index;
    link = &lbl_80627C60[index];
    if (link->active == 0) {
        link->active = 1;
        if (lbl_8064D469 != 0xFF) {
            link->next = 0xFF;
            link->previous = lbl_8064D468;
            lbl_80627C60[lbl_8064D468].next = index;
        } else {
            link->next = 0xFF;
            link->previous = 0xFF;
            lbl_8064D469 = index;
        }
        lbl_8064D468 = index;
        if (voice->special != 0) {
            lbl_8064D467--;
        } else {
            lbl_8064D466--;
        }
    }
    voice->index = -1;
}
