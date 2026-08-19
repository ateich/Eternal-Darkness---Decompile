#pragma use_lmw_stmw on

extern const char lbl_8024FB30[];
extern int fn_80167DC8(void*, void*);
extern int fn_80167D68(void*);
extern void fn_80163BB4(void*, const char*, ...);

void fn_80168634(void* object, int expected, const char* description,
                 void* input)
{
    int actual = fn_80167DC8(object, input);

    if (actual != expected)
        fn_80163BB4(object, lbl_8024FB30, fn_80167D68(input), description,
                    expected, actual);
}
