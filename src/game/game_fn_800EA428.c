typedef struct SlotState {
    int unused;
    int handles[3];
    int values[3];
} SlotState;

typedef struct Object {
    unsigned char pad[0xDC];
    SlotState *slots;
} Object;

extern void *fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern int fn_80130670(void *, int, int);
extern void fn_8020123C(int, void *, int, int);

void fn_800EA428(void *arg0, Object *object, int value)
{
    void *context = fn_80201B54(arg0);
    SlotState *slots = object->slots;
    int i;

    if (slots != 0) {
        for (i = 0; i < 3; i++) {
            if (slots->handles[i] != 0) {
                void *current = fn_80201BC8(arg0);
                if (slots->values[i] == value ||
                    fn_80130670(current, slots->values[i], value) != 0) {
                    fn_8020123C(0x39, context, slots->handles[i], 0);
                    slots->handles[i] = 0;
                }
            }
        }
    }
}
