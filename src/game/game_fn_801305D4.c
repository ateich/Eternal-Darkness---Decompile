typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0xC]; int ids[4]; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern int fn_8012DCBC(Object*, int, int, void*, int, int);
int fn_801305D4(Object* object)
{
    int i;
    int result = 0;
    for (i = 0; i < 4; i++) {
        int value;
        int id = object->runtime->ids[i];
        if (id != -1 && fn_8012DCBC(object, id, 3, &value, 0, 0)) {
            result = 1;
            break;
        }
    }
    return result;
}
