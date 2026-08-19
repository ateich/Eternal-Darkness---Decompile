typedef struct Buffer {
    char padding_00[0x1E];
    short position;
} Buffer;

typedef struct Parser {
    char padding_00[0x28];
    Buffer* buffer;
} Parser;

extern void fn_80166750(Parser*);
extern void fn_8015EE54(Buffer*, int);
extern void fn_8016437C(Parser*, int);

void fn_801658D0(Parser* parser)
{
    Buffer* buffer = parser->buffer;
    short start = buffer->position;

    fn_80166750(parser);
    fn_8015EE54(buffer, buffer->position - start);
    fn_8016437C(parser, buffer->position - start);
}
