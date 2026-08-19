typedef unsigned char u8;
typedef struct RuntimeState { int vector[3]; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void *);
void fn_8013009C(Object* object, RuntimeState* state)
{
    fn_80125ECC(object);
    *object->runtime = *state;
}
