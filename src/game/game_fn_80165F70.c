typedef struct Parser Parser;
typedef struct Entry Entry;

extern void fn_80163DA4(Parser*);
extern void fn_80165A54(Parser*, Entry*);
extern void fn_80163E94(Parser*, int);
extern void fn_801658D0(Parser*);

void fn_80165F70(Parser* parser, Entry* output)
{
    fn_80163DA4(parser);
    fn_80165A54(parser, output);
    fn_80163E94(parser, 0x110);
    fn_801658D0(parser);
}
