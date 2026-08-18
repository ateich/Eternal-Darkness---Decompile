typedef unsigned char u8;
typedef unsigned int u32;

extern u8* fn_80156938(void*);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, int, int, int);
extern void* fn_801A4410(void*);

void fn_80155644(void* source, void* target)
{
    u8* target_work = fn_80156938(target);
    u8* source_work = fn_80156938(source);
    void* list = *(void**)(source_work + 0x88);
    void* item = fn_8017FDE4(list);
    fn_80149B60(target_work, item, *(u32*)(source_work + 8),
                 *(u32*)(source_work + 0x48), 0);
    fn_80149B60(target_work, fn_801A4410(list), 0x10, 1, 0);
}
