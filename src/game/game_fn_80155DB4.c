typedef struct Node Node;

struct Node {
    Node* next;
    char pad[0x34];
    unsigned int id;
};

extern Node** fn_80155EF4(void);

Node* fn_80155DB4(unsigned int id)
{
    Node* node = *fn_80155EF4();

    while (node != 0) {
        if (node->id == id)
            return node;
        node = node->next;
    }
    return 0;
}
