extern char lbl_8064BB1C;
extern char lbl_8024F640[];
extern void fn_800F9D4C(char*, char*, ...);
extern void fn_8016209C(void*, char*, char*);

void fn_801621D8(void* parser, int value)
{
    char buffer[16];

    fn_800F9D4C(buffer, &lbl_8064BB1C, value);
    fn_8016209C(parser, lbl_8024F640, buffer);
}
