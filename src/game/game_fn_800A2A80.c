extern int fn_80201B64(void*);
extern int fn_80201B6C(void*);
extern int fn_80035FB8(void*, void*, void*, void*, void*, void*);

int fn_800A2A80(void* first, void* second, void* third, void* fourth,
                void* fifth, void* sixth)
{
    int result = 0;
    int value = fn_80201B64(first);
    int other = fn_80201B6C(first);

    if (other != value ||
        fn_80035FB8(first, second, third, fourth, fifth, sixth) != 0) {
        result = 1;
    }
    return result;
}
