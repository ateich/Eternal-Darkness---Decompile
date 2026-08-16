typedef unsigned char u8;

typedef struct Flags800A45B0 {
    u8 pad_bits : 1;
    u8 active : 1;
    u8 remaining_bits : 6;
} Flags800A45B0;

typedef struct Object800A45B0 {
    u8 pad0[0x24c];
    int children[4];
    u8 pad25c[0x46];
    Flags800A45B0 flags;
} Object800A45B0;

extern void *fn_80201814();
extern int fn_800A44E0(Object800A45B0*, int);
extern void fn_802020B4(void*, int);

int fn_800A45B0(Object800A45B0* object, int child)
{
    void* resource;
    int count;

    resource = fn_80201814(child);
    count = 0;
    if (resource != 0) {
        count = fn_800A44E0(object, child);
        if (object->flags.active) {
            fn_802020B4(resource, 0);
        }
    }
    return count;
}
