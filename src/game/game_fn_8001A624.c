typedef int s32;

extern s32 lbl_8064C9FC;
extern const char lbl_8023CC30[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800B9454(s32, s32);

s32 fn_8001A624(void* script)
{
    switch (fn_8016A598(script)) {
    case 0:
        lbl_8064C9FC = 0;
        break;
    case 1:
        lbl_8064C9FC = (s32)fn_8016A694(script, 1);
        break;
    default:
        fn_80163BB4(script, lbl_8023CC30, fn_8016A598(script));
        break;
    }
    fn_800B9454(1, 0);
    return 0;
}
