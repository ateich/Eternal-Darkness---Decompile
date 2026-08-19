typedef struct Node {
    char pad00[8];
    int size;
    struct Node* next;
    int state;
} Node;

typedef struct Collection {
    char pad00[0x2C];
    int count;
    int active_count;
    Node** lists;
    char pad38[0x28];
    int total_size;
} Collection;

#pragma use_lmw_stmw on

extern char lbl_8064BA88;
extern void fn_80161B0C(Collection*, int*);
extern void* fn_8016B5CC(Collection*, Node*, unsigned int, char*, int);

void fn_80161B58(Collection* collection, int preserve)
{
    int offset;
    int index;

    for (index = 0, offset = 0; index < collection->count; offset += 4, index++) {
        Node** link = (Node**)((char*)collection->lists + offset);
        while (*link != 0) {
            Node* node = *link;
            if (node->state != 0 && preserve == 0) {
                if (node->state < 2)
                    node->state = 0;
                link = &node->next;
            } else {
                *link = node->next;
                collection->active_count--;
                collection->total_size -= node->size + 21;
                fn_8016B5CC(collection, node, 0, &lbl_8064BA88, 252);
            }
        }
    }
    fn_80161B0C(collection, &collection->count);
}
