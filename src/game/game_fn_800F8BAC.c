extern unsigned char __files[];
extern char lbl_80239DE0[];
extern int fn_800F9F20(void *, const char *, ...);
extern void fn_800F6848(void);

void fn_800F8BAC(void *a, void *b, void *c)
{
    fn_800F9F20(__files + 0xA0, lbl_80239DE0, a, b, c);
    fn_800F6848();
}
