typedef signed int s32;
typedef unsigned char u8;

typedef struct ObjectDefinition {
    u8 pad[0x9E];
    u8 category;
    u8 subtype;
} ObjectDefinition;

extern void *fn_80158598(s32 object_id, s32 index);
extern s32 fn_80157E1C(void *collection);
extern void *fn_80157E24(void *collection, s32 index);
extern void *fn_80201814(s32 object_id);
extern void *fn_80201BC8(void *object);
extern ObjectDefinition *fn_80201B8C(void *object);
extern void *fn_80201C24(void *object);
extern void fn_8012C478(void *state, s32 index, s32 enabled);
extern s32 fn_800CC2D8(void *state, s32 group);

void fn_80047080(s32 object_id)
{
    s32 index;
    void *collection;
    s32 count;
    void *object;
    void *state;
    ObjectDefinition *definition;

    collection = fn_80158598(object_id, 0);
    if (collection != 0) {
        count = fn_80157E1C(collection);
        for (index = 0; index < count; index++) {
            object = fn_80201814((s32)fn_80157E24(collection, index));
            if (object != 0) {
                state = fn_80201BC8(object);
                if (state != 0) {
                    definition = fn_80201B8C(object);
                    fn_8012C478(state, 15, 1);
                    if (definition->category == 4 && definition->subtype == 0x12) {
                        fn_80201C24(object);
                        if ((u8)fn_800CC2D8(state, 0)) {
                            fn_8012C478(state, 16, 0);
                        }
                        if ((u8)fn_800CC2D8(state, 1)) {
                            fn_8012C478(state, 17, 0);
                        }
                    }
                }
            }
        }
    }
}
