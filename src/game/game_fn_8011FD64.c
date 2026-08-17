extern void* fn_8011FCF4(void* object);
extern void* fn_8011F950(void* object);
extern void fn_8012B9C8(void* object, int value);
extern void fn_80126880(void* object);
extern void fn_80125DE0(void* object);
extern void fn_8017CE74(void* manager, void* object);
extern void* lbl_8064CEA8;

void fn_8011FD64(void* object)
{
    void* entry;
    void* related;

    if (object != 0) {
        entry = fn_8011FCF4(object);
        related = fn_8011F950(object);
        if (entry != 0 && (*(unsigned*)((char*)entry + 0x1C) & 1) != 0) {
            *(unsigned*)((char*)entry + 0x1C) &= ~1u;
            if (related != 0) {
                fn_8012B9C8(related, 1);
            }
        }
        fn_80126880(object);
        fn_80125DE0(object);
        fn_8017CE74(lbl_8064CEA8, object);
    }
}
