extern void* fn_8004918C(void);
extern int fn_801A7840(void* object);

int fn_80050A48(void)
{
    void* object = fn_8004918C();

    if (object != 0) {
        return fn_801A7840(object);
    }
    return 0;
}
