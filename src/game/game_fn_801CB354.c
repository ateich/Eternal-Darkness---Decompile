typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Object {
    u8 pad[0xF4];
    u32 index;
} Object;

extern u8 lbl_8062A230[];

void fn_801CB354(u8 selector, u32 destination_index, u32 source_index)
{
    u8 offset;
    u8* source_row;
    u8* destination_row;

    destination_index = ((Object*)destination_index)->index;
    source_index = ((Object*)source_index)->index;
    if (selector < 0x40) {
        source_row = lbl_8062A230 + source_index * 0x86;
        destination_row = lbl_8062A230 + destination_index * 0x86;
        offset = selector & 0x1F;
        destination_row[0x43C0 + offset] = source_row[0x43C0 + offset];
        destination_row[0x43E0 + offset] = source_row[0x43E0 + offset];
    } else if ((u8)(selector - 0x80) <= 1) {
        source_row = lbl_8062A230 + source_index * 0x86;
        destination_row = lbl_8062A230 + destination_index * 0x86;
        offset = selector & ~1;
        destination_row[0x43C0 + offset] = source_row[0x43C0 + offset];
        destination_row[0x43C1 + offset] = source_row[0x43C1 + offset];
    } else if ((u8)(selector - 0x84) <= 1) {
        source_row = lbl_8062A230 + source_index * 0x86;
        destination_row = lbl_8062A230 + destination_index * 0x86;
        offset = selector & ~1;
        destination_row[0x43C0 + offset] = source_row[0x43C0 + offset];
        destination_row[0x43C1 + offset] = source_row[0x43C1 + offset];
    } else {
        source_row = lbl_8062A230 + source_index * 0x86;
        destination_row = lbl_8062A230 + destination_index * 0x86;
        destination_row[0x43C0 + selector] = source_row[0x43C0 + selector];
    }
}
