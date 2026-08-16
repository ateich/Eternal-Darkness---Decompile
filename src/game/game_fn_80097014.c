typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80097014 {
    u8 pad00[0x2C];
    u32 flags;
} State80097014;

typedef struct Context80097014 {
    u8 pad00[0x68];
    State80097014* state;
} Context80097014;

typedef struct ActorData80097014 {
    u8 pad00[0x9E];
    u8 kind;
    u8 subtype;
} ActorData80097014;

extern int fn_80200C38(void*);
extern int fn_80200C20(void*);
extern u32 fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern int fn_801A7498(int);
extern void *fn_80201814();
extern ActorData80097014*fn_80201B8C();
extern int fn_800DE354(void);
extern int fn_80201B44();
extern void *fn_80201BC8();
extern int fn_80092BBC(void*, void*, void*);
extern void fn_80096E24(void*);
extern int fn_800654F8(int);

void fn_80097014(void* unused, register void* object, register void* random,
                 register State80097014* state, register Context80097014* context,
                 register int* output)
{
    register int random_value;
    register int mapped;
    register int actor_flags;
    register ActorData80097014* actor_data;
    register int special;
    int current;

    if ((state->flags & 4) != 0) {
        return;
    }

    random_value = fn_80200C38(random);
    special = fn_80036D5C(object) & 0x80;
    actor_flags = fn_80036D5C(object);
    mapped = fn_801A7498(random_value);
    actor_data = fn_80201814();
    if (actor_data != 0) {
        actor_data = fn_80201B8C(actor_data);
    } else {
        actor_data = 0;
    }

    if (mapped == fn_800DE354()) {
        context->state->flags |= 0x80;
    }

    mapped = fn_80200C20(random);
    current = fn_80201B44();
    if (current == mapped && (actor_flags & 0x8000) != 0) {
        fn_80096E24(object);
        fn_80036DA4(object, (actor_flags & ~0x8000) | 0x80);
    }

    if (special == 0 && fn_80092BBC(object, fn_80201BC8(object), context) != 0 &&
        actor_data != 0 && actor_data->kind == 2 &&
        (actor_data->subtype == 5 || actor_data->subtype == 8)) {
        state->flags |= 0x400;
        state->flags |= 0x800;
    } else if ((state->flags & 0x100) == 0 && (state->flags & 0x20) == 0 && special == 0) {
        state->flags |= 0x200;
    }

    if (output != 0) {
        *output = fn_800654F8(random_value);
    }
}
