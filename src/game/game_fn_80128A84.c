typedef unsigned short u16;
typedef unsigned int u32;

extern int fn_80128AB8(void*, u16);
extern void fn_801287C4(void*, void*, u32, u32);

void fn_80128A84(void* queue, u16 value, u32 kind)
{
    fn_801287C4(queue, fn_80128AB8, value, kind);
}
