typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct RuntimeState {
    u32 first_handle;
    u32 second_handle;
    u32 third_handle;
    u8 pad_0C[8];
    s32 previous_value;
    s32 value;
    s32 previous_state;
    s32 state;
    s32 counter;
    s32 selection;
    u32 flags;
    u32 aux_handle;
    u32 sound_handle;
    u8 pad_3C[2];
    u8 mode;
    u8 previous_mode;
    u8 timer;
} RuntimeState;

extern u8 lbl_80302400[];
extern RuntimeState lbl_8030241C;
extern u8 lbl_803003C8[];
extern u8 lbl_80238978[];
extern u8 lbl_8023D020[];
extern u8 lbl_8063D378[];

extern void* lbl_8064C504;
extern u32 lbl_8064C2AC;
extern u8 lbl_8064B2C4;
extern s32 lbl_8064B2C0;
extern s32 lbl_8064B2B8;
extern s32 lbl_8064C6BC[];
extern u32 lbl_8064C6C4;
extern s32 lbl_8064C6D4;
extern s32 lbl_8064CBA4;
extern void* lbl_8064C4E0;
extern u32 lbl_8064C650;
extern s32 lbl_8064C6A0;
extern s32 lbl_8064C69C;
extern s32 lbl_8064CBA0;
extern void* lbl_8064CE80;
extern s32 lbl_8064D294;
extern s32 lbl_8064C694;
extern double lbl_8064DEC8;

extern void fn_80144C40(void);
extern void fn_801E5FB0(u32);
extern u32* fn_801E5D08(u32);
extern u32 fn_801E6CA0(void*, s32, s32, s32, s32);
extern void fn_801EF5EC(void);
extern void fn_8020ED80(s32);
extern void fn_8001DFEC(s32, s32);
extern void fn_8001DE84(s32, s32);
extern void fn_8001DE68(void);
extern void fn_8001DA18(void);
extern s32 fn_800B193C(void);
extern void fn_800B2AE8(void);
extern void fn_800B177C(s32, void*);
extern void fn_800B689C(s32, s32);
extern void fn_800B2548(s32, s32);
extern void fn_8002387C(s32);
extern void fn_80023800(s32);
extern void fn_80023918(s32);
extern float fn_8020F088(void*);
extern float fn_800F5ECC(float, s32, s32, s32);
extern float fn_800F6264(void);
extern s32 fn_8020ED10(void);
extern void fn_8001F758(s32, s32);
extern void fn_801AD404(s32, s32, s32);
extern void fn_801AD490(void);
extern void fn_801A9964(u32);
extern void fn_801E79A0(void*, s32);
extern void fn_801E7974(void*, s32);
extern s32 fn_8012070C(void);
extern void fn_8015E918(void*, s32, s32, s32, s32);
extern u32 fn_801A98F4(s32, s32);
extern void fn_800AFBA8(void*);
extern void fn_80045230(void);
extern void fn_800451C4(s32);
extern s32 fn_801E7578(s32);
extern s32 fn_801E75A4(s32, s32);
extern s32 fn_800FBFB0(void);
extern void fn_800427E0(s32);
extern void fn_80023674(void);
extern void fn_80023710(void);
extern u32 fn_80144470(s32);
extern void fn_80144430(s32, s32);
extern void fn_801441C0(s32, s32, s32);
extern void fn_801F8620(void);
extern void fn_801FA410(s32);
extern void fn_801F10BC(s32, s32, s32);
extern void fn_8011C6BC(s32, s32, s32);
extern void fn_8011D558(void);
extern void* fn_801E8A8C(s32);
extern void fn_801E8AEC(void*, s32, s32, s32);
extern void fn_801E8B24(void*, s32, s32);
extern void* fn_80144710(s32, s32, s32);
extern void fn_80023A68(void);
extern void fn_801A96A8(s32, s32, s32);
extern void fn_8011C830(s32);
extern void fn_801F85A4(void);
extern void fn_80025A78(s32);

static inline s32 random_three(void)
{
    s32 value = fn_800FBFB0();
    return value % 3;
}

static inline void start_menu_callback(void* callback, s32 event)
{
    fn_800B177C(3, callback);
    fn_800B689C(1, 1);
    fn_800B2548(event, 0);
}

