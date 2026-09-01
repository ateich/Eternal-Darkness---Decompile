typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int handle;
} Entry;

extern Entry* fn_801AF760(int);
extern int fn_801AE284(int);

int fn_801AF824(int id)
{
    Entry* entry = fn_801AF760(id);

    if (entry != 0) {
        return fn_801AE284(entry->handle);
    }
    return 0;
}
