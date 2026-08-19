typedef struct Parser {
    char pad0[8];
    int token;
} Parser;

extern void fn_80163DA4(Parser*);
extern int fn_801640C4(Parser*);
extern void fn_801641D4(Parser*, int, int);
extern void fn_8015EA7C(Parser*, const char*);
extern int fn_80163F00(Parser*, int);
extern void fn_801647F8(Parser*, int, int);
extern const char lbl_8024F9FC[];

void fn_801665B0(Parser* parser)
{
    int count = 0;
    int terminal = 0;

    if (parser->token != 0x29) {
        do {
            switch (parser->token) {
            case 0x115:
                fn_80163DA4(parser);
                terminal = 1;
                break;
            case 0x113:
                fn_801641D4(parser, fn_801640C4(parser), count++);
                break;
            default:
                fn_8015EA7C(parser, lbl_8024F9FC);
                break;
            }
        } while (!terminal && fn_80163F00(parser, 0x2C));
    }
    fn_801647F8(parser, count, terminal);
}
