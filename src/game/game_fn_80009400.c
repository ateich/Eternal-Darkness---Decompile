typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8010F3DC(s32);

s32 fn_80009400(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    switch (value) {
    case 1:
        fn_8010F3DC(0x800);
        break;
    case 2:
        fn_8010F3DC(0x2000);
        break;
    case 3:
        fn_8010F3DC(0x1000);
        break;
    }
    return 0;
}
