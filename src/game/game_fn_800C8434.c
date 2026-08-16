typedef unsigned int Color;
extern void fn_8012DBE8(void *, int, Color *);
extern void fn_8012C62C(void *, int, Color *, Color *, Color *, int);
extern Color lbl_8064F244;
extern Color lbl_8064F248;

void fn_800C8434(void *object)
{
    Color source;
    Color copy;
    Color a;
    Color b;
    fn_8012DBE8(object, 0xF, &source);
    b = lbl_8064F248;
    a = lbl_8064F244;
    copy = source;
    fn_8012C62C(object, 0xF, &copy, &a, &b, 6);
}
