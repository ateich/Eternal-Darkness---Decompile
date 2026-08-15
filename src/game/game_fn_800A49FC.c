typedef struct Value800A49FC {
    int value;
} Value800A49FC;

extern int fn_800A4A90(void*, int);
extern void fn_800A4AC4(void*, int, int, int);

void fn_800A49FC(void* object, Value800A49FC* slot, void* context)
{
    if (slot->value != -1) {
        int value = fn_800A4A90(context, slot->value);
        fn_800A4AC4(object, slot->value, value, 1);
        slot->value = -1;
    }
}
