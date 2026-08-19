typedef struct Owner {
    unsigned char pad0[0x18];
    unsigned int* entries;
} Owner;

typedef struct Object {
    Owner* owner;
    unsigned char pad4[0xC];
    int current;
} Object;

extern int fn_8015EE94(Object*);
extern void fn_8015EC60(Object*, int);

void fn_8015EED8(Object* object, int value)
{
    if (fn_8015EE94(object)) {
        Owner* owner;
        int index;
        unsigned int shifted;
        unsigned int* entry;

        owner = object->owner;
        shifted = value << 6;
        index = object->current;
        entry = &owner->entries[index];
        entry[-1] = shifted | (entry[-1] & ~0x7FC0U);
        fn_8015EC60(object, value);
    }
}
