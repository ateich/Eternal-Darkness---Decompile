typedef struct Parser {
    char padding_00[8];
    int token;
} Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern signed char lbl_8023A890[];
extern void fn_8015F694(Parser*, int, Entry*);
extern void fn_8015F768(Parser*, int, Entry*);
extern void fn_8015F7D4(Parser*, int, Entry*, Entry*);
extern void fn_80163DA4(Parser*);
extern void fn_80165464(Parser*, Entry*);
extern int fn_8016560C(int);
extern int fn_8016563C(int);

int fn_8016576C(Parser* parser, Entry* entry, int precedence)
{
    int operator_kind;
    signed char* operator_info;
    int value_kind = fn_8016560C(parser->token);

    if (value_kind != 2) {
        fn_80163DA4(parser);
        fn_8016576C(parser, entry, 7);
        fn_8015F694(parser, value_kind, entry);
    } else {
        fn_80165464(parser, entry);
    }

    operator_kind = fn_8016563C(parser->token);
    while (operator_kind != 14 &&
           lbl_8023A890[operator_kind * 2] > precedence) {
        fn_80163DA4(parser);
        fn_8015F768(parser, operator_kind, entry);
        operator_info = &lbl_8023A890[operator_kind * 2];
        {
            Entry right;
            int next_kind = fn_8016576C(parser, &right, operator_info[1]);
            fn_8015F7D4(parser, operator_kind, entry, &right);
            operator_kind = next_kind;
        }
    }
    return operator_kind;
}
