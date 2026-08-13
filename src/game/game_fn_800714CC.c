typedef unsigned char u8;
typedef short s16;

typedef struct State {
    int low;
    int high;
    u8 count;
    u8 enabled;
    s16 mode;
    int value;
} State;

typedef struct Config {
    char pad_00[0xC];
    int low;
    int high;
    char pad_14[8];
    int value;
} Config;

typedef struct Owner {
    char pad_00[0x15];
    u8 enabled;
    char pad_16[0xAE];
    Config *config;
} Owner;

typedef struct Entry {
    char pad_00[8];
    s16 count;
} Entry;

extern void *fn_80201B9C();
extern void *fn_80204844(void *, int);
extern Owner *fn_8006D444(void);
extern s16 fn_800891FC(void);
extern Entry *fn_8006D1DC(int);

void fn_800714CC(State *state)
{
    Owner *owner;
    Entry *entry;

    fn_80204844(fn_80201B9C(), 0x20);
    owner = fn_8006D444();
    if (owner != 0) {
        Config *config = owner->config;
        state->low = config->low;
        state->high = config->high;
        state->value = config->value;
        state->enabled = owner->enabled;
        state->mode = fn_800891FC();
    }
    entry = fn_8006D1DC(0xC);
    if (entry != 0) {
        state->count = entry->count;
    }
}
