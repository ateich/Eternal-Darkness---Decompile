typedef short s16;
typedef int s32;

extern s32 lbl_8064D18C;

extern void *fn_80201B9C(void);
extern void *fn_80201BC8();
extern void* fn_80201BC0(void*);
extern s32 fn_8011FB4C(void*);
extern int fn_80038308(void *, int, short *);
extern s32 fn_8013B8C0(void*, void*);

s32 fn_80034054(register void* target, register s32 check_value)
{
    register void* iterator;
    register void* object;
    register s32 count;
    register s32 valid;
    s16 value;

    iterator = fn_80201B9C();
    count = 0;
    while (iterator != 0) {
        object = fn_80201BC8(iterator);
        if (object != 0 && lbl_8064D18C == fn_8011FB4C(object)) {
            valid = 1;
            if (check_value != 0) {
                fn_80038308(iterator, 0, &value);
                if (value <= 0) {
                    valid = 0;
                }
            }
            if (valid != 0 && fn_8013B8C0(object, target) != 0) {
                count++;
            }
        }
        iterator = fn_80201BC0(iterator);
    }
    return count;
}
