typedef unsigned char u8;

typedef struct State80096D58 {
    u8 pad00[0x9F];
    u8 kind;
} State80096D58;

extern unsigned int fn_80036D5C(void*);
extern int fn_80201B54();
extern int fn_80201B64(void*);
extern void *fn_80201B8C();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201D34(void*, int);
extern void fn_80201D1C(void*, int);
extern void fn_8012B344();
extern void fn_8011FA8C(void*, int, unsigned int);
extern int fn_80201B6C(void*);
extern void fn_80201B7C(void*);

void fn_80096D58(register void* object, register void* resource)
{
    register unsigned int flags;
    State80096D58* state;

    flags = fn_80036D5C(object);
    ((void*)fn_80201B54(object));
    if (flags & 0x80000) {
        fn_80201B64(object);
        state = ((State80096D58*)fn_80201B8C(object));
        state->kind = 0x18;
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
        fn_80201D34(object, 0x2D);
        fn_80201D1C(object, 1);
        fn_8012B344(resource);
        fn_8011FA8C(resource, 0, 0x2000000);
        if (fn_80201B6C(object) == 1) {
            fn_80201B7C(object);
        }
    }
}
