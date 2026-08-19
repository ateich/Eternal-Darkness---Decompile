extern char lbl_8024FAD0[];
extern char* fn_80167D68(void*);
extern void fn_80163BB4(void*, const char*, ...);

void fn_80167D80(void* object, void* input)
{
    fn_80163BB4(object, lbl_8024FAD0, fn_80167D68(input));
}
