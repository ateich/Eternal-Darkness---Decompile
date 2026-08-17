typedef signed char s8;
typedef unsigned char u8;

extern float lbl_806501D8;

int fn_8012DB28(u8* value, const s8* step, u8 limit)
{
    int complete = 0;

    if ((*step > 0 && *value >= limit) ||
        (*step < 0 && *value <= limit)) {
        complete = 1;
    }

    if (lbl_806501D8 != (float)*step && !complete) {
        int next = *value + *step;
        if ((*step > 0 && next >= limit) ||
            (*step < 0 && next <= limit)) {
            *value = limit;
            complete = 1;
        } else {
            *value = next;
        }
    }
    return complete;
}
