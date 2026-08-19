typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SmallDescriptor {
    u32 word;
    u16 half;
} SmallDescriptor;

extern u32 lbl_80651C68;
extern u16 lbl_80651C6C;
extern void *fn_80156938();
extern void *fn_80201BC8();
extern int fn_8011F6A4(void*, u32, u32, int, u32*, int);
extern void fn_80182B84(void*);
extern void fn_80182BCC(void);
extern void* fn_80148008(void*, SmallDescriptor*, void*, void (*)(void));

void fn_801532B4(void* first, void* second)
{
    SmallDescriptor small;
    u32 position[3];
    u32 query[10];
    u8 descriptor[0x88];
    u8* first_data;
    void* item;

    small.word = lbl_80651C68;
    small.half = lbl_80651C6C;
    item = fn_80201BC8(fn_80156938(second));
    first_data = fn_80156938(first);
    fn_8011F6A4(item, *(u32*)(first_data + 8), *(u32*)(first_data + 0x48),
                -1, query, 1);
    fn_80182B84(descriptor);
    descriptor[0] = first_data[1];
    descriptor[1] = first_data[2];
    descriptor[2] = 100;
    *(signed char*)(descriptor + 3) = -2;
    if (first_data[1] > 1) {
        descriptor[0x16] = 4;
    }
    descriptor[0x15] = 20;
    descriptor[0x17] = first_data[3];
    position[0] = query[2];
    position[1] = query[3];
    position[2] = query[4];
    fn_80148008(position, &small, descriptor, fn_80182BCC);
}
