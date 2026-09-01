typedef unsigned char u8;

typedef struct ListNode ListNode;
struct ListNode {
    ListNode* next;
    ListNode* prev;
};

typedef struct Owner {
    u8 pad[0xE64];
    ListNode* lists[3];
} Owner;

extern ListNode* lbl_8064D384;

void fn_801B244C(Owner* owner)
{
    ListNode* node;
    ListNode* next;
    ListNode* null_node = 0;
    Owner* second;

    node = owner->lists[0];
    if (node != 0) {
        while ((next = node->next) != 0) {
            node = next;
        }
        if (lbl_8064D384 != 0) {
            node->next = lbl_8064D384;
            lbl_8064D384->prev = node;
        }
        lbl_8064D384 = owner->lists[0];
        owner->lists[0] = null_node;
    }

    second = (Owner*)((u8*)owner + 4);
    node = second->lists[0];
    if (node != 0) {
        while ((next = node->next) != 0) {
            node = next;
        }
        if (lbl_8064D384 != 0) {
            node->next = lbl_8064D384;
            lbl_8064D384->prev = node;
        }
        lbl_8064D384 = second->lists[0];
        second->lists[0] = null_node;
    }

    node = owner->lists[2];
    if (node != 0) {
        while ((next = node->next) != 0) {
            node = next;
        }
        if (lbl_8064D384 != 0) {
            node->next = lbl_8064D384;
            lbl_8064D384->prev = node;
        }
        lbl_8064D384 = owner->lists[2];
        owner->lists[2] = 0;
    }
}
