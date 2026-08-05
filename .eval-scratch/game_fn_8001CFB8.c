extern int fn_8016A598(void *);
extern void fn_80163BB4(void *, const char *, ...);
extern float fn_8016A694(void *, int);
extern int fn_800F5C54(void);
extern int fn_800289A4(int, int, int);
extern void fn_801FA198(int, const char *, int, int, int, int, int, int, int);
extern char lbl_8023BEF8[];
extern char lbl_8063CD18[];

int fn_8001CFB8(void *obj)
{
    int a, b, c, d, e, f;

    if (fn_8016A598(obj) != 6) {
        fn_80163BB4(obj, lbl_8023BEF8, 6, fn_8016A598(obj));
        return 0;
    }

    fn_8016A694(obj, 1);
    a = fn_800F5C54();
    b = (int)fn_8016A694(obj, 2);
    c = (int)fn_8016A694(obj, 3);
    d = (int)fn_8016A694(obj, 4);
    e = (int)fn_8016A694(obj, 5);
    f = (int)fn_8016A694(obj, 6);

    if (fn_800289A4(a, d, f) & 0xffff) {
        d = 0;
    }

    fn_801FA198(a, &lbl_8063CD18[0x110], b, c, d, 0, 0, e, 0);
    return 0;
}
