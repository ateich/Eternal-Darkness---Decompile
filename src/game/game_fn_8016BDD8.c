extern void* fn_80201B3C(void);
extern void fn_8016A970(void*, void*, int);

int fn_8016BDD8(void* state)
{
    void* value = fn_80201B3C();
    fn_8016A970(state, value, 0);
    return 1;
}
