typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800A7860 {
    u8 pad0[0x9F];
    u8 kind;
} State800A7860;

extern void* fn_80201814();
extern State800A7860* fn_80201B8C();

u32 fn_800A7860(void* object)
{
    u32 result = 0x40000;
    State800A7860* state = fn_80201814(object);

    if (state != 0) {
        state = fn_80201B8C(state);
        if (state != 0) {
            switch (state->kind) {
            case 6:
                result = 0x10000;
                break;
            case 3:
                result = 0x20000;
                break;
            case 4:
                result = 0x40000;
                break;
            }
        }
    }
    return result;
}
