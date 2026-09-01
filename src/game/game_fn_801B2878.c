typedef struct Node Node;
struct Node {
    Node* next;
    unsigned char pad[8];
    unsigned int value;
};

typedef struct Entry {
    unsigned char pad[12];
    unsigned int value;
    unsigned char rest[0x1858];
} Entry;

extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern volatile unsigned int lbl_8064D390;
extern Entry lbl_8060D420[];

unsigned int fn_801B2878(int index)
{
    Node* first;
    Node* second;
    unsigned int value;
    Node* node;
    unsigned int current;

    first = lbl_8064D39C;
    second = lbl_8064D398;

    do {
        current = lbl_8064D390;
        lbl_8064D390 = current + 1;
        value = current;
        lbl_8064D390 = __rlwinm(lbl_8064D390, 0, 1, 31);

        node = first;
        while (node != 0) {
            if (node->value == value) {
                value = -1;
                break;
            }
            node = node->next;
        }

        node = second;
        while (node != 0) {
            if (node->value == value) {
                value = -1;
                break;
            }
            node = node->next;
        }
    } while (value == (unsigned int)-1);

    return lbl_8060D420[index].value = value;
}
