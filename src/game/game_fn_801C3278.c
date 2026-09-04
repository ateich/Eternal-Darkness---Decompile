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

typedef struct VoiceState {
    u8 count;
    u8 pad01[3];
    void* value04;
    u8 pad08[0x900];
    u8 handle_to_record[64];
    u16 next_generation;
    void (*callback)(int, u16*);
} VoiceState;

extern VoiceState lbl_80627D60;
extern void* fn_801CDD00(u8, int);
extern void fn_801CCAC4(u8, void*, void*);
extern u16 fn_801CCB0C(u8);
extern u8 fn_801CCAF8(u8);

int fn_801C3278(u8 handle)
{
    VoiceState* state = &lbl_80627D60;
    VoiceRecord* records = (VoiceRecord*)state;
    u8 i;
    u8 slot;
    VoiceRecord* record;
    u16 generation;

    for (i = 0; i < state->count; i++) {
        record = &records[i];
        if (record->active && record->handle == handle) {
            record->active = 0;
            state->handle_to_record[record->handle] = 0xFF;
        }
    }

    for (slot = 0; slot < state->count; slot++) {
        if (!records[slot].active) {
            record = &records[slot];
            record->active = 1;
            record->value0C = 0;
            break;
        }
    }
    if (slot == state->count)
        slot = 0xFF;

    state->handle_to_record[handle] = slot;
    if (slot == 0xFF) {
        fn_801CCAC4(handle, 0, 0);
        return -1;
    }

    fn_801CCAC4(handle, fn_801CDD00(slot, 0), state->value04);
    records[slot].voice = fn_801CCB0C(handle);

    do {
        generation = state->next_generation++;
        for (i = 0; i < state->count; i++) {
            if (records[i].active && records[i].generation == generation)
                break;
        }
    } while (i != state->count);

    record = &records[slot];
    record->generation = generation;
    record->value0A = fn_801CCAF8(handle);
    record->handle = handle;
    if (state->callback != 0) {
        state->callback(0, &record->voice);
        return ((u32)record->generation << 8) | handle;
    }

    fn_801CCAC4(handle, 0, 0);
    return -1;
}
