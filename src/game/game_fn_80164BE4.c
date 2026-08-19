typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[0x34];
} Parser;

typedef struct ParserState {
    void* object;
    char padding_04[0x4CC];
} ParserState;

typedef struct Input {
    char padding_00[0x10];
    void* source;
} Input;

extern char lbl_8024F8BC[];
extern void* fn_801670A8(Parser*, void*);
extern void fn_801622BC(Parser*, Parser*, Input*, void*);
extern void fn_801649CC(Parser*, ParserState*);
extern void fn_80163DA4(Parser*);
extern void fn_80166750(Parser*);
extern void fn_80163ED4(Parser*, int, char*);
extern void fn_80164A64(Parser*);

void* fn_80164BE4(Parser* parser, Input* input)
{
    Parser local;
    ParserState state;
    fn_801622BC(parser, &local, input, fn_801670A8(parser, input->source));
    fn_801649CC(&local, &state);
    fn_80163DA4(&local);
    fn_80166750(&local);
    fn_80163ED4(&local, local.token == 0x11C, lbl_8024F8BC);
    fn_80164A64(&local);
    return state.object;
}
