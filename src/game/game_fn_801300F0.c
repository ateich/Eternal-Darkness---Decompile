typedef unsigned char u8;
typedef struct Object { u8 pad[0x290]; void* runtime; } Object;
void* fn_801300F0(Object* object)
{
    void* result = 0;
    void* runtime = object->runtime;

    if (runtime != 0) {
        result = runtime;
    }
    return result;
}
