typedef struct Lexer {
    char padding[8];
    int current_kind;
} Lexer;

extern void fn_80163E3C(Lexer*, int);
extern void fn_80163DA4(Lexer*);

void fn_80163E94(Lexer* lexer, int token)
{
    if (lexer->current_kind != token) {
        fn_80163E3C(lexer, token);
    }
    fn_80163DA4(lexer);
}
