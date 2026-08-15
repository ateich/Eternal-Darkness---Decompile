typedef struct Entry {
    unsigned char pad[48];
    float value;
    unsigned char flags;
} Entry;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    Entry *entry;
} ListNode;

extern ListNode *lbl_8064CA7C;

void fn_800BD638(ListNode *node)
{
    ListNode *current;
    ListNode *previous;

    node->entry->flags |= 2;
    if (lbl_8064CA7C != 0) {
        current = lbl_8064CA7C;
        previous = 0;
        goto test;
loop:
        if (current->entry->value >= node->entry->value) {
            if (current->prev != 0) {
                node->prev = current->prev;
                node->next = current;
                current->prev->next = node;
                current->prev = node;
                return;
            }
            node->prev = 0;
            node->next = current;
            current->prev = node;
            lbl_8064CA7C = node;
            return;
        }
        previous = current;
        current = current->next;
test:
        if (current != 0) {
            goto loop;
        }
        previous->next = node;
        node->prev = previous;
        node->next = 0;
        return;
    }
    lbl_8064CA7C = node;
    node->prev = 0;
    node->next = 0;
}
