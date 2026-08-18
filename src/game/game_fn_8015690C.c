typedef struct Object {
    unsigned char unknown00[0x28];
    void* value28;
} Object;

void fn_8015690C(Object* object, void* value)
{
    object->value28 = value;
}
