typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int object;
} Entry;

extern Entry* fn_801AF760(int);
extern int fn_801ADB70(int);

int fn_801B0B64(Entry* entry, int owner)
{
    int result = -1;

    if (entry == 0) {
        entry = fn_801AF760(owner);
    }
    if (entry != 0) {
        result = fn_801ADB70(entry->object);
    }
    return result;
}
