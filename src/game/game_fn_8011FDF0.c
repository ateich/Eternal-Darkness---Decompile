extern void* fn_8017CDB4(void* manager);
extern void* memset(void* destination, int value, unsigned long size);
extern void* lbl_8064CEA8;

void* fn_8011FDF0(void)
{
    void* object = fn_8017CDB4(lbl_8064CEA8);
    if (object != 0) {
        memset(object, 0, 0x2E0);
    }
    return object;
}
