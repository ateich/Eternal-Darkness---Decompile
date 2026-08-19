typedef struct ValueTable {
    char padding_00[0x20];
    short depth;
    short flag;
} ValueTable;

typedef struct ParserState {
    ValueTable* table;
    char padding_04[0x1A];
    short depth;
} ParserState;

typedef struct Parser {
    char padding_00[0x28];
    ParserState* state;
} Parser;

extern char lbl_8024F8A4[];
extern char lbl_8064BB5C;
extern void fn_8016425C(Parser*, int);
extern void fn_8016203C(Parser*, int, int, char*);
extern void fn_801644B0(Parser*, char*, int);
extern void fn_8015EC60(ParserState*, int);

void fn_801647F8(Parser* parser, int count, int flag)
{
    ParserState* state = parser->state;

    fn_8016425C(parser, count);
    fn_8016203C(parser, state->depth, 100, lbl_8024F8A4);
    state->table->depth = state->depth;
    state->table->flag = flag;
    if (flag != 0) {
        fn_801644B0(parser, &lbl_8064BB5C, 0);
        fn_8016425C(parser, 1);
    }
    fn_8015EC60(state, state->depth);
}
