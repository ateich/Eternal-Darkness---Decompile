typedef unsigned short u16;
typedef unsigned int u32;

extern void* memset(void*, int, u32);
extern void fn_8017CCA8(void*, u16, void*, u16);

void fn_8017CC38(void* first, u32 first_count, u16 first_size,
                 void* second, u32 second_count, u16 second_size)
{
    memset(first, 0, first_count * first_size);
    memset(second, 0, second_count * second_size);
    fn_8017CCA8(first, first_size, second, second_size);
}
