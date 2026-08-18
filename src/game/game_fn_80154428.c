typedef unsigned int u32;

extern void* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern int fn_8011F6A4(void*, u32, u32, int, u32*, int);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, u32, u32, int);

void fn_80154428(void* object, void* other)
{
    void* other_data = fn_80156938(other);
    void* data = fn_80156938(object);
    void* checked;
    u32 pair[10];

    if (other_data != 0 && (checked = fn_80201BC8(other_data)) != 0) {
        fn_8011F6A4(checked, *(u32*)((char*)data + 8),
                    *(u32*)((char*)data + 0x48), -1, pair, 1);
        fn_80149B60(other_data, fn_8017FDE4(*(void**)((char*)data + 0x88)),
                    pair[1], pair[0], 0);
    }
}
