typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x17a];
    u8 state;
} Entry;

extern Entry* fn_801AF760(int);

int fn_801AF85C(int id)
{
    Entry* entry = fn_801AF760(id);

    if (entry != 0 && (entry->state == 2 || entry->state == 3)) {
        return 1;
    }
    return 0;
}
