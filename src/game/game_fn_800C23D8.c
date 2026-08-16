extern int fn_80128EAC(void *);
extern int fn_8011EB04(void *);
extern int fn_8011EB14(void *);

int fn_800C23D8(void *object)
{
    int result = 0;
    int type = fn_80128EAC(object);

    if (type == 16 || type == 17) {
        result = 1;
    }
    if (result == 0) {
        int kind = fn_8011EB04(object);
        int state = fn_8011EB14(object);
        if (kind == 76 && type == 15 && state == 5) {
            result = 1;
        }
    }
    return result;
}
