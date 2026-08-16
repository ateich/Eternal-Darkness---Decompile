typedef unsigned char u8;

typedef struct Inner {
    u8 pad[0x5F];
    u8 value;
} Inner;

typedef struct Owner {
    Inner *inner;
} Owner;

extern void *fn_80201B3C(void);
extern void *fn_80201B8C();

int fn_800C5FA4(void)
{
    int result = 0;

    if (fn_80201B3C() != 0) {
        Owner *owner = ((Owner *)fn_80201B8C());
        if (owner->inner != 0) {
            result = owner->inner->value;
        }
    }
    return result;
}
