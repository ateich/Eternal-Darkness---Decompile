typedef unsigned char u8;
typedef unsigned int u32;

extern u8* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern int fn_8011F6A4(void*, u32, u32, int, u32*, int);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, u32, u32, int);

void fn_80152F04(void* first, void* second)
{
    u32 pair[10];
    u8* first_data;
    u8* second_data;
    void* item;
    void* state;

    second_data = fn_80156938(second);
    first_data = fn_80156938(first);
    item = fn_80201BC8(second_data);
    fn_8011F6A4(item, *(u32*)(first_data + 8), *(u32*)(first_data + 0x48),
                -1, pair, 1);
    state = fn_8017FDE4(*(void**)(first_data + 0x88));
    fn_80149B60(second_data, state, pair[1], pair[0], 0);
}
