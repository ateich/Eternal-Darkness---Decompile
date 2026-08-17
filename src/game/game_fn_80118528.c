extern void *fn_8015AA0C(void);
extern unsigned int lbl_8064CD78;
extern void *lbl_8064CD7C;
extern void DCInvalidateRange(void *, unsigned int);
extern void fn_8015E9EC(unsigned int, void *, unsigned int);
extern void fn_8015DAB0(void *);

void fn_80118528(void)
{
    void *buffer = fn_8015AA0C();

    lbl_8064CD7C = buffer;
    DCInvalidateRange(buffer, lbl_8064CD78);
    fn_8015E9EC(0xE72D60, buffer, lbl_8064CD78);
    fn_8015DAB0(lbl_8064CD7C);
}
