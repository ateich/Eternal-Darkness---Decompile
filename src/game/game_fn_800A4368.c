typedef unsigned char u8;

typedef struct Object800A4368 {
    u8 pad0[0x24c];
    int children[4];
    signed char child_count;
} Object800A4368;

int fn_800A4368(Object800A4368* object, int child)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (object->children[i] == child) {
            object->children[i] = 0;
            object->child_count--;
        }
    }
    return object->child_count;
}
