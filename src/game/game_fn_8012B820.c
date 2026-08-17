typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry8012B820 {
    u16 value;
    u8 pad[6];
} Entry8012B820;

typedef struct Owner8012B820 {
    u8 pad[0x180];
    Entry8012B820 entries[1];
} Owner8012B820;

u16 fn_8012B820(Owner8012B820* owner, u16 index)
{
    return owner->entries[index].value;
}
