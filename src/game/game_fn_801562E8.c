typedef struct Object Object;
typedef struct Child Child;

struct Child {
    void* pad0;
    Child* next;
    Object* object;
};

struct Object {
    char pad0[0x10];
    Child* children;
    char pad14[0x10];
    void (*callback)(Object*, Object*);
    char pad28[0x1c];
    unsigned int flags;
};

extern unsigned int lbl_8064D0C0;
extern unsigned int lbl_8064D0C4;
extern unsigned int lbl_8064D0C8;
extern unsigned int lbl_8064D0D0;
extern unsigned int lbl_8064D5A8;
extern void fn_80156F10(void);

void fn_801562E8(Object* object, Object* parent)
{
    Child* child = object->children;

    if (object != 0 && object->callback != 0) {
        object->callback(object, parent);
        object->flags |= 0x200;
    }

    lbl_8064D0C0++;
    if (lbl_8064D0C0 > 10)
        fn_80156F10();
    if (lbl_8064D0C0 > lbl_8064D0C4) {
        lbl_8064D0C4 = lbl_8064D0C0;
        lbl_8064D0C8 = lbl_8064D5A8;
    }
    lbl_8064D0D0++;

    while (child != 0) {
        Child* next = child->next;
        fn_801562E8(child->object, object);
        child = next;
    }

    lbl_8064D0D0--;
    lbl_8064D0C0--;
}
