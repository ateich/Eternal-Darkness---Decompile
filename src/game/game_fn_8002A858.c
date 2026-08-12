typedef int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
extern u32 fn_8011FAEC(void*);
extern s32 fn_80131458(void);
extern s32 fn_8012671C(void);
extern s32 fn_8015C628(void*);
extern void* fn_8011F950(void*);
extern s32 fn_801261F4(void*);
extern s32 fn_8011FCEC(void*);
extern void fn_8011EBFC(void*);
extern void* fn_80156928(void*);
extern void* fn_80156938();
extern s32 fn_8011FCB0(void*);
extern void fn_801568C0(void*, void*);
extern void *fn_80201B8C();
extern void fn_800DBD74(void*);
extern void* fn_80156930(void*);
extern void fn_801568E4(void*);
extern void fn_801568B8(void*, void*);
extern void fn_8011F7E0(void*, s32);
extern void fn_80126880(void*);
extern void fn_8002A508(void);
extern void fn_8002A590(void);

s32 fn_8002A858(void* callback, void* object, void* state)
{
    s32 allowed = 1;
    s32 result = 0;
    u32 flags;
    void* source;

    fn_8011EB04(object);
    if (object != 0) {
        flags = fn_8011FAEC(object);
        if (fn_80131458() != 0 && (flags & 0x8000) == 0) {
            allowed = 0;
        }
    }

    if (fn_8012671C() < 20 && fn_8015C628(state) != 0 && object != 0 &&
        fn_8011F950(object) != 0 && allowed != 0) {
        flags = fn_8011FAEC(object);
        if (fn_801261F4(object) != 0 && (flags & 0x8000) == 0 &&
            fn_8011FCEC(object) != -1) {
            fn_8011EBFC(object);
        }

        if ((fn_8011FAEC(object) & 0x8000) == 0) {
            if (fn_80156928(callback) == 0) {
                source = fn_80156938(callback);
                if (fn_8011FCB0(object) != 0) {
                    fn_801568C0(callback, fn_8002A508);
                } else {
                    fn_801568C0(callback, fn_8002A590);
                }
                if (source != 0 && fn_80201B8C(source) != 0) {
                    fn_800DBD74(source);
                }
            }
            if (fn_80156930(callback) == 0) {
                fn_801568E4(callback);
                fn_80156930(callback);
            }
        }
        result = 1;
    } else {
        fn_801568C0(callback, 0);
        fn_801568B8(callback, 0);
        fn_8011F7E0(object, 0);
        fn_80126880(object);
    }
    return result;
}
