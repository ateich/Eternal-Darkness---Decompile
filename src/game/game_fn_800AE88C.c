typedef unsigned char u8;

typedef struct Entry800AE88C {
    u8 pad0[0x1C];
    int handle;
} Entry800AE88C;

extern Entry800AE88C lbl_8031F718[5];

int fn_800AE88C(unsigned int index)
{
    Entry800AE88C* entry = &lbl_8031F718[index];
    return entry->handle;
}
