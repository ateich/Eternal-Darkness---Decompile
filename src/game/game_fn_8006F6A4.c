typedef unsigned char u8;

typedef struct Owner {
    u8 pad_00[0x18];
    u8 name[0xAC];
    void *config;
} Owner;

typedef struct Config {
    u8 pad_00[0x20];
    unsigned int flags;
} Config;

typedef struct GlobalState {
    u8 pad_00[8];
    unsigned int level;
} GlobalState;

typedef struct Runtime {
    u8 pad_00[0x44];
    void *object;
} Runtime;

typedef struct ObjectInfo {
    u8 pad_00[0x8C];
    Runtime *owner;
} ObjectInfo;

extern GlobalState lbl_803003C8;
char lbl_80244394[] = "Ins: Timeline Visitation";

extern void fn_8004736C(int);
extern void fn_800719D8(void);
extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void fn_8006EDA0(void *, void *);
extern int fn_800E4834(void);
extern void fn_800E46CC(void);
extern int fn_800E5044(void);
extern void fn_800E4674(void);
extern void fn_80043708(int);
extern void fn_80042818(int);
extern void fn_8009E130(Owner *);
extern void fn_800FD40C(void *, const char *);

void fn_8006F6A4(Owner *owner)
{
    Config *config;
    int level;
    GlobalState *state;
    void *first;
    void *second;

    fn_8004736C(1);
    fn_800719D8();
    config = owner->config;
    if (config->flags & 4) {
        state = &lbl_803003C8;
        level = state->level;
        config->flags = ((config->flags >> 3) << 3) | (config->flags & 3);
        config->flags |= 0x4000;
        first = fn_80201814(fn_80201B44());
        second = fn_80201814(((ObjectInfo *)fn_80201B8C(first))->owner->object);
        fn_8006EDA0(first, second);
        if (fn_800E4834()) {
            fn_800E46CC();
            config->flags |= 0x80;
        }
        if (fn_800E5044()) {
            fn_800E4674();
            config->flags |= 0x40;
        }
        switch (state->level) {
        case 7:
            level = 10;
            break;
        case 10:
            level = 7;
            break;
        case 0:
            level = 0x13;
            break;
        case 5:
            level = 0;
            break;
        case 9:
            level = 5;
            break;
        }
        fn_80043708(level);
        fn_80042818(level);
    }
    config->flags |= 0x10;
    fn_8009E130(owner);
    fn_800FD40C(owner->name, lbl_80244394);
}
