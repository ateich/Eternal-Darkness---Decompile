typedef unsigned char u8;

extern void* fn_801848AC(void*, void*, void*);
extern void fn_8017FE14(void*, void (*)(void));
extern void fn_8017FE1C(void*, void (*)(void));
extern void fn_80185078(void*, void*, void*);
extern void fn_801850E4(void*);
extern void fn_8018524C(void);
extern void fn_8018D7DC(void);

void* fn_801849E0(void* arg1, void* arg2, u8* arg3)
{
    void* result = fn_801848AC(arg1, arg2, arg3);

    if (result != 0) {
        fn_8017FE14(result, fn_8018524C);
        fn_8017FE1C(result, fn_8018D7DC);
        if (arg3 != 0 && arg3[0x16] == 0) {
            fn_801850E4(result);
        }
        fn_80185078(result, (char*)result + 0x10, arg3 + 0x20);
    }

    return result;
}
