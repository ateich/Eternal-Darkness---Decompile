typedef int s32;

#pragma use_lmw_stmw on

extern void* fn_80156938();
extern int fn_80201EB8();
extern void *fn_80201BC8();
extern s32 fn_8015C628(void*);
extern void* fn_8011F950(void*);
extern s32 fn_801261F4(void*);
extern void fn_802015D4(void*);
extern void fn_801568C0(void*, void*);
extern void fn_801568B8(void*, void*);
extern void fn_8011F7E0(void*, s32);
extern void fn_80126880(void*);

s32 fn_8002AB84(void* callback, void* unused, s32 run)
{
    void* source = fn_80156938(callback);
    void* state = (void*)fn_80201EB8();
    void* object = source != 0 ? fn_80201BC8(source) : 0;

    if (run != 0) {
        return 0;
    }
    if (fn_8015C628(state) != 0 && object != 0 &&
        fn_8011F950(object) != 0) {
        fn_801261F4(object);
        if (source != 0) {
            fn_802015D4(source);
        }
    } else {
        fn_801568C0(callback, 0);
        fn_801568B8(callback, 0);
        fn_8011F7E0(object, 0);
        fn_80126880(object);
    }
    return 0;
}
