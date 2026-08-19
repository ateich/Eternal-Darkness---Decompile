typedef struct SearchResult {
    int found;
    int depth;
    int value;
} SearchResult;

typedef struct ParserState {
    char padding_00[4];
    void* parent;
} ParserState;

typedef struct Parser {
    char padding_00[0x28];
    ParserState* state;
} Parser;

extern char lbl_8024F848[];
extern char lbl_8024F868[];
extern int fn_801644FC(Parser*, void*, SearchResult*);
extern void fn_8016209C(Parser*, char*, char*);
extern int fn_80163FE4(void*, void*);
extern int fn_801645F8(Parser*, SearchResult*);
extern void fn_8015F9B0(ParserState*, int, int);

void fn_801646BC(Parser* parser, void* value)
{
    SearchResult result;
    ParserState* state = parser->state;
    int level = fn_801644FC(parser, value, &result);

    if (level == -1) {
        if (state->parent == 0) {
            fn_8016209C(parser, lbl_8024F848, (char*)value + 0x14);
        }
        result.depth = fn_80163FE4(state->parent, value);
    } else if (level != 1) {
        fn_8016209C(parser, lbl_8024F868, (char*)value + 0x14);
    }
    fn_8015F9B0(state, 10, fn_801645F8(parser, &result));
}
