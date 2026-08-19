typedef struct Parser {
    char padding_00[8];
    int token;
    char padding_0C[0x1C];
    void* state;
} Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern void fn_80163DA4(Parser*);
extern void fn_8015F4D0(Parser*, Entry*, int);
extern int fn_80164120(Parser*);
extern void fn_8015ECCC(Parser*, int);
extern void fn_801655CC(Parser*);
extern void fn_80163E94(Parser*, int);
extern void fn_8015F9B0(void*, int, int);
extern void fn_80164D04(Parser*, int);

void fn_80164DF4(Parser* parser, Entry* entry)
{
    int value;

    for (;;) {
        switch (parser->token) {
        case 0x2E:
            fn_80163DA4(parser);
            fn_8015F4D0(parser, entry, 1);
            fn_8015ECCC(parser, fn_80164120(parser));
            entry->type = 2;
            break;
        case 0x5B:
            fn_80163DA4(parser);
            fn_8015F4D0(parser, entry, 1);
            entry->type = 2;
            fn_801655CC(parser);
            fn_80163E94(parser, 0x5D);
            break;
        case 0x3A:
            fn_80163DA4(parser);
            value = fn_80164120(parser);
            fn_8015F4D0(parser, entry, 1);
            fn_8015F9B0(parser->state, 0x10, value);
            fn_80164D04(parser, 1);
            entry->type = 3;
            entry->value_08 = -1;
            entry->value_04 = -1;
            break;
        case 0x28:
        case 0x7B:
        case 0x11B:
            fn_8015F4D0(parser, entry, 1);
            fn_80164D04(parser, 0);
            entry->type = 3;
            entry->value_08 = -1;
            entry->value_04 = -1;
            break;
        default:
            return;
        }
    }
}
