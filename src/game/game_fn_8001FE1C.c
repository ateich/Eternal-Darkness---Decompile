typedef signed short s16;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad_00[0x1C];
    s32 index;
    u8 pad_20[8];
    s32 count;
    u8 pad_2C[0xC];
    u32 sound_handle;
    u8 pad_3C[2];
    u8 mode;
} RuntimeState;

extern RuntimeState lbl_8030241C;
extern u8 lbl_803003C8[];

extern void fn_80144C40(void);
extern s32 fn_800B193C(void);
extern void fn_800B267C(s16);
extern u32 fn_801A98F4(s32, s32);
extern void fn_801A9964(u32);
extern s32 fn_801E7578(u8);

void fn_8001FE1C(s16 delta)
{
    RuntimeState* runtime;

    fn_80144C40();
    runtime = &lbl_8030241C;

    switch (runtime->mode) {
    case 4:
    case 5:
    case 6:
    case 8:
    case 13:
    case 30:
        if (fn_800B193C() != 0) {
            fn_800B267C(delta);
        }
        break;

    case 9:
    case 17:
        lbl_8030241C.index += delta * 4;
        if (lbl_8030241C.index >= lbl_8030241C.count) {
            lbl_8030241C.index -= lbl_8030241C.count;
        } else if (lbl_8030241C.index < 0) {
            lbl_8030241C.index += lbl_8030241C.count;
        }
        break;

    case 14:
        if (fn_800B193C() != 0) {
            fn_800B267C(delta);
        } else {
            lbl_8030241C.index += delta;
            if (lbl_8030241C.index >= lbl_8030241C.count) {
                lbl_8030241C.index = 0;
            } else if (lbl_8030241C.index < 0) {
                lbl_8030241C.index = lbl_8030241C.count - 1;
            }
        }
        fn_801A98F4(0x27B, 100);
        break;

    case 11: {
        s16 amount;
        s32 count;
        s32 last;
        u8 available;
        s32 invalid;

        amount = delta;
        count = runtime->count;
        last = count - 1;
        available = lbl_803003C8[0x1918];

        do {
            invalid = 0;

            runtime->index += amount;
            if (runtime->index < 0) {
                runtime->index = last;
            } else if (runtime->index >= count) {
                runtime->index = 0;
            }
            if ((available & (1 << (runtime->index + 1))) == 0) {
                invalid = 1;
            }
        } while (invalid);
        break;
    }

    case 7:
        do {
            s32 invalid = 0;

            runtime->index += delta;
            if (runtime->index >= runtime->count) {
                runtime->index = 0;
            } else if (runtime->index < 0) {
                runtime->index = runtime->count - 1;
            }

            if (runtime->index == 4 &&
                fn_801E7578(lbl_803003C8[0x1918]) < 1) {
                invalid = 1;
            } else if (runtime->index == 3 &&
                       fn_801E7578(lbl_803003C8[0x1918]) < 2) {
                invalid = 1;
            }
            if (!invalid) {
                break;
            }
        } while (1);

        if (lbl_8030241C.sound_handle != (u32)-1) {
            fn_801A9964(lbl_8030241C.sound_handle);
            lbl_8030241C.sound_handle = (u32)-1;
        }
        switch (runtime->index) {
        case 0:
            lbl_8030241C.sound_handle = fn_801A98F4(0x275, 100);
            break;
        case 1:
            lbl_8030241C.sound_handle = fn_801A98F4(0x276, 100);
            break;
        case 2:
            lbl_8030241C.sound_handle = fn_801A98F4(0x277, 100);
            break;
        case 4:
            lbl_8030241C.sound_handle = fn_801A98F4(0x278, 100);
            break;
        case 3:
            lbl_8030241C.sound_handle = fn_801A98F4(0x2D4, 100);
            break;
        }
        break;

    case 16:
    case 18:
        break;

    default:
        lbl_8030241C.index += delta;
        if (lbl_8030241C.index >= lbl_8030241C.count) {
            lbl_8030241C.index = 0;
        } else if (lbl_8030241C.index < 0) {
            lbl_8030241C.index = lbl_8030241C.count - 1;
        }
        break;
    }
}
