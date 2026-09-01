typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x177];
    u8 volume;
} Entry;

extern Entry* fn_801AF760(int);

void fn_801B09F0(int handle, u8 volume)
{
    Entry* entry = fn_801AF760(handle);

    if (entry != 0) {
        entry->volume = volume;
    }
}
