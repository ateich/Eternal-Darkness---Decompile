typedef unsigned long size_t;

extern size_t strlen(const char*);
extern void fn_8016A7D8(void*);
extern void fn_8016A890(void*, const char*, int);

void fn_8016A8F8(void* context, const char* string)
{
    if (string == 0) {
        fn_8016A7D8(context);
    } else {
        fn_8016A890(context, string, strlen(string));
    }
}
