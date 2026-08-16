typedef unsigned char u8;

typedef struct Inner {
    u8 pad[0x5E];
    u8 active;
    u8 value;
} Inner;

typedef struct Owner {
    Inner *inner;
} Owner;

extern Owner *fn_80201B8C(void *);
extern void fn_8011E174(int, int);

void fn_800C61F8(void *context, int kind)
{
    Owner *owner;

    if (kind == 0x53) {
        owner = fn_80201B8C(context);
        if (owner->inner->active != 0) {
            fn_8011E174(8, 0);
        }
        owner->inner->value = 0;
    }
}
