typedef unsigned char u8;

typedef struct Object800A2D78 {
    u8 pad00[0x64];
    void* handle;
} Object800A2D78;

extern void fn_801A4418(void*, int);

void fn_800A2D78(Object800A2D78* object)
{
    if (object->handle != 0) {
        fn_801A4418(object->handle, 0);
        object->handle = 0;
    }
}
