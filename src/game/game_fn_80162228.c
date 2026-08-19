typedef struct Input Input;
typedef int (*ReadFn)(Input*);

struct Input {
    unsigned int remaining;
    unsigned char* current;
    ReadFn read;
};

typedef struct Parser {
    int current_token;
    char pad04[0x2C];
    Input* input;
    int position;
} Parser;

extern char lbl_8024F658[];
extern void fn_8016203C(Parser*, int, int, char*);

void fn_80162228(Parser* parser)
{
    int token;

    if (parser->input->remaining-- != 0) {
        token = *parser->input->current++;
    } else {
        token = parser->input->read(parser->input);
    }
    parser->current_token = token;
    parser->position++;
    fn_8016203C(parser, parser->position, 0x7FFFFFFD, lbl_8024F658);
}
