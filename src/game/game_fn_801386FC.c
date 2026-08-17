typedef unsigned char u8;

extern u8* lbl_8064CFF8;
extern int fn_800467E8(void);
extern void fn_801386C8(int);

int fn_801386FC(u8 amount)
{
    int limit;
    u8* slot;
    int index;

    fn_800467E8();
    slot = lbl_8064CFF8 + 36 * 0x2F8;
    limit = amount + 36;
    index = 36;
    while (index < limit) {
        if (*(void**)slot != 0) {
            fn_801386C8(index);
        }
        index++;
        slot += 0x2F8;
    }
    return -1;
}
