typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct TypeDescriptor {
    void* name;
    s32 kind;
    u8 pad08[0x10];
} TypeDescriptor;

typedef struct ObjectDescriptor {
    void* name;
    s32 kind;
    u8 pad08[0x20];
} ObjectDescriptor;

typedef struct TransitionState {
    u8 pad00[0x1D0];
    s16 sound;
    u8 pad1D2[7];
    s8 busy;
    u8 type;
    u8 pad1DB[6];
    s8 mode;
    s8 restore;
} TransitionState;

extern TransitionState lbl_8030F540;
extern TypeDescriptor lbl_802417D0[];
extern ObjectDescriptor lbl_80241DE8[];

extern void fn_8001DA0C(void);
extern void fn_80052580(s32, s32, s32, s32, s32);
extern void fn_80052424(s32, s32, s32, s32);

s32 fn_80054844(s32 mode, s32 start)
{
    s32 result = 0;

    if (lbl_8030F540.busy != 0) {
        return 0;
    }

    if ((u8)mode == 1) {
        s32 transition = -1;

        switch (lbl_802417D0[lbl_8030F540.type].kind) {
        case 8:
            transition = 11;
            break;
        case 9:
            transition = 12;
            break;
        case 10:
            transition = 13;
            break;
        case 11:
            transition = 14;
            break;
        case 12:
            transition = 15;
            break;
        case 13:
            transition = 16;
            break;
        }

        if (transition != -1) {
            if (start != 0) {
                s32 current_mode = lbl_8030F540.mode;
                s32 restore = lbl_8030F540.restore;
                s32 sound = lbl_8030F540.sound;
                fn_8001DA0C();
                fn_80052580(current_mode, transition, restore, sound, 0);
            }
            result = 1;
        }
    } else if ((u8)mode == 0) {
        s32 transition = -1;

        switch (lbl_80241DE8[lbl_8030F540.type].kind) {
        case 0x8F:
            transition = 0xA9;
            break;
        case 0xAB:
            transition = 0xAA;
            break;
        case 0xAC:
            transition = 0x90;
            break;
        }

        if (transition != -1) {
            if (start != 0) {
                fn_8001DA0C();
                fn_80052424(transition, -1, 0, 0);
            }
            result = 1;
        }
    }

    return result;
}
