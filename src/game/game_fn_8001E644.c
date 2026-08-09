typedef int s32;
typedef unsigned int u32;

extern s32* lbl_8064C5A8;

extern void fn_80113B50(u32);
extern void fn_80113BA8(u32);
extern void fn_80113F54(u32);

void fn_8001E644(u32 type, s32 unused, s32 enable)
{
    s32* values;
    u32 next_mask;
    s32 current_shift;
    u32 current_mask;
    u32 previous_mask;
    u32 next_bit;
    u32 current_bit;
    u32 previous_bit;

    values = lbl_8064C5A8;
    next_mask = 0x10000 << (values[1] - 1);
    current_shift = values[0] - 1;
    current_mask = 0x10000 << current_shift;
    previous_mask = 0x10000 << (values[-1] - 1);
    next_bit = 1 << (values[1] - 1);
    current_bit = 1 << current_shift;
    previous_bit = 1 << (values[-1] - 1);

    switch (type) {
    case 0:
    case 1:
    case 2:
    case 12:
    case 13:
    case 14:
    case 16:
        break;
    case 11:
        if (enable != 0) {
            fn_80113F54(next_bit | 0x0C070810);
            fn_80113F54(previous_bit | 0x0C070300);
        }
        break;
    case 10:
    case 15:
        if (enable != 0) {
            fn_80113BA8(0x70000);
            fn_80113F54(next_bit | 0x0C010500);
            fn_80113F54(next_bit | 0x0C070440);
        }
        break;
    case 9:
        if (enable != 0) {
            fn_80113F54(next_bit | 0x0C040820);
            fn_80113F54(next_bit | 0x0C010420);
        }
        break;
    case 8:
        if (enable != 0) {
            fn_80113F54(next_bit | 0x0C020820);
            fn_80113F54(next_bit | 0x0C030440);
            fn_80113F54(next_bit | 0x0C031010);
        }
        break;
    case 7:
        fn_80113B50(0x20000000);
        if (enable != 0) {
            fn_80113B50(0x2000);
            fn_80113BA8(0x30000);
            fn_80113F54(next_bit | 0x0C011010);
            fn_80113F54(next_bit | 0x0C030480);
        }
        break;
    case 6:
        fn_80113B50(0x08A80000);
        if (enable != 0) {
            fn_80113B50(0x08A8);
            fn_80113BA8(0x10000);
            fn_80113F54(next_bit | 0x0C010480);
            fn_80113F54(next_bit | 0x0C010820);
        }
        break;
    case 5:
        fn_80113B50(next_mask | 0x04100000);
        if (enable != 0) {
            fn_80113B50(next_bit | 0x0410);
            fn_80113BA8(0x10000);
            fn_80113F54(next_bit | 0x0C010440);
            fn_80113F54(next_bit | 0x0C010410);
        }
        break;
    case 4:
        fn_80113B50(current_mask | 0x10400000);
        if (enable != 0) {
            fn_80113B50(current_bit | 0x1040);
            fn_80113BA8(0x10000);
            fn_80113F54(current_bit | 0x0C011040);
        }
        break;
    case 3:
        fn_80113B50(previous_mask | 0x03000000);
        if (enable != 0) {
            fn_80113B50(previous_bit | 0x0300);
            fn_80113BA8(0x10000);
            fn_80113F54(previous_bit | 0x0C010300);
        }
        break;
    }
}
