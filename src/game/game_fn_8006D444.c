typedef struct Result {
    unsigned char pad_0[0x38];
    void *value;
} Result;

extern Result *fn_80201B8C(void *object);

void *fn_8006D444(void *object)
{
    void *result = 0;

    if (object != 0) {
        Result *entry = fn_80201B8C(object);
        if (entry != 0) {
            result = entry->value;
        }
    }
    return result;
}
