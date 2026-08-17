typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0xC]; int ids[4]; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
int fn_8013057C(Object* object, int id)
{
    int result = 0;
    RuntimeState* runtime = object->runtime;

    if (runtime->ids[0] == id) {
        result = 1;
    } else if (runtime->ids[1] == id) {
        result = 1;
    } else if (runtime->ids[2] == id) {
        result = 1;
    } else if (runtime->ids[3] == id) {
        result = 1;
    }
    return result;
}
