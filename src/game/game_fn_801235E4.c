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

void fn_801235E4(Item* items, int count, int* total_offsets, int* total_sizes)
{
    Item* item = items;
    int i;
    int total_size = 0;
    int total_offset = 0;

    for (i = 0; i < count; item++, i++) {
        int size;
        int j;
        int use_first;

        use_first = item->use_first;
        size = fn_801234DC(item->kind, use_first, item->scale, item->value);

        total_size += size;
        for (j = 0; j < i; j++) {
            int key = items[j].key;
            if (key == item->key) {
                int first = items[j].use_first;
                if (first == item->use_first) {
                    float scale = items[j].scale;
                    if (scale == item->scale) {
                        item->offset = items[j].offset;
                        break;
                    }
                }
            }
        }

        if (i == j) {
            item->offset = fn_8012343C(item->runtime->sizing, use_first,
                                      item->scale);
            if (item->offset > 0x32000) {
                item->offset = 0;
            }
            total_offset += item->offset;
        }
    }

    *total_offsets = total_offset;
    *total_sizes = total_size;
}
