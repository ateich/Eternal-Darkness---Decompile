typedef int s32;
typedef unsigned int u32;

typedef struct Name {
    u32 words[3];
} Name;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80179DB0(Name*, void*);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8011EB04(void*);
extern s32 fn_8012FF34(void*, Name*, s32, s32);
extern void fn_801302BC(void*, s32);
extern void fn_8013037C(void*, float);
extern void fn_801302FC(void*, u32);

s32 fn_80008D24(void* script)
{
    s32 valid = 1;
    s32 actor;
    Name name;
    s32 value;
    float scale;
    void* object;
    s32 flags;
    s32 stage;
    void* name_arg;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    actor = (s32)fn_8016A694(script, 1);
    name_arg = fn_8016A784(script, 2);
    fn_80179DB0(&name, name_arg);
    value = (s32)fn_8016A694(script, 3);
    scale = (float)fn_8016A694(script, 4);
    flags = (s32)fn_8016A694(script, 5);

    fn_80201814(actor);
    object = fn_80201BC8();

    stage = fn_8011EB04(object);
    switch (stage) {
    case 28:
    case 79:
    case 80:
        valid = 0;
        break;
    }

    if (valid != 0 && fn_8012FF34(object, &name, 4, 5) != 0) {
        fn_801302BC(object, value);
        fn_8013037C(object, scale);
        fn_801302FC(object, flags & 0xFFFF);
    }

    return 0;
}
