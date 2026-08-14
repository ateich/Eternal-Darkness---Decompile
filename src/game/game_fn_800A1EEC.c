extern void fn_801AD404(int, int, int);
extern void fn_801AD490(void);
extern void fn_801AD734(int);
extern void fn_801B05E8(int, int, int, int, int, int, int, int);

void fn_800A1EEC(void)
{
    fn_801AD404(0, 0, 10);
    fn_801AD490();
    fn_801AD404(100, 100, 1);
    fn_801AD734(0x708);
    fn_801B05E8(0x262, 100, 6, 1, 0, 5, 0, 0);
}
