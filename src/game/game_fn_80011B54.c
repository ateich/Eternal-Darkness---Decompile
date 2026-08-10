typedef int s32;
typedef unsigned char u8;

typedef struct Type12Data {
    u8 pad_00[0x102];
    u8 value_102;
} Type12Data;

typedef struct ObjectInfo {
    u8 pad_00[0x54];
    Type12Data* data_54;
    u8 pad_58[0x47];
    u8 type;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201B8C();

s32 fn_80011B54(void* script)
{
    s32 handle;
    s32 value;
    void* parser;
    void* entry;
    ObjectInfo* object;

    parser = script;
    if (fn_8016A598(parser) != 2) {
        fn_80163BB4(parser, lbl_8023BEF8, 2, fn_8016A598(parser));
        return 0;
    }

    handle = (s32)fn_8016A694(parser, 1);
    value = (s32)fn_8016A694(parser, 2);
    entry = fn_80201814(handle);
    if (entry != 0) {
        object = fn_80201B8C(entry);
        if (object->type == 12) {
            object->data_54->value_102 = value;
        }
    }
    return 0;
}
