typedef struct Object {
    unsigned char pad0[8];
    void* value;
} Object;

extern void fn_80162114(void*, void*, void*);

void fn_8015EA7C(Object* object, void* value)
{
    fn_80162114(object, value, object->value);
}
