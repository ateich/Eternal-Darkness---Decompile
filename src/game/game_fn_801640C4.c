typedef struct Lexer {
    char padding_00[8];
    int current_kind;
    char padding_0c[4];
    void* current_value;
} Lexer;

extern char lbl_8024F7F4[];
extern void fn_80163ED4(Lexer*, int, char*);
extern void fn_80163DA4(Lexer*);

void* fn_801640C4(Lexer* lexer)
{
    void* value;

    fn_80163ED4(lexer, lexer->current_kind == 0x113, lbl_8024F7F4);
    value = lexer->current_value;
    fn_80163DA4(lexer);
    return value;
}
