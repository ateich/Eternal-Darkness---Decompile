typedef unsigned char u8;

typedef void (*Callback800A2068)(void*, void*);

typedef struct Vtable800A2068 {
    u8 pad000[0x34];
    Callback800A2068 callback;
} Vtable800A2068;

typedef struct Target800A2068 {
    Vtable800A2068* vtable;
} Target800A2068;

typedef struct Context800A2068 {
    u8 pad000[0x64];
    Target800A2068* target;
} Context800A2068;

extern Context800A2068* fn_80201B8C();

void fn_800A2068(void* object, void* argument)
{
    Context800A2068* context = fn_80201B8C(object);
    context->target->vtable->callback(object, argument);
}
