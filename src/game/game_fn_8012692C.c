typedef unsigned int u32;

typedef struct Entry {
    u32 key;
    u32 value;
} Entry;

typedef struct SearchState {
    u32 key;
    int direction;
    int distance;
    int span;
    Entry* current;
    Entry* previous;
} SearchState;

int fn_8012692C(Entry* entries, int count, SearchState* state)
{
    int step;
    int stride;
    int result;
    int done;
    Entry* previous;
    Entry* current;
    u32 key;
    int delta;

    result = 0;
    done = 0;
    key = state->key;
    previous = state->previous;
    current = state->current;
    step = -1;
    if (state->direction >= 0) {
        step = 1;
    }
    if (step == 1) {
        entries += count - 1;
    }
    stride = step * 8;

    while (done == 0) {
        if ((step >= 0 && key <= current->key) ||
            (step < 0 && current->key <= key)) {
            state->previous = previous;
            done = 1;
            state->current = current;
            delta = key - previous->key;
            if (delta < 0) {
                delta = 0U - (u32)delta;
            }
            state->distance = delta;
            delta = current->key - previous->key;
            if (delta < 0) {
                delta = 0U - (u32)delta;
            }
            state->span = delta;
        } else if (current == entries) {
            done = 2;
            result = 1;
        } else {
            previous = current;
            current = (Entry*)((char*)current + stride);
        }
    }
    return result;
}
