typedef struct Parser {
    char pad00[8];
    int position;
} Parser;

extern char lbl_8024F5EC[];
extern int fn_800F9D4C(char*, const char*, ...);
extern void fn_80162114(Parser*, char*, int);

void fn_8016203C(Parser* parser, int current, int limit, int token)
{
    char buffer[100];

    if (current > limit) {
        fn_800F9D4C(buffer, lbl_8024F5EC, token, limit);
        fn_80162114(parser, buffer, parser->position);
    }
}
