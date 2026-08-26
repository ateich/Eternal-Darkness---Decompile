extern int fn_8017BB24(void);
extern void* fn_8017BB44(void);
extern int fn_8017BDAC(void*);
extern int fn_8017BCD0(void);

void fn_8017BD3C(void)
{
    if (fn_8017BB24() == 0) {
        if (fn_8017BDAC(fn_8017BB44()) != 0) {
            fn_8017BCD0();
        }
    }
}
