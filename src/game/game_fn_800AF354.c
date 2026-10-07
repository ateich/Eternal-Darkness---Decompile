typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TransitionState {
    u8 reserved[0x15];
    u8 mode;
    u8 cooldown;
} TransitionState;

extern int lbl_803003C8[];
extern u32* lbl_8064C4E0;
extern u32 lbl_8064C4E4;
extern int lbl_8064C9D0;
extern int lbl_8064D18C;

extern int fn_801B2444(void);
extern int fn_801AD898(void);
extern int fn_801B2410(void);
extern int fn_801AD72C(void);
extern int fn_801E79FC(u32* set, u32 index);
extern void fn_801ACD8C(void);
extern int fn_800AF0DC(int);
extern void fn_801B1A1C(int id, int mode);
extern u16 fn_8004A608(u32 object, int level, u8* out_intensity,
                      u8* out_kind, u16* out_time, u32* out_flags);
extern int fn_800AE380(u16 id, u32 index, void* value, u16 arg6,
                      u16 arg7, u16 arg8, u8 kind, u16 arg10);
extern void fn_800AE3FC(u16 id, u32 index, void* value, u16 arg6,
                       u16 arg7, u16 arg8, u8 kind, u16 arg10);

void fn_800AF354(TransitionState* state)
{
    int enter = 0;
    int leave = 0;
    int timer = fn_801B2444();

    if (fn_801AD898() != 0 && fn_801B2410() != 0 &&
        (timer == 0 || timer >= 500)) {
        switch (fn_801AD72C()) {
        case 2:
        case 0x18:
        case 0x5F:
        case 0x68:
            leave = 1;
            lbl_8064C9D0 = 0;
            break;
        case 0x59:
        case 0x5A:
        case 0x5E:
        case 0x63:
        case 0x64:
        case 0x65:
        case 0x67:
        case 0x6A:
        case 0x70:
        case 0x7E:
        case 0x95:
        case 0x96:
        case 0x9E:
        case 0xA2:
        case 0xA3:
        case 0xA4:
        case 0xA5:
            lbl_8064C9D0 = 1;
            break;
        default:
            enter = 1;
            lbl_8064C9D0 = 0;
            break;
        }

        switch (lbl_803003C8[2]) {
        case 13:
        case 15:
            enter = 0;
            lbl_8064C9D0 = 1;
            break;
        }

        switch (lbl_8064D18C) {
        case 0x27:
        case 0x68:
        case 0x9D:
        case 0xB9:
            enter = 0;
            lbl_8064C9D0 = 1;
            break;
        case 0xBF:
            if (fn_801E79FC(lbl_8064C4E0, 0xBD) != 0) {
                enter = 0;
                lbl_8064C9D0 = 1;
            }
            break;
        }

        if (state->mode == 3 && enter != 0 && state->cooldown == 0) {
            u8 intensity;
            u8 kind;
            u16 time;
            u16 id;

            fn_801ACD8C();
            fn_801B1A1C(fn_800AF0DC(lbl_803003C8[2]), 30);
            state->cooldown = 100;
            id = fn_8004A608(lbl_8064C4E4, 0x3D, &intensity, &kind, &time, 0);
            if (id != 0xFFFF && fn_800AE380(id, 1, 0, 1, 320, 2, 0, 0) == 0) {
                fn_800AE3FC(id, 1, 0, 1, 320, 2, 0, 0);
            }
        } else if (state->mode < 3 && leave != 0 && state->cooldown == 0) {
            u8 intensity;
            u8 kind;
            u16 time;
            u16 id;

            fn_801ACD8C();
            fn_801B1A1C(lbl_803003C8[2], 30);
            state->cooldown = 100;
            id = fn_8004A608(lbl_8064C4E4, 0x3D, &intensity, &kind, &time, 0);
            if (id != 0xFFFF && fn_800AE380(id, 1, 0, 1, 320, 2, 0, 0) == 0) {
                fn_800AE3FC(id, 1, 0, 1, 320, 2, 0, 0);
            }
        }
        if (state->cooldown >= 1) {
            state->cooldown--;
        }
    }
}
