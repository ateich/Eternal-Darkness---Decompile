typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    void* object8C;
    u8 pad90[4];
    void* data94;
    u8 pad98[7];
    u8 value9F;
} ObjectInfo;

typedef struct NestedObject {
    u8 pad00[0x84];
    s32 value84;
    u8 pad88[0x34];
    s32 valueBC;
} NestedObject;

extern const u32 lbl_8064E164;
extern const u32 lbl_8064E168;
extern const u32 lbl_8064E16C;
extern const u32 lbl_8064E170;
extern const u32 lbl_8064E174;
extern const u32 lbl_8064E178;
extern const f32 lbl_8064E064;
extern const f32 lbl_8064E17C;
extern const u32 lbl_8065192C;
extern const u32 lbl_80651930;
extern const u32 lbl_80651934;

extern s32 fn_80200C10(void*);
extern int fn_80200C38(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern void* fn_80201BC8();
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern unsigned long long fn_8020123C();
extern void fn_8012C62C(void*, s32, u32*, u32*, u32*, s32);
extern void fn_80120AD0(s32, s32, s32, s32, f32, f32);
extern void fn_800CAC5C(u8, void*, u32*, u32*, u32*);
extern void fn_8012DBE8(void*, s32, u32*);

s32 fn_80031FE4(void* object, s32 action, void* event, s32* completed)
{
    u32 result2;
    u32 result1;
    u32 result0;
    u32 sample1;
    u32 sample0;
    u32 color0c;
    u32 color0b;
    u32 color0a;
    u32 color1c;
    u32 color1b;
    u32 color1a;
    u32 color2c;
    u32 color2b;
    u32 color2a;
    s32 event_id = fn_80200C10(event);
    ObjectInfo* info = fn_80201B8C(object);
    register s32 effect_id;
    register s32 object_id;
    object_id = fn_80201B54(object);
    effect_id = (s32)fn_80201BC8(object);

    if (action == 0) {
        if (event_id == 1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        if (event_id == 0x39) {
            NestedObject* nested = info->object8C;
            s32 value = nested->value84;
            if (value == 0x3F) {
                fn_8020123C(0xF0, object_id, object_id, value);
                fn_8020123C(0x39, object_id, object_id, 0);
            }
            return 1;
        }
        if (event_id == 0xD5) {
            ((NestedObject*)info->object8C)->valueBC = fn_80200C38(event);
            return 1;
        }
        if (event_id == 0xF0) {
            s32 value = fn_80200C38(event);
            fn_80201D34(object, value);
            fn_80201D1C(object, 1);
            if (completed != 0) {
                *completed = 1;
            }
            return 1;
        }
    } else if (action == 1) {
        if (event_id == 0x10) {
            fn_80201D2C(object, 10);
            fn_80201D14(object, 1);
            return 1;
        }
        if (event_id == 0x11) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (action == 10) {
        if (event_id == 1) {
            color0a = lbl_8064E168;
            color0b = lbl_8064E164;
            color0c = lbl_8065192C;
            fn_8012C62C((void*)effect_id, 15, &color0c, &color0b, &color0a, 4);
            fn_80120AD0(effect_id, 0, 100, 0x806, lbl_8064E064, lbl_8064E17C);
            return 1;
        }
        if (event_id == 0x3D) {
            color1a = lbl_8064E170;
            color1b = lbl_80651930;
            color1c = lbl_8064E16C;
            fn_8012C62C((void*)effect_id, 15, &color1c, &color1b, &color1a, 4);
            fn_800CAC5C(info->value9F, info->data94, &result2, &result1, &result0);
            fn_80201D34(object, result0);
            fn_80201D1C(object, 1);
            return 1;
        }
        if (event_id == 3) {
            fn_8012DBE8((void*)effect_id, 15, &sample1);
            if (((u8*)&sample1)[3] >= 0xFB) {
                fn_80201D34(object, ((NestedObject*)info->object8C)->value84);
                fn_80201D1C(object, 1);
            }
            return 1;
        }
    } else if (action == 11) {
        if (event_id == 1) {
            color2a = lbl_80651934;
            color2b = lbl_8064E178;
            color2c = lbl_8064E174;
            fn_8012C62C((void*)effect_id, 15, &color2c, &color2b, &color2a, 4);
            return 1;
        }
        if (event_id == 3) {
            fn_8012DBE8((void*)effect_id, 15, &sample0);
            if (((u8*)&sample0)[3] <= 10) {
                fn_80201D34(object, ((NestedObject*)info->object8C)->value84);
                fn_80201D1C(object, 1);
            }
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
