typedef struct Parser Parser;
typedef struct Entry Entry;

extern int fn_8016576C(Parser*, Entry*, int);

int fn_80165870(Parser* parser, Entry* entry)
{
    return fn_8016576C(parser, entry, -1);
}
