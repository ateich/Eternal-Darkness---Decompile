typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800971A0 {
    u8 pad00[0x2C];
    u32 flags;
} State800971A0;

typedef struct ActorData800971A0 {
    u8 pad00[0x9E];
    u8 kind;
    u8 subtype;
} ActorData800971A0;

extern int fn_80200C38(void*);
extern u32 fn_80036D5C(void*);
extern int fn_801A7498(int);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern int fn_80092BBC(void*, void*, void*);
extern void fn_80064B38(void*, void*, void*);

void fn_800971A0(void* unused, register void* object, register void* random,
                 register State800971A0* state, register void* context,
                 register void* final_arg)
{
    register int random_value;
    register int special;
    register ActorData800971A0* actor_data;

    if ((state->flags & 4) != 0) {
        return;
    }

    random_value = fn_80200C38(random);
    special = fn_80036D5C(object) & 0x80;
    fn_801A7498(random_value);
    actor_data = fn_80201814();
    if (actor_data != 0) {
        actor_data = ((ActorData800971A0*)fn_80201B8C(actor_data));
    } else {
        actor_data = 0;
    }

    if (special == 0 && fn_80092BBC(object, fn_80201BC8(object), context) != 0 &&
        actor_data != 0 && actor_data->kind == 2 &&
        (actor_data->subtype == 5 || actor_data->subtype == 8)) {
        state->flags |= 0x400;
        state->flags |= 0x800;
    } else if ((state->flags & 0x100) == 0 && (state->flags & 0x20) == 0 &&
               (fn_80036D5C(object) & 0x80) == 0) {
        state->flags |= 0x200;
    }

    fn_80064B38(object, random, final_arg);
}
