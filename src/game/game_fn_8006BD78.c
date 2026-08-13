typedef signed int s32;
typedef unsigned char u8;
typedef unsigned long size_t;

typedef struct Owner {
    u8 bytes[0xC4];
    void *state;
} Owner;

extern void *memset(void *dest, s32 value, size_t size);

void fn_8006BD78(Owner *owner)
{
    u8 *state;
    s32 preserve = 0;
    u8 *work;

    state = owner->state;
    *(s32 *)(state + 0x14) = 0;
    work = state + 0x48;
    *(s32 *)(state + 0x18) = 0;
    if ((*(s32 *)(state + 0x20) & 0x20000) != 0) {
        preserve = 1;
    }
    *(s32 *)(state + 0x20) = 0;
    *(s32 *)(state + 0x38) = 0;
    *(s32 *)(owner->bytes + 4) = 0;
    memset(owner->bytes + 0x40, 0, 0x2C);
    memset(owner->bytes + 0x18, 0, 0x20);
    memset(work, 0, 0xF4);
    *(s32 *)(work + 0x54) = -1;
    *(s32 *)(work + 0x58) = -1;
    *(s32 *)(work + 0x5C) = -1;
    if (preserve != 0) {
        *(s32 *)(state + 0x20) |= 0x20000;
    }
}
