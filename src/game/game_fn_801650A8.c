typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[0x1C];
    void* output;
} Parser;

extern void fn_80165010(Parser*);
extern void fn_80163DA4(Parser*);
extern void fn_8015F9B0(void*, int, int);

int fn_801650A8(Parser* parser)
{
    int count = 1;
    void* output = parser->output;

    fn_80165010(parser);
    while (parser->token == 0x2C) {
        fn_80163DA4(parser);
        if (parser->token == 0x3B || parser->token == 0x7D) {
            break;
        }
        fn_80165010(parser);
        count++;
        if (count % 31 == 0) {
            fn_8015F9B0(output, 0x16, 31);
        }
    }
    fn_8015F9B0(output, 0x16, count % 31);
    return count;
}
