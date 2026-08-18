typedef struct Value Value;
typedef struct Node Node;

struct Value {
    char pad[0x3c];
    int id;
};

struct Node {
    Node* next;
    Node* prev;
    Value* value;
};

extern Node* fn_80155F40(void);

Node* fn_801560CC(int id)
{
    Node* node = fn_80155F40();

    while (node != 0) {
        if (node->value->id == id)
            return node;
        node = node->prev;
    }
    return 0;
}
