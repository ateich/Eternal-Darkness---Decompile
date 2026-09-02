/*
 * Uncompiled session-1668 fallback evidence.  This file is deliberately kept
 * outside src/game: fn_801BAF90 remains the next honest frontier and is not a
 * registered NonMatching unit.  The surviving session-1668 candidate object
 * and objdiff data establish the code-generation lead described by the
 * adjacent frontier report.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamSlot {
    u32 id;
    u32 flags;
    u8 state;
    u8 pad09[0x54];
    u8 cleanup;
    u8 pad5E[2];
    u32 cache;
} StreamSlot;

extern StreamSlot lbl_8061AE48[];
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern u32 fn_801B9D1C(u32);
extern void fn_801BB3A0(u32);
extern void fn_801CD1E0(u8);

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

static inline void clear_stream(StreamSlot* slot)
{
    slot->state = 0;
}

void fn_801BAF90(u32 id)
{
    StreamSlot* slots = lbl_8061AE48;
    u8* cache_slots;
    u32 index;
    u32 cache;
    u8* cleanup;
    u32 offset;

    fn_801CE2B8();
    index = find_stream(id);
    if (index != (u32)-1) {
        fn_801BB3A0(id);
        offset = index;
        cleanup = (u8*)slots + 0x5D;
        fn_801CD1E0(cleanup[offset * sizeof(StreamSlot)]);
        cache_slots = (u8*)slots + 0x60;
        cache = *(u32*)(cache_slots + offset * sizeof(StreamSlot));
        if (cache != (u32)-1) {
            fn_801CE2B8();
            index = fn_801B9D1C(cache);
            if (index != (u32)-1) {
                fn_801BB3A0(cache);
                fn_801CD1E0(cleanup[index * sizeof(StreamSlot)]);
                if (*(u32*)(cache_slots + index * sizeof(StreamSlot)) != (u32)-1) {
                    fn_801BAF90(*(u32*)(cache_slots + index * sizeof(StreamSlot)));
                }
                clear_stream(&slots[index]);
            }
            fn_801CE280();
        }
        clear_stream(&slots[offset]);
    }
    fn_801CE280();
}
