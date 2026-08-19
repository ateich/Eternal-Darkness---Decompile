typedef struct Parser {
    char padding_00[8];
    int token;
} Parser;

typedef struct Entry {
    int values[3];
} Entry;

extern void fn_80165870(Parser*, Entry*);
extern void fn_8015F4D0(Parser*, Entry*, int);
extern void fn_80163DA4(Parser*);

int fn_80164C7C(Parser* parser)
{
    Entry entry;
    int count = 1;

    fn_80165870(parser, &entry);
    while (parser->token == 0x2C) {
        fn_8015F4D0(parser, &entry, 1);
        fn_80163DA4(parser);
        fn_80165870(parser, &entry);
        count++;
    }
    fn_8015F4D0(parser, &entry, 0);
    return count;
}
