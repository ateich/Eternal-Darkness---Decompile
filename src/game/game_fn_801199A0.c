extern void *lbl_8064C4E0;

extern int fn_801E79FC(void *object, int value);

int fn_801199A0(int value)
{
    switch (value) {
    case 0xC9:
        return fn_801E79FC(lbl_8064C4E0, 0x32B) == 0;
    case 0xCC:
        return fn_801E79FC(lbl_8064C4E0, 0x32C) == 0;
    case 0xCF:
        return fn_801E79FC(lbl_8064C4E0, 0x32D) == 0;
    case 0xC7:
        return fn_801E79FC(lbl_8064C4E0, 0x32E) == 0;
    case 0xD5:
        return fn_801E79FC(lbl_8064C4E0, 0x32F) == 0;
    default:
        return 0;
    }
}
