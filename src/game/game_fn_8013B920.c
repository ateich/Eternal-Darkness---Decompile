extern void *fn_80201B9C();
extern void *fn_80201BC8();
extern void* fn_80201BC0(void*);
extern int fn_8011FB4C(void*);
extern int fn_8011EB1C(void*);
extern int fn_8013B8C0(void*, void*);
extern void* lbl_8064C4E4;

int fn_8013B920(void* object, void* other)
{
    void* iterator;
    void* candidate;
    int count;
    int category;

    iterator = fn_80201B9C();
    count = 0;
    category = fn_8011FB4C(object);
    while (iterator != 0) {
        candidate = fn_80201BC8(iterator);
        if (candidate != 0 && candidate != lbl_8064C4E4 && candidate != object &&
            category == fn_8011FB4C(candidate) && fn_8011EB1C(candidate) == 2 &&
            fn_8013B8C0(candidate, other) != 0) {
            count++;
        }
        iterator = fn_80201BC0(iterator);
    }
    return count;
}
