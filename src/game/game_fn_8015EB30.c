typedef struct Owner {
    unsigned char pad0[0x18];
    unsigned int* entries;
} Owner;

typedef struct Object {
    Owner* owner;
    unsigned char pad4[4];
    void* value;
} Object;

extern char lbl_8024F240[];
extern void fn_8015EA7C(void*, void*);

void fn_8015EB30(Object* object, int index, int end)
{
    unsigned int* entries = object->owner->entries;
    unsigned int* entry = &entries[index];
    int offset;

    if (end == -1) {
        *entry = (*entry & 0x3F) | 0x7FFFFF80;
    } else {
        offset = end - (index + 1);
        if ((offset < 0 ? -offset : offset) > 0x1FFFFFF)
            fn_8015EA7C(object->value, lbl_8024F240);
        *entry = (*entry & 0x3F) | ((offset + 0x1FFFFFF) << 6);
    }
}
