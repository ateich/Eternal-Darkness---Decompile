typedef unsigned char u8;
typedef int s32;

typedef struct ObjectState {
    u8 pad0[0x1C0];
    u8 active;
} ObjectState;

typedef struct Object {
    u8 pad0[0x44];
    ObjectState* state;
    u8 pad48[0x57];
    u8 type;
} Object;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void *fn_80201814();
extern void *fn_80201B8C();

s32 fn_8000F38C(void* script)
{
    void* entity;
    Object* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    entity = fn_80201814((s32)fn_8016A694(script, 1));
    if (entity != 0) {
        object = fn_80201B8C(entity);
        if (object->type == 5) {
            object->state->active = 1;
        }
    }
    return 0;
}
