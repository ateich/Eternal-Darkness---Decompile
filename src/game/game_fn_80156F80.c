typedef struct Link {
    char pad[8];
    void* owner;
} Link;

typedef struct ObjectA {
    char pad[0x14];
    Link* link;
} ObjectA;

typedef struct ObjectB {
    char pad[0x10];
    Link* link;
} ObjectB;

extern void fn_80155D50(void);
extern Link* fn_80156080(Link*);

int fn_80156F80(ObjectA* first, ObjectB* second)
{
    fn_80155D50();
    if (first != 0 && second != 0) {
        first->link = fn_80156080(first->link);
        first->link->owner = second;
        second->link = fn_80156080(second->link);
        second->link->owner = first;
    }
    return 1;
}
