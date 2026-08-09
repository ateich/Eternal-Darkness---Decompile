typedef short s16;
typedef int s32;

typedef struct State {
    unsigned char pad_00[0x152];
    s16 kind152;
} State;

typedef struct Object {
    unsigned char pad_00[0x8C];
    State* state8C;
} Object;

s32 fn_80035958(Object* object)
{
    register State* state = object->state8C;
    register s32 result = 0;

    switch (state->kind152) {
    case 21:
        result = 1;
        break;
    case 59:
        result = 2;
        break;
    case 60:
        result = 3;
        break;
    }
    return result;
}
