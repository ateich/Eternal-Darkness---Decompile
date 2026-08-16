extern unsigned int lbl_80651B30;
extern unsigned int lbl_8064F640;
extern unsigned int lbl_8064F644;

extern void fn_8011FA8C(void *, int, int);
extern void fn_8012C62C(void *, int, unsigned int *, unsigned int *,
                        unsigned int *, int);

void fn_800E2344(void *unused, void *object)
{
    unsigned int first;
    unsigned int second;
    unsigned int third;

    fn_8011FA8C(object, 0xC0, 0);
    third = lbl_80651B30;
    second = lbl_8064F644;
    first = lbl_8064F640;
    fn_8012C62C(object, 15, &first, &second, &third, 4);
}
