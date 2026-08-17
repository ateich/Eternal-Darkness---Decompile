typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Range {
    u32 unused;
    u32 size;
    u32 start;
} Range;

typedef struct Object {
    char pad_0[0x3C];
    void* descriptor;
    char pad_40[0x120];
    char* entries;
} Object;

typedef struct Descriptor { char pad_0[8]; u16 count; } Descriptor;
typedef struct Entry { char pad_0[0x14]; u32 a; u32 b; char pad_1C[0x30]; } Entry;
typedef struct Runtime2 { void* value; } Runtime2;
typedef struct Runtime1 { char pad_0[4]; Runtime2* next; } Runtime1;
typedef struct Runtime { char pad_0[0xB8]; Runtime1* next; } Runtime;

extern Runtime* fn_80128E30(Object*);
extern u32 lbl_8064CFB4;

int fn_801353AC(Object* object, Range* range)
{
    int i;

    if (object != 0 && range != 0 && fn_80128E30(object)->next->next->value != 0) {
        for (i = 0; i < ((Descriptor*)object->descriptor)->count; i++) {
            Entry* entry = (Entry*)(object->entries + 4) + i;
            u32 a = entry->a;
            u32 b = entry->b;
            int a_inside = a >= range->start && a < range->start + range->size;
            int b_inside = b >= range->start && b < range->start + range->size;
            if (a_inside | b_inside) {
                lbl_8064CFB4 = 1;
                return 1;
            }
        }
        lbl_8064CFB4 = 0;
    }
    return 0;
}
