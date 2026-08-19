typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[4];
    double number;
    char padding_18[0x10];
    void* output;
    char padding_2C[8];
    void* context;
} Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern char lbl_8024F960[];
extern void fn_8015EA7C(Parser*, char*);
extern void fn_8015EDC0(void*, double);
extern void fn_8015EE54(void*, int);
extern void fn_80163DA4(Parser*);
extern void fn_80163E94(Parser*, int);
extern void fn_80164088(Parser*, int);
extern void fn_8016536C(Parser*);
extern void fn_80164F7C(Parser*, Entry*);
extern void fn_80165870(Parser*, Entry*);
extern void fn_8016668C(Parser*, int, void*);

void fn_80165464(Parser* parser, Entry* entry)
{
    void* output = parser->output;

    switch (parser->token) {
    case 0x11A:
        {
            double number = parser->number;
            fn_80163DA4(parser);
            fn_8015EDC0(output, number);
        }
        break;
    case 0x11B:
        fn_80164088(parser, *(int*)&parser->number);
        fn_80163DA4(parser);
        break;
    case 0x10B:
        fn_8015EE54(output, -1);
        fn_80163DA4(parser);
        break;
    case 0x7B:
        fn_8016536C(parser);
        break;
    case 0x108:
        fn_80163DA4(parser);
        fn_8016668C(parser, 0, parser->context);
        break;
    case 0x28:
        fn_80163DA4(parser);
        fn_80165870(parser, entry);
        fn_80163E94(parser, 0x29);
        return;
    case 0x25:
    case 0x113:
        fn_80164F7C(parser, entry);
        return;
    default:
        fn_8015EA7C(parser, lbl_8024F960);
        return;
    }

    entry->type = 3;
    entry->value_08 = -1;
    entry->value_04 = -1;
}
