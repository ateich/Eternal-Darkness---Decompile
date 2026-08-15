typedef unsigned char u8;

typedef struct Object800A4D04 {
    u8 pad0[0x268];
    void* handle;
} Object800A4D04;

extern void fn_801AC980(void*, int);

void fn_800A4D04(Object800A4D04* object)
{
    if (object->handle != 0) {
        fn_801AC980(object->handle, 0x14);
        object->handle = 0;
    }
}
