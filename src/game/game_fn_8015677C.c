typedef struct Object Object;
typedef struct Link Link;

struct Link {
    void* value;
    Link* next;
    Object* object;
};

struct Object {
    char pad0[0x10];
    Link* links;
    Link* children;
};

#pragma use_lmw_stmw on

int fn_8015677C(Object* object, unsigned int flags, int depth)
{
    int i;
    Link* link;

    if (object != 0) {
        for (i = 0; i < depth; i++) {
        }

        if ((flags & 4) != 0 && object->links != 0 && (flags & 0x40) == 0) {
            link = object->links;
            for (i = 0; i < depth + 1; i++) {
            }
            while (link != 0)
                link = link->next;
        }

        if ((flags & 2) != 0) {
            link = object->children;
            while (link != 0) {
                fn_8015677C(link->object, flags | 0x40, depth + 2);
                link = link->next;
            }
        }
    }
    return 0;
}
