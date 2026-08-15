typedef struct VTable800A4A60 {
    unsigned char pad0[0x44];
    void (*callback)(void*, void*);
} VTable800A4A60;

typedef struct Handler800A4A60 {
    VTable800A4A60* vtable;
} Handler800A4A60;

typedef struct Object800A4A60 {
    unsigned char pad0[0x64];
    Handler800A4A60* handler;
} Object800A4A60;

void fn_800A4A60(void* arg0, Object800A4A60* object)
{
    object->handler->vtable->callback(arg0, object);
}
