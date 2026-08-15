typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    unsigned char *entry;
} ListNode;

extern ListNode *lbl_8064CA7C;

ListNode *fn_800BD750(unsigned char *entry)
{
    ListNode *node;

    if (lbl_8064CA7C != 0) {
        node = lbl_8064CA7C;
        goto test;
loop:
            if (node->entry == entry) {
            if (node->prev == 0) {
                lbl_8064CA7C = node->next;
                if (node->next != 0) {
                    node->next->prev = 0;
                }
            } else {
                node->prev->next = node->next;
                if (node->next != 0) {
                    node->next->prev = node->prev;
                }
            }
            node->next = 0;
            node->prev = 0;
            node->entry[52] &= ~2;
                return node;
            }
            node = node->next;
test:
        if (node != 0) {
            goto loop;
        }
    }
    return 0;
}
