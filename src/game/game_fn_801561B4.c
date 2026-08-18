typedef struct Value Value;
typedef struct Node Node;

#pragma use_lmw_stmw on

struct Value {
    char pad0[8];
    void* owner;
    void* field_c;
    char pad10[0x2c];
    int id;
};

struct Node {
    Node* next;
    Node* prev;
    Value* value;
};

extern int fn_80156998(void);
extern Node* fn_80157308(void);
extern unsigned char fn_8015617C(Value*);
extern int fn_80156190(Value*, Node*);
extern Node* fn_80155F40(void);
extern Value* fn_80155E08(void);
extern Node* fn_80155E68(void);
extern void fn_80156120(Value*);

int fn_801561B4(Value* owner)
{
    int id = fn_80156998();
    int result = 0;
    Node* supplied = fn_80157308();

    if (supplied != 0) {
        if (!fn_8015617C(owner))
            result = fn_80156190(owner, supplied);
    } else {
        Node* head = fn_80155F40();
        Value* value = fn_80155E08();
        Node* node = fn_80155E68();

        if (head != 0 && node != 0) {
            Node* next = head->prev;
            node->prev = next;
            node->next = head;
            head->prev = node;
            if (next != 0)
                next->next = node;

            fn_80156120(value);
            value->id = id;
            result = 1;
            value->owner = owner;
            value->field_c = 0;
            node->value = value;
            owner->owner = 0;
            owner->field_c = value;
        } else {
            result = 0;
        }
    }
    return result;
}
