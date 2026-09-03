typedef unsigned short u16;
typedef unsigned int u32;

typedef struct StreamResource {
    void* value;
    u16 id;
    u16 references;
} StreamResource;

extern unsigned char lbl_8061C748[];
extern u16 lbl_8064D3F2;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BBD58(u16 id, void* value)
{
    unsigned char* selected;
    unsigned char* base = lbl_8061C748;
    int count;
    int index;
    int cursor;

    fn_801CE2B8();
    count = lbl_8064D3F2;
    index = 0;
    while (index < count && ((StreamResource*)(base + 0x600))[index].id < id) {
        index++;
    }

    if (index >= count) {
        goto append;
    }

    selected = base + index * sizeof(StreamResource);
    if (id == ((StreamResource*)(selected + 0x600))->id) {
        goto existing;
    }
    if ((u32)count >= 0x800) {
        goto insert_full;
    }
    cursor = count - 1;
    for (; cursor >= index; cursor--) {
        ((StreamResource*)(base + 0x600))[cursor + 1] =
            ((StreamResource*)(base + 0x600))[cursor];
    }
    lbl_8064D3F2++;
    goto write;

insert_full:
    fn_801CE280();
    return 0;

existing:
    fn_801CE280();
    ((StreamResource*)(selected + 0x600))->references++;
    return 0;

append:
    if ((u32)count < 0x800) {
        lbl_8064D3F2++;
        goto write;
    }
    fn_801CE280();
    return 0;

write:
    ((StreamResource*)(base + 0x600))[index].id = id;
    ((StreamResource*)(base + 0x600))[index].value = value;
    ((StreamResource*)(base + 0x600))[index].references = 1;
    fn_801CE280();
    return 1;
}
