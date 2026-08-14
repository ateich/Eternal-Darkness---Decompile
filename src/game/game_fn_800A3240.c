typedef struct VTable800A3240 {
    unsigned char pad00[0x38];
    void (*callback)(void*, void*);
} VTable800A3240;

typedef struct Object800A3240 {
    VTable800A3240* vtable;
} Object800A3240;

void fn_800A3240(Object800A3240* object, void* first, void* second)
{
    object->vtable->callback(first, second);
}
