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
extern void fn_80163A9C(Buffer*, unsigned int);
extern int fn_80163B14(char*, void*);
extern char lbl_8024F66C[];
extern char lbl_8024F6A4[];

void fn_801624A8(Parser* parser, int leading_point, void* result)
{
    unsigned int index = 0;
    Buffer* buffer = parser->buffer;
    int token;

    if (buffer->capacity < 10) {
        fn_80163A9C(buffer, 0x8A);
    }

    if (leading_point != 0) {
        buffer->data[0] = '.';
        index = 1;
    }

    while (fn_800F8D2C(parser->current_token)) {
        if (index + 10 > buffer->capacity) {
            fn_80163A9C(buffer, index + 0x8A);
        }
        buffer->data[index++] = parser->current_token;
        if (parser->input->remaining-- != 0) {
            token = *parser->input->current++;
        } else {
            token = parser->input->read(parser->input);
        }
        parser->current_token = token;
    }

    if (parser->current_token == '.') {
        buffer->data[index++] = parser->current_token;
        if (parser->input->remaining-- != 0) {
            token = *parser->input->current++;
        } else {
            token = parser->input->read(parser->input);
        }
        parser->current_token = token;

        if (parser->current_token == '.') {
            buffer->data[index++] = parser->current_token;
            if (parser->input->remaining-- != 0) {
                token = *parser->input->current++;
            } else {
                token = parser->input->read(parser->input);
            }
            parser->current_token = token;
            buffer->data[index++] = 0;
            fn_80162114(parser, lbl_8024F66C, 0x11A);
        }
    }

    while (fn_800F8D2C(parser->current_token)) {
        if (index + 10 > buffer->capacity) {
            fn_80163A9C(buffer, index + 0x8A);
        }
        buffer->data[index++] = parser->current_token;
        if (parser->input->remaining-- != 0) {
            token = *parser->input->current++;
        } else {
            token = parser->input->read(parser->input);
        }
        parser->current_token = token;
    }

    if (parser->current_token == 'e' || parser->current_token == 'E') {
        buffer->data[index++] = parser->current_token;
        if (parser->input->remaining-- != 0) {
            token = *parser->input->current++;
        } else {
            token = parser->input->read(parser->input);
        }
        parser->current_token = token;

        if (parser->current_token == '+' || parser->current_token == '-') {
            buffer->data[index++] = parser->current_token;
            if (parser->input->remaining-- != 0) {
                token = *parser->input->current++;
            } else {
                token = parser->input->read(parser->input);
            }
            parser->current_token = token;
        }

        while (fn_800F8D2C(parser->current_token)) {
            if (index + 10 > buffer->capacity) {
                fn_80163A9C(buffer, index + 0x8A);
            }
            buffer->data[index++] = parser->current_token;
            if (parser->input->remaining-- != 0) {
                token = *parser->input->current++;
            } else {
                token = parser->input->read(parser->input);
            }
            parser->current_token = token;
        }
    }

    buffer->data[index] = 0;
    if (fn_80163B14(buffer->data, result) == 0) {
        fn_80162114(parser, lbl_8024F6A4, 0x11A);
    }
}
