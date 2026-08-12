typedef void *ptr;

extern ptr fn_80201C48(void *event);
extern void *fn_80201814();
extern ptr fn_80204180(void *context, ptr value);

ptr fn_8005E9E4(void *context, void *event)
{
    ptr result;
    ptr value = fn_80201814(fn_80201C48(event));

    if (value != 0) {
        result = fn_80204180(context, value);
    }
    return result;
}
