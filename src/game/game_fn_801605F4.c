typedef struct Object {
    char* current;
    char* allocation;
    char* end;
    int count;
} Object;

void fn_801605F4(Object* object)
{
    if ((object->current - object->allocation) / 16 < object->count - 1)
        object->end = object->allocation + ((object->count - 1) << 4);
}
