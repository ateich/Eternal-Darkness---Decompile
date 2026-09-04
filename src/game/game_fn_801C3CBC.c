typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ResourceNode {
    u32 next;
    u16 id;
    u16 flags;
    u32 list0;
    u32 list1;
    u32 list4;
    u32 list2;
    u32 list3;
    u32 extra;
} ResourceNode;

typedef struct ResourceLoad {
    ResourceNode* node;
    void* archive;
    ResourceNode* base;
} ResourceLoad;

extern u8 lbl_8064DA20;
extern s16 lbl_8064DAF0;
extern ResourceLoad lbl_806386B0[];
extern u32 fn_801CD224(u32);
extern int fn_801BC0D4(void*, u32);
extern void fn_801C3B30(u16*, void*, u8, void*);
extern void fn_801BC670(u16, void*, u16);
extern void fn_801CD3E0(void);

int fn_801C3CBC(ResourceNode* base, u16 id, u32 kind, void* archive,
                void* direct)
{
    u16* list;
    ResourceNode* node;
    ResourceLoad* loads = lbl_806386B0;

    if (lbl_8064DA20 != 0) {
        s16 count = lbl_8064DAF0;
        if (count < 128) {
            node = base;
            while (node->next != 0xFFFFFFFF) {
                if (node->id == id) {
                    loads[count].node = node;
                    loads[count].base = base;
                    loads[count].archive = archive;
                    list = (u16*)((u8*)base + node->list1);
                    if (fn_801BC0D4(archive, fn_801CD224(kind))) {
                        fn_801C3B30(list, archive, 1, 0);
                    }
                    fn_801C3B30((u16*)((u8*)base + node->list0), direct, 0, 0);
                    fn_801C3B30((u16*)((u8*)base + node->list4), direct, 4, 0);
                    fn_801C3B30((u16*)((u8*)base + node->list2), direct, 2, 0);
                    fn_801C3B30((u16*)((u8*)base + node->list3), direct, 3, 0);
                    if (node->flags == 1) {
                        u8* extra = (u8*)base + node->extra;
                        fn_801BC670(id, extra + 4, *(u16*)extra);
                    }
                    fn_801CD3E0();
                    lbl_8064DAF0++;
                    return 1;
                }
                node = (ResourceNode*)((u8*)base + node->next);
            }
        }
    }
    return 0;
}
