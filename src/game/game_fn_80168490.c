typedef struct InputFunction {
    unsigned char pad00[0x20];
    unsigned short line_defined;
    unsigned short source_line;
    unsigned short num_params;
    unsigned char pad26[0x16];
    int max_stack;
    void* source;
} InputFunction;

extern void* fn_80161164(void*);
extern void* fn_80168080(void*, void*, int);
extern int fn_80167FE4(void*, void*, int);
extern int fn_80167DC8(void*, void*);
extern void fn_801681DC(void*, void*, void*, int);
extern void fn_801682B0(void*, void*, void*, int);
extern void fn_80168334(void*, void*, void*, int);
extern void fn_80168114(void*, void*, void*, int);

InputFunction* fn_80168490(void* object, void* input, int reverse)
{
    InputFunction* function = fn_80161164(object);

    function->source = fn_80168080(object, input, reverse);
    function->max_stack = fn_80167FE4(object, input, reverse);
    function->line_defined = fn_80167FE4(object, input, reverse);
    function->source_line = fn_80167DC8(object, input);
    function->num_params = fn_80167FE4(object, input, reverse);
    fn_801681DC(object, function, input, reverse);
    fn_801682B0(object, function, input, reverse);
    fn_80168334(object, function, input, reverse);
    fn_80168114(object, function, input, reverse);
    return function;
}
