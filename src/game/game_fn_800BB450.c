typedef struct Source {
    signed short value;
    unsigned char pad[0xB6];
    unsigned int word;
} Source;

typedef struct Owner {
    unsigned char pad[0x24];
    Source *source;
} Owner;

typedef struct Result {
    unsigned int word;
    signed short value;
    unsigned short pad;
} Result;

extern void *fn_80201B8C();
extern void *memcpy(void *, const void *, unsigned int);

unsigned short fn_800BB450(void *output, void *object)
{
    signed short value = 0;
    Result result;
    Owner *owner = ((Owner *)fn_80201B8C(object));

    if (owner != 0 && owner->source != 0) {
        value = owner->source->value;
        result.word = owner->source->word;
    }
    result.value = value;
    memcpy(output, &result, sizeof(result));
    return sizeof(result);
}
