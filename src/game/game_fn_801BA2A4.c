typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 positional;
    u8 pad0A[2];
    void (*callback)(void);
    u32 source;
    u32 samples;
    u32 buffer_bytes;
    u8 pad1C[0x0C];
    s16 position[16];
    u32 voice;
    u32 callback_arg;
    u32 voice_flags;
    u8 format;
    u8 volume;
    u8 left;
    u8 right;
    u8 aux_left;
    u8 aux_right;
    u8 saved_left;
    u8 saved_right;
    u8 priority;
    u8 cache_id;
    u8 pad5E[2];
    u32 cache;
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern u32 lbl_8064D3CC;
extern u32 lbl_8064D3EC;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern u32 fn_801BA6C4(u32, u32);
extern u8 fn_801CD1C0(u32, u32, u32, u32);
extern u32 fn_801BB1A0(u32);

u32 fn_801BA2A4(u8 format, u32 source, u32 samples, u32 voice_flags,
                u8 volume, u8 left, u8 right, u8 aux_left,
                u8 aux_right, u8 priority, u32 flags,
                void (*callback)(void), u32 callback_arg, s16* position)
{
    StreamSlot* slots = lbl_8061AE48;
    u32 slot_index;
    StreamSlot* slot;
    u32 id;
    u32 found;
    u32 bytes;

    fn_801CE2B8();

    for (slot_index = 0; slot_index < 64; slot_index++) {
        if (slots[slot_index].state == 0) {
            break;
        }
    }
    if (slot_index == 64) {
        id = (u32)-1;
        goto done;
    }

    do {
        id = lbl_8064D3EC++;
        if (id == (u32)-1) {
            lbl_8064D3EC++;
        }
        for (found = 0; found < 64; found++) {
            if (slots[found].state != 0 && slots[found].id == id) {
                break;
            }
        }
    } while (found != 64);

    slot = &slots[slot_index];
    slot->id = id;
    slot->flags = flags;
    bytes = fn_801BA6C4(samples, flags);
    slot->source = source;
    slot->samples = samples;
    slot->buffer_bytes = bytes;
    slot->callback = callback;
    slot->voice = (u32)-1;

    if (flags & 1) {
        if (position != 0) {
            int i;
            for (i = 0; i < 16; i++) {
                slot->position[i] = position[i];
            }
            *(unsigned short*)&slot->pad1C[4] = 8;
        }
        slot->positional = 1;
    } else {
        slot->positional = 0;
    }

    slot->voice_flags = voice_flags;
    slot->priority = priority;
    slot->format = format;
    slot->saved_left = left;
    slot->saved_right = right;

    if (lbl_8064D3CC & 1) {
        aux_left = 0x40;
        aux_right = 0;
    } else if (!(lbl_8064D3CC & 2)) {
        aux_right = 0;
    }

    slot->volume = volume;
    slot->left = aux_left;
    slot->right = aux_right;
    slot->aux_left = left;
    slot->aux_right = right;
    slot->callback_arg = callback_arg;
    slot->cache = (u32)-1;
    slot->state = 3;
    slot->cache_id = fn_801CD1C0(bytes, (u32)-1, aux_left, aux_right);

    if (slot->cache_id == 0xFF || (!(flags & 0x10000) && fn_801BB1A0(id) == 0)) {
        id = (u32)-1;
    }
    if (id == (u32)-1) {
        slot->state = 0;
    }

done:
    fn_801CE280();
    return id;
}
