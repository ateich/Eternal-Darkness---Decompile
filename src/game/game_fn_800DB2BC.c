extern void *fn_80201BC8();
extern void *fn_80201B94(void *);
extern int fn_80201CDC(void *);
extern float fn_8012B750(void *);
extern void fn_8012B7A0(void *, float);
extern float lbl_8064F484;
extern float lbl_8064F488;

void fn_800DB2BC(void *context)
{
    void *object = fn_80201BC8(context);
    int flags = fn_80201B94(context) != 0 ? fn_80201CDC(context) : 0;

    if ((flags & 0x1000000) != 0) {
        float angle = fn_8012B750(object);
        angle += lbl_8064F484;
        if (angle > lbl_8064F488) {
            angle -= lbl_8064F488;
        }
        fn_8012B7A0(object, angle);
    }
}
