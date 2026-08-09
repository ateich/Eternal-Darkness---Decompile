typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_80032A5C(u8* state)
{
    u8 amount = state[0x26];
    s32 increasing = amount != 0;
    u8 target;
    s32 difference;
    s32 complete = 1;
    u32 step;
    s32 i;

    step = amount != 0 ? amount : state[0x27];

    for (i = 0; i < 11; i++, state += 0x24) {
        target = state[0x47];

        if (target != 0) {
            if (increasing) {
                difference = target - step;

                if (state[0x4B] < (u8)(0 > difference ? 0 : difference)) {
                    state[0x4B] += step;
                    complete = 0;
                } else {
                    state[0x4B] = target;
                }
            } else {
                if (state[0x4B] > step) {
                    state[0x4B] -= step;
                    complete = 0;
                } else {
                    state[0x4B] = 0;
                }
            }
        }
    }

    return complete;
}
