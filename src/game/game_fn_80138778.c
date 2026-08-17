typedef unsigned char u8;

extern u8* lbl_8064CFF8;
extern int fn_800467E8(void);
extern void fn_801386C8(int);

void fn_80138778(void)
{
    int count = fn_800467E8();
    u8* slot = lbl_8064CFF8;
    int index = 0;

    while (index < count) {
        if (*(signed char*)(slot + 0x2F4) != 0) {
            fn_801386C8(index);
        }
        index++;
        slot += 0x2F8;
    }
}
