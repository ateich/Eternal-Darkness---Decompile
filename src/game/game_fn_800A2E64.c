typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2E64 {
    u8 pad000[0x160];
    void* handle;
} Object800A2E64;

extern u16 fn_801869DC(void*);
extern void fn_801869E4(void*, u16, u16, int);

int fn_800A2E64(Object800A2E64* object, u16 value)
{
    int result = 0;
    if (object->handle != 0) {
        u16 current = fn_801869DC(object->handle);
        if (current == value) {
        } else {
            fn_801869E4(object->handle, value, value, 0);
        }
        result = 1;
    }
    return result;
}
