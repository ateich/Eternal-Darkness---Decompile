extern int fn_8011F598(void*, int, int, int, void*, int);
extern void fn_8011EA00(void*);

int fn_8011F6A4(void* object, int first, int second, int previous,
                void* result, int options)
{
    int found = fn_8011F598(object, first, second, previous, result, options);
    if (found == -1) {
        fn_8011EA00(object);
    }
    return found;
}
