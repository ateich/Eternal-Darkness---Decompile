typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct LookupResult {
    u32 words[2];
} LookupResult;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158CC8(s32, s32, LookupResult*);
extern s32 fn_800382C0(void);
extern void fn_800CF46C(Vec3f*, LookupResult*, s32, s32, s32, u8, s32, u32);
extern char lbl_8023BEF8[];
char lbl_8023CD54[] = "Could not find marker %u\n";

s32 fn_8001C078(void* arg)
{
    LookupResult lookup;
    Vec3f position;
    s32 param3;
    s32 param4;
    u32 resource_id;
    s32 param2;
    s32 param5;
    s32 param6;
    u32 param7;
    s32 index;
    Vec3s* source;

    if (fn_8016A598(arg) != 7) {
        fn_80163BB4(arg, lbl_8023BEF8, 7, fn_8016A598(arg));
        return 0;
    }

    resource_id = fn_800F5C54(fn_8016A694(arg, 1));
    param2 = (s32)fn_8016A694(arg, 2);
    param3 = (s32)fn_8016A694(arg, 3);
    param4 = (s32)fn_8016A694(arg, 4);
    param5 = (s32)fn_8016A694(arg, 5);
    param6 = (s32)fn_8016A694(arg, 6);
    param7 = fn_800F5C54(fn_8016A694(arg, 7));

    index = fn_8015C4A4(resource_id, 2);
    if (index != -1) {
        source = fn_80158CC8(index, 2, &lookup);
    } else {
        fn_80163BB4(arg, lbl_8023CD54, resource_id);
    }

    position.x = source->x;
    position.y = source->y;
    position.z = source->z;
    if (fn_800382C0()) {
        fn_800CF46C(&position, &lookup, param3, param2, param4,
                    (u8)param5, param6, param7);
    }
    return 0;
}
