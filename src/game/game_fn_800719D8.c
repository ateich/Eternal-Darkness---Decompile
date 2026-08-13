typedef short s16;

/*
 * NonMatching: the recovered state layout and call semantics are honest, but
 * MWCC keeps the integer literals in r5-r8 and schedules the two float loads
 * differently in retail. Current objdiff: 57.96875%, 128 target / 144 base.
 */

typedef struct State {
    float x;
    float y;
    float z;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
} State;

typedef struct Owner {
    char pad_00[0xAC0];
    s16 value;
} Owner;

typedef struct Global {
    char pad_00[8];
    Owner *owner;
} Global;

extern float lbl_8064E850;
extern float lbl_8064E7E8;
extern State lbl_80312FD8;
extern Global lbl_80606328;
extern void fn_8015AA58(State *, Owner *, int, int, int, int);

void fn_800719D8(void)
{
    State *state = &lbl_80312FD8;

    state->x = lbl_8064E850;
    state->y = lbl_8064E7E8;
    state->z = lbl_8064E7E8;
    state->a = 200;
    state->b = 250;
    state->c = 1;
    state->d = 2;
    state->e = 2;
    state->f = 0;
    state->g = lbl_80606328.owner->value;
    state->h = 2;
    state->i = 1;
    fn_8015AA58(state, lbl_80606328.owner, state->d, state->c, state->b,
                state->a);
}
