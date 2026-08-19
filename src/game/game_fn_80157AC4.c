typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Object { void* primary; unsigned char* secondary; } Object;
extern u16 fn_80158234(Object*);
extern void fn_80158250(Object*, u16);

void fn_80157AC4(Object* object, u32 value)
{
    if ((fn_80158234(object) & 0x500) != 0 && value != 0x10) {
        fn_80158250(object, 0x100);
    } else if (value == 0x10) {
        fn_80158250(object, 0x400);
    }
    *(u32*)object->secondary = value;
}
