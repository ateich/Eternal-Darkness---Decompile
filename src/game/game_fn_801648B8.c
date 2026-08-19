typedef struct Frame {
    void* parent;
    int value;
    int index;
} Frame;

typedef struct Parser {
    char padding_00[0x28];
    void* state;
} Parser;

extern int fn_8015EC10(Parser*);
extern void fn_8015F1F8(Parser*, int, int);

void fn_801648B8(Parser* parser, Frame* frame)
{
    parser->state = frame->parent;
    fn_8015F1F8(parser, frame->value, fn_8015EC10(parser));
}
