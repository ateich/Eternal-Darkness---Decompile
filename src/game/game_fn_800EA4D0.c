typedef struct SlotState {
    int unused;
    int handles[3];
} SlotState;

typedef struct Object {
    unsigned char pad[0xDC];
    SlotState *slots;
} Object;

typedef struct Wrapper {
    unsigned char pad[0x8C];
    Object *object;
} Wrapper;

extern void *fn_80201814(void *);
extern Wrapper *fn_80201B8C(void *);
extern void fn_8020123C(int, void *, int, int);

void fn_800EA4D0(void *context, int handle)
{
    SlotState *slots;
    int i;

    slots = fn_80201B8C(fn_80201814(context))->object->slots;
    for (i = 0; i < 3; i++) {
        if (slots->handles[i] == handle) {
            fn_8020123C(0x39, context, handle, 0);
            slots->handles[i] = 0;
        }
    }
}
