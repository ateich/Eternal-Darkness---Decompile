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
};

extern unsigned int lbl_8064D0C0;
extern unsigned int lbl_8064D0CC;
extern unsigned int lbl_8064D0D0;
extern void fn_801562E8(Object*, Object*);

void fn_801563C0(Object* object)
{
    Child* child = object->children;

    lbl_8064D0C0 = 0;
    lbl_8064D0CC++;
    lbl_8064D0D0++;
    while (child != 0) {
        Child* next = child->next;
        fn_801562E8(child->object, object);
        child = next;
    }
    lbl_8064D0D0--;
    lbl_8064D0CC--;
}
