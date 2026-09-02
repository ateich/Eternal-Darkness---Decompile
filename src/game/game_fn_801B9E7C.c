typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 format;
    u8 pad0A[6];
    void* buffer;
    u8 pad14[0x34];
    u32 voice;
    u8 pad4C[0x11];
    u8 cache_id;
    u8 pad5E[6];
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801CD138(void*, u32, u32, u8, u32, u32);
extern void fn_801CCB20(u32, u8);

void fn_801B9E7C(u32 id, u32 start_a, u32 size_a, u32 start_b, u32 size_b)
{
    int i;
    StreamSlot* slot;
    StreamSlot* slots = lbl_8061AE48;

    fn_801CE2B8();
    for (i = 0; i < 64; i++) {
        if (slots[i].state != 0) {
            if (slots[i].id == id) {
                break;
            }
        }
    }
    if (i == 64) {
        i = -1;
    }

    if (i != -1) {
        slot = &slots[i];
        switch (slot->format) {
        case 0:
            start_a *= 2;
            size_a *= 2;
            start_b *= 2;
            size_b *= 2;
            break;
        case 1:
            start_a = (start_a / 14) * 8;
            size_a = ((size_a + 13) / 14) * 8;
            start_b = (start_b / 14) * 8;
            size_b = ((size_b + 13) / 14) * 8;
            break;
        }
        if (size_a != 0) {
            fn_801CD138(slot->buffer, start_a, size_a, slot->cache_id, 0, 0);
        }
        if (size_b != 0) {
            fn_801CD138(slot->buffer, start_b, size_b, slot->cache_id, 0, 0);
        }
        if (slot->format == 1) {
            fn_801CCB20(slot->voice,
                        *(u32*)((u8*)slot->buffer + 0x40000000) >> 24);
        }
    }
    fn_801CE280();
}
