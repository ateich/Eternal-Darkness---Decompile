typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    void *value;
    u8 bytes[6];
    u16 state;
    u8 tail[0x18];
} Entry;

typedef struct Owner {
    u8 bytes[0x14];
    u8 count;
    u8 mode;
    u8 pad[0x22];
    void *context;
} Owner;

extern Entry *lbl_8064C8D4;
extern s32 fn_80071AD4(void *value, u8 mode, void *context);

void fn_8006C89C(Owner *owner)
{
    s32 i;
    Entry *entry;
    u8 count;
    u16 active = 3;
    u16 inactive = 0;

    entry = lbl_8064C8D4;
    count = owner->count;
    for (i = 0; i < count; entry++, i++) {
        s32 found = fn_80071AD4(entry->value, owner->mode, owner->context);
        if (entry->state == 0 && found != 0) {
            entry->state = active;
        } else if (entry->state == 3 && found == 0) {
            entry->state = inactive;
        }
    }
}
