typedef struct Object Object;

struct Object {
    Object* previous;
    Object* next;
    Object* link_previous;
    Object* link_next;
    char pad10[0x34];
    unsigned int flags;
};

extern int fn_801565E0(Object*);
extern void fn_801563C0(Object*);
extern void fn_80156010(Object*, int);

int fn_8015662C(Object* object)
{
    int result;

    if ((object->flags & 1) == 0) {
        if (object->previous != 0)
            object->previous->next = object->next;
        if (object->next != 0)
            object->next->previous = object->previous;

        result = fn_801565E0(object);
        fn_801563C0(object);
        object->flags |= 2;
        object->link_next = 0;
        object->link_previous = 0;
        object->next = 0;
        object->previous = 0;
        fn_80156010(object, 2);
    } else {
        result = 0;
    }
    return result;
}
