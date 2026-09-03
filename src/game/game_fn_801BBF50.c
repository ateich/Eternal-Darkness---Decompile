typedef unsigned short u16;

typedef struct StreamResource8 {
    void* value;
    u16 id;
    u16 references;
} StreamResource8;

extern unsigned char lbl_8061C748[];
extern u16 lbl_8064D3F2;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BBF50(u16 id)
{
    unsigned char* base = lbl_8061C748;
    int count;
    int index;
    int cursor;

    fn_801CE2B8();
    count = lbl_8064D3F2;
    index = 0;
    while (index < count && ((StreamResource8*)(base + 0x600))[index].id != id) {
        index++;
    }

    if (index == count) {
        goto not_removed;
    }

    if (--((StreamResource8*)(base + 0x600))[index].references != 0) {
        goto not_removed;
    }

    cursor = index + 1;
    for (; cursor < count; cursor++) {
        ((StreamResource8*)(base + 0x600))[cursor - 1] =
            ((StreamResource8*)(base + 0x600))[cursor];
    }
    lbl_8064D3F2--;
    fn_801CE280();
    return 1;

not_removed:
    fn_801CE280();
    return 0;
}
