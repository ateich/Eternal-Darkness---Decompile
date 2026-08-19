typedef struct SearchResult {
    int found;
    int depth;
} SearchResult;

typedef struct Parser {
    char padding_00[0x28];
    void* state;
} Parser;

extern char lbl_8024F814[];
extern int fn_801644FC(Parser*, void*, SearchResult*);
extern void fn_8016209C(Parser*, char*, char*);
extern int fn_80163FE4(void*, void*);

void fn_8016457C(Parser* parser, void* value, SearchResult* result)
{
    int level = fn_801644FC(parser, value, result);

    if (level >= 1) {
        fn_8016209C(parser, lbl_8024F814, (char*)value + 0x14);
    } else if (level == -1) {
        result->depth = fn_80163FE4(parser->state, value);
    }
}
