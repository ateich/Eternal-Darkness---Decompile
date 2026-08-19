extern void fn_80160F00(void*, void*);
extern void fn_80160FEC(void*, int);

void fn_80160FAC(void* object, void* argument)
{
    if (argument != 0) {
        fn_80160F00(object, argument);
    }
    fn_80160FEC(object, 1);
}
