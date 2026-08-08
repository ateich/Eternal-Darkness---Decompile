typedef int s32;
typedef unsigned int u32;

typedef struct EventRecord {
    u32 words[8];
} EventRecord;

extern EventRecord lbl_8023DFD0[];
extern s32 lbl_8064C5E8;
extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;
extern s32 lbl_8064C704;

extern u32 fn_80144628(s32, EventRecord*, s32);
extern void fn_80144608(void);
extern void fn_80045B3C(s32);

void fn_80027730(u32 value, s32 next)
{
    lbl_8023DFD0[0].words[3] = value;
    lbl_8023DFD0[1].words[3] = value;
    lbl_8023DFD0[2].words[3] = value;
    lbl_8064C700 = -1;
    lbl_8064C6F8 = fn_80144628(3, lbl_8023DFD0, 0);
    fn_80144608();
    if (lbl_8064C5E8 != 3) {
        fn_80045B3C(1);
    }
    lbl_8064C704 = next;
}
