#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern void fn_801291C4(void*, unsigned short);

void fn_80129190(void* owner, unsigned short value)
{
    void* runtime = fn_80128E30(owner);
    fn_801291C4(runtime, value);
}
