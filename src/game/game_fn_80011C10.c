typedef int s32;
typedef unsigned char u8;

typedef struct Type12Data {
    u8 pad_00[0xE4];
    s32 value_E4;
} Type12Data;

typedef struct Type13Data {
    u8 pad_00[0x1C];
    s32 value_1C;
} Type13Data;

typedef struct ObjectInfo {
    u8 pad_00[0x54];
    Type12Data* data_54;
    u8 pad_58[0x0C];
    Type13Data* data_64;
    u8 pad_68[0x37];
    u8 type;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B8C();

s32 fn_80011C10(void* script)
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
            object->data_54->value_E4 = value;
        } else if (object->type == 13) {
            object->data_64->value_1C = value;
        }
    }
    return 0;
}
