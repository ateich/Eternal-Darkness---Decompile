typedef int s32;

typedef struct Inner {
    void* unk0;
    s32 value;
} Inner;

typedef struct Outer {
    void* unk0;
    Inner* inner;
} Outer;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(s32);
extern Outer* fn_80201B8C(void*);

s32 fn_8000D978(void* script)
{
    s32 object_id;
    s32 value;
    void* object;
    Outer* outer;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    value = (s32)fn_8016A694(script, 2);
    object = fn_80201814(object_id);
    if (object != 0) {
        outer = fn_80201B8C(object);
    } else {
        outer = 0;
    }
    if (object != 0 && outer != 0 && outer->inner != 0) {
        outer->inner->value = value;
    }
    return 0;
}
