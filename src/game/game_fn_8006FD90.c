typedef unsigned char u8;

typedef struct Owner {
    u8 pad_00[0xC4];
    struct Config *config;
} Owner;

typedef struct Config {
    u8 pad_00[0x20];
    unsigned int flags;
} Config;

typedef struct GlobalState {
    u8 pad_00[8];
    int level;
} GlobalState;

extern GlobalState lbl_803003C8;

extern void *fn_80201B9C(void);
extern void *fn_80204844(void *, int);
extern Owner *fn_8006D444(void);
extern int fn_8006BCE4(Owner *);
extern void fn_800E46A0(void);
extern void fn_800E4648(void);
extern void fn_8015AA28(int);
extern void fn_80043708(int);
extern void fn_80042818(int);

void fn_8006FD90(void)
{
    Owner *owner;
    Config *config;

    if (fn_80204844(fn_80201B9C(), 0x20) != 0) {
        owner = fn_8006D444();
        if (owner != 0 && fn_8006BCE4(owner) == 0xD) {
            config = owner->config;
            if (config->flags & 0x80000) {
                if (config->flags & 0x80) {
                    fn_800E46A0();
                }
                if (config->flags & 0x40) {
                    fn_800E4648();
                }
                fn_8015AA28(0);
                fn_80043708(lbl_803003C8.level);
                fn_80042818(lbl_803003C8.level);
                config->flags = ((config->flags >> 20) << 20) |
                                (config->flags & 0x7FFFF);
            }
        }
    }
}
