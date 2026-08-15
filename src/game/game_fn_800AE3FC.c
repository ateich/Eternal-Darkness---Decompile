typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry800AE3FC {
    u8 kind;
    u8 pad1[3];
    void* value;
    u16 id;
    u16 state;
    u16 arg10;
    u16 duration;
    u16 arg8;
    u16 arg6;
    u16 arg7;
    u8 pad16[2];
    unsigned int timer;
    int handle;
} Entry800AE3FC;

extern Entry800AE3FC lbl_8031F718[5];
extern void fn_800AE35C(Entry800AE3FC*, unsigned int);

void fn_800AE3FC(u16 id, unsigned int index, void* value, u16 arg6,
                 u16 arg7, u16 arg8, u8 kind, u16 arg10)
{
    Entry800AE3FC* entry = &lbl_8031F718[index];

    entry->kind = kind;
    entry->value = value;
    entry->state = 2;
    entry->id = id;
    entry->duration = 60;
    entry->arg8 = arg8;
    entry->arg6 = arg6;
    entry->arg7 = arg7;
    entry->arg10 = arg10;
    fn_800AE35C(entry, 0);
}
