typedef unsigned char u8;

typedef struct Config {
    u8 pad_00[0x20];
    int flags;
} Config;

typedef struct Owner {
    u8 pad_00[0xC4];
    Config *config;
} Owner;

int fn_80070AAC(Owner *owner)
{
    if (owner != 0 && owner->config != 0) {
        return owner->config->flags;
    }
    return 0;
}
