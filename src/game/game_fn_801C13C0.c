typedef unsigned int u32;

typedef struct Voice {
    unsigned char pad_000[0xF8];
    u32* link;
    u32* current;
} Voice;

u32 fn_801C13C0(Voice* voice)
{
    voice->current = voice->link;
    return voice->link[2];
}
