typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry800934A0 {
    u32 pad00[5];
    u32 value;
} Entry800934A0;

typedef struct ObjectState800934A0 {
    u8 pad00[0xCC];
    u32 entry_id;
} ObjectState800934A0;

typedef struct Runtime800934A0 {
    u8 pad00[0x8C];
    ObjectState800934A0* state;
} Runtime800934A0;

extern float lbl_8064EC7C;
extern float lbl_8064EC88;

extern int fn_80201B54(void*);
extern Runtime800934A0* fn_80201B8C(void*);
extern void* fn_801294DC(void*, int, int, int);
extern Entry800934A0* fn_800935CC(void*, void*, u32, int);
extern void fn_80128C28(void*, void (*)(void), int);
extern void fn_80204810(void);
extern void fn_80201138(int, void*, int, int, int, float);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);

void fn_800934A0(register void* object, register void* event, void* unused,
                 register int* result)
{
    register int kind;
    register ObjectState800934A0* state;
    register void* action;
    float value;

    kind = fn_80201B54(object);
    state = fn_80201B8C(object)->state;
    action = fn_801294DC(event, 143, 32, 8);
    if (action != 0) {
        Entry800934A0* entry = fn_800935CC(0, 0, state->entry_id, 4);
        if (entry != 0)
            value = (float)entry->value;
        else
            value = lbl_8064EC88;

        fn_80128C28(action, fn_80204810, (kind << 8) | 0xAB);
        if (value > lbl_8064EC7C)
            fn_80201138(5, object, 74, -1, 0, value);

        if (result != 0)
            *result = 1;
        fn_80201D2C(object, 74);
        fn_80201D14(object, 1);
    } else if (result != 0) {
        *result = 0;
    }
}
