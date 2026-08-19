typedef struct State State;

typedef struct Parser {
    char padding_00[0x08];
    int token;
    char padding_0C[0x1C];
    State* state;
} Parser;

typedef struct Entry {
    int type;
    int value;
    int extra;
} Entry;

extern void fn_80165F70(Parser*, Entry*);
extern int fn_8015EAD0(State*);
extern void fn_8015F2B0(State*, int*, int);
extern int fn_8015EC10(State*);
extern void fn_8015F1F8(State*, int, int);
extern void fn_80163DA4(Parser*);
extern void fn_801658D0(Parser*);
extern void fn_80163F38(Parser*, int, int, Entry*);

void fn_80165FC8(Parser* parser, Entry* output)
{
    State* state = parser->state;
    int start = -1;
    Entry entry;

    fn_80165F70(parser, &entry);
    while (parser->token == 0x105) {
        fn_8015F2B0(state, &start, fn_8015EAD0(state));
        fn_8015F1F8(state, entry.extra, fn_8015EC10(state));
        fn_80165F70(parser, &entry);
    }
    if (parser->token == 0x104) {
        fn_8015F2B0(state, &start, fn_8015EAD0(state));
        fn_8015F1F8(state, entry.extra, fn_8015EC10(state));
        fn_80163DA4(parser);
        fn_801658D0(parser);
    } else {
        fn_8015F2B0(state, &start, entry.extra);
    }
    fn_8015F1F8(state, start, fn_8015EC10(state));
    fn_80163F38(parser, 0x106, 0x109, output);
}
