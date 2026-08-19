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

extern int fn_800F8D2C(int);
extern void fn_80162114(Parser*, char*, int);
extern void fn_80162228(Parser*);
extern void fn_80163A9C(Buffer*, unsigned int);
extern char* fn_80166E3C(Buffer*, char*, unsigned int);
extern char lbl_8024F6D0[];
extern char lbl_8024F6E4[];

#define NEXT_TOKEN() do {                                                     \
    if (parser->input->remaining-- != 0) {                                    \
        token = *parser->input->current++;                                    \
    } else {                                                                  \
        token = parser->input->read(parser->input);                            \
    }                                                                         \
    parser->current_token = token;                                             \
} while (0)

#define SAVE_AND_NEXT(value) do {                                              \
    buffer->data[index++] = (value);                                           \
    NEXT_TOKEN();                                                              \
} while (0)

void fn_80162BEC(Parser* parser, int delimiter, char** result)
{
    Buffer* buffer = parser->buffer;
    unsigned int index;
    int value;
    int count;
    int token;

    if (buffer->capacity < 10) {
        fn_80163A9C(buffer, 0x8A);
    }

    index = 1;
    buffer->data[0] = parser->current_token;
    NEXT_TOKEN();

    while (parser->current_token != delimiter) {
        if (index + 10 > buffer->capacity) {
            fn_80163A9C(buffer, index + 0x8A);
        }

        switch (parser->current_token) {
        case -1:
        case '\n':
            buffer->data[index++] = 0;
            fn_80162114(parser, lbl_8024F6D0, 0x11B);
            break;

        case '\\':
            NEXT_TOKEN();
            switch (parser->current_token) {
            case 'a':
                SAVE_AND_NEXT('\a');
                break;
            case 'b':
                SAVE_AND_NEXT('\b');
                break;
            case 'f':
                SAVE_AND_NEXT('\f');
                break;
            case 'n':
                SAVE_AND_NEXT('\n');
                break;
            case 'r':
                SAVE_AND_NEXT('\r');
                break;
            case 't':
                SAVE_AND_NEXT('\t');
                break;
            case 'v':
                SAVE_AND_NEXT('\v');
                break;
            case '\n':
                buffer->data[index++] = '\n';
                fn_80162228(parser);
                break;
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
                value = 0;
                count = 0;
                do {
                    value = value * 10 + parser->current_token;
                    value -= '0';
                    NEXT_TOKEN();
                    count++;
                } while (count < 3 && fn_800F8D2C(parser->current_token));
                if (value != (unsigned char)value) {
                    buffer->data[index++] = 0;
                    fn_80162114(parser, lbl_8024F6E4, 0x11B);
                }
                buffer->data[index++] = value;
                break;
            default:
                SAVE_AND_NEXT(parser->current_token);
                break;
            }
            break;

        default:
            SAVE_AND_NEXT(parser->current_token);
            break;
        }
    }

    SAVE_AND_NEXT(parser->current_token);
    buffer->data[index] = 0;
    *result = fn_80166E3C(buffer, buffer->data + 1, index - 2);
}
