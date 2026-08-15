typedef unsigned char u8;

typedef struct Runtime800A4978 {
    u8 pad0[0x190];
    int current;
    u8 pad194[4];
    int selected;
} Runtime800A4978;

typedef struct Context800A4978 {
    u8 pad0[0x8c];
    struct Values800A4978* values;
} Context800A4978;

typedef struct Values800A4978 {
    u8 pad0[0xea];
    short entry[1];
} Values800A4978;

extern Runtime800A4978* fn_800A1D28(void*);
extern void fn_800A49FC(void*, int*, Context800A4978*);

void fn_800A4978(void* object, void* owner, Context800A4978* context)
{
    Values800A4978* values = context->values;
    Runtime800A4978* runtime = fn_800A1D28(object);

    if (runtime->current != -1 && runtime->current == runtime->selected) {
        if (values->entry[runtime->current] == 0) {
            fn_800A49FC(owner, &runtime->selected, context);
        }
    }
}
