typedef struct Primary { void** values; } Primary;
typedef struct Object { Primary* primary; } Object;
void* fn_80157864(Object* object, int index)
{
    if (object->primary->values != 0) return object->primary->values[index];
    return 0;
}
