extern void* fn_80050950(void);
extern int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))

int fn_8005099C(void)
{
    int result = -1;
    void* object = fn_80050950();

    if (object != 0) {
        result = fn_8011EB04(object);
    }
    return result;
}
