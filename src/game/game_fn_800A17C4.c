typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800A17C4 {
    u8 pad00[0x38];
    u32 resource;
} State800A17C4;

typedef struct Context800A17C4 {
    int mode;
    u8 pad04[4];
    short counter;
} Context800A17C4;

typedef struct Inner800A17C4 {
    u8 pad00[0x44];
    u32 resource;
} Inner800A17C4;

typedef struct Info800A17C4 {
    u8 pad00[0x8C];
    Inner800A17C4* inner;
} Info800A17C4;

extern Context800A17C4* fn_8006ED98(State800A17C4*);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void fn_8020104C(int, int, u32, int, float);
extern float lbl_8064EDB4;

int fn_800A17C4(register State800A17C4* state)
{
    int result = 1;
    Context800A17C4* context;
    u32 resource;

    context = fn_8006ED98(state);
    if (context != 0) {
        resource = ((Info800A17C4*)fn_80201B8C(fn_80201814(state->resource)))->inner->resource;
        switch (context->mode) {
        case 34:
            if (context->counter <= 10) {
                result = 0;
                fn_8020104C(0x51, 0, resource, 0, lbl_8064EDB4);
            }
            break;
        case 22:
            if (context->counter <= 1) {
                result = 0;
                fn_8020104C(0x51, 0, resource, 0, lbl_8064EDB4);
            }
            break;
        case 23:
            if (context->counter <= 1) {
                result = 0;
            }
            break;
        }
    }
    return result;
}
