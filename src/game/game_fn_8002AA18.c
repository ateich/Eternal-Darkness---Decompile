typedef int s32;
typedef unsigned char u8;

extern void* fn_80156938(void*);
extern int fn_80201EB8();
extern void* fn_80201BC8();
extern s32 fn_8002A858(void*, void*, void*);
extern void* fn_80156928(void*);
extern int fn_80201B4C(void*);
extern void* fn_8015C910(void);
extern u8 fn_80202160(void*);
extern void fn_802015D4(void*);
extern void fn_8011FAAC(void*);
extern u8 lbl_8064C714;

s32 fn_8002AA18(void* callback, void* unused, s32 run)
{
    void* source = fn_80156938(callback);
    void* state = (void*)fn_80201EB8();
    void* object;

    if (source != 0) {
        object = fn_80201BC8(source);
    } else {
        object = 0;
    }

    if (run != 0) {
        fn_8002A858(callback, object, state);
    } else if (fn_80156928(callback) != 0) {
        if (source != 0) {
            if (lbl_8064C714 == 0 || fn_80201B4C(source) != 1) {
                if (fn_8015C910() == 0 || fn_80202160(source) == 0) {
                    fn_802015D4(source);
                }
            }
        }
        fn_8011FAAC(object);
    }
    return 0;
}
