typedef struct Parser {
    char pad0[8];
    int token;
    char padC[0x28];
    void* context;
} Parser;

extern void fn_80165FC8(Parser*, void*);
extern void fn_80165A9C(Parser*, void*);
extern void fn_80163DA4(Parser*);
extern void fn_801658D0(Parser*);
extern void fn_80163F38(Parser*, int, int, void*);
extern void fn_80165EAC(Parser*, void*);
extern void fn_80165B78(Parser*, void*);
extern void fn_8016623C(Parser*, void*);
extern void fn_801660EC(Parser*);
extern void fn_801662A0(Parser*);
extern void fn_80166334(Parser*);
extern void fn_801663A0(Parser*);
extern void fn_8015EA7C(Parser*, const char*);
extern const char lbl_8024F9E4[];

int fn_80166440(Parser* parser)
{
    void* context = parser->context;

    switch (parser->token) {
    case 0x109:
        fn_80165FC8(parser, context);
        return 0;
    case 0x112:
        fn_80165A9C(parser, context);
        return 0;
    case 0x103:
        fn_80163DA4(parser);
        fn_801658D0(parser);
        fn_80163F38(parser, 0x106, 0x103, context);
        return 0;
    case 0x107:
        fn_80165EAC(parser, context);
        return 0;
    case 0x10E:
        fn_80165B78(parser, context);
        return 0;
    case 0x108:
        fn_8016623C(parser, context);
        return 0;
    case 0x10A:
        fn_801660EC(parser);
        return 0;
    case 0x25:
    case 0x113:
        fn_801662A0(parser);
        return 0;
    case 0x10F:
        fn_80166334(parser);
        return 1;
    case 0x102:
        fn_801663A0(parser);
        return 1;
    default:
        fn_8015EA7C(parser, lbl_8024F9E4);
        return 0;
    }
}
