typedef unsigned short u16;
typedef int s32;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_800F5C54(double);
extern u16 fn_800289A4(void*, s32, s32);
extern void fn_801FA198(void*, void*, s32, s32, s32, s32, s32, s32, s32);
extern char lbl_8023BEF8[];
extern char lbl_8063CD18[];

s32 fn_8001CFB8(void* script)
{
    s32 second;
    s32 fourth;
    s32 fifth;
    s32 third;
    void* first;
    s32 sixth;

    if (fn_8016A598(script) != 6) {
        fn_80163BB4(script, lbl_8023BEF8, 6, fn_8016A598(script));
        return 0;
    }

    first = fn_800F5C54(fn_8016A694(script, 1));
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);

    if (fn_800289A4(first, fourth, sixth) != 0) {
        fourth = 0;
    }

    fn_801FA198(first, lbl_8063CD18 + 0x110, second, third, fourth, 0, 0, fifth, 0);
    return 0;
}
