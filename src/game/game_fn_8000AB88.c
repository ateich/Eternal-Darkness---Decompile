typedef int s32;
typedef unsigned char u8;

typedef struct Entry {
    u8 pad0[8];
    struct Entry* child;
} Entry;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern Entry* fn_80201814(s32);
extern Entry* fn_80201B8C(Entry*);
extern void* fn_80201BC8(Entry*);
extern void fn_8005F8D0(s32, Entry*, void*, Entry*, Entry*, s32, s32, s32,
                       s32);

s32 fn_8000AB88(void* script)
{
    Entry* target;
    Entry* entry;
    s32 id;
    void* info;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }
    id = (s32)fn_8016A694(script, 1);
    entry = fn_80201814(id);
    if (entry != 0) {
        target = fn_80201B8C(entry);
    } else {
        target = 0;
    }
    if (entry != 0) {
        info = fn_80201BC8(entry);
    } else {
        info = 0;
    }
    if (info != 0 && target != 0) {
        fn_8005F8D0(id, entry, info, target, target->child, 0, 0, 0, 1);
    }
    return 0;
}
