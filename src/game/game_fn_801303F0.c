typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0xC]; int ids[4]; float first[4]; float second[4]; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
void fn_801303F0(Object* object, int id, int index, float first, float second)
{
    object->runtime->ids[index] = id;
    object->runtime->first[index] = first;
    object->runtime->second[index] = second;
}
