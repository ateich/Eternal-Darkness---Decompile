typedef struct Object {
    char pad00[0x28];
    void (*callback)(struct Object*, void*);
    char pad2C[0xC];
    void* callback_arg;
} Object;

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    Object* object;
    signed char countdown;
} Node;

extern Node* fn_80155F8C(void);
extern void fn_80155E3C(Object*);
extern void fn_80155EBC(Node*);

void fn_80156B1C(void (*removed)(Object*))
{
    Node* node = fn_80155F8C()->next;

    while (node != 0) {
        Node* next = node->next;

        if (node->countdown > 0) {
            node->countdown--;
        }

        if (node->countdown == 0) {
            Object* object = node->object;

            if (object->callback != 0) {
                object->callback(object, object->callback_arg);
            }

            node->prev->next = node->next;
            if (node->next != 0) {
                node->next->prev = node->prev;
            }

            if (removed != 0) {
                removed(node->object);
            }

            fn_80155E3C(node->object);
            fn_80155EBC(node);
            node->next = 0;
            node->prev = 0;
            node->object = 0;
        }

        node = next;
    }
}
