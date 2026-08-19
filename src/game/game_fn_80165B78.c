typedef struct State State;

typedef struct Parser {
    char padding_00[0x28];
    State* state;
} Parser;

typedef struct Entry {
    int type;
    int value;
    int extra;
} Entry;

extern int fn_8015EC10(State*);
extern void fn_80164898(State*, Entry*);
extern void fn_80163DA4(Parser*);
extern void fn_801658D0(Parser*);
extern void fn_80163F38(Parser*, int, int, Entry*);
extern void fn_80165A54(Parser*, Entry*);
extern void fn_8015F1F8(State*, int, int);
extern void fn_801648B8(State*, Entry*);

void fn_80165B78(Parser* parser, Entry* output)
{
    State* state = parser->state;
    int start = fn_8015EC10(state);
    Entry value;
    Entry saved;

    fn_80164898(state, &saved);
    fn_80163DA4(parser);
    fn_801658D0(parser);
    fn_80163F38(parser, 0x111, 0x10E, output);
    fn_80165A54(parser, &value);
    fn_8015F1F8(state, value.extra, start);
    fn_801648B8(state, &saved);
}
