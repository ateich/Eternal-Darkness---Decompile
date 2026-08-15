typedef struct SpatialEntry {
    unsigned char pad0[0x2C];
    short x;
    short y;
    unsigned char pad30[0x18];
    unsigned int flags;
} SpatialEntry;

typedef struct SpatialCollection {
    unsigned char pad0[0x34];
    unsigned short count;
    unsigned char pad36[2];
    SpatialEntry* entries;
} SpatialCollection;

extern SpatialCollection* fn_8015C390(int);
extern unsigned int fn_80179064(short, short, int, int);

void fn_800AAAB8(float* position, unsigned int maximum, SpatialEntry** output,
                 int* output_count)
{
    SpatialCollection* collection = fn_8015C390(2);
    *output_count = 0;

    if (collection != 0 && collection->count != 0) {
        unsigned short count = collection->count;
        SpatialEntry* entry = collection->entries;
        int index = 0;

        while (index < count && *output_count < 8) {
            if ((entry->flags & 0x40) != 0 &&
                fn_80179064(entry->x, entry->y, (int)position[0],
                            (int)position[1]) < maximum) {
                output[*output_count] = entry;
                (*output_count)++;
            }
            index++;
            entry++;
        }
    }
}
