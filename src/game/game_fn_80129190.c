extern void* fn_80128E30(void*);
extern void fn_801291C4(void*, unsigned short);

void fn_80129190(void* owner, unsigned short value)
{
    void* runtime = fn_80128E30(owner);
    fn_801291C4(runtime, value);
}
