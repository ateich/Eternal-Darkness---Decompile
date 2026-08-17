typedef struct Entry {
    void* object;
    unsigned char pad[8];
    float value;
} Entry;

typedef struct Object {
    unsigned char pad[0x174];
    struct Object* parent;
} Object;

int fn_801209DC(Entry* a, Entry* b)
{
    Object* first = a->object;
    Object* second = b->object;
    float first_value = a->value;
    float second_value = b->value;
    int result;

    if (first->parent == second) {
        result = 1;
    } else if (second->parent == first) {
        result = -1;
    } else {
        result = (int)(second_value - first_value);
    }
    return result;
}
