typedef struct Runtime {
    unsigned char pad[0x3C];
    void* sizing;
} Runtime;

typedef struct Item {
    float value;
    int kind;
    int offset;
    int padC;
    int key;
    int use_first;
    float scale;
    Runtime* runtime;
    int pad20;
} Item;

extern int fn_8012343C(void* sizing, int use_first, float scale);
extern int fn_801234DC(int kind, int use_first, float scale, float value);

void fn_801235E4(register Item* items, register int count,
                 register int* total_offsets, register int* total_sizes)
{
    Item* item = items;
    int i;
    int total_size = 0;
    int total_offset = 0;
    int use_first;
    int* size_out = total_sizes;
    int* offset_out = total_offsets;
    int item_count = count;
    Item* base = items;

    for (i = 0; i < item_count; item++, i++) {
        int size;
        int j;

        use_first = item->use_first;
        size = fn_801234DC(item->kind, use_first, item->scale, item->value);

        total_size += size;
        for (j = 0; j < i; j++) {
            if (item->key == base[j].key &&
                item->use_first == base[j].use_first &&
                item->scale == base[j].scale) {
                item->offset = base[j].offset;
                break;
            }
        }

        if (j == i) {
            item->offset = fn_8012343C(item->runtime->sizing, use_first,
                                      item->scale);
            if (item->offset > 0x32000) {
                item->offset = 0;
            }
            total_offset += item->offset;
        }
    }

    *offset_out = total_offset;
    *size_out = total_size;
}
