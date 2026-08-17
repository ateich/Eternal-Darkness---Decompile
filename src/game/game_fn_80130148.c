typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x44]; int state; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void*);
int fn_80130148(Object* object)
{
    fn_80125ECC(object);
    return object->runtime->state;
}
