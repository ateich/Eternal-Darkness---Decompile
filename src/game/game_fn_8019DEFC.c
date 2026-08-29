typedef unsigned char u8;
typedef signed short s16;

void fn_8019DEFC(u8* object)
{
    u8* state = object + 0x8C;
    s16 delta = 0;
    s16* timer = (s16*)state;
    int i = 0;

    while (i < object[1]) {
        state[i + 0x4F] = 0;
        if (timer[6] <= 0) {
            timer[6] = 0;
            delta -= state[0x71];
        } else {
            state[i + 0x4F] = 1;
        }
        timer++;
        i++;
    }
    *(s16*)(state + 0x4C) = delta;
}
