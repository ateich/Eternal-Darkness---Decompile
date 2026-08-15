typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    unsigned char *entry;
} ListNode;

extern ListNode *lbl_8064CA7C;

ListNode *fn_800BD6F0(void)
{
    ListNode *node = lbl_8064CA7C;

    if (node != 0) {
        if (node->next != 0) {
            node->next->prev = 0;
            lbl_8064CA7C = lbl_8064CA7C->next;
        } else {
            lbl_8064CA7C = 0;
        }
        node->next = 0;
        node->prev = 0;
        node->entry[52] &= ~2;
    }
    return node;
}
