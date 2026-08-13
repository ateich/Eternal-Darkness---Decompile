typedef unsigned char u8;
typedef int s32;

typedef struct Ref Ref;

typedef struct State {
    u8 pad[0x7C];
    s32 value;
} State;

typedef struct Object {
    State* state;
} Object;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201B8C();
extern char lbl_8023BEF8[];

s32 fn_8001C250(void* arg)
{
    Ref* ref = fn_80201814(fn_80201B44());
    s32 value;

    if (fn_8016A598(arg) != 1) {
        fn_80163BB4(arg, lbl_8023BEF8, 1, fn_8016A598(arg));
        return 0;
    }

    value = (s32)fn_8016A694(arg, 1);
    if (ref != 0) {
        Object* object = fn_80201B8C(ref);
        State* state = object != 0 ? object->state : 0;
        state->value = value;
    }
    return 0;
}
