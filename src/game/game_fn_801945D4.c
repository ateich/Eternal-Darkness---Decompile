typedef unsigned char u8;
typedef unsigned int u32;

void fn_801945D4(u8 width, u8 position, u32* output, const u32* first,
                 const u32* second, const u32* third)
{
    u8 inner = width - 4;

    switch (position) {
    case 0:
        output[0] = *first;
        output[(u8)(inner * 4) + 3] = *first;
        return;
    case 1: {
        u32* p;
        u8 stride = inner * 4;

        output[1] = *second;
        p = output + 1 + stride + 4;
        p[0] = *second;
        p[1] = *second;
        p[2] = *second;
        p[2] = *second;
        p += stride + 2;
        p[0] = *second;
        p[1] = *second;
        return;
    }
    default:
        break;
    }

    if (position == width - 1) {
        output[(u8)(inner * 2) + 2] = *first;
        return;
    }

    if (position == width - 2) {
        u32* p;
        u8 row2 = inner * 2;
        u8 row4 = inner * 4;

        p = output + row2 + 3;
        p[0] = *second;
        p += row4 + 5;
        p[0] = *second;
        p[1] = *second;
        return;
    }

    {
        u32* p = output + (position - 1) * 2;
        u32 offset;

        p[0] = *first;
        p[1] = *second;
        offset = ((u8)(inner - position) + 2) * 4 - 1;
        p += offset;
        p[0] = *first;
        p[1] = *second;
        p += (position - 2) * 4 + 5;
        p[0] = *second;
        p[1] = *third;
        p += offset;
        p[0] = *second;
        p[1] = *third;
    }
}
