typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

typedef struct BoundaryEntry {
    u16 type;
    u16 pad02;
    const void* data;
} BoundaryEntry;

typedef struct Boundary {
    u8 pad00[0x24];
    s8 flags;
    u8 pad25[3];
    u16 type;
    u8 pad2A[2];
    const void* data;
    s8 count;
    u8 pad31[3];
    const BoundaryEntry* entries;
} Boundary;

extern u8 fn_8013D36C(const void*, u16, const void*, const void*, s8);

int fn_8013D560(const void* point, const Boundary* boundary,
                const void* context)
{
    int offset;
    s8 i;
    register const void* saved_context;
    register const Boundary* saved_boundary;
    register const void* saved_point;

    /* ASM: the three mr instructions establish the retail long-lived argument
       copies in reverse parameter order; C scheduling reverses the first two. */
    asm {
        mr saved_context, r5
        mr saved_boundary, r4
        mr saved_point, r3
    }

    if (fn_8013D36C(saved_point, saved_boundary->type, saved_boundary->data,
                    saved_context, saved_boundary->flags)) {
        i = 0;
        offset = 0;
        while (i < saved_boundary->count) {
            const BoundaryEntry* entry =
                (const BoundaryEntry*)((const u8*)saved_boundary->entries + offset);
            if (fn_8013D36C(saved_point, entry->type, entry->data, saved_context,
                            saved_boundary->flags)) {
                return 0;
            }
            offset += sizeof(BoundaryEntry);
            i++;
        }
        return 1;
    }
    return 0;
}
