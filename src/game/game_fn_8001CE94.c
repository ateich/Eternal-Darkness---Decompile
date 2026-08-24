typedef int s32;

char lbl_8023CE68[20] = "EDCleanUpSubtitles";
char lbl_8023CE7C[32] = "EDStartSubtitlesForGhostMaid";
char lbl_8023CE9C[40] = "EDStartSubtitlesForInsanityPhoneCall";
char lbl_8023CEC4[28] = "EDStartSubtitleForEdward";
char lbl_8023CEE0[24] = "EDQueryPlayerOkToBrush";
char lbl_8023CEF8[36] = "EDStartSubtitlesForMikeDestroyThis";
char lbl_8023CF1C[36] = "EDStartSubtitlesForAlexClockPuzzle";

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_800E4558(s32);
extern char lbl_8023BEF8[];

s32 fn_8001CE94(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    value = fn_800E4558(value);
    fn_8016A830(script, (double)value);
    return 1;
}
