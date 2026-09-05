typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct State {
    u8 pad[0x121];
    u8 channel;
    u8 layer;
} State;

extern u32 fn_801CC13C(u32);
extern void fn_801CAD90(u32, u8, u8, s16);

void fn_801CC24C(State* state, u32 control, s16 value)
{
    value = value < 0 ? 0 : value > 0x3FFF ? 0x3FFF : value;

    switch ((u8)fn_801CC13C(control)) {
    default:
        if (state->channel != 0xFF) {
            fn_801CAD90(control, state->channel, state->layer, value);
        }
        break;
    case 0xA0:
    case 0xA1:
        break;
    }
}
