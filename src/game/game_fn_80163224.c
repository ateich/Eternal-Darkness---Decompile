#pragma use_lmw_stmw on

typedef struct Input Input;
typedef int (*ReadFn)(Input*);

struct Input {
    unsigned int remaining;
    unsigned char* current;
    ReadFn read;
};

typedef struct Buffer {
    char pad00[0x18];
    char* data;
    unsigned int capacity;
} Buffer;

typedef struct Parser {
    int current_token;
    char pad04[0x28];
    Buffer* buffer;
    Input* input;
} Parser;

typedef struct StringEntry {
    char pad00[0x10];
    int token;
} StringEntry;

extern int fn_800F8D2C(int);
extern int fn_800F8D44(int);
extern int fn_800F8D5C(int);
extern void fn_80162114(Parser*, char*, int);
extern void fn_801621D8(Parser*, int);
extern void fn_80162228(Parser*);
extern char* fn_801623B4(Parser*);
extern void fn_801624A8(Parser*, int, void**);
extern void fn_80162874(Parser*, void**);
extern void fn_80162BEC(Parser*, int, void**);
extern StringEntry* fn_801670A8(void*, char*);
extern char lbl_8024F700[];

#define NEXT_TOKEN() do {                                                     \
    int token;                                                               \
    if (parser->input->remaining-- != 0) {                                   \
        token = *parser->input->current++;                                   \
    } else {                                                                 \
        token = parser->input->read(parser->input);                           \
    }                                                                        \
    parser->current_token = token;                                            \
} while (0)

int fn_80163224(Parser* parser, void** result)
{
    StringEntry* entry;

    for (;;) {
        switch (parser->current_token) {
        case '\t':
        case '\r':
        case ' ':
            NEXT_TOKEN();
            continue;

        case '\n':
            fn_80162228(parser);
            continue;

        case '$':
            fn_80162114(parser, lbl_8024F700, '$');
            continue;

        case '-':
            NEXT_TOKEN();
            if (parser->current_token != '-') {
                return '-';
            }
            do {
                NEXT_TOKEN();
            } while (parser->current_token != '\n' && parser->current_token != -1);
            continue;

        case '[':
            NEXT_TOKEN();
            if (parser->current_token != '[') {
                return '[';
            }
            fn_80162874(parser, result);
            return 0x11B;

        case '=':
            NEXT_TOKEN();
            if (parser->current_token != '=') {
                return '=';
            }
            NEXT_TOKEN();
            return 0x116;

        case '<':
            NEXT_TOKEN();
            if (parser->current_token != '=') {
                return '<';
            }
            NEXT_TOKEN();
            return 0x118;

        case '>':
            NEXT_TOKEN();
            if (parser->current_token != '=') {
                return '>';
            }
            NEXT_TOKEN();
            return 0x117;

        case '~':
            NEXT_TOKEN();
            if (parser->current_token != '=') {
                return '~';
            }
            NEXT_TOKEN();
            return 0x119;

        case '"':
        case '\'':
            fn_80162BEC(parser, parser->current_token, result);
            return 0x11B;

        case '.':
            NEXT_TOKEN();
            if (parser->current_token == '.') {
                NEXT_TOKEN();
                if (parser->current_token == '.') {
                    NEXT_TOKEN();
                    return 0x115;
                }
                return 0x114;
            }
            if (!fn_800F8D2C(parser->current_token)) {
                return '.';
            }
            fn_801624A8(parser, 1, result);
            return 0x11A;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            fn_801624A8(parser, 0, result);
            return 0x11A;

        case -1:
            return 0x11C;

        case '_':
            goto identifier;

        default:
            if (fn_800F8D5C(parser->current_token)) {
                goto identifier;
            } else {
                int c = parser->current_token;
                if (fn_800F8D44(c)) {
                    fn_801621D8(parser, c);
                }
                NEXT_TOKEN();
                return c;
            }
        }
    }

identifier:
    entry = fn_801670A8(parser->buffer, fn_801623B4(parser));
    if (entry->token >= 3) {
        return entry->token + 0xFE;
    }
    *result = entry;
    return 0x113;
}
