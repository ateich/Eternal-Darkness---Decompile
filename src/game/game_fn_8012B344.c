#define FN_80128E30_RETURN int
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern void fn_8012B290(void*, void*);
extern int fn_8012B070(void*);

void fn_8012B344(void* owner)
{
    int state;

    state = fn_80128E30(owner);
    fn_8012B290(owner, (void*)state);
    fn_8012B070(owner);
}
