typedef unsigned int u32;
typedef unsigned short u16;

extern u32 lbl_802478D0[];
extern u32 lbl_80651A58;
extern u32 lbl_8064F13C;
extern u32 lbl_8064F138;

extern u32 fn_801578AC(void *);
extern u16 fn_80157994(void *);
extern void fn_8012C478(void *, int, int);
extern int fn_8011EB04(void *);
extern void fn_8012CBE8(void *, int, u32 *, u32 *, u32 *, int);
extern void fn_8012F58C(void *, int, int, int, int, int);
extern void* fn_8012C62C(void *, int, u32 *, u32 *, u32 *, int);

void fn_800BFFDC(void *object, void *state, int enabled)
{
    u32 kind = fn_801578AC(state);
    int is_primary = kind == 0x10;
    int is_secondary = 0;
    u32 first[3];
    u32 second[3];
    u32 third[3];

    if (!is_primary) {
        fn_8012C478(object, 0x10, enabled);
    }

    if (kind == 0x40 || kind == 0x80) {
        if (fn_80157994(state) >= 2 || enabled == 0) {
            is_secondary = 1;
        }
    }

    if (is_primary || is_secondary) {
        fn_8012C478(object, 0x11, enabled);
    }

    if (fn_8011EB04(object) != 0xC6) {
        if (enabled != 0) {
            if (!is_primary) {
                first[0] = lbl_802478D0[12];
                first[1] = lbl_802478D0[13];
                first[2] = lbl_802478D0[14];
                second[0] = lbl_802478D0[9];
                second[1] = lbl_802478D0[10];
                second[2] = lbl_802478D0[11];
                third[0] = lbl_802478D0[6];
                third[1] = lbl_802478D0[7];
                third[2] = lbl_802478D0[8];
                fn_8012CBE8(object, 0x10, first, second, third, 0);
                fn_8012F58C(object, 0x10, 1, 0, 0, 4);
            }
            if (is_primary || is_secondary) {
                first[0] = lbl_802478D0[12];
                first[1] = lbl_802478D0[13];
                first[2] = lbl_802478D0[14];
                second[0] = lbl_802478D0[9];
                second[1] = lbl_802478D0[10];
                second[2] = lbl_802478D0[11];
                third[0] = lbl_802478D0[6];
                third[1] = lbl_802478D0[7];
                third[2] = lbl_802478D0[8];
                fn_8012CBE8(object, 0x11, first, second, third, 0);
                fn_8012F58C(object, 0x11, 1, 0, 0, 4);
            }
        }
    } else if (enabled != 0) {
        first[0] = lbl_8064F138;
        second[0] = lbl_8064F13C;
        third[0] = lbl_80651A58;
        fn_8012C62C(object, 0x10, first, second, third, 4);
        fn_8012F58C(object, 0x10, 0, 0, 0, 0);
    }
}
