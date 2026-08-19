typedef struct Parser {
    char padding_00[0x08];
    int token;
} Parser;

extern int fn_801640C4(Parser*);
extern void fn_8016457C(Parser*, int, int*);
extern void fn_80163DA4(Parser*);
extern void fn_8015F4D0(Parser*, int*, int);
extern int fn_80164120(Parser*);
extern void fn_8015ECCC(Parser*, int);

int fn_80166190(Parser* parser, int* output)
{
    int special = 0;

    fn_8016457C(parser, fn_801640C4(parser), output);
    if (parser->token == 0x3A || parser->token == 0x2E) {
        special = parser->token == 0x3A;
        fn_80163DA4(parser);
        fn_8015F4D0(parser, output, 1);
        fn_8015ECCC(parser, fn_80164120(parser));
        *output = 2;
    }
    return special;
}
