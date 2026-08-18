typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Set {
    u8 count;
    u8 pad1[7];
    u32 id;
    u8 padC[0x3C];
    u32 value48;
    u8 pad4C[0x3C];
    void* object88;
} Set;

typedef struct Value {
    float pad0, pad4;
    float x, y, z;
    u8 trailing[0x10];
} Value;

extern Set* fn_80156938(void*);
extern void *fn_80201BC8();
extern int fn_8011F6A4(void*, u32, u32, int, Value*, int);
extern short* fn_801938A8(void*);
extern void fn_8014B604(float*, short*);
extern u8 fn_80202160(Set*);
extern void fn_8017FF24(void*, int, int);

void fn_8014B33C(void* left, void* right)
{
    Set* entry;
    float* x;
    float* y;
    float* z;
    int count;
    int i;
    Set* right_set;
    Set* set;
    Value value;

    right_set = fn_80156938(right);
    set = fn_80156938(left);

    if (right_set != 0 && set != 0) {
        count = set->count;
        entry = set;
        x = &value.x;
        y = &value.y;
        z = &value.z;
        for (i = 0; i < count; i++) {
            if (entry->object88 != 0) {
                void* context = fn_80201BC8(right_set);
                if (context != 0) {
                    short* rotation;
                    fn_8011F6A4(context, entry->id, entry->value48,
                                -1, &value, 1);
                    rotation = fn_801938A8(entry->object88);
                    fn_8014B604(x, rotation);
                    fn_8014B604(y, rotation + 1);
                    fn_8014B604(z, rotation + 2);
                }
                if (fn_80202160(right_set) != 0) {
                    fn_8017FF24(entry->object88, 0, 8);
                } else {
                    fn_8017FF24(entry->object88, 8, 0);
                }
            }
            entry = (Set*)((char*)entry + 4);
        }
    }
}
