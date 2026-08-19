typedef struct State State;

typedef struct Parser {
    char padding_00[0x28];
    State* state;
} Parser;

typedef struct Entry Entry;

extern int fn_8015F9B0(State*, int, int);
extern int fn_8015EC10(State*);
extern void fn_80163E94(Parser*, int);
extern void fn_8016425C(Parser*, Entry*);
extern void fn_801658D0(Parser*);
extern void fn_8015F1F8(State*, int, int);
extern void fn_8016437C(Parser*, Entry*);

void fn_80165C28(Parser* parser, Entry* output, int left, int right)
{
    State* state = parser->state;
    int first = fn_8015F9B0(state, left, -1);
    int start = fn_8015EC10(state);

    fn_80163E94(parser, 0x103);
    fn_8016425C(parser, output);
    fn_801658D0(parser);
    fn_8015F1F8(state, fn_8015F9B0(state, right, -1), start);
    fn_8015F1F8(state, first, fn_8015EC10(state));
    fn_8016437C(parser, output);
}
