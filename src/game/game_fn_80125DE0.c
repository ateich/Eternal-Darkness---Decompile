typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Child {
    u32 value;
    u8 pad[0x760];
    u32 counter_and_flag;
} Child;

typedef struct Header {
    u8 pad[8];
    u16 count;
} Header;

typedef struct ListEntry {
    u8 pad[0x48];
    u32 value;
} ListEntry;

typedef struct Owner {
    u8 pad_00[0x3C];
    Header* header;
    u8 pad_40[0x120];
    ListEntry* list;
    u8 pad_164[0x18];
    u32 slots[24][2];
    u32 field_23C;
    u32 field_240;
    u8 pad_244[0x60];
    Child* child;
} Owner;

/* NonMatching: honest reconstruction of owner/work-buffer teardown and the
 * per-list-entry reset. Retail is 216 bytes; GC/1.3 emits 224 bytes and scores
 * 89.44444%. Remaining differences are fixed-slot unrolling and loop register
 * allocation; no inline assembly or register binding is used. */
void fn_80125DE0(Owner* owner)
{
    int i;

    if (owner == 0 || owner->child == 0)
        return;
    owner->child->value = 0;
    owner->field_23C = 0;
    owner->field_240 = 0;
    owner->child->counter_and_flag &= ~1;
    owner->child = 0;
    for (i = 0; i < 24; i++)
        owner->slots[i][0] = 0;
    if (owner->list == 0)
        return;
    for (i = 0; i < owner->header->count; i++)
        owner->list[i].value = 0;
}
