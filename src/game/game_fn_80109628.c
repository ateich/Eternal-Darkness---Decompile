typedef unsigned char u8;
typedef unsigned int u32;

extern int fn_80108510(void);

int fn_80109628(void* state)
{
    int status;
    u8 flags;

    if (state == 0) {
        return (int)0xC0000000;
    }

    flags = *((u8*)state + 0x1AC);
    if (flags & 4) {
        return 4;
    }

    status = fn_80108510();
    switch (status) {
    case -1:
        return (int)0xA0000000;
    case 0:
    case 9:
        break;
    default:
        return fn_80108510() | 0x80000000;
    }

    flags = *((u8*)state + 0x1AC);
    if (flags & 2) {
        return flags & 0x12;
    }
    return flags & 1;
}
