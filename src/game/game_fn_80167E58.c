extern unsigned int fn_8016A480(void*, void*, void*);
extern void fn_80167D80(void*, void*);

void fn_80167E58(void* object, void* input, void* destination, void* size)
{
    if (fn_8016A480(input, destination, size) != 0) {
        fn_80167D80(object, input);
    }
}
