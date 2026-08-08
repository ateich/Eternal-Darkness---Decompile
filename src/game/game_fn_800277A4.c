typedef int s32;
typedef unsigned int u32;

typedef struct EventRecord {
    u32 words[8];
} EventRecord;

extern EventRecord lbl_8023DFD0[];
extern s32 lbl_8064C704;
extern void fn_80027640(s32, u32);

void fn_800277A4(void)
{
    u32 value = lbl_8023DFD0[0].words[3];
    lbl_8064C704 = 0;
    fn_80027640(1, value);
}
