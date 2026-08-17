typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern int fn_8011EB04(void *);
extern void* fn_80201C24();
extern void fn_801261F4(void *);
extern u16 fn_80157994(void *);
extern void fn_80124664(void *, int, int, float);
extern float lbl_8064F460;
extern float lbl_8064F464;

void fn_800DBD74(void *context)
{
    void *info = fn_80201B8C(context);
    void *object = fn_80201BC8(context);

    if (info != 0 && ((u8 *)info)[0x9e] == 4 && fn_8011EB04(object) == 0x70) {
        void *state = fn_80201C24(context);
        fn_801261F4(object);
        if (fn_80157994(state) != 0) {
            fn_80124664(object, 0x1a, 8, lbl_8064F460);
        } else {
            fn_80124664(object, 0x1a, 8, lbl_8064F464);
        }
    }
}
