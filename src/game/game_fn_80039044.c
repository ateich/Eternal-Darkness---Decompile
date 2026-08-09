typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u32 fn_801A74C0(void*);
extern void* fn_8004910C(void*);
extern void fn_80201E78(Vec3*, void*);
extern u32 fn_80038E5C(void*, void*, void*, Vec3*);
extern void* fn_80201B9C(void);
extern void* fn_80201BC0(void*);

u32 fn_80039044(void* source, void* target, void* effect)
{
    Vec3 position;
    Vec3 object_position;
    Vec3 source_position;
    Vec3* selected_position;
    void* object;
    void* current;
    u32 result = 0;
    u32 flags = fn_801A74C0(effect);

    object = fn_8004910C(effect);
    if (object != 0) {
        fn_80201E78(&object_position, object);
        selected_position = &object_position;
    } else {
        fn_80201E78(&source_position, source);
        selected_position = &source_position;
    }
    position = *selected_position;

    if (target != 0) {
        result = fn_80038E5C(source, target, effect, &position);
    }

    if ((flags & 1) != 0) {
        current = fn_80201B9C();
        while (current != 0) {
            if (current != target && current != source) {
                fn_80038E5C(source, current, effect, &position);
            }
            current = fn_80201BC0(current);
        }
    }

    return result;
}
