typedef struct Parser Parser;

extern void fn_80163DA4(Parser*);
extern int fn_80166190(Parser*, int*);
extern void fn_8016668C(Parser*, int, int);
extern void fn_8015F048(Parser*, int*);

void fn_8016623C(Parser* parser, int value)
{
    int output;
    int special;

    fn_80163DA4(parser);
    special = fn_80166190(parser, &output);
    fn_8016668C(parser, special, value);
    fn_8015F048(parser, &output);
}
