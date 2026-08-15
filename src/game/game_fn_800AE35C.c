typedef unsigned char u8;

typedef struct Entry800AE35C {
    u8 pad0[0x18];
    unsigned int timer;
} Entry800AE35C;

void fn_800AE35C(Entry800AE35C* entry, unsigned int value)
{
    entry->timer = value << 16;
}
