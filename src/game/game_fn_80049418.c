typedef signed int s32;

extern void* lbl_8064C4E0;

extern void* fn_80049388(void* object, s32 index, s32 value);
extern void *fn_80201BC8();
extern int fn_8011EB04(void* object);
extern void fn_801E7974(void* object, int value);
extern void fn_801E79A0(void* object, s32 value);

void fn_80049418(void* object)
{
    if (object != 0) {
        void* entry = fn_80049388(object, 4, 0);

        if (entry != 0) {
            if (fn_8011EB04(fn_80201BC8(entry)) == 0xC0) {
                fn_801E7974(lbl_8064C4E0, 0x2ED);
            } else {
                fn_801E79A0(lbl_8064C4E0, 0x2ED);
            }
        } else {
            fn_801E79A0(lbl_8064C4E0, 0x2ED);
        }
    }
}
