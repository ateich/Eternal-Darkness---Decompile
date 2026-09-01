typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x148];
    int handle;
} Entry;

extern Entry* fn_801B0A6C(int);

int fn_801B0B30(int owner)
{
    Entry* entry = fn_801B0A6C(owner);

    if (entry != 0) {
        return entry->handle;
    }
    return -1;
}
