typedef struct Object {
    void* primary;
    void* secondary;
} Object;

extern void fn_80157738(void*);
extern void fn_8017CE74(void*, void*);
extern void* lbl_8064D110;

void fn_801577E0(Object* object)
{
    if (object->secondary != 0) {
        fn_80157738(object->secondary);
    }
    fn_8017CE74(lbl_8064D110, object);
}
