typedef struct SlotState {
    int unused;
    int handles[3];
    int values[3];
    int ages[3];
} SlotState;

typedef struct Object {
    unsigned char pad[0xDC];
    SlotState *slots;
} Object;

extern void *fn_80201B54(void *);
extern int fn_80200C20(void *);
extern void fn_80201814(int);
extern SlotState *fn_800EA08C(void);
extern void fn_8020123C(int, void *, int, int);
extern int lbl_8064D5A8;

void fn_800EA0FC(void *arg0, Object *object, int value, void *id, int *result)
{
    void *context = fn_80201B54(arg0);
    int converted = fn_80200C20(id);
    SlotState *slots;
    int oldest;
    int empty;
    int selected;
    int first;
    int i;

    fn_80201814(converted);
    slots = object->slots;
    empty = 0;
    selected = -1;
    first = 1;
    if (slots == 0) {
        slots = fn_800EA08C();
        if (slots != 0) {
            object->slots = slots;
        } else if (result != 0) {
            *result = 0;
        }
    }

    if (slots != 0) {
        for (i = 0; i < 3; i++) {
            if (slots->handles[i] == 0) {
                selected = i;
                empty = 1;
                break;
            }
            if (first || slots->ages[i] < oldest) {
                oldest = slots->ages[i];
                selected = i;
                first = 0;
            }
        }
        if (!empty) {
            fn_8020123C(0x39, context, slots->handles[selected], 0);
        }
        slots->handles[selected] = converted;
        slots->values[selected] = value;
        slots->ages[selected] = lbl_8064D5A8;
        if (result != 0) {
            *result = 1;
        }
    }
}
