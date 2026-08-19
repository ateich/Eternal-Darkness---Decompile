typedef struct Parser {
    char padding_00[0x28];
    void* table;
} Parser;

extern void* fn_801640C4(Parser*);
extern int fn_80163FE4(void*, void*);

void fn_80164120(Parser* parser)
{
    fn_80163FE4(parser->table, fn_801640C4(parser));
}
