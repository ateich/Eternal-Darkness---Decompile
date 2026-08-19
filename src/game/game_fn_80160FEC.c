typedef struct Child {
    char _pad00[0x194];
    int state;
} Child;

typedef struct Object {
    char _pad00[0x14];
    Child* child;
} Object;

extern char lbl_8024F5C0[];
extern void fn_800F6564(Child*, int);
extern void fn_80160F00(Object*, char*);
extern void exit(int);

void fn_80160FEC(Object* object, int state)
{
    Child* child = object->child;

    if (child != 0) {
        child->state = state;
        fn_800F6564(object->child, 1);
    } else {
        if (state != 4) {
            fn_80160F00(object, lbl_8024F5C0);
        }
        exit(1);
    }
}
