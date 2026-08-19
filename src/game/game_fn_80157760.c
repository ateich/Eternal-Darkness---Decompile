typedef struct Object {
    void* primary;
    void* secondary;
    int primary_index;
    int secondary_index;
    unsigned int flags;
} Object;

extern Object* fn_8017CDB4(void*);
extern void* fn_80157688(int, int);
extern void* fn_801576C4(int, int);
extern void* lbl_8064D110;

Object* fn_80157760(int primary_index, int secondary_index)
{
    Object* object = fn_8017CDB4(lbl_8064D110);
    object->primary = fn_80157688(primary_index, 0);
    object->secondary = fn_801576C4(secondary_index, 0);
    object->flags = 0;
    object->primary_index = primary_index;
    object->secondary_index = secondary_index;
    return object;
}
