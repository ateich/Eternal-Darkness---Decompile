typedef struct Parser {
    char padding_00[0x08];
    int token;
    char padding_0C[0x04];
    void* value;
    char padding_14[0x18];
    void* allocator;
} Parser;

extern char lbl_8024F9AC[];
extern char lbl_8064BB70;
extern char lbl_8064BB74;
extern void fn_80163E94(Parser*, int);
extern int fn_801640C4(Parser*);
extern void* fn_801670A8(void*, char*);
extern void fn_80163ED4(Parser*, int, char*);
extern void fn_80163DA4(Parser*);
extern void fn_801655CC(Parser*);
extern void fn_801644B0(Parser*, char*, int);
extern void fn_801641D4(Parser*, int, int);
extern void fn_80165C28(Parser*, int, int, int);

void fn_80165DC0(Parser* parser, int output)
{
    int valid;
    int expression;

    fn_80163E94(parser, 0x2C);
    expression = fn_801640C4(parser);
    valid = 0;
    if (parser->token == 0x113 &&
        parser->value == fn_801670A8(parser->allocator, &lbl_8064BB70)) {
        valid = 1;
    }
    fn_80163ED4(parser, valid, lbl_8024F9AC);
    fn_80163DA4(parser);
    fn_801655CC(parser);
    fn_801644B0(parser, &lbl_8064BB74, 0);
    fn_801641D4(parser, output, 1);
    fn_801641D4(parser, expression, 2);
    fn_80165C28(parser, 3, 0x2E, 0x2F);
}
