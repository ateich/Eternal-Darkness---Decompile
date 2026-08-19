typedef struct Parser {
    char padding_00[0x08];
    int token;
} Parser;

extern void fn_80163DA4(Parser*);
extern int fn_801640C4(Parser*);
extern void fn_801641D4(Parser*, int, int);
extern int fn_80163F00(Parser*, int);
extern int fn_80164C7C(Parser*);
extern void fn_80164778(Parser*, int, int);
extern void fn_8016425C(Parser*, int);

void fn_801660EC(Parser* parser)
{
    int count = 0;
    int value;

    do {
        fn_80163DA4(parser);
        fn_801641D4(parser, fn_801640C4(parser), count++);
    } while (parser->token == 0x2C);
    if (fn_80163F00(parser, 0x3D)) {
        value = fn_80164C7C(parser);
    } else {
        value = 0;
    }
    fn_80164778(parser, count, value);
    fn_8016425C(parser, count);
}
