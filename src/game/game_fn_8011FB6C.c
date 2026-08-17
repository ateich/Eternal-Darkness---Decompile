extern unsigned int fn_8011FAEC(void* object);
extern void* lbl_8064C540;
extern void* lbl_8064C53C;

void* fn_8011FB6C(void* object)
{
    if (fn_8011FAEC(object) & 0x02000000U) {
        if (*(int*)((char*)object + 0x244) == 105) {
            return lbl_8064C540;
        }
        return lbl_8064C53C;
    }
    return *(void**)((char*)*(void**)((char*)object + 0x3C) + 0x68);
}
