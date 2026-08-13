extern int fn_80200C20(void *handle);
extern void *fn_80201814();
extern int fn_80201B44();
extern int fn_80201B5C(void *object);
extern int fn_80036E50(void *object);

void fn_80078CA4(void *unused, void *handle, int *output)
{
    int result = 0;

    if (handle != 0) {
        int handle_value = fn_80200C20(handle);
        void *object = fn_80201814(handle_value);

        if (object != 0 &&
            (handle_value == fn_80201B44(object) || fn_80201B5C(object) == 0x19) &&
            fn_80036E50(object) != 6) {
            result = 1;
        }
    }
    if (output != 0) {
        *output = result;
    }
}
