typedef struct Parser {
    char pad00[0x2C];
    void* output;
    char pad30[4];
    int position;
    char pad38[4];
    char* source;
} Parser;

extern char lbl_8024F608[];
extern void fn_80163C5C(char*, char*, int);
extern void fn_80163BB4(void*, const char*, ...);

void fn_8016209C(Parser* parser, int token, char* value)
{
    char context[80];

    fn_80163C5C(context, parser->source + 0x14, sizeof(context));
    fn_80163BB4(parser->output, lbl_8024F608, token, value,
                parser->position, context);
}
