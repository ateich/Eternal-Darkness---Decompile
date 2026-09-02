typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 pad09[0x3F];
    u32 voice;
    u8 pad4C[9];
    u8 volume;
    u8 left;
    u8 right;
    u8 aux_left;
    u8 aux_right;
    u8 saved_left;
    u8 saved_right;
    u8 pad5C[8];
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern u8 lbl_80619C20[];
extern u32 lbl_8064D3CC;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801CCCC4(u32, u32, u32, u32, float, float, float);

void fn_801BA15C(void)
{
    StreamSlot* slot;
    u32 i;

    fn_801CE2B8();
    slot = lbl_8061AE48;
    for (i = 0; i < lbl_80619C20[0x210]; slot++, i++) {
        if (slot->state != 0) {
            slot->left = slot->saved_left;
            slot->right = slot->saved_right;
            if (lbl_8064D3CC & 1) {
                slot->left = 0x40;
                slot->right = 0;
            } else if (!(lbl_8064D3CC & 2)) {
                slot->right = 0;
            }
            if (slot->state != 3) {
                fn_801CCCC4(slot->voice, 0, (u32)slot->left << 16,
                            (u32)slot->right << 16,
                            (float)slot->volume * (1.0f / 255.0f),
                            (float)slot->aux_left * (1.0f / 255.0f),
                            (float)slot->aux_right * (1.0f / 255.0f));
            }
        }
    }
    fn_801CE280();
}
