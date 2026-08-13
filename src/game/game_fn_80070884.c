typedef struct Owner {
    int pad_00;
    void *entry;
} Owner;

extern int fn_8006EC8C(Owner *, void *);
extern int fn_8006CB30(void *);
extern void fn_8006CAE4(void *, int, int);
extern void fn_8006BD78(Owner *);
extern void fn_802020B4(void *, int);
extern void fn_80201D2C();
extern void fn_80201D14();

int fn_80070884(Owner *owner, void *object)
{
    int result = 0;

    if (fn_8006EC8C(owner, object)) {
        fn_8006CAE4(owner->entry, fn_8006CB30(owner->entry), 0);
        fn_8006BD78(owner);
        fn_802020B4(object, 1);
        result = 1;
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
    return result;
}
