typedef struct Parser Parser;

typedef struct Entry {
    int type;
    int value_04;
    int value_08;
} Entry;

extern int fn_80163F00(Parser*, int);
extern int fn_801640C4(Parser*);
extern void fn_801646BC(Parser*, int);
extern void fn_8016457C(Parser*, int, Entry*);
extern void fn_80164DF4(Parser*, Entry*);

void fn_80164F7C(Parser* parser, Entry* entry)
{
    if (fn_80163F00(parser, 0x25)) {
        fn_801646BC(parser, fn_801640C4(parser));
        entry->type = 3;
        entry->value_08 = -1;
        entry->value_04 = -1;
    } else {
        fn_8016457C(parser, fn_801640C4(parser), entry);
    }
    fn_80164DF4(parser, entry);
}
