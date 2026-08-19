typedef struct State State;

typedef struct Parser {
    char padding_00[0x28];
    State* state;
} Parser;

extern char lbl_8064BB60;
extern char lbl_8064BB68;
extern void fn_80163E94(Parser*, int);
extern void fn_801655CC(Parser*);
extern int fn_80163F00(Parser*, int);
extern int fn_8015F9B0(State*, int, int);
extern void fn_801641D4(Parser*, int, int);
extern void fn_801644B0(Parser*, char*, int);
extern void fn_80165C28(Parser*, int, int, int);

void fn_80165CE8(Parser* parser, int output)
{
    State* state = parser->state;

    fn_80163E94(parser, 0x3D);
    fn_801655CC(parser);
    fn_80163E94(parser, 0x2C);
    fn_801655CC(parser);
    if (fn_80163F00(parser, 0x2C)) {
        fn_801655CC(parser);
    } else {
        fn_8015F9B0(state, 6, 1);
    }
    fn_801641D4(parser, output, 0);
    fn_801644B0(parser, &lbl_8064BB60, 1);
    fn_801644B0(parser, &lbl_8064BB68, 2);
    fn_80165C28(parser, 3, 0x2C, 0x2D);
}
