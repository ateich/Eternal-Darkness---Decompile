extern int fn_80201B54();
extern void fn_8015424C(void*, int, int, int, int, int, int, int);

void fn_800AD244(void)
{
    int index;
    void* object = ((void*)fn_80201B54());
    for (index = 9; index < 16; index++) {
        fn_8015424C(object, index, -1, 1, 0x230, 0, 1, 0x80);
    }
}
