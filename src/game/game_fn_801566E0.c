typedef struct Object Object;

struct Object {
    Object* previous;
    Object* next;
    void* value;
};

extern void fn_80155EBC(Object*);

Object* fn_801566E0(Object* head, void* value)
{
    Object* result = head;
    Object* current = head;

    while (current != 0) {
        if (current->value == value) {
            if (current->previous != 0)
                current->previous->next = current->next;
            if (current->next != 0)
                current->next->previous = current->previous;
            if (current == head)
                result = current->next;
            current->previous = 0;
            current->next = 0;
            current->value = 0;
            fn_80155EBC(current);
            return result;
        }
        current = current->next;
    }
    return result;
}
