typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Flags80093C04 {
    u8 pad00[0x2C];
    u32 flags;
} Flags80093C04;

typedef struct Runtime80093C04 {
    u8 pad00[0x68];
    Flags80093C04* flags;
} Runtime80093C04;

typedef struct State80093C04 {
    u8 pad00[0x54];
    int value;
} State80093C04;

extern int fn_80201B54();
extern int fn_80200C20(void*);
extern void* fn_801294DC(void*, int, int, int);
extern Runtime80093C04*fn_80201B8C();
extern State80093C04* fn_80036D38(void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_80093C04(register void* object, register void* resource,
                 register void* value_source, register int* result)
{
    register Runtime80093C04* runtime;

    fn_80201B54(object);
    value_source = (void*)fn_80200C20(value_source);
    if (fn_801294DC(resource, 0x25, 0x25, 8) != 0) {
        runtime = fn_80201B8C(object);
        {
            State80093C04* state = fn_80036D38(object);
            if (runtime != 0 && runtime->flags != 0) {
                runtime->flags->flags |= 0x200;
                runtime->flags->flags |= 0x80;
                runtime->flags->flags |= 0x800;
                runtime->flags->flags |= 0x400;
            }
            state->value = (int)value_source;
        }
        if (result != 0) {
            *result = 1;
        }
        fn_80201D2C(object, 0x38);
        fn_80201D14(object, 1);
    } else if (result != 0) {
        *result = 0;
    }
}