void fn_8001E894(void)
{
    RuntimeState* runtime = &lbl_8030241C;
    s32 keep_timer = 1;
    s32 i;

    fn_80144C40();

    switch (runtime->mode) {
    case 1:
    case 2:
    case 23:
    case 24:
    case 25:
    case 26:
    case 29:
    case 31:
        runtime->flags |= 1;
        keep_timer = 0;
        break;

    case 18:
        fn_801E5FB0(runtime->first_handle);
        fn_801E5FB0(runtime->second_handle);
        fn_801E5FB0(runtime->third_handle);
        runtime->first_handle = 0;
        runtime->second_handle = 0;
        runtime->third_handle = 0;
        if (runtime->previous_state == 0) {
            runtime->first_handle = fn_801E6CA0(lbl_8064C504, 0, 35, 0, 1);
            *fn_801E5D08(runtime->first_handle) = lbl_8064C2AC;
            fn_801EF5EC();
            fn_8020ED80(1);
        } else {
            runtime->first_handle = fn_801E6CA0(lbl_8064C504, 0, 36, 0, 1);
            *fn_801E5D08(runtime->first_handle) = lbl_8064C2AC;
            fn_8020ED80(0);
        }
        runtime->timer = 150;
        runtime->sound_handle = 7;
        runtime->counter = 0;
        fn_8001DFEC(19, 0);
        runtime->selection = 0;
        keep_timer = 0;
        break;

    case 30:
        if (fn_800B193C()) {
            fn_800B2AE8();
            keep_timer = 0;
        } else if (!lbl_8064B2C4) {
            s32 first = lbl_8064C6BC[0];
            s32 second = lbl_8064C6BC[1];
            if ((first == 0 || first == 2) && (second == 0 || second == 2)) {
                if (first == 0 && second == 0) {
                    start_menu_callback(fn_8002387C, 13);
                } else if ((first == 0 || first == 2) &&
                           (second == 0 || second == 2)) {
                    start_menu_callback(fn_8002387C, 14);
                } else {
                    fn_8002387C(1);
                }
            } else {
                fn_8002387C(1);
            }
        }
        break;

    case 8:
        if (fn_800B193C()) {
            fn_800B2AE8();
            keep_timer = 0;
        } else if (!lbl_8064B2C4 &&
                   (lbl_8064C6BC[0] == 0 || lbl_8064C6BC[0] == 2) &&
                   (lbl_8064C6BC[1] == 0 || lbl_8064C6BC[1] == 2)) {
            if (!(lbl_8064C6C4 & 1)) {
                lbl_8064C6C4 |= 1;
                lbl_8064C6C4 &= ~2u;
                start_menu_callback(fn_80023918, 34);
            } else {
                lbl_8064C6C4 = 1;
                fn_80023918(0);
            }
        } else {
            fn_80023800(1);
        }
        break;

    case 3: {
        s32 limit = *(s32*)(lbl_80302400 + 0x2CC);
        float now;
        fn_8020F088(lbl_80302400 + 0x60);
        fn_800F5ECC(0.0f, 0, 0, 0);
        now = fn_800F6264();
        lbl_8064C6D4 = 1;
        keep_timer = 0;
        if (fn_8020ED10() == 1)
            fn_8001F758(0, 0);
        if (runtime->previous_value == 255 && now > (float)limit) {
            fn_801AD404(0, 0, 10);
            fn_801AD490();
            fn_801AD404(100, 100, 1);
            fn_8001DFEC(1, 0);
            fn_8001DA18();
        }
        runtime->previous_value = 255;
        runtime->flags |= 1;
        break;
    }

    case 4:
    case 5:
    case 6:
    case 13:
        fn_800B2AE8();
        keep_timer = 0;
        break;

    case 7:
        if (runtime->sound_handle != (u32)-1) {
            fn_801A9964(runtime->sound_handle);
            runtime->sound_handle = (u32)-1;
        }
        if (runtime->aux_handle != (u32)-1) {
            fn_801A9964(runtime->aux_handle);
            runtime->aux_handle = (u32)-1;
        }
        switch (runtime->previous_state) {
        case 0:
        case 1: {
            void* dst = lbl_8064CBA4 == 1 ? lbl_8023D020 + 0x8F8
                                          : lbl_8023D020 + 0x908;
            fn_801E79A0(lbl_8064C4E0, 0x37E);
            fn_8015E918(dst, 0xE72D60, 0x330E0, fn_8012070C(), 0x330E0);
            if (runtime->previous_state == 0) {
                fn_8001DE84(8, 0);
                fn_8001DE68();
                fn_801A98F4(0x27A, 100);
            } else {
                s32* src = (s32*)(lbl_80238978 + 0x40);
                s32* dst_words = (s32*)(lbl_8023D020 + 0x7BC);
                start_menu_callback(fn_80023710, 1);
                for (i = 0; i < 16; ++i)
                    dst_words[i] = src[i];
                fn_8001DE84(13, 0);
                runtime->selection = 2;
            }
            break;
        }
        case 2:
            fn_800AFBA8(lbl_80302400 + 0x2DC);
            fn_8001DE84(14, 0);
            lbl_8064B2C0 = 1;
            runtime->selection = 7;
            lbl_8064C650 = fn_801A98F4(0x2D3, 100);
            break;
        case 3: {
            void* dst = lbl_8064CBA4 == 1 ? lbl_8023D020 + 0x8F8
                                          : lbl_8023D020 + 0x908;
            fn_8015E918(dst, 0xE72D60, 0x330E0, fn_8012070C(), 0x330E0);
            fn_8001DE84(9, 0);
            fn_801E7974(lbl_8064C4E0, 0x37E);
            runtime->selection = 12;
            lbl_8064C650 = fn_801A98F4(0x2D2, 100);
            break;
        }
        case 4:
            fn_8001DE84(28, 0);
            break;
        }
        keep_timer = 0;
        fn_801A98F4(0x279, 100);
        break;

    case 9:
    case 17: {
        s32 values[24];
        s32 index;
        for (i = 0; i < 24; ++i)
            values[i] = ((s32*)(lbl_80238978 + 0x80))[i];
        index = runtime->previous_state + (runtime->mode == 17 ? 12 : 0);
        runtime->counter = index == 12 ? 0 : (index < 12 ? index + 1 : index);
        index = runtime->counter;
        if (((s32*)(lbl_8023D020 + 0x538))[index] >= 0) {
            s32 value = values[index];
            *(s32*)(lbl_803003C8 + 8) = ((s32*)(lbl_8023D020 + 0x538))[index];
            *(s32*)(lbl_803003C8 + 0) = value;
            *(s32*)(lbl_803003C8 + 4) = value;
            lbl_803003C8[0x1914] = 0;
            *(u16*)(lbl_803003C8 + 0x1916) = 0;
            lbl_803003C8[0x191A] = 0;
            fn_80045230();
            fn_800451C4(0);
            lbl_8064C6A0 = -1;
            lbl_8064C69C = -1;
            if (index == 14) {
                fn_8001DFEC(20, 0);
                runtime->selection = 3;
            } else if (index == 15) {
                fn_8001DFEC(21, 0);
                runtime->selection = 7;
            } else {
                runtime->selection = 3;
                if (runtime->mode == 9) {
                    if (*(s32*)(lbl_8023D020 + 8) == 1) {
                        fn_800451C4(0);
                        if (fn_801E7578(lbl_803003C8[0x1918]) > 2) {
                            runtime->selection = 2;
                            fn_8001DFEC(250, 0);
                        } else {
                            fn_801A9964(lbl_8064C650);
                            fn_8001DE84(30, 0);
                        }
                    } else {
                        fn_8001DFEC(11,
                            fn_801E75A4(lbl_803003C8[0x1918], 0) - 1);
                    }
                } else {
                    fn_8001DFEC(22, random_three());
                }
            }
        }
        break;
    }

    case 21: {
        s32 values[24];
        s32 index = runtime->previous_state;
        s32* selected;
        for (i = 0; i < 24; ++i)
            values[i] = ((s32*)(lbl_80238978 + 0xE0))[i];
        *(s32*)(lbl_803003C8 + 0) = values[16 + index];
        *(s32*)(lbl_803003C8 + 4) = values[16 + index];
        selected = *(s32**)(lbl_8023D020 + 0x538 + index * 4);
        *(s32*)(lbl_8023D020 + 0x61C) = values[index];
        selected[15] = values[8 + index];
        fn_8001DFEC(22, random_three());
        runtime->selection = 3;
        break;
    }

    case 20: {
        s32 index = runtime->previous_state;
        *(s32*)(lbl_8023D020 + 0x618) =
            ((s32*)(lbl_80238978 + 0x140))[index];
        fn_8001DFEC(22, random_three());
        runtime->selection = 3;
        break;
    }

    case 14:
        if (fn_800B193C()) {
            fn_800B2AE8();
            keep_timer = 0;
            break;
        }
        switch ((u32)runtime->previous_state) {
        case 0:
            fn_800B177C(1, fn_80023674);
            fn_800B689C(0, 1);
            fn_800B2548(1, 0);
            break;
        case 1:
            *(u32*)(lbl_803003C8 + 0x10) ^= 1;
            break;
        case 2:
            lbl_8064CBA4 ^= 1;
            break;
        case 3: {
            u32 old = fn_80144470(1);
            fn_80144430(1, old ^ 1);
            if (old)
                fn_801441C0(1, 0, 30);
            break;
        }
        case 4: {
            s32* src = (s32*)(lbl_80238978 + 0x14C);
            s32* dst = (s32*)(lbl_8023D020 + 0x7DC);
            fn_801F8620();
            fn_801FA410(8);
            fn_801F10BC(0, 0, 0);
            *(s32*)(lbl_8063D378 + 0x40) = 1;
            runtime->mode = 16;
            for (i = 0; i < 8; ++i)
                dst[i] = src[i];
            fn_8011C6BC(0x66, 0x9A, 0xFE);
            break;
        }
        case 5:
            *(s32*)(lbl_8023D020 + 0x7C4) = 0;
            *(void**)(lbl_8023D020 + 0x824) = fn_8011D558;
            lbl_8064CE80 = fn_801E8A8C(0);
            fn_801E8AEC(lbl_8064CE80, 0, 0x33, 0x33);
            fn_801E8B24(lbl_8064CE80, lbl_8064CBA0, 0);
            fn_8001DE84(15, 0);
            break;
        case 6:
            if (lbl_8064D294 == 0)
                lbl_8064D294 = 1;
            else if (lbl_8064D294 == 1)
                lbl_8064D294 = 2;
            else if (lbl_8064D294 == 2)
                lbl_8064D294 = 0;
            fn_801A96A8(lbl_8064D294, 1, 1);
            break;
        }
        break;

    case 10:
        if (fn_80144710(0x1000, 0, 0)) {
            if (lbl_8064B2B8 || (u32)lbl_8064C694 >= 0x21)
                fn_80023A68();
        }
        keep_timer = 0;
        break;

    case 250:
        if (runtime->previous_state == 1)
            fn_801E7974(lbl_8064C4E0, 13);
        fn_801A9964(lbl_8064C650);
        fn_8001DE84(30, 0);
        break;

    case 11:
    case 22:
        fn_800427E0(runtime->previous_state + 1);
        if (fn_801E7578(lbl_803003C8[0x1918]) > 2) {
            runtime->selection = 2;
            fn_8001DFEC(250, 0);
        } else {
            fn_801A9964(lbl_8064C650);
            fn_8001DE84(30, 0);
        }
        break;

    case 16: {
        s32* src = (s32*)(lbl_80238978 + 0x16C);
        s32* dst = (s32*)(lbl_8023D020 + 0x7DC);
        for (i = 0; i < 8; ++i)
            dst[i] = src[i];
        fn_8011C830(1);
        fn_801F85A4();
        runtime->previous_mode = runtime->mode;
        runtime->mode = 14;
        runtime->value = runtime->previous_state;
        runtime->previous_state = 4;
        runtime->selection = 7;
        lbl_8064B2C0 = 1;
        break;
    }

    case 251:
    case 252:
    case 253:
    case 254:
        fn_80025A78(1);
        break;

    default:
        keep_timer = 0;
        break;
    }

    if (keep_timer)
        fn_801A98F4(0x27C, 100);
}
