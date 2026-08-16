typedef struct StringWriteState {
    char* buffer;
    unsigned long limit;
    unsigned long used;
} StringWriteState;

int fn_800FA0B0(StringWriteState*, const char*, unsigned long);
int __pformatter_800FA174(void*, void*, const char*, void*);

int fn_800F9E2C(char* buffer, const char* format, void* args)
{
    int result;
    StringWriteState state;

    state.buffer = buffer;
    state.limit = (unsigned long)-1;
    state.used = 0;
    result = __pformatter_800FA174(fn_800FA0B0, &state, format, args);
    if (buffer != 0) {
        buffer[result < (unsigned long)-1 ? result : (unsigned long)-2] = 0;
    }
    return result;
}
