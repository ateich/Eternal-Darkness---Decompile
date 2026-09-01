typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int object;
} Entry;

extern Entry* fn_801AF760(int);
extern int fn_801AEA78(int);

int fn_801B0A28(int handle)
{
    int result = 0;
    Entry* entry = fn_801AF760(handle);

    if (entry != 0) {
        result = fn_801AEA78(entry->object);
    }

    return result;
}
