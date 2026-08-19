typedef struct Node {
    char pad[4];
    struct Node* next;
    void* object;
} Node;

typedef struct List {
    char pad[4];
    Node* head;
} List;

typedef struct Object {
    char pad[0x38];
    unsigned int id;
} Object;

extern List* fn_80155F8C(void);

int fn_80157050(unsigned int id)
{
    Node* node = fn_80155F8C()->head;
    int result = 0;

    while (node != 0) {
        if (((Object*)node->object)->id == id) {
            result = 1;
            break;
        }
        node = node->next;
    }
    return result;
}
