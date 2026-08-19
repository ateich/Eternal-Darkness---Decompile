typedef struct Parser Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern void fn_8015F4D0(Parser*, Entry*, int);
extern void fn_80165870(Parser*, Entry*);

void fn_801655CC(Parser* parser)
{
    Entry entry;
    fn_80165870(parser, &entry);
    fn_8015F4D0(parser, &entry, 1);
}
