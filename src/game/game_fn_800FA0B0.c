void* memcpy(void*, const void*, unsigned long);

typedef struct StringWriteState {
    char* buffer;
    unsigned long limit;
    unsigned long used;
} StringWriteState;

int fn_800FA0B0(StringWriteState* state, const char* source, unsigned long count)
{
    unsigned long written = state->limit - state->used;
    if (state->used + count <= state->limit) {
        written = count;
    }
    memcpy(state->buffer + state->used, source, written);
    state->used += written;
    return 1;
}
