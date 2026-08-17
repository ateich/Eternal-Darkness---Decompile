typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x50]; void* value; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
void* fn_80130428(Object* object)
{
    return object->runtime->value;
}
