typedef unsigned int u32;

typedef void (*Callback)(void);

typedef struct CallbackDescriptor {
    u32 type;
    u32 flags;
    Callback callback;
    u32 value;
    u32 parameter;
    u32 reserved[3];
} CallbackDescriptor;

extern void fn_80048ADC(void);
extern void fn_80048B24(void);

/* Callback descriptors used by the game-state variable handlers. */
#pragma force_active on
CallbackDescriptor lbl_8023EE40[2] = {
    {0x00030000, 1, fn_80048ADC, 0, 100, {0, 0, 0}},
    {0x000C0000, 1, fn_80048B24, 0, 100, {0, 0, 0}},
};
#pragma force_active reset
