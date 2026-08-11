typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct TransitionState {
    u8 pad000[0x1C8];
    s32 elapsed;
    u8 pad1CC[10];
    s16 resource;
    s8 action;
    u8 selected;
    u8 type;
    u8 pad1DB;
    s8 special;
    u8 pad1DD;
    u8 pending;
} TransitionState;

typedef struct TransitionDescriptor {
    u8 pad00[0x1A];
    s8 requirement;
    u8 pad1B[0xD];
} TransitionDescriptor;

extern TransitionState lbl_8030F540;
extern TransitionDescriptor lbl_80241DE8[];
extern s32 lbl_8064CB78;
extern u32 lbl_8064E4D0;
extern s32 fn_80045240(s32);
extern void fn_80132D50(void);
extern void fn_801F348C(u32*, s32);

void fn_80053600(s16 value)
{
    s32 one = fn_80045240(1);
    s32 two = fn_80045240(2);
    s32 three = fn_80045240(3);

    if (lbl_8030F540.resource != -1 && lbl_8030F540.action == -1) {
        s8 requirement = lbl_80241DE8[lbl_8030F540.type].requirement;
        s32 ready = lbl_8064CB78;

        if (requirement == -1) {
            if (one != 0 || two != 0 || three != 0) {
                ready = 1;
            }
        } else if (requirement == 4) {
            if (one != 0 && two != 0 && three != 0) {
                ready = 1;
            }
        } else {
            if (requirement == 0 && one != 0) {
                ready = 1;
            }
            if (requirement == 1 && two != 0) {
                ready = 1;
            }
            if (requirement == 2 && three != 0) {
                ready = 1;
            }
        }

        if (lbl_8030F540.special != 0) {
            ready = 1;
        }

        if ((lbl_8030F540.elapsed > 180 || value == 2) && ready != 0) {
            u32 timed_value;
            lbl_8030F540.action = 0x15;
            lbl_8030F540.selected = (u8)value;
            fn_80132D50();
            timed_value = lbl_8064E4D0;
            fn_801F348C(&timed_value, 20);
        } else if (ready != 0) {
            lbl_8030F540.pending = 1;
        }
    } else {
        lbl_8030F540.pending = 1;
    }
}
