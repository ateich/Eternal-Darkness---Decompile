typedef struct Object {
    char padding00[108];
    int active;
} Object;

typedef struct Nested {
    char padding00[4];
    int state;
} Nested;

typedef struct Source {
    char padding00[8];
    Nested* nested;
} Source;

typedef struct Context {
    void* handler;
    char padding04[88];
    Source* source;
} Context;

typedef void (*Callback)(Object*, void*);

extern void fn_801607D8(Object*, Context*, Callback);

void fn_8016088C(Object* object, Source* source, Callback callback, void* handler)
{
    Context context;

    if (object->active != 0) {
        context.source = source;
        context.handler = handler;
        source->nested->state = 0;
        fn_801607D8(object, &context, callback);
    }
}
