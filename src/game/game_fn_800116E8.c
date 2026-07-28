typedef int s32;
typedef unsigned char u8;

typedef struct ObjectInfo {
    u8 pad_00[0x0C];
    void* data_0C;
    u8 pad_10[0x44];
    void* data_54;
    u8 pad_58[0x0C];
    void* data_64;
    u8 pad_68[0x37];
    u8 type;
} ObjectInfo;

typedef struct Type7Data {
    u8 pad_00[0x34];
    s32 value_34;
} Type7Data;

typedef struct Type12Data {
    u8 pad_00[0xEC];
    s32 value_EC;
} Type12Data;

typedef struct Type13Data {
    u8 pad_00[0x4C];
    s32 value_4C;
} Type13Data;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern ObjectInfo* fn_80201B8C(void*);

s32 fn_800116E8(void* script)
{
    s32 handle;
    s32 value;
    void* entry;
    ObjectInfo* object;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    handle = (s32)fn_8016A694(script, 1);
    value = (s32)fn_8016A694(script, 2);
    entry = fn_80201814(handle);
    if (entry != 0) {
        object = fn_80201B8C(entry);
        if (object->type == 7) {
            ((Type7Data*)object->data_0C)->value_34 = value;
        } else if (object->type == 12) {
            ((Type12Data*)object->data_54)->value_EC = value;
        } else if (object->type == 13) {
            ((Type13Data*)object->data_64)->value_4C = value;
        }
    }
    return 0;
}
