typedef unsigned char u8;

typedef struct Handler800A230C Handler800A230C;

typedef struct Vtable800A230C {
    u8 pad000[0xC];
    void (*callback)(void*, void*, void*, void*);
} Vtable800A230C;

struct Handler800A230C {
    Vtable800A230C* vtable;
};

typedef struct Context800A230C {
    u8 pad000[0x64];
    Handler800A230C* handler;
    u8 pad068[0x2C];
    void* value;
} Context800A230C;

extern Context800A230C* fn_80201B8C(void*);
extern void fn_800A3E94(Handler800A230C*, void*);

void fn_800A230C(void* first, void* second, void* third, void* fourth)
{
    Context800A230C* context = fn_80201B8C(first);

    if (context->handler->vtable == 0) {
        fn_800A3E94(context->handler, context->value);
    }
    context->handler->vtable->callback(first, second, third, fourth);
}
