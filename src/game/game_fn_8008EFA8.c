typedef struct Runtime {
    unsigned char pad[0x50];
    struct State* state;
} Runtime;

typedef struct State {
    unsigned char pad[0x1C];
    short value1;
    short value2;
} State;

extern void* fn_80200C20(void*);
extern void *fn_80201814();
extern int fn_80201B5C(void*);
extern Runtime*fn_80201B8C();
extern void *fn_80201BC8();
extern void fn_80066754(void*, void*, void*);
extern void fn_80128EAC(void*);

void fn_8008EFA8(void* object, void* event, void* data)
{
    void* actor;
    Runtime* runtime;
    void* result;

    if (event != 0) {
        actor = fn_80201814(fn_80200C20(event));
        if ((actor != 0 && fn_80201B5C(actor) == 24) || actor == object) {
            runtime = fn_80201B8C(object);
            result = fn_80201BC8(object);
            runtime->state->value1 = 105;
            runtime->state->value2 = 105;
            fn_80066754(object, event, data);
            fn_80128EAC(result);
        }
    }
}
