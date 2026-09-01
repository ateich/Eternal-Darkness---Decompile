typedef unsigned char u8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct Entry {
    u8 pad000[0x14C];
    Vec3 position;
} Entry;

extern Entry* fn_801AF760(int);

void fn_801B0BB4(int owner, Vec3* position)
{
    Entry* entry = fn_801AF760(owner);

    if (entry != 0 && position != 0) {
        entry->position = *position;
    }
}
