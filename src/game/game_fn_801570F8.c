typedef struct Link {
    struct Link* prev;
    struct Link* next;
    void* owner;
} Link;

typedef struct ObjectA {
    char pad[0x14];
    Link* links;
} ObjectA;

typedef struct ObjectB {
    char pad[0x10];
    Link* link;
} ObjectB;

extern void fn_80155D50(void);
extern void fn_80155EBC(Link*);
extern Link* fn_801566E0(Link*, ObjectA*);

void fn_801570F8(ObjectA* first, ObjectB* second)
{
    Link* node;
    Link* next;

    fn_80155D50();
    if (first != 0 && second != 0) {
        node = first->links;
        while (node != 0) {
            next = node->next;
            if (node->owner == second) {
                ((ObjectB*)node->owner)->link =
                    fn_801566E0(((ObjectB*)node->owner)->link, first);
                if (node->prev != 0) {
                    node->prev = node->next;
                } else {
                    first->links = node->next;
                }
                if (node->next != 0) {
                    node->next->prev = node->prev;
                }
                fn_80155EBC(node);
            }
            node = next;
        }
    }
}
