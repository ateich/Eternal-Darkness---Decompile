typedef unsigned int u32;

typedef struct Entry {
    u32 key;
    u32 value;
} Entry;

typedef struct SearchState {
    int unknown0;
    int unknown4;
    int distance;
    int span;
    Entry* current;
    Entry* previous;
} SearchState;

void fn_80127128(Entry* entries, int count, SearchState* state, int direction,
                 u32* output)
{
    state->distance = 0;
    state->span = 0;
    if (direction >= 0) {
        state->previous = entries;
        count = 1;
    } else {
        count--;
        state->previous = entries + count;
        count--;
    }
    state->current = entries + count;
    *output = state->previous->key;
}
