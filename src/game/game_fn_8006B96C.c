typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

static const u16 mode1_events[10] = {0x1E, 0x69, 0x97, 0xA1, 0xA7, 0xF3, 0xF8, 0xFD, 0xFF, 0x101};
static const u16 mode2_events[5] = {0x1B, 0x45, 0x7B, 0xF5, 0xFF};
static const u16 mode5_events[8] = {0x05, 0x27, 0x53, 0x9D, 0xB9, 0xBF, 0xD5, 0x124};
static const s32 mode4_requirements[9] = {0x221, 0x269, 0x2C2, 0x3C5, 0x20B, 0x1E6, 0x1E5, 0x20C, 0x20D};
static const u16 mode4_events[9] = {0x55, 0x64, 0x66, 0x77, 0x8B, 0xAA, 0xAC, 0x129, 0x12A};
static const s32 mode6_requirements[6] = {0x244, 0x244, 0x171, 0x23F, 0x34A, 0x243};
static const u16 mode6_events[6] = {0x1B, 0x159, 0x20, 0x43, 0xCA, 0xFF};

extern s32 lbl_8064B52C;
extern u16 lbl_8064B530;
extern u16 lbl_8064B534;
extern void *lbl_8064C4E0;
extern s32 fn_801E79FC(void *, s32);

s32 fn_8006B96C(s32 event, s32 mode)
{
    const u16 *list;
    s32 i;
    s32 count = 0;
    s32 result = -1;
    const s32 *requirements = 0;
    const u16 *events = 0;
    s32 require_set = 1;

    switch (mode) {
    case 9:
        switch (event) {
        case 0xA5:
        case 0xA9:
        case 0xEA:
        case 0x126:
        case 0x127:
            result = 0;
            break;
        case 0xA7:
        case 0xA8:
        case 0xE9:
        case 0x12B:
        case 0x12D:
        case 0x12E:
        case 0x132:
        case 0x133:
        case 0x134:
        case 0x139:
        case 0x142:
            result = 0;
            break;
        }
        break;
    case 4:
        switch (event) {
        case 0x54:
            if (fn_801E79FC(lbl_8064C4E0, 0x3F1) == 0) {
                result = 0;
            }
            break;
        case 0x44:
            if (fn_801E79FC(lbl_8064C4E0, 0x2A3) == 0) {
                result = 0;
            }
            break;
        default: {
            list = mode4_events;
            for (i = 0; i < 9; list++, i++) {
                if (event == *list) {
                    if (fn_801E79FC(lbl_8064C4E0, mode4_requirements[i]) != 0) {
                        result = i;
                    }
                    break;
                }
            }
            break;
        }
        }
        break;
    case 7:
        events = &lbl_8064B530;
        count = 1;
        requirements = &lbl_8064B52C;
        break;
    case 8:
        events = &lbl_8064B534;
        count = 1;
        break;
    case 6:
        events = mode6_events;
        requirements = mode6_requirements;
        count = 6;
        if (event == 0xCA) {
            require_set = 0;
        }
        break;
    case 3:
        switch (event) {
        case 0x68:
        case 0x9D:
        case 0xB9:
            result = 0;
            break;
        case 0x51:
            if (fn_801E79FC(lbl_8064C4E0, 0x2B3) == 0) {
                result = 0;
            }
            break;
        }
        break;
    case 1:
        events = mode1_events;
        count = 10;
        break;
    case 2:
        events = mode2_events;
        count = 5;
        break;
    case 5:
        events = mode5_events;
        count = 8;
        break;
    case 10:
        switch (event) {
        case 0x56:
            if (fn_801E79FC(lbl_8064C4E0, 0x202) == 0) {
                result = 0;
            }
            break;
        }
        break;
    }

    if (requirements != 0) {
        if (events != 0) {
            for (i = 0; i < count; events++, i++) {
                if (*events == event) {
                    if (require_set != 0) {
                        if (fn_801E79FC(lbl_8064C4E0, requirements[i]) == 0) {
                            result = i;
                        }
                    } else if (fn_801E79FC(lbl_8064C4E0, requirements[i]) != 0) {
                        result = i;
                    }
                    break;
                }
            }
        }
    } else if (events != 0) {
        for (i = 0; i < count; events++, i++) {
            if (*events == event) {
                result = i;
                break;
            }
        }
    }
    return result;
}
