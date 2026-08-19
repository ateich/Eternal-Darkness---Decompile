typedef struct Lexer {
    char padding_00[8];
    int current_kind;
    char padding_0c[0x28];
    int line;
} Lexer;

extern char lbl_8024F7AC[];
extern void fn_80163E3C(Lexer*, int);
extern void fn_80162188(int, char*);
extern int fn_800F9D4C(char*, const char*, ...);
extern void fn_8015EA7C(Lexer*, char*);
extern void fn_80163DA4(Lexer*);

void fn_80163F38(Lexer* lexer, int expected, int opener, int line)
{
    char expected_name[16];
    char opener_name[16];
    char message[100];

    if (lexer->current_kind != expected) {
        if (line == lexer->line) {
            fn_80163E3C(lexer, expected);
        } else {
            fn_80162188(expected, expected_name);
            fn_80162188(opener, opener_name);
            fn_800F9D4C(message, lbl_8024F7AC, expected_name, opener_name, line);
            fn_8015EA7C(lexer, message);
        }
    }
    fn_80163DA4(lexer);
}
