typedef unsigned char u8;
typedef struct RuntimeState { u8 pad[0x4C]; unsigned int mask; } RuntimeState;
typedef struct Object { u8 pad[0x290]; RuntimeState* runtime; } Object;
extern void fn_80125ECC(void*);
void fn_80130214(Object* object, u8 mask)
{
    fn_80125ECC(object);
    object->runtime->mask = mask;
}
