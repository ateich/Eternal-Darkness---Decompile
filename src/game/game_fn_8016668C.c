typedef struct RuntimeObject {
    char pad0[0x3C];
    void* context;
} RuntimeObject;

typedef struct ParserState {
    RuntimeObject* object;
    char pad4[0x28];
    char entries[99][12];
} ParserState;

typedef struct Parser Parser;

extern void fn_801649CC(Parser*, ParserState*);
extern void fn_80163E94(Parser*, int);
extern void fn_801644B0(Parser*, void*, int);
extern void fn_8016425C(Parser*, int);
extern void fn_801665B0(Parser*);
extern void fn_80166750(Parser*);
extern void fn_80163F38(Parser*, int, int, void*);
extern void fn_80164A64(Parser*);
extern void fn_80164908(Parser*, ParserState*);
extern char lbl_8064BB7C;

void fn_8016668C(Parser* parser, int scoped, void* context)
{
    ParserState state;

    fn_801649CC(parser, &state);
    state.object->context = context;
    fn_80163E94(parser, 0x28);
    if (scoped) {
        fn_801644B0(parser, &lbl_8064BB7C, 0);
        fn_8016425C(parser, 1);
    }
    fn_801665B0(parser);
    fn_80163E94(parser, 0x29);
    fn_80166750(parser);
    fn_80163F38(parser, 0x106, 0x108, context);
    fn_80164A64(parser);
    fn_80164908(parser, &state);
}
