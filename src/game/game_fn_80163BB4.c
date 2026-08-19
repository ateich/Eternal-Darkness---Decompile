typedef struct {
    unsigned char gpr;
    unsigned char fpr;
    unsigned char reserved[2];
    char* input_arg_area;
    char* reg_save_area;
} va_list[1];

#define va_start(ap, last) __builtin_va_info(&(ap))

extern int fn_800F9E2C(char*, const char*, void*);
extern void fn_80160FAC(void*, char*);

void fn_80163BB4(void* object, const char* format, ...)
{
    va_list args;
    char buffer[284];

    va_start(args, format);
    fn_800F9E2C(buffer, format, args);
    fn_80160FAC(object, buffer);
}
