typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x50]; void* value; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
void fn_8013041C(Object* object, void* value)
{
    object->runtime->value = value;
}
