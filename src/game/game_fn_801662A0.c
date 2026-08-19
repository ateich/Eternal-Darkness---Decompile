typedef struct Parser {
    char pad0[0x28];
    void* state;
} Parser;

extern void fn_80164F7C(Parser*, int*);
extern char* fn_8015EE94(void*);
extern void fn_80163ED4(Parser*, char*, const char*);
extern void fn_8015EED8(void*, int);
extern int fn_80165934(Parser*, int*, int);
extern void fn_8015EE54(void*, int);
extern const char lbl_8024F99C[];

void fn_801662A0(Parser* parser)
{
    int value;
    void* state = parser->state;

    fn_80164F7C(parser, &value);
    if (value == 3) {
        fn_80163ED4(parser, fn_8015EE94(state), lbl_8024F99C);
        fn_8015EED8(state, 0);
    } else {
        int result = fn_80165934(parser, &value, 1);
        fn_8015EE54(state, result);
    }
}
