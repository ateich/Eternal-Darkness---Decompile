typedef signed int s32;

#pragma use_lmw_stmw on

extern void *fn_801A7498(void *);
extern void *fn_801A7490(void *);
extern void* fn_80201814();
extern s32 fn_8003BD48(void *, void *);

s32 fn_800607BC(void *owner, void *resource)
{
    s32 result = 0;
    void *first = fn_801A7498(resource);
    void *second = fn_801A7490(resource);
    void *resolved_first = fn_80201814(first);

    fn_80201814(second);
    if (resolved_first != 0) {
        result = fn_8003BD48(owner, resource);
    }
    return result;
}
