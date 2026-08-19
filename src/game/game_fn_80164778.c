typedef struct Parser {
    char padding_00[0x28];
    void* state;
} Parser;

extern int fn_8015EE94(void*);
extern void fn_8015EED8(void*, int);
extern void fn_8015EE54(void*, int);

void fn_80164778(Parser* parser, int start, int end)
{
    void* state = parser->state;
    int count = end - start;

    if (end > 0 && fn_8015EE94(state)) {
        count--;
        if (count <= 0) {
            fn_8015EED8(state, -count);
            count = 0;
        } else {
            fn_8015EED8(state, 0);
        }
    }
    fn_8015EE54(state, count);
}
