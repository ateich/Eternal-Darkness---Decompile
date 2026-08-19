typedef unsigned int u32;

typedef struct Object {
    unsigned char pad[396];
    u32 mask;
} Object;

int fn_80158264(Object* object, u32*** values, int requested)
{
    u32 mask = object->mask;
    int matches = 0;
    int index;

    if (mask != 0) {
        for (index = 0; index < 32; index++) {
            u32 value = (**values)[index];
            if (value != 0 && (value & mask) == value) {
                matches++;
                if (requested >= 0 && matches == requested) {
                    return index;
                }
            }
        }
    }
    if (requested >= 0) {
        return -1;
    }
    return matches;
}
