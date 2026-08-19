typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Set {
    u8 count;
    u8 pad1[7];
    u32 id;
    u8 padC[0x3C];
    int value48;
    u8 pad4C[0x3C];
    void* objects[16];
} Set;

extern void *fn_80156938();
extern short* fn_801938A8(void*);
extern void fn_801534D8(Set*, short*, float);

void fn_8014AF38(void* left, void* right)
{
    Set* entry;
    int count;
    int i;
    Set* left_set;
    Set* right_set;

    right_set = fn_80156938(right);
    left_set = fn_80156938(left);
    count = left_set->count;
    entry = left_set;

    for (i = 0; i < count; i++) {
        float fraction = (float)entry->value48 / (float)(left_set->count - 1);
        short* rotation = fn_801938A8(entry->objects[0]);
        fn_801534D8(right_set, rotation, fraction);
        entry = (Set*)((char*)entry + 4);
    }
}
