typedef struct Object {
    unsigned char unknown00[0x24];
    void* value24;
} Object;

void fn_80156904(Object* object, void* value)
{
    object->value24 = value;
}
