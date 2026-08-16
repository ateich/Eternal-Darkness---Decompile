typedef struct State {
    unsigned char pad_000[0xea];
    short field_0ea;
    short field_0ec;
    unsigned char pad_0ee[0x18];
    short field_106;
} State;

typedef struct Object {
    unsigned char pad_000[0x8c];
    State *state;
} Object;

extern int fn_800D4310(int);
extern void fn_800A4AC4(void *, int, int, int);

void fn_800D6588(void *actor, Object *object)
{
    State *state = object->state;

    if (state->field_0ec == 0) {
        int value = fn_800D4310(1);
        fn_800A4AC4(actor, 1, value, 0);
    }
    if (state->field_0ea == 0) {
        fn_800A4AC4(actor, 0, fn_800D4310(0), 0);
    }
    if (state->field_106 == 0) {
        fn_800A4AC4(actor, 14, fn_800D4310(14), 0);
    }
}
