typedef unsigned char u8;

extern int lbl_8064D18C;

extern void fn_800EA3A0(void *object, void *event, void *state);
extern int fn_80035628(void *object);
extern int fn_80201EB8(void *object);
extern void fn_8019CFBC(void *value, int mode);
extern void fn_800BD2DC(void *object, void *event);

void fn_8007827C(void *object, void *event, void *state)
{
    fn_800EA3A0(object, event, state);
    if (fn_80035628(object) == 3 && fn_80201EB8(object) != lbl_8064D18C) {
        void *entry = *(void **)((u8 *)state + 0xC8);
        if (entry != 0) {
            fn_8019CFBC(*(void **)((u8 *)entry + 0x88), 0);
            *(void **)((u8 *)state + 0xC8) = 0;
        }
    }
    fn_800BD2DC(object, event);
}
