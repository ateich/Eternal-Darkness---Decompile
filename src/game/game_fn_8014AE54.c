typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Set {
    u8 count;
    u8 pad1[7];
    u32 id;
    u8 padC[0x3C];
    u32 value48;
    u8 pad4C[0x3C];
    void* objects[16];
} Set;

typedef struct Vec {
    float pad0, pad4;
    float x, y, z;
    u8 trailing[0x10];
} Vec;

extern Set* fn_80156938(void*);
extern void *fn_80201BC8();
extern u8 fn_801938A0(void*);
extern void fn_8011F6A4(void*, u32, u32, int, Vec*, int);
extern short* fn_8017FDE4(void*);
extern void fn_8014B604(float*, short*);

void fn_8014AE54(void* left, void* right)
{
    Set* entry;
    float* x;
    float* y;
    float* z;
    int i;
    int count;
    Set* right_set;
    Set* set;
    Vec value;

    right_set = fn_80156938(right);
    set = fn_80156938(left);
    count = set->count;

    if (set != 0) {
        entry = set;
        x = &value.x;
        y = &value.y;
        z = &value.z;
        for (i = 0; i < count; i++) {
            void* object = entry->objects[0];
            void* context = fn_80201BC8(right_set);
            short* position;

            fn_8011F6A4(context, entry->id, entry->value48,
                        fn_801938A0(object) - 1, &value, 1);
            position = fn_8017FDE4(object);
            fn_8014B604(x, position);
            fn_8014B604(y, position + 1);
            fn_8014B604(z, position + 2);
            entry = (Set*)((char*)entry + 4);
        }
    }
}
