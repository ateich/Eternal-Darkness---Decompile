extern float lbl_806504EC;
extern void* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern int fn_801FE494(void*);
extern int fn_801FE4C8(void*);
extern void fn_80149CC4(void*, float*, int, int, int);
extern void fn_801FDEB4(void*, float*);

void fn_8014C9F4(void* first, void* second)
{
    float value[4];
    void* first_runtime;
    void* second_runtime;
    int a;
    int b;

    second_runtime = fn_80156938(second);
    fn_80201BC8(second_runtime);
    first_runtime = fn_80156938(first);
    if (first_runtime != 0) {
        a = fn_801FE494(first_runtime);
        b = fn_801FE4C8(first_runtime);
        fn_80149CC4(second_runtime, value, a, b, 0);
        value[2] += lbl_806504EC;
        fn_801FDEB4(first_runtime, value);
    }
}
