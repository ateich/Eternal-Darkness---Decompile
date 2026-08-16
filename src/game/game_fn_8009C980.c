extern void *fn_80201814();
extern int fn_8009C820(void*, int);

int fn_8009C980(register void* state, register int actor_id)
{
    void* actor = fn_80201814(actor_id);
    int result = 0;
    if (actor != 0) {
        result = fn_8009C820(state, actor_id);
    }
    return result;
}
