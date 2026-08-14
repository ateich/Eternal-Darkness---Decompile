typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec800A1724 {
    float x;
    float y;
    float z;
} Vec800A1724;

typedef struct Work800A1724 {
    u8 pad00[0x68];
    Vec800A1724 position;
} Work800A1724;

typedef struct State800A1724 {
    u8 pad00[0x38];
    u32 resource;
    u8 pad3C[0x88];
    Work800A1724* work;
} State800A1724;

typedef struct Context800A1724 {
    u8 pad00[8];
    short counter;
} Context800A1724;

extern Context800A1724* fn_8006ED98(State800A1724*);
extern void* fn_80201814(u32);
extern void* fn_80201BC8(void*);
extern void fn_8011F114(Vec800A1724*, void*);
extern Vec800A1724* fn_8011F770(void*);
extern void fn_8012AC74(void*, Vec800A1724*, int);

int fn_800A1724(register State800A1724* state)
{
    Work800A1724* work = state->work;
    Context800A1724* context;
    void* transform;
    Vec800A1724 value;
    Vec800A1724* position;

    context = fn_8006ED98(state);
    if (context->counter > 0) {
        transform = fn_80201BC8(fn_80201814(state->resource));
        fn_8011F114(&value, transform);
        position = fn_8011F770(transform);
        if (position != 0) {
            *position = work->position;
            fn_8012AC74(transform, &value, 3);
        }
    }
    return 1;
}
