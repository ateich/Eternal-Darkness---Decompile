typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064C98C;
extern void* lbl_8064C988;
extern u8 lbl_8031D718[9];

extern void fn_801D19FC(void*, void*);
extern void *fn_80201814();
extern void fn_8014CBC0(void*);
extern void* fn_80205288(void*);
extern void* fn_80201C24();
extern int fn_800AD1D0(int);
extern void fn_80157B60(void*, u8);
extern void fn_80157B3C(void*, int);
extern void fn_800DBF60(void*, void*, int, void*, float);

void fn_800A7738(int enabled, u32 kind, float value)
{
    void* object;
    void* actor;
    int state;

    if (enabled == 0) {
        fn_801D19FC(lbl_8064C988, lbl_8031D718);
    } else {
        object = fn_80201814(lbl_8064C98C);
        fn_8014CBC0(lbl_8031D718);
        if (object != 0) {
            object = fn_80205288(object);
            if (object != 0) {
                actor = fn_80201C24();
                if (actor != 0) {
                    fn_80157B60(actor, fn_800AD1D0(0));
                    switch (kind) {
                    case 0x10000:
                        state = 2;
                        break;
                    case 0x20000:
                        state = 3;
                        break;
                    case 0x40000:
                        state = 4;
                        break;
                    }
                    fn_80157B3C(actor, state);
                    fn_800DBF60(lbl_8064C98C, object, state,
                                lbl_8031D718, value);
                }
            }
        }
    }
}
