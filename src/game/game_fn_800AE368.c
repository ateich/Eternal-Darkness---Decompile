typedef unsigned char u8;

typedef struct Entry800AE368 {
    u8 pad0[0x18];
    unsigned int timer;
} Entry800AE368;

int fn_800AE368(Entry800AE368* entry, unsigned int value)
{
    return (entry->timer >> 16) == value;
}
