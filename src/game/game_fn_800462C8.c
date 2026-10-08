typedef signed int s32;
typedef unsigned int u32;

typedef struct Owner {
    unsigned char pad_00[0xC4];
    unsigned char *state;
} Owner;

extern void *fn_80201B9C(void);
extern void *fn_80204844(void *, s32);
extern Owner *fn_8006D444(void *);
extern s32 fn_8006BCE4(Owner *);

s32 fn_800462C8(s32 check_state)
{
    Owner *owner;
    void *object;
    unsigned char *state;
    s32 result;
    s32 kind;

    object = fn_80204844(fn_80201B9C(), 0x20);
    result = 0;
    if (object != 0) {
        owner = fn_8006D444(object);
        if (owner != 0) {
            kind = fn_8006BCE4(owner);
            state = owner->state;
            switch (kind) {
            case 4:
            case 9:
            case 11:
            case 12:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 22:
            case 23:
            case 25:
            case 26:
            case 28:
            case 29:
            case 30:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
                result = kind;
                break;
            case 13:
                result = kind;
                if ((check_state & 1) != 0 && (*(u32 *)(state + 0x20) & 4) != 0) {
                    result = 0;
                }
                break;
            }
        }
    }
    return result;
}
