typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

#pragma use_lmw_stmw on

extern int lbl_8064C5C8;
extern int lbl_8064C5C4;

extern void* fn_80156938();
extern void *fn_80201BC8();
extern int fn_801FA44C(void);
extern int fn_80201EB8(void *);
extern u32 fn_8011FAEC(void*);
extern s32 fn_8002A858(void*, void*, void*);
extern void fn_801568C0(void*, int);
extern void fn_801568B8(void*, void*);
extern void fn_8011F7E0(void*, int);
extern void fn_80126880(void*);
extern int fn_80156928(void*);
extern int fn_80201B44(void);
extern int fn_80201AE4(void);
extern void* fn_8015C910(void);
extern u8 fn_80202160(void*);
extern void fn_80048C74(void*);
extern void fn_802015D4(void*);

int fn_800073E4(void* object, int value, int apply)
{
    void* item = fn_80156938(object, value);
    void* context;
    int state;
    void* child;
    u32 flags;

    if (item != 0) {
        context = fn_80201BC8(item);
    } else {
        context = 0;
    }

    state = fn_801FA44C();
    child = (void*)fn_80201EB8(item);
    flags = fn_8011FAEC(context);

    if (apply != 0) {
        int result = fn_8002A858(object, context, child);
        if (item == 0 || result == 0) {
            register void* replacement = fn_80201BC8(item);
            fn_801568C0(object, 0);
            fn_801568B8(object, 0);
            fn_8011F7E0(replacement, 0);
            fn_80126880(replacement);
        }
    } else {
        int active = fn_80156928(object) != 0;
        if (item != 0 && active != 0) {
            int current = fn_80201B44();
            int same = current == fn_80201AE4();

            if ((lbl_8064C5C8 != 0 && same != 0) ||
                (lbl_8064C5C4 != 0 && same == 0)) {
                if ((flags & 0x8000) == 0) {
                    if (fn_8015C910() == 0 || fn_80202160(item) == 0) {
                        if (state != 0) {
                            fn_80048C74(item);
                        }
                        fn_802015D4(item);
                    }
                }
            }
        }
    }
    return 0;
}
