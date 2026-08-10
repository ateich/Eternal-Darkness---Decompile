typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_8014B888(s32, void**, s32*);
extern void fn_80198C8C(void*, s32, s32, s32, s32, s32);

s32 fn_80017ED0(void* script)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 fifth;
    void* object;
    s32 unused;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    fn_8014B888(first, &object, &unused);
    if (object != 0) {
        fn_80198C8C(object, second, third, fourth, fifth, 0);
    }
    return 1;
}
