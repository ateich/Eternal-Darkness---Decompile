typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct GameEntry {
    s32 state;
    s32 object;
    s32 phase;
    s32 valueC;
    s32 value10;
    s32 value14;
    u32 flags;
    s32 value1C;
} GameEntry;

typedef struct GameState {
    GameEntry entries[2];
    s32 current;
} GameState;

extern GameState lbl_80300368;
extern void* lbl_8064C4E4;
extern void* lbl_8064C4E0;
extern void* lbl_8064C500;
extern void* lbl_8064C504;
extern char lbl_8063CD18[];
extern char lbl_8063C6B8[];
extern float lbl_8064DFF0;
extern float lbl_8064DFF4;

extern s32 fn_801290D0(void*);
extern void fn_80128F74(void*, u32);
extern void fn_801A5C30(s32);
extern void fn_801F8620(void);
extern void fn_801F85A4(void);
extern void fn_801FA410(s32);
extern void fn_801F7208(void*, float);
extern s32 fn_801FBEF0(void*, s32, s32);
extern s32 fn_801FC034(void*, s32, s32, float);
extern void fn_80046D38(s32);
extern u16 fn_800289A4(s32, s32, s32);
extern void fn_801FA198(s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern void fn_8011E310(s32, s32, s32, s32, s32, s32, s32);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_80027730(void*, s32, s32);
extern void fn_801FA354(void);
extern void fn_80028B44(void);
extern void fn_8016B400(int, int, int);
extern void* fn_80201814(s32);
extern void* fn_80201C24(void*);
extern s32 fn_80157BC4(void);
extern s32 fn_80157BF4(s32);
extern int fn_80201B44(void);
extern void fn_80205680(void*, void*, s32);
extern s32 fn_8015821C(s32);
extern int fn_801E79FC(void*, int);
extern void fn_801B05E8(s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_80027948(void*, s32, void*, s32, s32, s32, s32);

static inline void enable_object_flags(void)
{
    if (lbl_8064C4E4 != 0) {
        fn_80128F74(lbl_8064C4E4, fn_801290D0(lbl_8064C4E4) | 4);
    }
}

static inline void reset_pair(void)
{
    fn_801F8620();
    fn_801FA410(10);
    fn_801F7208(lbl_8063CD18 + 0x550, lbl_8064DFF0);
    fn_801F7208(lbl_8063C6B8 + 0x550, lbl_8064DFF0);
}

static inline void begin_scene(s32 kind, s32 player_mode)
{
    fn_8011E310(2, kind, -2,
                lbl_80300368.entries[lbl_80300368.current].object,
                0x32, player_mode, 1);
}

static inline void activate_entry(s32 player_mode, s32 retry)
{
    s32 ok;

    reset_pair();
    ok = fn_801FBEF0(lbl_8064C4E4,
                     lbl_80300368.entries[lbl_80300368.current].value14,
                     lbl_80300368.entries[lbl_80300368.current].flags & 1);
    if (!ok && retry) {
        ok = fn_801FC034(lbl_8064C4E4,
                        lbl_80300368.entries[lbl_80300368.current].value14,
                        lbl_80300368.entries[lbl_80300368.current].flags & 1,
                        lbl_8064DFF4);
    }
    if (ok) {
        lbl_80300368.entries[lbl_80300368.current].flags |= 4;
        lbl_80300368.entries[lbl_80300368.current].flags &= ~1U;
    }
    if (lbl_80300368.entries[lbl_80300368.current].flags & 4) {
        fn_80046D38(0);
    }
    if (fn_800289A4(lbl_80300368.entries[lbl_80300368.current].value14,
                    lbl_80300368.entries[lbl_80300368.current].flags & 1, 0)) {
        lbl_80300368.entries[lbl_80300368.current].flags &= ~1U;
    }
    fn_801FA198(lbl_80300368.entries[lbl_80300368.current].value14,
                lbl_8063CD18 + 0x550, 0, 0,
                lbl_80300368.entries[lbl_80300368.current].flags & 1,
                0, 0, 0, 0);
    if (retry &&
        lbl_80300368.entries[lbl_80300368.current].value10 < 0) {
        begin_scene(7, player_mode);
        lbl_80300368.entries[lbl_80300368.current].phase = 3;
    } else {
        begin_scene(0x22, player_mode);
    }
}

static inline void finish_entry(void)
{
    fn_801F85A4();
    if (!(lbl_80300368.entries[lbl_80300368.current].flags & 1)) {
        fn_801FA354();
    }
    if (lbl_80300368.entries[lbl_80300368.current].flags & 4) {
        fn_80046D38(1);
    }
    fn_80028B44();
    lbl_80300368.entries[lbl_80300368.current].state = 0;
    fn_8016B400(lbl_80300368.entries[lbl_80300368.current].object, 0, 0);
}

void fn_80028198(void)
{
    s32 player_mode = 2;
    s32 current = lbl_80300368.current;
    s32 old_phase = lbl_80300368.entries[current].phase;

    if (current != 0) {
        player_mode = 4;
    }
    lbl_80300368.entries[current].phase++;

    switch (lbl_80300368.entries[lbl_80300368.current].state) {
    case 1:
        lbl_80300368.entries[lbl_80300368.current].state = 0;
        fn_80027730(fn_801E6CA0(lbl_8064C500,
                               lbl_80300368.entries[lbl_80300368.current].valueC,
                               lbl_80300368.entries[lbl_80300368.current].value10,
                               0, 1),
                     lbl_80300368.entries[lbl_80300368.current].object, 0);
        break;

    case 2:
        switch (old_phase) {
        case 0:
            enable_object_flags();
            fn_801A5C30(0);
            activate_entry(player_mode, 1);
            break;
        case 1:
            fn_80027730(fn_801E6CA0(lbl_8064C500,
                                   lbl_80300368.entries[lbl_80300368.current].valueC,
                                   lbl_80300368.entries[lbl_80300368.current].value10,
                                   0, 1), -2, 0);
            reset_pair();
            break;
        case 2:
            enable_object_flags();
            fn_801A5C30(0);
            begin_scene(7, player_mode);
            break;
        case 3:
            fn_801A5C30(1);
            fn_801F85A4();
            if (!(lbl_80300368.entries[lbl_80300368.current].flags & 1)) {
                fn_801FA354();
            }
            if (lbl_80300368.entries[lbl_80300368.current].flags & 4) {
                fn_80046D38(1);
            }
            fn_80028B44();
            lbl_80300368.entries[lbl_80300368.current].state = 0;
            fn_8016B400(lbl_80300368.entries[lbl_80300368.current].object, 0, 0);
            break;
        }
        break;

    case 3:
        switch (old_phase) {
        case 0:
            enable_object_flags();
            fn_801A5C30(0);
            activate_entry(player_mode, 0);
            break;
        case 1:
            fn_80027730(fn_801E6CA0(lbl_8064C500,
                                   lbl_80300368.entries[lbl_80300368.current].valueC,
                                   lbl_80300368.entries[lbl_80300368.current].value10,
                                   0, 1), -2, 0);
            reset_pair();
            break;
        case 2:
            enable_object_flags();
            fn_801A5C30(0);
            begin_scene(0x13, player_mode);
            break;
        case 3: {
            void* object;
            s32 scene;
            s32 value1;
            s32 value2;

            object = fn_80201814(lbl_80300368.entries[lbl_80300368.current].value1C);
            scene = (s32)fn_80201C24(object);
            value1 = fn_80157BC4();
            value2 = fn_80157BF4(scene);
            object = fn_80201814(lbl_80300368.entries[lbl_80300368.current].value1C);
            if (object != 0) {
                fn_80205680(object, (void*)fn_80201B44(), 0x1E);
            }
            if (fn_8015821C(scene) == 0x1F &&
                !fn_801E79FC(lbl_8064C4E0, 0x10A)) {
                fn_801B05E8(0xC, 0x64, 6, 1, 0, 5, 0, 0);
            }
            object = (void*)fn_80201B44();
            fn_80027948(fn_801E6CA0(lbl_8064C504, value2, value1, 0, 1), -2, object,
                        lbl_80300368.entries[lbl_80300368.current].value1C,
                        0, 0, 0);
            break;
        }
        case 4:
            enable_object_flags();
            finish_entry();
            break;
        }
        break;
    }
}
