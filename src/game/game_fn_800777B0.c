typedef unsigned char u8;

extern void *fn_80201B8C(void *);
extern void *fn_80201B54(void *);
extern unsigned long long fn_8020123C(int, void *, void *, int);

/* NonMatching: behavior-complete event-forwarding wrapper. Retail assigns the
 * object and info pointers to the opposite callee-saved registers and schedules
 * the r30 save after the argument move. */
int fn_800777B0(void *unused, void *object)
{
    register u8 *info;
    void *handle;

    info = *(u8 **)((u8 *)fn_80201B8C(object) + 0x8C);
    handle = fn_80201B54(object);

    fn_8020123C(0x6E, handle, *(void **)(info + 0x48), 0);
    return 1;
}
