extern void* fn_80201ADC(void);
extern int fn_80201B64(void);

int fn_800AD3A4(void)
{
    if (fn_80201ADC() != 0) {
        return fn_80201B64() == 8;
    }
    return 0;
}
