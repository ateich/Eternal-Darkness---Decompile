typedef struct Parser {
    char pad0[8];
    int token;
} Parser;

extern int fn_80166440(Parser*);
extern int fn_80163F00(Parser*, int);
extern int fn_80165894(int);

void fn_80166750(Parser* parser)
{
    int result = 0;

    while (!result && !fn_80165894(parser->token)) {
        result = fn_80166440(parser);
        fn_80163F00(parser, 0x3B);
    }
}
