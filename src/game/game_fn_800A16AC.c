typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec800A16AC {
    float x;
    float y;
    float z;
} Vec800A16AC;

typedef struct State800A16AC {
    u8 pad00[0x38];
    u32 resource;
} State800A16AC;

extern void fn_8006ED98(State800A16AC*);
extern void* fn_80201814();
extern void* fn_80201BC8();
extern void fn_800C1B50(u32, int, int, float, float);
extern void fn_8011F114();
extern void fn_8012AC74(void*, Vec800A16AC*, int);
extern float lbl_8064EDB8;

int fn_800A16AC(register State800A16AC* state)
{
    void* transform;
    Vec800A16AC position;

    fn_8006ED98(state);
    transform = fn_80201BC8(fn_80201814(state->resource));
    fn_800C1B50(state->resource, 0xF, 1, lbl_8064EDB8, lbl_8064EDB8);
    fn_8011F114(&position, transform);
    fn_8012AC74(transform, &position, 3);
    return 1;
}
