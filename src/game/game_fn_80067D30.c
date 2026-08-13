typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

typedef struct RuntimeSlot {
    u8 data[0xFC];
    s32 sound;
    u8 reserved[10];
    u8 kind;
    s8 active;
    u8 tail[4];
} RuntimeSlot;

typedef struct ObjectState {
    s32 unused;
    RuntimeSlot **installed;
} ObjectState;

extern s32 lbl_8064C548;
extern void *fn_80201B8C();
extern void fn_801AC980(s32 handle, s32 fade);

void fn_80067D30(void *object)
{
    ObjectState *state = fn_80201B8C(object);
    RuntimeSlot **installed = state != 0 ? state->installed : 0;

    if ((u32)((*installed)->sound + 0x10000) != 0xFFFF) {
        fn_801AC980((*installed)->sound, 30);
    }
    lbl_8064C548 = (*installed)->active;
    (*installed)->sound = -1;
}
