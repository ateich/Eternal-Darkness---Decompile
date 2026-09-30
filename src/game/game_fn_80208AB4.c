typedef signed int s32;
typedef unsigned int u32;

typedef void (*SIPollingHandler)(s32, u32);

extern SIPollingHandler lbl_80640D08[4];

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 enabled);
extern s32 fn_80208950(s32 enable);

s32 fn_80208AB4(SIPollingHandler handler)
{
    s32 interrupts;
    s32 i;

    interrupts = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        if (lbl_80640D08[i] == handler) {
            lbl_80640D08[i] = 0;

            for (i = 0; i < 4; i++) {
                if (lbl_80640D08[i] != 0) {
                    break;
                }
            }

            if (i == 4) {
                fn_80208950(0);
            }

            OSRestoreInterrupts(interrupts);
            return 1;
        }
    }

    OSRestoreInterrupts(interrupts);
    return 0;
}
