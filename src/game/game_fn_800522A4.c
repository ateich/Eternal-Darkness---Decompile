typedef unsigned int u32;

typedef struct Entry {
    unsigned char pad[0x20];
    u32 flags;
} Entry;

typedef struct Object {
    unsigned char pad[0xC4];
    Entry* entry;
} Object;

extern int fn_8006D3E4(int mask, int value);
extern Object* fn_8006D444(void);
extern void *fn_80201B9C(void);
extern void fn_80204844(void* object, int value);

int fn_800522A4(void)
{
    int result = 0;
    Object* object;

    if (fn_8006D3E4(0x2000, 0) != 0) {
        fn_80204844(fn_80201B9C(), 0x20);

        object = fn_8006D444();
        if (object != 0 && (object->entry->flags & 0x10) != 0) {
            result = 1;
        }
    }

    return result;
}
