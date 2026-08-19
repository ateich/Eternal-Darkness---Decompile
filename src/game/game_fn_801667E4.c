typedef struct Parser {
    char pad0[0x44];
    void* value44;
} Parser;

extern void* fn_80167798(Parser*, int);
extern void fn_801604F8(Parser*, int);
extern void fn_80166AC4(Parser*);
extern void fn_80161FD0(Parser*);
extern void fn_80167CA0(Parser*);
extern void fn_8016AAB4(Parser*);
extern void fn_8016AB6C(Parser*, int);
extern int fn_801667BC(void*);
extern void fn_8016A950(Parser*, int (*)(void*), int);
extern void fn_8016AB20(Parser*, const char*);
extern const char lbl_8024FA18[];

void fn_801667E4(Parser* parser, int* configured_size)
{
    int size = 0x400;

    if (*configured_size != 0) {
        size = *configured_size + 0x14;
    }
    parser->value44 = fn_80167798(parser, 10);
    fn_801604F8(parser, size);
    fn_80166AC4(parser);
    fn_80161FD0(parser);
    fn_80167CA0(parser);
    fn_8016AAB4(parser);
    fn_8016AB6C(parser, 1);
    fn_8016A950(parser, fn_801667BC, 0);
    fn_8016AB20(parser, lbl_8024FA18);
}
