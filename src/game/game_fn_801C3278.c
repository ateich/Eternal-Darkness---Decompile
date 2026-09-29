typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct VoiceRecord {
    u8 pad00[8];
    u8 active;
    u8 pad09;
    u8 value0A;
    u8 handle;
    u32 value0C;
    u8 pad10[8];
    u16 voice;
    u16 generation;
    u8 pad1C[8];
} VoiceRecord;

typedef union VoiceState {
    VoiceRecord records[64];
    u8 raw[0x950];
    struct {
        u8 count;
        u8 pad01[3];
        void* value04;
        u8 pad08[0x900];
        u8 handle_to_record[64];
        u16 next_generation;
        void (*callback)(int, u16*);
    } state;
} VoiceState;

extern VoiceState lbl_80627D60;
extern void* fn_801CDD00(u8, int);
extern void fn_801CCAC4(u8, void*, void*);
extern u16 fn_801CCB0C(u8);
extern u8 fn_801CCAF8(u8);

int fn_801C3278(int handle)
{
    VoiceState* state = &lbl_80627D60;
    u8 clean_handle;
    u8 i;
    u8 j;
    u8 slot;
    void* data;
    u8* handle_slot;
    VoiceRecord* record;
    u32 record_offset;
    u16 generation;
    u16* generation_ptr;

    for (i = 0; i < state->state.count; i++) {
        record = &state->records[i];
        if (record->active && record->handle == (u8)handle) {
            record->active = 0;
            state->state.handle_to_record[record->handle] = 0xFF;
        }
    }

    slot = 0;
    while (slot < state->state.count) {
        if (!state->records[slot].active) {
            record = &state->records[slot];
            record->active = 1;
            record->value0C = 0;
            goto found;
        }
        slot++;
    }
    slot = 0xFF;

found:
    clean_handle = handle;
    handle_slot = &state->raw[clean_handle + 0x908];
    *handle_slot = slot;
    if (slot != 0xFF) {
        data = fn_801CDD00(*handle_slot, 0);
        fn_801CCAC4(clean_handle, data, state->state.value04);
        state->records[slot].voice = fn_801CCB0C(clean_handle);
        record_offset = slot * sizeof(VoiceRecord);

        do {
            generation = state->state.next_generation++;
            for (record = state->records, j = 0; j < state->state.count; record++, j++) {
                if (record->active && record->generation == generation)
                    break;
            }
        } while (j != state->state.count);

        generation_ptr = (u16*)&state->raw[record_offset + 0x1A];
        *generation_ptr = generation;
        state->raw[record_offset + 0x0A] = fn_801CCAF8(clean_handle);
        state->raw[record_offset + 0x0B] = handle;
        if (state->state.callback != 0) {
            state->state.callback(0, (u16*)&state->raw[record_offset + 0x18]);
            return ((u32)*generation_ptr << 8) | (u8)handle;
        }
        fn_801CCAC4(clean_handle, 0, 0);
    } else {
        fn_801CCAC4(clean_handle, 0, 0);
    }
    return -1;
}
