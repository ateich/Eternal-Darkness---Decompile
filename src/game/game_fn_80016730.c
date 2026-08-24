typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800542D0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32);

s32 fn_80016730(void* script)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 fifth;
    s32 sixth;
    s32 seventh;
    s32 eighth;
    s32 ninth;
    s32 tenth;
    s32 eleventh;
    s32 twelfth;
    s32 thirteenth;

    if (fn_8016A598(script) != 13) {
        fn_80163BB4(script, lbl_8023BEF8, 13, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);
    seventh = (s32)fn_8016A694(script, 7);
    eighth = (s32)fn_8016A694(script, 8);
    ninth = (s32)fn_8016A694(script, 9);
    tenth = (s32)fn_8016A694(script, 10);
    eleventh = (s32)fn_8016A694(script, 11);
    twelfth = (s32)fn_8016A694(script, 12);
    thirteenth = (s32)fn_8016A694(script, 13);
    fn_800542D0(first, second, third, fourth, fifth, sixth, seventh, eighth,
                ninth, tenth, eleventh, twelfth, thirteenth);
    return 0;
}
