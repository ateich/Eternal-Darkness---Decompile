typedef struct Lexer {
    char padding[0x18];
    int lookahead_kind;
    int lookahead_padding;
    double lookahead_value;
} Lexer;

extern int fn_80163224(Lexer*, double*);

void fn_80163E08(Lexer* lexer)
{
    lexer->lookahead_kind = fn_80163224(lexer, &lexer->lookahead_value);
}
