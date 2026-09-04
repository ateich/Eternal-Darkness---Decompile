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

extern s16 lbl_8064D470;
extern ResourceLoad lbl_806286B0[];
extern void fn_801CE2B8(void);
extern void fn_801C9460(void*, u16);
extern void fn_801B399C(u16);
extern void fn_801C242C(void*);
extern void fn_801CE280(void);
extern void fn_801C3BCC(u16*, void*, u8, void*);
extern void fn_801BC240(void*);
extern void fn_801C3B30(u16*, void*, u8, void*);
extern void fn_801BC798(u16);

int fn_801C3E2C(void)
{
    ResourceNode* node;
    void* archive;
    ResourceNode* base;
    u8* extra;

    node = lbl_806286B0[lbl_8064D470-- - 1].node;
    base = lbl_806286B0[lbl_8064D470].base;
    archive = lbl_806286B0[lbl_8064D470].archive;

    fn_801CE2B8();
    if (node->flags == 1) {
        extra = (u8*)base + node->extra;
        fn_801C9460(extra + 4, *(u16*)extra);
    } else {
        fn_801B399C(node->id);
    }
    fn_801C242C((u8*)base + node->list0);
    fn_801CE280();
    fn_801C3BCC((u16*)((u8*)base + node->list1), 0, 1, (void*)1);
    fn_801BC240(archive);
    fn_801C3B30((u16*)((u8*)base + node->list0), 0, 0, (void*)1);
    fn_801C3B30((u16*)((u8*)base + node->list4), 0, 4, (void*)1);
    fn_801C3B30((u16*)((u8*)base + node->list2), 0, 2, (void*)1);
    fn_801C3B30((u16*)((u8*)base + node->list3), 0, 3, (void*)1);
    if (node->flags == 1) {
        fn_801BC798(node->id);
    }
    return 1;
}
