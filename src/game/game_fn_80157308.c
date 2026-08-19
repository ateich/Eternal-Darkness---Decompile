typedef struct Object {
    char pad00[0x3C];
    int identifier;
} Object;

typedef struct Node {
    struct Node* previous;
    struct Node* next;
    Object* object;
} Node;

extern Node* fn_80155F40(void);

Object* fn_80157308(int identifier)
{
    Node* node = fn_80155F40();

    while (node != 0) {
        Object* object = node->object;
        if (object->identifier == identifier) {
            return object;
        }
        node = node->next;
    }
    return 0;
}
