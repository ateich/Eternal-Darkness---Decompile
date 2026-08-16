typedef unsigned int u32;

typedef struct ObjectState {
    unsigned char pad[0x8c];
    u32* flags;
} ObjectState;

extern ObjectState*fn_80201B8C();
extern u32 fn_8011FAEC(void*);
extern void* fn_80201B3C(void);
extern int fn_80201B5C(void*);

int fn_8008C93C(void* object, void* resource)
{
    int result = 0;
    ObjectState* state = fn_80201B8C(object);
    if ((*state->flags & 0x00400000) == 0 &&
        (fn_8011FAEC(resource) & 0x40000000) != 0 &&
        fn_80201B5C(fn_80201B3C()) != 50) {
        result = 1;
    }
    return result;
}
