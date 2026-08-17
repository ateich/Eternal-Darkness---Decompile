typedef struct ListNode {
    struct ListNode* next;
    struct ListNode* previous;
    unsigned char pad[0x132C];
    unsigned int id;
} ListNode;

extern ListNode* lbl_8064D088;
extern ListNode* lbl_8064D094;
extern void* lbl_8064D09C;
extern void fn_8017CE74(void*, void*);

void fn_80149E28(ListNode* node)
{
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
    if (lbl_8064D094 != 0 && node == lbl_8064D094) {
        lbl_8064D094 = node->next;
    }
    if (lbl_8064D088 != 0 && node == lbl_8064D088) {
        lbl_8064D088 = node->previous;
    }
    node->id = 0;
    fn_8017CE74(lbl_8064D09C, node);
}
