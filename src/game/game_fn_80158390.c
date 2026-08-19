typedef unsigned int u32;

typedef struct Object Object;

extern u32 fn_80157EFC(Object*);

int fn_80158390(Object* object, u32*** values, int requested)
{
    int matches = 0;
    int index;
    u32 mask = fn_80157EFC(object);

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
