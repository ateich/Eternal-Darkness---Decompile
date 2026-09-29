typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

void fn_801945D4(u8 width, u8 position, u32* output, const u32* first,
                 const u32* second, const u32* third)
{
    u8 inner = width - 4;
    s32 pos = position;

    switch (pos) {
    case 0: {
        u32 index = inner * 4;
        index += 3;
        output[0] = *first;
        output += index;
        *output = *first;
        return;
    }
    case 1: {
        u32 stride = inner * 4;

        output[1] = *second;
        output = output + 1;
        output += stride + 4;
        output[0] = *second;
        output[1] = *second;
        output += 2;
        *output = *second;
        output += stride + 3;
        output[0] = *second;
        output[1] = *second;
        return;
    }
    default:
        break;
    }

    if (pos == width - 1) {
        u32 index = inner * 2;
        index += 2;
        output += index;
        *output = *first;
        return;
    }

    if (pos == width - 2) {
        u32 row2 = inner * 2;
        u32 row4 = inner * 4;

        row2 += 3;
        output = output + row2;
        output[0] = *second;
        output += row4 + 5;
        output[0] = *second;
        output[1] = *second;
        return;
    }

    {
        u32 index = pos - 1;
        u32 offset;

        index *= 2;
        output = output + index;
        output[0] = *first;
        output++;
        output[0] = *second;
        offset = (inner - pos + 2) * 4 - 1;
        output += offset;
        output[0] = *first;
        output++;
        output[0] = *second;
        output += (pos - 2) * 4 + 5;
        output[0] = *second;
        output++;
        output[0] = *third;
        output += offset;
        output[0] = *second;
        output[1] = *third;
    }
}
