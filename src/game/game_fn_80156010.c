typedef struct Node Node;

struct Node {
    Node* next;
    Node* prev;
    void* value;
    unsigned char type;
};

extern Node* fn_80155F8C(void);
extern Node* fn_80155E68(void);

void fn_80156010(void* value, unsigned char type)
{
    Node* head = fn_80155F8C();
    Node* node = fn_80155E68();

    node->next = head;
    node->prev = head->prev;
    if (head->prev != 0)
        head->prev->next = node;
    head->prev = node;
    node->type = type;
    node->value = value;
}
