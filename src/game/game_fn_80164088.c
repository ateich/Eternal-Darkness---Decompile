typedef struct Parser {
    char padding_00[0x28];
    void* table;
} Parser;

extern int fn_80163FE4(void*, void*);
extern void fn_8015ECCC(Parser*, int);

void fn_80164088(Parser* parser, void* entry)
{
    fn_8015ECCC(parser, fn_80163FE4(parser->table, entry));
}
