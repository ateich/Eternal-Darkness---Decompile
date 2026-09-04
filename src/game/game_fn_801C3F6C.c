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
    u32 records0;
    u32 records1;
} ResourceNode;

typedef struct ResourceLoad {
    ResourceNode* node;
    void* archive;
    ResourceNode* base;
} ResourceLoad;

typedef struct ResourceRecord {
    u16 id;
    u8 payload[0x52];
} ResourceRecord;

extern s16 lbl_8064D470;
extern ResourceLoad lbl_806286B0[];
extern int fn_801B2980(void*, void*, ResourceRecord*, void*, void*, void*, u16);
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801C3F6C(u16 resource_id, u16 record_id, void* arg2, void* arg3,
                u8 unlocked, void* arg5)
{
    int i;

    for (i = 0; i < lbl_8064D470; i++) {
        ResourceNode* node = lbl_806286B0[i].node;
        if (node->id == resource_id) {
            ResourceRecord* record;
            ResourceNode* base;
            void* list0;
            void* list1;

            if (node->flags != 0) {
                return -1;
            }
            base = lbl_806286B0[i].base;
            list0 = (u8*)base + node->extra;
            list1 = (u8*)base + node->records0;
            record = (ResourceRecord*)((u8*)base + node->records1);
            while (record->id != 0xFFFF) {
                if (record->id == record_id) {
                    int result;
                    if (unlocked) {
                        result = fn_801B2980(list0, list1, record, arg2, arg3,
                                             arg5, resource_id);
                    } else {
                        fn_801CE2B8();
                        result = fn_801B2980(list0, list1, record, arg2, arg3,
                                             arg5, resource_id);
                        fn_801CE280();
                    }
                    return result;
                }
                record++;
            }
            return -1;
        }
    }
    return -1;
}
