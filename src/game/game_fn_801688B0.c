#pragma use_lmw_stmw on

extern int fn_801686A8(void*, void*);
extern void* fn_80168490(void*, void*, int);

void* fn_801688B0(void* object, void* input)
{
    return fn_80168490(object, input, fn_801686A8(object, input));
}
