typedef struct Object Object;
typedef struct Link Link;

struct Link {
    Link* previous;
    Link* next;
    Object* object;
};

struct Object {
    Object* previous;
    Object* next;
    char pad08[8];
    Link* links_previous;
    Link* links_next;
    char pad18[0xC];
    void (*callback)(Object*, Object*);
    char pad28[0x1C];
    unsigned int flags;
};

extern Object* fn_80155EF4(void);
extern void fn_80155D50(void);
extern void fn_80155EBC(Link*);
extern void fn_8015662C(Object*);
extern Link* fn_801566E0(Link*, Object*);
extern unsigned int lbl_8064D0CC;
extern unsigned int lbl_8064D0D0;

void fn_801571C4(void)
{
    Object* object;

    object = fn_80155EF4();
    lbl_8064D0CC++;
    while (object != 0) {
        Object* next_object = object->previous;

        if ((object->flags & 2) != 0) {
            Link* link = object->links_previous;
            Link* link2 = object->links_next;

            while (link != 0) {
                Link* next = link->next;
                if (link->object != 0) {
                    if (link->object->callback != 0) {
                        link->object->callback(link->object, object);
                    }
                    if (link->object->links_next != 0) {
                        fn_80155D50();
                        link->object->links_next =
                            fn_801566E0(link->object->links_next, object);
                    }
                }
                fn_80155EBC(link);
                link = next;
            }

            while (link2 != 0) {
                Link* next = link2->next;
                if (link2->object != 0 && link2->object->links_previous != 0) {
                    lbl_8064D0D0++;
                    link2->object->links_previous =
                        fn_801566E0(link2->object->links_previous, object);
                    lbl_8064D0D0--;
                }
                fn_80155EBC(link2);
                link2 = next;
            }
            fn_8015662C(object);
        }
        object = next_object;
    }
    lbl_8064D0CC--;
}
