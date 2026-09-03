typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 pad09[0x13];
    u32 active;
    u8 pad20[0x28];
    u32 voice;
    u8 pad4C[8];
    u8 channel;
    u8 pad55[0xB];
    u32 cache;
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern u32 fn_801C1FE0(u8);

static inline u32 find_stream(StreamSlot* slots, u32 id)
{
    u32 i;

    for (i = 0; i < 64; i++) {
        if (slots[i].state != 0 && slots[i].id == id) {
            return i;
        }
    }
    return -1;
}

int fn_801BB1A0(u32 id)
{
    register StreamSlot* slot;
    StreamSlot* slots = lbl_8061AE48;
    u32 index;
    int result = 0;
    u8* state;
    u8* cache_base;
    u32 cache;
    u32 voice;

    fn_801CE2B8();
    index = find_stream(slots, id);
    if (index != (u32)-1) {
        id = index * sizeof(StreamSlot);
        state = (u8*)slots + id + 8;
        if (*state == 3) {
            slot = (StreamSlot*)((u8*)slots + id);
            voice = fn_801C1FE0(slot->channel);
            slot->voice = voice;
            if (voice == (u32)-1) {
                fn_801CE280();
                return 0;
            }
            slot->active = 0;
            *state = 1;
        }
        cache_base = (u8*)slots + 0x60;
        cache = *(u32*)(cache_base + id);
        if (cache != (u32)-1) {
            result = fn_801BB1A0(*(u32*)(cache_base + index * sizeof(StreamSlot)));
        } else {
            result = 1;
        }
    }
    fn_801CE280();
    return result;
}
