typedef int s32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C504;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_801E6CA0(void*, s32, s32, s32, s32);
extern void fn_80027730(void*, s32, s32);

s32 fn_80017260(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    switch ((s32)fn_8016A694(script, 1)) {
    case 2:
        fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x2E, 0, 1), 0, 0);
        break;
    case 3:
        fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x2F, 0, 1), 0, 0);
        break;
    case 4:
        fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x30, 0, 1), 0, 0);
        break;
    case 5:
        fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x31, 0, 1), 0, 0);
        break;
    case 6:
        fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x32, 0, 1), 0, 0);
        break;
    }
    return 1;
}
