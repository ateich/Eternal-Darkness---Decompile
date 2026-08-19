typedef struct ParserState {
    char padding_00[0x1C];
    short value_1C;
} ParserState;

typedef struct Parser {
    char padding_00[8];
    int token;
    int value_0C;
    int value_10;
    char padding_14[0x14];
    ParserState* state;
    char padding_2C[8];
    int line;
} Parser;

extern char lbl_8024F8CC[];
extern void fn_80163DA4(Parser*);
extern int fn_80164C7C(Parser*);
extern void fn_80163F38(Parser*, int, int, int);
extern void fn_8016536C(Parser*);
extern void fn_80164088(Parser*, int);
extern void fn_8015EA7C(Parser*, char*);
extern void fn_8015F9D4(ParserState*, int, int, int);

void fn_80164D04(Parser* parser, int count)
{
    ParserState* state = parser->state;
    int new_count = state->value_1C - count - 1;
    int line;

    switch (parser->token) {
    case 0x28:
        line = parser->line;
        fn_80163DA4(parser);
        if (parser->token != 0x29) {
            fn_80164C7C(parser);
        }
        fn_80163F38(parser, 0x29, 0x28, line);
        break;
    case 0x7B:
        fn_8016536C(parser);
        break;
    case 0x11B:
        fn_80164088(parser, parser->value_10);
        fn_80163DA4(parser);
        break;
    default:
        fn_8015EA7C(parser, lbl_8024F8CC);
        break;
    }

    state->value_1C = new_count;
    fn_8015F9D4(state, 2, new_count, 0xFF);
}
