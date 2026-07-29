typedef int s32;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BED8[];
extern s32 fn_8016A598(void*);
extern s16* fn_8016A784(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void fn_80152838(Vec3f*, Vec3f*, s32);

s32 fn_80016270(void* script)
{
    const char* errors = lbl_8023BED8;
    s16* start_position;
    s16* offset;
    Vec3f start;
    Vec3f end;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, errors + 0x20, 2, fn_8016A598(script));
        return 0;
    }

    start_position = fn_8016A784(script, 1);
    offset = fn_8016A784(script, 2);
    if (start_position == 0) {
        fn_80163BB4(script, errors + 0xC34, 0);
    }
    if (offset == 0) {
        fn_80163BB4(script, errors + 0xC74, 0);
    }

    start.x = start_position[0];
    start.y = start_position[1];
    start.z = start_position[2];
    end.x = start.x + offset[0];
    end.y = start.y + offset[1];
    end.z = start.z + offset[2];
    fn_80152838(&start, &end, 4);
    return 0;
}
