extern void* fn_8004918C(void);
extern void* fn_8004910C(void);
extern void *fn_80201BC8();

void* fn_80050950(void)
{
    void* result = 0;

    if (fn_8004918C() != 0 && fn_8004910C() != 0) {
        result = fn_80201BC8();
    }
    return result;
}
