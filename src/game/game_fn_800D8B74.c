typedef unsigned short u16;

typedef struct RangeDescriptor {
    int minimum;
    int maximum;
    u16 span;
} RangeDescriptor;

int fn_800D8B74(int kind, RangeDescriptor *range)
{
    int result = 3;

    switch (kind) {
    default:
        result = 0;
        break;
    case 15:
    case 16:
        range->minimum = 44;
        range->maximum = 120;
        range->span = range->maximum - range->minimum;
        break;
    case 4:
        range->minimum = 50;
        range->maximum = 78;
        range->span = 55;
        break;
    case 5:
        range->minimum = 1;
        range->maximum = 180;
        range->span = range->maximum - range->minimum;
        break;
    case 78:
        range->minimum = 108;
        range->maximum = 142;
        range->span = 55;
        break;
    }
    return result;
}
