typedef int s32;
typedef unsigned char u8;

typedef struct Type13Entry {
    s32 first;
    s32 clear_04;
    s32 second;
    s32 third;
    s32 clear_10;
    s32 unknown_14;
} Type13Entry;

typedef struct Type13Data {
    u8 pad_00[4];
    Type13Entry entries[1];
} Type13Data;

typedef struct ObjectInfo {
    u8 pad_00[0x64];
    Type13Data* data_64;
    u8 pad_68[0x37];
    u8 type;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201B8C();

s32 fn_80011CE0(void* script)
{
    s32 handle;
    s32 index;
    s32 first;
    s32 second;
    s32 third;
    void* parser;
    void* entry;
    ObjectInfo* object;
    Type13Entry* target;

    parser = script;
    if (fn_8016A598(parser) != 5) {
        fn_80163BB4(parser, lbl_8023BEF8, 5, fn_8016A598(parser));
        return 0;
    }

    handle = (s32)fn_8016A694(parser, 1);
    index = (s32)fn_8016A694(parser, 2);
    first = (s32)fn_8016A694(parser, 3);
    second = (s32)fn_8016A694(parser, 4);
    third = (s32)fn_8016A694(parser, 5);
    entry = fn_80201814(handle);
    if (entry != 0) {
        object = fn_80201B8C(entry);
        if (object->type == 13) {
            target = &object->data_64->entries[index];
            target->first = first;
            target->second = second;
            target->third = third;
            target->clear_04 = 0;
            target->clear_10 = 0;
        }
    }
    return 0;
}
