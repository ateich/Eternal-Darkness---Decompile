typedef struct State State;

typedef struct Parser {
    char padding_00[0x28];
    State* state;
} Parser;

typedef struct Entry Entry;

extern int fn_80165870(Parser*, Entry*);
extern void fn_8015F414(State*, Entry*, int);

void fn_80165A54(Parser* parser, Entry* entry)
{
    fn_80165870(parser, entry);
    fn_8015F414(parser->state, entry, 0);
}
