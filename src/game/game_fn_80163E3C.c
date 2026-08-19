extern char lbl_8024F798[];
extern void fn_80162188(int, char*);
extern int fn_800F9D4C(char*, const char*, ...);
extern void fn_8015EA7C(void*, char*);

void fn_80163E3C(void* lexer, int token)
{
    char token_name[16];
    char message[100];

    fn_80162188(token, token_name);
    fn_800F9D4C(message, lbl_8024F798, token_name);
    fn_8015EA7C(lexer, message);
}
