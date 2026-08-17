extern void* lbl_8064CE94;
extern void* lbl_8064CE98;
extern unsigned int lbl_8064CE88;
extern void (*lbl_8064CE9C)(void*, int);
extern void (*lbl_8064CEA0)(void);

extern void fn_8011E1C4(void);

void fn_8011E234(void* context, void (*release)(void*, int), void (*update)(void))
{
    lbl_8064CE94 = context;
    lbl_8064CE98 = 0;
    lbl_8064CE88 = 0;
    lbl_8064CE9C = release;
    lbl_8064CEA0 = update;
    fn_8011E1C4();
}
