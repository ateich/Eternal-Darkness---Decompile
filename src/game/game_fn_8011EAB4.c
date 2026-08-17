typedef struct Object {
    unsigned char pad0[68];
    unsigned char field_44[240];
    int override;
} Object;

extern void fn_80129CE8(void*, void*, int, int, int);

void fn_8011EAB4(Object* object, int value)
{
    void* field = object->field_44;
    int selected = value;

    if (object->override != -1) {
        selected = object->override;
    }
    fn_80129CE8(object, field, selected, 33, 1);
}
