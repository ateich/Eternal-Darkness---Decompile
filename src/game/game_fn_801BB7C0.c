typedef unsigned short u16;

typedef struct StreamResource {
    void* value;
    u16 id;
    u16 references;
} StreamResource;

extern unsigned char lbl_8061C748[];
extern u16 lbl_8064D3F4;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BB7C0(u16 id)
{
    unsigned char* base = lbl_8061C748;
    int count;
    int index;
    int cursor;

    fn_801CE2B8();
    count = lbl_8064D3F4;
    index = 0;
    while (index < count && ((StreamResource*)(base + 0x4600))[index].id != id) {
        index++;
    }

    if (index == count) {
        goto not_removed;
    }

    if (--((StreamResource*)(base + 0x4600))[index].references != 0) {
        goto not_removed;
    }

    cursor = index + 1;
    for (; cursor < count; cursor++) {
        ((StreamResource*)(base + 0x4600))[cursor - 1] =
            ((StreamResource*)(base + 0x4600))[cursor];
    }
    lbl_8064D3F4--;
    fn_801CE280();
    return 1;

not_removed:
    fn_801CE280();
    return 0;
}
