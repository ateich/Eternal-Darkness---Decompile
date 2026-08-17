typedef struct ListNode {
    struct ListNode* next;
    struct ListNode* previous;
} ListNode;

extern ListNode* lbl_8064D088;
extern ListNode* lbl_8064D094;

void fn_80149D64(ListNode* node)
{
    if (node != 0) {
        if (lbl_8064D088 != 0) {
            lbl_8064D088->next = node;
            node->previous = lbl_8064D088;
            lbl_8064D088 = node;
        } else {
            lbl_8064D088 = node;
            lbl_8064D094 = node;
        }
    }
}
