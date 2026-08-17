typedef unsigned int u32;
typedef struct Object { char pad_0[0x118]; u32 state; } Object;
extern int fn_8015E830(u32);
int fn_80135970(Object* object)
{
    int result = 0;
    u32 state = object->state;
    if ((state & 0x80000000) != 0 || fn_8015E830(state) != 0) result = 1;
    return result;
}
