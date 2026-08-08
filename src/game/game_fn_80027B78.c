typedef unsigned int u32;

extern u32 lbl_8064DFE4;
extern u32 lbl_8064DFE8;
extern u32 lbl_8064DFEC;

extern void* fn_80201814(void*);
extern void* fn_80201C2C(void*);
extern void* fn_80201BC8(void*);
extern void fn_80204E0C(void*, void*);
extern void fn_8011FA8C(void*, u32, int);
extern void fn_8012C62C(void*, int, u32*, u32*, u32*, int);

void fn_80027B78(void* first, void* second)
{
    void* first_node;
    void* second_info;
    void* object;

    second_info = fn_80201814(second);
    first_node = fn_80201C2C(fn_80201814(first));
    object = fn_80201BC8(second_info);
    fn_80204E0C(second_info, first_node);
    if (object != 0) {
        u32 first_value;
        u32 second_value;
        u32 third_value;

        fn_8011FA8C(object, 0x10100, 0);
        third_value = lbl_8064DFEC;
        second_value = lbl_8064DFE8;
        first_value = lbl_8064DFE4;
        fn_8012C62C(object, 0xF, &first_value, &second_value, &third_value, 4);
    }
}
