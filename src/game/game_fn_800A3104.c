typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A3104 {
    u8 pad00[0x84];
    u16 flags;
} Object800A3104;

extern int fn_800A30C0(Object800A3104*);

/*
 * Behavior-complete reconstruction. The retail TU inlined fn_800A30AC here
 * and retained its result in r0 before moving it to r31. With this function
 * split into an independent TU, MWCC coalesces that value directly into r31,
 * leaving the generated body four bytes shorter.
 */
int fn_800A3104(Object800A3104* object, int enabled)
{
    u16 old_value = object->flags & 1;

    if (fn_800A30C0(object) == 0) {
        if (enabled != 0) {
            object->flags |= 1;
        } else {
            object->flags &= ~1;
        }
    }
    return old_value;
}
