extern int fn_80128E30(void*);
extern void fn_8012B290(void*, void*);
extern int fn_8012B070(void*);

void fn_8012B344(void* owner)
{
    int state;

    state = fn_80128E30(owner);
    fn_8012B290(owner, (void*)state);
    fn_8012B070(owner);
}
