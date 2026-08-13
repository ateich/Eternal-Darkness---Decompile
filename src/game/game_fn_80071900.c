extern void *fn_8004918C(void *);
extern int fn_801A7780(void *);

int fn_80071900(void *object)
{
    int result = 0;

    if (object != 0) {
        if (fn_801A7780(fn_8004918C(object)) & 0x90038) {
            result = 1;
        }
    }
    return result;
}
