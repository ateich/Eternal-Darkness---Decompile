typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int handle;
} Entry;

extern Entry* fn_801AF760(int);
extern int fn_801AEAE0(int);

int fn_801AF924(int id)
{
    Entry* entry = fn_801AF760(id);
    int result = 0;

    if (entry != 0) {
        result = (u8)fn_801AEAE0(entry->handle) == 3;
    }
    return result;
}
