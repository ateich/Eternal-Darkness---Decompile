typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct ObjectFlags {
    u8 pad_00[0x2C];
    s32 flags;
} ObjectFlags;

typedef struct ObjectInfo {
    u8 pad_00[0x68];
    ObjectFlags* object_flags;
    u8 pad_6C[0x20];
    s32* state_flags;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B8C();

s32 fn_8000DDAC(void* script)
{
    s32 object_id;
    s32 option;
    s32 enabled;
    void* entry;
    ObjectInfo* object;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    option = (s32)fn_8016A694(script, 2);
    enabled = (s32)fn_8016A694(script, 3);
    fn_8016A694(script, 4);
    entry = fn_80201814(object_id);
    if (entry != 0) {
        object = fn_80201B8C(entry);
        switch (option) {
        case 4:
            if (enabled != 0) {
                *object->state_flags |= 0x00800000;
            } else {
                *object->state_flags &= ~0x00800000;
            }
            break;
        case 0x20:
        case 0x40:
        case 0x400:
        case 0x1000:
            if (enabled != 0) {
                object->object_flags->flags |= option;
            } else {
                object->object_flags->flags &= ~option;
            }
            break;
        case 1:
            if (enabled != 0) {
                object->object_flags->flags |= 4;
            } else {
                object->object_flags->flags &= ~4;
            }
            break;
        case 2:
            if (enabled != 0) {
                *object->state_flags |= 0x400;
            } else {
                *object->state_flags &= ~0x400;
            }
            break;
        case 3:
            if (enabled != 0) {
                object->object_flags->flags |= 0x10;
            } else {
                object->object_flags->flags &= ~0x10;
            }
            break;
        }
    }
    return 0;
}
