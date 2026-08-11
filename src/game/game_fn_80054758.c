typedef signed int s32;

#pragma use_lmw_stmw on

extern void fn_80052424(s32, s32, s32, s32);
extern void fn_80052580(s32, s32, s32, s32, s32);

s32 fn_80054758(s32 mode)
{
    s32 transition_types[12] = {
        -1, -1, -1, -1, 0x29, -1,
        0x34, -1, 0x39, -1, -1, 0x3B
    };
    s32 started = 0;
    s32 transition_type = transition_types[mode];

    if (transition_type != -1) {
        fn_80052580(2, (short)transition_type, 1, 1, 0);
        started = 1;
    } else if (mode != 0 && mode != 1) {
        fn_80052424(0x82, -1, 0, 0);
    }

    return started;
}
