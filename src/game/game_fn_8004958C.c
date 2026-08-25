typedef signed int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern float lbl_8064E3B4;
extern float lbl_8064E3B8;

extern void fn_8011FC38(void* object, s32 value, s32 enabled);
extern int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
extern void fn_8011FE6C(void* object);
extern void fn_80124664(void* object, s32 field, s32 mode, float value);
extern s32 fn_801261F4(void* object);
extern void fn_8012B344(void*);
extern u32 fn_80157994(void* object);
extern s32 fn_80157E1C(void* list);
extern void* fn_80157E24(void* list, s32 index);
extern void* fn_80158598(int object, int index);
extern void *fn_80201814();
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void* fn_80201C24();
extern void fn_80205680(void* object, void* parent, s32 value);

void fn_8004958C(void* object, s32 value)
{
    void* parent;
    s32 count;
    s32 index;
    void* list;

    parent = (void*)fn_80201B54(object);
    list = fn_80158598((s32)parent, 0);
    if (list != 0) {
        count = fn_80157E1C(list);
        index = 0;
        while (index < count) {
            void* entry;
            void* item;

            entry = fn_80201814(fn_80157E24(list, index));
            item = fn_80201BC8(entry);
            if (fn_8011EB04(item) == 0x70) {
                void* linked;

                linked = fn_80201C24(entry);
                fn_801261F4(item);
                if ((fn_80157994(linked) & 0xFFFF) != 0) {
                    fn_80124664(item, 0x1A, 8, lbl_8064E3B4);
                } else {
                    fn_80124664(item, 0x1A, 8, lbl_8064E3B8);
                }
            }
            fn_8011FC38(item, value, 1);
            fn_8012B344(item);
            fn_8011FE6C(item);
            fn_80205680(entry, parent, 0x5B);
            index++;
        }
    }
}
