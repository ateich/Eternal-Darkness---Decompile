extern unsigned int lbl_8064D5A8;
extern int lbl_8064D18C;

extern void *fn_80201B94(void *object);
extern void *fn_80201BC8(void *object);
extern void *fn_8011FB4C(void *runtime);
extern int fn_8011F598(void *runtime, int first, int second, int previous,
                     void *result, unsigned char options);
extern void *fn_80204318(void *object, int value);
extern int fn_80201B54(void *object);
extern void fn_80201D2C(void *object, int value);
extern void fn_80201D14(void *object, unsigned char value);
extern int fn_80201B44(void);
extern void fn_80201DD8(void *object, void *value);

void fn_800C76DC(void *object)
{
    void *runtime;
    void *relation;
    void *other;
    int identifier;
    /* fn_8011F598 writes result data through offset 0x20. */
    unsigned int result[9];

    if ((lbl_8064D5A8 & 0x3F) == 0) {
        relation = fn_80201B94(object);
        runtime = fn_80201BC8(object);
        if (lbl_8064D18C == (int)fn_8011FB4C(runtime) &&
            fn_8011F598(runtime, 1, 0xF, -1, result, 1) != -1) {
            other = fn_80204318(object, 0);
            if (other != 0) {
                identifier = fn_80201B54(other);
            } else {
                fn_80201D2C(object, 0xE);
                fn_80201D14(object, 1);
                identifier = fn_80201B44();
            }
            fn_80201DD8(relation, (void *)identifier);
        }
    }
}
