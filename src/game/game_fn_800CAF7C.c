typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x9E];
    u8 kind;
    u8 subtype;
} RuntimeState;

extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern int fn_80066D04(void *, int);

int fn_800CAF7C(void *object)
{
    int result = 0;
    RuntimeState *state;

    if (object != 0 && (state = ((RuntimeState *)fn_80201B8C(object))) != 0 &&
        fn_80201BC8(object) != 0) {
        if (state->kind == 2 && state->subtype == 4) {
            int value = fn_80066D04(object, 8);
            result = fn_80066D04(object, 0);
            return result + value + fn_80066D04(object, 9);
        } else if (state->kind == 2 && state->subtype == 6) {
            result = 0;
        } else if (state->kind == 2 &&
                   (state->subtype == 12 || state->subtype == 13)) {
            result = 1;
        } else if (state->kind == 2 && state->subtype == 13) {
            result = 1;
        } else {
            return fn_80066D04(object, 0);
        }
    }
    return result;
}
