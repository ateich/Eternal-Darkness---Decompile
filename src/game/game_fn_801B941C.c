typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef u32 (*StreamCallback)(u16*, u32, u32, u32, u32);

typedef struct StreamSlot {
    u32 unk00;
    u32 flags;
    u8 state;
    u8 format;
    u8 pad0A[2];
    StreamCallback callback;
    u16* buffer;
    u32 block_samples;
    u32 buffer_samples;
    u32 cursor;
    u8 pad20[0x28];
    u32 voice;
    u32 callback_arg;
    u32 voice_flags;
    u8 pad54;
    u8 volume;
    u8 pan;
    u8 span;
    u8 aux_a;
    u8 aux_b;
    u8 pad5A[2];
    u8 priority;
    u8 cache_id;
    u8 pad5E[6];
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern u8 lbl_80619E30;
extern u8 lbl_8064D3E8;
extern u8 lbl_8064D3E9;
extern void* lbl_8064D3D0;
extern void DCInvalidateRange(void*, u32);
extern u32 fn_801CD200(u8);
extern u32 fn_801CD094(u32);
extern void fn_801CD138(void*, u32, u32, u8, u32, u32);
extern void fn_801C20C8(u32);

/*
 * Streaming voice service.  The state-machine and ring-buffer ownership are
 * recovered from retail; voice setup details are still being typed, so this
 * remains an honest NonMatching reconstruction.
 */
void fn_801B941C(void)
{
    u32 i;

    if (lbl_8064D3E8 != 0) {
        lbl_8064D3E8--;
        return;
    }
    lbl_8064D3E8 = lbl_8064D3E9;

    for (i = 0; i < lbl_80619E30; i++) {
        StreamSlot* slot = &lbl_8061AE48[i];
        u32 available;
        u32 next;

        if (slot->state == 1) {
            u32 cache = fn_801CD200(slot->cache_id);
            slot->voice_flags |= 0x40000000;
            slot->pad20[2] = slot->buffer[0] >> 8;
            slot->pad20[3] = slot->pad20[2];
            DCInvalidateRange(slot->buffer, 1);
            (void)cache;
            slot->state = 2;
            continue;
        }

        if (slot->state != 2) {
            continue;
        }

        available = fn_801CD094(slot->voice);
        if (slot->format == 1) {
            available = (available / 14) * 14;
        }
        if (slot->cursor == available) {
            continue;
        }

        if (slot->cursor < available) {
            u32 offset = slot->format == 1 ? (slot->cursor / 14) * 8
                                           : slot->cursor * 2;
            u32 got = slot->callback((u16*)((u8*)slot->buffer + offset),
                                     available - slot->cursor, 0, 0,
                                     slot->callback_arg);
            if (got != 0 && slot->state == 2) {
                next = (slot->cursor + got) % slot->block_samples;
                if ((slot->flags & 0x20000) == 0) {
                    u32 bytes = slot->format == 1 ? ((next + 13) / 14) * 8
                                                  : next * 2;
                    fn_801CD138(slot->buffer, offset, bytes - offset,
                                slot->cache_id, 0, 0);
                }
                slot->cursor = next;
            }
        } else {
            u32 got = slot->callback(slot->buffer, slot->block_samples, 0, 0,
                                     slot->callback_arg);
            if (got != 0 && slot->state == 2) {
                next = (slot->cursor + got) % slot->block_samples;
                fn_801CD138(slot->buffer, 0, next * 2, slot->cache_id, 0, 0);
                slot->cursor = next;
            }
        }
    }
}
