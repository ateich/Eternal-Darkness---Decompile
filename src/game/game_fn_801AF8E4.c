typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x17a];
    u8 state;
} Entry;

extern Entry* fn_801AF760(int);

int fn_801AF8E4(int id)
{
    Entry* entry = fn_801AF760(id);

    if (entry != 0 && entry->state != 0) {
        return 0;
    }
    return 1;
}
