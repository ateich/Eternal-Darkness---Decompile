typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int handle;
} Entry;

extern Entry* fn_801AF760(int);
extern int fn_801AEAE0(int);

int fn_801AF96C(int id)
{
    int result = 0;
    Entry* entry = fn_801AF760(id);

    if (entry != 0) {
        result = fn_801AEAE0(entry->handle);
    }
    return result;
}
