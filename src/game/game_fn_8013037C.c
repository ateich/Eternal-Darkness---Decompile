typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x40]; float value; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void*);
void fn_8013037C(Object* object, float value)
{
    fn_80125ECC(object);
    object->runtime->value = value;
}
