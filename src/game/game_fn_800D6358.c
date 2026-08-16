typedef struct Range {
    int start;
    int end;
    short length;
} Range;

int fn_800D6358(int kind, Range *range)
{
    int result = 3;

    switch (kind) {
    default:
        result = 0;
        break;
    case 16:
        range->start = 0;
        range->end = 90;
        range->length = range->end - range->start;
        break;
    case 4:
    case 6:
    case 8:
        range->start = 48;
        range->end = 69;
        range->length = 45;
        break;
    case 5:
    case 7:
    case 9:
        range->start = 48;
        range->end = 69;
        range->length = 45;
        break;
    case 78:
        range->start = 0;
        range->end = 60;
        range->length = range->end - range->start;
        break;
    }
    return result;
}
