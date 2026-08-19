#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern int fn_8012AFE8(void*);

int fn_8012AFC4(void* owner)
{
    return fn_8012AFE8(fn_80128E30(owner));
}
