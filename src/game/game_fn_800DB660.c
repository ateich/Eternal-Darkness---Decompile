typedef unsigned int u32;

typedef struct Triple {
    u32 x;
    u32 y;
    u32 z;
} Triple;

extern void *fn_80201BC8();
extern void* fn_80201C24();
extern void *fn_80155DB4(void *);
extern int fn_80201B44();
extern void *fn_80158598(int, int);
extern int fn_80201B54();
extern int fn_80158264(void *, void *, int);
extern int fn_801E1ED4(int);
extern int fn_801E2004(int);
extern void fn_8012C62C(void *, int, u32 *, u32 *, u32 *, int);
extern void fn_8012F58C(void *, int, int, int, int, int);
extern void *fn_80201814();
extern void fn_8002A754(void *, void *);
extern void fn_800CC140(int, int, int, void *, int);
extern u32 fn_80157864(void *, int);
extern void fn_801568B8(void *, int);
extern u32 lbl_8064F4AC;
extern u32 lbl_8064F4B0;
extern u32 lbl_8064F4B4;
extern u32 lbl_8064F4B8;
extern u32 lbl_8064F4BC;
extern u32 lbl_8064F4C8;
extern u32 lbl_80651ACC;
extern u32 lbl_80651AD0;
extern u32 lbl_80651AD4;

void fn_800DB660(void *context, int mode)
{
    void *object = fn_80201BC8(context);
    void *state = fn_80201C24(context);
    void *action = fn_80155DB4(context);

    if (mode == 1) {
        int owner = fn_80201B44();
        void *owner_state = fn_80158598(owner, 0);
        int kind = fn_80201B54(context);
        int index = fn_80158264(owner_state, state, 1);
        void *linked = (*(void ***)state)[index];

        if (fn_801E1ED4(fn_80201B44()) != 0 && fn_801E2004(fn_80201B44()) == 4) {
            Triple value;
            value.x = lbl_8064F4B4;
            value.y = lbl_8064F4B0;
            value.z = lbl_8064F4AC;
            fn_8012C62C(object, 15, &value.z, &value.y, &value.x, 6);
            fn_8012F58C(object, 15, 0, 1, 30, 8);
        } else {
            Triple value;
            value.x = lbl_80651AD4;
            value.y = lbl_80651AD0;
            value.z = lbl_8064F4B8;
            fn_8012C62C(object, 15, &value.z, &value.y, &value.x, 0);
        }

        fn_8002A754(action, fn_80155DB4(fn_80201814(owner)));
        fn_800CC140(owner, kind, 0, linked, 0);
    } else {
        if (fn_80157864(state, 0) != 0) {
            Triple value;
            value.x = lbl_80651ACC;
            value.y = lbl_8064F4C8;
            value.z = lbl_8064F4BC;
            fn_8012C62C(object, 15, &value.z, &value.y, &value.x, 0);
        }
        fn_801568B8(action, 0);
    }
}
