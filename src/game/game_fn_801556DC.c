typedef unsigned char u8;
typedef unsigned int u32;

extern u8* fn_80156938(void*);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, int, int, int);

void fn_801556DC(void* source, void* target)
{
    u8* target_work = fn_80156938(target);
    u8* source_work = fn_80156938(source);
    void* item = fn_8017FDE4(*(void**)(source_work + 0x88));
    fn_80149B60(target_work, item, *(u32*)(source_work + 8),
                 *(u32*)(source_work + 0x48), 0);
}
