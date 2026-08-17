typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x54]; u8 index; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void*);
u8 fn_8013017C(Object* object)
{
    fn_80125ECC(object);
    return object->runtime->index;
}
