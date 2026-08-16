typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x8C];
    void *resource;
} RuntimeState;

typedef struct Resource {
    u8 pad[0x146];
    short value;
} Resource;

extern RuntimeState *fn_80201B8C();
extern void *fn_80201B54();
extern void fn_8016B400(int, void *, int);

int fn_800CCA44(void *object)
{
    RuntimeState *state = fn_80201B8C(object);
    Resource *resource = state != 0 ? state->resource : 0;

    if (resource != 0 && resource->value != 0 && resource->value > 0) {
        void *model = fn_80201B54(object);
        int value = resource->value;
        fn_8016B400(value, model, 0);
        return 1;
    }
    return 0;
}
