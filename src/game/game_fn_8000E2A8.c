typedef unsigned char u8;
typedef int s32;

typedef struct ValueSet {
    s32 values[10];
} ValueSet;

typedef struct RuntimeState {
    u8 pad[0x68];
    ValueSet* values;
} RuntimeState;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(s32);
extern RuntimeState* fn_80201B8C(void);

s32 fn_8000E2A8(void* script)
{
    s32 object_id;
    s32 selector;
    s32 first;
    s32 second;
    RuntimeState* state;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    selector = (s32)fn_8016A694(script, 2);
    first = (s32)fn_8016A694(script, 3);
    second = (s32)fn_8016A694(script, 4);

    if (fn_80201814(object_id) != 0) {
        state = fn_80201B8C();
        switch (selector) {
        case 1:
            state->values->values[0] = first;
            break;
        case 2:
            state->values->values[1] = first;
            break;
        case 3:
            state->values->values[2] = first;
            state->values->values[3] = second;
            break;
        case 4:
            state->values->values[4] = first;
            state->values->values[5] = second;
            break;
        case 5:
            state->values->values[6] = first;
            state->values->values[7] = second;
            break;
        case 6:
            state->values->values[8] = first;
            state->values->values[9] = second;
            break;
        }
    }

    return 0;
}
