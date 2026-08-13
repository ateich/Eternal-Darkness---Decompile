typedef unsigned short u16;

typedef struct Entry {
    int type;
    char pad_04[6];
    u16 state;
    char pad_0C[0xC];
    unsigned int flags;
} Entry;

typedef struct Owner {
    int pad_00;
    Entry *entry;
    char pad_08[0xBC];
    void *config;
} Owner;

extern void *fn_80201B9C(void);
extern void *fn_80204844(void *, int);
extern Owner *fn_8006D444(void);

int fn_80071258(void)
{
    int result = 0;
    Owner *owner;

    if (fn_80204844(fn_80201B9C(), 0x20) != 0) {
        owner = fn_8006D444();
        if (owner != 0 && owner->config != 0 && owner->entry != 0 &&
            (owner->entry->flags & 0x100) != 0 && owner->entry->state == 4) {
            result = 1;
        }
    }
    return result;
}
