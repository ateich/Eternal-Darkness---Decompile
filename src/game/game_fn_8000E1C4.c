typedef unsigned char u8;
typedef int s32;

typedef struct ValueOwner {
    u8 pad[0x28];
    s32 value;
} ValueOwner;

typedef struct PrimaryOwner {
    u8 pad[0x60];
    s32 value;
} PrimaryOwner;

typedef struct RuntimeState {
    PrimaryOwner* primary;
    u8 pad_04[0x64];
    ValueOwner* secondary;
    u8 pad_6C[0x32];
    u8 use_primary;
} RuntimeState;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern void* fn_80201814();
extern void* fn_80201B8C();

s32 fn_8000E1C4(void* script)
{
    s32 value = 0;
    RuntimeState* state;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    if (fn_80201814((s32)fn_8016A694(script, 1)) != 0) {
        state = fn_80201B8C();
        if (state->use_primary == 1) {
            value = state->primary->value;
        } else if (state->secondary != 0) {
            value = state->secondary->value;
        }
    }

    fn_8016A830(script, (double)value);
    return 1;
}
