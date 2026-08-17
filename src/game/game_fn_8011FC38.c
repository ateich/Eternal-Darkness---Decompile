extern int fn_80138DB4(void* object, int value);
extern void fn_8011FBD0(void* object, int value, int preserve);

void fn_8011FC38(void* object, int value, int preserve)
{
    if (*(int*)((char*)object + 0x294) != value || preserve) {
        if (fn_80138DB4(object, value)) {
            fn_8011FBD0(object, value, preserve);
        }
    }
}
