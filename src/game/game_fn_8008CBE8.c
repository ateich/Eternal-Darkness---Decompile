typedef unsigned int u32;

typedef struct ObjectState {
    unsigned char pad[0x48];
    u32* value;
} ObjectState;

extern ObjectState*fn_80201B8C();

u32 fn_8008CBE8(void* object, u32 value)
{
    u32 old_value;
    ObjectState* state = fn_80201B8C(object);
    old_value = *state->value;
    *state->value = value;
    return old_value;
}
