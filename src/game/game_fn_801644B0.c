typedef struct Parser {
    char padding_00[0x2C];
    void* allocator;
} Parser;

extern void* fn_801670F4(void*);
extern void fn_801641D4(Parser*, void*, int);

void fn_801644B0(Parser* parser, int unused, int count)
{
    fn_801641D4(parser, fn_801670F4(parser->allocator), count);
}
