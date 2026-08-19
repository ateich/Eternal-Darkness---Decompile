extern signed char lbl_8064BBC8;
extern const char lbl_8024FB14[];
extern int fn_80167DC8(void*, void*);
extern int fn_80167D68(void*);
extern void fn_80163BB4(void*, const char*, ...);

void fn_80168598(void* object, void* input)
{
    const signed char* signature = &lbl_8064BBC8;

    while (*signature != 0 && fn_80167DC8(object, input) == *signature)
        ++signature;
    if (*signature != 0)
        fn_80163BB4(object, lbl_8024FB14, fn_80167D68(input));
}
