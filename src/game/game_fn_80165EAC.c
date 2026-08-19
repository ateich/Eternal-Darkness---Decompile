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

extern char lbl_8024F9BC[];
extern void fn_80164898(State*, Entry*);
extern void fn_80163DA4(Parser*);
extern int fn_801640C4(Parser*);
extern void fn_80165CE8(Parser*, int);
extern void fn_80165DC0(Parser*, int);
extern void fn_8015EA7C(Parser*, char*);
extern void fn_80163F38(Parser*, int, int, Entry*);
extern void fn_801648B8(State*, Entry*);

void fn_80165EAC(Parser* parser, Entry* output)
{
    State* state = parser->state;
    Entry saved;
    int expression;

    fn_80164898(state, &saved);
    fn_80163DA4(parser);
    expression = fn_801640C4(parser);
    switch (parser->token) {
    case 0x3D:
        fn_80165CE8(parser, expression);
        break;
    case 0x2C:
        fn_80165DC0(parser, expression);
        break;
    default:
        fn_8015EA7C(parser, lbl_8024F9BC);
        break;
    }
    fn_80163F38(parser, 0x106, 0x107, output);
    fn_801648B8(state, &saved);
}
