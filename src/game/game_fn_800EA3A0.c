typedef struct SlotState {
    int unused;
    int handles[3];
} SlotState;

typedef struct Object {
    unsigned char pad[0xDC];
    SlotState *slots;
} Object;

extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void fn_800EA0D0(void *);

void fn_800EA3A0(void *arg0, Object *object)
{
    void *context = (void *)fn_80201B54(arg0);
    int i;
    SlotState *slots = object->slots;

    if (slots != 0) {
        for (i = 0; i < 3; i++) {
            if (slots->handles[i] != 0) {
                fn_8020123C(0x39, context, slots->handles[i], 0);
                slots->handles[i] = 0;
            }
        }
        fn_800EA0D0(slots);
        object->slots = 0;
    }
}
