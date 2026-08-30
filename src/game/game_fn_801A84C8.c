typedef struct Node801A84C8 Node801A84C8;

struct Node801A84C8 {
    Node801A84C8* next;
    Node801A84C8* previous;
};

extern Node801A84C8* lbl_8064D280;
extern Node801A84C8* lbl_8064D284;

void fn_801A84C8(Node801A84C8* node)
{
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
    if (lbl_8064D280 != 0 && node == lbl_8064D280) {
        lbl_8064D280 = node->next;
    }
    if (lbl_8064D284 != 0 && node == lbl_8064D284) {
        lbl_8064D284 = node->previous;
    }
}
