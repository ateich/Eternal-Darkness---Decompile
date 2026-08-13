typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node80092CCC {
    u32 value00;
    u32 id;
    u32 value08;
    u32 alternate_id;
} Node80092CCC;

typedef struct Entry80092CCC {
    u32 id;
    unsigned char pad04[0xE];
    u16 count;
    unsigned char pad14[0x14];
    Node80092CCC* node;
} Entry80092CCC;

typedef struct State80092CCC {
    unsigned char pad00[0xC8];
    u32 previous_id;
    u32 current_id;
} State80092CCC;

extern Entry80092CCC* fn_800935CC(int, int, u32, int);

int fn_80092CCC(void* unused1, void* unused2, register State80092CCC* state)
{
    Entry80092CCC* entry = fn_800935CC(0, 0, state->current_id, 4);

    if (entry != 0) {
        Node80092CCC* node = entry->node;
        u32 id;
        u16 count = entry->count;

        if (state->previous_id == node->id) {
            if (count == 1)
                id = node->id;
            else
                id = node->alternate_id;
        } else {
            id = node->id;
        }

        if (count != 0) {
            entry = fn_800935CC(0, 0, id, 4);
            if (entry != 0) {
                state->previous_id = state->current_id;
                state->current_id = entry->id;
            }
        } else {
            state->current_id = 0;
        }
    } else {
        state->current_id = 0;
    }
    return 1;
}
