typedef struct State {
    char pad0[0x1C];
    short previous;
    short current;
} State;

typedef struct Parser {
    char pad0[8];
    void* token;
    char padC[0x1C];
    State* state;
} Parser;

extern void fn_80163DA4(Parser*);
extern int fn_80165894(void*);
extern int fn_80164C7C(Parser*);
extern void fn_8015F9B0(State*, int, int);

void fn_80166334(Parser* parser)
{
    State* state = parser->state;

    fn_80163DA4(parser);
    if (!fn_80165894(parser->token)) {
        fn_80164C7C(parser);
    }
    fn_8015F9B0(state, 1, parser->state->current);
    state->previous = state->current;
}
