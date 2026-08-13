extern int fn_80079008(void *context, void *object);
extern void *fn_801294DC(void *object, int kind, int flags, int enabled);

void fn_80079054(void *context, unsigned int flags, void *object)
{
    if ((flags & 0x1FF) == 0) {
        if (fn_80079008(context, object)) {
            fn_801294DC(object, 0x10, 0x20, 1);
        } else {
            fn_801294DC(object, 0x77, 0x20, 1);
        }
    }
}
