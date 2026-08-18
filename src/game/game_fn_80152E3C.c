typedef unsigned char u8;
typedef unsigned int u32;

extern void* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern int fn_8011F6A4(void*, u32, u32, int, u32*, int);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, u32, u32, int);
extern void* fn_8017FE04(void*);
extern void fn_8012DBE8(void*, int, u8*);

void fn_80152E3C(void* first, void* second)
{
    u8 local[0x34];
    u8* first_data;
    u8* second_data;
    void* item;
    void* state;

    second_data = fn_80156938(second);
    first_data = fn_80156938(first);
    item = fn_80201BC8(second_data);
    if (item != 0) {
        fn_8011F6A4(item, *(u32*)(first_data + 8), *(u32*)(first_data + 0x48),
                    -1, (u32*)(local + 4), 1);
        state = *(void**)(first_data + 0x88);
        if (state != 0) {
            state = fn_8017FDE4(state);
            fn_80149B60(second_data, state, *(u32*)(local + 8),
                        *(u32*)(local + 4), 0);
            state = fn_8017FE04(*(void**)(first_data + 0x88));
            fn_8012DBE8(item, 15, local);
            ((u8*)state)[3] = local[3];
        }
    }
}
