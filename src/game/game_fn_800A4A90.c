typedef struct VTable800A4A90 {
    unsigned char pad0[8];
    int (*callback)(void*, void*);
} VTable800A4A90;

typedef struct Handler800A4A90 {
    VTable800A4A90* vtable;
} Handler800A4A90;

typedef struct Object800A4A90 {
    unsigned char pad0[0x64];
    Handler800A4A90* handler;
} Object800A4A90;

int fn_800A4A90(Object800A4A90* object, void* value)
{
    return object->handler->vtable->callback(value, object->handler->vtable);
}
