typedef struct Object {
    char pad[0x3C];
    void* value;
} Object;

void fn_80156F78(Object* object, void* value)
{
    object->value = value;
}
