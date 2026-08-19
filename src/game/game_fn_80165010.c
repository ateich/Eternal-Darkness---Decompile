typedef struct Parser {
    char padding_00[8];
    int token;
} Parser;

extern char lbl_8024F8E8[];
extern int fn_80164120(Parser*);
extern void fn_8015ECCC(Parser*, int);
extern void fn_80163DA4(Parser*);
extern void fn_801655CC(Parser*);
extern void fn_80163E94(Parser*, int);
extern void fn_8015EA7C(Parser*, char*);

void fn_80165010(Parser* parser)
{
    switch (parser->token) {
    case 0x113:
        fn_8015ECCC(parser, fn_80164120(parser));
        break;
    case 0x5B:
        fn_80163DA4(parser);
        fn_801655CC(parser);
        fn_80163E94(parser, 0x5D);
        break;
    default:
        fn_8015EA7C(parser, lbl_8024F8E8);
        break;
    }
    fn_80163E94(parser, 0x3D);
    fn_801655CC(parser);
}
