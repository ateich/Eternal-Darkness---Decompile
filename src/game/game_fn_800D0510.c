typedef struct Range {
    int first;
    int last;
    unsigned short width;
} Range;

int fn_800D0510(int kind, Range *range)
{
    int result = 3;

    switch (kind) {
    default:
        result = 0;
        break;
    case 16:
        range->first = 48;
        range->last = 85;
        range->width = range->last + 20 - range->first;
        break;
    case 78:
        range->first = 13;
        range->last = 43;
        range->width = range->last + 20 - range->first;
        break;
    }

    return result;
}
