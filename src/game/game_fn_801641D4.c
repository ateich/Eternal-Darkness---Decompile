typedef struct ParserState {
    char padding_00[0x1E];
    short depth;
    char padding_20[0x18C];
    int slots[1];
} ParserState;

typedef struct Parser {
    char padding_00[0x28];
    ParserState* state;
} Parser;

extern char lbl_8024F804[];
extern void fn_8016203C(Parser*, int, int, char*);
extern int fn_80164158(Parser*, void*);

void fn_801641D4(Parser* parser, void* value, int count)
{
    ParserState* state = parser->state;

    fn_8016203C(parser, state->depth + count + 1, 200, lbl_8024F804);
    state->slots[state->depth + count] = fn_80164158(parser, value);
}
