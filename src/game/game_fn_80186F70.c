typedef signed short s16;

#pragma use_lmw_stmw on

extern int fn_800FBFB0(void);

void fn_80186F70(s16* output, int count, int magnitude, float step, float base)
{
    s16* destination;
    int step_integer = (int)step;
    int range = magnitude;
    int sign = step_integer >> 31;

    if (((sign ^ step_integer) - sign) > range) {
        int index;

        destination = output;
        index = 0;
        while (index < count) {
            int value = fn_800FBFB0() % step_integer;
            if (step_integer < 0) {
                value = -value;
            }
            *destination = (s16)(base + (float)value);
            base += step;
            index++;
            destination++;
        }
    } else {
        int index;

        destination = output;
        index = 0;
        while (index < count) {
            int value = fn_800FBFB0() % range;
            if ((value & 1) != 0) {
                value = -value;
            }
            *destination = (s16)(base + (float)value);
            base += step;
            index++;
            destination++;
        }
    }
}
