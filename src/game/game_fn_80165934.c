typedef struct State State;

typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[0x1C];
    State* state;
} Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern char lbl_8024F978[];
extern char lbl_8024F99C[];
extern void fn_8016203C(Parser*, int, int, char*);
extern void fn_80163DA4(Parser*);
extern void fn_80164F7C(Parser*, Entry*);
extern void fn_80163ED4(Parser*, int, char*);
extern void fn_80163E94(Parser*, int);
extern int fn_80164C7C(Parser*);
extern void fn_80164778(Parser*, int, int);
extern void fn_8015F048(Parser*, Entry*);
extern int fn_8015F9D4(State*, int, int, int);

int fn_80165934(Parser* parser, Entry* entry, int count)
{
    int left = 0;

    fn_8016203C(parser, count, 254, lbl_8024F978);
    if (parser->token == ',') {
        Entry next;
        fn_80163DA4(parser);
        fn_80164F7C(parser, &next);
        fn_80163ED4(parser, next.type != 3, lbl_8024F99C);
        left = fn_80165934(parser, &next, count + 1);
    } else {
        int expressions;
        fn_80163E94(parser, '=');
        expressions = fn_80164C7C(parser);
        fn_80164778(parser, count, expressions);
    }

    if (entry->type != 2) {
        fn_8015F048(parser, entry);
    } else {
        fn_8015F9D4(parser->state, 20, left + count + 2, 1);
        left += 2;
    }
    return left;
}
