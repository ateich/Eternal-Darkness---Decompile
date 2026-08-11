typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct TransitionState {
    u8 pad000[0x1D8];
    s8 action;
    u8 selected;
    u8 type;
    u8 pad1DB;
    s8 special;
    u8 pad1DD[4];
    s8 enabled;
} TransitionState;

typedef struct TypeDescriptor {
    u8 pad00[8];
    s16 requirement;
    u8 pad0A[14];
} TypeDescriptor;

extern TransitionState lbl_8030F540;
extern TypeDescriptor lbl_802417D0[];
extern s32 lbl_8064CB78;
extern u32 lbl_8064E4D4;
extern s32 fn_80045240(s32);
extern void fn_80132D50(void);
extern void fn_801F348C(u32*, s32);

void fn_800537CC(s16 value)
{
    s32 one = fn_80045240(1);
    s32 two = fn_80045240(2);
    s32 three = fn_80045240(3);
    s32 ready = lbl_8064CB78;

    if (lbl_8030F540.action == -1) {
        s16 requirement = lbl_802417D0[lbl_8030F540.type].requirement;

        if (requirement == -1) {
            if (one != 0 || two != 0 || three != 0) {
                ready = 1;
            }
        } else {
            if (requirement == 1) {
                if (one != 0) {
                    ready = 1;
                    goto requirement_done;
                }
            }
            if (requirement == 2) {
                if (two != 0) {
                    ready = 1;
                    goto requirement_done;
                }
            }
            if (requirement == 3 && three != 0) {
                ready = 1;
            }
        }

requirement_done:
        if (lbl_8030F540.enabled == 0 || lbl_8030F540.special != 0) {
            ready = 1;
        }

        if (ready != 0) {
            u32 timed_value;
            lbl_8030F540.action = 0x15;
            lbl_8030F540.selected = (u8)value;
            fn_80132D50();
            timed_value = lbl_8064E4D4;
            fn_801F348C(&timed_value, 20);
        }
    }
}
