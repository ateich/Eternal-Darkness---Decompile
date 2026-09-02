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
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

static inline u32 find_stream(u32 id)
{
    u32 i;

    for (i = 0; i < 64; i++) {
        if (lbl_8061AE48[i].state != 0 && lbl_8061AE48[i].id == id) {
            return i;
        }
    }
    return -1;
}

void fn_801BA708(u32 id, s16* position);

static inline void update_cached_stream(u32 id, s16* position)
{
    fn_801BA708(id, position);
}

void fn_801BA708(u32 id, s16* position)
{
    StreamSlot* slots = lbl_8061AE48;
    u32 slot_index;
    u32 cache;
    StreamSlot* slot;

    fn_801CE2B8();
    slot_index = find_stream(id);

    if (slot_index != (u32)-1) {
        slot = &slots[slot_index];
        slot->position[0] = position[0];
        slot->position[1] = position[1];
        slot->position[2] = position[2];
        slot->position[3] = position[3];
        slot->position[4] = position[4];
        slot->position[5] = position[5];
        slot->position[6] = position[6];
        slot->position[7] = position[7];
        slot->position[8] = position[8];
        slot->position[9] = position[9];
        slot->position[10] = position[10];
        slot->position[11] = position[11];
        slot->position[12] = position[12];
        slot->position[13] = position[13];
        slot->position[14] = position[14];
        slot->position[15] = position[15];
        *(unsigned short*)&lbl_8061AE48[slot_index].pad1C[4] = 8;
        cache = lbl_8061AE48[slot_index].cache;
        if (cache != (u32)-1) {
            update_cached_stream(cache, position);
        }
    }
    fn_801CE280();
}
