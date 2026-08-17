typedef struct Triple {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Triple;

extern void* fn_80201C24();
extern int fn_801579F4(void *);
extern void *fn_80201814();
extern void *fn_80155DB4(void *);
extern void *fn_80201BC8();
extern int fn_80201B44();
extern void fn_800DB95C(void *);
extern void fn_800DB874(void *);
extern void fn_80157C98(void *, int, int);
extern void fn_8002A754(void *, void *);
extern unsigned int fn_80157864(void *, int);
extern void fn_8012C62C(void *, int, unsigned int *, unsigned int *, unsigned int *, int);
extern unsigned int lbl_8064F48C;
extern unsigned int lbl_8064F490;
extern unsigned int lbl_8064F494;
extern unsigned int lbl_8064F498;
extern unsigned int lbl_8064F49C;
extern unsigned int lbl_8064F4A0;

void fn_800DB4F4(void *context, int mode)
{
    int count = fn_801579F4(fn_80201C24(context));
    if (count > 0) {
        void *linked = fn_80201814(count);
        void *linked_action = fn_80155DB4(linked);
        void *object = fn_80201BC8(linked);
        void *state = fn_80201C24(linked);
        int owner = fn_80201B44();
        fn_800DB95C(object);
        fn_800DB874(linked);
        fn_80157C98(state, 0x200, 0);
        fn_8002A754(linked_action, fn_80155DB4(fn_80201814(owner)));
        if (mode == 1) {
            Triple value;
            value.x = lbl_8064F48C;
            value.y = lbl_8064F490;
            value.z = lbl_8064F494;
            fn_8012C62C(object, 15, &value.z, &value.y, &value.x, 0);
        } else if (fn_80157864(state, 0) != 0) {
            Triple value;
            value.x = lbl_8064F498;
            value.y = lbl_8064F49C;
            value.z = lbl_8064F4A0;
            fn_8012C62C(object, 15, &value.z, &value.y, &value.x, 0);
        }
    }
}
