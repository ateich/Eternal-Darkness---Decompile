typedef unsigned char u8;

typedef struct Entry800AE348 {
    u8 pad0[0x18];
    int timer;
} Entry800AE348;

extern int lbl_8064C8CC;

void fn_800AE348(Entry800AE348* entry)
{
    entry->timer += lbl_8064C8CC;
}
