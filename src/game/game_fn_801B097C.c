typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 pad000[0x174];
    u16 flags;
} Entry;

extern Entry* fn_801AF760(int);

void fn_801B097C(int handle, unsigned int set, unsigned int clear)
{
    Entry* entry = fn_801AF760(handle);

    if (entry != 0) {
        entry->flags |= set;
        entry->flags &= ~clear;
    }
}
