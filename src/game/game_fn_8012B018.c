typedef unsigned char u8;

typedef struct Entry8012B018 {
    u8 pad[0xFC];
    unsigned short flags;
    u8 tail[0x12];
} Entry8012B018;

typedef struct Table8012B018 {
    Entry8012B018 entries[8];
    unsigned short count;
} Table8012B018;

int fn_8012B018(u8* owner, int* output)
{
    Table8012B018* table;
    int index;
    int result;

    table = *(Table8012B018**)(owner + 0x40);
    result = 0;
    index = table->count + 1;
    index &= -(index < 8);
    if (index < 8) {
        if ((table->entries[index].flags & 2) != 0) {
            result = 1;
            if (output != 0) {
                *output = index;
            }
        }
    }
    return result;
}
