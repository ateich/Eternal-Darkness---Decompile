typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Definition {
    u8 pad_0[0xE];
    u16 runtime_index;
} Definition;

typedef struct Entry {
    unsigned int field_0;
    Definition* definition;
    u16 field_8;
    u16 flags;
} Entry;

typedef struct RuntimeRecord {
    u8 pad_0[0x48];
    Entry* entry;
} RuntimeRecord;

typedef struct State {
    u8 pad_0[0x160];
    RuntimeRecord* runtime;
    u8 pad_164[0xDC];
    Entry** entries;
} State;

/*
 * The entry array must contain at least 18 elements. Definitions on qualifying
 * entries must be non-null and their runtime indices valid for the runtime
 * array.
 */
void fn_8012BFE4(u8* state_bytes)
{
    State* state = (State*)state_bytes;
    Entry* entry;
    int i;

    for (i = 0; i < 18; i++) {
        entry = state->entries[i];
        if (entry != 0 && (entry->flags & 0x3F) != 0) {
            state->runtime[entry->definition->runtime_index].entry = entry;
        }
    }
}
