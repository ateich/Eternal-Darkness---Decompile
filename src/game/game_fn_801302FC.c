typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x48]; int value; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void *);
void fn_801302FC(Object* object, int value)
{
    fn_80125ECC(object);
    object->runtime->value = value;
}
