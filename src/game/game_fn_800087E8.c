typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Root {
    u32 value;
    u8 pad_04[12];
} Root;

extern Root lbl_803003C8;
extern u32 lbl_80302010[];
extern void* lbl_8064C4E4;
extern u32 fn_8011FCE4(void*);
extern void* memcpy(void*, const void*, u32);

u16 fn_800087E8(u8* destination)
{
    u32 count;
    u16 offset = 0;
    u8 byte;

    lbl_80302010[lbl_803003C8.value] = fn_8011FCE4(lbl_8064C4E4);

    for (count = 0; count < 12;) {
        byte = lbl_80302010[count];
        memcpy(destination + offset, &byte, 1);
        offset++;
        count++;
    }

    return (offset + 31) & ~31;
}
