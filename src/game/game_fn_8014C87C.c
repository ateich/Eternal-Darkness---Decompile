extern void* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern int fn_8011F6A4(void*, int, int, int, int*, int);
extern void fn_801FDEB4(void*, int*);

void fn_8014C87C(void* first, void* second)
{
    int values[10];
    void* owner;
    void* first_runtime;

    owner = fn_80201BC8(fn_80156938(second));
    first_runtime = fn_80156938(first);
    if (first_runtime != 0) {
        fn_8011F6A4(owner, 17, 1, -1, values, 1);
        fn_801FDEB4(first_runtime, values + 2);
    }
}
