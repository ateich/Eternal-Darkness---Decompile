extern void* fn_80201B94();
extern void *fn_80201C48(void *);
extern int fn_80201B54();
extern void fn_80129FD0(void *, int, int);
extern unsigned long long fn_8020123C();

#pragma opt_propagation off
int fn_800D3598(void *state, void *object)
{
    void *saved_object;
    int id;
    void *value;

    saved_object = object;
    value = fn_80201C48(fn_80201B94(saved_object));
    id = fn_80201B54(saved_object);

    fn_80129FD0(state, 0x2300000, 0);
    fn_8020123C(159, id, value, 1);
    return 1;
}
#pragma opt_propagation reset
