typedef unsigned int u32;

typedef struct Vec3_80092FA4 {
    float x, y, z;
} Vec3_80092FA4;

typedef struct State80092FA4 {
    u32 flags;
    unsigned char pad04[0xC8];
    u32 entry_id;
} State80092FA4;

typedef struct Entry80092FA4 {
    u32 id;
    Vec3_80092FA4 position;
} Entry80092FA4;

#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS Vec3_80092FA4*, void*
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern Entry80092FA4* fn_800935CC(int, Vec3_80092FA4*, u32, int);
extern unsigned int fn_80178E94(Vec3_80092FA4*, Vec3_80092FA4*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_80092FA4(register void* object, void* unused,
                register State80092FA4* state)
{
    Vec3_80092FA4 query_position;
    Vec3_80092FA4 object_position;
    register Entry80092FA4* entry;
    int result = 0;

    if (!(state->flags & 0x400)) {
        fn_80201E78(&object_position, object);
        query_position = object_position;
        entry = fn_800935CC(0, &query_position, state->entry_id, 4);
        if (entry != 0)
            fn_80178E94(&query_position, &entry->position);

        if (entry != 0) {
            fn_80201D2C(object, 0x3E);
            fn_80201D14(object, 1);
            result = 1;
        } else {
            entry = fn_800935CC(0, &query_position, 0, 1);
            if (entry != 0) {
                state->entry_id = entry->id;
                fn_80201D2C(object, 0x3E);
                fn_80201D14(object, 1);
                result = 1;
            }
        }
    }
    return result;
}
