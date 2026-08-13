typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec800A0324 {
    float x;
    float y;
    float z;
} Vec800A0324;

typedef struct Object800A0324 {
    u8 pad00[0x44];
    int resource;
} Object800A0324;

typedef struct List800A0324 {
    u8 pad00[0x0D];
    u8 count;
    u8 pad0E[0xA6];
    int handles[1];
} List800A0324;

typedef struct State800A0324 {
    u8 pad00[0x38];
    int resource;
    u8 pad3C[0x88];
    List800A0324* list;
} State800A0324;

extern Vec800A0324 lbl_802396D4;
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_8011F114(Vec800A0324*, void*);
extern Object800A0324* fn_80036D38(void*);
extern u32 fn_80178F14(int, int, int, int, int, int);
extern void fn_80067180(void*);
extern void* fn_80201B54(void*);
extern void fn_8020123C(int, void*, void*, int);
extern void fn_8009EF8C(State800A0324*);

int fn_800A0324(State800A0324* state)
{
    Vec800A0324 origin = lbl_802396D4;
    Vec800A0324 position;
    Vec800A0324 copy;
    List800A0324* list;
    void* owner;
    void* actor;
    void* linked;
    void* transform;
    void* first;
    int i;

    list = (List800A0324*)((u8*)state->list + 0x48);
    owner = fn_80201814(state->resource);
    linked = 0;
    if (owner != 0) {
        transform = fn_80201BC8(owner);
        if (transform != 0) {
            fn_8011F114(&origin, transform);
        }
        linked = fn_80201814(fn_80036D38(owner)->resource);
    }

    for (i = 0; i < list->count; i++) {
        actor = fn_80201814(list->handles[i]);
        if (actor != 0) {
            transform = fn_80201BC8(actor);
            if (transform != 0) {
                fn_8011F114(&position, transform);
                copy = position;
                if (fn_80178F14((int)copy.x, (int)copy.y, (int)copy.z,
                                (int)origin.x, (int)origin.y, (int)origin.z) <= 150) {
                    fn_80067180(actor);
                    first = fn_80201B54(linked);
                    fn_8020123C(0x56, fn_80201B54(linked), first, 0);
                }
            }
        }
    }
    fn_8009EF8C(state);
    return 1;
}
