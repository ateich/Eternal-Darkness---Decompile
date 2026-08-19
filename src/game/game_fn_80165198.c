typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[0x1C];
    void* output;
} Parser;

extern char lbl_8024F900[];
extern void fn_801655CC(Parser*);
extern void fn_80163DA4(Parser*);
extern void fn_8016203C(Parser*, int, int, char*);
extern void fn_8015F9D4(void*, int, int, int);

int fn_80165198(Parser* parser)
{
    void* output = parser->output;
    int count = 1;

    fn_801655CC(parser);
    while (parser->token == 0x2C) {
        int page;

        fn_80163DA4(parser);
        if (parser->token == 0x3B || parser->token == 0x7D) {
            break;
        }
        fn_801655CC(parser);
        count++;
        page = count / 62;
        fn_8016203C(parser, page, 0x1FFFF, lbl_8024F900);
        if (count % 62 == 0) {
            fn_8015F9D4(output, 0x15, page - 1, 62);
        }
    }
    fn_8015F9D4(output, 0x15, count / 62, count % 62);
    return count;
}
