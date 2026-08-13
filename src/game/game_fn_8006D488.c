typedef struct Object {
    unsigned char pad_0[0x38];
    void *value;
} Object;

typedef struct Node {
    unsigned char pad_0[0x44];
    void *object;
} Node;

extern Object *fn_80201814(void *object);
extern Node *fn_80036D38(Object *object);

Object *fn_8006D488(Object *object)
{
    Object *result = 0;

    if (object != 0) {
        Object *entry = fn_80201814(object->value);
        if (entry != 0) {
            Node *node = fn_80036D38(entry);
            result = fn_80201814(node->object);
        }
    }
    return result;
}
