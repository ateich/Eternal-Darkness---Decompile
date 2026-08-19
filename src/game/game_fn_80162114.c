typedef struct ValueSet {
    char pad00[0x18];
    char* value;
} ValueSet;

typedef struct Parser {
    char pad00[0x2C];
    ValueSet* values;
} Parser;

extern void fn_80162188(char*, signed char*);
extern void fn_8016209C(Parser*, int, char*);

void fn_80162114(Parser* parser, int token, char* source)
{
    signed char value[8];

    fn_80162188(source, value);
    if (value[0] == 0) {
        fn_8016209C(parser, token, parser->values->value);
    } else {
        fn_8016209C(parser, token, (char*)value);
    }
}
