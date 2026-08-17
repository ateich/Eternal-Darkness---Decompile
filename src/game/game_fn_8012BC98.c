typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8* lbl_8064D790;
extern u16 fn_801F6734(void*, void*);

u16 fn_8012BC98(u8* owner, u8* output)
{
    u16 total;
    u16 inner;
    int outer;
    u8* entry;
    u32 one;
    s16 id;

    total = 0;
    outer = 0;
    entry = *(u8**)(owner + 0x60);
    while (outer < *(int*)(owner + 0x5C)) {
        inner = 0;
        one = 1;
        while (inner < 11) {
            id = ((s16*)entry)[inner];
            if (id != -1 && (*(u32*)(entry + 0x18) & (one << inner))) {
                total += fn_801F6734(output + total, lbl_8064D790 + id * 12);
            }
            inner++;
        }
        outer++;
        entry += 0x20;
    }
    return (total + 0x1F) & ~0x1F;
}
