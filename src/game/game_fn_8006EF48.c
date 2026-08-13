typedef struct Owner {
    unsigned char pad_00[0xC4];
    void **config;
} Owner;

extern void fn_8006E3F8(void *owner);
extern void fn_8015C948(void *object, int a, int b, int c, int d, int e,
                       int f, int g, void (*callback)(void *), Owner *owner,
                       int enabled);

void fn_8006EF48(Owner *owner)
{
    fn_8015C948(owner->config[0x12], 0, 0, 0, 0, 1, 1, 0x11,
                fn_8006E3F8, owner, 1);
}
