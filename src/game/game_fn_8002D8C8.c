typedef unsigned short u16;
typedef int s32;

static void transfer_flag(u16* source, u16* destination, s32* count,
                          u16 flag)
{
    if ((*source & flag) != 0) {
        *destination |= flag;
        (*count)++;
        *source &= ~flag;
    }
}

void fn_8002D8C8(s32 mode, u16* source, u16* destination, s32* count)
{
    switch (mode) {
    case 1:
        transfer_flag(source, destination, count, 1);
        transfer_flag(source, destination, count, 8);
        break;
    case 2:
        transfer_flag(source, destination, count, 1);
        transfer_flag(source, destination, count, 4);
        break;
    case 3:
        transfer_flag(source, destination, count, 1);
        transfer_flag(source, destination, count, 2);
        break;
    case 4:
        transfer_flag(source, destination, count, 1);
        transfer_flag(source, destination, count, 4);
        transfer_flag(source, destination, count, 2);
        transfer_flag(source, destination, count, 8);
        break;
    }
}
