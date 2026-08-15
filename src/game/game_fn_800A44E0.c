typedef unsigned char u8;

typedef struct Object800A44E0 {
    u8 pad0[0x24c];
    int children[4];
    signed char child_count;
} Object800A44E0;

int fn_800A44E0(Object800A44E0* object, int child)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (object->children[i] == 0) {
            object->children[i] = child;
            object->child_count++;
            break;
        }
    }
    return object->child_count;
}
