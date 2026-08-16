typedef unsigned char u8;
typedef unsigned int u32;

void fn_800F35E4(void *destination, int value, u32 length)
{
    u8 *cursor = (u8 *)destination - 1;
    u32 fill = (u8)value;

    if (length >= 32) {
        u32 prefix = ~(u32)cursor & 3;
        if (prefix != 0) {
            length -= prefix;
            do {
                *++cursor = fill;
            } while (--prefix != 0);
        }

        if (fill != 0)
            fill = (fill << 24) | (fill << 16) | (fill << 8) | fill;

        destination = cursor - 3;
        value = length >> 5;
        if (value != 0) do {
            ((u32 *)destination)[1] = fill;
            ((u32 *)destination)[2] = fill;
            ((u32 *)destination)[3] = fill;
            ((u32 *)destination)[4] = fill;
            ((u32 *)destination)[5] = fill;
            ((u32 *)destination)[6] = fill;
            ((u32 *)destination)[7] = fill;
            destination = (u32 *)destination + 8;
            *(u32 *)destination = fill;
        } while (--value != 0);
        value = (length >> 2) & 7;
        if (value != 0) do {
            destination = (u32 *)destination + 1;
            *(u32 *)destination = fill;
        } while (--value != 0);
        cursor = (u8 *)destination + 3;
        length &= 3;
    }

    if (length != 0) do {
        *++cursor = fill;
    } while (--length != 0);
}
