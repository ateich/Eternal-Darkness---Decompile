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
extern void* fn_80201814();
extern void* fn_80201C24();
extern s32 fn_80157BC4(void);
extern s32 fn_80157BF4(s32);
extern int fn_80201B44(void);
extern void fn_80205680(void*, void*, s32);
extern s32 fn_8015821C(s32);
extern int fn_801E79FC(void*, int);
extern void fn_801B05E8(s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_80027948(void*, s32, void*, s32, s32, s32, s32, s32);

static void enable_object_flags(void)
{
    if (lbl_8064C4E4 != 0) {
        fn_80128F74(lbl_8064C4E4, fn_801290D0(lbl_8064C4E4) | 4);
    }
}

static void reset_pair(void)
{
    fn_801F8620();
    fn_801FA410(10);
    fn_801F7208(lbl_8063CD18 + 0x550, lbl_8064DFF0);
    fn_801F7208(lbl_8063C6B8 + 0x550, lbl_8064DFF0);
}

static void begin_scene(GameEntry* entry, s32 kind, s32 player_mode)
{
    fn_8011E310(2, kind, -2, entry->object, 0x32, player_mode, 1);
}

static void activate_entry(GameEntry* entry, s32 player_mode, s32 retry)
{
    void* camera = lbl_8063CD18 + 0x550;
    s32 ok;

    reset_pair();
    ok = fn_801FBEF0(lbl_8064C4E4, entry->value14, entry->flags & 1);
    if (!ok && retry) {
        ok = fn_801FC034(lbl_8064C4E4, entry->value14,
                        entry->flags & 1, lbl_8064DFF4);
    }
    if (ok) {
        entry->flags |= 4;
        entry->flags &= ~1;
    }
    if (entry->flags & 4) {
        fn_80046D38(0);
    }
    if (fn_800289A4(entry->value14, entry->flags & 1, 0)) {
        entry->flags &= ~1;
    }
    fn_801FA198(entry->value14, camera, 0, 0, entry->flags & 1,
                0, 0, 0, 0);
    if (entry->value10 < 0) {
        begin_scene(entry, 7, player_mode);
        entry->phase = 3;
    } else {
        begin_scene(entry, 0x22, player_mode);
    }
}

static void finish_entry(GameEntry* entry)
{
    fn_801F85A4();
    if (!(entry->flags & 1)) {
        fn_801FA354();
    }
    if (entry->flags & 4) {
        fn_80046D38(1);
    }
    fn_80028B44();
    entry->state = 0;
    fn_8016B400(entry->object, 0, 0);
}

void fn_80028198(void)
{
    GameEntry* entry = &lbl_80300368.entries[lbl_80300368.current];
    s32 old_phase = entry->phase++;
    s32 player_mode = lbl_80300368.current == 0 ? 2 : 4;

    switch (entry->phase) {
    case 1:
        entry->state = 0;
        fn_80027730(fn_801E6CA0(lbl_8064C500, entry->valueC,
                               entry->value10, 0, 1), entry->object, 0);
        break;

    case 2:
        switch (old_phase) {
        case 0:
            enable_object_flags();
            fn_801A5C30(0);
            activate_entry(entry, player_mode, 1);
            break;
        case 1:
            fn_80027730(fn_801E6CA0(lbl_8064C500, entry->valueC,
                                   entry->value10, 0, 1), -2, 0);
            reset_pair();
            break;
        case 2:
            enable_object_flags();
            fn_801A5C30(0);
            begin_scene(entry, 7, player_mode);
            break;
        case 3:
            fn_801A5C30(1);
            fn_801F85A4();
            if (!(entry->flags & 1)) {
                fn_801FA354();
            }
            if (entry->flags & 4) {
                fn_80046D38(1);
            }
            fn_80028B44();
            entry->state = 0;
            fn_8016B400(entry->object, 0, 0);
            break;
        }
        break;

    case 3:
        switch (old_phase) {
        case 0:
            enable_object_flags();
            fn_801A5C30(0);
            activate_entry(entry, player_mode, 0);
            break;
        case 1:
            fn_80027730(fn_801E6CA0(lbl_8064C500, entry->valueC,
                                   entry->value10, 0, 1), -2, 0);
            reset_pair();
            break;
        case 2:
            enable_object_flags();
            fn_801A5C30(0);
            begin_scene(entry, 0x13, player_mode);
            break;
        case 3: {
            void* object = fn_80201814(entry->value1C);
            s32 scene = (s32)fn_80201C24();
            s32 value1 = fn_80157BC4();
            s32 value2 = fn_80157BF4(scene);
            void* target = fn_80201814(entry->value1C);
            void* actor;
            if (target != 0) {
                fn_80205680(target, (void*)fn_80201B44(), 0x1E);
            }
            if (fn_8015821C(scene) == 0x1F &&
                !fn_801E79FC(lbl_8064C4E0, 0x10A)) {
                fn_801B05E8(0xC, 0x64, 6, 1, 0, 5, 0, 0);
            }
            actor = (void*)fn_80201B44();
            fn_801E6CA0(lbl_8064C504, value2, value1, 0, 1);
            fn_80027948(actor, -2, object, entry->value1C,
                        0, 0, 0, 0);
            break;
        }
        case 4:
            enable_object_flags();
            finish_entry(entry);
            break;
        }
        break;
    }
}
